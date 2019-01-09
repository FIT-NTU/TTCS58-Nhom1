#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<fstream>
using namespace std;
ifstream f("b3.txt" );
//khoi tao nhan vien
class nhanvien{
	protected :
	int manv;
	string hoten;
	int songaycong;
	public:
		bool operator<(nhanvien nv)
		{
			return songaycong<nv.songaycong;
		}
		int luong()
		{
			return songaycong*300000;	
		}
		void InNv()
		{
			cout<<hoten<<"\t\t"<<manv<<"\t\t"<<songaycong<<"\t\t"<<luong()<<endl;
		}
		friend class qlinhanvien;
};
bool k(nhanvien i, nhanvien j)
{
	return i<j;
}
class qlinhanvien{
	vector<nhanvien> dsnv;
	public:
		void docDSnhanVientuFile()
		{
			int n ;
			string s;
			getline(f , s) ; n = atoi(s.c_str());
			dsnv.resize(n);
			n = dsnv.size();
			for(int i=0;i<n;i++)
			{
				getline(f , s) ; dsnv[i].hoten = s;
				getline(f , s) ; dsnv[i].manv = atoi(s.c_str());
				getline(f , s) ; dsnv[i].songaycong = atoi(s.c_str());
			}
			f.close();
		}
		void sapxep()
		{
			sort(dsnv.begin(),dsnv.end(),k);
		}
		void timkiem()
		{
			int n=dsnv.size();
			int x ,dem=0 ;
			cout<<"nhap ma nhan vien can tim : "; cin>>x;
			for(int i=0;i<n;i++)
			{
				if(dsnv[i].manv==x) 
				{
				cout<<"Thong tin nhan vien can tim :"<<endl;
				dsnv[i].InNv(); dem++;
				}
			}
			if(dem==0)
			{
			cout<<"Khong co nhan vien can tim"<<endl;
			}
			cout<<"------------------------------------------------------------------------------------------"<<endl;
		}
		void them()
		{
			int n=dsnv.size();
			n++;
			dsnv.resize(n);
			ifstream f("b3nhanvienbosung.txt");
			string s;
			getline(f , s) ; dsnv[n-1].hoten = s;
			getline(f , s) ; dsnv[n-1].manv = atoi(s.c_str());
			getline(f , s) ; dsnv[n-1].songaycong = atoi(s.c_str());
			f.close();
		}
		void XoaNv()
		{
			int n = dsnv.size();
			int dem=0;
			int x;
			cout<<"nhap ma nhan vien can xoa : "; cin>>x;
			for(int i=0;i<n;i++)
			{
				if(dsnv[i].manv==x) 
				{
				dem++;
				dsnv.erase(dsnv.begin()+i);
				cout<<"--DA XOA NHAN VIEN THANH CONG----CHON 2 DE XEM DANH SACH SAU KHI XOA--"<<endl;
				break;
				}
			}
			if(dem==0) 
			{
			cout<<"Khong co nhan vien can xoa"<<endl;
			}
		}
		
		void capNhat()
		{
			int y,n = dsnv.size();
			int dem=0;
			cout<<"Nhap ma nhan vien can cap nhat : ";cin>>y;
			for(int i=0;i<n;i++)
			{
				if(dsnv[i].manv==y) 
				{
					dem++;
					int k;
					cout<<"Nhap so de thuc hien cap nhat voi so : \n1.Thay doi ten nhan vien \n2.Thay doi so ngay cong nhan vien \n3.Thay doi ma nhan vien nhan vien \n4.Ket thuc\n";cin>>k ;
					while(k==1||k==2||k==3)
					{
						if(k==1)
						{
							fflush(stdin);
							cout<<"nhap lai ten nhan vien : "; getline(cin,dsnv[i].hoten);
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi so ngay cong nhan vien \n3.Thay doi ma nhan vien nhan vien \n4.Ket thuc\n";cin>>k;
						}else
						if(k==2)
						{
							cout<<"nhap lai so ngay cong nhan vien : ";cin>>dsnv[i].songaycong;
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi so ngay cong nhan vien \n3.Thay doi ma nhan vien nhan vien \n4.Ket thuc\n";cin>>k;
						}else
						if(k==3)
						{
							cout<<"nhap lai ma nhan vien nhan vien : ";cin>>dsnv[i].manv;
							cout<<"ban can cap nhat gi them ? chon so : \n1.Thay doi ten nhan vien \n2.Thay doi so ngay cong nhan vien \n3.Thay doi ma nhan vien nhan vien \n4.Ket thuc\n";cin>>k;
						}
					}
					system("cls");
					cout<<"--DA CAP NHAT NHAN VIEN THANH CONG----CHON 2 DE XEM DANH SACH SAU KHI CAP NHAT--"<<endl;
				}
			}
			if(dem==0)
			{
				cout<<"Khong co nhan vien can cap nhat"<<endl;
			}

			
		}
		
