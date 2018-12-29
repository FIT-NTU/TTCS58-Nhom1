#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
struct NhanVien
{
	int MaNV;
	string Holot;
	string Ten;
	int Tienluong;
};
void Nhap(NhanVien &NV)
{
	cout << "Nhap ma nhan vien: "; cin >> NV.MaNV;
	cout << "Nhap ho lot nhan vien: ";
	cin.ignore();
	getline(cin, NV.Holot);
	cout << "Nhap ten nhan vien: "; getline(cin, NV.Ten);
	cout << "Nhap tien luong nhan vien: "; cin >> NV.Tienluong;
}
void XuatNhanVien(NhanVien &NV)
{
	cout <<NV.MaNV<<"\t"<<NV.Holot<<"\t"<<NV.Ten<<"\t"<<NV.Tienluong<<endl;
}
void NhapDSNhanVien(int &n, NhanVien NV[])
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien thu " << i + 1 << "." << endl;
		Nhap(NV[i]);
	}
}
void Docfile(ifstream &f, NhanVien &NV)
{
	f >> NV.MaNV;
	string temp;
	getline(f, temp);
	getline(f, NV.Holot);
	getline(f, NV.Ten);
	f >> NV.Tienluong;
}
void Ghifile(ofstream &f, NhanVien &NV)
{
	f<<"________________________________________________________________________________"<<endl;
	f << "|"<<NV.MaNV <<"\t|"<< NV.Holot << "\t|"<< NV.Ten << "\t|"<< NV.Tienluong<<"|" << endl;
}
void DocDS(ifstream &f, int &n, NhanVien NV[])
{
	for (int i = 0; i < n; i++)
	{
		Docfile(f, NV[i]);
	}
}
void XuatDS(int n, NhanVien NV[])
{
	for (int i = 0; i < n; i++)
	{
		XuatNhanVien(NV[i]);
	}
}

