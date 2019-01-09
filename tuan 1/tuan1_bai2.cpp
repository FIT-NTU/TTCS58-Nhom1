#include <vector>
#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#define N 10
using namespace std;

struct nut{
	int giatri, hang_vitri, cot_vitri, a;
	nut *tieptheo;
};
typedef struct nut Nut;
//
struct MAT 
{ 
    int rows, cols; 
    nut *hang_vitri[10]; 
    MAT(int _row = 10, int _col = 10) 
        { 
            rows = _row; 
            cols = _col; 
        } 
}; 

class Danhsach{
private:
	int r=0, c=0;
	Nut *head, *tail;
public:
	Danhsach();
	Danhsach(int r, int c);
	int Get_hang();
	int Get_cot();

	Nut *TaoNut(int hang, int cot, int giatri);
	void nhapDanhsach();
	
	void them_dau(Nut *p);
	void them_cuoi(Nut *p);

	void xuatNut();
	void xuat_matranthua();
	int **xuat_matranthua1();
	
	void multiNumber(int n);
	void det_matrannho(int ** matrix, int ** temp, int p, int q);
	int det(int ** matrix, int n);
	void inverse();
};


Danhsach::Danhsach(int hang, int cot)
{
	r = hang;
	c = cot;
}

int Danhsach::Get_hang()
{
	return r;
}

int Danhsach::Get_cot()
{
	return c;
}

void Danhsach::nhapDanhsach()
{	
	int temp = 0, index = 0;
	do {
		cout << "Nhap so hang: "; cin >> r;
		if (r == 0)
			cout << "Nhap sai! Nhap lai: " << endl;
	} while (r == 0);
	do {
		cout << "Nhap so cot: "; cin >> c;
		if (c == 0)
			cout << "Nhap sai! Nhap lai: " << endl;
	} while (c == 0);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "A[" << i << ", " << j << "]" << " = "; 
			cin >> temp;
			if (temp != 0) {
				index++;
				them_cuoi(TaoNut(i, j, temp));
			}
		}
	}
	// dieu kien nhan biet ma tran thua
	if (index > (c*r) / 2) {
		cout << "Khong phai ma tran thua" << endl;
		cout << "Nhap lai:" << endl;
		nhapDanhsach();
	}
}

Nut * Danhsach::TaoNut(int hang, int cot, int giatri)
{
	Nut *p = new Nut;
	p->cot_vitri = cot;
	p->hang_vitri = hang;
	p->giatri = giatri;
	p->tieptheo = NULL;
	return p;
}

void Danhsach::them_dau(Nut * p)
{
	if (head == NULL) {
		head = tail = p;
	}
	else {
		p->tieptheo = head->tieptheo;
		head = p;
	}
}

void Danhsach::them_cuoi(Nut * p)
{
	if (head == NULL) {
		head = tail = p;
	}
	else {
		tail->tieptheo = p;
		tail = p;
	}
}

// Xuat ra danh sach cac nut
void Danhsach::xuatNut()
{
	if (head == NULL) {
		cout << "Danh sach rong" << endl;
		return;
	}
	Nut * temp = head;
	while (temp != NULL)
	{
		cout << "hang: " << temp->hang_vitri << ", cot: " << temp->cot_vitri << ", giatri: " << temp->giatri << ";" << endl;
		temp = temp->tieptheo;
	}
}

