#include <iomanip>
#include <stdio.h>
#include <conio.h>
#define dau 10
#define cuoi 3
#define MAX1 6
#include "console1.h"
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

void inmenu(int vt);
void menu(int vt);
 
typedef char xau[80];
xau mnu[6] = {
	"1. Doc thong tin nhan vien tu file  input3.txt",
	"2. Nhap ma nhan vien va hien thi thong tin nhân vien ",
	"3. Cho biet ho ten nhan vien co luong cao nhat va thap nhat ", //ki tu dau tien moi8 tu viet hoa
	"4. Sap xep nhan vien tang dan theo ten ( cung ten theo ho)",
	"5. Ghi tat ca vao file output3.txt!!",
	"6. Thoat !!!"};

 

 
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
	cout<<endl<<" --->Enter de quay lai menu.";
   getch();
}


//nhap ma
void nhapma()
{
	
	cout<<"nhap ma nhan vien can kiem tra: ";
	cin>>ms;
	int dem=0;
	for(int i=1;i<=n;i++) if(a[i].manv==ms)
		{
			dem=dem+1;
			cout<<setw(10)<<a[i].manv<<setw(10)<<a[i].holot<<setw(10)<<a[i].ten<<setw(10)<<a[i].luong<<endl;
		}
	if(dem==0)cout<<"khong co ho so nhan vien voi ma tren";
	cout<<endl<<" --->Enter de quay lai menu.";
	getch();
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
	cout<<endl<<" --->Enter de quay lai menu.";
	getch();
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
	for(int i=1;i<=n;i++)
	{
		cout<<setw(10)<<a[i].manv;
		cout<<setw(10)<<a[i].holot;
		cout<<setw(10)<<a[i].ten;
		cout<<setw(10)<<a[i].luong;
		cout<<endl;
	}
			
	cout<<endl<<" --->Enter de quay lai menu.";
	getch();
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
	
	cout<<"Da ghi vao file ouput3.txt.";
	cout<<endl<<" --->Enter de quay lai menu.";
	getch();
}

 
main()
{
	while(1)
	{ menu(1);
	}
   
}
 
void inmenu(int vt)
{
    int i;
    clrscr();
    gotoXY(dau,cuoi); TextColor(12);
    gotoXY(dau-10,cuoi+1); TextColor(6);
    printf("Le Tuan Tai 58131379 chu y: phai doc du lieu tu file truoc moi co du lieu ");
    for (i=1; i<=MAX1; i++)
        {
            if (i==vt) TextColor(2);
            else TextColor(7);
            gotoXY(dau-1,cuoi+1+i); printf(mnu[i-1]);
        }
}
 
void menu(int vt)
{
    char c;
    do
    {
        inmenu(vt);
        gotoXY(80,25);
        c=getch();
        switch (c)
        {
        	
            case 72: vt--; if (vt==0) vt=6; break;
            case 80: vt++; if (vt==7) vt=1; break;
            case 27: exit(0);
        }
    } while (c!=13);
    switch (vt)
        {
            case 1: clrscr();
					cout<<"1. Doc thong tin nhan vien tu file  input3.txt\n";
					doc(); 
					menu(vt);
					break;
            case 2: clrscr();
					cout<<"2. Nhap ma nhan vien va hien thi thong tin nhan vien \n"; 
					nhapma();
					
					menu(vt);
			  break;
            case 3: clrscr();
				cout<<"3. Cho biet ho ten nhan vien co luong cao nhat va thap nhat \n";
				luongminmax(); 
				menu(vt);
				break;
            case 4: clrscr();
				cout<<"4. Sap xep nhan vien tang dan theo ten ( cung ten theo ho)\n";
				sapxep(); 
				menu(vt);
				break;
            case 5: clrscr(); 
				ghi();
				cout<<"5. Da ghi tat ca vao file output3.txt!!\n";
				menu(vt);
			 	break;
            case 6: exit(0);
        }
}
 

