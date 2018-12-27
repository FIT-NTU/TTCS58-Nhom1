#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;
int hoa=0,thuong=0;	

//xoa khoang trang
void xoakt (char chuoi[255])
{
	//xoa dau chuoi
	while(chuoi[0] == ' ') strcpy(&chuoi[0], &chuoi[1]); //kt1 de len kt0
	//xoa giua chuoi
	for(int i = 0; i< strlen(chuoi) - 1; i++) 
		if(chuoi[i] == ' ' && chuoi[i+1] == ' ')
		{
			strcpy(&chuoi[i], &chuoi[i+1]);
			i--;	
		}
	//xoa dau cuoi
	while(chuoi[strlen(chuoi)-1] == ' ') strcpy(&chuoi[strlen(chuoi)-1], &chuoi[strlen(chuoi)]); //lay kt null de len kt cuoi cung
}


//chuan hoa
void chuanhoa(char chuoi[255])
{
	chuoi=strlwr(chuoi); //dinh dang het chu thuong
	chuoi[0]=toupper(chuoi[0]);
	
	for(int i = 1; i< strlen(chuoi) - 1; i++)
		if(chuoi[i] == ' ')
		{
			chuoi[i+1]=toupper(chuoi[i+1]);
		}
	
}

//thong ke
void thongke(char chuoi[255])
{
		for(int i = 0; i< strlen(chuoi) - 1; i++)
		if(chuoi[i]>=65 && chuoi[i]<=90) hoa=hoa+1;
			else if (chuoi[i]>=97&&chuoi[i]<=122) thuong=thuong+1;
			
}

int main()	

{
	int luachon;
	char chuoi[255];
	char chuoi0[255];//chuoi ban dau;
	char chuoi1[255];//chuoi sau kkhi xoa khoang trang;
	char chuoi2[255];//chuoi sau khi chuan hoa;
	
	system("cls");//xoa mang hinh
	cout << "\nNhap vao chuoi: ";
	gets(chuoi);
	for(int i = 0; i< strlen(chuoi) - 1; i++)
		{
			chuoi0[i]=chuoi[i];
		}
	//tao file va ghi tat ca vao file
	ofstream input1 ("input1.txt");
	input1<<chuoi;puts(chuoi);
	input1.close();
	while (1)
	{
	cout << "-------------MENU-------------" << endl;
	cout << "\n1. Xoa khoang trang thua" << endl;
	cout << "\n2. Chuan hoa dang Proper" << endl;
	cout << "\n3. Thong ke chu hoa chu thuong" << endl;
	cout << "\n4. Ghi tat ca ket qua vao file text" << endl;
	cout << "\n5. Ket thuc" << endl;
	cout << "-------------END--------------";
	cout << "\nNhap lua chon: " << endl;
	cin >> luachon;
	
	if (luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4 && luachon!=5)
	{
		cout <<"Lua chon khong hop le !";
		system("pause");
	}
	
	else if(luachon == 1) //xoa khoang trang thua
		{
			xoakt(chuoi);
			cout << "KQ sau khi xoa khoang trang thua:" ;
			puts(chuoi);
				for(int i = 0; i< strlen(chuoi) - 1; i++)
		{
			chuoi1[i]=chuoi[i];
		}
		}
		
	else if (luachon == 2) //chuan hoa
		{
			chuanhoa(chuoi);
			cout<<"Chuan hoa dang Proper:";
			puts(chuoi);
				for(int i = 0; i< strlen(chuoi) - 1; i++)
		{
			chuoi2[i]=chuoi[i];
		}
		}
		
	else if (luachon == 3) //thong ke
		{	
				
			thongke(chuoi0);
			cout<<"\nChu hoa "<<hoa;
			cout<<"\nChu thuong "<<thuong<<endl;
	
		
		}
	else if (luachon == 4) //ghi tat ca vao file
		{
			ofstream output1 ("output1.txt");
			output1<<chuoi1<<endl;
			output1<<chuoi2<<endl;
			output1<<"Chu hoa "<<hoa<<"\t Chu thuong "<<thuong;
			input1.close();
			cout<<"Da ghi vao file "<<endl;
		}
		
	else if(luachon==5) //ket thuc
		{
			break;
		}
	}
	return 0;
	
}

