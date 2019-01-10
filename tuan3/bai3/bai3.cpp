#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
int n;
struct nhanvien{
	int songay,ma;
	int luong;
	string ten;
};
typedef struct nhanvien nv;
void nhap(nhanvien &nv)
{
		cout<<"nhap ten nhan vien: ";
		cin.ignore();
		getline(cin,nv.ten);
		cout<<"nhap ma nhan vien: ";
		cin>>nv.ma;
		cout<<" nhap so ngay lam: ";
		cin>>nv.songay;
		nv.luong=nv.songay*300000;
		
}
void nhapDS(vector<nv> &ds)
{	
	cout<<"nhap so luong nhan vien: ";
	cin>>n;
	ds.resize(n);
	for(int i=0;i<ds.size();i++)
	{
		nhap(ds[i]);
	}
}
void xuat(nhanvien nv)
{
	
		cout<<"ten nhan vien: "<<nv.ten<<endl;
		cout<<"ma nhan vien: "<<nv.ma<<endl;
		cout<<"so ngay lam nhan vien: "<<nv.songay<<endl;
		cout<<"luong co ban: "<<nv.luong<<endl;
}
void xuatDS(vector<nv> ds)
{	
	for(int i=0;i<ds.size();i++)
	{
		xuat(ds[i]);
	}
}
// sap xep thong tin theo so ngay tu be den lon;
void sapxep(vector<nv> &ds)
{

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ds[i].songay > ds[j].songay)
			{
				swap(ds[i],ds[j]);	
			}
		}	
	}
	xuatDS(ds);
}
// kiem tra nhan vien co xuat hien hay ko
int  kt(vector<nv> ds,int manv)
{	
	for(int i=0;i<ds.size();i++)
	{
		if(ds[i].ma==manv)
		return i;
	}
	return -1;

}
//tim nhan vien
void tim(vector <nv> ds)
{	
	nhanvien nv;
	int manv,x;
	cout<<"nhap ma nhan vien can tim: ";
	cin>>manv;
	if(kt(ds,manv)==-1)   // goi lai ham kt de kiem tra ma nv có xuat hien ko
	{
		cout<<"ko co nhan vien can tim:"<<endl;
	}else x=kt(ds,manv);
	cout<<"=====*****thong tin nhap vien can tim*****==== "<<endl;
	xuat(ds[x]);
}
//them nhan vien
void themnv(vector<nv> &ds)
{	
	ds.resize(n);
	nhanvien nv;
	nhap(nv);
	if(kt(ds,nv.ma)==-1)
	{
		ds.push_back(nv);
		xuatDS(ds);
	}
	else cout<<"!>>thong tin bi trung<<!";
}
//xoa nhan vien theo ma
void xoa(vector <nv> &ds)
{	
	int x,manv;
	nhanvien nv;
	cout<<"nhap ma nhan vien can xoa:";
	cin>>manv;
	if(kt(ds,manv)==-1)   //goi lai ham kt de kiem tra ma nv có xuat hien ko
	{
		cout<<"ko co ma nhan vien nay"<<endl;
	}
	else {	
			x=kt(ds,manv);
			ds.erase(ds.begin()+x);
		}
}
// kiem tra dieu kien sau do sua
void sua(vector <nv> &ds)
{	
	nhanvien nv;
	int manv,x;
	cout<<"nhap ma nhan vien can sua: ";
	cin>>manv;
	if(kt(ds,manv)==-1)
	{
		cout<<"ko co ma nhan vien nay";
	}
	else {	
			x=kt(ds,manv);
			cout<<"nhap ten nhan vien:";
			cin.ignore();
			getline(cin,nv.ten);
			cout<<"nhap ma nhan vien: ";
			cin>>nv.ma;
			cout<<"nhap so ngay lam :";
			cin>>nv.songay;
			ds[x].ten=nv.ten;
			ds[x].ma=nv.ma;
			ds[x].songay=nv.songay;
		}
}
void menu()
{
	cout<<"==============*****MENU*****=================="<<endl;
	cout<<"1.nhap thong tin nhan vien"<<endl;
	cout<<"2.in ra danh sach nhan vien "<<endl;
	cout<<"3.sap xep danh sach tang dan theo so ngay lam"<<endl;
	cout<<"4.tim kiem theo ma nhan vien"<<endl;
	cout<<"5.them nhan vien vao cuoi danh sach "<<endl;
	cout<<"6.xoa nhan vien theo ma"<<endl;
	cout<<"7.cap nhat thong tin nhan vien"<<endl;
}
 void chon(vector <nv> &ds)
 {
 	menu();
	int b ;
	cout<<"==========="<<"chon cac muc trong menu phia tren"<<"==========="<<endl;
	cout<<"--CHON SO TREN MENU--:";
	cin>>b;
 	switch(b)
	{					
		case 1: 
				system("cls");
				 nhapDS(ds);
				 chon(ds);
			break;
		case 2 :
				system("cls");
				cout<<"=====*****thong tin nhan vien vua nhap****========="<<endl;
				xuatDS(ds);
				chon(ds);
			break;
		case 3:	
				system("cls");
				cout<<"========******danh sach sau khi sap xep theo so ngay lam******========="<<endl;
				sapxep(ds);
				chon(ds);	
			break;
		case 4:
			system("cls");
				tim(ds);
				chon(ds);	
			break;
		case 5:
			system("cls");
				themnv(ds);
				chon(ds);
			break;	
		case 6:
			system("cls");
				xoa(ds);
				cout<<"++++++++++++***danh sach nhan vien sau khi xoa***+++++++++++++"<<endl;
				xuatDS(ds);
				chon(ds);
			break;	
		case 7:
			system("cls");
			sua(ds);
			cout<<"++++++++*****danh sach nhan vien sau khi cap nhat****++++++++++++++"<<endl;
			xuatDS(ds);
			break;	
		default:
					cout<<"ban nhap ko hop le"<<endl<<"--------"<<"moi ban nhap lai"<<"--------"<<endl;	
						
					
	}	
 }
int main()
{
	vector <nv> ds_l;
	chon(ds_l);
//	nhapDS(ds_l);
//	xuatDS(ds_l);
//	cout<<endl;
//	cout<<"sau khi sap xep"<<endl;
//	sapxep(ds_l);
//	cout<<endl;
//	tim(ds_l);
//	cout<<endl;
//	themnv(ds_l);
//	cout<<endl;
//	xoa(ds_l);
//	xuatDS(ds_l);
//	cout<<endl;
//	sua(ds_l);
//	xuatDS(ds_l);
}
