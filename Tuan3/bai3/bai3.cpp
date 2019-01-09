#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<fstream>

using namespace std;
// khai bao kieu du lieu nhan vien
struct NhanVien{
	int nvID;
	string HoTen;
	int NgayCong;
	int Luong;
};
NhanVien nv,nvMoi;
// danh sach nhan vien co kieu du lieu la nhanvien
vector <NhanVien> dsnv;
// cac ham trong chuong trinh
bool ThemNV(NhanVien nv);
bool XoaNV(int nvID);
void CapNhat(NhanVien nvMoi);
void TimNV(int nvID);
void inNV(NhanVien nv);
void inDSNV();
NhanVien Nhapbp();
void DocDS(ifstream &f,vector<NhanVien> &dsnv);
void GhiDS(ofstream &f,vector<NhanVien> &dsnv);
void menu();
int luachon();
void thuchien(vector<NhanVien> &dsnv,ofstream &f);
// ham chinh
int main(){
	ifstream infile;
	ofstream outfile;
	outfile.open("output3.txt");
	infile.open("input3.txt");
	DocDS(infile,dsnv);
		while (1)
	{
		system("cls");
	thuchien(dsnv,outfile);
	}
}

// them nv
bool ThemNV(NhanVien nv){
	int size = dsnv.size();
	for(int i = 0; i < size; i++)
	if(nv.nvID == dsnv[i].nvID)
		return false;
	dsnv.push_back(nv);
		return true;
}
// xoa nv
bool XoaNV(int nvID){
	int size = dsnv.size();
	int vitri = -1;
	for(int i= 0; i < size; i++){
		if(nvID == dsnv[i].nvID)
			vitri= i;
	}
	if(vitri != -1){
		dsnv.erase(dsnv.begin()+ vitri);
		return true;
	}
	return false;
}
// cap nhat nv
void CapNhat(NhanVien nvMoi){
	int size = dsnv.size();
	int vitri = -1;
	for(int i = 0; i < size; i++){
		if(nvMoi.nvID == dsnv[i].nvID)
		vitri = i;
	}
	if(vitri != -1){
		dsnv[vitri].nvID=nvMoi.nvID;
			dsnv[vitri].HoTen=nvMoi.HoTen;
			dsnv[vitri].NgayCong=nvMoi.NgayCong;
			dsnv[vitri].Luong=nvMoi.NgayCong*30000;
	}
}
// tim nv
void TimNV(int nvID)
{		int k;
		int size = dsnv.size();
	for(int i = 0; i < size; i++)
	if(nvID == dsnv[i].nvID)//kiem tra xem thu co ton tai nhan vien hay khong
	{
		cout <<"Thong tin nhan vien co ma: "<<nvID<<endl;
		inNV(dsnv[i]);//neu tim thay thi xuat ra thong tin nhan vien
		k = 1;
	}
	if(k != 1)
	cout <<"Khong tim thay nhan vien."<<endl;//thong bao neu khong tim thay nhan vien
}
//sapxep nhan vien theo ngay cong
void SapXep(){
	int size = dsnv.size();
	for(int i = 0; i < size-1; i++){
		for(int j =i+1; j < size; j++){
			if(dsnv[i].NgayCong > dsnv[j].NgayCong)
				swap(dsnv[i],dsnv[j]);
		}
	}
}
//nhap nv tu ban phim
NhanVien Nhapbp(){
	NhanVien nv;
	cout<<"Nhap ma nv: ";
	cin>>nv.nvID;
	cout<<"Nhap ten nv :";fflush(stdin);
	getline(cin,nv.HoTen);
	cout<<"Nhap NgayCong: ";
	cin>>nv.NgayCong;
	nv.Luong= nv.NgayCong*300000;
	return nv;
}
// nhap ds tu ban phim
NhanVien Nhapbp1(){
	cout<<"nhap vao so luong nv: "<<endl;
		int n;
	cin>> n;
	dsnv.resize(n);
	for(int i = 0; i < n; i++){
		dsnv[i]=Nhapbp();
	}
	return nv;
}
// in 1 nv
void inNV(NhanVien nv){
	cout <<" maNv "<< nv.nvID << endl;
	cout <<" tenNV "<<nv.HoTen  << endl;
	cout <<" NgayCong "<<nv.NgayCong << endl;
	cout <<" luongNV "<< nv.Luong << endl;
}
// in dsnv
void inDSNV(){
	int size=dsnv.size();
	for(int i = 0;i < size; i++)
		inNV(dsnv[i]);
}
void Ghifile(ofstream &outfile,NhanVien &NV)
{
	//ghi vao file du lieu 1 nhan vien
	outfile<<NV.nvID<<endl;
	outfile<<NV.HoTen<<endl;
	outfile<<NV.NgayCong<<endl;
	outfile<<NV.Luong<<endl;
}

