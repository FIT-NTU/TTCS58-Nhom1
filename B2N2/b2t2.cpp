#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<fstream>
using namespace std;
ifstream f("inputb2n2.txt");
//ofstream p("outputb2n1.txt");
//khoi tao nhan vien
class nhanVien{
	protected :
	int maNv;
	string hoten;
	int tuoi;
	int luong;
	public:
		
		void InNv()
		{
			cout<<maNv<<"\t\t"<<hoten<<"\t\t"<<tuoi<<"\t\t"<<luong<<endl;
		}
		friend class qLiNvien;
};

class qLiNvien{
	vector<nhanVien> dsNv;
	public:
		//nhap danh sach nhan vien
		void nhapDS()
		{
			int n,a,g;
			cout<<"Nhap so luong nhan vien : ";cin>>n;
			dsNv.resize(n);
			n=dsNv.size();
			a=n;
			
			for(int i=0;i<n;i++)
			{
			cout<<"Nhap Ma Nhan Vien : "; cin>>dsNv[i].maNv;
			g=0;
			do{
				if(i==0)
				{
					break;
				}else
				if(dsNv[i].maNv==dsNv[g].maNv)
				{
					cout<<"nhap lai : "; cin>>dsNv[i].maNv;
					g=0;
				}else g++;
			}while(g<i);
			fflush(stdin);
			cout<<"Nhap Ho va Ten : "; getline(cin,dsNv[i].hoten);
			cout<<"Nhap Tuoi Nhan Vien : ";cin>>dsNv[i].tuoi;
			cout<<"Nhap Luong Nhan Vien : ";cin>>dsNv[i].luong;
			}
		}
		//nhap danh sach nhan vien tu file
		void nhapDstufile()
		{
			int n;
			string s;
			getline(f , s) ;  n = atoi(s.c_str()); 
			dsNv.resize(n);
			n=dsNv.size();
			for(int i=0;i<n;i++)
			{
				getline(f , s) ; dsNv[i].maNv = atoi(s.c_str());
				getline(f , s) ; dsNv[i].hoten = s;
				getline(f , s) ; dsNv[i].tuoi = atoi(s.c_str());
				getline(f , s) ; dsNv[i].luong = atoi(s.c_str());
			}
		}
		void ghiDsvaofile()
		{
			int p;
			p=fopen("outputb2n1.dat","rb");
			p<<"Ma nhan vien"<<"\t"<<"Ho ten nhan vien"<<"\t"<<"Tuoi"<<"\t\t"<<"Luong"<<endl;
			int n = dsNv.size();
			for(int i=0;i<n;i++)
			{
				p<<dsNv[i].maNv<<"\t\t"<<dsNv[i].hoten<<"\t\t"<<dsNv[i].tuoi<<"\t\t"<<dsNv[i].luong<<endl;
			}
			p<<"------------------------------------------------------------------\n";
		}
		//them nhan vien
		void them()
		{
			int x,n,a,l,g=0,c;
			cout<<"Nhap so luong nhan vien can them : ";cin>>x;
			n=dsNv.size();
			a=n;
			dsNv.resize(n+x);
			n=dsNv.size();
		//	c=a;
			for(int i=n-1;i>=a;i--)
			{
			cout<<"Nhap Ma Nhan Vien : "; cin>>dsNv[i].maNv;
			do{
				if(dsNv[i].maNv==dsNv[g].maNv)
				{
				cout<<"nhap lai : ";cin>>dsNv[i].maNv;
				g=0;
				}else g++;
				
			}while(g<a);
			fflush(stdin);
			cout<<"Nhap Ho va Ten : "; getline(cin,dsNv[i].hoten);
			cout<<"Nhap Tuoi Nhan Vien : ";cin>>dsNv[i].tuoi;
			cout<<"Nhap Luong Nhan Vien : ";cin>>dsNv[i].luong;
			}	
		}
		//cap nhat nhan vien
		void capNhat()
		{
			int y,n = dsNv.size();
			cout<<"Nhap ma nhan vien can cap nhat : ";cin>>y;
			for(int i=0;i<n;i++)
			{
				if(dsNv[i].maNv==y) 
				{
					int k;
					cout<<"Nhap so de thuc hien cap nhat voi so : \n1.Thay doi ten nhan vien \n2.Thay doi tuoi nhan vien \n3.Thay doi luong nhan vien \n4.Ket thuc\n";cin>>k ;
					while(k==1||k==2||k==3)
					{
						if(k==1)
						{
							fflush(stdin);
							cout<<"nhap lai ten nhan vien : "; getline(cin,dsNv[i].hoten);
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi tuoi nhan vien \n3.Thay doi luong nhan vien \n4.Ket thuc\n";cin>>k;
						}else
						if(k==2)
						{
							cout<<"nhap lai tuoi nhan vien : ";cin>>dsNv[i].tuoi;
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi tuoi nhan vien \n3.Thay doi luong nhan vien \n4.Ket thuc\n";cin>>k;
						}else
						if(k==3)
						{
							cout<<"nhap lai luong nhan vien : ";cin>>dsNv[i].luong;
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi tuoi nhan vien \n3.Thay doi luong nhan vien \n4.Ket thuc\n";cin>>k;
						}
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				dsNv[i].InNv();
			}
			
			
		}
		//xoa nhan vien
		void XoaNv()
		{
			int n = dsNv.size();
			int x;
			cout<<"nhap ma nhan vien can xoa : "; cin>>x;
			for(int i=0;i<n;i++)
			{
				if(dsNv[i].maNv==x) dsNv.erase(dsNv.begin()+i);
			}
		}
		//tim kiem nhan vien
		void timkiem()
		{
			int n=dsNv.size();
			int x ,dem=0 ;
			cout<<"nhap ma nhan vien can tim : "; cin>>x;
			for(int i=0;i<n;i++)
			{
				if(dsNv[i].maNv==x) 
				{
				cout<<"Thong tin nhan vien can tim :"<<endl;
				dsNv[i].InNv(); dem++;
				}
			}
			if(dem==0) cout<<"Khong co nhan vien can tim"<<endl;
		}
		//in ra danh sach nhan vien
		void inDS()
		{
			int n ;
			n=dsNv.size();
			cout<<"Ma nhan vien"<<"\t"<<"Ho ten nhan vien"<<"\t"<<"Tuoi"<<"\t\t"<<"Luong"<<endl;
			for(int i=0;i<n;i++)
			{
				dsNv[i].InNv();
			}
			cout<<"----------------------------------------------------------------"<<endl;
		}
};


int main()
{
	qLiNvien ql;
	
	int k;
	ql.nhapDstufile();
	ql.inDS();
	cout<<"Vui long chon so de chon cong viec thuc hien "<<endl;
	cout<<"Chon 1. De nhap lai du lieu nhan vien"<<endl;
	cout<<"Chon 2. De them du lieu nhan vien"<<endl;
	cout<<"Chon 3. De xoa du lieu nhan vien"<<endl;
	cout<<"Chon 4. De cap nhat du lieu nhan vien"<<endl;
	cout<<"Chon 5. De tim kiem nhan vien"<<endl;
	cout<<"Chon 6. De in ra man hinh"<<endl;
	cout<<"Chon 0. De ket thuc"<<endl;
	cout<<"Nhap so : ";cin>>k;
	
	/*while(k!=1)
	{
		if(k==0)
		{
			break;
		}
		cout<<"chua co danh sach nhan vien !!!"<<endl;
		cout<<"Vui long chon lai so de chon cong viec thuc hien "<<endl;
		cout<<"Chon 1. De nhap du lieu nhan vien"<<endl;
		cout<<"Chon 2. De them du lieu nhan vien"<<endl;
		cout<<"Chon 3. De xoa du lieu nhan vien"<<endl;
		cout<<"Chon 4. De cap nhat du lieu nhan vien"<<endl;
		cout<<"Chon 5. De tim kiem nhan vien"<<endl;
		cout<<"Chon 6. De in ra man hinh"<<endl;
		cout<<"Chon 0. De ket thuc"<<endl;
		cout<<"Nhap so : ";cin>>k;
	}*/
	
	
	while(k==1||k==2||k==3||k==4||k==5||k==6)
	{
		if(k==1)
		{
			//int m;
			//cout<<"ban muon lay danh sach tu dau ? \nNhap 1. de nhap tu ban phim \nNhap 2. de lay danh sach tu file\n"; cin>>m;
			//if(m==1)
			//	{
				ql.nhapDS();	
			//	} else 
			//	{
			//	ql.nhapDstufile();
			//	}
		}else
		if(k==2)
		{
			ql.them();
			ql.ghiDsvaofile();
		}else
		if(k==3)
		{
			ql.XoaNv();
			ql.ghiDsvaofile();
		}else
		if(k==4)
		{
			ql.capNhat();
			ql.ghiDsvaofile();
		}
		if(k==5)
		{
			ql.timkiem();
		}
		if(k==6)
		{
			ql.inDS();
		}
	cout<<"Ban co muon tiep tuc tuc hien cong viec hay nhap so "<<endl;
	cout<<"Chon 1. De nhap du lieu nhan vien"<<endl;
	cout<<"Chon 2. De them du lieu nhan vien"<<endl;
	cout<<"Chon 3. De xoa du lieu nhan vien"<<endl;
	cout<<"Chon 4. De cap nhat du lieu nhan vien"<<endl;
	cout<<"Chon 5. De tim kiem nhan vien"<<endl;
	cout<<"Chon 6. De in ra man hinh"<<endl;
	cout<<"Chon 0. De ket thuc"<<endl;
	cout<<"Nhap so : ";cin>>k;
	}
	system("pause");
}
