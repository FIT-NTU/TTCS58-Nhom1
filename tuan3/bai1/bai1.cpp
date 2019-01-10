#include<iostream>
using namespace std;
void nhap(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cin >> a[i]; 
	}
}
void xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
// sap xep mang tu be den lon
void sapxep(int n,int a[])
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
	xuat(a,n); 
}
//tim phan tu x
int tim(int a[],int n,int x )
{
	
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		return i;
	}
	return -1;
}
// them phan tu
void chen(int a[], int &n, int vt, int c)
{
	for(int i = n - 1; i >= vt; i--)
	{
		a[i + 1] = a[i];
	}
	a[vt] = c; 
	n++; 
	xuat(a,n);
}
//xoa phan tu
void xoa(int a[], int &n,int x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			count++;
		else
			a[i - count] = a[i];
	}
	n -= count;

	xuat(a,n);
}
// xoa cac phan tu trung lap
void xoa_trung(int a[],int n)
{
    for(int i=0;i<n-1;i++) 
    for(int j=i+1;j<n;j++) 
        if(a[i]==a[j]) 
        { 
            for (int k=j;k<n-1;++k ) 
                a[k]=a[k+1]; 
            --n; 
            i--;
        }  
    xuat(a,n);
}
//-----------
int main()
{
	int n,x,a[50],vt,c;
	// nhap so luong phan tu a[10,20]
	do{
		cout<<"nhap so luong phan tu: ";
		cin>>n;
	}while(n<10 || n>20 ); 
	//nhap cac phan tu trong mang
	cout<<"nhap phan tu trong mang:"<<endl;
	nhap(a,n);
	//---
	cout<<"sau khi sap xep";
	sapxep(n,a);
	cout<<endl;
	//----
	cout<<"nhap x:";
	cin>>x;
	if(tim(a,n,x)!=-1)
	{
		cout<<"phan x nam tai vi tri:"<<tim(a,n,x)<<endl;	
	}
	else 
	{
		cout<<"mang sau khi chen: "<<endl;
		for(int i = 0; i < n; i++)
		{
			if(a[i] < x && x<a[i+1])
			chen(a,n,i+1,x);
		}
	}	
	cout<<"mang sau khi xoa"<<endl;
	xoa(a,n,x);
	cout<<endl;
	cout<<"mang sau khi xoa trung:"<<endl;
	xoa_trung(a,n);
	
}