// Xuat ra ma tran 2 chieu tu link Danhsach
void Danhsach::xuat_matranthua()
{
	int temp[10][10];
	Nut * p = head;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}

	while (p != NULL) {
		temp[p->hang_vitri][p->cot_vitri] = p->giatri;
		p = p->tieptheo;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

// Tao mang 2 chieu tu link Danhsach
int ** Danhsach::xuat_matranthua1()
{
	int ** temp = 0;
	Nut *p = head;
	temp = new int*[r];
	for (int i = 0; i < r; i++) {
		temp[i] = new int[c];
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}

	while (p != NULL) {
		temp[p->hang_vitri][p->cot_vitri] = p->giatri;
		p = p->tieptheo;
	}
	return temp;
}

// Nhan voi 1 so khac 0
void Danhsach::multiNumber(int n)
{
	Nut *p = head;
	cout << "Nhap so can nhan: ";
	do {
		cin >> n;
		if (n == 0) {
			cout << "Nhap lai: ";
		}
	} while (n == 0);
	
	while (p != NULL)
	{
		p->giatri = p->giatri * n;
		p = p->tieptheo;
	}
	cout << "Ma tran sau khi nhan voi " << n << ":" << endl;
	xuat_matranthua();
}

// Tao ma tran nho tu ma tran da cho
void Danhsach::det_matrannho(int ** matrix, int **temp, int p, int q)
{
	int i = 0, j = 0;
	for (int hang = 0; hang < c; hang++) {
		for (int cot = 0; cot < c; cot++) {
			if (hang != p && cot != q) {
				temp[i][j++] = matrix[hang][cot];
				if (j == c - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

Danhsach::Danhsach()
{
	head = tail = NULL;
}



 Tao ma tran nghich dao
void Danhsach::inverse()
{
	double matrix[N][N];
	int ** temp = new int*[N];
	for (int i = 0; i < r; i++) {
		temp[i] = new int[r];
	}

	int sign = 1;
	int det1 = det(xuat_matranthua1(), c);
	if (det1 == 0) {
		cout << "Ma tran nay khong kha nghich." << endl;
		return;
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			det_matrannho(xuat_matranthua1(), temp, i, j);
			matrix[i][j] = sign *det(temp, c - 1) * 1/(det1);
			sign = -sign;
		}
	}
	cout << "Ma tran nghich dao la: " << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

// Tinh dinh thuc
int mdeterm(MAT a) 
{ 
    if (a.rows != a.cols)  
        { 
            printf("\nKhong phai ma tran vuong!\n"); 
            return 0; 
        }
    float *c[10], temp; 
    int k, j, p; 
    for (k = 0; k < a.rows; k ++) 
        { 
            c[k] = new float[a.cols]; 
            for (j = 0; j < a.cols; j++) c[k][j] = 0; 
            nut *pa = a.hang_vitri[k]; 
            while (pa != NULL) 
                { 
                    c[k][pa->cot_vitri] = (float) pa->giatri; 
                    pa = pa ->tieptheo; 
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


Danhsach *x = new Danhsach;
void showmenu() {
	cout << endl << "----------DANH SACH----------" << endl;
	cout << "0. Thoat" << endl;
	cout << "1. Tao 1 ma tran thua" << endl;
	cout << "2. Hien thi ma tran thua dang LINKER Danhsach" << endl;
	cout << "3. Hien thi ma tran thua dang ARRAY" << endl;
	cout << "4. Nhan ma tran thua voi 1 so khac 0" << endl;
	cout << "5. Nghich dao cua 1 ma tran thua" << endl;
	cout << "6. Dinh thuc cua 1 ma tran thua" << endl;
	cout << "7. Cong, Tru, Nhan, Chia 2 ma tran thua" << endl;
}

void select() {
	int n = 0, r = 0, c = 0, temp = 0, a;
	cout << "Lua chon: "; cin >> n;
	switch (n)
	{
	case 0: 
		return;
	case 1:
		x->nhapDanhsach();
		system("cls");
		cout << "Da tao ma tran thua!" << endl;	
		showmenu();
		select();
		break;
	case 2:
		system("cls");
		cout << "Ma tran thua dang link Danhsach la: " << endl;
		x->xuatNut();
		showmenu();
		select();
		break;
	case 3:
		system("cls");
		cout << "Ma tran thua dang array: " << endl;
		x->xuat_matranthua();
		showmenu();
		select();
		break;
	case 4:
		cout << "Nhap so can nhan: "; cin >> temp;
		system("cls");
		x->multiNumber(temp);
		showmenu();
		select();
		break;

	case 5:
		system("cls");
		if (x->Get_hang() != x->Get_cot()) {
			cout << "Day khong phai la ma tran don vi cap n" << endl;
			cout << "Nhap lai de tinh!!!" << endl;
		}
		else {
			x->inverse();
		}
		showmenu();
		select();
		break;
	case 6:
		system("cls");
		{
//			MAT a(r,c);
	//    	input(a,'A'); 
	    	cout << "Dinh thuc cua ma tran A la: " << mdeterm(a) << endl;
		showmenu();
		select();
		break;
		}
	default:
		system("cls");
		cout << "Sai cu phap" << endl;
		showmenu();
		select();
		break;
	}
}

int main() {
	showmenu();
	select();
	system("pause");
}
