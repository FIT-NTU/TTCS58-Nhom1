#include<iostream>
#include<string>
#include<fstream>
using namespace std;
fstream f;

void NhapChuoi(string &s)
{
	f.open("input1.txt", ios::in || ios::out);
	f << s << endl;
}
void Xoa(string &s, int &n,int x)
{
	for (int i = x; i < n; i++)
	{
		s[i] = s[i + 1];
	}
	n--;
}
void XoaKhoangTrang(string &s)
{
	int n = s.length();
	while (s[0] == ' ')
	{
		Xoa(s, n, 0);
	}
	while (s[n - 1] == ' ' && s[n] == '\0')
	{
		Xoa(s, n, 0);
	}
	for (int i = 0; i < n; i++)
	{
		while (s[i] == ' ' && s[i + 1] == ' ')
		{
			Xoa(s, n, i);
			i--;
		}
	}
	cout << "Chuoi sau khi xoa cac khoang trang du thua la: " << s << endl;
}
void ChuanHoaChuoi(string &s) 
{
	if (s[0] > 90)
	{
		s[0] = s[0] - 32;
	}
	for (int i = 0; i < s.length()-1; i++)
	{
		if (s[i]== 32 && s[i+1] > 90)
		{
			s[i + 1] = s[i + 1] - 32;
		}
	}
	cout << "Chuoi sau khi chuan hoa la: " << s << endl;
}
void ThongKeKyTu(string s)
{
	int dem = 0,sum;
	int n = s.length();
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == 32)
		{
			dem++;
		}
	}
	sum = n - dem;
	cout << "So ky tu chu cai trong chuoi la: " << sum << endl;
}
void Menu()
{
	cout <<"Cac chuc nang cua chuong trinh:"<<endl;
	cout <<"1: Luu chuoi vua nhap vao file input1.txt.";
	cout <<"2: Xoa cac khoang trang du thua trong chuoi vua nhap.";
	cout <<"3: "
}
int main()
{
	string s;
	int chon;
	cout << "Nhap vao chuoi ban dau: ";
	getline(cin, s);
	cin.ignore();
	cout << "Chon ham: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
		NhapChuoi(s);
		break;
	case 2:
		ChuanHoaChuoi(s);
		break;
	case 3:
		XoaKhoangTrang(s);
		break;
	case 4:
		ThongKeKyTu(s);
		break;
	case 5:
		break;
	}
	return 0;
}
