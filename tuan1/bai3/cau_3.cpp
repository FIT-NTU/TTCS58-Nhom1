#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
int n,x,indexmin,indexmax;
struct nhanvien{
	int ma,luong;
	string ho,ten;
};
void doc(nhanvien *&nv)
{
	fstream f;
	f.open("D:\\input3.txt",ios::in);
	f>>n;
	
    //cout<<"==============thong tin tu file==============="<<endl;
	for(int i=0;i<n;i++)
	{
		f>>nv[i].ma;
		f>>nv[i].ho;
		f>>nv[i].ten;
		f>>nv[i].luong;
				
	} f.close();
	
	
}
void xuat(nhanvien *nv)
{
	for(int i=0;i<n;i++)
	{
		cout<<"ma nhan vien: "<<nv[i].ma<<endl;
		cout<<"ho nhan vien: "<<nv[i].ho<<endl;
		cout<<"ho nhan vien: "<<nv[i].ten<<endl;
		cout<<"ho nhan vien: "<<nv[i].luong<<endl;
	}
}
void  tim(nhanvien *nv)
{
	for(int i=0;i<n;i++)
	{
		if(nv[i].ma==x)
		{	
			cout<<"ma nhan vien: "<<nv[i].ma<<endl;
			cout<<"ho nhan vien: "<<nv[i].ho<<endl;
			cout<<"ten nhan vien: "<<nv[i].ten<<endl;
			cout<<"luong nhan vien: "<<nv[i].luong<<endl;			
		}
	}
}
void menu()
{	
	cout<<"\n\n=============menu=================="<<endl;	
	cout<<"1.nhap ma nhan vien can tim"<<endl;
	cout<<"2.nhan vien co luong cao nhat va thap nhat"<<endl;
	cout<<"3.sap xep nhan vien "<<endl;
	cout<<"4.in ket qua vao file"<<endl;
	cout<<"5.nhap them nhan vien"<<endl;
}
void sapxep(nhanvien *&nv)
{
	for(int i =0 ; i<n-1; i++)
	{
		for(int j = i+1; j<n;j++)
		{
			if(nv[i].ten.compare(nv[j].ten) > 0 )
			{
				swap(nv[i],nv[j]);
			}
			else if(nv[i].ten.compare(nv[j].ten) == 0)
			{
				if(nv[i].ho.compare(nv[j].ho)>0)
				{
					swap(nv[i],nv[j]);
				}
			}
		}
	}xuat(nv); 	
}

void luongmaxmin(nhanvien *nv)
{
	int  max =nv[0].luong;
	 int min = nv[0].luong;
	 int indexmax=0, indexmin=0;
	for(int i=0;i<n;i++)
	{
		if(nv[i].luong >= max) 
		{
			max= nv[i].luong;
			indexmax = i;
			cout<<endl<<"nhan vien co luong cao nhat: "<<nv[indexmax].ho<<" "<<nv[indexmax].ten;
		}
	
	}
	for(int i=0;i<n;i++)
	{
		if(nv[i].luong < min)
		{
		  	min= nv[i].luong;
			indexmin=i;
		cout<<endl<<"nhan vien co luong thap nhat: "<<nv[indexmin].ho<<" "<<nv[indexmin].ten;
		}
		
	}
}
void ghifile(nhanvien *nv)
{
	fstream f;
	f.open("D:\\output3.txt",ios::out);
	// dau ket qua tim vao file
	f<<"=============ket qua 1============"<<endl;
	for(int i=0;i<n;i++)
	{
		if(nv[i].ma==x)
		{
			f<<"ma nhan vien: "<<nv[i].ma<<endl;
			f<<"ho nhan vien: "<<nv[i].ho<<endl;
			f<<"ten nhan vien: "<<nv[i].ten<<endl;
			f<<"luong nhan vien: "<<nv[i].luong<<endl;
		}
	}	 
		// ket qua luong
	f<<"================ket qua 2============="<<endl;
		 int max =nv[0].luong;
		 int min = nv[0].luong;
		 indexmax=0, indexmin=0;
	for(int i=0;i<n;i++)
	{
		if(nv[i].luong >= max) 
		{
			max= nv[i].luong;
			indexmax = i;
			f<<endl<<"nhan vien co luong cao nhat: "<<nv[indexmax].ho<<" "<<nv[indexmax].ten;
		}	
	}
	for(int i=0;i<n;i++)
	{
		if(nv[i].luong < min)
		{
			min= nv[i].luong;
			indexmin=i;
			f<<endl<<"nhan vien co luong thap nhat: "<<nv[indexmin].ho<<" "<<nv[indexmin].ten;
		}
	}
	// ket qua sau khi sap xep
	f<<endl<<"==========ket qua 3============"<<endl;
		sapxep(nv);
		for(int i=0;i<n;i++)
		{
			f<<"ma nhan vien: "<<nv[i].ma<<endl;
			f<<"ho nhan vien: "<<nv[i].ho<<endl;
			f<<"ten nhan vien: "<<nv[i].ten<<endl;
			f<<"luong nhan vien: "<<nv[i].luong<<endl;
		}	
	f.close();	
}
void nhapthem(nhanvien *nv)
{
	fstream f;
	//nhanvien *nv;
	int m;
	cout<<"==============Moi nhap thong tin nhan vien==============";
	cout<<endl<<"so luong nhan vien them: ";
	cin>>m;
	//nv = new nhanvien[m];
	f.open("D:\\input3.txt",ios::out);
	f<<n+m<<endl;
	for(int i=0; i<n;i++){
		f<<nv[i].ma<<endl;
		f<<nv[i].ho<<endl;
		f<<nv[i].ten<<endl;
		f<<nv[i].luong<<endl;
		
	}
	for(int i=n;i<n+m;i++)
	{	
		fflush(stdin);
		cout<<endl<<"ma nhan vien: ";
		cin>>nv[i].ma;
		cin.ignore();
		f<<nv[i].ma<<endl;
		fflush(stdin);
		cout<<"ho nhan vien:"<<endl;
		getline(cin,nv[i].ho);
		f<<nv[i].ho<<endl;
		fflush(stdin);
		cout<<"ten nhan vien:"<<endl;
		getline(cin,nv[i].ten);
		f<<nv[i].ten<<endl;
		fflush(stdin);
		cout<<"luong nhan vien: "<<endl;
		cin>>nv[i].luong;
		cin.ignore();
		f<<nv[i].luong<<endl;
	}
	

	f.close();
	
}
void chon(nhanvien *nv)
{	
	menu();
	int b ;
	cout<<"----------------"<<"chon cac muc trong menu phia tren"<<"-----------"<<endl;
	cout<<"lua chon so";
	cin>>b;
	switch(b)
	{					
		case 1: 	
					cout<<"nhap ma nhan vien can tim: ";
					cin>>x;
					tim(nv);
					chon(nv);	
			break;
		case 2 :
					luongmaxmin(nv);
					chon(nv);
			break;
		case 3:	
					cout<<"ket qua sau khi sap xep:"<<endl;
					sapxep(nv);
					chon(nv);
			break;
		case 4:
					ghifile(nv);
			break;
		case 5:
					nhapthem(nv);
			break;	
		default:
					cout<<"ban nhap ko hop le"<<endl<<"--------"<<"moi ban nhap lai"<<"--------"<<endl;	
					menu();
					cout<<endl;
					chon(nv);	
					
	}	
}

int main()
{	
 	 int n;
 	 nhanvien *nv;
 	 nv = new nhanvien[50];
 	 doc(nv);
 	 xuat(nv);
 	 chon(nv);
}

