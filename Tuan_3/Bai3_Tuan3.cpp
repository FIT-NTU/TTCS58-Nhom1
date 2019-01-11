#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
//------------------------------------------------
struct nhanvien
{
	int manv,sncong;
	unsigned int luong;
	char hoten[30];
};
//-------------------------------------------
void nhap(nhanvien a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap vao Ma nhan vien : ";	cin>>a[i].manv;
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[i].hoten,30);
		cout<<"So ngay cong : ";	cin>>a[i].sncong;
		a[i].luong=a[i].sncong*300000;
		cout<<"Luong : "<<a[i].luong<<endl;
	}
}
//------------------------------------------------
void Xuat(nhanvien a[],int n)
{
	cout<<"STT"<<"  "<<"Ma nhan vien"<<"  "<<"Ho ten nhan vien"<<"  "<<"So ngay cong"<<"  "<<"Luong"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<i+1<<"  "<<a[i].manv<<"   "<<" "<<a[i].hoten<<"\t "<<a[i].sncong<<"\t"<<a[i].luong<<endl;
	}
	cout<<endl;
}
//------------------------------------------------------------
void sapXep(nhanvien a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].sncong>a[j].sncong)
				swap(a[i],a[j]);
		}
	}
	Xuat(a,n);
}
//-------------------------------------------------------------
void timKiem(nhanvien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can tim : ";	cin>>x;
	for(int i=0;i<n;i++)
		if(a[i].manv==x)
			index=i;
	cout<<"Vi tri cua nhan vien : "<<index+1<<endl;
	cout<<"Ma: "<<a[index].manv<<"\t"<<"Ho ten: "<<a[index].hoten<<"\t"<<"So ngay cong: "<<a[index].sncong<<"\t "<<"Luong: "<<a[index].luong<<endl;
}
//------------------------------------------------------------------
void themNv(nhanvien a[],int &n)
{
	int h;
	cout<<"Ma nhan vien : ";	cin>>h;
	for(int j=0;j<n;j++)
	if(a[j].manv!=h)
	{
		++n;
		for(int i=0;i<n;i++)
		{
			if(i==n-1)
			{
				a[i].manv=h;
				fflush(stdin);
				cout<<"Ho ten nhan vien : ";	cin.getline(a[i].hoten,30);
				cout<<"So ngay cong : ";	cin>>a[i].sncong;
				a[i].luong=a[i].sncong*300000;
				cout<<"Luong : "<<a[i].luong<<endl;
				cout<<"Danh sach nhan vien sau khi them"<<endl;
			}
		}
		Xuat(a,n);
	}
}
//--------------------------------------------------------
void xoaNv(nhanvien a[],int &n)
{
	int x,index;
	cout<<"Ma nhan vien can xoa : ";	cin>>x;
	for(int i=0;i<n;i++)
		if(a[i].manv==x)
			index=i;
	if(a[index].manv==x)
	{
		while(index<n)
		{
			a[index]=a[index+1];
			index++;
		}
		n--;
		cout<<"Danh sach nhan vien sau khi xoa"<<endl;
		Xuat(a,n);
	}
	else
		cout<<"Ma nhan vien khong ton tai!"<<endl;
}
//------------------------------------------------------------
void capNhatNv(nhanvien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can sua : ";	cin>>x;
	for(int i=0;i<n;i++)
		if(a[i].manv==x)
			index=i;
	if(a[index].manv==x)
	{
		cout<<"Ma nhan vien moi : ";	cin>>a[index].manv;
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[index].hoten,30);
		cout<<"So ngay cong : ";	cin>>a[index].sncong;
		a[index].luong=a[index].sncong*300000;
		cout<<"Luong : "<<a[index].sncong<<endl;
		cout<<"Danh sach nhan vien sau khi cat nhap"<<endl;
		Xuat(a,n);
	}
	else
		cout<<"Ma nhan vien khong ton tai!"<<endl;
}
//--------------------------------------------------------
void ghiFile(char *file,nhanvien a[],int n)
{
	ofstream f;
	f.open(file);
	f<<n<<endl;
	for(int i=0;i<n;i++)
		f<<a[i].manv<<endl<<a[i].hoten<<endl<<a[i].sncong<<endl<<a[i].luong<<endl;
	f.close();
}
//--------------------------------------------------------------------
void menu()
{
	nhanvien a[100];
	int n;
	int chon;

		do
		{
			system("cls");
			cout<<"\t\t------------Menu------------"<<endl;
			cout<<"\t1.Nhap thong tin nhan vien"<<endl;
			cout<<"\t2.In danh sach nhan vien"<<endl;
			cout<<"\t3.Sap xep danh sach nhan vien theo so ngay cong"<<endl;
			cout<<"\t4.Tim kiem nhan vien theo ma nhan vien"<<endl;
			cout<<"\t5.Them mot nhan vien moi"<<endl;
			cout<<"\t6.Xoa mot nhan vien theo ma nhan vien"<<endl;
			cout<<"\t7.Cap nhat thong tin nhan vien theo ma nhan vien"<<endl;
			cout<<"\t8. Thoat !"<<endl;
			cout<<"\tChon chuc nang : ";	
			cin>>chon;
			switch(chon)
			{		
				case 1:
					cout<<endl;
					do
					{
						cout<<"So luong nhan vien : ";
						cin>>n;
					}while(n<0 || n>=10);
					nhap(a,n);
					ghiFile("input3.txt",a,n);
					system("pause");
					do
					{
						system("cls");
						cout<<"---------Menu---------"<<endl;
						cout<<"\t1.In danh sach nhan vien"<<endl;
						cout<<"\t2.Sap xep danh sach nhan vien theo so ngay cong"<<endl;
						cout<<"\t3.Tim kiem nhan vien theo ma nhan vien"<<endl;
						cout<<"\t4.Them mot nhan vien moi"<<endl;
						cout<<"\t5.Xoa mot nhan vien theo ma nhan vien"<<endl;
						cout<<"\t6.Cap nhat thong tin nhan vien theo ma nhan vien"<<endl;
						cout<<"\t8.Thoat !!"<<endl;
						cout<<"\tChon menu : "<<endl;	
						cin>>chon;
						switch(chon)
						{
							case 8:
								break;
							case 1:
								cout<<endl;
								Xuat(a,n);
								system("pause");
								break;
							case 2:
								cout<<endl;
								sapXep(a,n);
								system("pause");
								break;
							case 3:
								cout<<endl;
								timKiem(a,n);
								system("pause");
								break;
							case 4:
								cout<<endl;
								themNv(a,n);
								system("pause");
								break;
							case 5:
								cout<<endl;
								xoaNv(a,n);
								system("pause");
								break;
							case 6:
								cout<<endl;
								capNhatNv(a,n);
								system("pause");
								break;
							default:
								cout<<"Muc lua chon khong ton tai!"<<endl;
								break;
						}
					}while(chon!=0);
					break;
				default:
					cout<<"khong co du lieu"<<endl;
					system("pause");
			}
		}while(chon!=0&&chon!=1);
}
//-------------------------------------------------------
int main()
{
	menu();
	system("pause");
}
