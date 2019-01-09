
#include <conio.h>
#include <string.h>
#include <iostream>
char *pathin="input1.txt";
char *pathout="output1.txt";
char str[255];
char str1[255];
char str2[255];
int kitu;
using namespace std;
void Nhap()
{
	
	FILE *file;
	file = fopen(pathin,"wt");
	if (!file)
		cout<<"khong tim thay file"<<endl;
	else
	{
	
	cout<<"nhap chuoi: ";
	fflush(stdin);
	gets(str);
	fprintf(file,str);
	cout<<"da ghi vao file";
	}
	fclose(file);
}
void BoKhoangTrong()
{
	
		
	//xoa khoang trang dau cau:
	while(str[0]==' ')strcpy(&str[0],&str[1]);
	
	//xoa khaong tran o giua:
	for(int i=0;i<strlen(str);i++)
		if(str[i]==' ' && str[i+1]== ' ')
			{
				strcpy(&str[i],&str[i+1]);
				i--;
			}
			
			
	//xoa cuoi 
	while(str[strlen(str)-1]==' ') strcpy(&str[strlen(str)-1],&str[strlen(str)]);
	
	
	

	for(int i=0;i<strlen(str);i++) str1[i]=str[i];
	puts(str1);
}

void ChuanHoa()
{

	
	for(int i=0;i<strlen(str);i++) str[i]=str1[i];
	

			
			//chuyen chuoi ve toan bo chu thuong
		strlwr(str);
			
			//viet hoa chu dau cau
			// ham toupper chuyen chu thuong thanh chu in
		str[0]=toupper(str[0]);
			
			//viet hoa chu con lai
		for(int i=1;i<strlen(str);i++) if(str[i]==' ') str[i+1]=toupper(str[i+1]);


		for(int i=0;i<strlen(str);i++) str2[i]=str[i];
		puts(str2);
}


//------------------------
//tinh so chu hoa chu thuong cua chuoi ban dau


void ThongKe()
{
	int count=0;
			for(int i=0;i<strlen(str);i++) if(str[i]==' ') count=count+1;
			kitu=strlen(str)-count;
			cout<<"\nki tu:"<<kitu;
			
		

}

//ghi file
void ghi()
{
		FILE *file;
		file=fopen(pathout,"w");
			if (!file)
				cout<<"khong tim thay file output "<<endl;
			else
			{
				fprintf(file,str1);
				fprintf(file,"\n");
				fprintf(file,str2);
				fprintf(file,"\n so ki tu cua chuoi ban dau: %d",kitu);
				
				
			}
			fclose(file);
}



void Menu();		// Ham nay se xuat ra cac danh sach menu
int ChonMenu();		// Ham nay dung de chon 1 menu tuong ung
void XuLyMenu();	// Xu ly menu ung voi menu duoc chon


void Menu()
{
	cout<<"Le Tuan Tai 58131379\n\n\n";
	cout<<"===============MENU==============\n";
	cout<<"1. Nhap chuoi toi da 255 ki tu va ghi vao tap tin input1.txt\n";
	cout<<"2. Bo khoang trang thua\n"; 
	cout<<"3. Chuan hoa dang Proper\n"; //ki tu dau tien moi8 tu viet hoa
	cout<<"4. Thong ke luong ki tu chu cai trong chuoi\n";
	cout<<"5. Ghi tat ca vao file !!\n";
	cout<<"9. Thoat !!!\n";
	cout<<"==================================\n";
}


int ChonMenu()
{
	int n=0;
	cout<<"\n\nMoi chon yeu cau:";
	cin>>n;
	if(n > 0 || n < 9) return n;
		else return ChonMenu();
}

void XuLyMenu()
{
	int chon;
	chon=ChonMenu();
	switch(chon)
	{
		case 1:
			cout<<"1. Nhap chuoi toi da 255 ki tu va ghi vao tap tin input1.txt\n";
			Nhap();
			break;
		case 2:
			cout<<"2. Bo khoang trang thua\n"; 
			BoKhoangTrong();
			break;
		case 3:
			cout<<"3. Chuan hoa dang Proper\n";
			ChuanHoa();
			break;
		case 4:
			cout<<"4. Thong ke luong ki tu chu cai trong chuoi\n";
			ThongKe();
			break;
		case 5:
			ghi();
			cout<<"da ghi vao file !!!";
			break;
		case 9:
			cout<<"9. Thoat !!!\n\n\n";
			cout<<"THANK YOU";
			exit(1);
			break;		
	}
}


int main()
{
	Menu();
	while(1)
	{
		XuLyMenu();
	}
	_getch();
}


