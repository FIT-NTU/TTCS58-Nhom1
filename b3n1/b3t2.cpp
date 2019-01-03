#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream t("b1.txt");
ifstream g("b2.txt");
ifstream f("b3.txt");
ifstream m("tl1.txt");
ifstream u("tl2.txt");
ifstream a("tl3.txt");
ofstream l("luu.txt");
int k;
int dem=0;
class de{
	protected:
	int cau;
	string cauhoi;
	string tl1,tl2,tl3,tl4;
	int cautraloi;
	public:

		void xuat()
		{
			cout<<"Cau "<<cau<<" :"<<endl;
			cout<<cauhoi<<endl;
			cout<<"1."<<tl1<<endl;
			cout<<"2."<<tl2<<endl;
			cout<<"3."<<tl3<<endl;
			cout<<"4."<<tl4<<endl;
		}
	friend class bode;
	
};

class bode{
	vector<de> ds;
	public:
		void nhapds()
		{
			int n;
			string s;
			cout<<"Chon bo de ban muon thuc hien\nNhap 1 de chon bo de so 1 \nNhap 2 de chon bo de so 2 \nNhap 3 de chon bo de so 3\n";cin>>k;
			if(k==3)
			{
			getline(f , s) ; n = atoi(s.c_str());
			ds.resize(n);
			n=ds.size();
			for(int i=0;i<n;i++)
			{
			 	string s;
				getline(f , s) ; ds[i].cau = atoi(s.c_str());
				getline(f , s) ; ds[i].cauhoi = s ;
				getline(f , s) ; ds[i].tl1 = s ;
				getline(f , s) ; ds[i].tl2 = s ;
				getline(f , s) ; ds[i].tl3 = s ;
				getline(f , s) ; ds[i].tl4 = s ;
			} 
			}else
			if(k==2)
			{
			getline(g , s) ; n = atoi(s.c_str());
			ds.resize(n);
			n=ds.size();
			for(int i=0;i<n;i++)
			{
				string s;
			 	getline(g , s) ; ds[i].cau = atoi(s.c_str());
				getline(g , s) ; ds[i].cauhoi = s ;
				getline(g , s) ; ds[i].tl1 = s ;
				getline(g , s) ; ds[i].tl2 = s ;
				getline(g , s) ; ds[i].tl3 = s ;
				getline(g , s) ; ds[i].tl4 = s ;
			} 
			}else
			if(k==1)
			{
			getline(t , s) ; n = atoi(s.c_str());
			ds.resize(n);
			n=ds.size();
			for(int i=0;i<n;i++)
			{
				string s;
			 	getline(t , s) ; ds[i].cau = atoi(s.c_str());
				getline(t , s) ; ds[i].cauhoi = s ;
				getline(t , s) ; ds[i].tl1 = s ;
				getline(t , s) ; ds[i].tl2 = s ;
				getline(t , s) ; ds[i].tl3 = s ;
				getline(t , s) ; ds[i].tl4 = s ;
			} 
			}else cout<<"Khong co bo de can nhap !"<<endl ;
		}
		void xuatds()
		{
			if(k==3)
			{
			int n;
			n=ds.size();
			for(int i=0;i<n;i++)
			{
				ds[i].xuat();
				int ctl;
				string s;
				cout<<"Chon cau tra loi : ";cin>>ctl;
				getline(a , s) ; ds[i].cautraloi = atoi(s.c_str());
				a.close();
				if(ctl==ds[i].cautraloi) 
				{
					dem++;
				//	cout<<"ban tra loi dung "<<endl;
				}//else cout<<"ban tra loi sai "<<endl;	
			}
			//l<<"so cau tra loi dung : "<<dem<<endl;
			}
			if(k==2)
			{
			int n;
			n=ds.size();
			for(int i=0;i<n;i++)
			{
				ds[i].xuat();
				int ctl;
				string r;
				cout<<"Chon cau tra loi : ";cin>>ctl;
				getline(u , r) ; ds[i].cautraloi = atoi(r.c_str());
				if(ctl==ds[i].cautraloi) 
				{
					dem++;
				//	cout<<"ban tra loi dung "<<endl;
				}//else cout<<"ban tra loi sai "<<endl;
					
			}
			//l<<"so cau tra loi dung : "<<dem<<endl;
			}
			if(k==1)
			{
			int n;
			n=ds.size();
			for(int i=0;i<n;i++)
			{
			ds[i].xuat();
				int ctl;
				string s;
				cout<<"Chon cau tra loi : ";cin>>ctl;
				getline(m , s) ; ds[i].cautraloi = atoi(s.c_str());
				if(ctl==ds[i].cautraloi) 
				{
					dem++;
				//	cout<<"ban tra loi dung "<<endl;
				}//else cout<<"ban tra loi sai "<<endl;
					
			}
			
			}
					
		}
		void luudiem()
		{
			l<<"so cau tra loi dung : "<<dem<<endl;
		}
		void xemdiem()
		{
			cout<<"so diem nguoi choi dat duoc : "<<dem<<endl;
		}
};

int main()
{
	int w;
	bode bd;
	cout<<"Vui long chon so de chon cong viec thuc hien "<<endl;
	cout<<"Chon 1. De chon bo de"<<endl;
	cout<<"Chon 2. De tra loi cau hoi"<<endl;
	cout<<"Chon 3. De luu diem"<<endl;
	cout<<"Chon 4. De xem diem"<<endl;
	cout<<"Chon 0. De ket thuc"<<endl;
	cout<<"Nhap so : ";cin>>w;
	
	while(w!=1)
	{
		if(w==0) break;
		if(w==4) 
		{
			bd.xemdiem();
			break;
		}
		cout<<"Chua chon bo de !!!"<<endl;
		cout<<"Vui long chon lai so de chon cong viec thuc hien "<<endl;
		cout<<"Chon 1. De chon bo de"<<endl;
		cout<<"Chon 2. De tra loi cau hoi"<<endl;
		cout<<"Chon 3. De luu diem"<<endl;
		cout<<"Chon 4. De xem diem"<<endl;
		cout<<"Chon 0. De ket thuc"<<endl;
		cout<<"Nhap so : ";cin>>w;
		
	}
	
	while(w==1||w==2||w==3||w==4)
	{
		if(w==1)
		{
			bd.nhapds();
			cout<<"da chon bo de so : "<<k<<endl;
		}else
		if(w==2)
		{
			bd.xuatds();
		}else
		if(w==3)
		{
			bd.luudiem();
		}
		if(w==4)
		{
			bd.xemdiem();
		}
		cout<<"Vui long chon so de chon cong viec thuc hien "<<endl;
		cout<<"Chon 1. De chon bo de"<<endl;
		cout<<"Chon 2. De tra loi cau hoi"<<endl;
		cout<<"Chon 3. De luu diem"<<endl;
		cout<<"Chon 4. De xem diem"<<endl;
		cout<<"Chon 0. De ket thuc"<<endl;
		cout<<"Nhap so : ";cin>>w;
	}
	
	system("pause");
}
