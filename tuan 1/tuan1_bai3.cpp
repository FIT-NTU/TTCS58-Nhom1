#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ofstream ghi;
ofstream h("output3.txt");
int n;

struct nhanvien
{
	int manv, tienluong;
	string holot, ten;
}; 

nhanvien nv[50];

void showmenu();
void chon(nhanvien nv[], int n);
void nhap(nhanvien nv[], int &n);
void ghiFile(nhanvien nv[], int n);
void search_manv(nhanvien nv[], int n);
void timluong(nhanvien nv[], int n);
void sapxep( nhanvien nv[], int n);
void output( nhanvien nv[], int n);

void menu()
{ 
	cout << "1. Nhap thong tin nhan vien." << endl;
	cout << "2. Nhap ma nhan vien va cho biet thong tin nhan vien do."<<endl;
	cout << "3. In ra nhan vien co luong cao nhat va thap nhat."<<endl;
	cout << "4. Sap xep nhan vien tang dan theo ten." << endl << endl;
}

void chon(nhanvien nv[], int n)
{
	int select;
	cout << "\n\t\t\tNhap lua chon cua ban:  ";
	cin >> select;
		switch (select)
		{
			case 1:
				nhap(nv, n);
				chon(nv, n);
				break;
			case 2:
				search_manv(nv, n);
				chon(nv, n);
				break;
			case 3:
				timluong(nv, n);
				chon(nv, n);
				break;
			case 4:
				sapxep(nv, n);
				chon(nv, n);
				break;	
		}
}

void nhap(nhanvien nv[], int &n)
{
	do
	{
		cout << "- Nhap so luong nhan vien: ";
		cin >> n;
		if ( n < 0 || n > 50)
		{
			cout << "yeu cau nhap lai ... !" << endl;
		}
	} while ( n < 0 || n > 50 );
	
	for ( int i = 0; i < n; i++)
	{
		cout << "\t+Nhap thong tin nhan vien thu: " << i+1 << endl;
		cout << "\t\tNhap ma nhan vien: ";
		cin >> nv[i].manv;
		cout << "\t\tNhap ho lot nhan vien: ";
		cin >> nv[i].holot;
		cout << "\t\tNhap ten nhan vien: ";
		cin >> nv[i].ten;
		cout << "\t\tNhap  tien luong: ";
		cin >> nv[i].tienluong;
	}
	ghiFile(nv, n);
}

void ghiFile(nhanvien nv[], int n)
{
	
	ghi.open("Input3.txt");
	ghi << "soluong nhan vien la: " << n << endl<<endl;
	for (int i = 0; i < n; i++)
	{
		ghi << "thong tin nhan vien thu: " << i+1 << endl;
		ghi << "ma nhan vien: " << nv[i].manv << endl;
		ghi << "ho nhan vien: " << nv[i].holot << endl;
		ghi <<  "ten nhan vien: " << nv[i].ten << endl;
		ghi << "tien luong: " << nv[i].tienluong << endl << endl; 
	}
	ghi.close();
	cout << "Da ghi file!" << endl;
}

void search_manv(nhanvien nv[], int n)
{
	int manhanvien, index;
	cout << "Nhap ma nhan vien ban can tim: ";
	cin >> manhanvien;
	for (int i = 0; i < n; i++)
	{
		if (manhanvien == nv[i].manv)
		{
			cout << "Ma nhan vien la: " << nv[i].manv << endl;
			cout << "Ho ten nhan vien la: " << nv[i].holot << " " << nv[i].ten << endl;
			cout << "Tien luong la: " << nv[i].tienluong << endl;
			h << "thong tin nhan vien can tim la: " << endl;
			h << "Ma nhan vien la: " << nv[i].manv << endl;
			h << "Ho ten nhan vien la: " << nv[i].holot << " " << nv[i].ten << endl;
			h << "Tien luong la: " << nv[i].tienluong << endl << endl;
		}
	}
}

void timluong(nhanvien nv[], int n)
{
	int index_max = 0, index_min = 0;
	int max = nv[0].tienluong;
	int min = nv[0].tienluong;
	
	for(int i = 1; i < n; i++ )
	{
		if( max < nv[i].tienluong )  
		{
			index_max = i;
			max = nv[index_max].tienluong;
		}
	}
	cout << "ho ten nhan vien co luong cao nhat la: " << nv[index_max].holot << " " << nv[index_max].ten << endl;
	

	for(int i = 1; i < n; i++)
	{
		if( min > nv[i].tienluong)
		{
			index_min = i;
			min = nv[index_min].tienluong;
		}
	}
	cout << "ho ten nhan vien co luong thap nhat la: " << nv[index_min].holot << " " << nv[index_min].ten << endl;
	
	for( int i = 0; i < n; i++)
	{
		if( nv[i].tienluong == max )
			h << "ho ten nhan vien co luong cao nhat la: " << nv[i].holot << " " << nv[i].ten << endl;
		if( nv[i].tienluong == min )
			h << "ho ten nhan vien co luong thap nhat la: " << nv[i].holot << " " << nv[i].ten << endl;
	}
}

void sapxep (nhanvien nv[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j=i+1; j < n; j++)
		{
			if((nv[i].ten.compare(nv[j].ten))>0)
			{ 
				swap(nv[i],nv[j]);
			} else if( (nv[i].ten.compare(nv[j].ten)) == 0 )
			
			{
				if( (nv[i].holot.compare(nv[j].holot)) > 0 )
				{
					swap(nv[i],nv[j]);
				}
			}
		}
	}
	cout << " ho ten nhan vien sau khi da sap xep: " << endl;
	h << endl << "ho ten nhan vien sau khi da sap xep: " << endl;
	for ( int i = 0; i < n; i++)
	{
		cout << nv[i].holot << " " << nv[i].ten << endl;
		
		h << nv[i].holot << " " << nv[i].ten << endl;
	}
}

void output( nhanvien nv[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		h << nv[i].holot << nv[i].ten << endl;
	}
}

int main ()
{
	menu();
	chon(nv, n);
	system ("pause");
}
