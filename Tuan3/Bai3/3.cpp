#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

// define
class NhanVien {
    public:
        int nhanVienId;
        string hoTen;
        int soNgayCong;
        int luong() {
            return this->soNgayCong * 300000;
        }
        void nhapNV();
        void inNV();
    friend class DSNV;
};
class DSNV: public NhanVien {
    public:
        int n; // so luong nhan vien
        vector<NhanVien> dsnv;
        void nhapDSNV();
        void inDSNV();
        void sapXep();
        int timKiem(int nvID);
        bool themNhanVien(NhanVien nv);
        void xoaNhanVien(int nv);
        void suaNhanVien(int nvID);
};
DSNV ds;

void showMenu();
void menuOption();
void readFile();
void thoat();
void quayLaiMenu();

int main() {
    showMenu();
    menuOption();
}

// nhap thong tin nhan vien
void NhanVien::nhapNV() {
    cout << "Ma nhan vien: "; cin >> nhanVienId;
    cin.ignore();
    cout << "Ho ten nhan vien: "; getline(cin, hoTen);
    cout << "Ngay cong: "; cin >> soNgayCong;
}
// in thong tin nhan vien
void NhanVien::inNV() {
    cout << nhanVienId << "\t\t" << hoTen << "\t" << soNgayCong << "\t\t" << luong() << endl;
}
// nhap danh sach nhan vien
void DSNV::nhapDSNV() {
    cout << "Nhap so luong nhan vien: "; cin >> n;
    dsnv.resize(n);
    for(int i = 0; i < n; i++) {
        cout << "Nhan vien thu " << i + 1 << endl;
        dsnv[i].nhapNV();
    }
}
// in danh sach nhan vien
void DSNV::inDSNV() {
    cout << "Danh sach nhan vien" << endl;
    cout << "Ma nhan vien" << "\tHo ten" << "\t\t\tSo ngay cong" << "\tLuong" << endl;
    for(int i = 0; i < n; i++) {
        dsnv[i].inNV();
    }
}
// sap xep danh sach nhan vien theo ngay cong
void DSNV::sapXep() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(dsnv[i].soNgayCong > dsnv[j].soNgayCong) {
                NhanVien tmp = dsnv[i];
                dsnv[i] = dsnv[j];
                dsnv[j] = tmp;
            }
        }
    }
}
// tim kiem nhan vien theo ma
int DSNV::timKiem(int nvID) {
    for(int i = 0; i < n; i++) {
        if(dsnv[i].nhanVienId == nvID)
            return i;
    }
    return -1;
}
// them nhan vien
bool DSNV::themNhanVien(NhanVien nv) {
    for(int i = 0; i < n; i++) {
        if(dsnv[i].nhanVienId == nv.nhanVienId)
            return false;
    }
    dsnv.push_back(nv);
    n++;
    return true;
}
// xoa nhan vien
void DSNV::xoaNhanVien(int nvID) {
    for(int i = 0; i < n; i++) {
        if(dsnv[i].nhanVienId == nvID) {
            dsnv.erase(dsnv.begin() + i);
            cout << "Da xoa nhan vien" << endl;
            // i--;
            break;
        }
    }
    n = dsnv.size();
}
// sua thong tin nhan vien
void DSNV::suaNhanVien(int nvID) {
    NhanVien tmp;
    int i = timKiem(nvID);
    if(i != -1) {
        cout << "Ho ten: ";
        cin.ignore(); getline(cin, tmp.hoTen);
        cout << "So ngay cong: "; cin >> tmp.soNgayCong;
        if(tmp.hoTen != "") {
            dsnv[i].hoTen = tmp.hoTen;
        }
        if(tmp.soNgayCong >= 0) {
            dsnv[i].soNgayCong = tmp.soNgayCong;
        }
        cout << "Da thay doi thong tin nhan vien" << endl;
    } else {
        cout << "Khong tim thay nhan vien" << endl;
    }
}

