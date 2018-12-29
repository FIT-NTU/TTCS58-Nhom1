#include<iostream>
#include<conio.h>
#include<string.h>
#include<vector>
#include<bits/stdc++.h> 
#include<iomanip>
#include<fstream>
#include<windows.h>

using namespace std;

struct NhanVien{
	long int maNV;
	string holot;
	string ten;
	long int luong;
};
typedef struct NhanVien nv;

bool checkEmpty(){
	ifstream infile;
	infile.open("input3.txt");
	string s;
	getline(infile, s);
	if (s[0]=='\0') return true;
	return false;
}

void nhapVaoFile(){
	vector< nv > a;
	int n;
	cout<<"Nhap so luong nhan vien (<=50 nhan vien): "; cin>>n;
	while (n>50 or n<1)
	{
		cout<<"So luong nhan vien khong duoc lon hon 50 va khong duoc nho hon 1.\n";
		cout<<"Hay nhap lai so luong nhan vien: "; cin>>n;
	}
	a.resize(n);
	ofstream outfile;
	outfile.open("input3.txt", ios::out | ios::app);
	for(int i=0; i<n; i++)
	{
		if (!checkEmpty()) outfile << endl;
		system("cls");
		cout<<"Nhap ma nhan vien cua nhan vien thu "<<i+1<<": "; cin>>a[i].maNV; outfile << a[i].maNV << endl;
		cout<<"Nhap ho lot cua nhan vien thu "<<i+1<<": "; fflush(stdin); getline(cin, a[i].holot); outfile << a[i].holot << endl;
		cout<<"Nhap ten cua nhan vien thu "<<i+1<<": "; fflush(stdin); getline(cin, a[i].ten); outfile << a[i].ten << endl;
		cout<<"Nhap luong cua nhan vien thu "<<i+1<<": "; cin>>a[i].luong; outfile << a[i].luong;
	}
	outfile.close();
}

nv createNV(long int ma, string hl, string tn, long int lg){
	nv res;
	res.maNV = ma;
	res.holot = hl;
	res.ten = tn;
	res.luong = lg;
	return res;
}

void docFile(vector< nv > &res){
	res.resize(0);
	ifstream infile;
	infile.open("input3.txt");
	while (!infile.eof())
	{
		nv temp;
		long int ma, lg;
		string hl, tn;
		infile>>ma; infile.ignore(256, '\n');
		getline(infile, hl);
		getline(infile, tn);
		infile>>lg; infile.ignore(256, '\n');
		temp = createNV(ma, hl, tn, lg);
		res.push_back(temp);
	}
	infile.close();
}

void xoaTTNV(){
	ofstream outfile;
	outfile.open("input3.txt", ios::trunc);
	outfile.close();
	cout<<"Da xoa thong tin nhan vien";
	getch();
}

void truyXuatTheoMaNhanVien(vector< nv > a){
	ofstream outfile;
	outfile.open("output3.txt", ios::app);
	int target;
	cout<<"Nhap ma nhan vien cua nhan vien can truy xuat: "; cin>>target;
	for(int i=0; i<a.size(); i++)
	{
		if (a[i].maNV==target)
		{
			cout<<"\nHo ten: "<<a[i].holot + " " + a[i].ten; outfile << a[i].holot + " " + a[i].ten << endl;
			cout<<"\nMa nhan vien: "<<a[i].maNV; outfile << a[i].maNV << endl;
			cout<<"\nLuong: "<<a[i].luong; outfile << a[i].luong << endl;
			break;
		}
		else if (i==a.size()-1)
		{
			cout<<"\nKhong tim thay nhan vien nao.";
			outfile<<"\nKhong tim thay nhan vien nao.\n";
		}
	}
	outfile.close();
	getch();
}

