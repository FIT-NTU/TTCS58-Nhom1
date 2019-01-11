#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#define cachso 5
#define cachten 10
#define cach ' '
using namespace std;

int n;

struct nhanVien
{
	int msnv;
	string ho;
	string ten;
	int luong;
}; 

nhanVien nv[50];

void menu();
void chon();
void nhap(nhanVien nv[], int &n);
void timKiem();
void ghiFile();
void timLuong();
void xuat();
void sapXep();
void ghiFile();
void output ();
//void docFiel(nhanVien nv[], int n);
//void doc(nhanVien nv[], int n);

void menu()
{
	cout << "-----------------Menu-------------------"<<endl;
	cout << "1.Nhap thong tin nhan vien." << endl;
	cout << "2.Nhap ma va cho biet thong tin nhan vien."<<endl;
	cout << "3.In ra nhan vien co luong cao nhat."<<endl;
	cout << "4.Sap xep nhan vien tang dan." << endl;
	cout << "5.Ghi vao File." << endl;
	cout << "6.Thoat."<<endl;
	cout << "----------------------------------------"<<endl;
}

void chon()
{
	int select;
	cout << "Nhap vao lua chon cua ban:";
	cin >> select;
	if (select != 1 && n==0)
	{
		system("cls");
		cout << "Chua co thong tin nhan vien, moi ban nhap thong tin nhan vien."<<endl;
		menu();
		chon();
	}
	else
	{
		switch (select)
		{
			case 1:
				nhap(nv, n);
				chon();
				break;
			case 2:
				timKiem();
				chon();
				break;
			case 3:
				timLuong();
				chon();
				break;
			case 4:
				sapXep();
				chon ();
				break;
			case 5:
				break;
		}
	}
}

void nhap(nhanVien nv[], int &n)
{
	cout << "Nhap vao so luong nhan vien: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ma: ";
		cin >> nv[i].msnv;
		cout << "Nhap ho: ";
		cin >> nv[i].ho;
		cout << "Nhap ten: ";
		cin >> nv[i].ten;
		cout << "Tien luong: ";
		cin >> nv[i].luong;
	}
	ghiFile();
}

void ghiFile()
{
	fstream ghi;
	ghi.open("Input3.txt");//, ios::app);
	for (int i = 0; i < n; i++)
	{
		ghi << nv[i].msnv << endl;
		ghi << nv[i].ho << endl;
		ghi << nv[i].ten << endl;
		ghi << nv[i].luong << endl;
	}
	ghi.close();
	cout << "Da ghi file!" << endl;
}

void output()
{
	fstream ghi;
	ghi.open("output3.txt", ios::app);
	for (int i = 0; i < n; i++)
	{
		ghi << nv[i].msnv <<endl;
		ghi << nv[i].ho <<endl;
		ghi << nv[i].ten <<endl;
		ghi << nv[i].luong <<endl;
	}
	ghi.close();
	cout << "Da tao file output!" << endl;
}

void xuat()
{
	cout << left << setw(cachso) << setfill(cach) << "Ma";
	cout << left << setw(cachten) << setfill(cach) << "Ho";
	cout << left << setw(cachten) << setfill(cach) << "Ten";
	cout << left << setw(cachso) << setfill(cach) << "Luong";
	cout << endl;
	for (int i=0; i<n; i++)
	{
		cout << left << setw(cachso) << setfill(cach) << nv[i].msnv;
		cout << left << setw(cachten) << setfill(cach) << nv[i].ten;
		cout << left << setw(cachten) << setfill(cach) << nv[i].ho;
		cout << left << setw(cachso) << setfill(cach) << nv[i].luong;
		cout << endl;
	}
}

void timKiem()
{
	int ma;
	int dem = 0;
	cout << "Nhap ma nhan vien: ";
	cin >> ma;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].msnv==ma)
		{
			cout <<"Ma: "<< nv[i].msnv << endl;
			cout <<"Ten: "<< nv[i].ten << endl;
			cout <<"Ho: "<< nv[i].ho << endl;
			cout <<"Luong: "<< nv[i].luong << endl;
			dem ++;
		}
	}
	if (dem == 0)
	{
		cout << "Khong co ket qua"<<endl;
	}
}

void timLuong()
{
	cout << "Nhan vien co luong cao nhat."<<endl;
	int max=nv[0].luong;
	int tam = 0;
	for (int i=1; i<n; i++)
	{
		if (nv[i].luong > max)
		{
			max=nv[i].luong;
			tam = i;
		}
	}
	cout <<nv[tam].msnv<<" "<< nv[tam].ho << " "<< nv[tam].ten<<" "<<nv[tam].luong<<endl;
	output ();
	cout << "Nhan vien co luong thap nhat."<<endl;
	int min=nv[0].luong;
	int tam1 = 0;
	for (int i=1; i<n; i++)
	{
		if (nv[i].luong < min)
		{
			min=nv[i].luong;
			tam1 = i;
		}
	}
	cout <<nv[tam1].msnv<<" "<< nv[tam1].ho << " "<< nv[tam1].ten<<nv[tam1].luong<<endl;
	output ();
}

void sapXep ()
{
	for(int i =0 ; i<n-1; i++)
	{
		for(int j = i+1; j<n;j++)
		{
			if(nv[i].ten.compare(nv[j].ten) > 0 )
			{
				swap(nv[i],nv[j]);
			}
			else if(nv[i].ten.compare(nv[j].ten) == 0)
			{
				if(nv[i].ho.compare(nv[j].ho)>0)
				{
					swap(nv[i],nv[j]);
				}
			}
		}
	}
	cout << "Thu tu sau khi sap xep: "<<endl;
	xuat();
}

int main ()
{
	menu();
	chon();
	system ("pause");
}

