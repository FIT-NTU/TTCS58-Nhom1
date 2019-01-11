#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
ofstream g ("output3.txt");
struct nhanvien
{
	int manv, tienluong;
	char holot[30],ten[10];
};
void nhap(nhanvien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhan vien "<<i+1<<endl;
		cout<<"Ma so nhan vien : ";	cin>>a[i].manv;
		fflush(stdin);
		cout<<"Ho lot : ";	cin.getline(a[i].holot,30);
		cout<<"Ten : ";	cin.getline(a[i].ten,10);
		cout<<"Tien luong : ";	cin>>a[i].tienluong;
	}
	ofstream f;
	f.open("input3.txt");
	f<<n<<endl;
	for(int i=0;i<n;i++)
	{
		f<<a[i].manv<<endl;
		f<<a[i].holot<<endl;
		f<<a[i].ten<<endl;
		f<<a[i].tienluong<<endl;
	}
	f.close();
}
void timkiemmanv(nhanvien a[],int n)
{
	int x,index;
	cout<<"Nhap ma nhan vien can tim : ";	cin>>x;
	for(int i=0;i<n;i++)
		if(x==a[i].manv)
			index=i;
	if(a[index].manv==x)
	{
		cout<<"Thong tin nhan vien da duoc tim kiem : "<<x<<endl;
		g<<"Thong tin nhan vien da duoc tim kiem : "<<x<<endl;
		cout<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong"<<endl;
		g<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong"<<endl;
		cout<<" "<<index+1<<"\t"<<" "<<a[index].manv<<"\t"<<" "<<a[index].holot<<"\t"<<" "<<a[index].ten<<"\t"<<" "<<a[index].tienluong<<endl;
		g<<a[index].manv<<"\t"<<a[index].holot<<"\t\t"<<a[index].ten<<"\t\t"<<a[index].tienluong<<endl;
	}
	else
		cout<<"Khong co ma nhan vien nay!"<<endl;
}
void maxmin(nhanvien a[],int n)
{
	int max=a[0].tienluong,index;
	for(int i=0;i<n;i++)
	{
		if(max<=a[i].tienluong)
		{
			max=a[i].tienluong;
			index=i;
		}
	}
	int min=a[0].tienluong,index1;
	for(int j=0;j<n;j++)
	{
		if(min>=a[j].tienluong)
		{
			min=a[j].tienluong;
			index1=j;
		}
	}
	cout<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong Lon Nhat"<<endl;
	g<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong Lon Nhat"<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i].tienluong==max)
		{
			cout<<" "<<i+1<<"\t"<<" "<<a[i].manv<<"\t"<<a[i].holot<<"\t"<<a[i].ten<<"\t\t"<<max<<endl;
			g<<" "<<i+1<<"\t"<<" "<<a[i].manv<<"\t"<<a[i].holot<<"\t"<<a[i].ten<<"\t\t"<<max<<endl;
		}
	}
	cout<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong Nho Nhat"<<endl;
	g<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong Nho Nhat"<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i].tienluong==min)
		{
			cout<<" "<<i+1<<"\t"<<" "<<a[i].manv<<"\t"<<a[i].holot<<"\t"<<a[i].ten<<"\t\t"<<min<<endl;
			g<<" "<<i+1<<"\t"<<" "<<a[i].manv<<"\t"<<a[i].holot<<"\t"<<a[i].ten<<"\t\t"<<min<<endl;
		}
	}
}
void sapxep(nhanvien a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(strcmp(a[i].ten,a[j].ten)>0)
				swap(a[i],a[j]);
			else
			{
				if(strcmp(a[i].ten,a[j].ten)==0)
				{
					if(strcmp(a[i].holot,a[j].holot)>0)
						swap(a[i],a[j]);
				}
			}
}
void xuat(nhanvien a[],int n)
{
	cout<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong"<<endl;
	g<<"STT"<<"\t"<<"MaNV"<<"\t"<<"Ho lot"<<"\t\t"<<"Ten"<<"\t\t"<<"Tien Luong"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<i+1<<"\t"<<" "<<a[i].manv<<"\t"<<" "<<a[i].holot<<"\t"<<" "<<a[i].ten<<"\t"<<" "<<a[i].tienluong<<endl;
		g<<a[i].manv<<"\t"<<a[i].holot<<"\t\t"<<a[i].ten<<"\t\t"<<a[i].tienluong<<endl;
	}
}
void menu(nhanvien a[],int n)
{
	ifstream k;
	k.open("input3.txt");
	int chon;
	if(k!=NULL)
	{
		cout<<"Du lieu trong file input3.txt"<<endl;
		char s[30];
		k.getline(s,30);	n=atoi(s);
		cout<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho lot nhan vien"<<"\t|"<<"Ten"<<"\t|"<<"Tuoi"<<"|"<<"Luong"<<endl;
		for(int i=0;i<n;i++)
		{
			k.getline(s,30);	a[i].manv=atoi(s);
			k.getline(s,30);	strcpy(a[i].holot,s);
			k.getline(s,30);	strcpy(a[i].ten,s);
			k.getline(s,30);	a[i].tienluong=atoi(s);
			cout<<i+1<<"\t"<<a[i].manv<<"\t"<<" "<<a[i].holot<<"\t\t"<<a[i].ten<<"\t"<<a[i].tienluong<<endl;
		}
		do
		{
			cout<<"1.Nhap lai danh sach nhan vien"<<endl;
			cout<<"2.Tim kiem thong tin nhan vien qua MA NHAN VIEN"<<endl;
			cout<<"3.Thong tin nhan vien co luong cao nhat va nhan vien co luong thap nhat"<<endl;
			cout<<"4.Sap xep ten nhan vien theo thu tu tang dan theo ten (theo ho)"<<endl;
			cout<<"5.Thoat"<<endl;
			cout<<"------------------------------------------------------------------------"<<endl;
			cout<<"Chon muc tu menu: ";	cin>>chon;
			switch(chon)
			{
				case 1:
					do
					{
						cout<<"So luong nhan vien : ";
						cin>>n;
					}while(n>50);
					nhap(a,n);
					cout<<"Du lieu da ghi vao file input3.txt"<<endl;
					break;
				case 2:
					timkiemmanv(a,n);
					break;
				case 3:
					cout<<"Danh sach nhan vien co tien luong lon nhat va thap nhat : "<<endl;
					g<<"Danh sach nhan vien co tien luong lon nhat va thap nhat : "<<endl;
					maxmin(a,n);
					break;
				case 4:
					cout<<"Sau khi da sap xep : "<<endl;
					g<<"Sau khi da sap xep : "<<endl;
					sapxep(a,n);
					xuat(a,n);
				case 5:
					cout<<"Ket thuc"<<endl;
					break;
				default:
					cout<<"Muc ban lua chua khong ton tai! Xin lua chon lai memu :"<<endl;
					break;
			}
		}while(chon!=5);
	}
	else
	{
		do
		{
			cout<<"1.Nhap danh sach nhan vien"<<endl;
			cout<<"2.Tim kiem thong tin nhan vien qua MA NHAN VIEN"<<endl;
			cout<<"3.Thong tin nhan vien co luong cao nhat va nhan vien co luong thap nhat"<<endl;
			cout<<"4.Sap xep ten nhan vien theo thu tu tang dan theo ten (theo ho)"<<endl;
			cout<<"5.Thoat"<<endl;
			cout<<"------------------------------------------------------------------------"<<endl;
			cout<<"Chon muc tu menu: ";	cin>>chon;
			switch(chon)
			{
				case 1:
					do
					{
						cout<<"So luong nhan vien : ";
						cin>>n;
					}while(n>50);
					nhap(a,n);
					do
					{
						cout<<"1.Nhap lai danh sach nhan vien"<<endl;
						cout<<"2.Tim kiem thong tin nhan vien qua MA NHAN VIEN"<<endl;
						cout<<"3.Thong tin nhan vien co luong cao nhat va nhan vien co luong thap nhat"<<endl;
						cout<<"4.Sap xep ten nhan vien theo thu tu tang dan theo ten (theo ho)"<<endl;
						cout<<"5.Thoat"<<endl;
						cout<<"------------------------------------------------------------------------"<<endl;
						cout<<"Chon muc tu menu: ";	cin>>chon;
					switch(chon)
					{
						case 1:
							do
							{
								cout<<"So luong nhan vien : ";
								cin>>n;
							}while(n>50);
							nhap(a,n);
							cout<<"Du lieu da ghi vao file input3.txt"<<endl;
							break;
						case 2:
							timkiemmanv(a,n);
							break;
						case 3:
							cout<<"Danh sach nhan vien co tien luong lon nhat va thap nhat : "<<endl;
							g<<"Danh sach nhan vien co tien luong lon nhat va thap nhat : "<<endl;
							maxmin(a,n);
							break;
						case 4:
							cout<<"Sau khi da sap xep : "<<endl;
							g<<"Sau khi da sap xep : "<<endl;
							sapxep(a,n);
							xuat(a,n);
						case 5:
							cout<<"Ket thuc"<<endl;
							break;
						default:
							cout<<"Muc ban lua chua khong ton tai! Xin lua chon lai memu :"<<endl;
							break;
					}
					}while(chon!=5);
				case 5:
					break;
				default:
					cout<<"Du lieu khong ton tai, xin hay chon 1 truoc khi thuc hien cac thao tac tiep theo!"<<endl;
					break;
			}
		}while(chon!=5);
	}
	k.close();
	g.close();
}
int main()
{
	int n;
	nhanvien a[50];
	menu(a,n);
	return 0;
}
