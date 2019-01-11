#include <iostream>
#include <fstream>
using namespace std;

int a[20];
int n, x;

void docfile(istream &f, int a[],int &n);
void nhap(int a[20], int &n);
void xuat(int a[20], int n);
void sap_xep(int a[20], int n);
void tim_tong_max(int a[20], int n);
int tim_x(int a[20], int n);

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

void xuat (int a[], int n)
{
	cout <<"Danh sach cac phan tu co trong mang la: "<< endl;
	for (int i=0; i<n; i++)
	{
		cout << a[i] << "\t";
	}
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
	cout<<"Mang sau khi sap xep: "<<endl;
	xuat(a, n);
}

void tim_tong_max(int a[], int n)
{
	int max_tam = 0;
	int max_tong = 0;
	for (int i=0; i<n; i++)
	{
		max_tam = max_tam + a[i];
		if (max_tam<=0)
		{
			max_tam = 0;
		}
		else 
		{
			if (max_tong<max_tam)
			{
				max_tong=max_tam;
			}
		}
	}
	cout <<"Tong: "<<max_tong<<endl;
}

int tim_x(int a[], int n, int x)
{
	int r = n - 1;
	int l = 0;
	while (r >= l)
	{
    	int mid = (l + r )/ 2;
    	if (a[mid] == x)
    	{
    		return mid;
		}
		if (a[mid] > x)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;	
		}
	}
	return -1;
} 

int main ()
{
	ifstream f("mang2.txt");
	docfile(f, a, n);
//	nhap(a, n);
	xuat(a, n);
	tim_tong_max(a, n);
	sap_xep(a, n);
	cout <<endl<< "Nhap vao phan tu can tim: ";
	cin >> x;
	int kq=tim_x(a, n, x);
	if (kq==-1)
	{
		cout <<"Gia tri "<<x<<" ko co trong mang."<<endl;
	}
	else
	{
		cout <<x<<" Xuat hien tai vi tri "<< kq<<endl;
	}
}
