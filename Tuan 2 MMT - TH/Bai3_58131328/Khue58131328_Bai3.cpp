#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct boDe
{
	string cauHoi,a,b,c,d,dapAn;
};
struct nguoiChoi
{
	int diem,slch;
	string ten,tenDe;
};
void khoitao(nguoiChoi b[50]);
void chonBoDe(boDe a[],int n);
void traLoi(char *file,boDe a[],int n);
void xemDiem(nguoiChoi a[]);
void menu();
nguoiChoi b[50];
int soLan=1,kt=0;
void khoitao(nguoiChoi b[50])
{
	b[soLan].diem=0;
}
void chonBoDe(boDe a[],int n)
{
	int chon;
	do
	{
		system("cls");
		cout<<"Chon bo de trac nghiem"<<endl;
		cout<<"1.Bo de 1"<<endl;
		cout<<"2.Bo de 2"<<endl;
		cout<<"3.Bo de 3"<<endl;
		cout<<"4.Quay lai"<<endl;
		cout<<"Chon :>";	cin>>chon;
		switch(chon)
		{
			case 1:
				traLoi("BoDe1.txt",a,n);
				break;
			case 2:
				traLoi("BoDe2.txt",a,n);
				break;
			case 3:
				traLoi("BoDe3.txt",a,n);
				break;
			case 4:
				menu();
				break;
			default:
				cout<<"Lua chon khong ton tai!"<<endl;
				system("pause");
				break;
		}
	}while(chon!=4&&chon!=1&&chon!=2&&chon!=3);
}
void traLoi(char *file,boDe a[],int n)
{
	system("cls");
	ifstream f;
	string s;
	khoitao(b);
	fflush(stdin);
	if(kt!=1)
	{
		cout<<"Ten nguoi choi :>";	getline(cin,b[soLan].ten);
	}
	f.open(file);
	getline(f,s);	n=atoi(s.c_str());
	cout<<"Bo de gom "<<n<<" cau"<<endl;
	int i=0,chon;
	char choise[2],choise1[2];
	while(i<n)
	{
		getline(f,s);	a[i].cauHoi=s;
		getline(f,s);	a[i].a=s;
		getline(f,s);	a[i].b=s;
		getline(f,s);	a[i].c=s;
		getline(f,s);	a[i].d=s;
		getline(f,s);	a[i].dapAn=s;
		cout<<a[i].cauHoi<<endl<<a[i].a<<endl<<a[i].b<<endl<<a[i].c<<endl<<a[i].d<<endl;
		do
		{
			fflush(stdin);
			cout<<"Dap an cua ban la:>";	cin.getline(choise,2);
			if(strcmp(choise,"A")==0)
			{
				if(a[i].a.compare(a[i].dapAn)==0)
				{
					cout<<"Dung"<<"\n\n";
					b[soLan].diem++;
				}
				else
					cout<<"Sai!"<<"Dap an la : "<<a[i].dapAn<<"\n\n";
			}
			else if(strcmp(choise,"B")==0)
			{
				if(a[i].b.compare(a[i].dapAn)==0)
				{
					cout<<"Dung"<<"\n\n";
					b[soLan].diem++;
				}
				else
					cout<<"Sai!"<<"Dap an la : "<<a[i].dapAn<<"\n\n";
			}
			else if(strcmp(choise,"C")==0)
			{
				if(a[i].c.compare(a[i].dapAn)==0)
				{
					cout<<"Dung"<<"\n\n";
					b[soLan].diem++;
				}
				else
					cout<<"Sai!"<<"Dap an la : "<<a[i].dapAn<<"\n\n";
			}
			else if(strcmp(choise,"D")==0)
			{
				if(a[i].d.compare(a[i].dapAn)==0)
				{
					cout<<"Dung"<<"\n\n";
					b[soLan].diem++;
				}
				else
					cout<<"Sai!"<<"Dap an la : "<<a[i].dapAn<<"\n\n";
			}
			else
				cout<<"Dap an chi co A, B, C, D! xin chon lai dap an."<<endl;
		}while(strcmp(choise,"A")!=0&&strcmp(choise,"B")!=0&&strcmp(choise,"C")!=0&&strcmp(choise,"D")!=0);
		i++;
	}
	cout<<"Diem cua ban la : "<<b[soLan].diem<<"/"<<n<<"\n\n";
	b[soLan].slch=n;
	b[soLan].tenDe=file;
	ofstream k ("ketqua.txt");
	k<<soLan<<endl;
	if(k!=NULL)
	{
		for(int i=1;i<=soLan;i++)
		{
			k<<b[i].slch<<endl;
			k<<b[i].tenDe<<endl;
			k<<b[i].ten<<endl;
			k<<b[i].diem<<endl;
		}
	}
	else
	{
		for(int i=1;i<=soLan;i++)
		{
			k<<b[i].slch<<endl;
			k<<b[i].tenDe<<endl;
			k<<b[i].ten<<endl;
			k<<b[i].diem<<endl;
		}
	}
	k.close();
	soLan++;
	fflush(stdin);
	cout<<"Ban co muon choi lai hay tiep tuc khong? <t/y/n>"<<endl;
	cout<<"t<Tiep tuc>\ny<Choi lai>\nn<Thoat>\n";
	do
	{
		cin.getline(choise1,2);
		if(strcmp(choise1,"t")==0)
		{
			kt=0;
			menu();
		}
		else if(strcmp(choise1,"y")==0)
		{
			soLan--;
			kt=1;
			traLoi(file,a,n);
		}
		else if(strcmp(choise1,"n")==0)
			cout<<"Ket thuc"<<endl;
		else
			cout<<"Xin cho t/y/n"<<endl;
	}while(strcmp(choise1,"y")!=0&&strcmp(choise1,"n")!=0&&strcmp(choise1,"t")!=0);
	f.close();
}
void xemDiem(nguoiChoi a[])
{
	ifstream h;
	h.open("ketqua.txt");
	int m;
	string s;
	getline(h,s);	m=atoi(s.c_str());
	if(h!=NULL)
	{
		for(int i=1;i<=m;i++)
		{
			getline(h,s);	a[i].slch=atoi(s.c_str());
			getline(h,s);	a[i].tenDe=s;
			getline(h,s);	a[i].ten=s;
			getline(h,s);	a[i].diem=atoi(s.c_str());
			cout<<"Nguoi choi "<<a[i].ten<<" ban dat tong diem "<<a[i].diem<<"/"<<a[i].slch<<" trong bo de "<<a[i].tenDe<<endl;
		}
		getline(h,s);
		cout<<s<<endl;
	}
	else
		cout<<"Chua co du lieu!"<<endl;
	h.close();
}
void menu()
{
	boDe a[50];
	int n,chon;
	do
	{
		system("cls");
		cout<<"---------Tro choi tra loi trac nghiem---------"<<endl;
		cout<<"1.Chon bo de trac nghiem."<<endl;
		cout<<"2.Xem diem cua nguoi choi."<<endl;
		cout<<"3.Thoat."<<endl;
		cout<<"Chon :>";	cin>>chon;
		switch(chon)
		{
			case 1:
				chonBoDe(a,n);
				break;
			case 2:
				xemDiem(b);
				system("pause");
				break;
			case 3:
				break;
			default:
				cout<<"Lua chon khong ton tai!"<<endl;
				system("pause");
				break;
		}
	}while(chon!=3&&chon!=1);
}
int main()
{
	menu();
	return 0;
}
