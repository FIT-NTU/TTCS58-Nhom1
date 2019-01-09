#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;

ifstream f;
ofstream b("output.txt");
struct NhanVien //khai bao cau truc nhan vien
{
	int maNV;
	char hoTen[20];
	int songaycong;
	int luong;	
};

class DSNV //lop danh sach nhan vien
{
	public:
		int n;
		vector<NhanVien> dsNV;
		void doc();
		void ghi();
		void nhapDSNVTuBanPhim();
		void inDSNV_ManHinh();
		void themNV();
		void timMSNV();
		void sapxep();
		void xoaMSNV();
		void suaMSNV();
		void luongmoi();
		void menu();
};

void DSNV::doc()
{
	f.open("input.txt", ios::in);
	f>>n;
	for(int i=0; i<n; i++)
	{
		f>>dsNV[i].maNV;
		f>>dsNV[i].hoTen;
		f>>dsNV[i].songaycong;
	}
	f.close();
}

void DSNV::ghi()
{
	b<<"Ma nhan vien"<<"\t"<<"Ho ten"<<"\t\t\t"<<"So ngay cong"<<"\t"<<"Luong nhan vien"<<endl;
	for(int i=0;i<n;i++)
	b<<dsNV[i].maNV<<"\t\t"<<dsNV[i].hoTen<<"\t\t"<<dsNV[i].songaycong<<"\t\t"<<dsNV[i].songaycong*300000<<endl;
}
void DSNV::nhapDSNVTuBanPhim() //dau vao
{
	dsNV.resize(n); //dat lai kich thuoc vector
	n=dsNV.size(); //lay kich thuoc vector
	for(int i=0;i<n;i++)
	{
		cout<<"Nhan vien thu "<<i+1<<":"<<endl;
		fflush(stdin);
		cout<<"Nhap ma so nhan vien:"<<endl;
		cin>>dsNV[i].maNV;
		fflush(stdin);
		cout<<"Nhap ho va ten nhan vien:"<<endl; 
		cin.getline(dsNV[i].hoTen, 20);
		cout<<"Nhap so ngay cong cua nhan vien:"<<endl;
		cin>>dsNV[i].songaycong;
	}
}

void DSNV::inDSNV_ManHinh() //dau ra
{
	for(int i=0;i<n;i++)
	{
		cout<<"Ma so nhan vien:"<<dsNV[i].maNV<<endl;
		cout<<"Ho va ten:"<<dsNV[i].hoTen<<endl;
		cout<<"So ngay cong cua nhan vien:"<<dsNV[i].songaycong<<endl;
		cout<<"Luong nhan vien:"<<dsNV[i].songaycong*300000<<endl;
		cout<<"*********************************************"<<endl;
	}
	ghi();
}

void DSNV::timMSNV() //tim thong tin nhan vien theo ma nhan vien
{
	int x;
	cout<<"Nhap ma nhan vien can tim:"<<endl;
	cin>>x;
	for(int i=0;i<n;i++)
	{
		if(dsNV[i].maNV==x)
		{
			cout<<"================Thong tin nhan vien================"<<endl;
			cout<<"Ma so nhan vien:"<<dsNV[i].maNV<<endl;
			cout<<"Ho va ten:"<<dsNV[i].hoTen<<endl;
			cout<<"So ngay cong cua nhan vien:"<<dsNV[i].songaycong<<endl;
			cout<<"Luong nhan vien:"<<dsNV[i].songaycong*300000<<endl;
			cout<<"*********************************************"<<endl;
			b<<"-----------Thong tin nhan vien------------"<<endl;
			b<<"STT"<<"\t"<<"Ma nhan vien"<<"\t"<<"Ho ten"<<"\t\t\t\t"<<"So ngay cong"<<"\t"<<"Luong nhan vien"<<endl;
			b<<i+1<<"\t"<<dsNV[i].maNV<<"\t\t"<<dsNV[i].hoTen<<"\t\t\t"<<dsNV[i].songaycong<<"\t\t\t"<<dsNV[i].songaycong*300000<<endl;
			b<<endl;
		}	
		else if(dsNV[i].maNV!=x)
			cout<<"Khong tim thay nhan vien co ma tren!"<<endl;
	}

}	
void DSNV::themNV() //them 1 nhan vien moi
{
	int z,a,g=0;
	do
	{
		cout<<"Nhap so luong nhan vien can them:";
		cin>>z;
	}while(n>10);
	n=dsNV.size();
	a=n;
	dsNV.resize(n+z); //dat lai kich thuoc vector
	n=dsNV.size(); //lay kich thuoc moi
	for(int i=n-1;i>=a;i--)
	{
		cout<<"Nhap ma so nhan Vien:"; 
		cin>>dsNV[i].maNV;
		if(dsNV[i].maNV==dsNV[g].maNV) //neu ma nhan vien da ton tai
		{
			cout<<"Nhap lai : ";
			cin>>dsNV[i].maNV;
		}
		fflush(stdin);
		cout<<"Nhap ho va ten nhan vien : "; 
		cin.getline(dsNV[i].hoTen, 20);
		cout<<"Nhap so ngay cong cua nhan vien : ";
		cin>>dsNV[i].songaycong;
	}	
}

