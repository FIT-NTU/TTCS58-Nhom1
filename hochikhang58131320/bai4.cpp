#include<iostream>
#include<fstream>
#include<windows.h>
#include<MMsystem.h>
using namespace std;

int a[20], b[20];
int n,P;
int dem=0; //so cach chon
int S=0; //tong gia tri phan thuong

ifstream f;
ofstream s("output4.txt");

void doc()
{
	f.open("input4.txt");
	f>>n;
	f>>P;
	cout<<n<<"\t"<<P<<endl;
	for(int i=0;i<n;i++)
	{
		f>>a[i];
		cout<<a[i]<<"\t";
	}
	f.close();
	cout<<endl<<endl;
}
void inKQ() 
{
	int S=0;
	for(int i=0;i<n;i++) //i: lan thu i
	if(b[i]==1) 
		S=S+a[i]; //cong gia tri cac phan thuong
	if(S==P) //tong sau bang tong truoc
	{
		dem=dem+1; 
		for(int j=0;j<n;j++)
		{
			if(b[j]==1) //xet cac truong hop chon duoc
			{
				cout<<"\t"<<b[j]; //chon duoc in ra 1
				s<<"\t"<<b[j];
			}
			else
			{
				cout<<"\t"<<b[j]; //khong chon duoc in ra 0
				s<<"\t"<<b[j];	 
			}
		}
		cout<<endl;
		s<<endl;
	}
}
void kiemtra(int i) //da du so phan tu cua n chua 
{
	for(int j=0;j<=1;j++)
	{
		b[i]=j; 
		if(i<n-1)
			kiemtra(i+1);
		else
			inKQ();
	}
}
void ghi()
{
	ofstream s;	
	s.open("output4.txt");
	if(dem>0)
	{
		s<<dem<<endl;
		cout<<"So cach chon la:"<<dem<<endl;
		kiemtra(0);
	}
	else if(dem==0)
	{
		s<<"Khong chon duoc";
		cout<<"Khong chon duoc"<<endl;
	}
}
int main()
{
	doc();
	//tuong tac cua so console
	int k; //doi mau chu
	HANDLE Color;
	Color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Color, k=4);
	cout<<k;
	kiemtra(0);
	ghi();
	system("pause");
	return 0;
}




