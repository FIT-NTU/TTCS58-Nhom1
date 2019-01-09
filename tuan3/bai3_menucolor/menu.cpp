#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include<string.h>
#define dau 10
#define cuoi 3
#define MAX1 7
#include <vector>
#include "console1.h"
#include<fstream>
#include <iostream>
using namespace std;
#define max 100
//char tenfile[20]="input.txt";

int n;
int ms;
int maxi=0,mini=0;
struct nhanvien
{
	int manv,songaycong;
	int luong;
	string hoten;
};
vector<nhanvien>ds;

void inmenu(int vt);
void menu(int vt);
 
typedef char xau[80];
xau mnu[7] = {
	"1. Nhap va hien thi thong tin nhan vien ",
	"2. Sap xep nhan vien tang dan theo so ngay cong",
	"3. Nhap ma nhan vien va hien thi thong tin nhan vien ",
	"4. Them thong tin 1 nhan vien moi vao cuoi danh sach ", 
	"5. Xoa nhan vien ",
	"6. Cap nhat thong tin sinh vien ",
	"7. Thoat !!!"};

 
//nhap
void nhap()
{
	do
	{
		cout<<"Nhap n so nhan vien: ";
		cin>>n;
	}while(n<1||n>10);
	for(int i=0;i<n;i++)
	{
		nhanvien nv;
		cout<<"Nhap ma nhan vien (kieu int): ";
		cin>>nv.manv;
		cout<<"Nhap ho va ten nhan vien: ";
		fflush(stdin);
		getline(cin,nv.hoten);
		cout<<"Nhap so ngay cong: ";
		cin>>nv.songaycong;
		nv.luong=nv.songaycong*30000;
		ds.push_back(nv);
		cin.ignore();
	}
	
}

void xuatds()
{
	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"msnv: "<<ds[i].manv<<endl;
		cout<<"Ho ve ten: "<<ds[i].hoten<<endl;
		cout<<"so ngay cong: "<<ds[i].songaycong<<endl;
		cout<<"luong: "<<ds[i].luong<<endl;
	}
}

void sapxep()
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(ds[i].songaycong>ds[j].songaycong)
			{
				nhanvien tam;
				tam=ds[i];
				ds[i]=ds[j];
				ds[j]=tam;
			}
	
}


void nhapma()
{
	int msnvct;
	cout<<"\nnhap ma nhan vien can kiem tra: ";
	cin>>msnvct;
	for(int i=0;i<n;i++) if(ds[i].manv==msnvct)
		{
			cout<<setw(15)<<"ma nhan vien"<<setw(20)<<"Ho va ten"<<setw(15)<<"so ngay cong"<<setw(10)<<"luong"<<endl;
			cout<<setw(15)<<ds[i].manv<<setw(20)<<ds[i].hoten<<setw(15)<<ds[i].songaycong<<setw(10)<<ds[i].luong<<endl;
		}
}
 
bool kiemtra(int maso)
{
	int a=0;
	for(int i=0;i<n;i++)
		if(ds[i].manv==maso) a=1;
			
	if(a==1)return true;
		else return false;
}
 
void them()
{
	cout<<"Nhap thong tin nhan vien can them vao:"<<endl;
		nhanvien nv;
		do{
			cout<<"Nhap ma nhan vien (kieu int): ";
			cin>>nv.manv;
		}while(kiemtra(nv.manv));	
			cout<<"Nhap ho va ten nhan vien: ";
			fflush(stdin);
			getline(cin,nv.hoten);
			cout<<"Nhap so ngay cong: ";
			cin>>nv.songaycong;
			nv.luong=nv.songaycong*30000;
			ds.push_back(nv);
			cin.ignore();
			n++;
	
		
}

void xoa()
{
		int vt,manvcx;
		cout<<"Nhap thong tin nhan vien can xoa:"<<endl;
		nhanvien nv;
		do{
			cout<<"Nhap ma nhan vien (kieu int): ";
			cin>>manvcx;
		}while(!kiemtra(manvcx));	
		for(int i=0;i<n;i++)
			if(ds[i].manv==manvcx) vt=i; 
		ds.erase(ds.begin()+vt);
		n--;
}

void capnhat()
{
	int vt,manvcs;
		cout<<"Nhap thong tin nhan vien can cap nhat:"<<endl;
		nhanvien nv;
		do{
			cout<<"Nhap ma nhan vien (kieu int): ";
			cin>>manvcs;
		}while(!kiemtra(manvcs));	
		for(int i=0;i<n;i++)
			if(ds[i].manv==manvcs) vt=i; 
		
		cout<<"Nhap ho va ten nhan vien: ";
		fflush(stdin);
		getline(cin,nv.hoten);
		cout<<"Nhap so ngay cong: ";
		cin>>nv.songaycong;
		nv.luong=nv.songaycong*30000;
		ds[vt]=nv;
		ds[vt].manv=manvcs;
		
	
}
 //doc nhan vien
//void doc(char* tenfile)
//{
//	fstream file;
//	file.open(tenfile,ios::in);
//	if (file.fail())
//		cout<<"khong mo duoc file !!"<<endl;
//	else
//		{	
//			while(!file.eof())
//			{
//				nhanvien nv;
//				file>>nv.manv;
//				file.getline(nv.hoten,max);
//				file>>nv.songaycong;
//				nv.luong=nv.songaycong*30000;
//				ds.push_back(nv);
//				file.ignore();
//			}								
//		file.close();
//		int n=ds.size();
//		for(int i=0;i<n;i++)
//			{
//				cout<<ds[i].manv<<endl;
//				cout<<ds[i].hoten<<endl;
//				cout<<ds[i].songaycong<<endl;
//				cout<<ds[i].luong<<endl;
//			
//			}
//		}
//	
//}



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
    printf("Le Tuan Tai 58131379");
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
        	case 1: vt=1;break;
            case 72: vt--; if (vt==0) vt=7; break;
            case 80: vt++; if (vt==8) vt=1; break;
            case 27: exit(0);
        }
    } while (c!=13);
    switch (vt)
        {
            case 1: clrscr();
					cout<<"1. Nhap va hien thi danh sach nhan vien\n";
					nhap();
					xuatds();
					cout<<endl<<" --->Enter de quay lai menu.";
					getch();
					//doc(tenfile); 
					menu(vt);
					break;
            case 2: clrscr();
					cout<<"2. Sap xep nhan vien tang dan theo so ngay cong\n"; 
					sapxep();
					xuatds();
					
					cout<<endl<<" --->Enter de quay lai menu.";
					getch();
					menu(vt);
			  break;
            case 3: clrscr();
				cout<<"3. Nhap ma nhan vien va hien thi thong tin nhan vien\n";
			
				nhapma();
				
				cout<<endl<<" --->Enter de quay lai menu.";
				getch(); 
				menu(vt);
				break;
            case 4: clrscr();
				cout<<"4. Them thong tin 1 nhan vien moi vao cuoi danh sach \n";
				them();
				xuatds();
				cout<<endl<<" --->Enter de quay lai menu.";
				getch();
				menu(vt);
				break;
            case 5: clrscr(); 
		
				cout<<"5. Xoa nhan vien \n";
				xoa();
				xuatds();
				cout<<endl<<" --->Enter de quay lai menu.";
				getch();
				menu(vt);
			 	break;
            case 6: 
            	clrscr();
				cout<<"6. Cap nhat thong tin sinh vien \n";
				capnhat();
				xuatds();
            	cout<<endl<<" --->Enter de quay lai menu.";
				getch();
				menu(vt);
            case 7:exit(0);
        }
}
 

