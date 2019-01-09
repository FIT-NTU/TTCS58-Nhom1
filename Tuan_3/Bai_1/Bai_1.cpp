#include <iostream>
#include <fstream>
using namespace std;

int a[20];
int n;

void NhapTuFile(int a[], string path) {
	ifstream f;
	int x, y;
	f.open(path.c_str(), ios::out);
	if(f.is_open()) {
		f >> n;
		for(int i = 0; i < n; i++) {
			f >> a[i];
		}
	}
	cout << "Da nhap file thanh cong" << endl;
	f.close();
}
void NhapMang(int a[]){
	cout << "So phan tu muon nhap:"; cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "A[ "<< i << "] = "; cin >> a[i];
	}
}

void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "   ";
	}
	cout <<endl;
}

int KiemTra(int a[], int n, int x) {
	for(int i = 0; i < n; i++) {
		if(a[i] == x){
			return i;
		}
	}
	return -1;
}

void SapXep(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j ++) {
			if(a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}

}

void Chen(int a[], int vitri, int giatri) {
	int j = 0;
	while(a[j] != 0) {
		j += 1;
	}
	n = j + 1;
	for (int i = j; i >= vitri; i--) {
		a[i + 1] = a[i];
	}
	a[vitri] = giatri;
}

void ChenKT(int a[], int giatri) {
	int j = 0;
	while(a[j] != 0) {
		j += 1;
	}
	if(a[0] > giatri) {
		Chen(a, 0, giatri);
	} else {
		for(int i = j - 1; i >= 1; i--) {
			if(giatri > a[i]) {
				Chen(a, i + 1, giatri);
				break;
			}
		}	
	}
}

// Xoa phan tu co gia tri la giatri
void Xoa(int a[], int giatri) {
	int j = 0;
	while(a[j] != 0) {
		j += 1;
	}
//	n = j - 1;
	for(int i = 0; i < j; i++) {
		if(a[i] == giatri) {
			for(int k = i; k < j; k++) {
				a[k] = a[k + 1];
			}
			i -= 1;
			n -= 1;
		}
	}
}

// Xoa 1 vi tri nao do 
void Xoa1(int a[], int vitri) {
	n -= 1;
	for (int i = vitri; i < n; i++){
		a[i] = a[i + 1];
	}
}

void XoaTrungLap(int a[]) {
//	int j = n;
	for (int i = 0; i < n - 1; i++) {
		for(int k = i + 1; k < n; k++) {
			if(a[i] == a[k]) {
				Xoa1(a, k);
			}
		}
	}
}


void menu() {
	cout << "0. Nhap danh sach tu file" << endl;
	cout << "1. Nhap vao danh sach" << endl;
	cout << "2. Sap xep theo thu tu tang dan" << endl;
	cout << "3. Kiem tra so x co ton tai" << endl;
	cout << "4. Chen so x neu chua co trong day nhung van tang dan" << endl;
	cout << "5. Xoa tat ca cac phan tu co gia tri x neu co trong day" << endl;
	cout << "6. Xoa cac phan tu trung lap trong day" << endl;
	cout << "7. In ra tat ca cac phan tu" << endl;
	cout << "8. Thoat" << endl;
}

void select() {
	menu();
	int temp = 0, h = 0;
	do {
		cout << "Ban chon: "; cin >> h;
	} while(h < 0 ||  h > 8);
	switch(h) {
		case 0:
			system("cls");
			NhapTuFile(a, "input1.txt");
			select();
			break;
		case 1:
			system("cls");
			NhapMang(a);
			select();
			break;
		case 2:
			system("cls");
			SapXep(a, n);
			cout << "Da sap xep thanh cong:" << endl;
			XuatMang(a, n);
			select();
			break;	
		case 3:
			cout << "Nhap so x: "; cin >> temp;
			system("cls");
			if(KiemTra(a, n, temp) == -1) {
				cout << "Khong ton tai so " << temp << " trong mang!" << endl;;
			} else {
				cout << "Vi tri so " << temp << " trong mang la: " << KiemTra(a, n, temp) << endl;
			}
			select();
			break;
		case 4:
			cout << "Nhap so can chen: "; cin >> temp;
			system("cls");
			if(KiemTra(a, n, temp) == -1) {
				ChenKT(a, temp);
				cout << "Da chen thanh cong phan so " << temp << " vao danh sach." << endl;
				XuatMang(a,n);
			} else {
				cout << "Da co phan tu nay trong day" << endl;
			}
			select();
			break;
		case 5:
			cout << "Nhap so can xoa: "; cin >> temp;
			system("cls");
			if(KiemTra(a, n, temp) == -1) {
				cout << "Khong co phan tu nao co gia tri " << temp <<  " trong day" << endl;
			} else {
				Xoa(a, temp);
				cout << "Da xoa thanh cong" << endl;
				XuatMang(a, n);
			}
			select();
			
			break;
		case 6:
			system("cls");
			XoaTrungLap(a);
			cout << "Xoa trung lap thanh cong" << endl;
			XuatMang(a, n);
			select();
			break;
		case 7:
			system("cls");
			XuatMang(a, n);
			select();
			break;
		case 8:
			return;
			break;
			
			
	}
}

int main() {
	int temp;
	select();
	system("pause");
}
