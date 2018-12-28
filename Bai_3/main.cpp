#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define N 4
#define numWidth 10
#define nameWidth 30
#define separator ' '
struct emp {
	int id;
	string lastname;
	string firstname;
	int salary;
};
typedef struct emp Emp;

void readFile(vector<Emp> &list, string path) {
	int n;
	ifstream file;
	Emp temp;
	list.clear();
	file.open(path.c_str(), ios::out);
	if (file.is_open()) {
		file >> n;
		if (n > 50) {
			cout << "So nhan vien qua 50" << endl;
			file.close();
			return;
		}
		for (int i = 0; i < n; i++) {
			file >> temp.id;
			file >> temp.lastname;
			file >> temp.firstname;
			file >> temp.salary;
			list.push_back(temp);
		}
	}

	file.close();
}

void writeFile(string * s, int n, string path) {
	ofstream file;
	file.open(path.c_str(), ios_base::out);

	for (int row = 0; row < n; row++) {
		file << "Emp: " << row + 1 << endl;
		for (int col = 0; col < N; col++) {
			file << s[row  * N + col] << endl;
		}
	}
	file.close();
}




// tra ve nhan vien co ma nhan vien
int searchEmp(vector<Emp> list, int id) {
	int n = list.size();
	Emp * p = new Emp;
	for (int i = 0; i < n; i++) {
		if (list.at(i).id == id) {
			return i;
		}
	}
	return -1;
}

// Tra ve luong cao nhat hoac thap nhat
int Salary(vector<Emp> list, int k) {
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
	cout << "Da sap xep thanh cong" << endl;
}

void menu() {
	cout << "1. Nhap thong tin nhan vien" << endl;
	cout << "2. Thong tin nhan vien tu ma nhan vien" << endl;
	cout << "3. Nhan vien co luong cao nhat va thap nhat" << endl;
	cout << "4. Sap xep nhan vien theo ten" << endl;
	cout << "5. Hien tat ca nhan vien" << endl;
	cout << "6. Thoat" << endl;
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

// In ra danh sach nhan vien co dieu kien
void showSelectEmp(vector<Emp> list, int * c, int n) {
	cout << left << setw(numWidth) << setfill(separator) << "ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Ho";
	cout << left << setw(nameWidth) << setfill(separator) << "Ten";
	cout << left << setw(numWidth) << setfill(separator) << "Luong";
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << left << setw(numWidth) << setfill(separator) << list.at(c[i]).id;
		cout << left << setw(nameWidth) << setfill(separator) << list.at(c[i]).lastname;
		cout << left << setw(nameWidth) << setfill(separator) << list.at(c[i]).firstname;
		cout << left << setw(numWidth) << setfill(separator) << list.at(c[i]).salary;
		cout << endl;
	}
	cout << endl;
}

// In ra nhan vien co luong cao nhat hoac thap nhat
void showSalary(vector<Emp> list, int size) {
	int * c = new int[size], n = 0;
	int temp;
	cout << "Cao nhat (0) hay thap nhat (1): ";
	do {
		cin >> temp;
		if (!(temp == 1 || temp == 0)) {
			cout << "Nhap lai: ";
		}
	} while (!(temp == 1 || temp == 0));
	system("cls");

	cout << "Nhan vien co luong " << (temp == 0 ? "cao nhat" : "thap nhat") << " la: " << endl;
	temp = Salary(list, temp);
	for (int i = 0; i < size; i++) {
		if (list.at(i).salary == temp) {
			c[n++] = i;
		}
	}
	showSelectEmp(list, c, n);
	delete[] c;
}

// In ra nhan vien theo ma nhan vien
void showEmpId(vector<Emp> list, int n) {
	if (searchEmp(list, n) != -1) {
		int * a = new int;
		a[0] = searchEmp(list, n);
		showSelectEmp(list, a, 1);
		delete[] a;
	}
	else {
		cout << "Khong co ma so nhan vien nay!!!" << endl;
	}
}

void select(vector<Emp> &list) {
	int n = 0, temp = 0, size = list.size();
	cout << "Ban chon: "; cin >> n;
	if (n == 6) {
		return;
	}
	fstream file;
	file.open("output3.txt", ios::out | ios::app);
	switch (n)
	{

	case 1:
		readFile(list, "input3.txt");
		system("cls");
		cout << "Nhap thanh cong!" << endl;
		menu();
		select(list);
		break;
	case 2:			// Tim nhan vien theo ma nhan vien
		cout << "Ma nhan vien: "; cin >> temp;
		system("cls");
		showEmpId(list, temp);
		if (file.is_open()) {
			file << "Thong tin nhan vien co ma la " << list.at(temp).id << endl;
			file << "Ten: " << list.at(temp).lastname << " " << list.at(temp).firstname << endl;
			file << "Luong: " << list.at(temp).salary << endl;
		}
		menu();
		select(list);
		break;

	case 3:	// In ra nhan vien co luong cao nhat hoac thap nhat
		
		showSalary(list, size);
		menu();
		select(list);
		break;
	case 4:
		sortName(list);
		system("cls");
		showAllEmp(list);
		menu();
		select(list);
		if (file.is_open()) {
			file << "Da sap xep thanh cong" << endl;
		}
		break;
	case 5:
		system("cls");
		showAllEmp(list);
		menu();
		select(list);
		break;
	case 6:
		file.close();
		break;
	default:
		system("cls");
		cout << "Nhap sai" << endl;
		menu();
		select(list);
		break;
	}
}

int main() {
	int n = 0;
	vector<Emp> dsNV;
	menu();
	select(dsNV);
	system("pause");
}
