#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#define MAX 10
#define MIN 0

using namespace std;
typedef struct nhanvien NhanVien;
struct nhanvien
{
	string hoten;
	int manv;
	int ngaycong;
	int luong;	
};
NhanVien nv[10];
int n;
void nhap ()
{
	cout<<"Nhap so luong nhan vien : ";
	cin>>n;
	do
	if(n <= MIN || n > MAX)
	{
		cout<<"\nKhong hop le ! Moi nhap lai !";
		break;
	}
	while(n <= MIN || n > MAX);	
	for ( int i = 0; i < n; i++)
	{
		cout<<"Nhap ho ten:";
		cin>>nv[i].hoten;
		cout<<"Nhap ID: ";
		cin>>nv[i].manv;
		cout<<"Nhap so luong ngay cong: ";
		cin>>nv[i].ngaycong;
		nv[i].luong=nv[i].ngaycong*300000;
		cout<<"  "<<endl;
	}
}

void xuat ()
{
	cout<<"\n---------------------\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"Ho ten nhan vien: "<<nv[i].hoten<<endl;
		cout<<"ID nhan vien: "<<nv[i].manv<<endl;
		cout<<"So ngay cong: "<<nv[i].ngaycong<<endl;
		cout<<"Tien luong: "<<nv[i].luong<<endl;
	}
						

}


void sx()
{
	for (int i = 0; i < n - 1; i++) 
	{
		for(int j = i; j < n; j++)
		{
			if(nv[i].ngaycong > nv[j].ngaycong) 
			{
				swap(nv[i],nv[2]);
			}
		}
	}
	
}

void timnv ()
{
	int id;
	cout << "Nhap ma nhan vien : ";
	cin >> id;
	for (int i = 0; i < n; i++)
	{
		if (id==nv[i].manv)
		{
			cout<<"ID nhan vien can tim: "<<nv[i].manv<<endl;
			cout<<"Ho ten nhan vien can tim: "<<nv[i].hoten<<endl;
			cout<<"So ngay cong: "<<nv[i].ngaycong<<endl;
			cout<<"Tien luong: "<<nv[i].luong<<endl;
		}
	
	}
}

void xoanv ()
{
	int id;
	cout<<"Nhap ma nhan vien: ";
	cin.ignore(); //xoa bo nho dem
	cin>>id;
	for (int i=0;i<n;i++)
	{
		if (nv[i].manv==id)
		{
			for (int j=i; j<n; j++)
			{
				nv[j]=nv[j+1];
			n--;
			}
		}
	}
	
}

void suanv ()
{
	int id;
	cout<<"Nhap ma nhan vien: ";
	cin.ignore();
	cin>>id;
	for (int i=0;i<n;i++)
	{
		if (nv[i].manv==id)
		{
			cout<<"Nhap ho ten: ";
			cin>>nv[i].hoten;
			cout<<"Nhap so ngay cong: ";
			cin>>nv[i].ngaycong;
			nv[i].luong=nv[i].ngaycong*30000;
			
		}
		
	}
	xuat();
}

void themnv() 
{
		cout<<"Nhap ho ten:";
		cin>>nv[n].hoten;
		cout<<"Nhap ID: ";
		cin>>nv[n].manv;
		cout<<"Nhap so luong ngay cong: ";
		cin>>nv[n].ngaycong;
		nv[n].luong=nv[n].ngaycong*300000;
		n += 1;
		
		xuat();
}


void menu()
{
	
	int lc;
	cout<<"1. Nhap thong tin nhan vien"<<endl;
	cout<<"2. Sap xep danh sach nhan vien"<<endl;
	cout<<"3. Tim kiem nhan vien"<<endl;
	cout<<"4. Them nhan vien"<<endl;
	cout<<"5. Xoa nhan vien"<<endl;
	cout<<"6. Cap nhat thong tin nhan vien"<<endl;

}


void lcmenu(NhanVien nv[], int n)
{
	int lc;
	cout<<"\nNHAP LUA CHON: ";
	cin>>lc;
		switch (lc)
		{
			case 1:
				
				nhap();
				xuat();
				getch();
				system("cls");
				menu();
				lcmenu(nv, n);
				
				break;
			case 2:
				sx();
				xuat();
				getch();
				system("cls");
				menu();
				lcmenu(nv, n);
				
				break;
			case 3:
				timnv();
				getch();
				system("cls");
				menu();
				lcmenu(nv, n);
				break;
			case 4:
				themnv();
				getch();
				system("cls");
				menu();
				lcmenu(nv, n);
				break;	
			case 5:
				xoanv();
				xuat();
				getch();
				system("cls");
				menu();
				lcmenu(nv, n);
				break;
			case 6:
				suanv();
				getch();
				system("cls");
				menu();
				lcmenu(nv, n);
		}
}


int main()
{
	int n;
	menu();
	lcmenu(nv,n);
	return 0;
}
