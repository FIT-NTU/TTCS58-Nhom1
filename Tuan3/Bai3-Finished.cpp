#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<vector>
#include<windows.h>
#include<bits/stdc++.h>
#include<fstream> 

using namespace std;

struct nhanVien{
	string hoten;
	long int id;
	int ngaycong;
	long int luong;
};
typedef struct nhanVien nv;

vector< nv > dsnv;

bool IDtontai(int target){
	for (int i=0; i<dsnv.size(); i++)
	{
		if (dsnv[i].id==target) return true;
	}
	return false;
}

void nhap(){
	int n;
	cout<<"Nhap so luong nhan vien muon them vao: "; cin>>n;
	if (n<=0)
	{
		cout<<"So duoc nhap vao <=0, vay la ban khong can them nhan vien nao.\n";
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			nv temp;
			cout<<"\nNhap thong tin cho nhan vien thu "<<i+1<<endl;
			cout<<"ID: "; cin>>temp.id;
			while (IDtontai(temp.id))
			{
				cout<<"ID nay da ton tai.\n";
				cout<<"Hay nhap lai ID: "; cin>>temp.id;
			}
			cout<<"Ho ten: "; fflush(stdin); getline(cin, temp.hoten);
			cout<<"So ngay cong: "; cin>>temp.ngaycong;
			temp.luong = temp.ngaycong * 300000;
			
			dsnv.push_back(temp);
		}
		cout<<"\n\nDa nhap xong danh sach "<<n<<" nhan vien.";
	}
}

//void nhapTuFile(string file_name){
//	const char* real_name;
//	real_name = file_name.c_str();
//	ifstream infile;
//	infile.open(real_name);
//	while (!infile.eof())
//	{
//		nv temp;
//		fflush(stdin); getline(infile, temp.hoten);
//		infile>>temp.id; infile.ignore(256, '\n');
//		infile>>temp.ngaycong; infile.ignore(256, '\n');
//		temp.luong = temp.ngaycong * 300000;
//		dsnv.push_back(temp);
//	}
//	cout<<"\n\nDA LAY XONG DSNV TU FILE.";
//	infile.close();
//}

void xuat(){
	cout<<"\nHo ten:\t\t\tID:\t\tNgay cong:\tLuong:";
	for (int i=0; i<dsnv.size(); i++)
	{
		cout<<"\n";
		cout<<left<<setw(24)<<dsnv[i].hoten;
		cout<<left<<setw(16)<<dsnv[i].id;
		cout<<left<<setw(16)<<dsnv[i].ngaycong;
		cout<<dsnv[i].luong;
		cout<<endl;
	}
}

bool _lambda(nv nv1, nv nv2) { 
    return (nv1.ngaycong < nv2.ngaycong); 
} 
void sapxep(){
	sort(dsnv.begin(), dsnv.end(), _lambda);
}

void timkiem(long int target){
	for (int i=0; i<dsnv.size(); i++)
	{
		if (dsnv[i].id==target)
		{
			cout<<"\nHo ten: "<<dsnv[i].hoten;
			cout<<"\nID: "<<dsnv[i].id;
			cout<<"\nSo ngay cong: "<<dsnv[i].ngaycong;
			cout<<"\nLuong: "<<dsnv[i].luong;
			cout<<endl;
			break;
		}
		else if (i==dsnv.size()-1)
		{
			cout<<"\nKhong tim thay nhan vien.";
		}
	}
}

void themnhanvien(){
	nv temp;
	cout<<"\nNhap thong tin cho nhan vien can them:\n";
	cout<<"\nID: "; cin>>temp.id;
	while (IDtontai(temp.id))
	{
		cout<<"ID nay da ton tai.\n";
		cout<<"Hay nhap lai ID: "; cin>>temp.id;
	}
	cout<<"\nHo ten: "; fflush(stdin); getline(cin, temp.hoten);
	cout<<"\nSo ngay cong: "; cin>>temp.ngaycong;
	temp.luong = temp.ngaycong * 300000;
	dsnv.push_back(temp);
}

void xoanhanvien(int target){
	for(int i=0; i<dsnv.size(); i++)
	{
		if (dsnv[i].id==target)
		{
			dsnv.erase(dsnv.begin() + i);
			cout<<"\nDa xoa nhan vien.";
			break;
		}
		else if (i==dsnv.size()-1)
		{
			cout<"\nKhong tim thay nhan vien.";
		}
	}
}

void capnhatnhanvien(int target){
	for(int i=0; i<dsnv.size(); i++)
	{
		if (dsnv[i].id==target)
		{
			string ht;
			long int id, lg;
			int nc;
			cout<<"\nNhap lai ho ten, nhap 0 de giu ten cu: "; fflush(stdin); getline(cin, ht);
			if (ht.compare("0")!=0) dsnv[i].hoten = ht;
			cout<<"\nNhap lai ID, nhap 0 de giu id cu: "; cin>>id;
			if (id!=0) dsnv[i].id = id;
			cout<<"\nNhap lai so ngay cong, nhap 0 de giu so ngay cong cu: "; cin>>nc;
			if (nc!=0) dsnv[i].ngaycong = nc;
			dsnv[i].luong = dsnv[i].ngaycong * 300000;
			break;
		}
		else if (i==dsnv.size()-1)
		{
			cout<<"\nKhong tim thay nhan vien can sua.";
		}
	}
}

main(){
	while (true)
	{
		int control;
		system("cls");
		cout<<"0. Thoat chuong trinh.\n";
		cout<<"1. Nhap danh sach nhan vien.\n";
		cout<<"2. Tim kiem nhan vien.\n";
		cout<<"3. Xoa nhan vien.\n";
		cout<<"4. Sua mot nhan vien.\n";
		cout<<"5. Xuat danh sach nhan vien.\n";
		cout<<"6. Them nhan vien.\n";
//		cout<<"7. Lay danh sach nhan vien tu file.\n";
		cout<<"Nhap dieu muon lam: "; cin>>control;
		while (control > 6 /*7*/ or control < 0)
		{
			cout<<"\nChi duoc nhap so tu 0 den 6.\n";
			cout<<"Hay nhap lai: "; cin>>control;
		}
		if (control==0)
		{
			cout<<"\nNhap <ENTER> de thoat chuong trinh.";
			break;
		}
		if (control==1)
		{
			nhap();
			getch();
		}
		if (control==2)
		{
			long int target;
			cout<<"\nNhap id cua nhan vien can tim: "; cin>>target;
			timkiem(target);
			getch();
		}
		if (control==3)
		{
			long int target;
			cout<<"\nNhap id cua nhan vien can xoa: "; cin>>target;
			xoanhanvien(target);
			getch();
		}
		if (control==4)
		{
			long int target;
			cout<<"\nNhap id cua nhan vien can sua: "; cin>>target;
			capnhatnhanvien(target);
			getch();
		}
		if (control==5)
		{
			sapxep();
			xuat();
			getch();
		}
		if (control==6)
		{
			themnhanvien();
			cout<<"\nDa them nhan vien vao danh sach.";
			getch();
		}
//		if (control==7)
//		{
//			string file_name;
//			cout<<"\nNhap ten file: "; fflush(stdin); getline(cin, file_name);
//			nhapTuFile(file_name);
//			getch();
//		}
	}
	getch();
}
