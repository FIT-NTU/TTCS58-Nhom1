#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "console1.h"
#define dau 10
#define cuoi 3
#define MAX1 6

using namespace std;

struct NhanVien
{
	char nvID[4],hoTen[21];
	int tuoi,luong;	
};

vector<NhanVien> dsNV;

char tenfile[20]="dulieu.txt";


bool themNV(NhanVien nv);
bool xoaNV(char* nvID);
bool capnhatNV(NhanVien nvMoi);
NhanVien NhapNV();
void docDSNV(char* tenfile);
void ghiDSNV(char* tenfile);
void inDSNV();

void Menu();
int chonMenu();
void xulyMenu();

void inmenu(int vt);
void menu(int vt);
 
typedef char xau[80];
xau mnu[6] = {
	"1. Hien thi danh sach nhan vien ",
	"2. Them nhan vien ",
	"3. Xoa nhan vien ", 
	"4. Cap nhat thong tin nhan vien",
	"5. Ghi danh sach vao file",
	"6. Thoat !!!  "};





int main()
{
	docDSNV(tenfile);
while(1)
	{ 
		
		menu(1);
	}

	
	system("pause");
}






bool themNV(NhanVien nv)
{
	int n=dsNV.size();
	for(int i=0;i<n;i++)
		if(strcmp(dsNV[i].nvID,nv.nvID)==0) return false;
	dsNV.push_back(nv);
	return true;
}

void inDSNV()
{
	cout<<"Danh sach nhan vien: \n";
	int n=dsNV.size();
	for(int i=0;i<n;i++)
		{
			cout<<dsNV[i].nvID<<endl;
			cout<<dsNV[i].hoTen<<endl;
			cout<<dsNV[i].tuoi<<endl;
			cout<<dsNV[i].luong<<endl;
		}
}


bool xoaNV(char* nvId)
{
	int n=dsNV.size();
	int vt=-1;
	for(int i=0;i<n;i++) 
		if(strcmp(dsNV[i].nvID,nvId)==0)
		{
			vt=i;
			break;
		} 
	if(vt==-1) return false;	
	else 
	{
		dsNV.erase(dsNV.begin()+vt);
		return true;
	}
}


bool capnhatNV(NhanVien nvMoi)
{
	int n=dsNV.size();
	int vt=-1;
	for(int i=0;i<n;i++) 
		if(strcmp(dsNV[i].nvID,nvMoi.nvID)==0)
		{
			vt=i;
			break;
		} 
	if(vt==-1) return false;	
	else 
	{
		strcpy(dsNV[vt].hoTen,nvMoi.hoTen);
		dsNV[vt].tuoi=nvMoi.tuoi;
		dsNV[vt].luong=nvMoi.luong;
		return true;
	}
}


NhanVien NhapNV()
{
	NhanVien nv;
	cout<<" Nhap ma so nhan vien: "<<endl;
	fflush(stdin);
	gets(nv.nvID);
	cout<<" Nhap ho ten nhan vien: "<<endl;
	fflush(stdin);
	gets(nv.hoTen);
	cout<<" Nhap tuoi nhan vien: "<<endl;
	cin>>nv.tuoi;
	cout<<" Nhap luong nhan vien: "<<endl;
	cin>>nv.luong;
	return nv;
}

void docDSNV(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::in);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{
			while(!file.eof())
			{	
				NhanVien nv;
					
				file.getline(nv.nvID,4);
				
				file.getline(nv.hoTen,21);
				file>>nv.tuoi;
				file>>nv.luong;
				dsNV.push_back(nv);	
				file.ignore();						
			}
			file.close();			
		}
}
void ghiDSNV(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::out);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{
			int n=dsNV.size();
			for(int i=0;i<n-1;i++)
			{
				file<<dsNV[i].nvID<<endl;
				file<<dsNV[i].hoTen<<endl;
				file<<dsNV[i].tuoi<<endl;
				file<<dsNV[i].luong<<endl;				
			}
			file<<dsNV[n-1].nvID<<endl;
			file<<dsNV[n-1].hoTen<<endl;
			file<<dsNV[n-1].tuoi<<endl;
			file<<dsNV[n-1].luong;			
		}
}

void inmenu(int vt)
{
    int i;
    clrscr();
    gotoXY(dau,cuoi); TextColor(12);
    gotoXY(dau-10,cuoi+1); TextColor(6);
    printf(" Le Tuan Tai 58131379 ");
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
					cout<<"1. Danh sach nhan vien: \n";
					
					inDSNV();
					cout<<endl<<" --->Enter de quay lai menu.";
					getch();
					menu(vt);
					break;
            case 2: clrscr();
					cout<<"2. Them nhan vien \n"; 
					if(themNV(NhapNV())) cout<<"\nDa Them nhan vien "<<endl;
						else cout<<"\nKhong co nhan vien tren trong danh sach"<<endl;
					inDSNV();
					cout<<endl<<" --->Enter de quay lai menu.";
					getch();
					menu(vt);
			  break;
            case 3: clrscr();
				cout<<"3. Xoa nhan vien: \n";
				cout<<" Nhap id nhan vien can xoa: ";
				char temp[4];
				gets(temp);
				if(xoaNV(temp)) cout<<"\nDa xoa nhan vien "<<endl;
					else cout<<"\nKhong co nhan vien tren trong danh sach"<<endl;
				inDSNV();
				cout<<endl<<" --->Enter de quay lai menu.";
				getch();
				menu(vt);
				break;
            case 4: clrscr();
				cout<<"4. Cap nhat thong tin nhan vien \n";
				if(capnhatNV(NhapNV())) cout<<"\nDa cap nhat thong tin nhan vien "<<endl;
						else cout<<"\nKhong co nhan vien tren trong danh sach"<<endl;
				inDSNV();
				cout<<endl<<" --->Enter de quay lai menu.";
				getch();
				menu(vt);
				break;
            case 5: clrscr(); 
				ghiDSNV(tenfile);
				cout<<"5. Da ghi tat ca vao file dulieu.txt\n";
				cout<<endl<<" --->Enter de quay lai menu.";
				getch();
				menu(vt);
			 	break;
            case 6: exit(0);
        }
}
