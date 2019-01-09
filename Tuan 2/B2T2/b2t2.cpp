#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<fstream>
using namespace std;
ifstream f("inputb2t1.dat" );
ofstream g("inputb2t1.dat" , ios::app);
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
	nhanVien nv;
	public:
	
		//nhap danh sach nhan vien tu file
		void docDSnhanVientuFile()
		{
			int n ;
			string s;
			getline(f , s) ; n = atoi(s.c_str());
			dsNv.resize(n);
			n = dsNv.size();
			for(int i=0;i<n;i++)
			{
				getline(f , s) ; dsNv[i].maNv = atoi(s.c_str());
				getline(f , s) ; dsNv[i].hoten = s;
				getline(f , s) ; dsNv[i].tuoi = atoi(s.c_str());
				getline(f , s) ; dsNv[i].luong = atoi(s.c_str());
			}
			f.close();
		}
		//nhap lai danh sach nhan vien
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
			cout<<"--------------------------------------------------------------------------"<<endl;
			}
		}
		
		//them x nhan vien		
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
			
		}
		void ghiDSnhanViencvaoFile()
		{
			//xoa toan bo du lieu trong file va ghi lai tu dau
			ofstream k("inputb2t1.dat");
			int n;
			n = dsNv.size();
			k<<n<<endl;
			for(int i=0;i<n;i++)
			{
				k<<dsNv[i].maNv<<endl;
				k<<dsNv[i].hoten<<endl;
				k<<dsNv[i].tuoi<<endl;
				k<<dsNv[i].luong<<endl;	
			}
		}

};


int main()
{
	qLiNvien ql;
	int k;
	ql.docDSnhanVientuFile();
	cout<<endl;
	cout<<"			 			1. Add Record"<<endl;
	cout<<"			 			2. List Record"<<endl;
	cout<<"			 			3. Modify Record"<<endl;
	cout<<"			 			4. Delete Record"<<endl;
	cout<<"			 			5. Exit"<<endl;
	cout<<"			 			Your Choice : ";cin>>k;
	
	while(k==1||k==2||k==3||k==4)
	{
		if(k==1)
		{
			ql.them();
			ql.ghiDSnhanViencvaoFile();
			system("cls");
		}else
		if(k==2)
		{
			system("cls");
			ql.inDS();
		}else
		if(k==3)
		{
			ql.capNhat();
			ql.ghiDSnhanViencvaoFile();
			system("cls");
		}else
		if(k==4)
		{
			ql.XoaNv();
			ql.ghiDSnhanViencvaoFile();
			system("cls");
		}
		cout<<endl;
		cout<<"						Another choice ?"<<endl;
		cout<<endl;
		cout<<"			 			1. Add Record"<<endl;
		cout<<"			 			2. List Record"<<endl;
		cout<<"			 			3. Modify Record"<<endl;
		cout<<"			 			4. Delete Record"<<endl;
		cout<<"			 			5. Exit"<<endl;
		cout<<"			 			Your Choice : ";cin>>k;
	}

	
	system("pause");
	
}
