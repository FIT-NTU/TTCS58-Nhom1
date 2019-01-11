#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
using namespace std;
void ghifile(char a[])
{
	ofstream f;
	f.open("input1.txt");
	cin.ignore();
	cout<<"Nhap chuoi : ";
	cin.getline(a,255);
	f<<a;
	f.close();
}
void xoakhoangtrang(char a[])
{
	int i;
	int n=strlen(a);
	//xoa khoang trang dau chuoi
	while(a[0]==' ')
	{
		for(int j=0;j<n;++j)
			a[j]=a[j+1];
		i++;
	}
	//xoa khoang trang xuat hien nhieu hon 2 lan giua cac ki tu trong chuoi
	i=0;
	while(i<n)
	{
		if(a[i]==' '&&a[i+1]==' ')
		{
			for(int j=i;j<n;++j)
				a[j]=a[j+1];	
			i--;
		}
		i++;
	}
	//xoa khoang trang cuoi chuoi
	while(a[n-2]==' ')
	{
		a[n-2]='\0';
	}
}
void Proper(char a[])
{
	int i;
	int n=strlen(a);
	if(a[0]>=97&&a[0]<=122)
		a[0]-=32;
	for(i=1;i<n;i++)
		if(a[i]>=65&&a[i]<=90)
			a[i]+=32;
	i=0;
	while(i<n)
	{
		if(a[i]==' '&&a[i+1]>=97&&a[i+1]<=122)
			a[i+1]-=32;
		i++;
	}
}
int dem(char a[])
{
	int dem=0;
	for(int i=0;i<strlen(a);i++)
		if(a[i]>=65&&a[i]<=122)
			dem++;
	return dem;
}
void menu()
{
	ofstream g;
	g.open("output1.txt");
	ifstream k;
	k.open("input1.txt");
	char a[255];
	int chon;
	if(k!=NULL)
	{
		cout<<"Du lieu ton tai trong file input1.txt : ";
		k.getline(a,255);
		cout<<a<<endl;
		do
		{
			cout<<"1.Nhap lai du lieu"<<endl;
			cout<<"2.Bo cac khoang trang thua"<<endl;
			cout<<"3.Chuan hoa dang Proper"<<endl;
			cout<<"4.Thong ke so luong cac ki tu chu cai trong chuoi"<<endl;
			cout<<"5.Thoat"<<endl;
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Chon muc luc menu(1->5) : ";	cin>>chon;
			switch(chon)
			{
				case 1:
					ghifile(a);
					cout<<a<<" da duoc luu!"<<endl;
					break;
				case 2:
					xoakhoangtrang(a);
					cout<<a<<endl;
					g<<"Sau khi da bo cac khoang trang thua : "<<a<<endl;
					break;
				case 3:
					Proper(a);
					cout<<a<<endl;
					g<<"Sau khi chuan hoa chuoi dang Proper : "<<a<<endl;
					break;
				case 4:
					cout<<"\t"<<dem(a)<<endl;
					g<<"So luong ki tu cac chu cai trong chuoi : "<<dem(a)<<endl;
					break;
				case 5:
					cout<<"Ket thuc!";
					break;
				default:
					cout<<"Muc lua chon khong ton tai! Xin lua chon lai menu : "<<endl;
					break;
			}
		}while(chon!=5);
	}
	else
	{
		do
		{
			cout<<"1.Nhap du lieu"<<endl;
			cout<<"2.Bo cac khoang trang thua"<<endl;
			cout<<"3.Chuan hoa dang Proper"<<endl;
			cout<<"4.Thong ke so luong cac ki tu chu cai trong chuoi"<<endl;
			cout<<"5.Thoat"<<endl;
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Chon muc luc menu(1->5) : ";	cin>>chon;
			switch(chon)
			{
				case 1:
					ghifile(a);
					cout<<a<<" da duoc luu!"<<endl;
					do
					{
						cout<<"1.Nhap lai du lieu"<<endl;
						cout<<"2.Bo cac khoang trang thua"<<endl;
						cout<<"3.Chuan hoa dang Proper"<<endl;
						cout<<"4.Thong ke so luong cac ki tu chu cai trong chuoi"<<endl;
						cout<<"5.Thoat"<<endl;
						cout<<"-------------------------------------------------"<<endl;
						cout<<"Chon muc luc menu(1->5) : ";	cin>>chon;
						switch(chon)
						{
							case 1:
								ghifile(a);
								cout<<a<<" da duoc luu!"<<endl;
								break;
							case 2:
								xoakhoangtrang(a);
								cout<<a<<endl;
								g<<"Sau khi da bo cac khoang trang thua : "<<a<<endl;
								break;
							case 3:
								Proper(a);
								cout<<a<<endl;
								g<<"Sau khi chuan hoa chuoi dang Proper : "<<a<<endl;
								break;
							case 4:
								cout<<"\t"<<dem(a)<<endl;
								g<<"So luong ki tu cac chu cai trong chuoi : "<<dem(a)<<endl;
								break;
							case 5:
								cout<<"Ket thuc!";
								break;
							default:
								cout<<"Muc lua chon khong ton tai! Xin lua chon lai menu : "<<endl;
								break;
						}
					}while(chon!=5);
					break;
				case 5:
					cout<<"Ket thuc!";
					break;
				default:
					cout<<"Du lieu khong ton tai, xin nhap du lieu vao truoc khi thuc hien cac thao tac sau!"<<endl;
					break;
			}
		}while(chon!=5);
	}
	k.close();
	g.close();
}
int main()
{
	menu();
	getch();
}
