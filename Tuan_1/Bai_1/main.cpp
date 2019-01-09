#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

void Show();
string s = "";
void NhapChuoi() {
	s = "";
	do {
		cout << "Nhap chuoi co toi da 255 ky tu: ";
		cin.ignore(100, '\n');
		getline(cin, s);
		if (s.length() > 255) {
			cout << "Nhap lai:";
		}
	} while (s.length() > 255);
}

string trim(string& s) {
	if (s.length() == 0)
		return "";
	string ss = s;
	ss.erase(0, ss.find_first_not_of(" "));
	ss.erase(ss.find_last_not_of(" ") + 1);
	return ss;
}

void BoKhoangTrang() {
	s = trim(s);
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ' && s[i + 1] == ' ') {
			for (int j = i; j < n; j++) {
				s[j] = s[j + 1];
			}
			n--;
			i--;
		}
	}
}

void Proper() {
	int n = s.length();
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s[0] = toupper(s[0]);
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == ' ') {
			s[i] = toupper(s[i]);
		}
	}
}

int SoLuongKyTu() {
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ' && isalpha(s[i])) {
			j++;
		}
	}
	return j;
}

void NhapFile() {
	ofstream file("input1.txt");
	if (file.fail()) {
		cout << "Khong the mo file" << endl;
		return;
	}
	file << s << endl;

	file.open("output1.txt", ios::out);
	file << "========================================" << endl;
	file.close();
}

void NhapKQ() {
	ofstream file("output1.txt", ios::app);
	file << s << endl;
	file.close();
}


void Menu() {

	cout << "****************************************************************" << endl;
	cout << "*                     THAO TAC TREN CHUOI                      *" << endl;
	cout << "****************************************************************" << endl;

	cout << "1. Nhap 1 chuoi co toi da 255 ky tu" << endl;
	cout << "2. Bo khoang trang thua" << endl;
	cout << "3. Chuan hoa chuoi dang proper" << endl;
	cout << "4. Thong ke so luong cac ky tu chu cai co trong chuoi" << endl;
	cout << "5. Chuoi la" << endl;
	cout << "6. Thoat" << endl;
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
}

void Chon() {
	int i;
	cout << "Chon: "; cin >> i;
	if (i != 1 && s == "") {
		system("cls");
		cout << "Ban chua nhap 1 chuoi." << endl;
		Show();
		return;
	}
	ofstream file;
	file.open("output1.txt", ios::out | ios::app);
	switch (i) {
	case 1:
		NhapChuoi();
		NhapFile();
		system("cls");
		Show();
		break;
	case 2:
		BoKhoangTrang();
		file << "Ban chon bo khoang trang: " << 2 << " => " << s << endl;
		system("cls");
		cout << "Da bo khoang trang: " << s << endl;
		Show();
		break;
	case 3:
		Proper();
		file << "Ban chon chuan hoa chuoi dang proper: " << 3  << " => " << s << endl;
		system("cls");
		cout << "Da xu ly proper: " << s << endl;
		Show();
		break;
	case 4:
		system("cls");
		file << "Ban chon so ky tu co trong chuoi : " << 4 << " => " << s << endl;
		cout << "So ky tu co trong chuoi la: " << SoLuongKyTu() << endl;
		Show();
		break;
	case 5:
		system("cls");
		cout << "Chuoi la: " << s << endl;
		Show();
		break;
	case 6:
		file.close();
		return;
	default:
		system("cls");
		cout << "Sai cu phap" << endl;
		Show();
		break;
	}
}

void Show() {
	Menu();
	Chon();
}

int main() {
	Show();
	system("pause");
}