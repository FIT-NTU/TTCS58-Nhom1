//8h sang mai nop
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

struct NHANVIEN
{	
	int maNV;
	char ho[15]; //gom ho va ten lot
	char ten[15];
	float luong;
};
typedef struct NHANVIEN nhanvien; //dinh nghia cau truc

ifstream f;
ofstream a("input3.txt");
ofstream k("output3.txt");

//doc file
void doc(nhanvien nv[], int n)
{
	f.open("input.txt", ios::in);
	if(f.fail())
	{
		cout<<"Khong the mo file";
	}else
	for(int i=0;i<n;i++)
	{
		f>>n;
		f>>nv[i].maNV;
		f>>nv[i].ho;
		f>>nv[i].ten;
		f>>nv[i].luong;
	}
	f.close();
}
void nhap(nhanvien nv[], int n)
{
	for(int i=0;i<n;i++)
	{
	cout<<"Nhan vien thu "<<i+1<<":"<<endl;
	cout<<"Nhap ma so nhan vien:"<<endl;
	cin>>nv[i].maNV;
	fflush(stdin); //xoa bo nho dem
	cout<<"Nhap ho nhan vien:"<<endl; //ho va ten lot
	cin.getline(nv[i].ho, 15);
	fflush(stdin); 
	cout<<"Nhap ten nhan vien:"<<endl;
	cin.getline(nv[i].ten, 15);
	cout<<"Nhap luong nhan vien:"<<endl;
	cin>>nv[i].luong;
	}
}

void ghi1(nhanvien nv[], int n)
{
	a<<"STT"<<"\t"<<"Ma nhan vien"<<"\t"<<"Ho"<<"\t\t"<<"Ten"<<"\t"<<"Luong nhan vien"<<endl;
	for(int i=0;i<n;i++)
	a<<i+1<<"\t"<<nv[i].maNV<<"\t\t"<<nv[i].ho<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].luong<<endl;
}

void xuat(nhanvien nv[], int n)
{
	cout<<"STT"<<"\t"<<"Ma nhan vien"<<"\t"<<"Ho"<<"\t\t"<<"Ten"<<"\t"<<"Luong nhan vien"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<nv[i].maNV<<"\t\t"<<nv[i].ho<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].luong<<endl;
	}
	ghi1(nv, n);
}

void ghi2(nhanvien nv[], int n)
{
	k<<"STT"<<"\t"<<"Ma nhan vien"<<"\t"<<"Ho"<<"\t\t"<<"Ten"<<"\t"<<"Luong nhan vien"<<endl;
	for(int i=0;i<n;i++)
	k<<i+1<<"\t"<<nv[i].maNV<<"\t\t"<<nv[i].ho<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].luong<<endl;
}
void timMSNV(nhanvien nv[],int n)
{
	int x;
	cout<<"Nhap ma nhan vien can tim:"<<endl;
	cin>>x;
	for(int i=0;i<n;i++)
	{
		if(nv[i].maNV==x)
		{
			cout<<"STT"<<"\t"<<"Ma nhan vien"<<"\t"<<"Ho"<<"\t\t"<<"Ten"<<"\t"<<"Luong nhan vien"<<endl;
			cout<<i+1<<"\t"<<nv[i].maNV<<"\t\t"<<nv[i].ho<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].luong<<endl;
			k<<"-----------Thong tin nhan vien------------"<<endl;
			k<<"STT"<<"\t"<<"Ma nhan vien"<<"\t"<<"Ho"<<"\t\t"<<"Ten"<<"\t"<<"Luong nhan vien"<<endl;
			k<<i+1<<"\t"<<nv[i].maNV<<"\t\t"<<nv[i].ho<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].luong<<endl;
		}	
		else
		{	
			cout<<"Khong tim thay nhan vien co ma tren!"<<endl;
			k<<"Khong tim thay nhan vien co ma tren!"<<endl;
		}
	}
}	
void timluong(nhanvien nv[], int n)
{
	double max = nv[0].luong, min = nv[0].luong;
	for (int i = 1; i < n; i++) 
	{
		if(max < nv[i].luong) 
			max = nv[i].luong;
		if(min > nv[i].luong) 
			min = nv[i].luong;
	}
	int j = 0;
	cout << "Luong cao nhat la:" << endl;
	for (int i = 0; i < n; i++) 
	{
		if (nv[i].luong == max) {

			cout<<nv[i].ho<<" "<<nv[i].ten<<endl;
			j++;
			k<<"-----------Nhan vien co luong cao nhat------------"<<endl;
			k<<nv[i].ho<<" "<<nv[i].ten<<endl;
		}
	}
	j = 0;
	cout << "Luong thap nhat la:" << endl;
	for (int i = 0; i < n; i++) 
	{
		if (nv[i].luong == min) 
		{
			cout<<nv[i].ho<<" "<<nv[i].ten<<endl;
			j++;
			k<<"-----------Nhan vien co luong thap nhat------------"<<endl;
			k<<nv[i].ho<<" "<<nv[i].ten<<endl;
		}
	}
}
void sapxep(nhanvien nv[],int n)
{
	cout<<"STT"<<"\t"<<"Ma nhan vien"<<"\t"<<"Ho"<<"\t\t"<<"Ten"<<"\t"<<"Luong nhan vien"<<endl;
	for(int i=0;i<n;i++)
	{  	for(int j=i+1;j<n;j++)
			if( strcmp(nv[i].ten, nv[j].ten)> 0) //dung ham strcmp de so sanh 2 chuoi
			{
				swap(nv[i], nv[j]);
			}	
			else if(strcmp(nv[i].ten, nv[j].ten)== 0)
			{
				if(strcmp(nv[i].ho, nv[j].ho)> 0)
				{
					swap(nv[i], nv[j]);
				}
			}
		cout<<i+1<<"\t"<<nv[i].maNV<<"\t\t"<<nv[i].ho<<"\t\t"<<nv[i].ten<<"\t\t"<<nv[i].luong<<endl;
	}  
 	ghi2(nv, n); 
}
void menu(nhanvien nv[], int n)
{
	int k; //bien lua chon
	do
	{
		cout<<"\n______________PHAN MEM QUAN LY NHAN VIEN______________"<<endl;
		cout<<"0.Thoat."<<endl;
		cout<<"1.Doc thong tin nhan vien tu file  input3.txt"<<endl;
		cout<<"2.Nhap thong tin nhan vien va ghi vao file"<<endl;
		cout<<"3.Nhap ma nhan vien va cho biet thong tin nhan vien do"<<endl;
		cout<<"4.Cho biet ho ten nhan vien co luong cao nhat va thap nhat"<<endl;
		cout<<"5.Sap xep nhan vien tang dan theo ten, neu cung ten thi xep theo ho"<<endl;
		cout<<"Ban chon chuc nang so:"<<endl;
		cin>> k;
		switch( k )
		{
			case 0: break;
			case 1:
				doc(nv, n);
				break;
			case 2:
				do
				{
					cout<<"Nhap so luong nhan vien : ";
					cin>>n;
				}while(n>50);
				nhap(nv, n);
				xuat(nv, n);
				break;
			
			case 3:
				timMSNV(nv, n);
				break;
			
			case 4:
				timluong(nv, n);
				break;
			
			case 5:
				sapxep(nv, n);
				break;		
			default:
				cout<< "\nNhap lai!";
				break;
		}
	}while(k!=0); //neu =0 se ket thuc
}
int main()
{
	nhanvien nv[50];
	int n;
	menu(nv, n);
	system("pause");
}



