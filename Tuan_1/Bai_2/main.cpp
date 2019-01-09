#include<iostream>
#include <vector>
using namespace std;
#define N 10
struct node {
	int value;
	int row_position;
	int col_position;
	struct node *next;
};
typedef struct node Node;

class List {
private:
	int r=0, c=0;
	Node *head, *tail;
public:
	List();
	List(int r, int c);
	int GetRow();
	int GetCol();

	Node *createNode(int row, int col, int value);
	void inputList();
	
	void addFirst(Node *p);
	void addLast(Node *p);

	void outputNode();
	void outputSparseMatric();
	int **outputSparseMatric1();
	
	void multiNumber(int n);
	void detSmallMatrix(int ** matrix, int ** temp, int p, int q);
	int det(int ** matrix, int n);
	void inverse();
};


List::List(int row, int col)
{
	r = row;
	c = col;
}

int List::GetRow()
{
	return r;
}

int List::GetCol()
{
	return c;
}

void List::inputList()
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
			cout << "A[" << i << ", " << j << "]" << " = "; cin >> temp;
			if (temp != 0) {
				index++;
				addLast(createNode(i, j, temp));
			}
		}
	}
	if (index > (c*r) / 2) {
		cout << "Khong phai ma tran thua" << endl;
		cout << "Nhap lai:" << endl;
		inputList();
	}
}

Node * List::createNode(int row, int col, int value)
{
	Node *p = new Node;
	p->col_position = col;
	p->row_position = row;
	p->value = value;
	p->next = NULL;
	return p;
}

void List::addFirst(Node * p)
{
	if (head == NULL) {
		head = tail = p;
	}
	else {
		p->next = head->next;
		head = p;
	}
}

void List::addLast(Node * p)
{
	if (head == NULL) {
		head = tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}

// Xuat ra danh sach cac node
void List::outputNode()
{
	if (head == NULL) {
		cout << "Danh sach rong" << endl;
		return;
	}
	Node * temp = head;
	while (temp != NULL)
	{
		cout << "Row: " << temp->row_position << ", Col: " << temp->col_position << ", Value: " << temp->value << ";" << endl;
		temp = temp->next;
	}
}

// Xuat ra ma tran 2 chieu tu link list
void List::outputSparseMatric()
{
	int temp[10][10];
	Node * p = head;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}

	while (p != NULL) {
		temp[p->row_position][p->col_position] = p->value;
		p = p->next;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

// Tao mang 2 chieu tu link list
int ** List::outputSparseMatric1()
{
	int ** temp = 0;
	Node *p = head;
	temp = new int*[r];
	for (int i = 0; i < r; i++) {
		temp[i] = new int[c];
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}

	while (p != NULL) {
		temp[p->row_position][p->col_position] = p->value;
		p = p->next;
	}
	return temp;
}

// Nhan voi 1 so khac 0
void List::multiNumber(int n)
{
	Node *p = head;
	cout << "Nhap so can nhan: ";
	do {
		cin >> n;
		if (n == 0) {
			cout << "Nhap lai: ";
		}
	} while (n == 0);
	
	while (p != NULL)
	{
		p->value = p->value * n;
		p = p->next;
	}
	cout << "Ma tran sau khi nhan voi " << n << ":" << endl;
	outputSparseMatric();
}

// Tao ma tran nho tu ma tran da cho
void List::detSmallMatrix(int ** matrix, int **temp, int p, int q)
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

List::List()
{
	head = tail = NULL;
}

// Tinh dinh thuc
int List::det(int **matrix, int n)
{
	int D = 0;
	if (n == 1) {
		return matrix[0][0];
	}
	int ** temp = new int*[N];
	for (int i = 0; i < r; i++) {
		temp[i] = new int[r];
	}
	int sign = 1;

	for (int f = 0; f < n; f++) {
		detSmallMatrix(matrix, temp, 0, f);
		D += sign * matrix[0][f] * det(temp, n - 1);
		sign = -sign;
	}
	return D;
}

// Tao ma tran nghich dao
void List::inverse()
{
	double matrix[N][N];
	int ** temp = new int*[N];
	for (int i = 0; i < r; i++) {
		temp[i] = new int[r];
	}

	int sign = 1;
	int det1 = det(outputSparseMatric1(), c);
	if (det1 == 0) {
		cout << "Ma tran nay khong kha nghich." << endl;
		return;
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			detSmallMatrix(outputSparseMatric1(), temp, i, j);
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

List *x = new List;
void menu() {
	cout << "1. Tao ma tran thua" << endl;
	cout << "2. Hien thi ma tran thua dang link list" << endl;
	cout << "3. Hien thi ma tran thua dang array" << endl;
	cout << "4. Nhan ma tran thua voi 1 so khac 0" << endl;
	cout << "5. Nghich dao cua 1 ma tran thua" << endl;
	cout << "6. Dinh thuc cua 1 ma tran thua" << endl;
	cout << "7. Thoat" << endl;
}

void select() {
	int n = 0, r = 0, c = 0, temp = 0;
	cout << "Lua chon: "; cin >> n;
	switch (n)
	{
	case 1:
		x->inputList();
		system("cls");
		cout << "Da tao ma tran thua!" << endl;	
		menu();
		select();
		break;
	case 2:
		system("cls");
		cout << "Ma tran thua dang link list la: " << endl;
		x->outputNode();
		menu();
		select();
		break;
	case 3:
		system("cls");
		cout << "Ma tran thua dang array: " << endl;
		x->outputSparseMatric();
		menu();
		select();
		break;
	case 4:
		cout << "Nhap so can nhan: "; cin >> temp;
		system("cls");
		x->multiNumber(temp);
		menu();
		select();
		break;

	case 5:
		system("cls");
		if (x->GetRow() != x->GetCol()) {
			cout << "Day khong phai la ma tran don vi cap n" << endl;
			cout << "Nhap lai de tinh!!!" << endl;
		}
		else {
			x->inverse();
		}
		menu();
		select();
		break;
	case 6:
		system("cls");
		if (x->GetRow() != x->GetCol()) {
			cout << "Day khong phai la ma tran don vi cap n" << endl;
			cout << "Nhap lai de tinh!!!" << endl;
		}
		else {
			cout << "Dinh thuc ma tran la: " << x->det(x->outputSparseMatric1(), r)<< endl;
		}
		menu();
		select();
		break;
	case 7: 
		return;
	default:
		system("cls");
		cout << "Sai cu phap" << endl;
		menu();
		select();
		break;
	}
}

int main() {
	menu();
	select();
	system("pause");
}

