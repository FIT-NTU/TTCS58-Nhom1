#include<stdio.h>
#include<iostream>
#include<vector>
#include "console1.h"

using namespace std;

struct NhanVien
{
	char nvID[4],hoTen[20];
	int tuoi,luong;	
};

vector<NhanVien> dsNV;

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





int main()
{
	NhanVien nv1,nv2,nvMoi;
	strcpy(nv1.nvID,"123");
	strcpy(nv1.hoTen,"le tuan tai");
	nv1.tuoi=23;
	nv1.luong=3000;
	
	strcpy(nv2.nvID,"456");
	strcpy(nv2.hoTen,"nguyen van a");
	nv2.tuoi=22;
	nv2.luong=2000;
	
	strcpy(nvMoi.nvID,"456");
	strcpy(nvMoi.hoTen,"nguyen van b");
	nvMoi.tuoi=23;
	nvMoi.luong=3000;
	
	themNV(nv1);
	themNV(nv2);
	
	xoaNV("123");	
	
	capnhatNV(nvMoi);
	inDSNV();
	NhapNV();
	
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
	gets(nv.nvID);
	cout<<" Nhap tuoi nhan vien: "<<endl;
	cin>>nv.tuoi;
	cout<<" Nhap luong nhan vien: "<<endl;
	cin>>nv.luong;
}

