#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int n;
string str;
char *chuoi;

void nhap()
{   
	fstream f,k;
	f.open("D:\\input1.txt",ios::out);
	k.open("D:\\ouput1.txt",ios::out);
	fflush(stdin);
	getline(cin,str);
	f<<str;
	k<<"chuoi vua nhap: "<<str<<endl;
	k.close();
	f.close();
	cout <<str<<endl;
}
string xoatrang()
{
	//xoa dau
	
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0); 
	}
	//xoa cuoi
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1); 
	}
	// xoa ki tu giua
	for (int i = 0; i < str.length(); i++)
	{
		
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	
	return str;
	
}
string in_hoa()
{	
	//chuyen toan bo chuoi thanh thuong
	strlwr((char *)str.c_str());
	// ghi hoa moi ki tu sau dau cach
	if (str[0] != ' ')
	{
		if (str[0] >= 97 && str[0] <= 122)
		{
			str[0] -= 32;
		}	
	}
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			if (str[i + 1] >= 97 && str[i + 1] <= 122)
			{
				
				str[i + 1] -= 32; 
			}
		}
	}
	return str;
}
int dem()
{	
	int dem=0; 
	for (int i=0;i<str.length();i++)
	{
		if(str[i]!=' ')
		dem++;
	}
	return dem;
}
void ghi_kq()
{
	fstream f;
	f.open("D:\\ouput1.txt",ios::app);
	f<<"chuoi sau khi xoa khoang trang:"<<xoatrang()<<endl;
	f<<"chuoi sau khi in hoa: "<<in_hoa()<<endl;
	f<<"so luong ki tu: "<<dem();
	f.close();
}
void menu()
{	

	cout<<"1.nhap du lieu vao file"<<endl;
	cout<<"2.bo cac khoang trang thua"<<endl;
	cout<<"3.chuan hoa chuoi dang proper"<<endl;
	cout<<"4.thong ke so luong ki tu"<<endl;
	cout<<"5.in ket qua vao file"<<endl;
}

void chon()
{	

	cout<<"----------------"<<"chon cac muc trong menu phia tren"<<"-----------"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:system("cls"); 
			nhap(); 
			menu();
			chon();
			break;
		case 2: 
			cout<<"chuoi sau khi xoa khoang trang: "<<xoatrang()<<endl;
			menu();
			chon();
			break;
		case 3 :
			cout<<"chuoi sau khi in hoa: "<<in_hoa()<<endl;
			menu();
			chon();
			break;
		case 4:
			cout<<"so luong ki tu: "<<dem()<<endl;
			menu();
			chon();
			break;
		case 5:
		
			ghi_kq();
			cout<<"--da ghi ket qua vao file--"<<endl;
			menu();
			chon();
			break;
		default:
			cout<<"ban nhap ko hop le"<<endl<<"--------"<<"moi ban nhap lai"<<"--------"<<endl;	
			menu();
			cout<<endl;
			chon();	
					
	}
		
}


int main()
{


	menu();
	chon();
	
}