int TimNhanVien(int ma, NhanVien NV[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ma == NV[i].MaNV)
		{
			return i;
		}
		else return -1;
	}
}
int Min(int n, NhanVien NV[])
{
	int min = NV[0].Tienluong;
	for (int i = 1; i < n; i++)
	{
		if (NV[i].Tienluong < min)
		{
			min = NV[i].Tienluong;
		}
	}
	return min;
}
int Max(int n, NhanVien NV[])
{
	int max = NV[0].Tienluong;
	for (int i = 1; i < n; i++)
	{
		if (NV[i].Tienluong > max)
		{
			max = NV[i].Tienluong;
		}
	}
	return max;
}
int LuongLonNhat(NhanVien NV[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (NV[i].Tienluong == Max(n, NV))
			dem++;
	}
	return dem;
}
int LuongNhoNhat(NhanVien NV[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (NV[i].Tienluong == Min(n, NV))
			dem ++;
	}
	return dem;
}
void DuyetNhanVien(NhanVien NV[], int a[], int b[], int n)
{
	int dem = 0;
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (NV[i].Tienluong == Max(n, NV))
		{
			a[dem] = i;
			dem++;
		}
	}
	for(int i = 0; i< n; i++)
	{
			if (NV[i].Tienluong == Min(n, NV))
		{
			b[dem1] = i;
			dem1++;
		}
	}
}
void SoSanhTen(NhanVien NV[], int n)
{
	for (int i = 0; i< n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (NV[i].Ten.compare(NV[j].Ten) == 1)
				swap(NV[i], NV[j]);
			else if (NV[i].Ten.compare(NV[j].Ten) == 0)
			{
				if (NV[i].Holot.compare(NV[j].Holot) == 1)
					swap(NV[i], NV[j]);
			}
	}
}
void GhiKQVaoFile( NhanVien NV[],int a[], int b[], int &n, int &x)
{
	ofstream f("output3.txt");
	if (TimNhanVien(x,NV,n) !=-1)
	{
		Ghifile(f, NV[TimNhanVien(x, NV, n)]);
		f << endl;
	}
	else
	{
		string s = "Khong tim thay nhan vien.";
		f <<s<< endl;
	}
	f << "Danh sach ho ten nhan vien co luong lon nhat." << endl;
	f<<"Ho va ten: "<<endl;
	for (int i = 0; i < n; i++)
	{
		if (NV[i].Tienluong == Max(n,NV))
		{
			f << NV[i].Holot << " " << NV[i].Ten << endl;
		}
	}
	f << "Danh sach ho ten nhan vien co luong nho nhat." << endl;
	f<<"Ho va ten: "<<endl;
	for (int i = 0; i < n; i++)
	{
		if (NV[i].Tienluong == Min(n, NV))
		{
			f << NV[i].Holot << " " << NV[i].Ten << endl;
		}
	}
	SoSanhTen(NV, n);
	f << "Danh sach nhan vien sau khi sap xep." << endl;
	f <<"MaNV\tHolot\tTen\tTienluong"<<endl;
	for (int  i = 0; i < n; i++)
	{
		Ghifile(f,NV[i]);
	}
}
void Menu()
{
	cout << "Cac chuc nang cua chuong trinh." << endl;
	cout << "1: Kiem tra so luong nhan vien trong file." << endl;
	cout << "2: Tim kiem nhan vien theo ma nhan vien." << endl;
	cout << "3: Danh sach ho ten nhan vien co luong cao nhat va thap nhat." << endl;
	cout << "4: Danh sach nhan vien sap xep theo ten." << endl;
	cout << "5: Ghi tat ca ket qua thuc hien duoc vao file." << endl;
	cout << "6: Thoat." << endl;
}
int ChonChucNang()
{
	int chon;
	cout << "Moi chon chuc nang muon thuc hien: ";
	cin >> chon;
	if (chon > 0 && chon < 7) return chon;
	else return ChonChucNang();
}
void Author()
{
	cout << "Thuc tap co so tuan 1, bai 1." << endl;
	cout << "Sinh vien thuc hien: Nguyen Tuan Anh." << endl;
	cout << "Giang vien huong dan: Bui Thi Hong Minh." << endl;
}
void XuLyMenu()
{
	ifstream f("input3.txt");
	int n,x;
	f >> n;
	NhanVien *NV = new NhanVien[n];
	DocDS(f, n, NV);
	int Lmin = LuongNhoNhat(NV, n);
	int Lmax = LuongLonNhat(NV, n);
	int a[50];
	int b[50];
	DuyetNhanVien(NV, a, b, n);
	int chucnang = ChonChucNang();
	switch (chucnang)
	{
	case 1:
	{
		cout << "-----------oOo-----------" << endl;
		if(n <= 50)
		cout << "So luong nhan vien trong file la: " << n << endl;
		else
		{
			cout <<"So luong nhan vien vuot qua dieu kien.vui long kiem tra lai.";
			exit(1);
		}
		break;
	}
	case 2:
	{
		
		cout << "-----------oOo-----------" << endl;
		cout << "Nhap ma nhan vien can tim: ";
		cin >> x;
		if (TimNhanVien(x,NV,n)!=-1)
		{
			XuatNhanVien(NV[TimNhanVien(x, NV, n)]);
		}
		else cout << "Khong tim thay nhan vien co ma nhan vien " << x << endl;
		break;
	}
	case 3:
	{
		cout << "-----------oOo-----------" << endl;
		cout << "Danh sach nhan vien co luong lon nhat la: " << endl;
		for (int  i = 0; i < Lmax; i++)
		{
			cout << "Ho ten nhan vien: " << NV[a[i]].Holot << " " << NV[a[i]].Ten << endl;
			
		}
		cout << "Danh sach nhan vien co luong nho nhat la: " << endl;
		for (int i = 0; i < Lmin; i++)
		{
			
			cout << "Ho ten nhan vien: " << NV[b[i]].Holot << " " << NV[b[i]].Ten << endl;
		}
		break;
	}
	case 4:
	{
		cout << "-----------oOo-----------" << endl;
		cout << "Danh sach nhan vien sau khi sap xep la: "<<endl;
		cout <<"MaNV\tHolot\tTen\tTienluong"<<endl;
		SoSanhTen(NV, n);
		XuatDS(n, NV);
		break;
	}
	case 5:
	{
		cout << "-----------oOo-----------" << endl;
		cout << "Tat ca ket qua da duoc ghi vao file output1.txt." << endl;
		GhiKQVaoFile(NV,a,b,n,x);
		break;
	}
	case 6:
	{
		cout << "-----------oOo-----------" << endl;
		cout << "Cam on vi da su dung chuong trinh." << endl;
		cout << "-----------oOo-----------" << endl;
		exit(1);
		break;
	}
	}
}
int main()
{
	Author();
	Menu();
	while(1)
	{
		XuLyMenu();
	}
	system("pause");
}
