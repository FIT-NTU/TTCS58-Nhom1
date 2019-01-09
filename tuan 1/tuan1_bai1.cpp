#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string s, a, b, c;

void showMenu();
void chon();
void nhapChuoi();
void ghiFile(string s);
void xoaKhoangTrang();
void proper(string s);
void dem();
void output();

int main()
{
	showMenu();
	chon();
	cout << s << endl;
	system("pause");
}


void showMenu()
{	
	cout << "1. Nhap vao mot chuoi va ghi vao tap tin: " << endl;
	cout << "2. Bo cac khoang trang thua: " << endl;
	cout << "3. Chuan hoa chuoi dang Proper: " << endl;
	cout << "4. Thong ke so luong cac ki tu chu cai: " << endl;
	cout << "5. Ghi tat ca ket qua thuc hien duoc vao tap tin: " << endl<<endl;
}

void chon()
{
	int select;
	cout << "Lua chon cua ban la: ";
	cin >> select;
	switch (select)
	{
		case 1:
			nhapChuoi();
			chon();
			break;
		case 2:
			xoaKhoangTrang();
			chon();
			break;
		case 3:
			proper(s);
			chon();
			break;
		case 4:
			dem();
			chon();
			break;
		case 5:
			output();
			chon();
			break;
	}
}
void nhapChuoi()
{
	cout << "Nhap vao mot chuoi: ";
	cin.ignore();
	getline(cin, s);
	cout << "Chuoi vua nhap la: "<< s << endl;
	a = s;
	ghiFile(s);
}

void ghiFile(string s)
{
	ofstream ghi;
	ghi.open("Input1.txt",ios::app);
	ghi << s << endl;
	ghi.close();
	cout << "Da ghi file!" << endl;
}

void xoaKhoangTrang()
{
	int i = 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			for (int j = i;j < n;j++)
			{
				s[j] = s[j + 1];
			}
			n--;
			i--;
		}
	}
	// xoa dau
	i = 0;
	if (s[i] == ' ') s.erase(s.begin() + i);
	//xoa cuoi
	i = n;
	if (s[i] == ' ') s.erase(s.begin() + i);
	cout << s << endl << "Da xoa cac khoang trang thua!!!"<<endl;
	b = s;
}

void proper(string s)
{
	int dodai = s.length();
	for ( int i = 0; i <= dodai-1; i++ ) 
	{
		if( s[i] >= 65 && s[i] <= 90 )
			s[i] += 32;
	}
	
	for (int i = 0; i <= dodai-1; i++)
	{
		if (s[i] == ' ' && isalpha(s[i + 1]))
			s[i + 1] = toupper(s[i + 1]);
	}
	if (isalpha(s[0]) || isdigit(s[0]))
		s[0] = toupper(s[0]);
	else
	{
		cout << "Chuoi cua ban chua duoc chuan hoa, nhap 2" << endl;
		chon();
	}
	cout << "Chuoi sau khi chuan hoa." << endl;
	cout << s << endl;
	c = s;
}

void dem()
{
	int dem=0;
	int dodai = s.length();
	for (int i = 0; i < dodai-1 ; i++)
	{
		if (isalpha(s[i]))
			dem++;
	}
	cout <<"So ki tu: " << dem <<endl;
}

void output()
{
	ofstream ghi;
	ghi.open("output1.txt",ios::app);
	ghi << "Chuoi da nhap: " << a << endl;
	ghi << "Chuoi bo cac khoang trang thua: " << b << endl;
	ghi << "Chuoi chuan hoa Proper: " <<c << endl;
	ghi.close();
	cout << "Da xuat ra file!" << endl;
}


