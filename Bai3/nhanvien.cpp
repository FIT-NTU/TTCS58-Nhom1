#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
FILE*f;
typedef struct{
char NhanVienID[4];
char hoTen[20];
int tuoi;
int luong;
} NhanVien ;
vector <NhanVien> dsNV;
bool themNV(NhanVien nv);
void inNV(NhanVien nv);
void inDSNV();
NhanVien NhapNVtuBP();
bool xoaNV(char* nvID);
void CapNhatNV(NhanVien nvMoi);
void DocFile();
void GhiFile();
int main(){
	NhanVien nv1,nv2;
	strcpy(nv1.NhanVienID,"001");
	strcpy(nv1.hoTen,"Nguyen Van A");
	nv1.tuoi=30;
	nv1.luong=30000;
	strcpy(nv2.NhanVienID,"002");
	strcpy(nv2.hoTen,"Nguyen Van B");
	nv2.tuoi=35;
	nv2.luong=34000;
	themNV(nv1);
	themNV(nv2);
	inDSNV();
	NhanVien nv3=NhapNVtuBP();
	//in ds nhan vien sau khi them
	themNV(nv3);
	inDSNV();
	//in ds nhan vien sau khi xoa
//	xoaNV("002");
	inDSNV();
	NhanVien nvMoi=NhapNVtuBP();
	CapNhatNV(nvMoi);
	cout<<"danh sach nhan vien sau khi cap nhat:\n";
	inDSNV();
	DocFile();
	inDSNV();
    GhiFile();
    inDSNV();
	}
	
bool themNV(NhanVien nv){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		if(strcmp(nv.NhanVienID,dsNV[i].NhanVienID)==0)
		return false;
		dsNV.push_back(nv);
	return true;
}	
void inNV(NhanVien nv){
	cout <<" maNv "<< nv.NhanVienID << endl;
	cout <<" tenNV "<<nv.hoTen  << endl;
	cout <<" tuoiNV "<<nv. tuoi << endl;
	cout <<" luongNV "<< nv.luong << endl;
}
void inDSNV(){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		inNV(dsNV[i]);
}
NhanVien NhapNVtuBP(){
	NhanVien nv;
	cout<<"Nhap ten nv:";fflush(stdin);
	gets(nv.hoTen);
	cout<<"Nhap ma nv:";fflush(stdin);
	gets(nv.NhanVienID);
	cout<<"Nhap tuoi nv:";
	cin>>nv.tuoi;
	cout<<"Nhap luong nv:";
	cin>>nv.luong;
	return nv;
}
bool xoaNV(char* nvID){
		int size=dsNV.size();
		int vtxoa=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvID,dsNV[i].NhanVienID)==0){
			vtxoa=i;
			break;
		}
		if(vtxoa!=-1){
			dsNV.erase(dsNV.begin()+vtxoa);
			return true;
		}
		return false;
}
void CapNhatNV(NhanVien nvMoi){
		int size=dsNV.size();
		int vtCapNhat=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvMoi.NhanVienID,dsNV[i].NhanVienID)==0){
			vtCapNhat=i;
			break;
		}
	if(vtCapNhat!=-1){	
		strcpy(dsNV[vtCapNhat].NhanVienID,nvMoi.NhanVienID);
			strcpy(dsNV[vtCapNhat].hoTen,nvMoi.hoTen);
			dsNV[vtCapNhat].tuoi=nvMoi.tuoi;
			dsNV[vtCapNhat].luong=nvMoi.luong;
}}
void DocFile(){
	f=fopen("fileName","rb");
	if(f!=NULL)
	{
		while(!feof(f))
		{
			NhanVien nv;
			fread(&nv,sizeof(NhanVien),1,f);
			dsNV.push_back(nv);
			}
		fclose(f);
		dsNV.pop_back();
		}
		}
void GhiFile()	{
	int size=dsNV.size();
	FILE*f;
	f=fopen("fileName","wb");
	NhanVien nv;
	for(int i=0;i<size;i++){
		nv=dsNV[i];
		fwrite(&nv,sizeof(NhanVien),1,f);
		}
	}
	

