#include <iostream>
using namespace std;
int a[15]={15,-42,4,7,8,2,9,20,17,2,18,-87,12,6,14};
int n=15;
int b[15];

void xuat()
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
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

int tknp(int left, int right,int x)
{
	if(right>=left)
	{
		int mid=(right+left)/2;
		if(a[mid]==x) return mid;
		if(a[mid]>x) 
		{
			right=mid-1;
			return tknp(left,right,x);
		}
		if(a[mid]<x)
		{
			left=mid+1;
			return tknp(left,right,x);
		}
	}
	return -1;
}

void trave()
{
	for(int i=0;i<n;i++) b[i]=0;
}

void ghigtri(int i,int j)
{
	for(int k=i;k<=j;k++)
		b[k]=a[k];
}

void tonglt()
{
	
	int max=0;
	for(int i=0;i<n-1;i++)
		{
			int tong=a[i];
			for(int j=i+1;j<n;j++)
			{
				tong=tong+a[j];	
				if(tong>max)
				{
					trave();
					ghigtri(i,j);
					max=tong;
				}
			}
				
		}
		
	for(int i=0;i<n;i++)
		if(b[i]!=0)cout<<b[i]<<" ";		
}

int main()
{
	int x;
	sapxep();
	xuat();
	cout<<"\nnhap x:";
	cin>>x;
	cout<<endl;
	if(tknp(0,n-1,x)==-1) cout<<"k tim dc;";
		else cout<<"vi tri: "<<tknp(0,n-1,x)<<" (bat dau la vi tri 0) ";


//de hien thi tong lien tieeps lon nhat tat hamf chuc nang sapxep va timf kiem phia tren;
//	tonglt(); 
	cout<<endl;
	system("pause");
}
