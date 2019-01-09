#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include <stdlib.h>
#define cachso 5
#define cachten 10
#define cach ' '
#include <iomanip>
 
 using namespace std;
 
 struct NhanVien{
 	int MaNhanVien;
 	string HoLot;
 	string Ten;
 	int Luong;
 }
 NVFind, NVMax, NVMin;
 
 class DSNhanVien{
 	public:
	int n;
 	vector<NhanVien> ds;
 	void NhapDS();
 	void XuatDS();
 	NhanVien TimNV();
    NhanVien LuongMax();
    NhanVien LuongMin();
 	void SapXep();
 };
 
 int chon;
 DSNhanVien DSNV;
 int TroVe;
 
void ShowMenu();
void LuaChon();
void NhapDS();
void XuatDS();
void LuuVaoFile(DSNhanVien DSNV);
void SapXep();
void LuuKQFile(NhanVien NVFind, NhanVien NVMax, DSNhanVien DSNV);
bool TroVeMenu();
void readFile();



int main() {
    ShowMenu();
    LuaChon();

}

 void ShowMenu(){
 	cout<< "0. nhap nv tu file"<< endl;
 	cout<< "1.nhap nhan vien tu ban phim"<< endl;
 	cout<< "2.tim nhan vien"<< endl;
 	cout<< "3.nhan vien co luong cao nhat va thap nhat"<< endl;
 	cout<< "4.xap sep nhan vien"<< endl;
 	cout<< "5. luu ket qua"<< endl;
 	cout<< "6.exit "<<endl;
 }
 
 void LuaChon(){
 	cout<< "hay nhan chon yeu cau"<< endl;
 	cin>> chon;
 	switch(chon){
 		case 0:
 			system("cls");
 			readFile();
 			 if(TroVeMenu())
			   {
                system("cls");
                ShowMenu();
                LuaChon();
            	}
			else
			   {
           	    cout << "Exited" << endl;
       			}
            break;
 		case 1:
 			system("cls");
 			DSNV.NhapDS();
 			 LuuVaoFile(DSNV);
 			 if(TroVeMenu())
			   {
                system("cls");
                ShowMenu();
                LuaChon();
            	}
			else
			   {
           	    cout << "Exited" << endl;
       			}
            break;
 		case 2:
            system("cls");
            NVFind = DSNV.TimNV();
            if(NVFind.MaNhanVien) {
            	cout << left << setw(cachso) << setfill(cach) << "Ma";
	cout << left << setw(cachten) << setfill(cach) << "Ho";
	cout << left << setw(cachten) << setfill(cach) << "Ten";
	cout << left << setw(cachso) << setfill(cach) << "Luong";
	cout << endl;

		cout << left << setw(cachso) << setfill(cach) << NVFind.MaNhanVien;
		cout << left << setw(cachten) << setfill(cach) << NVFind.HoLot;
		cout << left << setw(cachten) << setfill(cach) << NVFind.Ten;
		cout << left << setw(cachso) << setfill(cach) << NVFind.Luong;
		cout << endl;

                
            } else {
                cout << "======================" << endl;
                cout << "ko tim thay" << endl;
            }
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 3:
            system("cls");
            NVMax = DSNV.LuongMax();
            NVMin =DSNV.LuongMin();
            if(NVMax.MaNhanVien) {
                // block empty list
                cout << "nhan vien co luong cao nhat : " << endl;
               	cout << left << setw(cachso) << setfill(cach) << "Ma";
	cout << left << setw(cachten) << setfill(cach) << "Ho";
	cout << left << setw(cachten) << setfill(cach) << "Ten";
	cout << left << setw(cachso) << setfill(cach) << "Luong";
	cout << endl;

		cout << left << setw(cachso) << setfill(cach) << NVMax.MaNhanVien;
		cout << left << setw(cachten) << setfill(cach) << NVMax.HoLot;
		cout << left << setw(cachten) << setfill(cach) << NVMax.Ten;
		cout << left << setw(cachso) << setfill(cach) << NVMax.Luong;
		cout << endl;
            } else {
                cout << "======================" << endl;
                cout << "ko tim thay" << endl;
            }
            if(NVMin.MaNhanVien) {
                // block empty list
                cout << "Nhan Vien co luong thap nhat: " << endl;
                	cout << left << setw(cachso) << setfill(cach) << "Ma";
	cout << left << setw(cachten) << setfill(cach) << "Ho";
	cout << left << setw(cachten) << setfill(cach) << "Ten";
	cout << left << setw(cachso) << setfill(cach) << "Luong";
	cout << endl;

		cout << left << setw(cachso) << setfill(cach) << NVMin.MaNhanVien;
		cout << left << setw(cachten) << setfill(cach) << NVMin.HoLot;
		cout << left << setw(cachten) << setfill(cach) << NVMin.Ten;
		cout << left << setw(cachso) << setfill(cach) << NVMin.Luong;
		cout << endl;
               
            } else {
                cout << "======================" << endl;
                cout << "ko tim thay" << endl;
            }
            
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 4:
            	system("cls");
            	DSNV.SapXep();
            cout << "sau khi sap xep" << endl;
            DSNV.XuatDS();
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 5:
            LuuKQFile(NVFind, NVMax, DSNV);
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 6:
            	cout << "\t\t\t\t  Exited" << endl;
            	break;
	 }
 }
 
 void readFile() {
    ifstream h;
    h.open("input3.txt");
    
    if(h.is_open()) {
    	cout<<"da doc file:";
        string line;
        int i = 0;
        int tmp;
        while(getline(h, line)) {
            tmp = i / 4;
            DSNV.ds.resize(tmp + 1);
            switch(i % 4) {
                case 0:
                    DSNV.ds[tmp].MaNhanVien = atoi(line.c_str());
                    i++;
                    break;
                case 1:
                    DSNV.ds[tmp].HoLot = line;
                    i++;
                    break;
                case 2:
                    DSNV.ds[tmp].Ten = line;
                    i++;
                    break;
                case 3:
                    DSNV.ds[tmp].Luong = atoi(line.c_str());
                    i++;
                    break;
            }
        } DSNV.n = tmp + 1;
    } else {
        
    }

    h.close();
}
 
 void DSNhanVien::NhapDS(){
 	cout<< "nhap so luong nhan vien:  "; cin>>n;
 	ds.resize(n);
 	for(int i = 0; i < n; i++){
 		cout<< "--------------------"<< endl;
 		fflush(stdin);
 		cout<< "nhap ma nhan vien: ";
		 fflush(stdin); cin>>ds[i].MaNhanVien;
 		cout<< "nhap ho Lot: ";
		 fflush(stdin); getline(cin, ds[i].HoLot);
 		cout<< " nhap ten nhan vien: "; 
		 fflush(stdin); getline(cin, ds[i].Ten);
		cout<< "nhap luong nhan vien: "; 
		 cin>> ds[i].Luong; 
	 }
 }
 
 void DSNhanVien::XuatDS(){
 	cout << left << setw(cachso) << setfill(cach) << "Ma";
	cout << left << setw(cachten) << setfill(cach) << "Ho";
	cout << left << setw(cachten) << setfill(cach) << "Ten";
	cout << left << setw(cachso) << setfill(cach) << "Luong";
	cout << endl;
	for (int i=0; i<n; i++)
	{
		cout << left << setw(cachso) << setfill(cach) << ds[i].MaNhanVien;
		cout << left << setw(cachten) << setfill(cach) << ds[i].HoLot;
		cout << left << setw(cachten) << setfill(cach) << ds[i].Ten;
		cout << left << setw(cachso) << setfill(cach) << ds[i].Luong;
		cout << endl;
	}
 }
 
 NhanVien DSNhanVien::TimNV() {
    int MaNhanVien;
    cout << "Nhap ma nv can find: > "; cin >> MaNhanVien;

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(ds[i].MaNhanVien == MaNhanVien) {
            return ds[i];
        }
    }
    return NVFind;
}

