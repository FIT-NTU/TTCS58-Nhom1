//Hovaten: Sam Van Quan, MSSV: 58131370
// SDT: 0352609900; email: vanquanntuk58@gmail.com
#include<iostream>
#include <vector>
#include <conio.h>
using namespace std;
#define N 100
struct node {
	int data;
	int row_tiep;
	int col_tiep;
	struct node *Next;
};
typedef struct node Node;
class List {
	int h=0, c=0;
	Node *Head, *Tail;
public:
	List();
	List(int h, int c);
	int TaoHang();
	int TaoCot();
	Node *TaoNode(int row, int col, int data);
	void InNode();
	void ThemDau(Node *p);
	void ThemCuoi(Node *p);
	void XuatMaTranThua();
	int **XuatMaTran1();
	void NhanMaTran(int n);
	void TaoMaTran(int ** matrix, int ** temp, int p, int q);
	int det(int ** matrix, int n);
	void MaTranNghichDao();
};
List::List() // khong tao 1 danh sach rong 
{
	Head = Tail = NULL;
}
List::List(int row, int col)// khoi tao danh sach gom cot va hang
{
	h = row;
	c = col;
}

int List::TaoHang()
{
	return h;
}

int List::TaoCot()
{
	return c;
}

void List::InNode()
{	
	int tam = 0, vitri = 0;
	do {
		cout << "Nhap vao so hang: "; cin >> h;
		if (h == 0)
			cout << "Nhap sai! Nhap lai: " << endl;
	} while (h == 0);
	do {
		cout << "Nhap so cot: "; cin >> c;
		if (c == 0)
			cout << "Nhap sai! Nhap lai: " << endl;
	} while (c == 0);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			cout << "A[" << i << ", " << j << "]" << " = "; cin >> tam;
			if (tam != 0) {
				vitri++;
				ThemDau(TaoNode(i, j, tam));
			}
		}
	}
	if (vitri > (h*c) / 2) {
		cout << "Khong phai ma tran thua" << endl;
		cout << "Nhap lai:" << endl;
		InNode();
	}
}

Node * List::TaoNode(int row, int col, int data)
{
	Node *p = new Node;
	p->col_tiep = col;
	p->row_tiep = row;
	p->data = data;
	p->Next = NULL;
	return p;
}

void List::ThemDau(Node * p)
{
	if (Head == NULL) {
		Head = Tail = p;
	}
	else {
		p->Next = Head->Next;
		Head = p;
	}
}

void List::ThemCuoi(Node * p)
{
	if (Head == NULL) {
		Head = Tail = p;
	}
	else {
		Tail->Next = p;
		Tail = p;
	}
}
void List::XuatMaTranThua()
{
	int temp[10][10];
	Node * p = Head;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}

	while (p != NULL) {
		temp[p->row_tiep][p->col_tiep] = p->data;
		p = p->Next;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

int ** List::XuatMaTran1()
{
	int ** temp = 0;
	Node *p = Head;
	temp = new int*[h];
	for (int i = 0; i < h; i++) {
		temp[i] = new int[c];
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}

	while (p != NULL) {
		temp[p->row_tiep][p->col_tiep] = p->data;
		p = p->Next;
	}
	return temp;
}

void List::NhanMaTran(int n)
{
	Node *p = Head;
	cout << "Nhap so can nhan: ";
	do {
		cin >> n;
		if (n == 0) {
			cout << "Nhap lai: ";
		}
	} while (n == 0);
	
	while (p != NULL)
	{
		p->data = p->data * n;
		p = p->Next;
	}
	cout << "Ma tran sau khi nhan voi " << n << ":" << endl;
	XuatMaTranThua();
}

// Tao ma tran nho tu ma tran da cho
void List::TaoMaTran(int ** matrix, int **temp, int p, int q)
{
	int i = 0, j = 0;
	for (int row = 0; row < c; row++) {
		for (int col = 0; col < c; col++) {
			if (row != p && col != q) {
				temp[i][j++] = matrix[row][col];
				if (j == c - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}
// Tinh dinh thuc
int List::det(int **matrix, int n)
{
	int D = 0;
	if (n == 1) {
		return matrix[0][0];
	}
	int ** temp = new int*[N];
	for (int i = 0; i < h; i++) {
		temp[i] = new int[h];
	}
	int sign = 1;// kí hieu 

	for (int f = 0; f < n; f++) {
		TaoMaTran(matrix, temp, 0, f);
		D += sign * matrix[0][f] * det(temp, n - 1);
		sign = -sign;
	}
	return D;
}

// Tao ma tran nghich dao
void List::MaTranNghichDao()
{
	double matrix[N][N];
	int ** temp = new int*[N];
	for (int i = 0; i < h; i++) {
		temp[i] = new int[h];
	}

	int sign = 1;
	int det1 = det(XuatMaTran1(), c);
	if (det1 == 0) {
		cout << "Ma tran nay khong kha nghich." << endl;
		return;
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			TaoMaTran(XuatMaTran1(), temp, i, j);
			matrix[i][j] = sign *det(temp, c - 1) * 1/(det1);
			sign = -sign;
		}
	}
	cout << "Ma tran nghich dao la: " << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

List *x = new List;
void menu() {
	cout<<"************___________________MENU__________________*******************"<<endl;
	cout << "1. Tao ma tran thua" << endl;
	cout << "2. Hien thi Ma Tran Thua" << endl;
	cout << "3. Nhan ma tran thua voi 1 so khac 0" << endl;
	cout << "4. Nghich dao cua 1 ma tran thua" << endl;
	cout << "5. Dinh thuc cua 1 ma tran thua" << endl;
	cout << "6. Ket Thuc " << endl;
}
void ChucNang() {
	int n = 0, r = 0, c = 0, temp = 0;
	cout << "Xin chon MeNu:  "; cin >> n;
	switch (n)
	{
	case 1:
		x->InNode();
		system("cls");
		cout << "Da tao ma tran thua!" << endl;	
		menu();
		ChucNang();
		break;
	case 2:
		system("cls");
		cout << "Hien Thi Ma Tran Thua: " << endl;
		x->XuatMaTranThua();
		menu();
		ChucNang();
		break;
	case 3:
		cout << "Nhap so can nhan: "; cin >> temp;
		system("cls");
		x->NhanMaTran(temp);
		menu();
		ChucNang();
		break;

	case 4:
		system("cls");
		if (x->TaoHang() != x->TaoCot()) {
			cout << "Day khong phai la ma tran don vi cap n" << endl;
			cout << "Nhap lai de tinh!!!" << endl;
		}
		else {
			x->MaTranNghichDao();
		}
		menu();
		ChucNang();
		break;
	case 5:
		system("cls");
		if (x->TaoHang() != x->TaoCot()) {
			cout << "Day khong phai la ma tran don vi cap n" << endl;
			cout << "Nhap lai de tinh!!!" << endl;
		}
		else {
			cout << "Dinh thuc ma tran la: " << x->det(x->XuatMaTran1(), r)<< endl;
		}
		menu();
		ChucNang();
		break;
	case 6: 
		return;
	default:
		system("cls");
		cout << "Sai cu phap" << endl;
		menu();
		ChucNang();
		break;
	}
}

int main() {
	menu();
	ChucNang();
	getch();
}

