#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;

int n,a;

struct nhanVien
{
	int tuoi, ma, luong;
	string ten;
};

typedef struct nhanVien nv;

//Khai bao toan bo cac ham co trong chuong trinh
void nhap();
void nhapDSNV();
void xuat();
void xuatDSNV();
void kiemTra();
void xoaNV();
void capNhat();
void timKiem();
void ghifile();
void menu();
void chon();

// Nhap thong tin nhan vien
void nhap(nhanVien &nv)
{
	cout<<"Ma: ";
	cin>>nv.ma;
	cout<<"Ho ten: ";
	cin.ignore();
	getline(cin,nv.ten);
	cout<<"Tuoi: ";
	cin>>nv.tuoi;
	cout<<"Luong: ";
	cin>>nv.luong;
}

//Nhap danh sach nhan vien
void nhapDSNV(vector<nv> &ds)
{	
	cout<<"Nhap vao so luong nhan vien: ";
	cin>>n;
	ds.resize(n); // tinh toan kich thuoc cua danh sach
	for(int i=0;i<ds.size();i++)  // cho vong lap chay tu dau toi cuoi danh sach
	{
		nhap(ds[i]);
	}
}

//Xuat thong tin nhan vien
void xuat(nhanVien nv)
{
	cout<<"Ma: "<<nv.ma<<endl;
	cout<<"Ten: "<<nv.ten<<endl;
	cout<<"Tuoi: "<<nv.tuoi<<endl;
	cout<<"Luong: "<<nv.luong<<endl;
}

//Xuat danh sach nhan vien
void xuatDSNV(vector<nv> ds)
{	
	cout << "---------------------------"<<endl;
	cout << "Danh sach nhan vien hien co."<<endl;
	for(int i=0;i<ds.size();i++)
	{
		xuat(ds[i]);
	}
}

// kiem tra nhan vien da co trong danh sach hay chua
int  kiemTra(vector<nv> ds, int manv) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
{	
	for(int i=0;i<ds.size();i++)
	{
		if(ds[i].ma==manv)
		return i;
	}
	return -1;
}

// kiem tra dieu kien va them nhan vien vao
void themNV(vector<nv> &ds)
{
	nhanVien nv;
	nhap(nv);
	if(kiemTra(ds,nv.ma)==-1)//Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		ds.push_back(nv); 
	}
	else 
		cout<<"Ma nhan vien da ton tai"<<endl;
}

//kiem tra dieu kien va xoa nhan vien
void xoaNV(vector <nv> &ds)
{	
	int x, manv;
	nhanVien nv;
	cout<<"Nhap ma nhan vien can xoa:";
	cin>>manv;
	if(kiemTra(ds,manv)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Ma nhan vien khong ton tai"<<endl;
	}
	else 
	{	
		x=kiemTra(ds,manv);
		ds.erase(ds.begin()+x); // xoa phan tu tai vi tri x
	}
}

// kiem tra dieu kien sau do sua
void capNhat(vector <nv> &ds)
{	
	nhanVien nv;
	int manv, x;
	cout<<"Nhap ma nhan vien can cap nhat: ";
	cin>>manv;
	if(kiemTra(ds,manv)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Khong tim thay nhan vien co ma nay."<<endl;
	}
	else 
	{	
		x=kiemTra(ds,manv);
		cout<<"Ho ten:";
		cin.ignore();
		getline(cin,nv.ten); // nhan khoang trang 
		cout<<"Tuoi: ";
		cin>>nv.tuoi;
		cout<<"Luong:";
		cin>>nv.luong;
		ds[x].ten=nv.ten; 
		ds[x].tuoi=nv.tuoi;
		ds[x].luong=nv.luong;
	}
}

// kiem tra dieu kien roi  sau do tim
void timKiem(vector <nv> ds)
{
	nhanVien nv;
	int manv,x;
	cout<<"Nhap ma nhan vien can tim: ";
	cin>>manv;
	if(kiemTra(ds,manv)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Ma nhan vien vua nhap khong ton tai."<<endl;
	}
	else 
	{
		x=kiemTra(ds,manv);
		cout<<"============================"<<endl;
		cout<<"Thong tin nhap vien can tim: "<<endl;
		xuat(ds[x]);
	}
}

void ghifile(vector<nv> ds)
{	
	fstream f;
	f.open("output2.txt");
	for(int i=0;i<ds.size();i++)
	{
		f<<"Ma: "<<ds[i].ma<<endl;
		f<<"Ten: "<<ds[i].ten<<endl;
		f<<"Tuoi: "<<ds[i].tuoi<<endl;
		f<<"Luong: "<<ds[i].luong<<endl;
	}
	f.close();
}

void menu()
{
	cout<<"___________ Menu ____________"<<endl;
	cout<<"1.Them 1 nhan vien."<<endl;
	cout<<"2.Xoa nhan vien theo ma."<<endl;
	cout<<"3.Cap Nhat nhan vien theo ma."<<endl;
	cout<<"4.Tim kiem thong tin nhan vien theo ma."<<endl;
	cout<<"5.In danh sach nhan vien vao file."<<endl;
	cout<<"6.Thoat."<<endl;
	cout<<"-----------------------------"<<endl;
}

void chon(vector <nv> ds)
{	
	menu();
	int select ;
	cout<<"Nhap vao lua chon cua ban: ";
	cin>>select;
	switch(select)
	{					
		case 1: 
			cout<<"Nhap thong tin nhan vien can them. "<<endl;
//			cin.ignore(); // xoa bo nho dem.
			themNV(ds);
			xuatDSNV(ds);
			chon(ds);
			break;
		case 2 :
			xoaNV(ds);
			xuatDSNV(ds);
			chon(ds);
			break;
		case 3:	
			capNhat(ds);
			xuatDSNV(ds);
			chon(ds);	
			break;
		case 4:
			timKiem(ds);
			chon(ds);	
			break;
		case 5:
			ghifile(ds);
			cout<<"Da ghi du lieu vao file!"<<endl;
			chon(ds);
			break;
		case 6:
			exit(0);
			break;
		default:
			cout<<"Moi ban nhap lai (1=>6): "<<endl;
			chon(ds);
	}	
}

int main()
{	
	vector <nv> employee;
	nhapDSNV(employee);
	chon(employee);
}
