#include <iostream>
#include <fstream>
using namespace std;
int n,p,so_kq=0,sum=0,x=0; 
int a[50],tam[50],kq[50][50];
void docfile()
{
	fstream f;
	f.open("D:\\input.txt",ios::in);
	f>>n>>p;
	for(int i=0;i<n;i++)
	{
		f>>a[i];
	}
	f.close();
}
void luu() 
{
	for (int i =0;i<n;i++) 
	{
		kq[so_kq][i]=tam[i];
	}
}
void xuat()
{
	for (int i=0;i<so_kq;i++) 
	{
		for (int j=0;j<n;j++) 
		{
			cout<<kq[i][j]<<" ";
		}
			cout<<endl;
	}
}
void quay_lui(int sum,int x) 
{
	for (int i=x;i<n;i++) 
	{
		if ((sum + a[i])<=p) 
		{
			sum =sum+a[i];
			tam[i]=1;
			if (sum==p) 
			{
				luu();
				so_kq =so_kq+1;
			}
			else {
				quay_lui(sum,i+1);
			}
				sum =sum-a[i];
				tam[i] = 0;
		}
	}
}
// ghi ket qua vao file
void ghifile() 
{
	fstream f;
	f.open("D:\\output.txt",ios::out);
	f<<"===============ket qua ==============="<<endl;
	quay_lui(sum,x);
	if (so_kq==0) 
	{
		cout <<"Khong chon duoc"<< endl;
		f<<"khong chon duoc"<<endl;
	}
	else{
			f<<so_kq<<endl;
			cout<<so_kq<<endl;
			xuat();
			for(int i=0;i<so_kq;i++) 
			{
				for(int j=0;j<n;j++) 
				{
					f<<kq[i][j]<<" ";
				}
				f<<endl;
			}
		}
}
int main() 
{	
	docfile();
	ghifile();
}
