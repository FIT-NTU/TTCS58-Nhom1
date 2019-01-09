#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;
char s[255];

void XoaKTrang()
{
	 // Xoa khoang trang dau chuoi
    while( s[0] == ' ' ) strcpy(&s[0], &s[1]);
 
    // Xoa khoang trang cuoi chuoi
    while( s[strlen(s)-1] == ' ') s[strlen(s)-1] = '\0';
 
    // Xoa khoang trang thua giua 2 tu 
 
    int i;
    for(i = 0; i < strlen(s); i++)
    {
        if( s[i] == ' ' && s[i+1] == ' ')
        {
            strcpy(&s[i], &s[i+1]);
            i--; 
        }
    }
 
    printf("\nChuoi bo cac khoang trang thua:%s", s);
}

void ChuanHoa()
{
	XoaKTrang();
	s2 = strlwr(s2); //chuyen chuoi ve ky tu thuong
	
	s2[0] = toupper(s2[0]);
	
	for(int i = 1; i< strlen(s2) - 1; i++)
		if(s2[i] == ' ')
		{
			s2[i+1]=toupper(s2[i+1]);
		}
		cout << "\nChuan hoa chuoi:" << s2 <<endl;	
}

void ThongKe()
{
	int a=0,t=0;	
		for(int i=0; i<strlen(s)-1; i++)
		if(s[i]>=65 && s[i]<=90){ a=a+1;			
		} 
		else if (s[i]>=97&&s[i]<=122) t=t+1;
			cout<<"\nSo luong chu thuong: " << t << endl;
			cout<<"\nSo luong chu hoa: " << a << endl;			
}

void GhiFile()
{
	ofstream ghi;
	ghi.open("input1.txt");
	ghi << s;
	ghi.close();
	cout << "Ghi file thanh cong!" << endl;
}

void output()
{
	int a, t;
	char s1[255], s2[255];
	ofstream output1("output1.txt");

	output1<<"Chu hoa "<< a <<"\t Chu thuong "<< t;
	output1.close();
	cout<<"Da ghi vao file! "<<endl;
}
void ShowMenu()
{
	cout << "\n---------------------MENU---------------------\n";
	cout << "1. Xoa khoang trang thua" << endl;
	cout << "2. Chuan hoa chuoi dang proper" << endl;
	cout << "3. Thong ke so luong chu hoa va chu thuong" << endl;
	cout << "4. Ghi ket qua vao file output1" << endl;
	cout << "5. Ket thuc" << endl;
	cout << "\n---------------------END-------------------\n";
}

void Chon()
{
	int select;
	cout << "\nLua chon cua ban la: ";
	cin >> select;
	switch (select)
	{
		case 1:
			XoaKTrang();
			Chon();
			break;
		case 2:
			ChuanHoa(s);
			Chon();
			break;
		case 3:
			ThongKe();
			Chon();
			break;
		case 4:
			output();
			Chon();
			break;
		case 5:
			break;
	}
}

int main()	
{
	printf("Nhap vao mot chuoi: ");
	gets(s);
	printf("\nChuoi vua nhap: ");
	puts(s);
	GhiFile();
	ShowMenu();
	Chon();
	
	system("pause");
	return 0;
}

