#include<iostream>
using namespace std;
#include<string.h>
#include<vector>
#include<stdio.h>
struct NhanVien{
	char ma[4]; 
	char hoten[50];
	int songaycong,luong;
};
vector<NhanVien> ds;	

void Nhap(NhanVien &nv)
{
	cout << "\nNhap ma nhan vien: "; fflush(stdin);
	gets(nv.ma);
	cout << "\nNhap ho ten nhan vien: ";
	fflush(stdin); gets(nv.hoten); 
	cout << "\nNhap vao so ngay cong cua nhan vien: ";
	cin >> nv.songaycong;	
}
void NhapDS(vector<NhanVien> &ds)
{
	int n = ds.size();
	for(int i = 0; i < n ;i++)
		Nhap(ds[i]);
}
void DocFile(){
	FILE *f;
	f=fopen("input3.txt", "rb");
	if(f==NULL)
		cout<<"\nMo file khong thanh cong. Xin kiem tra lai!";
	else
		while(!feof(f)){
			NhanVien nv;
			fread(&nv, sizeof(NhanVien), 1, f);
			ds.push_back(nv);
		}
	fclose(f);
	ds.pop_back();
}
void InNV(NhanVien &nv){
	nv.luong = nv.songaycong*300000;
	cout <<nv.ma<<"\t"<<nv.hoten<<"\t"<<nv.songaycong<<"\t"<<nv.luong<<endl;	
}
void InDSNV()
{
	int n = ds.size();
	cout << "Ma nhan vien: " << "\tHo ten: " << "\tSo ngay cong: " << "\tLuong: " << endl;
	for(int i=0; i<n; i++)
		InNV(ds[i]);
}
void SapXep()
{
	int n = ds.size();
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ds[i].songaycong > ds[j].songaycong)
			{
				int tam = ds[i].songaycong;
				ds[i].songaycong = ds[j].songaycong;
				ds[j].songaycong = tam;
			}
		}
	}
}
int TimMSNV(char *ma)
{
	int n = ds.size();
	for(int i=0;i<n;i++)
	{
		if(strcmp(ma, ds[i].ma)==0)
			return i;
			break;
	}
	return -1;
}
void ThemNV()
{
	NhanVien nv;
	do
	{
		cout <<"Nhap ma nhan vien can them: ";
		fflush(stdin);
		gets(nv.ma);
	}while(TimMSNV(nv.ma) != -1);
	cout <<"Nhap ho ten nhan vien: ";fflush(stdin);
	gets(nv.hoten);
	cout <<"Nhap vao so ngay cong: ";cin >> nv.songaycong;
	ds.push_back(nv);
	cout <<"Da them nhan vien!"<<endl;
}
void XoaNV(){
	char ma[4];
	cout << "\nNhap ma nhan vien: "; fflush(stdin);
	gets(ma);
	int t = TimMSNV(ma);
	if(t==-1)	cout << "\nKhong tim thay nhan vien can xoa\n";
	else
		ds.erase(ds.begin()+t);
}
void CapNhat()
{
	NhanVien nv;
	char ma[4];
	cout << "\nNhap ma nhan vien: "; fflush(stdin);
	gets(nv.ma);
	int tam = TimMSNV(nv.ma);
	if(tam == -1) cout<<"\nKhong tim thay nhan vien can tim\n";
	else{
		cout << "\nNhap ho ten nhan vien: ";
		fflush(stdin); gets(nv.hoten); 
		cout << "\nNhap vao so ngay cong cua nhan vien: ";
		cin >> nv.songaycong;
	}
	if(strcmp(nv.hoten,"0")!=0)
		strcpy(ds[tam].hoten, nv.hoten);
	if(nv.songaycong!=0)
		ds[tam].songaycong=nv.songaycong;
}

void ShowMenu()
{
	cout << "\n---------------------MENU---------------------\n";
	cout << "1. Nhap thong tin danh sach nhan vien" << endl;
	cout << "2. In ra danh sach nhan vien" << endl;
	cout << "3. Sap xep nhan vien tang dan theo so ngay cong" << endl;
	cout << "4. Tim kiem theo ma nhan vien" << endl;
	cout << "5. Them mot nhan vien vao cuoi danh sach" << endl;
	cout << "6. Xoa mot nhan vien ra khoi danh sach theo ma" << endl;
	cout << "7. Cap nhat thong tin nhan vien theo ma" << endl;
	cout << "8. Ket thuc" << endl;
	cout << "\n---------------------END-------------------\n";
}

void Chon()
{
	NhanVien nv;
	int n;
	int select;
	cout << "\nLua chon cua ban la: ";
	cin >> select;

	switch (select)
	{
		case 1:
			system("cls");
			do
			{
				cout <<"nhap so luong nhan vien: "; 
				cin>> n;
			}while(n<0||n>10);
			ds.resize(n);
			NhapDS(ds);
			system("pause");
			break;
		case 2:
			system("cls");
			cout<<"\nIn danh sach nhan vien vua nhap\n";
			InDSNV();
			system("pause");
			break;
		case 3:
			system("cls");
			cout<<"\nSap xep nhan vien tang dan theo so ngay cong\n";
			SapXep();
			InDSNV();
			system("pause");
			break;
		case 4:
			{
				system("cls");
				cout<<"\nTim kiem theo ma nhan vien\n";
				char ma[4]; cout << "\nNhap ma nhan vien: "; fflush(stdin);
				gets(ma);
				int tam = TimMSNV(ma);
				if(tam == -1)	cout<< "\nKhong tim thay nhan vien can tim\n";
				else	
				cout<<"\nThong tin nhan vien vua tim duoc la: \n";
				InNV(ds[tam]);
				system("pause");	
				break;
			}
		case 5:
			system("cls");
			cout<<"\nThem nhan vien vao ds nhan vien\n";
			ThemNV();
			cout<<"\nNhan vien da them vao ds nhan vien\n";
			InDSNV();
			system("pause");
			break;
		case 6:
			system("cls");
			cout<<"\nXoa nhan vien ra khoi ds nhan vien\n";
			XoaNV();
			cout<<"\nDanh sach nhan vien sau khi xoa\n";
			InDSNV();
			system("pause");
			break;
		
		case 7:
			system("cls");
			cout<<"\nCap nhat nhan vien theo ma nhan vien\n";
			CapNhat();			
			break;
		case 8:
			exit(1);
			break;
	}
}

int main()
{
	DocFile();
	
	while(1)
	{
		system("cls");
		ShowMenu();
		Chon();
	}
	system("pause");
}
