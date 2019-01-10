#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

string s, a, b, c;
int d=0;

void showMenu();
void chon();
void nhapChuoi();
void ghiFile(string s);
void xoaKhoangTrang();
void proper();
void dem();
void output();
int out();

int main()
{
	showMenu();
	chon();
	system("pause");
}

void showMenu()
{
	cout << "-----------------------Menu-----------------------"<<endl;
	cout << "1. Nhap vao mot chuoi va ghi vao tap tin." << endl;
	cout << "2. Bo cac khoang trang thua." << endl;
	cout << "3. Chuan hoa chuoi dang Proper." << endl;
	cout << "4. Thong ke so luong cac ki tu chu cai." << endl;
	cout << "5. Ghi tat ca ket qua thuc hien duoc vao tap tin." << endl;
	cout << "6. Exit."<<endl;
	cout << "--------------------------------------------------"<<endl;
}

void chon()
{
	int select;
	cout << "Lua chon cua ban: ";
	cin >> select;
	if (select != 1 && s == "")
	{
		cout << "Chua co chuoi!" <<endl;
		showMenu();
		chon();
	}
	else
	{
		switch (select)
		{   
			case 1:
			    nhapChuoi();
			    chon();
			    showMenu();
			    break;
			case 2:
				xoaKhoangTrang();
				chon();
				showMenu();
				break;
			case 3:
				proper();
				chon();
				showMenu();
				break;
			case 4:
				dem();
				chon();
				showMenu();
				break;
			case 5:
				output();
				chon();
				showMenu();
				break;
			case 6:
				return;
			case 7:
				cout << s<<endl;
				break;
		}
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
	ghi.open("Input1.txt");
	ghi << s;
	ghi.close();
	cout << "Da ghi file!" << endl;
}

void xoaKhoangTrang()
{
	int i = 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' '&& s[i + 1] == ' ')
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
	if (s[i] == ' ') 
		s.erase(s.begin() + i);
	//xoa cuoi
	i = n;
	if (s[i] == ' ') 
		s.erase(s.begin() + i);
	cout << s << endl << "Da xoa cac khoang trang thua!!!"<<endl;
	b = s;
}

void proper()
{ 
	int dodai = s.length();
	for (int i = 0; i <= dodai; i++)
	{
		if (s[i] == ' ' && isalpha(s[i + 1]))
			s[i + 1] = toupper(s[i + 1]);
		else 
			s[i + 1] = tolower(s[i + 1]);
	}
	if (s[dodai]=' ')
	{
		s[dodai]=s[dodai-1];
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
	for (int i = 0; i < dodai; i++)
	{
		if (isalpha(s[i]))
			dem++;
	}
	cout <<"So ki tu: " << dem <<endl;
	d = dem;
}

void output()
{
	ofstream ghi;
	ghi.open("output1.txt");
	ghi << a << endl;
	ghi << b << endl;
	ghi << c << endl;
	ghi << d << endl;
	ghi.close();
	cout << "Da xuat ra file!" << endl;
}

