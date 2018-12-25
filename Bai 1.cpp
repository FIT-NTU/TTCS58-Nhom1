#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>

using namespace std; 
ofstream f("input.txt");
ofstream s("output.txt");
string ten;
string ten1;
int a;
void nhapchuoi()
{
	do{
	fflush(stdin);
	cout<<"nhap ten :"; getline(cin,ten);
	a=ten.length();
	}while(a>255);
	ten1=ten;
	f<<ten<<endl;
}
void xoa()
{
	int i=0;
    int n=ten.length();
	for(int i=0;i<n;i++)
	{
		if(ten[i]==' '&&ten[i+1]==' ')
		{
			for(int j=i;j<n;j++)
			{
			ten[j]=ten[j+1];
			}
			n--;
			i--;
		}
	}
// xoa ki tu dau tien neu la khoang trang
i = 0;
if(ten[i]==' ') ten.erase(ten.begin()+i);
//xoa ki tu cuoi cung neu la khoang trang
i=n;
if(ten[i]==' ') ten.erase(ten.begin()+i);
}
void viethoa()
{	
	 int n=ten.length();
	 for (int i=0;i<=n;i++) 
         {
		   if (ten[i]== ' ' && ten[i+1]!=' ') 
        	{
			if(int(char(ten[i+1]))>97 && int(char(ten[i+1]))<=122)
				{
                           ten[i+1]=char(int(ten[i+1]-32));                
				}
			}
	 	}
	//viet hoa ky tu dau tien cua chu dau tien
	int i = 0;
	if (ten[i]!= ' ' && ten[i+1]!=' ') 
        	{
			if(int(char(ten[i]))>97 && int(char(ten[i]))<=122)
				{
                           ten[i]=char(int(ten[i]-32));                 
				}
			}
	//truong hop chu dau tien chi co 1 ky tu
	i = 0;
	if (ten[i]!= ' ' && ten[i+1]==' ') 
        	{
			if(int(char(ten[i]))>97 && int(char(ten[i]))<=122)
				{
                           ten[i]=char(int(ten[i]-32));                 
				}
			}
}
void thongke()
{
	int dem=0;
	for(int i=0;i<a;i++)
	{
		if(ten1[i]!=' ') dem++;
	}
	s<<dem<<endl;
}
int main()
{	
	int k;
	cout<<"Vui long chon so de chon cong viec thuc hien "<<endl;
	cout<<"Chon 1. De nhap chuoi"<<endl;
	cout<<"Chon 2. De xoa khoang trang"<<endl;
	cout<<"Chon 3. De viet hoa chu cai dau tien"<<endl;
	cout<<"Chon 4. De thong ke ky tu trong chuoi"<<endl;
	cout<<"Nhap so : ";cin>>k;
	while(k==1||k==2||k==3||k==4)
	{
		if(k==1)
		{
			nhapchuoi();
			s<<ten<<endl;
		}else
		if(k==2)
		{
			xoa();
			s<<ten<<endl;
		}else
		if(k==3)
		{
			viethoa();
			s<<ten<<endl;
		}else
		if(k==4)
		{
			thongke();
		}
		cout<<"Ban con muon lam cong viec gi khac hay nhap so neu khong thi hay nhap so 0 de hoan thanh cong viec\nNhap so : ";cin>>k;
	}

	
}
