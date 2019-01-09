#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>


using namespace std;
typedef struct nhanvien NhanVien;
struct nhanvien
{
	int manv;
	string hl;
	string tennv;
	int tl;	
};
nhanvien e[50];

//nhap thong tin nv
void nhapttnv(nhanvien &e)
{
	int n;
	for (int i=0; i<n; i++)
	{
	cout<<"\nNhap ma nhan vien:"<<endl;
	cin>>e.manv;
	fflush(stdin); //xoa bo dem
	cout<<"\nNhap ho lot nhan vien:"<<endl;
	getline(cin, e.hl);
	cout<<"\nNhap ten nhan vien:"<<endl;
	getline(cin, e.tennv);
	fflush(stdin); //xoa bo dem
	cout<<"\nNhap tien luong nhan vien:"<<endl;
	cin>>e.tl;
	}
}

//xuat thong tin nhan vien
void xuatttnv(nhanvien e)
{
	cout<<"\nMa nv: "<<e.manv;
	cout<<"\nHo lot nv: "<<e.hl;
	cout<<"\nTen nv:"<<e.hl;
	cout<<"\nTien luong nv: "<<e.tl;	
	
}

//tim thong tin nhan vien theo ma so nhan vien
void timnv(nhanvien e)
{
	int maso;
	while(2)
	{
		cout<<"Nhap ma so nv can tim: ";
		cin>>maso;
		if(maso==e.manv);
		{
			cout<<"\nTHONG TIN NHAN VIEN\n";
			cout<<"Ho lot: "<<e.hl<<endl;
			cout<<"Ten: "<<e.tennv<<endl;
			cout<<"Tien luong: "<<e.tl<<endl;
			
		}
		if (maso!=e.manv)
		{
			system("cls");
			cout<<"Khong tim thay nv trong du lieu"<<endl;
			break;
		}
	}
}

//tim luong nhan vien cao nhat, thap nhat
void timl(nhanvien nv[] )
{
	int n;
	int index_max = 0, index_min = 0;
	int max = nv[0].tl;
	int min = nv[0].tl;
	
	for(int i = 1; i < n; i++ )
	{
		if( max < nv[i].tl )  
		{
			index_max = i;
			max = nv[index_max].tl;
		}
	}
	cout << "Nguoi co luong cao nhat la: " << nv[index_max].hl << " " << nv[index_max].tennv << endl;

	for(int i = 1; i < n; i++)
	{
		if( min > nv[i].tl)
		{
			index_min = i;
			min = nv[index_min].tl;
		}
	}
	cout << "Nguoi co luong thap nhat la: " << nv[index_min].hl << " " << nv[index_min].tennv << endl;
}

void sapxep (nhanvien nv[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j=i+1; j < n; j++)
		{
			if((nv[i].tennv.compare(nv[j].tennv))>0)
			{ 
				swap(nv[i],nv[j]);
			} else if((nv[i].tennv.compare(nv[j].tennv))==0)
			{
				if((nv[i].hl.compare(nv[j].hl))>0)
				{
					swap(nv[i],nv[j]);
				}
			}
		}
	}
	xuatttnv;	
}


void infile (nhanvien e)
{
	ofstream a ("input3.txt",ios::app);
	a<<e.manv<<endl;
	a<<e.hl<<endl;
	a<<e.tennv<<endl;
	a<<e.tl<<endl;
	a.close();
}

void docfile(nhanvien e[])
  {
	int n;
	ifstream a;
	a.open("input3.txt", ios::in);
	int i=0;
	if (a.is_open()) {
		
		while (!a.eof()) 
		{
			
			a >> e[i].manv;
			a >> e[i].hl;
			a >> e[i].tennv;
			a >> e[i].tl;
			i++;
		}
	}
	a.close();

}

	


int main()
{	
	nhanvien a[50];
	int nhap;
	while (1)
	{
	//nhap du lieu nv
	cout<<"\nNhan 1 de nhap thong tin nv. Nhan 2 de bo qua neu da co du lieu: ";
	cin>>nhap;
		if (nhap==2)
	{
		docfile(e);
		break;
	}
	if (nhap==1)
	system("cls");//xoa mang hinh
	nhanvien a,b,c;
	cout<<"\n\n\t\tNHAP THONG TIN NHAN VIEN\n"<<endl;
	nhapttnv(a);
	nhapttnv(b);
	nhapttnv(c);
	
	
	cout<<"\nNHAN VIEN\n"<<endl;

	xuatttnv(a);
	xuatttnv(b);
	xuatttnv(c);
	//
	infile(a);
	infile(b);
	infile(c);
	break;
	}
	

	//tao memu
	int luachon;
	while (1)
	{
	cout << "\n\n\t\t-------------MENU-------------\n" << endl;
	cout << "\n1. Tim thong tin nhan vien" << endl;
	cout << "\n2. Xem muc luong nhan vien" << endl;
	cout << "\n3. Sap xep nhan vien" << endl;
	cout << "\n4. Ghi tat ca ket qua vao file text" << endl;
	cout << "\n5. Ket thuc" << endl;
	cout << "\n\n\t\t-------------END--------------\n";
	cout << "\nNhap lua chon: " << endl;
	cin >> luachon;
	
	if (luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon!=5)
	{
		cout <<"\nLua chon khong hop le !";
		system("pause");
	}
	
	else if(luachon == 1) //tim ttnv
	{
	system("cls");//xoa mang hinh		
	nhanvien x;
	timnv(x);

	}
		
	else if (luachon == 2) //xem muc luong nv
	{
		system("cls");//xoa mang hinh
	
		
	}
		
	else if (luachon == 3) //sap xep nv
	{
		system("cls");//xoa mang hinh
		
	}
	else if (luachon == 4) //ghi tat ca vao file
		{
			system("cls");//xoa mang hinh
			
		}
		
	else if(luachon==5) //ket thuc
		{
			break;
		}
	}
	return 0;	
}
