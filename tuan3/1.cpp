#include <iostream>
#include<fstream>
using namespace std;

	int a[20];
	int n;
	
void docfile(istream &f, int a[],int &n);
void nhap(int a[20], int &n);
void xuat(int a[20], int n);
void sap_xep(int a[20], int n);
void kiem_tra(int a[20], int n);
void xoa_mot(int a[20], int n, int vt_xoa);
void xoa_phan_tu_x(int a[20], int n, int x);
void xoa_trung_lap(int a[20], int n);
	
void docfile(istream &f, int a[],int &n)
{
	f >> n;
	for(int i = 0; i < n; i++)
	{
		f >> a[i];	
	}
}

void nhap(int a[20], int &n)
{
	do
	{
		cout << "Nhap vao so phan tu: ";
		cin >> n;
	}
	while (n<10 || n>20);
	for (int i=0; i<n; i++)
	{
		cout << "a["<<i<<"]: ";
		cin >> a[i];
		if (a[i]==0)
			break;
	}
}

void xuat(int a[20], int n)
{
	cout << "Danh sach co trong mang la: "<<endl;
	for (int i=0; i<n; i++)
	{
		cout <<a[i]<<"   ";
	}
	cout <<endl;
}

void sap_xep(int a[20], int n)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i]>a[j])
			{
				swap (a[i], a[j]);
			}
		}
	}
	cout<<"__________________________"<<endl;
	cout<<"Mang sau khi sap xep: "<<endl;
	xuat(a, n);
}

void kiem_tra(int a[20], int n)
{
	int x, dem=0;
	cout << "Moi ban nhap vao x: ";
	cin >> x;
	for (int i=0; i<n; i++)
	{
		if (x==a[i])
		{
			cout << "Phan tu "<<x<<" co ton tai trong mang."<<endl;
			xoa_phan_tu_x(a, n ,x);
			dem ++;
			
		}
	}
	if (dem==0)
	{
		cout << "Phan tu "<<x<<" Khong ton tai trong mang."<<endl;
		for (int i=0; i<n; i++)
		{
			if (x<a[i])
			{
				for (int j=n; j>i; j--)
				{
					a[j] = a[j-1];
				}
				a[i]=x;
				break;
			}
		}
		n++;
		xuat(a, n);
	}
}

void xoa_mot(int a[20], int n, int vt_xoa)
{
	for (int i=vt_xoa; i<n; i++)
	{
		a[i] = a[i+1];
	}
	n--;
}

void xoa_phan_tu_x(int a[20], int n, int x)
{
	for (int i=0; i<n; i++)
	{
		if (x==a[i])
		{
			xoa_mot(a, n, i);
			i--;
		}
	}
	xuat (a, n);
}

void xoa_trung_lap(int a[20], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] == a[j])
			{
				xoa_mot(a, n, j);
				n--;			
			}
		}
	}
	cout <<"_____________________________________"<<endl;
	cout << "Danh sach sau khi xoa su trung lap."<<endl;
	xuat (a, n);
}

int main ()
{
	ifstream f("mang1.txt");
	docfile(f,a,n);
	xuat(a, n);
	sap_xep(a, n);
	kiem_tra(a, n);
	xoa_trung_lap(a, n);
}