NhanVien DSNhanVien::LuongMax(){
    if(ds.size()) {
        int Max = ds[0].Luong;
        int tam = 0;
        for(int i = 1; i < n; i++) {
            if(ds[i].Luong > Max) {
                Max = ds[i].Luong;
                tam = i;
            }
        }
        return ds[tam];
    } else {
        return NVMax;
    } 
} 
NhanVien DSNhanVien::LuongMin(){
    if(ds.size()) {
        int Min = ds[0].Luong;
        int tam = 0;
        for(int i = 1; i < n; i++) {
            if(ds[i].Luong < Min) {
                Min = ds[i].Luong;
                tam = i;
            }
        }
        return ds[tam];
    } else {
        return NVMin;
    } 
} 

void DSNhanVien::SapXep() {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            if(ds[i].Ten.compare(ds[j].Ten) > 0) {
                // if ds[i].Ten > ds[i + 1].Ten
                // ASCII greater
                NhanVien tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
}

void LuuVaoFile(DSNhanVien DSNV) {
    ofstream fileDSNV;
    fileDSNV.open("dsnv.txt");
    int len = DSNV.ds.size();
    for(int i = 0; i < len; i++) {
        fileDSNV << "======================" << endl;
        fileDSNV << "MaNhanVien: " << DSNV.ds[i].MaNhanVien << endl;
        fileDSNV << "Ho Ten: " << DSNV.ds[i].HoLot << endl;
        fileDSNV << "Ten: " << DSNV.ds[i].Ten << endl;
        fileDSNV << "Luong: " << DSNV.ds[i].Luong << endl;
    }
    fileDSNV.close();
    cout << "\nWrited to dsnv.txt\n\n";
}

void LuuKQFile(NhanVien NVFind, NhanVien NVMax, DSNhanVien DSNV) {
    fstream KQ;
    KQ.open("output3.txt", ios::app);

    KQ << "tim nv: " << endl;
    if(NVFind.MaNhanVien) {
        KQ << "mnv:"<< NVFind.MaNhanVien;
        KQ << "\nHo: " << NVFind.Ten << endl;
        KQ << "\nTen: " << NVFind.HoLot << endl;
        KQ << "\nLuong: " << NVFind.Luong << endl;
        KQ << "======================" << endl;
    } else {
        KQ << "Not found\n\n";
    }

    KQ << "Max luong " << endl;
    if(NVMax.MaNhanVien) {
        KQ << "Ma Nhan Vien : " << NVMax.MaNhanVien;
        KQ << "\nTen        : " << NVMax.Ten << endl;
        KQ << "\nHo Lot     : " << NVMax.HoLot << endl;
        KQ << "\nLuong      : " << NVMax.Luong << endl;
        KQ << "======================" << endl;
    } else {
        KQ << "Employees is empty\n\n";
    }
    
    KQ << "Min Luong " << endl;
    if(NVMax.MaNhanVien) {
        KQ << "Ma Nhan Vien : " << NVMax.MaNhanVien;
        KQ << "\nTen        : " << NVMax.Ten << endl;
        KQ << "\nHo Lot     : " << NVMax.HoLot << endl;
        KQ << "\nLuong      : " << NVMax.Luong << endl;
        KQ << "======================" << endl;
    } else {
        KQ << "Employees is empty\n\n";
    }
    
    KQ << "sau khi sap xep: " << endl;
    int tmp = DSNV.ds.size();
    if(tmp) {
        for(int i = 0; i < tmp; i++) {
            KQ << "======================" << endl;
            KQ << "Ma Nhan Vien: " << DSNV.ds[i].MaNhanVien;
            KQ << "\nTen		   : " << DSNV.ds[i].Ten << endl;
            KQ << "\nHo Lot     : " << DSNV.ds[i].HoLot << endl;
            KQ << "\nLuong     : " << DSNV.ds[i].Luong << endl;
        }
    } else {
        KQ << "Employees is empty\n\n";
    }

    KQ.close();
    cout << "\nWrited to output3.txt\n\n";
}

bool TroVeMenu() {
    cout << "Enter 1 de tro ve menu:> "; cin >> TroVe;

    if(TroVe == 1) {
        return true;
    } return false;
}
