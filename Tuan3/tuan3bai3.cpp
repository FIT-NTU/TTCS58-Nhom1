#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
struct NhanVien
{
	string hoten;
	int MaNV, songaycong, tienluong;
};
#define DS_nhan_vien vector<NhanVien>
void Nhap_NV(NhanVien &NV)
{
	cout << "Nhap ma nhan vien: "; cin >> NV.MaNV;
	cout << "Nhap ho ten nhan vien: ";
	cin.ignore();
	getline(cin, NV.hoten);
	cout << "Nhap so ngay cong cua nhan vien: "; cin >> NV.songaycong;
}
void Xuat_NV(NhanVien &NV)
{
	NV.tienluong = NV.songaycong * 300000;
	cout << NV.MaNV << "\t" << NV.hoten << "\t\t" << NV.songaycong << "\t" << NV.tienluong << endl;
}
void Nhap_DS_NV(int &n, DS_nhan_vien &list)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien thu " << i + 1 << "." << endl;
		Nhap_NV(list[i]);
	}
}
void Doc_tu_file(ifstream &f, NhanVien &NV)
{
	f >> NV.MaNV;
	string temp;
	getline(f, temp);
	getline(f, NV.hoten);
	f >> NV.songaycong;
}
void Doc_DS_NV(ifstream &f, int &n, DS_nhan_vien &list)
{
	for (int i = 0; i < n; i++)
	{
		Doc_tu_file(f, list[i]);
	}
}
void Xuat_DS_NV(DS_nhan_vien &list)
{
	int n = list.size();
	for (int i = 0; i < n; i++)
	{
		Xuat_NV(list[i]);
	}
}

int Tim_nhan_vien_theo_ma(int ma, DS_nhan_vien list)
{
	int n = list.size();
	for (int i = 0; i < n; i++)
	{
		if (list[i].MaNV == ma)
		{
			return i;
		}
	}
	return -1;
}
void Tim_NV(DS_nhan_vien &list)
{
	cout << "Nhap ma nhan vien can tim: "; int manv;
	cin >> manv;
	int tam = Tim_nhan_vien_theo_ma(manv, list);
	if (tam != -1)
	{
		cout << "Thong tin nhan vien co ma " << manv << " la." << endl;
		cout << "MaNV\tHo ten\t\tSo ngay cong\tTien luong" << endl;
		Xuat_NV(list[tam]);
	}
	else
	{
		cout << "Khong tim thay nhan vien." << endl;
	}
}
void Them_NV(DS_nhan_vien &list)
{
	NhanVien NV;
	do
	{
		cout << "Nhap vao ma nhan vien, ma nhan vien phai khac voi cac nhan vien da co trong danh sach: ";
		cin >> NV.MaNV;
	} while (Tim_nhan_vien_theo_ma(NV.MaNV, list) != -1);//vong lap do while kiem tra xem ma nhan vien moi co bi trung voi ma nhan vien cu hay khong.
														 //nhap cac thong tin khac cua nhan vien
	cout << "Nhap ho ten nhan vien: "; cin.ignore();
	getline(cin, NV.hoten);
	cout << "Nhap so ngay cong cua nhan vien: ";
	cin >> NV.songaycong;
	list.push_back(NV);//them nhan vien vao cuoi vector
	cout << "Da them nhan vien." << endl;
}
void Xoa_NV(DS_nhan_vien &list)
{
	int manv;
	cout << "nhap vao ma nhan vien can xoa: ";
	cin >> manv;
	if (Tim_nhan_vien_theo_ma(manv, list) != -1)//dung ham kiem tra de kiem tra xem co ma nhan vien can xoa hay khong
	{
		list.erase(list.begin() + Tim_nhan_vien_theo_ma(manv, list));//neu co se tien hanh xoa nhan vien
		cout << "Da xoa nhan vien." << endl;
	}
	else
		cout << "Khong tim thay nhan vien." << endl;// thong bao neu khong tim thay
}
void Cap_nhat_NV(DS_nhan_vien &list)
{
	NhanVien NV;
	int manv;
	cout << "Nhap ma nhan vien can sua:";
	cin >> manv;
	//kiem tra xem nhan vien can sua co ton tai hay khong
	int temp = Tim_nhan_vien_theo_ma(manv, list);
	if (temp != -1)
	{
		cout << "Nhap vao thong tin can sua, Nhap vao 0 neu khong co thay doi." << endl;
		cout << "Nhap ho ten:"; cin.ignore();
		getline(cin, NV.hoten);
		cout << "Nhap so ngay cong: ";
		cin >> NV.songaycong;
		if (NV.hoten.compare("0") != 0)
			list[temp].hoten = NV.hoten;
		if (NV.songaycong != 0)
			list[temp].songaycong = NV.songaycong;
		cout << "Da sua thong tin nhan vien." << endl;
	}
	else
		cout << "Khong tim thay nhan vien!" << endl;
}
void Sap_xep_theo_so_ngay_cong(DS_nhan_vien &list)
{
	int n = list.size();
	for (int i = 0; i< n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (list[i].songaycong > list[j].songaycong)
				swap(list[i], list[j]);
		}
	}
}
void Menu()
{
	cout << "Cac chuc nang cua chuong trinh:" << endl;
	cout << "1: Nhap danh sach nhan vien." << endl;
	cout << "2: Them 1 nhan vien." << endl;
	cout << "3: Xoa 1 nhan vien theo ma nhan vien." << endl;
	cout << "4: Sua 1 nhan vien theo ma nhan vien." << endl;
	cout << "5: Tim kiem thong tin 1 nhan vien theo ma." << endl;
	cout << "6: In danh sach nhan vien." << endl;
	cout << "7: Su dung du lieu tu file." << endl;
	cout << "8: Thoat chuong trinh." << endl;
}
int Chonchucnang()
{
	int chon;
	cout << "Nhap chuc nang muon thuc hien: ";
	cin >> chon;
	if (chon > 0 && chon < 9)
		return chon;
	else return Chonchucnang();
}
void Xulychucnang(vector<NhanVien> &list)
{
	int n,k;
	ifstream f("input3.txt");
	
	Menu();
	int chucnang = Chonchucnang();
	switch (chucnang)
	{
	case 1:
		system("cls");
		do
		{
			cout << "Nhap vao so luong nhan vien: "; 
			cin >> k;
		} while (k < 0 || k>10);
		list.resize(k);
		Nhap_DS_NV(k, list);
		cout <<"Da nhap danh sach nhan vien."<<endl;
		system("pause");
		break;
	case 2:
		system("cls");
		Them_NV(list);
		system("pause");
		break;
	case 3:
		system("cls");
		Xoa_NV(list);
		system("pause");
		break;
	case 4:
		system("cls");
		Cap_nhat_NV(list);
		system("pause");
		break;
	case 5:
		system("cls");
		Tim_NV(list);
		system("pause");
		break;
	case 6:
		system("cls");
		cout <<"Danh sach nhan vien sap xep theo so ngay cong."<<endl;
		Sap_xep_theo_so_ngay_cong(list);
		Xuat_DS_NV(list);
		system("pause");
		break;
	case 7:
		system("cls");
		f >> n;
		list.resize(n);
		Doc_DS_NV(f,n,list);
		cout << "Da doc du lieu tu file input4.txt." << endl;
		system("pause");
		break;
	case 8:
		cout << "Cam on ban da su chung chuong trinh" << endl;
		exit(1);
		break;
	}
}
int main()
{
	DS_nhan_vien list;
	while (1)
	{
		system("cls");
		Xulychucnang(list);
	}
	system("pause");
}
