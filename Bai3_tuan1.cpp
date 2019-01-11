//Hovaten: Sam Van Quan, MSSV: 58131370
// SDT: 0352609900; email: vanquanntuk58@gmail.com
#include <iomanip>
#include <conio.h>
#include <string.h>
#include<fstream>
#include <iostream>
using namespace std;
#define MAX 50
int n,MSNV;
int Max=0,Min=0;
struct NhanVien
{
	string Ho,Ten;
	int MNV,Luong;
};
NhanVien a[MAX];
void Nhap()
{
	ifstream file;
	file.open("input3.txt", ios::in);
	file>>n;
	for(int i=1;i<=n;i++)
	{
		file>>a[i].MNV;
		string temp;
		getline(file,temp);
		getline(file,a[i].Ho);
		getline(file,a[i].Ten);
		file>>a[i].Luong;
	}
}
int TimVaIn(int MSNV)
{ 
	for(int i=1;i<=n;i++) if(a[i].MNV == MSNV)
		{
			return i;
		}else return -1;
}
void LuongNV()
{
	Max=a[1].Luong;
	Min=a[1].Luong;
	for(int i=2;i<=n;i++) 
		{
				if(a[i].Luong > Max)
			{
					Max=a[i].Luong;
					
			}
			if(a[i].Luong < Min)
				{
					Min = a[i].Luong;
					
				}
		}
	
		
	cout<<"\nNhan Vien co luong cao nhat la: ";
	for(int i=1;i<=n;i++) if(a[i].Luong == Max)
		{
			cout<<"    "<<a[i].MNV<<"    "<<a[i].Ho<<"    "<<a[i].Ten<<"    "<<a[i].Luong<<endl;
		}
	cout<<"Nhan vien co luong thap nhat la: ";	
	for(int i=1;i<=n;i++) if(a[i].Luong == Min)
		{
			cout<<"     "<<a[i].MNV<<"     "<<a[i].Ho<<"    "<<a[i].Ten<<"    "<<a[i].Luong<<endl;
		}
}
void SapXep()
{
	NhanVien b;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i].Ten.compare(a[j].Ten)==0)
			{
			
				if(a[i].Ho.compare(a[j].Ho)>0)
					{
						b=a[i];
						a[i]=a[j];
						a[j]=b;
					}
			}
			 else if(a[i].Ten.compare(a[j].Ten)>0)
					{
						b=a[i];
						a[i]=a[j];
						a[j]=b;
					}
				
		}
}
void GhiFile()
{
	ofstream file;
	file.open("output3.txt", ios::out);
	file<<"thong tin nhan vien can kiem tra:\n";
	for(int i=1;i<=n;i++) if(a[i].MNV == MSNV)
		{
			file<<"   "<<a[i].MNV<<"    "<<a[i].Ho<<"    "<<a[i].Ten<<"     "<<a[i].Luong<<endl;
		}
	file<<"Nhan vien co luong cao nhat:  "<<endl;
	for(int i=1;i<=n;i++) if(a[i].Luong == Max)
		{
			file<<"    "<<a[i].MNV<<"      "<<a[i].Ho<<"    "<<a[i].Ten<<"     "<<a[i].Luong<<endl;
		}
	file<<"Nhan Vien co luong thap nhat: "<<endl;
	for(int i=1;i<=n;i++) if(a[i].Luong == Min)
		{
			file<<"    "<<a[i].MNV<<"     "<<a[i].Ho<<"     "<<a[i].Ten<<"      "<<a[i].Luong<<endl;
		}
	file<<"danh sach sau khi sap xep:\n";
	file<<"     "<<"Ma NV: "<<"     "<<"Ho lot: "<<"     "<<"Ten"<<"    "<<"Luong:  "<<endl;
			for(int i=1;i<=n;i++)
	{
		file<<"      "<<a[i].MNV;
		file<<"      "<<a[i].Ho;
		file<<"      "<<a[i].Ten;
		file<<"      "<<a[i].Luong;
		file<<endl;
	}
	
}
void Menu()
{
	cout<<"Ho va ten: Sam Van Quan"<<endl;
	cout<<"MSSV: 58131370"<<endl;
	cout<<"********___Menu___********"<<endl;
	cout<<"1. Doc thong tin nhan vien tu file  input3.txt"<<endl;
	cout<<"2. Nhap ma nhan vien va hien thi thong tin nhân vien "<<endl; 
	cout<<"3. Cho biet ho ten nhan vien co luong cao nhat va thap nhat "<<endl; //
	cout<<"4. Sap xep nhan vien tang dan theo ten ( cung ten theo ho)"<<endl;
	cout<<"5. Ghi tat ca vao file output3.txt!!"<<endl;
	cout<<"6. Het ^^"<<endl;
}
int ChonMenu()
{
	int n=0;
	cout<<"\nMoi chon yeu cau:";
	cin>>n;
	if(n > 0 || n < 6) return n;
		else return ChonMenu();
}

void XuLyMenu()
{
	int chon;
	int mnv;
	chon=ChonMenu();
	switch(chon)
	{
		case 1:{
			cout<<"1. Doc thong tin nhan vien tu file  input3.txt"<<endl;
			Nhap();
			break;
			}
		case 2:{
			cout<<"2. Nhap ma nhan vien: ";
			cin>>mnv;
			if(TimVaIn(mnv)!=-1)
			{
				cout<<a[TimVaIn(mnv)].MNV<<"\t"<<a[TimVaIn(mnv)].Ho<<"\t"<<a[TimVaIn(mnv)].Ten<<"\t"<<a[TimVaIn(mnv)].Luong;
			}
			else cout<<"Khong tim thay Nhan vien nay";
			break;
			}
		case 3:{
			cout<<"3. Cho biet ho ten nhan vien co luong cao nhat va thap nhat "<<endl;
			LuongNV();
			break;
			}
		case 4:{
			cout<<"4. Sap xep nhan vien tang dan theo ten ( cung ten theo ho) "<<endl;
			cout<<"\tDa sap xep thanh cong ! ";SapXep();
			break;
			}
		case 5:{
			GhiFile();
			cout<<"5. Da ghi tat ca vao file output3.txt "<<endl;
			break;
			}
		case 6:{
			cout<<"6. Het ^^ "<<endl;
			exit(1);
			break;
			}		
	}
}
int main()
{
	
	Menu();
	while(1)
	{
		XuLyMenu();
	}

	getch();
}


