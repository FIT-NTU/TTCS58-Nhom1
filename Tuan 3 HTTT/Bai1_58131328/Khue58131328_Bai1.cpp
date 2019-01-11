#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
void nhap(int a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d] : ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}
int kiemtra(int a[],int n,int x)
{
	int i=0;
	while(a[i]!=x&&i<n)
		i++;
	if(i>=n)
		return -1;
	return i;
}
void sapxep(int a[],int n)
{
	int tam;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
	}
	xuat(a,n);
}
void chen(int a[],int &n,int x)
{
	int index;
	int i=0;
	while(a[i]<x)
	{
		i++;
		index=i;
	}
	for(int j=n;j>index;j--)
		a[j]=a[j-1];
	a[index]=x;
	n++;
	xuat(a,n);
}
void xoax(int a[],int &n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			for(int k=i;k<n;k++)
				a[k]=a[k+1];
			n--;
			i--;
		}
	}
	xuat(a,n);
}
void xoacacphantutrunglap(int a[],int &n)
{
	int i,j;
	i=0;
	while(i<n)
	{
		j=i+1;
		while(j<n)
		{
			if(a[i]==a[j])
			{
				for (int k=j;k<n;k++)
					a[k]=a[k+1];
				n--;
			}
			else
				j=j+1;
		}
		i=i+1;
	}
	xuat(a,n);
}
void ghifile(char *file,int a[],int n)
{
	ofstream f;
	f.open(file);
	f<<n<<endl;
	for(int i=0;i<n;i++)
		f<<a[i]<<" ";
	f.close();
}
void docfile(char *file,int a[],int n)
{
	int x;
	ifstream f;
	f.open(file);
	if(f!=NULL)
	{
		f>>n;
		cout<<"So luong phan tu cua mang : "<<n<<endl;
		for(int i=0;i<n;i++)
		{
			f>>a[i];
			cout<<" "<<a[i];
		}
		cout<<endl<<"\nMang sau khi duoc sap xep"<<endl;
		sapxep(a,n);
		cout<<endl<<"Nhap X : ";	cin>>x;
		if(kiemtra(a,n,x)!=-1)
		{
			cout<<endl<<x<<" da ton tai tai vi tri : "<<kiemtra(a,n,x)<<endl;
			cout<<endl<<"Cac phan tu co gia tri la "<<x<<" se bi xoa\n";
			xoax(a,n,x);
		}
		else
		{
			cout<<endl<<x<<" Khong ton tai trong mang, "<<x<<" se duoc chen vao mang"<<endl;
			chen(a,n,x);
		}
		cout<<endl<<"Mang sau khi da duoc bo di cac phan tu trung lap"<<endl;
		xoacacphantutrunglap(a,n);
	}
	else
	{
		do
		{
			printf("So phan tu cua mang : ",n);
			scanf("%d",&n);
		}while(n<10||n>20);
		nhap(a,n);
		ghifile("input1.txt",a,n);
		cout<<endl<<"\nMang sau khi duoc sap xep"<<endl;
		sapxep(a,n);
		cout<<endl<<"Nhap X : ";	cin>>x;
		if(kiemtra(a,n,x)!=-1)
		{
			cout<<endl<<x<<" da ton tai tai vi tri : "<<kiemtra(a,n,x)<<endl;
			cout<<endl<<"Cac phan tu co gia tri la "<<x<<" se bi xoa\n";
			xoax(a,n,x);
		}
		else
		{
			cout<<endl<<x<<" Khong ton tai trong mang, "<<x<<" se duoc chen vao mang"<<endl;
			chen(a,n,x);
		}
		cout<<endl<<"Mang sau khi da duoc bo di cac phan tu trung lap"<<endl;
		xoacacphantutrunglap(a,n);
	}
}
int main()
{
	int a[50],n;
	docfile("input1.txt",a,n);
	return 0;
}