void Docfile(ifstream &infile,NhanVien &NV)
{
	//doc tu file du lieu 1 nhan vien
	infile>>NV.nvID;
	string temp;
	
	getline(infile,temp);
	getline(infile,NV.HoTen);
	infile>>NV.NgayCong;
	NV.Luong=NV.NgayCong*300000;
}

void DocDS(ifstream &f,vector<NhanVien> &dsnv)
{
	//doc tu file danh sach nhan vien.
	int n;
	f>>n;
	dsnv.resize(n);
	for(int i = 0; i< dsnv.size(); i++)
	{
		Docfile(f,dsnv[i]);
	}
}

void GhiDS(ofstream &f,vector<NhanVien> &dsnv)
{
	//ghi vao file danh sach nhan vien
	f << dsnv.size()<<endl;
	for(int i = 0; i<dsnv.size();i++)
	{
		Ghifile(f,dsnv[i]);
	}
}
// menu chuc nang
void Menu()
{
	cout << "Cac chuc nang cua chuong trinh:" << endl;
	cout << "1: nhap vao nv tu ban phim. "<< endl;
	cout << "2: Sap Xep "<<endl; 
	cout << "3: Them 1 nhan vien." << endl;
	cout << "4: Xoa 1 nhan vien theo ma nhan vien." << endl;
	cout << "5: Cap Nhat 1 nhan vien theo ma nhan vien." << endl;
	cout << "6: Tim kiem thong tin 1 nhan vien theo ma." << endl;
	cout << "7: In danh sach nhan vien." << endl;
	cout << "8: Ghi danh sach vao file."<<endl;
	cout << "9: Thoat chuong trinh."<<endl;
	
}
//  lua chon chuc nang
int luachon(){
	int chon; 
	cout << "Nhap chuc nang muon thuc hien: ";
	cin >> chon;
	return chon;
}
// thuc hien chuc nang
void thuchien(vector<NhanVien> &dsnv,ofstream &f){
		Menu();
	int chon = luachon();
	switch (chon)
	{
	case 1:
		system("cls");
		Nhapbp1();
		system("pause");
		break;
	case 2:
		system("cls");
		cout<<" ds nhan vien da sap xep theo ngay cong: ";
		SapXep();
		system("pause");
		break;
	case 3:
		system("cls");
		 nv = Nhapbp();
		ThemNV(nv);
		system("pause");
		break;
	case 4:
		int nvID;
		cout<<"nhap ma nv can xoa";
		cin>> nvID;
		system("cls");
		XoaNV(nvID);
		system("pause");
		break;
	case 5:
		system("cls");
		cout<< "nhap thong tin nv can sua";
		nvMoi = Nhapbp();
		CapNhat(nvMoi);
		system("pause");
		break;
	case 6:
		system("cls");
		cout<<"nhap ma nv can tim";
		int ID;
		cin>> ID;
		TimNV(ID);
		system("pause");
		break;
	case 7:
		system("cls");
		inDSNV();
		system("pause");
		break;
	case 8:
		system("cls");
		GhiDS(f,dsnv);
		cout <<"Da ghi vao file output3.txt."<<endl;
		system("pause");
		break;
	case 9:
		cout <<"Cam on ban da su chung chuong trinh"<<endl;
		exit(1);
		break;
	
	}
}
