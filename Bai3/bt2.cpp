#include<iostream>
#include<string.h>

using namespace std;
class NhanVien{
	char NhanVien [3];
	char hoTen [20];
	int MaNV;
	int tuoi;
	float luong;
};
class QLnhanvien{
	int n;

	
		private:
		bool themNV();
		void xoaNV();
		void capnhatNV();
		NhanVien nhapNVTuBP();
		void docDSnvTuFile();
		void ghiNVTuFile();
		void inDSNV();
		};
		public:
 int Nhap()
{
        cout<<"Nhap ma nv: "; cin>>maso;
        hoten  = new char[25];
        cout<<"Nhap ho ten: "; cin.get(hoten,25);
        cout<<"Nhap luong: "; cin>>luong;
        tiep = NULL;
    }
int Xuat() {
			cout<<" ten nv : "<<hoTen<<endl;

			cout<<" ma nhan vien : "<<MaNV<<endl;

			cout<<" luong nv : "<<luong<<endl;;

		}
class QLNhanVien {
//	 quan li so nhan vien
	private:
		int sonhanVien;
		NhanVien *st, temp;
	public:
		void nhapTT() {
			cout << "Nhap so Nhan vien:";
			cin >> soNhanVien;
			cin.ignore();    //fflush(stdin);

			st = new NhanVien[soNhanVien];

			for(int i = 0; i < soNhanVien; i++) {
				cout<<"Nhap so nhan vien "<<i+1<<endl;
				st[i].Nhap();
			}
		}
void xuatTT() {
			for(int i = 0; i < soNhanVien; i++) {
				cout<<"so nhan vien " <<i+1<<endl;
				st[i].Xuat();
				cout << "ten nv:"<< st[i].hoTen()<<endl;
				cout << "ma nv:" << st[i].MaNV() << endl;
				cout << "ma nv:" << st[i].MaNV() << endl;
				cout<<"=====================================\n";
			}
		}
int main(){
	QLnhanvien ds;
	ds. Nhap();
	ds. Xuat();
	}
