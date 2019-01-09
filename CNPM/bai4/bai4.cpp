#include <iomanip>
#include <fstream>
#include<iostream>
#include "console1.h"
using namespace std;
int n,P;
int a[20];
int b[20];
int tong=0;//cân.
int count=0;
//doc file
void doc()
{
	ifstream file;
	file.open("input.txt", ios::in);
	file>>n;
	file>>P;
	for(int i=0;i<n;i++)
	{
	file>>a[i];
	}
	for(int i=0;i<n;i++)
	{
	cout<<setw(4)<<a[i];
	}
	cout<<endl;
	cout<<"tong gia tri phan thuong: "<<P<<endl;
	
}


//thu sai quay lui muc1
void inkqtong(int k)
{	int S=0;int j;
	for(j=0;j<n;j++) if (b[j]==1) S=S+a[j];
	
	if(k==0)//k= 0 dung de xuat cac truong hop va tinh count so truong hop duoc chon
	{
	if (S==P)
		{
		count=count+1;
		for (j=0;j<n;j++)
			if(b[j]==1) cout<<setw(4)<<1;
			else cout<<setw(4)<<0;
		cout<<endl;
		}
	}
	if(k==1) //k=1 dugn de ghi vao file output.txt
	{
		ofstream file;
		file.open("output.txt", ios::app);	
		if (S==P)
		{
		for (j=0;j<n;j++)
			if(b[j]==1) file<<setw(4)<<1;
			else file<<setw(4)<<0;
		file<<endl;
		}
	}
}
void thutong(int i,int k)
{
	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(b[i]==1) tong=tong+a[i];//can
		if((i<n-1)&&( tong < P)) thutong(i+1,k); //can
		else  inkqtong(k);
		if (b[i]==1) tong=tong-a[i];//can
		b[i]=0;
		
	}
}


int main()
{
	doc();
	thutong(0,0);
	
	ofstream file;
	file.open("output.txt", ios::out);	
	if(count>0)
	{

	file<<count<<endl;
	thutong(0,1);
	}
	if(count==0)
	{
	file<<"khong chon duoc"<<endl;
	}
	cout<<"\nso cach chon qua:"<<count<<endl;
	system("pause")	;
}
