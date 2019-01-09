#include<iostream>
using namespace std;

int a[20]={15,52,4,5,5,6,8,2,4,5,2,1,5,2,5,0,0,0,0,0};
int n=15;
//void nhap()
// {
// 	do
// 	{
// 		cout<<"nhap n , 10<= n <=20: ";
// 		cin>>n;
//	 }while(n<10||n>20);
//	for(int i=0;i<n;i++)
//	{
//		cout<<" a["<<i<<"]:";
//		cin>>a[i];
//	}
// }
void xuatmang()
{
	int i=0;
	while(a[i]!=0&&i<n)
	{
		cout<<a[i]<<"  ";
		i++;
	}
	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<"  ";
//	}
//	cout<<endl;
}

void sapxep()
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				int tam;
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
	
}
bool kiemtra(int x)
{
	int i=0;
	while((a[i]!=x)&&(i<n))
	{
		i++;
	}
	if(i<n) return true;
	else return false;
}
void chen(int x)
{
	int i=0;
	int m=0;
	int vt;
	while(a[i]!=0)
	{
	if(a[i]<x)vt=i+1;
	m=m+1;
	i++;
	}
//	cout<<m<<" "<<vt;
	for(i=m;i>vt;i--)
		{
			a[i]=a[i-1];	
		}
	a[vt]=x;
}

void xoa(int x)
{
	int i=0;
	int m=0;
 	while(a[i]!=0)
	{
		m=m+1;
		i++;
	}
	i=0;
	while(i<m)
	{
		if(a[i]==x)
		{
			for(int j=i;j<m-1;j++)
			{
				a[j]=a[j+1];
			}
		a[m-1]=0;
		m=m-1;
		
		}
		else i++;				
	}
}

void xoalap()
{
	int i=0;
	int m=0;
 	while(a[i]!=0)
	{
		m=m+1;
		i++;
	}
	i=0;
	while(i<m)
	{
		if(a[i]==a[i+1])
		{
			for(int j=i+1;j<m-1;j++)
				a[j]=a[j+1];
			a[m-1]=0;
			m=m-1;
		}
		else i++;
			
	}
	
}
int main()
{
//	nhap();
	xuatmang();
	int x;
	sapxep();
	xuatmang();
	cout<<"nhap gia tri x:";
	cin>>x;
	
	if(kiemtra(x))
		{
			cout<<"mang co phan tu mang gia tri "<<x<<endl;
			cout<<"mang sau khi xoa:"<<endl;
			xoa(x);
			xuatmang();
		}
		else
		{
			cout<<"mang k co phan tu mang gia tri "<<x<<endl;
			chen(x);
			cout<<"mang sau khi chen: "<<endl;
			xuatmang();
		}
	cout<<"xoa trung lap:"<<endl;
	xoalap();
	xuatmang();
	cout<<endl;
	system("pause");
}
