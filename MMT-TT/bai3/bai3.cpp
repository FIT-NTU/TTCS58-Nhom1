#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#define max 100

using namespace std;

string ten;

struct dulieu
{
	char cauhoi[max],traloi1[max],traloi2[max],traloi3[max];
	int dapan;
};
vector<dulieu> ds;

struct xemdiem
{
	char hoten[max];
	int diem;
};
vector<xemdiem>d;

char file[20]="diem.txt",file1[20]="de1.txt",file2[20]="de2.txt";

void docdiem(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::in);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{	
			while(!file.eof())
			{
				xemdiem di;		
				file.getline(di.hoten,max);
				file>>di.diem;
				d.push_back(di);
				file.ignore();
			}								
		file.close();
		int m=d.size();
		for(int i=0;i<m;i++)
			{
				cout<<d[i].hoten<<endl;
				cout<<d[i].diem<<endl;
			}
		}
	
}
void ghidiem(string ten,int diemdat, char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::app);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{	
								
			file<<ten<<endl;
			file<<diemdat<<endl;
		
		
		file.close();
		}
	
}

void docfilede(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::in);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{	
			while(!file.eof())
			{
				dulieu	dl;		
				file.getline(dl.cauhoi,max);
				file.getline(dl.traloi1,max);
				file.getline(dl.traloi2,max);
				file.getline(dl.traloi3,max);
				file>>dl.dapan;
				ds.push_back(dl);
				file.ignore();
			}								
		file.close();
		}
	
}
void lambai()
{
	int diem=0;
	int n=ds.size();
	for(int i=0;i<n;i++)
		{
			int temp;
			cout<<endl<<ds[i].cauhoi<<endl;
			cout<<ds[i].traloi1<<endl;
			cout<<ds[i].traloi2<<endl;
			cout<<ds[i].traloi3<<endl;
			cout<<"dap an ban chon la dap an so bao nhieu: ";
			cin>>temp;
			if(temp==ds[i].dapan)
			{
				cout<<"\n Ban da tra loi dung."<<endl;
				diem=diem+1;
			}else
				{
					cout<<"\nBan da tra loi sai. \n Dap an dung la dap an so: "<<ds[i].dapan<<endl;
				}
			 
		}
	cout<<"So diem cua ban la: "<<diem<<endl;
	
	
	ghidiem(ten,diem,file);
	cout<<"da ghi lai ten va diem xua ban"<<endl;
}



int chonde()
{
	int de;
	do
	{
		
		cout<<"chon bo de nhan 1 hoac 2 xem diem nguoi choi bam 0:";
		cin>>de;
	}while(de<0||de>2);
	switch(de)
	{
		case 0:
			docdiem(file);
			break;
		case 1: 
			ds.clear();
			docfilede(file1);
			lambai();
			break;
		case 2: 
			ds.clear();
			docfilede(file2);
			lambai();
			break;
		
			
	}
}


int main()
{
	while(1)
	{
		cout<<" nhap ten cua ban :";
		getline(cin,ten);
		chonde();
		int a;
		cout<<"nhap 1 de tiep tuc nhap 0 de thoat:";
		cin>>a;
		if(a==0) break;
	}

	
	system("pause");
}
