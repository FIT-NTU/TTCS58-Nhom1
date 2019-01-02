#include <stdio.h> 
#include <stdlib.h> 
#include<iostream>
#define max 10 

using namespace std;

struct PNODE 
{ 
    int hang, cot; 
    int data; 
    PNODE *next; 
}; 

struct MAT 
{ 
    int hangs, cots; 
    PNODE *hang[max]; 
    MAT(int _hang = max, int _cot = max) 
        { 
            hangs = _hang; 
            cots = _cot; 
        } 
}; 

void set(PNODE *dest, int hang, int cot, int data) 
{ 
    dest->data = data; 
    dest->hang = hang; 
    dest->cot = cot; 
} 

void append(PNODE * &dest, PNODE *src) 
{ 
    src ->next = NULL; 
    if (dest == NULL) dest = src; 
    else dest = dest->next = src; 
} 

void input(MAT &a, char name) 
{ 
    int k, j; int _data;  
    for (k = 0; k < a.hangs; k ++) 
        { 
            PNODE *last = a.hang[k] = NULL; 
            for (j = 0; j < a.cots; j ++) 
                { 
                    printf("%c[%d,%d] = ",name,k,j); 
                    scanf("%d",&_data); 
                    if (_data) 
                        { 
                            PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
                            set(temp,k,j,_data); 
                            append(last,temp); 
                            if (a.hang[k] == NULL) a.hang[k] = last; 
                        } 
                } 
        } 
} 


PNODE * rowsum(PNODE *a, PNODE *b, int mode = 1) 
{ 
    PNODE *c = NULL,*last = NULL, *pa = a, *pb = b; 
    while (pa != NULL && pb != NULL) 
        { 
            PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
            if (pa->cot < pb->cot) 
                { 
                    set(temp,pa->hang,pa->cot,pa->data); 
                    pa = pa->next; 
                } 
            else 
                if (pa->cot > pb->cot) 
                    { 
                        if (mode) 
                             set(temp,pb->hang,pb->cot,pb->data); 
                        else set(temp,pb->hang,pb->cot,-pb->data); 
                        pb = pb->next; 
                    } 
                else 
                    { 
                        if (mode)  
                             set(temp,pb->hang,pb->cot,pa->data + pb->data); 
                        else set(temp,pb->hang,pb->cot,pa->data - pb->data); 
                        pa = pa->next; 
                        pb = pb->next; 
                    } 
            append(last,temp); 
            if (c == NULL) c = last; 
        } 
    while (pb != NULL) 
        { 
            PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
            if (mode) 
                 set(temp,pb->hang,pb->cot, pb->data); 
            else set(temp,pb->hang,pb->cot,-pb->data); 
            append(last,temp); 
            if (c == NULL) c = last; 
            pb = pb->next; 
        } 
    while (pa != NULL) 
        { 
            PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
            set(temp,pa->hang,pa->cot,pa->data); 
            append(last,temp); 
            if (c == NULL) c = last; 
            pa = pa->next; 
        } 
    return c; 
} 

void matsum(MAT a, MAT b, MAT &c, int mode=1) 
{ 
    c.hangs = a.hangs; c.cots = a.cots; 
    for (int k = 0; k < a.hangs; k++) 
        c.hang[k] = rowsum(a.hang[k],b.hang[k], mode); 

} 

void matmul(MAT a, MAT b, MAT &c) 
{ 
    int k, j, *_data = new int[b.cots]; 
     
    PNODE *last; 
    c.hangs = a.hangs; c.cots = b.cots; 
    for (k = 0; k < a.hangs; k++) 
        { 
            for (j = 0; j < b.cots; j++) _data[j] = 0; 
            PNODE *pa = a.hang[k]; 
            while (pa !=NULL) 
                { 
                    PNODE *pb = b.hang[pa->cot]; 
                    while (pb != NULL) 
                        { 
                            _data[pb->cot] += pa->data*pb->data; 
                            pb = pb->next; 
                        } 
                    pa = pa->next; 
                } 
            c.hang[k] = last = NULL; 
            for (j = 0; j < b.cots; j++) 
                if (_data[j]) 
                    { 
                        PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
                        set(temp,k,j,_data[j]); 
                        append(last,temp); 
                        if (c.hang[k] == NULL) c.hang[k] = last; 
                    } 
        } 
    delete _data; 
} 

