#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

ofstream ofs;
ofstream s("output1.txt");
//Mo tep de ghi
void ghi(char a[255])
{
	ofs.open("input1.txt");
	ofs<<a;
	ofs.close();
}

void nhapchuoi(char a[255])
{
	fflush(stdin); //xoa bo nho dem
	cout<<"Nhap vao 1 chuoi:";
	cin.getline(a, 255);
	cout<<"Chuoi vua nhap la:"<<a;
	ghi(a);
}

void xoa(char a[255],int vitrixoa)
{
	int n=strlen(a);//gan n= do dai cua chuoi
    for(int i=vitrixoa;i<n;i++)//duyet chuoi toi vi tri can xoa
     a[i]=a[i+1];
	a[n-1]='\0'; //end
}
void xoa_khoang_trang(char*a)
{
    for(int i=0;i<strlen(a);i++) //strlen(a) la do dai chuoi a
    if(a[i]==' '&& a[i+1]==' ') //giua cac tu chi giu lai 1 khoang trang
		{
			xoa(a,i);
			i--;
		}
    if(a[0]==' ') //xoa khoang trang dau chuoi
		xoa(a,0);
    if(a[strlen(a)-1]==' ') //xoa khoang trang cuoi chuoi
		xoa(a,strlen(a)-1);
	cout<<"Chuoi sau khi bo cac khoang trang la:"<<a<<endl;
	s<<a<<endl; //in chuoi sau khi xoa khoang trang vao file output1.txt
}

void proper(char *a) 
{ 
	char *p; //con tro p
	p=a;
	p[0]=toupper(p[0]); //gan vi tri 0 la vi tri dau tien cua chuoi
    while (strstr(p, " ") != NULL) //ham chuyen ky tu dau tien cua cac tu trong chuoi thanh chu viet hoa
    {
        p = strstr(p, " ") + 1;
        p[0] = toupper(p[0]);
    }
    cout<<"Chuoi sau khi chuan hoa la:"<<a<<endl;
    s<<a<<endl; //in chuoi sau chuan hoa vao file output1.txt
}
void dem(char*a)
{
	int dem=0;
	for(int i=0;i<strlen(a);i++) //duyet tu dau toi cuoi chuoi
	if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
	{
		dem++;
	}	
	cout<<"So luong chu cai trong chuoi la:"<<dem<<endl;
	s<<dem<<endl; //in so luong vao file output1.txt
}
void menu(char *a)
{
	
	int k; //bien lua chon
	do
	{
		cout<<"\n____MENU____"<<endl;
		cout<<"0.Thoat."<<endl;
		cout<<"1.Nhap 1 chuoi va ghi vao file"<<endl;
		cout<<"2.Bo cac khoang trang thua(dau, cuoi chuoi va chi giu lai 1 khoang trang giua cac tu"<<endl;
		cout<<"3.Chuan hoa chuoi sao cho ky tu dau tien moi tu in hoa"<<endl;
		cout<<"4.Dem so chu cai co trong chuoi"<<endl;
		cout<<"Ban chon chuc nang so:"<<endl;
		cin>> k;
		switch( k )
		{
			case 0: break;
			case 1:
				nhapchuoi(a);
				break;
			
			case 2:
				xoa_khoang_trang(a);
				break;
			
			case 3:
				proper(a);
				break;
			
			case 4:
				dem(a);
				break;		
		
			default:
				cout<< "\nNhap lai!";
				break;
		}
	}while(k!=0); //neu =0 se ket thuc
}
int main()
{
	char a[255];
	char *p;
	menu(a);
	system("pause");
	return 0;
}

	
	
	
	
	
