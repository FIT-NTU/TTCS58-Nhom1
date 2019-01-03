#include <iostream>
using namespace std;

struct Node
{
	int x;
	int y;
	int gt;
	struct Node *next;
};

Node *ds=new Node; // Khai bao bien co kieu du lieu la node

void menu();
void chon();
void tao();
void xuat();
 
void menu()
{
	cout << "-----------------Menu-------------------"<<endl;
	cout << "1.Tao ma tran." << endl;
	cout << "2.Hien thi ma tran thua."<<endl;
	cout << "3.Nhan ma tran voi mot so khac 0."<<endl;
	cout << "4.Nghich dao ma tran." << endl;
	cout << "5.Dinh thuc cua ma tran." << endl;
	cout << "6.Cong tru nhan chia 2 ma tran thua."<<endl;
	cout << "----------------------------------------"<<endl;
}

void chon()
{
	int select;
	cout << "Nhap vao lua chon cua ban: ";
	cin >> select;
	switch (select)
	{
		case 1:
			tao();
			menu();
			chon();
			break;
		case 2:
			xuat();
			menu();
			chon();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			cout << "Ket thuc!"<<endl;
			break;
		default:
			system("cls");
			menu();
			cout << "Chon sai !"<<endl;
			chon();
	}
}

void tao()
{
	ds -> next = NULL;
	Node *a=new Node;
	cout << "Nhap vao so hang: ";
	cin >> a->x;
	cout << "Nhap vao so cot: ";
	cin >> a->y;
	
	//Gioi han kich thuoc cho ma tran thua
	a->gt=a->x * a->y;
	a->next = ds->next;
	ds->next=a;
	
	// Nhap du lieu vao danh sach
	int tam;
	int  dem = a->gt /2;
	bool quit = false;
	cout << "An 0 de thoat!"<<endl;
	while (!quit)
	{
		cout << "Nhap vao tao do x: ";
		cin >> tam;
		if (tam == 0)
		{
			quit = true;
		}
		else
		{
			a = new Node;
			a->x=tam;
			cout << "Nhap vao tao do y: ";
			cin >> tam;
			if (tam == 0)
			{
				quit = true;
			}
			else
			{
				a->y=tam;
				cout << "Nhap vao gia tri: ";
				cin >> tam;
				if (tam = 0)
				{
					quit == true;
				}
				else
				{
					a->gt=tam;
					a->next=ds->next;
					ds->next=a;
					dem--;
				}
			}
		}
		if (dem == 0)
		{
			quit = true;
			cout << "Ma tran day!"<<endl;
		}
	}
}

void xuat()
{
	
}

int main ()
{
	menu();
	chon();
}

