#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<string>
#include<time.h>
using namespace std;
string XoaKhoangTrang(string &s)
{
	int i;
	//xoa cac ky tu trang nam o dau chuoi
	while (s[0]==' ')
	{
		s.erase(s.begin()+0);
	}
	// Xoa cac ky tu trang o cuoi chuoi
	while (s[s.length() - 1]==' ')
	{
		s.erase(s.begin() + s.length() - 1);
	}
	//Xoa cac ky tu trang nam o giua chuoi
	for (i = 0; i < s.length(); i++)
	{
		while (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(s.begin()+i);
			i--;
		}
	}
	return s;
}
string ChuanHoaProper(string &s)
{
	//neu ky tu dau tien chua viet hoa thi chuyen no thanh ky tu viet hoa
	if (s[0] > 96)
	{
		s[0] = s[0] - 32;
	}

	for (int i = 1; i < s.length(); i++)
	{
		//neu la dau khoang trong thi khong doi
		if (s[i]==32)
		{
			s[i] = s[i];
		}
		//neu la ky tu viet thuong ma truoc do la dau khoang trong thi doi thanh ky tu viet hoa
		else if (s[i] > 96 && s[i-1] == 32)
		{
			s[i] = s[i] - 32;
		}
		//neu la ky tu viet hoa ma truoc do khong phai khoang trong thi doi lai thanh ky tu thuong
		else if (s[i] < 96 && s[i-1]!=32)
		{
			s[i] = s[i] + 32;
		}
		//cac ky tu con lai giu nguyen.
		else s[i] = s[i];
	}
	return s;
}
int ThongKeKyTu(string &s)
{
	int dem = 0;
	//duyet tu dau den cuoi chuoi. neu khong phai khoang trang thi dem +1
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != 32)
			dem++;
	}
	return dem;
}
void GhiKetQuaVaoFile(string &s)
{
	//ghi ket qua thuc hien cac ham vao file
	ofstream f("ouput1.txt");
	f << "Chuoi sau khi xoa cac khoang trang:/" << XoaKhoangTrang(s) << "/" << endl;
	f <<"Chuoi sau khi chuan hoa:/"<< ChuanHoaProper(s)<<"/"<<endl;
	f << "So ky tu: " << ThongKeKyTu(s);
}
void GhiChuoiNhapVaoFile(string &s)
{
	//ghi chuoi vua nhap vaofile
	ofstream f("input1.txt");
	f << "chuoi vua nhap: /" << s << "/";
}
void Menu()
{
	cout << "Cac chuc nang cua chuong trinh: " << endl;
	cout << "1: Ghi chuoi vao file input1.txt." << endl;
	cout << "2: Xoa cac khoang trang du thua." << endl;
	cout << "3: Chuan hoa chuoi dang proper." << endl;
	cout << "4: Thong ke cac ky tu chu cai trong chuoi." << endl;
	cout << "5: Ghi tat ca ket qua vao file." << endl;
	cout << "6:Thoat." << endl;
}
int ChonChucNang()
{
	int chon;
	cout<< "-----------oOo-----------" << endl;
	cout << "Nhap chuc nang muon thuc hien: ";
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
void XuLyMenu(string &s,string &temp)
{

	int chucnang = ChonChucNang();
	switch (chucnang)
	{
	case 1:
	{
		cout<< "-----------oOo-----------" << endl;
		cout << "Chuoi vua nhap da duoc ghi vao file input.txt" << endl;
		GhiChuoiNhapVaoFile(temp);
		break;
	}
	case 2:
	{
		cout<< "-----------oOo-----------" << endl;
		cout << "Chuoi sau khi xoa cac khoang trong du thua: " << XoaKhoangTrang(s) << endl;
		break;
	}
	case 3:
	{
		cout<< "-----------oOo-----------" << endl;
		cout << "Chuoi sau khi chuan hoa proper: " << ChuanHoaProper(s) << endl;
		break;
	}
	case 4:
	{
		cout<< "-----------oOo-----------" << endl;
		cout << "So ky tu chu cai trong chuoi la: " << ThongKeKyTu(s) << endl;
		break;
	}
	case 5:
	{
		cout<< "-----------oOo-----------" << endl;
		cout << "Tat ca ket qua da duoc ghi vao file output1.txt." << endl;
		GhiKetQuaVaoFile(temp);
		break;
	}
	case 6:
	{
		cout<< "-----------oOo-----------" << endl;
		cout << "Cam on vi da su dung chuong trinh." << endl;
		cout<< "-----------oOo-----------" << endl;
		system("pause");
		exit(1);
		break;
	}
	}
}
int main()
{
	string s,temp;
	Author();
	cout << "-----------oOo-----------" << endl;
	cout << "Nhap vao 1 chuoi: ";	
	getline(cin, s);
	temp = s;
	cout<< "-----------oOo-----------" << endl;
	Menu();
	while(1)
	{
		XuLyMenu(s,temp);
	}
	system("pause");
}
