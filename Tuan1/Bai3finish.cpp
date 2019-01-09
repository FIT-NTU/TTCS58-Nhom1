#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include"console.cpp"
#include"console.h"
#include<ctime>
#include <cstdlib>
#define dau 30
#define cuoi 5
#define MAX 6
typedef char menu[100];
menu submenu[6] =
{
	"1: Kiem tra so luong nhan vien trong file.",
	"2: Tim kiem nhan vien theo ma nhan vien.",
	"3: Danh sach ho ten nhan vien co luong cao nhat va thap nhat.",
	"4: Danh sach nhan vien sap xep theo ten.",
	"5: Ghi tat ca ket qua thuc hien duoc vao file.",
	"6: Thoat."
};
using namespace std;
struct NhanVien
{
	int MaNV;
	string Holot;
	string Ten;
	int Tienluong;
};
void Author()
{
	TextColor(4);
	gotoXY(30, 0);
	cout << "__________________________________________" << endl;
	gotoXY(30, 1);
	cout << "|     Thuc tap co so tuan 1, bai 3.      |" << endl;
	gotoXY(30, 2);
	cout << "|Sinh vien thuc hien: Nguyen Tuan Anh.   |" << endl;
	gotoXY(30, 3);
	cout << "|Giang vien huong dan: Bui Chi Thanh.    |" << endl;
	gotoXY(30, 4);
	cout << "------------------------------------------" << endl;
}
void Nhap(NhanVien &NV)
{
	cout << "Nhap ma nhan vien: "; cin >> NV.MaNV;
	cout << "Nhap ho lot nhan vien: ";
	cin.ignore();
	getline(cin, NV.Holot);
	cout << "Nhap ten nhan vien: "; getline(cin, NV.Ten);
	cout << "Nhap tien luong nhan vien: "; cin >> NV.Tienluong;
}
void XuatNhanVien(NhanVien &NV, int x, int y)
{
	gotoXY(x + 1, y);
	cout << NV.MaNV;
	gotoXY(x + 17, y);
	cout << NV.Holot;
	gotoXY(x + 33, y);
	cout << NV.Ten;
	gotoXY(x + 49, y);
	cout << NV.Tienluong << endl;
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

	f << "|" << NV.MaNV << "\t|" << NV.Holot << "\t|" << NV.Ten << "\t|" << NV.Tienluong << "|" << endl;
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
		XuatNhanVien(NV[i], dau, i + 3);
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
			dem++;
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
	for (int i = 0; i< n; i++)
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
void GhiKQVaoFile(NhanVien NV[], int a[], int b[], int &n, int &x)
{
	ofstream f("output3.txt");
	if (TimNhanVien(x, NV, n) != -1)
	{
		Ghifile(f, NV[TimNhanVien(x, NV, n)]);
		f << endl;
	}
	else
	{
		string s = "Khong tim thay nhan vien.";
		f << s << endl;
	}
	f << "Danh sach ho ten nhan vien co luong lon nhat." << endl;
	f << "Ho va ten: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (NV[i].Tienluong == Max(n, NV))
		{
			f << NV[i].Holot << " " << NV[i].Ten << endl;
		}
	}
	f << "Danh sach ho ten nhan vien co luong nho nhat." << endl;
	f << "Ho va ten: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (NV[i].Tienluong == Min(n, NV))
		{
			f << NV[i].Holot << " " << NV[i].Ten << endl;
		}
	}
	SoSanhTen(NV, n);
	f << "Danh sach nhan vien sau khi sap xep." << endl;
	f << "STT\tMaNV\tHolot\t\tTen\tTienluong" << endl;
	for (int i = 0; i < n; i++)
	{
		f << "-------------------------------------------" << endl;
		f << "|" << i + 1 << "\t";
		Ghifile(f, NV[i]);
	}
}
void InMenu(int vitri)
{
	system("cls");
	Author();
	int i;
	gotoXY(dau + 8, cuoi); TextColor(6);
	cout << "Cac chuc nang cua chuong trinh." << endl;
	gotoXY(dau + 12, cuoi + 1); TextColor(6);
	printf("==========oOo==========");
	for (i = 1; i <= MAX; i++)
	{
		if (i == vitri) TextColor(2);
		else TextColor(7);
		gotoXY(dau - 1, cuoi + 1 + i);
		cout << submenu[i - 1];
	}
}
void XuLyMenu(int vitri)
{
	ifstream f("input3.txt");
	int n, x;
	f >> n;
	NhanVien *NV = new NhanVien[n];
	DocDS(f, n, NV);
	int Lmin = LuongNhoNhat(NV, n);
	int Lmax = LuongLonNhat(NV, n);
	int a[50];
	int b[50];
	DuyetNhanVien(NV, a, b, n);
	char c;
	do
	{
		InMenu(vitri);
		gotoXY(80, 25);
		c = getch();
		switch (c)
		{
		case 72: vitri--; if (vitri == 0) vitri = 6; break;
		case 80: vitri++; if (vitri == 7) vitri = 1; break;
		case 27: exit(0);
		}
	} while (c != 13);
	switch (vitri)
	{
	case 1:
	{
		system("cls");
		gotoXY(dau, 0);
		if (n <= 50)
			cout << "So luong nhan vien trong file la: " << n << endl;
		else
		{
			cout << "So luong nhan vien vuot qua dieu kien.vui long kiem tra lai.";
			exit(1);
		}
		system("pause");
		XuLyMenu(vitri);
		break;
	}
	case 2:
	{
		system("cls");
		gotoXY(dau, 0);
		cout << "Nhap ma nhan vien can tim: ";
		cin >> x;
		if (TimNhanVien(x, NV, n) != -1)
		{
			gotoXY(dau + 2, 1);
			cout << "Ma nhan vien";
			gotoXY(dau + 18, 1);
			cout << "Ho lot";
			gotoXY(dau + 34, 1);
			cout << "Ten";
			gotoXY(dau + 50, 1);
			cout << "Tien luong" << endl;
			XuatNhanVien(NV[TimNhanVien(x, NV, n)], dau + 1, 2);
		}
		else
		{
			gotoXY(dau, 0);
			cout << "Khong tim thay nhan vien co ma nhan vien " << x << endl;
		}
		system("pause");
		XuLyMenu(vitri);
		cout << endl;
		break;
	}
	case 3:
	{
		system("cls");
		gotoXY(dau, 0);
		cout << "Danh sach nhan vien co luong lon nhat la: " << endl;
		for (int i = 0; i < Lmax; i++)
		{
			gotoXY(dau, i + 1);
			cout << "Ho ten nhan vien: " << NV[a[i]].Holot << " " << NV[a[i]].Ten << endl;

		}
		gotoXY(dau, Lmax + 2);
		cout << "Danh sach nhan vien co luong nho nhat la: " << endl;
		for (int i = 0; i < Lmin; i++)
		{
			gotoXY(dau, Lmax + i + 3);
			cout << "Ho ten nhan vien: " << NV[b[i]].Holot << " " << NV[b[i]].Ten << endl;
		}
		system("pause");
		XuLyMenu(vitri);
		break;
	}
	case 4:
	{
		system("cls");
		gotoXY(dau, 0);
		cout << "Danh sach nhan vien sau khi sap xep la: " << endl;
		gotoXY(dau + 1, 2);
		cout << "Ma nhan vien";
		gotoXY(dau + 17, 2);
		cout << "Ho lot";
		gotoXY(dau + 33, 2);
		cout << "Ten";
		gotoXY(dau + 49, 2);
		cout << "Tien luong" << endl;
		SoSanhTen(NV, n);
		XuatDS(n, NV);
		system("pause");
		XuLyMenu(vitri);
		break;
	}
	case 5:
	{
		system("cls");
		gotoXY(dau, 0);
		cout << "Tat ca ket qua da duoc ghi vao file output3.txt." << endl;
		GhiKQVaoFile(NV, a, b, n, x);
		system("pause");
		XuLyMenu(vitri);
		break;
	}
	case 6:
	{
		system("cls");
		TextColor(9);
		gotoXY(dau + 4, 0);
		cout << "-----------oOo-----------" << endl;
		gotoXY(dau, 1);
		cout << "Cam on vi da su dung chuong trinh." << endl;
		gotoXY(dau + 4, 2);
		cout << "-----------oOo-----------" << endl;
		TextColor(7);
		exit(1);
		XuLyMenu(vitri);
		break;
	}
	}
}
int main()
{
	XuLyMenu(1);
	system("pause");
}
