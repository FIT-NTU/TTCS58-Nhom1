#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define N 50
#define numWidth 10
#define nameWidth 30
#define separator ' '
#define INPUT "input3.txt"
#define OUTPUT "output3.txt"

//ofstream write;
//ifstream read;
struct emp {
	int id;
	string lastname;
	string firstname;
	int salary;
};
typedef struct emp Emp;

// CAC HAM CHUC NANG
void readFile(vector<Emp> &list, string path) {
	int n;
	Emp temp;
	ifstream read;
	list.clear();
	read.open(path.c_str(), ios::out);
	if (read.is_open()) {
		read >> n;
		if (n > 50) {
			cout << "So nhan vien qua 50" << endl;
			read.close();
			return;
		}
		for (int i = 0; i < n; i++) {
			read >> temp.id;
			read >> temp.lastname;
			read >> temp.firstname;
			read >> temp.salary;
			list.push_back(temp);
		}
	}
	read.close();
}

void writeFile(string * s, int n, string path) {
	ofstream write;
	write.open(path.c_str(), ios_base::out);
	for (int row = 0; row < n; row++) {
		write << "Emp: " << row + 1 << endl;
		for (int col = 0; col < N; col++) {
			write << s[row  * N + col] << endl;
		}
	}
	write.close();
}

void writeStringContinue(string s, string path) {
	ofstream write;
	write.open(path.c_str(), ios::out | ios::app);
	if (write.is_open()) {
		write << s << endl;
	}
	write.close();
}

// tra ve nhan vien co ma nhan vien
int checkEmp(vector<Emp> list, int id) {
	int n = list.size();
	Emp * p = new Emp;
	for (int i = 0; i < n; i++) {
		if (list.at(i).id == id) {
			return i;
		}
	}
	return -1;
}

// Tra ve luong cao nhat hoac thap nhat tuy thuoc vao so k
int salaryHL(vector<Emp> list, int k) {
	int n = list.size();
	int minmax = list.at(0).salary;


	for (int i = 1; i < n; i++) {
		if (k == 0) {	// Luong cao nhat
			if (list.at(i).salary > minmax) {
				minmax = list.at(i).salary;
			}
		}
		else {			// Luong thap nhat
			if (list.at(i).salary < minmax) {
				minmax = list.at(i).salary;
			}
		}
	}
	return minmax;
}


// HAM XY LY
/* ================================================================ */

// Sap xep nhan vien
void sortName(vector<Emp> &list) {
	int n = list.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {

			if (list.at(i).firstname.compare(list.at(j).firstname) > 0) {
				Emp temp = list.at(i);
				list.at(i) = list.at(j);
				list.at(j) = temp;
			}
			if (list.at(i).firstname.compare(list.at(j).firstname) == 0) {
				if (list.at(i).lastname.compare(list.at(j).lastname) > 0) {
					Emp temp = list.at(i);
					list.at(i) = list.at(j);
					list.at(j) = temp;
				}
			}

		}
	}
}

// In ra tat ca cac nhan vien
void showAllEmp(vector<Emp> list) {
	int n = list.size();

	cout << left << setw(numWidth) << setfill(separator) << "ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Ho";
	cout << left << setw(nameWidth) << setfill(separator) << "Ten";
	cout << left << setw(numWidth) << setfill(separator) << "Luong";
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << left << setw(numWidth) << setfill(separator) << list.at(i).id;
		cout << left << setw(nameWidth) << setfill(separator) << list.at(i).lastname;
		cout << left << setw(nameWidth) << setfill(separator) << list.at(i).firstname;
		cout << left << setw(numWidth) << setfill(separator) << list.at(i).salary;
		cout << endl;
	}
	cout << endl;
}

int * listEmpSalary(vector<Emp> list, int k) {
	int n = list.size();
	int * a = new int[n], index = 0;
	int salary = salaryHL(list, k);
	for (int i = 0; i < n; i++) {
		if (list.at(i).salary == salary) {
			index = index + 1;
			a[index] = i;
		}
	}
	a[0] = index;
	return a;
}

// In ra danh sach nhan vien co co trong mang c, chi so dau tien la so luong
void showEmpSelect(vector<Emp> list, int * c) {
	int n = c[0];
	cout << left << setw(numWidth) << setfill(separator) << "ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Ho";
	cout << left << setw(nameWidth) << setfill(separator) << "Ten";
	cout << left << setw(numWidth) << setfill(separator) << "Luong";
	cout << endl;

	for (int i = 1; i <= n; i++) {
		cout << left << setw(numWidth) << setfill(separator) << list.at(c[i]).id;
		cout << left << setw(nameWidth) << setfill(separator) << list.at(c[i]).lastname;
		cout << left << setw(nameWidth) << setfill(separator) << list.at(c[i]).firstname;
		cout << left << setw(numWidth) << setfill(separator) << list.at(c[i]).salary;
		cout << endl;
	}
	cout << endl;
}