int mdeterm(MAT a) 
{ 
    if (a.hangs != a.cots)  
        { 
            printf("\nKhong phai ma tran vuong!\n"); 
            return 0; 
        } 
    float *c[max], temp; 
    int k, j, p; 
    for (k = 0; k < a.hangs; k ++) 
        { 
            c[k] = new float[a.cots]; 
            for (j = 0; j < a.cots; j++) c[k][j] = 0; 
            PNODE *pa = a.hang[k]; 
            while (pa != NULL) 
                { 
                    c[k][pa->cot] = (float) pa->data; 
                    pa = pa ->next; 
                } 
        } 
    int sign = 1; 
    for (k = 0; k < a.hangs-1; k ++) 
        { 
            if (c[k][k] == 0) 
                { 
                    p = k+1; 
                    while (p < a.hangs && c[p][k] == 0) p ++; 
                    if (p == a.hangs) return 0; 
                    sign = -sign; 
                    for (j = k; j < a.hangs; j++) 
                        { 
                            temp = c[k][j];  
                            c[k][j] = c[p][j]; 
                            c[p][j] = temp; 
                        } 
                } 
            for (p = k+1; p < a.hangs; p ++) 
                for (j = a.hangs-1; j >= k; j--) 
                    c[p][j]= c[p][j]-c[k][j]*c[p][k]/c[k][k]; 
        } 
    temp = sign; 
    for (k = 0; k < a.hangs; k ++)  
        {    temp *= c[k][k]; 
            delete c[k]; 
        } 
    return (int) temp; 
} 

void output(MAT a, char *name) 
{ 
    printf("\n%s:\n", name); 
    int k; PNODE *temp; 
    for (k = 0; k < a.hangs; k ++) 
        { 
            printf("\n"); 
            temp = a.hang[k]; int j = 0; 
            if (temp == NULL) 
                for (int i = j; i < a.cots; i ++) 
                    printf("%8d",0); 

            while (temp != NULL) 
                { 
                    for (int i = j; i < temp->cot; i ++) 
                        printf("%8d",0); 
                    j = temp->cot + 1; 
                    printf("%8d",temp->data); 
                    temp = temp->next; 
                    if (temp == NULL) 
                        for (int i = j; i < a.cots; i ++) 
                            printf("%8d",0); 
                } 
        } 
    printf("\n"); 
} 

void matfree(MAT &a) 
{ 
    int k; 
    for (k = 0; k < a.hangs; k++) 
        { 
            PNODE *pa = a.hang[k]; 
            while (pa != NULL) 
                { 
                    a.hang[k] = pa->next; 
                    delete pa; 
                    pa = a.hang[k]; 
                } 
        } 
} 

int main() 
{ 
    int n = 3; 
    MAT a(n,n), b(n,n), c; 
    cout<<"tao ma tran a"<< endl;
    input(a,'A'); 
    cout<<"ma tran a:";
    output(a, "A"); 
    printf("\nDinh thuc cua A = %d\n",mdeterm(a));
    cout<<"nhap ma tran B"<<endl;
    input(b,'B'); 
    output(b,"B"); 
    cout<<"cong, tru, nhan 2 ma tran";
    matsum(a,b,c);output(c,"A + B:"); 
    matsum(a,b,c,0);output(c,"A - B"); 
    matmul(a,b,c);output(c,"A * B"); 
    matfree(a); matfree(b); matfree(c); 
}
