#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<conio.h>
#include <ctype.h>
using namespace std;
char s[255];
char a[255];
void NhapChuoiVaoFile()
{
	ofstream f("input1.txt");
	f << "chuoi vua duoc nhap la: \n" << s << " ";
	f.close();
		cout<<"Ghi file thanh cong";
}
char XoaKhoangTrang(){
	while(s[0]==' ')strcpy(&s[0],&s[1]);//xoa dau
	for(int i=0;i<strlen(s);i++)//xoa giua
		if(s[i]==' ' && s[i+1]== ' ')
			{
				strcpy(&s[i],&s[i+1]);
				i--;
			}
	while(s[strlen(s)-1]==' ') strcpy(&s[strlen(s)-1],&s[strlen(s)]);//xoa cuoi
	for(int i=0;i<strlen(s);i++) a[i]=s[i];
	puts(a);
}
int ChuanHoa()
{
	for(int i=0;i<strlen(s);i++) s[i]=a[i];
		strlwr(s);//chuyen ve chuoi thuong
		s[0]=toupper(s[0]);// viete hoa chu cai dau
		for(int i=1;i<strlen(s);i++) if(s[i]==' ') s[i+1]=toupper(s[i+1]);
		for(int i=0;i<strlen(s);i++) a[i]=s[i];
		puts(a);
}
int DemKiTu()
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++) //duyet tu dau -> cuoi chuoi.neu khong phai o trong thi dem +1
	{
		if (s[i] != 32)
			dem++;
	}
	return dem;
}
void GhiKetQuaVaoFile()
{
	//ghi ket qua thuc hien cac ham vao file
	ofstream f("D://TT Co so/Bo de 1/output1.txt");
	f <<"Xoa khoang trang: "<<XoaKhoangTrang()<<endl;
	f <<"Chuan hoa proper: "<<ChuanHoa<< endl;
	f << "So ky tu: " << DemKiTu();
}
void Menu()
{
	cout<<"Ho va ten: Sam Van Quan"<<endl;
	cout<<"MSSV la: 58131370"<<endl;
	cout<<"Menu chuong trinh gom: "<<endl;
	cout<<"1. Nhap va ghi file: "<<endl;
	cout<<"2. Xoa khoang tranng: "<<endl;
	cout<<"3. Chuan hoa chuoi:  "<<endl;
	cout<<"4. Dem ki tu:  "<<endl;
	cout<<"5. Ghi lai het vao file "<<endl;
	cout<<"6. ket thuc menu: "<<endl;
}
int ChucNang()
{	int n;
	cout<<"Moi ban chon chu nang: "<<endl;
	cin>>n;
	if (n > 0 && n < 7) return n;
	else return ChucNang();
}
void XuLyMenu(){
	int chon;
	chon = ChucNang();
	switch(chon)
	{
		case 1:
			cout<<"1. 1. Nhap va ghi file: \n";
			NhapChuoiVaoFile();
			break;
		case 2:
			cout<<"2. Xoa khoang tranng: \n"; 
			XoaKhoangTrang();
			break;
		case 3:
			cout<<"3. Chuan hoa chuoi: \n";
			ChuanHoa();
			break;
		case 4:
			cout<<"4. Dem ki tu: \n";
			DemKiTu();
			break;
		case 5:
			GhiKetQuaVaoFile();
			cout<<"5. Ghi lai het vao file ";
			break;
		case 6:
			cout<<"6. ket thuc menu: ";
			exit(1);
			break;		
	}
}

int main(){
	Menu();
	while(1)
	{
		XuLyMenu();
	}
	system("pause");
}