		void inDS()
		{
			int n ;
			n=dsnv.size();
			cout<<"Ho ten nhan vien"<<"\t"<<"Ma nhan vien"<<"\t"<<"So ngay cong"<<"\t"<<"Luong"<<endl;
			for(int i=0;i<n;i++)
			{
				dsnv[i].InNv();
			}
		}
		void ghiDSnhanViencvaoFile()
		{
			//xoa toan bo du lieu trong file va ghi lai tu dau
			ofstream k("b3.txt");
			int n;
			n = dsnv.size();
			k<<n<<endl;
			for(int i=0;i<n;i++)
			{
				k<<dsnv[i].hoten<<endl;
				k<<dsnv[i].manv<<endl;
				k<<dsnv[i].songaycong<<endl;
			}
		}
			
};
int main()
{
	qlinhanvien ql;
	int k;
	cout<<"--------------------MENU---------------------"<<endl;
	cout<<"1.Nhap danh sach nhan vien tu File "<<endl;
	cout<<"2.In danh sach nhan vien"<<endl;
	cout<<"3.Sap xep danh sach nhan vien tang dan theo so ngay cong"<<endl;
	cout<<"4.Tim kiem theo ma nhan vien"<<endl;
	cout<<"5.Them 1 nhan vien vao cuoi danh sach"<<endl;
	cout<<"6.Xoa 1 nhan vien ra khoi danh sach theo ma nhap vao"<<endl;
	cout<<"7.Cap nhat thong tin nhan vien"<<endl;
	cout<<"0.Ket thuc"<<endl;
	cout<<"Nhap lua chon : "; cin>>k;
	
	while(k!=1)
	{
		system("cls");
		if(k==0)
		{
			system("cls");
			cout<<"-------------------KET THUC CHUONG TRINH------------------------"<<endl;
			exit(0);	
		}else
		cout<<"-------------------CHUA CO DANH SACH NHAN VIEN !!!------------------------"<<endl;
		cout<<"1.Nhap danh sach nhan vien tu File "<<endl;
		cout<<"2.In danh sach nhan vien"<<endl;
		cout<<"3.Sap xep danh sach nhan vien tang dan theo so ngay cong"<<endl;
		cout<<"4.Tim kiem theo ma nhan vien"<<endl;
		cout<<"5.Them 1 nhan vien vao cuoi danh sach"<<endl;
		cout<<"6.Xoa 1 nhan vien ra khoi danh sach theo ma nhap vao"<<endl;
		cout<<"7.Cap nhat thong tin nhan vien"<<endl;
		cout<<"0.Ket thuc"<<endl;
		cout<<"Nhap lua chon : "; cin>>k;
	}
	while(k==0||k==1||k==2||k==3||k==4||k==5||k==6||k==7)
	{
		if(k==1)
		{
			ql.docDSnhanVientuFile();
			system("cls");
			cout<<endl;
			cout<<"-------------------DA NHAP DANH SACH NHAN VIEN THANH CONG------------------------"<<endl;
		}else
		if(k==2)
		{
			system("cls");
			ql.inDS();
			cout<<"------------------------------------------------------------------"<<endl;
		}else
		if(k==3)
		{
			system("cls");
			ql.sapxep();
			cout<<endl;
			cout<<"--DA SAP XEP NHAN VIEN THANH CONG----CHON 2 DE XEM DANH SACH SAU SAP XEP--"<<endl;
		}else
		if(k==4)
		{
			system("cls");
			ql.timkiem();
		}
		else
		if(k==5)
		{
			system("cls");
			cout<<"Danh sach truoc khi them"<<endl;
			ql.inDS();
			ql.them();
			cout<<"--DA THEM NHAN VIEN THANH CONG----CHON 2 DE XEM DANH SACH SAU KHI THEM--"<<endl;
		}else
		if(k==6)
		{
			system("cls");
			ql.XoaNv();
			
		}else
		if(k==7)
		{
			system("cls");
			ql.capNhat();

		}else
		if(k==0)
		{
			ql.ghiDSnhanViencvaoFile();
			system("cls");
			cout<<"Da ghi tat ca ca thay doi vao FILE"<<endl;
			cout<<"-------------------KET THUC CHUONG TRINH------------------------"<<endl;
			exit(0);	
		}
		
	
		cout<<"1.Nhap danh sach nhan vien tu File "<<endl;
		cout<<"2.In danh sach nhan vien"<<endl;
		cout<<"3.Sap xep danh sach nhan vien tang dan theo so ngay cong"<<endl;
		cout<<"4.Tim kiem theo ma nhan vien"<<endl;
		cout<<"5.Them 1 nhan vien vao cuoi danh sach"<<endl;
		cout<<"6.Xoa 1 nhan vien ra khoi danh sach theo ma nhap vao"<<endl;
		cout<<"7.Cap nhat thong tin nhan vien"<<endl;
		cout<<"0.Ket thuc"<<endl;
		cout<<"Nhap lua chon : "; cin>>k;
	}
	system("pause");
	
	
}
