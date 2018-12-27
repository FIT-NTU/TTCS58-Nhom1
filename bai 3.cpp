#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;

ofstream f("input3.txt");
ofstream s("output3.txt");
struct nhanvien{
	int manv;
	string holot;
	string ten;
	int tienluong;
};
void nhap(nhanvien nv[],int n)
{

	for(int i = 0; i<n;i++)
	{
		fflush(stdin);
		cout<<"\nnhap ma nhan vien :";cin>>nv[i].manv;
		fflush(stdin);
		cout<<"\nnhap ho lot : ";getline(cin,nv[i].holot);
		fflush(stdin);
		cout<<"\nnhap ten : ";getline(cin,nv[i].ten);
		cout<<"\nnhap tien luong : ";cin>>nv[i].tienluong;
		cout<<"----------------------------------------------------------"<<endl;
	}
}
void xuatvaofileI(nhanvien nv[], int n)
{
	f<<"ma nhan vien"<<"\t"<<"ho lot"<<"\t\t"<<"ten"<<"\t"<<"tien luong"<<endl;
	//cout<<"ma nhan vien"<<"\t"<<"ho lot"<<"\t\t"<<"ten"<<"\t"<<"tien luong"<<endl;
	for (int i=0;i<n;i++)
	{
	//	cout<<nv[i].manv<<"\t\t"<<nv[i].holot<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].tienluong<<endl;
		f<<nv[i].manv<<"\t\t"<<nv[i].holot<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].tienluong<<endl;
	}

}
void xuatvaofileO(nhanvien nv[], int n)
{
	s<<"ma nhan vien"<<"\t"<<"ho lot"<<"\t\t"<<"ten"<<"\t"<<"tien luong"<<endl;
//	cout<<"ma nhan vien"<<"\t"<<"ho lot"<<"\t\t"<<"ten"<<"\t"<<"tien luong"<<endl;
	for (int i=0;i<n;i++)
	{
//		cout<<nv[i].manv<<"\t\t"<<nv[i].holot<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].tienluong<<endl;
		s<<nv[i].manv<<"\t\t"<<nv[i].holot<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].tienluong<<endl;
	}

}
void tim(nhanvien nv[], int n)
{
	int x;
	int dem=0;
	cout<<"Vui long nhap ma de tim nhan vien : ";cin>>x;
	for(int i=0;i<n;i++)
	{
		if(nv[i].manv==x) 
		{
			s<<"ma nhan vien"<<"\t"<<"ho lot"<<"\t\t"<<"ten"<<"\t"<<"tien luong"<<endl;
			s<<nv[i].manv<<"\t\t"<<nv[i].holot<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].tienluong<<endl;
			dem++;
		}
	}
	if(dem==0) s<<"khong tim thay"<<endl;
	s<<"---------------------------------------------------------------"<<endl;
	
}
void luong(nhanvien nv[],int n)
{ 
	int max=nv[0].tienluong;
	int min=nv[0].tienluong;
	for(int i=1;i<n;i++)
	{
		if(max<nv[i].tienluong) 
		{
			max = nv[i].tienluong;
		}else max = max;
	}
	for(int i=1;i<n;i++)
	{
		if(nv[i].tienluong<min)
		{
			min=nv[i].tienluong;
		}else min=min;
	}
//	cout<<max<<endl;
//	cout<<min<<endl;
	
	for(int i=0;i<n;i++)
	{
		if(nv[i].tienluong==max) s<<"ho ten nhan vien co so tien luong cao nhat : "<<nv[i].holot<<" "<<nv[i].ten<<endl;
		if(nv[i].tienluong==min) s<<"ho ten nhan vien co so tien luong thap nhat : "<<nv[i].holot<<" "<<nv[i].ten<<endl;
	}
	s<<"---------------------------------------------------------------"<<endl;
}
void sapxep(nhanvien nv[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((nv[i].ten.compare(nv[j].ten))>0)
			{ 
				swap(nv[i],nv[j]);
			} else if((nv[i].ten.compare(nv[j].ten))==0)
			{
				if((nv[i].holot.compare(nv[j].holot))>0)
				{
					swap(nv[i],nv[j]);
				}
			}

		}
	}
}
int main()
{
	int n;
	int k;
	nhanvien nv[50];
	cout<<"------MENU------"<<endl;
	cout<<"Vui long chon so de chon cong viec thuc hien "<<endl;
	cout<<"Chon 1. De nhap nhan vien va xuat nhan vien vao file input3.txt"<<endl;
	cout<<"Chon 2. De nhap ma va tim nhan vien"<<endl;
	cout<<"Chon 3. De biet duoc ho ten nhan vien nao co luong cao nhat va thap nhat"<<endl;
	cout<<"Chon 4. De sap xep ten nhan vien tang dan theo chuoi"<<endl;
	cout<<"Nhap so : ";cin>>k;
	while(k==1||k==2||k==3||k==4)
	{
		if(k==1)
		{
			do{
				cout<<"nhap so luong nhan vien : ";cin>>n;
			}while(n>50);
			nhap(nv,n);
			xuatvaofileI(nv,n);
			xuatvaofileO(nv,n);
			s<<"---------------------------------------------------------------"<<endl;
		}else
		if(k==2)
		{
			tim(nv,n);
		}else
		if(k==3)
		{
			luong(nv,n);
		}else
		if(k==4)
		{
			sapxep(nv,n);
			xuatvaofileO(nv,n);
			s<<"---------------------------------------------------------------"<<endl;
		}
	cout<<"------MENU------"<<endl;
	cout<<"Vui long chon so de chon cong viec thuc hien "<<endl;
	cout<<"Chon 1. De nhap nhan vien va xuat nhan vien vao file input3.txt"<<endl;
	cout<<"Chon 2. De nhap ma va tim nhan vien"<<endl;
	cout<<"Chon 3. De biet duoc ho ten nhan vien nao co luong cao nhat va thap nhat"<<endl;
	cout<<"Chon 4. De sap xep ten nhan vien tang dan theo chuoi"<<endl;
	cout<<"Nhap so : ";cin>>k;
	}
	system("pause");
	
}
