#include <stdio.h> 
#include <stdlib.h> 
#define max 10 

struct PNODE 
{ 
    int row, col; 
    int data; 
    PNODE *next; 
}; 

struct MAT 
{ 
    int rows, cols; 
    PNODE *row[max]; 
    MAT(int _row = max, int _col = max) 
        { 
            rows = _row; 
            cols = _col; 
        } 
}; 

void set(PNODE *dest, int row, int col, int data) 
{ 
    dest->data = data; 
    dest->row = row; 
    dest->col = col; 
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
    for (k = 0; k < a.rows; k ++) 
        { 
            PNODE *last = a.row[k] = NULL; 
            for (j = 0; j < a.cols; j ++) 
                { 
                    printf("%c[%d,%d] = ",name,k,j); 
                    scanf("%d",&_data); 
                    if (_data) 
                        { 
                            PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
                            set(temp,k,j,_data); 
                            append(last,temp); 
                            if (a.row[k] == NULL) a.row[k] = last; 
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
            if (pa->col < pb->col) 
                { 
                    set(temp,pa->row,pa->col,pa->data); 
                    pa = pa->next; 
                } 
            else 
                if (pa->col > pb->col) 
                    { 
                        if (mode) 
                             set(temp,pb->row,pb->col,pb->data); 
                        else set(temp,pb->row,pb->col,-pb->data); 
                        pb = pb->next; 
                    } 
                else 
                    { 
                        if (mode)  
                             set(temp,pb->row,pb->col,pa->data + pb->data); 
                        else set(temp,pb->row,pb->col,pa->data - pb->data); 
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
                 set(temp,pb->row,pb->col, pb->data); 
            else set(temp,pb->row,pb->col,-pb->data); 
            append(last,temp); 
            if (c == NULL) c = last; 
            pb = pb->next; 
        } 
    while (pa != NULL) 
        { 
            PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
            set(temp,pa->row,pa->col,pa->data); 
            append(last,temp); 
            if (c == NULL) c = last; 
            pa = pa->next; 
        } 
    return c; 
} 

void matsum(MAT a, MAT b, MAT &c, int mode=1) 
{ 
    c.rows = a.rows; c.cols = a.cols; 
    for (int k = 0; k < a.rows; k++) 
        c.row[k] = rowsum(a.row[k],b.row[k], mode); 

} 

void matmul(MAT a, MAT b, MAT &c) 
{ 
    int k, j, *_data = new int[b.cols]; 
     
    PNODE *last; 
    c.rows = a.rows; c.cols = b.cols; 
    for (k = 0; k < a.rows; k++) 
        { 
            for (j = 0; j < b.cols; j++) _data[j] = 0; 
            PNODE *pa = a.row[k]; 
            while (pa !=NULL) 
                { 
                    PNODE *pb = b.row[pa->col]; 
                    while (pb != NULL) 
                        { 
                            _data[pb->col] += pa->data*pb->data; 
                            pb = pb->next; 
                        } 
                    pa = pa->next; 
                } 
            c.row[k] = last = NULL; 
            for (j = 0; j < b.cols; j++) 
                if (_data[j]) 
                    { 
                        PNODE *temp = (PNODE *) malloc (sizeof(PNODE)); 
                        set(temp,k,j,_data[j]); 
                        append(last,temp); 
                        if (c.row[k] == NULL) c.row[k] = last; 
                    } 
        } 
    delete _data; 
} 

int mdeterm(MAT a) 
{ 
    if (a.rows != a.cols)  
        { 
            printf("\nKhong phai ma tran vuong!\n"); 
            return 0; 
        } 
    float *c[max], temp; 
    int k, j, p; 
    for (k = 0; k < a.rows; k ++) 
        { 
            c[k] = new float[a.cols]; 
            for (j = 0; j < a.cols; j++) c[k][j] = 0; 
            PNODE *pa = a.row[k]; 
            while (pa != NULL) 
                { 
                    c[k][pa->col] = (float) pa->data; 
                    pa = pa ->next; 
                } 
        } 
    int sign = 1; 
    for (k = 0; k < a.rows-1; k ++) 
        { 
            if (c[k][k] == 0) 
                { 
                    p = k+1; 
                    while (p < a.rows && c[p][k] == 0) p ++; 
                    if (p == a.rows) return 0; 
                    sign = -sign; 
                    for (j = k; j < a.rows; j++) 
                        { 
                            temp = c[k][j];  
                            c[k][j] = c[p][j]; 
                            c[p][j] = temp; 
                        } 
                } 
            for (p = k+1; p < a.rows; p ++) 
                for (j = a.rows-1; j >= k; j--) 
                    c[p][j]= c[p][j]-c[k][j]*c[p][k]/c[k][k]; 
        } 
    temp = sign; 
    for (k = 0; k < a.rows; k ++)  
        {    temp *= c[k][k]; 
            delete c[k]; 
        } 
    return (int) temp; 
} 

void output(MAT a, char *name) 
{ 
    printf("\n%s:\n", name); 
    int k; PNODE *temp; 
    for (k = 0; k < a.rows; k ++) 
        { 
            printf("\n"); 
            temp = a.row[k]; int j = 0; 
            if (temp == NULL) 
                for (int i = j; i < a.cols; i ++) 
                    printf("%8d",0); 

            while (temp != NULL) 
                { 
                    for (int i = j; i < temp->col; i ++) 
                        printf("%8d",0); 
                    j = temp->col + 1; 
                    printf("%8d",temp->data); 
                    temp = temp->next; 
                    if (temp == NULL) 
                        for (int i = j; i < a.cols; i ++) 
                            printf("%8d",0); 
                } 
        } 
    printf("\n"); 
} 

void matfree(MAT &a) 
{ 
    int k; 
    for (k = 0; k < a.rows; k++) 
        { 
            PNODE *pa = a.row[k]; 
            while (pa != NULL) 
                { 
                    a.row[k] = pa->next; 
                    delete pa; 
                    pa = a.row[k]; 
                } 
        } 
} 

int main() 
{ 
    int n;
	printf("\nNhap n = "); scanf("%d",&n); 
    MAT a(n,n), b(n,n), c; 
    input(a,'A'); 
    printf("\nDinh thuc cua A = %d\n",mdeterm(a)); 
     
    input(b,'B'); 
    output(a, "A"); 
    output(b,"B"); 
    matsum(a,b,c);output(c,"A + B:"); 
    matsum(a,b,c,0);output(c,"A - B"); 
    matmul(a,b,c);output(c,"A * B"); 
    matfree(a); matfree(b); matfree(c); 
}
