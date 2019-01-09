#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct nhan_vien
{
	int ma;
	int so_ngay_cong;
	int luong;
	string ho_ten;
};

int n;
nhan_vien nv;
vector <nhan_vien> ds;

// Hien thi menu
void menu()
{
	cout << "________________ Menu __________________"<<endl;
	cout << "1.Nhap thong tin nhan vien." << endl;
	cout << "2.In ra danh sach thong tin nhan vien."<<endl;
	cout << "3.Sap xep danh sach tang dan theo so ngay cong."<<endl;
	cout << "4.Tim kiem theo ma nhan vien." << endl;
	cout << "5.Them moi 1 nhan vien vao cuoi danh sach." << endl;
	cout << "6.Xoa 1 nhan vien ra khoi danh sach theo ma nhap vao."<<endl;
	cout << "7.Cap nhap thong tin nhan vien."<<endl;
	cout << "8.Thoat."<<endl;
	cout << "----------------------------------------"<<endl;
}

// Nhap thong tin nhan vien
void nhap(nhan_vien &nv)
{
	cout<<"Ho ten: ";
	cin.ignore();
	getline(cin,nv.ho_ten);
	cout<<"Ma: ";
	cin>>nv.ma;
	cout<<"So ngay cong: ";
	cin>>nv.so_ngay_cong;
	nv.luong = nv.so_ngay_cong * 300000;
	cout <<"Luong: "<< nv.luong<<endl;
}

void nhap_ds_nhan_vien(vector <nhan_vien> &ds, int &n)
{
	do
	{
		cout << "Nhap vao so luong nhan vien: " ;
		cin >> n;	
	}
	while (n>10);
	ds.resize(n);
	for(int i=0;i<ds.size();i++)  // cho vong lap chay tu dau toi cuoi danh sach
	{
		nhap(ds[i]);
	}
}

void in_mot_nv(nhan_vien nv)
{
	cout << "Ho ten: "<< nv.ho_ten<<endl;
	cout << "Ma: "<<nv.ma<<endl;
	cout << "So ngay cong: "<<nv.so_ngay_cong<<endl;
	cout << "Luong: "<<nv.luong<<endl;
}

void in_ds(vector <nhan_vien> ds)
{
	cout << "_________________________"<<endl;
	cout << "Danh sach thong tin nhan vien hien co: "<<endl;
	for (int i=0; i<ds.size(); i++)
	{
		in_mot_nv(ds[i]);
	}
}

void sap_xep()
{
	int size = ds.size();
	for (int i=0; i<size-1; i++)
	{
		for (int j=i+1; j<size; j++)
		{
			if (ds[i].so_ngay_cong > ds[j].so_ngay_cong)
			{
				swap (ds[i], ds[j]);
			}
		}
	}
	cout << "Danh sach nhan vien sau khi sap xep."<<endl;
	in_ds(ds);
}

int  kiemTra(vector<nhan_vien> ds, int manv) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
{	
	for(int i=0;i<ds.size();i++)
	{
		if(ds[i].ma==manv)
		return i;
	}
	return -1;
}

void tim_kiem(vector <nhan_vien> ds)
{
	nhan_vien nv;
	int manv,x;
	cout<<"Nhap ma nhan vien can tim: ";
	cin>>manv;
	if(kiemTra(ds,manv)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Ma nhan vien vua nhap khong ton tai."<<endl;
	}
	else 
	{
		x=kiemTra(ds,manv);
		cout<<"============================"<<endl;
		cout<<"Thong tin nhap vien can tim: "<<endl;
		in_mot_nv(ds[x]);
	}
}

void them_nv(vector<nhan_vien> &ds)
{
	nhan_vien nv;
	nhap(nv);
	if(kiemTra(ds,nv.ma)==-1)//Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		ds.push_back(nv); 
	}
	else 
		cout<<"Ma nhan vien da ton tai"<<endl;
}

void xoa_nv(vector <nhan_vien> &ds)
{	
	int x, manv;
	nhan_vien nv;
	cout<<"Nhap ma nhan vien can xoa:";
	cin>>manv;
	if(kiemTra(ds,manv)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Ma nhan vien khong ton tai"<<endl;
	}
	else 
	{	
		x=kiemTra(ds,manv);
		ds.erase(ds.begin()+x); // xoa phan tu tai vi tri x
	}
}

void capNhat(vector <nhan_vien> &ds)
{	
	nhan_vien nv;
	int manv, x;
	cout<<"Nhap ma nhan vien can cap nhat: ";
	cin>>manv;
	if(kiemTra(ds,manv)==-1) //Kiem tra ma nhan vien moi nhap co trung voi ma nhan vien da co trong danh sach chua
	{
		cout<<"Khong tim thay nhan vien co ma nay."<<endl;
	}
	else 
	{	
		x=kiemTra(ds,manv);
		cout<<"Ho ten:";
		cin.ignore();
		getline(cin,nv.ho_ten); // nhan khoang trang 
		cout<<"So ngay cong: ";
		cin>>nv.so_ngay_cong;
		cout << "Luong: "<<nv.so_ngay_cong*300000<<endl;
		ds[x].ho_ten=nv.ho_ten; 
		ds[x].so_ngay_cong=nv.so_ngay_cong;
	}
}

void chon(vector<nhan_vien> &ds)
{
	int select;
	cout << "Nhap vao lua chon cua ban:";
	cin >> select;
	if (select != 1 && n==0)
	{
		system("cls");
		cout << "Chua co thong tin nhan vien, moi ban nhap thong tin nhan vien."<<endl;
		menu();
		chon(ds);
	}
	else
	{
		switch (select)
		{
			case 1:
				nhap_ds_nhan_vien(ds, n);
				chon(ds);
				break;
			case 2:
				in_ds(ds);
				chon(ds);
				break;
			case 3:
				sap_xep();
				chon(ds);
				break;
			case 4:
				tim_kiem(ds);
				chon(ds);
				break;
			case 5:
				them_nv(ds);
				chon(ds);
				break;
			case 6:
				xoa_nv(ds);
				chon(ds);
				break;
			case 7:
				capNhat(ds);
				chon(ds);
				break;
			case 8:
				exit(0);
				break;
		}
	}
}

int main ()
{
	vector <nhan_vien> employee;
	menu();
	chon(employee);
}
