#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;
int n;
string str;
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
	string temp =str;
	
	while (temp[0] == ' ')
	{
		temp.erase(temp.begin() + 0); 
	}
	//xoa cuoi
	while (temp[temp.length() - 1] == ' ')
	{
		temp.erase(temp.begin() + temp.length() - 1); 
	}
	// xoa ki tu giua
	for (int i = 0; i < temp.length(); i++)
	{
		
		if (temp[i] == ' ' && temp[i + 1] == ' ')
		{
			temp.erase(temp.begin() + i);
			i--;
		}
	}
	
	return temp;
	
}
string in_hoa()
{	
	string temp=str;
	//chuyen ki tu thuong
	for(int i=0; i<=temp.length();i++)
	{
		if(temp[i]>=65 && temp[i]<=90)
			temp[i]+=32;
	}
	temp[0]-=32;
	//in hoa ki tu dau 
	for(int i=1; i<temp.length();i++)
	{
		if(temp[i]==' ' && temp[i+1]>=97 && temp[i+1]<=122)
			temp[i+1]-=32;
	}
	return temp;
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
		case 2:system("cls");  
			cout<<"chuoi sau khi xoa khoang trang: "<<xoatrang()<<endl;
			menu();
			chon();
			break;
		case 3 :system("cls"); 
			cout<<"chuoi sau khi in hoa: "<<in_hoa()<<endl;
			menu();
			chon();
			break;
		case 4:system("cls"); 
			cout<<"so luong ki tu: "<<dem()<<endl;
			menu();
			chon();
			break;
		case 5:system("cls"); 
	
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