void writeEmpSelect(vector<Emp> list, int * c, string path) {
	int n = c[0];
	ofstream write;

	write.open(path.c_str(), ios::out | ios::app);
	if (write.is_open()) {
		write << left << setw(numWidth) << setfill(separator) << "ID";
		write << left << setw(nameWidth) << setfill(separator) << "Ho";
		write << left << setw(nameWidth) << setfill(separator) << "Ten";
		write << left << setw(numWidth) << setfill(separator) << "Luong";
		write << endl;

		for (int i = 1; i <= n; i++) {
			write << left << setw(numWidth) << setfill(separator) << list.at(c[i]).id;
			write << left << setw(nameWidth) << setfill(separator) << list.at(c[i]).lastname;
			write << left << setw(nameWidth) << setfill(separator) << list.at(c[i]).firstname;
			write << left << setw(numWidth) << setfill(separator) << list.at(c[i]).salary;
			write << endl;
		}
		write << endl;
	}

	write.close();
}

void menu() {
	cout << "1. Nhap thong tin nhan vien" << endl;
	cout << "2. Thong tin nhan vien tu ma nhan vien" << endl;
	cout << "3. Nhan vien co luong cao nhat va thap nhat" << endl;
	cout << "4. Sap xep nhan vien theo ten" << endl;
	cout << "5. Hien tat ca nhan vien" << endl;
	cout << "6. Thoat" << endl;
}

void select(vector<Emp> &list) {
	int n = 0, temp = 0, *tempA;

	cout << "Ban chon: "; cin >> n;
	if (n == 6) {
		return;
	}

	switch (n)
	{
	case 1:
		readFile(list, "input3.txt");
		writeStringContinue("=======================================================================", OUTPUT);

		system("cls");
		cout << "Nhap thanh cong!" << endl;
		menu();
		select(list);
		break;
	case 2:			// Tim nhan vien theo ma nhan vien
		cout << "Ma nhan vien: "; cin >> temp;
		system("cls");
		if (checkEmp(list, temp) != -1) {
			tempA = new int[2];
			tempA[0] = 1;
			tempA[1] = checkEmp(list, temp);
			showEmpSelect(list, tempA);
			writeStringContinue("Ban Chon 2: Thong tin nhan vien tu ma nhan vien", OUTPUT);
			writeEmpSelect(list, tempA, "output3.txt");
		}
		else {
			cout << "Khong co nhan vien co ma la " << temp << endl;
		}

		menu();
		select(list);
		break;

	case 3:	// In ra nhan vien co luong cao nhat hoac thap nhat
		do {
			cout << "Cao nhat (0) - thap nhat(1):"; cin >> temp;
		} while (temp != 0 && temp != 1);
		system("cls");
		tempA = new int[N];
		tempA = listEmpSalary(list, temp);
		writeStringContinue("Ban chon 3: Tim nhan vien co luong cao nhat, thap nhat", OUTPUT);
		if (temp == 0) {
			cout << "Nhan vien co luong cao nhat la:" << endl;
			writeStringContinue("Nhan vien co luong cao nhat la:", OUTPUT);
		}
		else {
			cout << "Nhan vien co luong thap nhat la:" << endl;
			writeStringContinue("Nhan vien co luong cao nhat la:", OUTPUT);
		}
		showEmpSelect(list, tempA);
		writeEmpSelect(list, tempA, OUTPUT);

		menu();
		select(list);
		break;
	case 4:
		system("cls");
		sortName(list);
		showAllEmp(list);
		writeStringContinue("Ban chon 4: Sap xep nhan vien\nSap xep nhan vien thanh cong", OUTPUT);
		menu();
		select(list);
		break;
	case 5:
		system("cls");
		showAllEmp(list);
		menu();
		writeStringContinue("Ban chon 5: Hien tat ca nhan vien co trong danh sach", OUTPUT);
		select(list);
		break;
	case 6:
		return;
	default:
		system("cls");
		cout << "Nhap sai" << endl;
		menu();
		select(list);
		break;
	}
}

int main() {
	int n = 0, *a = new int[N];
	vector<Emp> dsNV;
	menu();
	select(dsNV);
	system("pause");
}