void DSNV::sapxep()
{
	cout<<"Ma nhan vien"<<"\t"<<"Ho va ten"<<"\t\t\t\t"<<"So ngay cong"<<"\t"<<"Luong nhan vien"<<endl;
	for(int i=0;i<n;i++)
	{  	for(int j=i+1;j<n;j++)
			if( dsNV[i].songaycong > dsNV[j].songaycong) 
			{
				swap(dsNV[i], dsNV[j]);
			}	
		cout<<dsNV[i].maNV<<"\t\t"<<dsNV[i].hoTen<<"\t\t\t\t"<<dsNV[i].songaycong<<"\t\t"<<dsNV[i].songaycong*300000<<endl;
	}  
 	ghi(); 
}
void DSNV::suaMSNV() //sua thong tin nhan vien theo ma nhan vien
{
	int y;
	cout<<"Nhap ma cua nhan vien can sua doi:"<<endl;
	cin>>y;
	n = dsNV.size(); 
	for(int i=0;i<n;i++)
	{
		if(dsNV[i].maNV==y) 
				{
					int h;
					cout<<"1.Thay doi ho va ten nhan vien"<<endl;
					cout<<"2.Thay doi so ngay cong cua nhan vien"<<endl;
					cout<<"Ban muon sua gi?"<<endl;
					cin>>h ;
					if(h==1 || h==2 )
					{
						if(h==1)
						{
							fflush(stdin);
							cout<<"Nhap lai ten nhan vien : "<<endl;
							cin.getline(dsNV[i].hoTen, 20);
						}
						else if(h==2)
						{
							cout<<"Nhap lai so ngay cong nhan vien : "<<endl;
							cin>>dsNV[i].songaycong;
						}
					}
				}		
	}
}

void DSNV::xoaMSNV()
{
	n = dsNV.size();
	int l,t;
	cout<<"Nhap ma nhan vien can xoa : ";
	cin>>l;
	for(int i=0;i<n;i++)
	if(dsNV[i].maNV==l)
		t=i;
	if(dsNV[t].maNV==l)
	{
		if(t<n)
		{
			dsNV[t]=dsNV[t+1];
			t++;
		}
		n--;
		cout<<"Xoa thanh cong!"<<endl;
		b<<"Xoa thanh cong!"<<endl;
	}
	else
		cout<<"Xoa that bai!"<<endl;
		b<<"Xoa that bai!"<<endl;
}

void DSNV::menu() //danh sach chuc nang
{
	int k; //bien lua chon
	do
	{
		cout<<"\n**********Coder by Ho Chi Khang - 58131320**********";
		cout<<"\n______________PHAN MEM QUAN LY NHAN VIEN______________"<<endl;
		cout<<"1.Doc thong tin nhan vien tu file "<<endl;
		cout<<"2.Nhap thong tin nhan vien"<<endl;
		cout<<"3.Sap xep nhan vien tang dan theo so ngay cong"<<endl;
		cout<<"4.Them nhan vien moi"<<endl;
		cout<<"5.Nhap ma nhan vien va cho biet thong tin nhan vien do"<<endl;
		cout<<"6.Sua doi nhan vien theo ma nhan vien"<<endl;
		cout<<"7.Xoa nhan vien theo ma nhan vien"<<endl;
		cout<<"8.In ra man hinh danh sach nhan vien"<<endl;
		cout<<"9.Thoat!"<<endl;
		cout<<"Ban chon chuc nang so:"<<endl;
		cin>> k;
		system("cls"); //xoa man hinh
		switch( k )
		{
			case 1:
				doc();
				break;
			case 2:
				do
				{
					cout<<"Nhap so luong nhan vien : "<<endl;
					cin>>n;
				}while(n>10);
				nhapDSNVTuBanPhim();
				break;
			case 3:
				sapxep();
				break;
				
			case 4:
				themNV();
				ghi();
				break;
			
			case 5:
				timMSNV();
				break;
			
			case 6:
				suaMSNV();
				break;		
				
			case 7:
				xoaMSNV();

				break;
			case 8:
				inDSNV_ManHinh();	
				break;
			case 9: 
				exit(0);
				break;	
			default:
				cout<< "\nNhap lai!";
				break;
		}
	}while(k!=0); //neu =0 se ket thuc
}

int main() //ham chinh
{
	int n;
	DSNV a;
	a.menu();
	system("pause");
}

 