// hien thi menu
void showMenu() {
    system("cls");
    cout << "\n\n";
    cout << "\t\t\t\t1 : Nhap danh sach nhan vien" << endl;
    cout << "\t\t\t\t2 : In danh sach nhan vien" << endl;
    cout << "\t\t\t\t3 : Sap xep danh sach nhan vien" << endl;
    cout << "\t\t\t\t4 : Tim kiem nhan vien" << endl;
    cout << "\t\t\t\t5 : Them nhan vien" << endl;
    cout << "\t\t\t\t6 : Xoa nhan vien" << endl;
    cout << "\t\t\t\t7 : Cap nhat thong tin nhan vien" << endl;
    cout << "\t\t\t\t8 : Doc du lieu tu file" << endl;
    cout << "\t\t\t\t9 : Thoat" << endl;
}
// lua chon tren menu
void menuOption() {
    int option;
    cout << "\t\t\t\tNhap lua chon: "; cin >> option;
    int i, nvID;
    NhanVien tmp;
    switch(option) {
        case 1:
            system("cls");
            ds.nhapDSNV();
            quayLaiMenu();
            break;
        case 2:
            system("cls");
            ds.inDSNV();
            quayLaiMenu();
            break;
        case 3:
            system("cls");
            ds.sapXep();
            ds.inDSNV();
            quayLaiMenu();
            break;
        case 4:
            system("cls");
            cout << "Nhap vao ma nhan vien: ";
            cin >> nvID;
            i = ds.timKiem(nvID);
            if(i != -1) {
                ds.dsnv[i].inNV();
            } else {
                cout << "Khong tim thay nhan vien" << endl;
            }
            quayLaiMenu();
            break;
        case 5:
            system("cls");
            cout << "Ma nhan vien moi: "; cin >> tmp.nhanVienId;
            cout << "Ho ten moi: "; cin.ignore(); getline(cin, tmp.hoTen);
            cout << "Ngay cong moi: "; cin >> tmp.soNgayCong;
            ds.themNhanVien(tmp);
            quayLaiMenu();
            break;
        case 6:
            system("cls");
            cout << "Ma nhan vien can xoa: "; cin >> nvID;
            ds.xoaNhanVien(nvID);
            quayLaiMenu();
            break;
        case 7:
            system("cls");
            cout << "Ma nhan vien can sua: "; cin >> nvID;
            ds.suaNhanVien(nvID);
            quayLaiMenu();
            break;
        case 8:
            system("cls");
            readFile();
            quayLaiMenu();
            break;
        case 9:
            thoat();
            break;
        default:
            showMenu();
            cout << "Lua chon khong hop le!" << endl;
            menuOption();
    }
}
void readFile() {
    system("cls");

    string filename;
    cin.ignore();
    cout << "Nhap vao ten file: "; getline(cin, filename);
    fstream myfile;
    myfile.open(filename);
    int i = 0;
    if(myfile.is_open()) {
        while(!myfile.eof()) {
            ds.dsnv.resize(i + 1);
            string line;
            // ma nhan vien
            getline(myfile, line);
            ds.dsnv[i].nhanVienId = atoi(line.c_str());
            // ho ten
            getline(myfile, line);
            ds.dsnv[i].hoTen = line;
            // so ngay cong
            getline(myfile, line);
            ds.dsnv[i].soNgayCong = atoi(line.c_str());
            i++;
        } ds.n = ds.dsnv.size();
        cout << "Da doc xong du lieu tu file" << endl;
    } else {
        cout << "Khong doc duoc file!" << endl;
    }
}
void thoat() {
    cout << "Tam biet, hen gap lai" << endl;
}
void quayLaiMenu() {
    cout << "Nhan phim bat ky de quay lai menu...";
    string nothing;
    cin.ignore();
    getline(cin, nothing);
    showMenu();
    menuOption();
}