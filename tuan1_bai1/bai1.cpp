#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>

using namespace std;

void NhapChuoi();
void LuuFile(string s);
void ShowMenu();
void XoaKhoangTrang();
void ChuanHoaProPer();
void Dem();
void ketqua();
string s,b,c;
int tong;

int main() {
	ShowMenu();
	system("pause");
	return 0;
}
void ShowMenu() {
	cout << "1.nhap chuoi ki tu" << endl;
	cout << "2.bo khoang trang" << endl;
	cout << "3.chuan hoa dang proper" << endl;
	cout << "4.thog ke so luong cac ky tu chu cai co trong chuoi" << endl;
	cout << "5.luu file" << endl;
	cout<<"--------------------"<<endl;
	int x;
	cout << "nhap lenh ban can thuc hien" << endl;
	cin >> x;
	switch (x) {
	case 1:
		system("cls");
		NhapChuoi();
		break;
	case 2:
		system("cls");
		XoaKhoangTrang();
		break;
	case 3:
		system("cls");
		ChuanHoaProPer();
		break;
	case 4:
		system("cls");
		Dem();
		break;	
	case 5:
		system("cls");
		ketqua();
	}
}
void NhapChuoi() {
	cout << "nhap vao chuoi s" << endl;
	fflush(stdin);
	getline(cin, s);
	cout << s << endl;
	LuuFile(s);
	ShowMenu();
}
void LuuFile(string s) {
	ofstream luu;
	luu.open("bai1.txt");
	luu << s;
	luu.close();
}
void XoaKhoangTrang(){
	int n=s.length();
	for(int i = 0; i <= n; i++)
	{
		if(s[i] ==' ' && s[i+1]==' ')
		{
			for(int j = i; j < n; j++ )
			{
				s[j]=s[j+1];
			}
		n--;
		i--;
		}
	}
	//xoa dau
	int i=0;
	if(s[i]==' ')
	{
		s.erase(s.begin()+i);
	}
	//xoa cuoi
	i=n;
	if(s[i]==' ')s.erase(s.begin()+i);
	cout<< s << endl<< "da xoa cac khoang trang"<< endl;
	 b= s;
	ShowMenu();
}
void ChuanHoaProPer(){
	int chieudai=s.length();
	if(isalnum(s[0]))
		s[0]=toupper(s[0]);
	for(int i = 0;i <= chieudai; i++){
		if(s[i]==' '&&isalnum(s[i+1]))
		s[i+1]=toupper(s[i+1]);
	}
	cout<< "chuoi da dc chuan hoa"<< endl;
	cout<< s << endl;
	c= s;
	ShowMenu();
}
void Dem(){
	tong=0;
	for(int i=0; i< s.length(); i++){
		if(isalnum(s[i]))
		 tong=tong+1;
	}
	cout<<"tong la: "<< tong<< endl;
	ShowMenu();
}
void ketqua(){
	ofstream luu;
	luu.open("bai2.txt");
	luu <<" xoa khoang trang: "<< b<<endl;
	luu <<"chuan hoa:" << c<< endl;
	luu <<"tong ki tu: " <<tong;
	luu.close();
}
