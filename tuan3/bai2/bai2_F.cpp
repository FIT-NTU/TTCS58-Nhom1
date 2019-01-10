#include<iostream>
#include<fstream>
using namespace std;
int n,a[50];
void doc()
{
	fstream f;
	f.open("dulieu.txt",ios::in);
	f>>n;
	for(int i=0;i<n;i++)
	{
		f>>a[i];
	}
}
void xuat()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
}
void sapxep()
{
	int tam;
     for (int i=0;i<n-1;i++)
     {
         for (int j=i+1;j<n;j++)
         {
             if (a[i] > a[j])
             {
                 tam=a[i];
                 a[i]=a[j];
                 a[j]=tam;
             }
         }
     }
	xuat(); 
}
//tim kiem nhi phan
int tim( int a[],int left, int right,int x)
{ 
	if (left > right) return -1;

	int mid = (left + right) / 2;

	if (x == a[mid]) 
		return mid;

	if (x < a[mid]) 
		return tim(a,left,mid-1,x);

	if (x > a[mid]) 
		return tim(a,mid+1,right,x);
}
//---
void tim_tong()
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
int main()
{
	int x;
	doc();
	xuat();
	cout<<endl;
	cout<<"ket qua";
	tim_tong();
	//------
	cout<<"sau khi sap xep";
	sapxep();
	cout<<endl;
	//----
	cout<<"nhap x:";
	cin>>x;
	cout<<"vi tri can tim: "<<tim(a,0,n-1,x)<<endl;
}
