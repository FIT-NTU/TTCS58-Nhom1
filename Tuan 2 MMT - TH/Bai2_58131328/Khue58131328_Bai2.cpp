#include<iostream>
using namespace std;
#include<fstream>
#include<stdlib.h>
#include<string.h>
struct nhanVien
{
	int maNv;
	char hoTen[30];
	int tuoi;
	int luongCb;
};
ofstream k ("output2.txt");
void nhap(nhanVien a[],int &n);
void themNv(nhanVien a[],int &n);
void xoaNv(nhanVien a[],int &n);
void capNhatNv(nhanVien a[],int n);
void timKiemNv(nhanVien a[],int n);
void ghifile(char *file,nhanVien a[],int n);
void ghiFileNhiPhan(char *file,nhanVien a[],int n);
void docFileNhiPhan(char *file,nhanVien a[],int n);
void nhap(nhanVien a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Ma nhan vien : ";	cin>>a[i].maNv;
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[i].hoTen,30);
		cout<<"Tuoi : ";	cin>>a[i].tuoi;
		cout<<"Luong : ";	cin>>a[i].luongCb;
	}
}
void inDanhSachNv(nhanVien a[],int n)
{
	cout<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<i+1<<"\t"<<a[i].maNv<<"\t"<<" "<<a[i].hoTen<<"\t\t    "<<a[i].tuoi<<"\t"<<a[i].luongCb<<endl;
	}
	cout<<endl;
}
void themNv(nhanVien a[],int &n)
{
	int x,index;
	cout<<"Vi tri can them : ";	cin>>x;
	if(x>=0&&x<=n)
	{
		int h;
		cout<<"Ma nhan vien : ";	cin>>h;
		for(int j=0;j<n;j++)
			if(a[j].maNv==h)
				index=j;
		if(a[index].maNv==h)
			cout<<"Ma nhan vien da ton tai!"<<endl;
		else
		{
			for(int i=n;i>x;i--)
				a[i]=a[i-1];
			a[x].maNv=h;
			fflush(stdin);
			cout<<"Ho ten nhan vien : ";	cin.getline(a[x].hoTen,30);
			cout<<"Tuoi : ";	cin>>a[x].tuoi;
			cout<<"Luong : ";	cin>>a[x].luongCb;
			n++;
			cout<<"Danh sach nhan vien sau khi them"<<endl;
			k<<"Sau khi them mot nhan vien vao danh sach : "<<endl;
			k<<"---------------------------------------------"<<endl;
			k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
			for(int j=0;j<n;j++)
				k<<" "<<j+1<<"\t"<<a[j].maNv<<"\t"<<" "<<a[j].hoTen<<"\t\t    "<<a[j].tuoi<<"\t"<<a[j].luongCb<<endl;
			inDanhSachNv(a,n);
		}
	}
	else
		cout<<"Vi tri nay khong the them!"<<endl;
}
void xoaNv(nhanVien a[],int &n)
{
	int x,index;
	cout<<"Ma nhan vien can xoa : ";
	cin>>x;
	for(int i=0;i<n;i++)
		if(a[i].maNv==x)
			index=i;
	if(a[index].maNv==x)
	{
		while(index<n)
		{
			a[index]=a[index+1];
			index++;
		}
		n--;
		cout<<"Danh sach nhan vien sau khi xoa"<<endl;
		k<<"Sau khi xoa mot nhan vien vao danh sach : "<<endl;
		k<<"---------------------------------------------"<<endl;
		k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
		for(int j=0;j<n;j++)
			k<<" "<<j+1<<"\t"<<a[j].maNv<<"\t"<<" "<<a[j].hoTen<<"\t\t    "<<a[j].tuoi<<"\t"<<a[j].luongCb<<endl;
		inDanhSachNv(a,n);
	}
	else
		cout<<"Ma nhan vien khong ton tai!"<<endl;
}
void capNhatNv(nhanVien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can sua : ";
	cin>>x;
	for(int i=0;i<n;i++)
	{
		if(a[i].maNv==x)
			index=i;
	}
	if(a[index].maNv==x)
	{
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[index].hoTen,30);
		cout<<"Tuoi : ";	cin>>a[index].tuoi;
		cout<<"Luong : ";	cin>>a[index].luongCb;
		cout<<"Danh sach nhan vien sau khi cat nhap"<<endl;
		k<<"---------------------------------------------"<<endl;
		k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
		k<<"Danh sach sau khi cap nhat : "<<endl;
		for(int j=0;j<n;j++)
			k<<" "<<j+1<<"\t"<<a[j].maNv<<"\t"<<" "<<a[j].hoTen<<"\t\t    "<<a[j].tuoi<<"\t"<<a[j].luongCb<<endl;
		inDanhSachNv(a,n);
	}
	else
		cout<<"Ma nhan vien khong ton tai!"<<endl;
}
void timKiemNv(nhanVien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can tim : ";
	cin>>x;
	for(int i=0;i<n;i++)
	{
		if(a[i].maNv==x)
			index=i;
	}
	if(a[index].maNv==x)
	{
		cout<<" "<<a[index].maNv<<"\t"<<a[index].hoTen<<"\t"<<a[index].tuoi<<"\t"<<a[index].luongCb<<endl;
		k<<"---------------------------------------------"<<endl;
		k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
		k<<"Ket qua sau khi tim kiem : "<<endl;
		k<<"Vi tri : "<<index<<a[index].maNv<<"\t"<<a[index].hoTen<<"\t"<<a[index].tuoi<<"\t"<<a[index].luongCb<<endl;
	}
	else
		cout<<"Ma nhan vien khong ton tai!"<<endl;
}
void ghifile(char *file,nhanVien a[],int n)
{
	ofstream f;
	f.open(file);
	f<<n<<endl;
	for(int i=0;i<n;i++)
		f<<a[i].maNv<<endl<<a[i].hoTen<<endl<<a[i].tuoi<<endl<<a[i].luongCb<<endl;
	f.close();
}
void ghiFileNhiPhan(char *file,nhanVien a[],int n)
{
	FILE *f;
	f=fopen(file,"wb");
	fwrite(&a,sizeof(nhanVien),1,f);
	fclose(f);
}
void docFileNhiPhan(char *file,nhanVien a[],int n)
{
	FILE *g;
	g=fopen(file,"rb");
	fread(&a,sizeof(nhanVien),1,g);
	for(int i=0;i<n;i++)
		cout<<a[i].maNv<<"\t"<<" "<<a[i].hoTen<<"\t\t    "<<a[i].tuoi<<"\t"<<a[i].luongCb<<endl;
	fclose(g);
}
int main()
{
	nhanVien a[50];
	int n,chon;
	ifstream g;
	g.open("input2.txt");
	if(g!=NULL)
	{
		char s[30];
		g.getline(s,30);	n=atoi(s);
		cout<<"Du lieu trong file : "<<endl;
		cout<<"So luong nhan vien : "<<n<<endl;
		cout<<"---------------------------------------------"<<endl;
		cout<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"\t|"<<"Tuoi"<<"|"<<"Luong"<<endl;
		for(int i=0;i<n;i++)
		{
			g.getline(s,30);	a[i].maNv=atoi(s);
			g.getline(s,30);	strcpy(a[i].hoTen,s);
			g.getline(s,30);	a[i].tuoi=atoi(s);
			g.getline(s,30);	a[i].luongCb=atoi(s);
			cout<<" "<<i+1<<"\t"<<a[i].maNv<<"\t"<<" "<<a[i].hoTen<<"\t"<<a[i].tuoi<<"\t"<<a[i].luongCb<<endl;
		}
		system("pause");
		do
		{
			system("cls");
			cout<<"--------Chuong trinh quan ly nhan vien---------"<<endl;
			cout<<"1.Them mot nhan vien"<<endl;
			cout<<"2.Sua doi thong tin nhan vien theo ma nhan vien"<<endl;
			cout<<"3.Xoa mot nhan vien theo ma nhan vien"<<endl;
			cout<<"4.Tim kiem nhan vien theo ma nhan vien"<<endl;
			cout<<"5.In danh sach nhan vien"<<endl;
			cout<<"0.Thoat"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Chon :>";	cin>>chon;
			switch(chon)
			{
				case 0:
					break;
				case 1:
					themNv(a,n);
					system("pause");
					break;
				case 2:
					capNhatNv(a,n);
					system("pause");
					break;
				case 3:
					xoaNv(a,n);
					system("pause");
					break;
				case 4:
					timKiemNv(a,n);
					system("pause");
					break;
				case 5:
					inDanhSachNv(a,n);
					system("pause");
					break;
				default:
					cout<<"Muc lua chon khong ton tai!"<<endl;
			}
		}while(chon!=0);
	}
	else
	{
		do
		{
			system("cls");
			cout<<"--------Chuong trinh quan ly nhan vien---------"<<endl;
			cout<<"1.Nhap danh sach nhan vien"<<endl;
			cout<<"2.Them mot nhan vien"<<endl;
			cout<<"3.Sua doi thong tin nhan vien theo ma nhan vien"<<endl;
			cout<<"4.Xoa mot nhan vien theo ma nhan vien"<<endl;
			cout<<"5.Tim kiem nhan vien theo ma nhan vien"<<endl;
			cout<<"6.In danh sach nhan vien"<<endl;
			cout<<"0.Thoat"<<endl;
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Chon menu :>";
			cin>>chon;
			switch(chon)
			{
				case 0:
					break;
				case 1:
					cout<<"So luong nhan vien : ";
					cin>>n;
					nhap(a,n);
					ghifile("input2.txt",a,n);
					system("pause");
					do
					{
						system("cls");
						cout<<"--------Chuong trinh quan ly nhan vien---------"<<endl;
						cout<<"1.Them mot nhan vien"<<endl;
						cout<<"2.Sua doi thong tin nhan vien theo ma nhan vien"<<endl;
						cout<<"3.Xoa mot nhan vien theo ma nhan vien"<<endl;
						cout<<"4.Tim kiem nhan vien theo ma nhan vien"<<endl;
						cout<<"5.In danh sach nhan vien"<<endl;
						cout<<"0.Thoat"<<endl;
						cout<<"-----------------------------------------------"<<endl;
						cout<<"Chon :>";	cin>>chon;
						switch(chon)
						{
							case 0:
								break;
							case 1:
								themNv(a,n);
								system("pause");
								break;
							case 2:
								capNhatNv(a,n);
								system("pause");
								break;
							case 3:
								xoaNv(a,n);
								system("pause");
								break;
							case 4:
								timKiemNv(a,n);
								system("pause");
								break;
							case 5:
								inDanhSachNv(a,n);
								system("pause");
								break;
							default:
								cout<<"Muc lua chon khong ton tai!"<<endl;
						}
					}while(chon!=0);
					break;
				default:
					cout<<"Du lieu khong ton tai!"<<endl;
					system("pause");
			}
		}while(chon!=0&&chon!=1);
	}
	g.close();
	return 0;
}
