#include <iomanip>
#include <conio.h>
#include <string.h>
#include<fstream>
#include <iostream>
using namespace std;
#define MAX 50
int n;
int ms;
int maxi=0,mini=0;
struct nhanvien
{
	int manv,luong;
	string holot,ten;
};
nhanvien a[MAX];




//doc nhan vien
void doc()
{
	
	ifstream file;
	file.open("input3.txt", ios::in);
	file>>n;
	for(int i=1;i<=n;i++)
	{
		file>>a[i].manv;
		file>>a[i].holot;
		file>>a[i].ten;
		file>>a[i].luong;
	}

   
}


//nhap ma
void nhapma()
{
	
	cout<<"nhap ma nhan vien can kiem tra: ";
	cin>>ms;
	for(int i=1;i<=n;i++) if(a[i].manv==ms)
		{
			cout<<setw(10)<<a[i].manv<<setw(10)<<a[i].holot<<setw(10)<<a[i].ten<<setw(10)<<a[i].luong<<endl;
		}
}

//xuat luon min max
void luongminmax()
{
	maxi=a[1].luong;
	mini=a[1].luong;
	for(int i=2;i<=n;i++) 
		{
			if(a[i].luong>maxi) 
				{
					maxi=a[i].luong;
					
				}
			if(a[i].luong<mini)
				{
					mini=a[i].luong;
					
				}
		}
	
		
	cout<<"\nluong cao nhat: ";
	for(int i=1;i<=n;i++) if(a[i].luong==maxi)
		{
			cout<<setw(10)<<a[i].manv<<setw(10)<<a[i].holot<<setw(10)<<a[i].ten<<setw(10)<<a[i].luong<<endl;
		}
	cout<<"luong thap nhat: ";	
	for(int i=1;i<=n;i++) if(a[i].luong==mini)
		{
			cout<<setw(10)<<a[i].manv<<setw(10)<<a[i].holot<<setw(10)<<a[i].ten<<setw(10)<<a[i].luong<<endl;
		}
}

//sap xep
void sapxep()
{
	nhanvien b;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i].ten.compare(a[j].ten)==0)
			{
			
				if(a[i].holot.compare(a[j].holot)>0)
					{
						b=a[i];
						a[i]=a[j];
						a[j]=b;
					
					}
			}
			 else if(a[i].ten.compare(a[j].ten)>0)
					{
						b=a[i];
						a[i]=a[j];
						a[j]=b;
					
					}
				
		}
			

}

//ghi vao file
void ghi()
{
	ofstream file;
	file.open("output3.txt", ios::out);
	file<<"thong tin nhan vien can kiem tra:\n";
	for(int i=1;i<=n;i++) if(a[i].manv==ms)
		{
			file<<setw(10)<<a[i].manv<<setw(10)<<a[i].holot<<setw(10)<<a[i].ten<<setw(10)<<a[i].luong<<endl;
		}
	file<<"luong cao nhat:  ";
	for(int i=1;i<=n;i++) if(a[i].luong==maxi)
		{
			file<<setw(10)<<a[i].manv<<setw(10)<<a[i].holot<<setw(10)<<a[i].ten<<setw(10)<<a[i].luong<<endl;
		}
	file<<"luong thap nhat: ";	
	for(int i=1;i<=n;i++) if(a[i].luong==mini)
		{
			file<<setw(10)<<a[i].manv<<setw(10)<<a[i].holot<<setw(10)<<a[i].ten<<setw(10)<<a[i].luong<<endl;
		}
	file<<"danh sach sau khi sap xep:\n";
	file<<setw(10)<<"maNV"<<setw(10)<<"Holot"<<setw(10)<<"Ten"<<setw(10)<<"Luong"<<endl;
			for(int i=1;i<=n;i++)
	{
		file<<setw(10)<<a[i].manv;
		file<<setw(10)<<a[i].holot;
		file<<setw(10)<<a[i].ten;
		file<<setw(10)<<a[i].luong;
		file<<endl;
	}
	
}

void Menu();		// Ham nay se xuat ra cac danh sach menu
int ChonMenu();		// Ham nay dung de chon 1 menu tuong ung
void XuLyMenu();	// Xu ly menu ung voi menu duoc chon


void Menu()
{
	cout<<"Le Tuan Tai 58131379\n\n\n";
	cout<<"===============MENU==============\n";
	cout<<"1. Doc thong tin nhan vien tu file  input3.txt\n";
	cout<<"2. Nhap ma nhan vien va hien thi thong tin nhân vien \n"; 
	cout<<"3. Cho biet ho ten nhan vien co luong cao nhat va thap nhat \n"; //ki tu dau tien moi8 tu viet hoa
	cout<<"4. Sap xep nhan vien tang dan theo ten ( cung ten theo ho)\n";
	cout<<"5. Ghi tat ca vao file output3.txt!!\n";
	cout<<"9. Thoat !!!\n";
	cout<<"==================================\n";
}


int ChonMenu()
{
	int n=0;
	cout<<"\n\nMoi chon yeu cau:";
	cin>>n;
	if(n > 0 || n < 9) return n;
		else return ChonMenu();
}

void XuLyMenu()
{
	int chon;
	chon=ChonMenu();
	switch(chon)
	{
		case 1:
			cout<<"1. Doc thong tin nhan vien tu file  input3.txt\n";
			doc();
			break;
		case 2:
			cout<<"2. Nhap ma nhan vien va hien thi thong tin nhan vien \n"; 
			nhapma();
			break;
		case 3:
			cout<<"3. Cho biet ho ten nhan vien co luong cao nhat va thap nhat \n";
			luongminmax();
			break;
		case 4:
			cout<<"4. Sap xep nhan vien tang dan theo ten ( cung ten theo ho)\n";
			sapxep();
			break;
		case 5:
			ghi();
			cout<<"5. Da ghi tat ca vao file output3.txt!!\n";
			break;
		case 9:
			cout<<"9. Thoat !!!\n\n\n";
			cout<<"THANK YOU";
			exit(1);
			break;		
	}
}
int main()
{
	Menu();
	while(1)
	{
		XuLyMenu();
	}

	_getch();
}