void TenNVLuongCaoNhatVaThapNhat(vector< nv > a){
	ofstream outfile;
	outfile.open("output3.txt", ios::app);
	nv maxLuong=a[0], minLuong=a[0];
	for (int i=1; i<a.size(); i++)
	{
		if (a[i].luong>maxLuong.luong)
		{
			maxLuong=a[i];
		}
		if (a[i].luong<minLuong.luong)
		{
			minLuong=a[i];
		}
	}
	cout<<"\nNhan vien co luong thap nhat la: "<<minLuong.holot + " " + minLuong.ten + " - " << minLuong.luong; outfile <<"max luong: " + minLuong.holot + " " + minLuong.ten + " - " << minLuong.luong << endl;
	cout<<"\nNhan vien co luong cao nhat la: "<<maxLuong.holot + " " + maxLuong.ten + " - " << maxLuong.luong; outfile <<"min luong: " + maxLuong.holot + " " + maxLuong.ten + " - " << minLuong.luong << endl;
	outfile.close();
	getch();
}

bool SSanhTen(nv nv1, nv nv2){
	if (nv1.ten[0]<nv2.ten[0]) return true;
	else if (nv1.ten[0]==nv2.ten[0]) return (nv1.holot[0]<nv2.holot[0]);
}

void SXepTen(vector< nv > &a){
	sort(a.begin(), a.end(), SSanhTen); 
}

void xuatRaFileDanhSachTenNhanVienSauSapXep(vector< nv > a){
	ofstream outfile;
	outfile.open("output3.txt", ios::out | ios::trunc);
	outfile << "Danh sach nhan vien:\n";
	for (int i=0; i<a.size(); i++)
	{
		outfile << a[i].holot + " " + a[i].ten << endl;
	}
	outfile<<"\n";
	outfile.close();
}

void xoaDSNV(){
	ofstream outfile;
	outfile.open("output3.txt", ios::trunc);
	outfile.close();
	cout<<"Da xoa danh sach nhan vien";
	getch();
}

void veBang(vector< nv > a){
		cout<<"STT\tMa nhan vien\tHo ten\t\t\tLuong";
	for (int i=0; i<a.size(); i++)
	{
		cout<<"\n";
		cout<<" "<<i+1<<" \t"<<setw(-12)<<a[i].maNV<<"\t\t"<<setw(-30)<<a[i].holot + " " + a[i].ten<<"\t\t"<<setw(-8)<<a[i].luong;
	}
}

main(){
	vector< nv > NhanVien;
	while (true)
	{
		int control;
		docFile(NhanVien);
		system("cls");
		cout<<"0. Ket thuc chuong trinh.\n";
		cout<<"1. Nhap them nhan vien vao danh sach nhan vien. (luu vao file input3.txt)\n";
		cout<<"2. Tim nhan vien theo ma nhan vien.\n";
		cout<<"3. Tim nhan vien co luong cao nhat va nhan vien co luong thap nhat.\n";
		cout<<"4. Xuat danh sach nhan vien ra file output3.txt.\n";
		cout<<"5. Xoa thong tin nhan vien. (xoa du lieu cua file input3.txt)\n";
		cout<<"6. Xoa danh sach nhan vien. (xoa du lieu cua file output3.txt)\n";
		cout<<"Hay chon dieu can lam tu menu ung voi so thu tu cua no: "; cin>>control;
		while (control>6 or control<0)
		{
			cout<<"\nChi duoc nhap gia tri tu 0 den 6.";
			cout<<"\nHay nhap lai: "; cin>>control;
		}
		system("cls");
		if (control==0) break;
		else if (control==1) nhapVaoFile();
		else if (control==2) truyXuatTheoMaNhanVien(NhanVien);
		else if (control==3) TenNVLuongCaoNhatVaThapNhat(NhanVien);
		else if (control==4)
		{
			SXepTen(NhanVien);
			xuatRaFileDanhSachTenNhanVienSauSapXep(NhanVien);
			cout<<"Da xuat danh sach nhan vien ra file outpu3.txt\n";
			cout<<"Danh sach nhan vien sap xep theo ten:\n\n";
			veBang(NhanVien);
			getch();
		}	
		else if (control==5) xoaTTNV();
		else if (control==6) xoaDSNV();
	}
}
