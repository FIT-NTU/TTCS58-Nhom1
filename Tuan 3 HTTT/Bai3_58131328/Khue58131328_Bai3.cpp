#include<iostream>
using namespace std;
#include<fstream>
#include<stdlib.h>
#include<string.h>
struct nhanVien
{
	int maNv,soNgayCong;
	unsigned int luong;
	char hoTen[30];
};
void nhap(nhanVien a[],int &n);
void inDanhSachNv(nhanVien a[],int n);
void sapXep(nhanVien a[],int n);
void timKiem(nhanVien a[],int n);
int tkVitri(nhanVien a[],int n,int x);
void themNv(nhanVien a[],int &n);
void xoaNv(nhanVien a[],int &n);
void capNhatNv(nhanVien a[],int n);
void ghiFile(char *file,nhanVien a[],int n);
void nhap(nhanVien a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Ma nhan vien : ";	cin>>a[i].maNv;
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[i].hoTen,30);
		cout<<"So ngay cong : ";	cin>>a[i].soNgayCong;
		a[i].luong=a[i].soNgayCong*300000;
		cout<<"Luong : "<<a[i].luong<<endl;
	}
}
void inDanhSachNv(nhanVien a[],int n)
{
	cout<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"So ngay cong"<<"|"<<"Luong"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<i+1<<"\t"<<a[i].maNv<<"\t"<<" "<<a[i].hoTen<<"\t\t    "<<a[i].soNgayCong<<"\t"<<a[i].luong<<endl;
	}
	cout<<endl;
}
void sapXep(nhanVien a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].soNgayCong>a[j].soNgayCong)
				swap(a[i],a[j]);
		}
	}
	inDanhSachNv(a,n);
}
void timKiem(nhanVien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can tim : ";	cin>>x;
	for(int i=0;i<n;i++)
		if(a[i].maNv==x)
			index=i;
	cout<<"Vi tri cua nhan vien : "<<index+1<<endl;
	cout<<a[index].maNv<<" "<<a[index].hoTen<<" "<<a[index].soNgayCong<<" "<<a[index].luong<<endl;
}
int tkVitri(nhanVien a[],int n,int x)
{
	for(int i=0;i<n;i++)
		if(a[i].maNv==x)
			return i;
	return -1;
}
void themNv(nhanVien a[],int &n)
{
	int h,index;
	cout<<"Ma nhan vien : ";	cin>>h;
	if(tkVitri(a,n,h)!=-1)
		cout<<"Ma nhan vien da ton tai!"<<endl;
	else
	{
		++n;
		for(int i=0;i<n;i++)
		{
			if(i==n-1)
			{
				a[i].maNv=h;
				fflush(stdin);
				cout<<"Ho ten nhan vien : ";	cin.getline(a[i].hoTen,30);
				cout<<"So ngay cong : ";	cin>>a[i].soNgayCong;
				a[i].luong=a[i].soNgayCong*300000;
				cout<<"Luong : "<<a[i].luong<<endl;
				cout<<"Danh sach nhan vien sau khi them"<<endl;
			}
		}
		inDanhSachNv(a,n);
	}
}
void xoaNv(nhanVien a[],int &n)
{
	int x,index;
	cout<<"Ma nhan vien can xoa : ";	cin>>x;
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
		inDanhSachNv(a,n);
	}
	else
		cout<<"Ma nhan vien khong ton tai!"<<endl;
}
void capNhatNv(nhanVien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can sua : ";	cin>>x;
	int h=tkVitri(a,n,x);
	if(tkVitri(a,n,x)!=-1)
	{
		cout<<"Ma nhan vien moi : ";	cin>>a[h].maNv;
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[h].hoTen,30);
		cout<<"So ngay cong : ";	cin>>a[h].soNgayCong;
		a[h].luong=a[h].soNgayCong*300000;
		cout<<"Luong : "<<a[h].soNgayCong<<endl;
		cout<<"Danh sach nhan vien sau khi cat nhap"<<endl;
		inDanhSachNv(a,n);
	}
	else
		cout<<"Ma nhan vien khong ton tai!"<<endl;
}
void ghiFile(char *file,nhanVien a[],int n)
{
	ofstream f;
	f.open(file);
	f<<n<<endl;
	for(int i=0;i<n;i++)
		f<<a[i].maNv<<endl<<a[i].hoTen<<endl<<a[i].soNgayCong<<endl<<a[i].luong<<endl;
	f.close();
}
//void ghiFileNhiPhan(char *file,nhanVien a[],int n)
//{
//	FILE *f;
//	f=fopen(file,"wb");
//	fwrite(&a,sizeof(nhanVien),1,f);
//	fclose(f);
//}
//void docFileNhiPhan(char *file,nhanVien a[],int n)
//{
//	FILE *g;
//	g=fopen(file,"rb");
//	fread(&a,sizeof(nhanVien),1,g);
//	for(int i=0;i<n;i++)
//		cout<<a[i].maNv<<"\t"<<" "<<a[i].hoTen<<"\t\t    "<<a[i].soNgayCong<<"\t"<<a[i].luong<<endl;
//	fclose(g);
//}
void menu()
{
	nhanVien a[10];
	int n;
	int chon;
	ifstream g;
	g.open("input3.txt");
	if(g!=NULL)
	{
		char s[50];
		g.getline(s,50);	n=atoi(s);
		for(int i=0;i<n;i++)
		{
			g.getline(s,50);	a[i].maNv=atoi(s);
			g.getline(s,50);	strcpy(a[i].hoTen,s);
			g.getline(s,50);	a[i].soNgayCong=atoi(s);
			g.getline(s,50);	a[i].luong=atoi(s);
		}
		inDanhSachNv(a,n);
		system("pause");
		do
		{
			system("cls");
			cout<<"---------Chuong trinh quan ly nhan vien---------"<<endl;
			cout<<"1.In danh sach nhan vien"<<endl;
			cout<<"2.Sap xep danh sach nhan vien theo so ngay cong"<<endl;
			cout<<"3.Tim kiem nhan vien theo ma nhan vien"<<endl;
			cout<<"4.Them mot nhan vien moi"<<endl;
			cout<<"5.Xoa mot nhan vien theo ma nhan vien"<<endl;
			cout<<"6.Cap nhat thong tin nhan vien theo ma nhan vien"<<endl;
			cout<<"0.Thoat\n\n";
			cout<<"Chon menu :>";	cin>>chon;
			switch(chon)
			{
				case 0:
					break;
				case 1:
					cout<<endl;
					inDanhSachNv(a,n);
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
	}
	else
	{
		do
		{
			system("cls");
			cout<<"------------Chuong trinh quan ly nhan vien------------"<<endl;
			cout<<"1.Nhap danh sach nhan vien"<<endl;
			cout<<"2.In danh sach nhan vien"<<endl;
			cout<<"3.Sap xep danh sach nhan vien theo so ngay cong"<<endl;
			cout<<"4.Tim kiem nhan vien theo ma nhan vien"<<endl;
			cout<<"5.Them mot nhan vien moi"<<endl;
			cout<<"6.Xoa mot nhan vien theo ma nhan vien"<<endl;
			cout<<"7.Cap nhat thong tin nhan vien theo ma nhan vien"<<endl;
			cout<<"0.Thoat\n\n";
			cout<<"Chon menu :>";	cin>>chon;
			switch(chon)
			{
				case 0:
					break;
				case 1:
					cout<<endl;
					do
					{
						cout<<"So luong nhan vien : ";
						cin>>n;
					}while(n>10);
					nhap(a,n);
					ghiFile("input3.txt",a,n);
					system("pause");
					do
					{
						system("cls");
						cout<<"---------Chuong trinh quan ly nhan vien---------"<<endl;
						cout<<"1.In danh sach nhan vien"<<endl;
						cout<<"2.Sap xep danh sach nhan vien theo so ngay cong"<<endl;
						cout<<"3.Tim kiem nhan vien theo ma nhan vien"<<endl;
						cout<<"4.Them mot nhan vien moi"<<endl;
						cout<<"5.Xoa mot nhan vien theo ma nhan vien"<<endl;
						cout<<"6.Cap nhat thong tin nhan vien theo ma nhan vien"<<endl;
						cout<<"0.Thoat\n\n";
						cout<<"Chon menu :>";	cin>>chon;
						switch(chon)
						{
							case 0:
								break;
							case 1:
								cout<<endl;
								inDanhSachNv(a,n);
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
					cout<<"Du lieu khong ton tai!"<<endl;
					system("pause");
			}
		}while(chon!=0&&chon!=1);
	}
}
int main()
{
	menu();
	return 0;
}
