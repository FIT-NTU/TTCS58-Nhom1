#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;


#define nameWidth 25
#define numWidth 15
#define separator ' '
#define HESOLUONG 300000

class Emp {
private:
	int id;
	string name;
	int age;
	int dayWork;
    int salary;
public:
	// GET
	int getId();
	string getName();
	int getDayWork();
	int getAge();
    int getSalary();
	// SET
	void setId(int Id);
	void setName(string Name);
	void setDayWork(int dayWork);
	void setAge(int Age);
	Emp(int Id, string Name, int Age, int daywork);
};

// GET
int Emp::getId()
{
	return id;
}

string Emp::getName()
{
	return name;
}

int Emp::getDayWork()
{
	return dayWork;
}

int Emp::getAge()
{
	return age;
}

int Emp::getSalary() {
    return this->salary;
}
// SET
void Emp::setId(int Id) {
	this->id = Id;
}

void Emp::setName(string Name)
{
	this->name = Name;
}

void Emp::setDayWork(int dayWork)
{
	this->dayWork = dayWork;
    this->salary = this->dayWork * HESOLUONG;
}

void Emp::setAge(int Age)
{
	this->age = Age;
}


Emp::Emp(int Id, string Name, int Age, int dayWork)
{
	this->id = Id;
	this->name = Name;
	this->age = Age;
	this->dayWork = dayWork;
    this->salary = this->dayWork* HESOLUONG;

}

class DSNV {
private:
	vector<Emp*> list;
	int size = 0;
public:
	int getSize();
	int indexEmpById(int id);

	void readFromFile(string path);
	// void writeFile(string path);
	void addEmp();
	void delEmp(int index);
	void editEmp(int index);
	void showAllEmp();
	void showOneEmp(int index);
    void sortDayWork();
    void inputEmp();
};


int DSNV::getSize() {
	return size;
}

// Lay chi so cua nhan vien co ma nhan vien la: id
int DSNV::indexEmpById(int id) {
	if (this->size == 0) {
		return -1;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->list.at(i)->getId() == id) {
			return i;
		}
	}
	return -1;
}

void DSNV::readFromFile(string path)
{
	int id, age, salary;
	string name = "";
	string temp;
	ifstream file;
	file.open(path.c_str());
	if (file.fail()) {
		cout << "KHONG THE MO FILE" << endl;
		return;
	}
	while (!file.eof())
	{
		file >> id;
		file.ignore();
		getline(file, name);
		file >> age;
		file >> salary;
		this->list.push_back(new Emp(id, name, age, salary));
		this->size += 1	;
	}
	file.close();
}

void DSNV::addEmp() {
	int id, age, daywork;
	string name;
	cout << "Ma nhan vien: ";
	do {
		cin >> id;
		if (indexEmpById(id) != -1) {
			cout << "Da co ma nhan vien nay. Nhap lai: ";
		}
	} while (indexEmpById(id) != -1);
	cin.ignore();
	cout << "Ten: "; getline(cin, name);
	cout << "Tuoi: "; cin >> age;
	cout << "Ngay cong: "; cin >> daywork;
	cout << endl;
	this->list.push_back(new Emp(id, name, age, daywork));
	this->size += 1;
}

void DSNV::inputEmp() {
	int n;
	cout << "Nhap so luong nhan vien: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "NHAN VIEN THU : " << i + 1 << endl;
		addEmp();
	}
}

void DSNV::delEmp(int id) {
	if (indexEmpById(id) == -1) {
		cout << "KHONG CO NHAN VIEN CO MA LA " << id << endl;
		return;
	}
	this->list.erase(this->list.begin() + indexEmpById(id));
	this->size -= 1;
	cout << "XOA NHAN VIEN THANH CONG" << endl;
}

void DSNV::sortDayWork() {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i; j < size; j++) {
            if (list.at(i)->getDayWork() > list.at(j)->getDayWork()) {
                swap(list.at(i), list.at(j));
            }
        }
    }
    cout << "DA SAP XEP THANH CONG" << endl;
}


void menuEditEmp() {
	cout << "Sua gi:" << endl;
	cout << "1. Ma nhan vien" << endl;
	cout << "2. Ten nhan vien" << endl;
	cout << "3. Tuoi nhan vien" << endl;
	cout << "4. So ngay cong" << endl;
}
void DSNV::editEmp(int index)
{
	int id, age, dayWork, temp;
	string name;
	if (indexEmpById(index) == -1) {
		cout << "KHONG CO NHAN VIEN NAY!" << endl;
	}
	else {
		menuEditEmp();
		cout << "Ban chon: "; cin >> temp;
		switch (temp)
		{
		case 1:
			cout << "Nhap ma nhan vien moi: ";
			do {
				cin >> id;
				if (indexEmpById(id) != -1) {
					cout << "Da co ma nhan vien nay. Nhap lai: ";
				}
			} while (indexEmpById(id) != -1);
			this->list.at(indexEmpById(index))->setId(id);
			break;
		case 2:
			cin.ignore();
			cout << "Nhap ten nhan vien moi: "; getline(cin, name);
			this->list.at(indexEmpById(index))->setName(name);
			break;
		case 3:
			cout << "Nhap tuoi nhan vien moi: "; cin >> age;
			this->list.at(indexEmpById(index))->setAge(age);
			break;
		case 4:
			cout << "Nhap ngay cong nhan vien moi "; cin >> dayWork;
			this->list.at(indexEmpById(index))->setDayWork(dayWork);
			break;
		default:
			cout << "Nhap sai" << endl;
			break;
		}
		system("cls");
		cout << "SUA NHAN VIEN THANH CONG" << endl;
	}
}


void DSNV::showAllEmp() {
	cout << "DANH SACH TAT CA CAC NHAN VIEN:" << endl;
	cout << left << setw(numWidth) << setfill(separator) << "Ma";
	cout << left << setw(nameWidth) << setfill(separator) << "Ho ten";
	cout << left << setw(nameWidth) << setfill(separator) << "Tuoi";
	cout << left << setw(numWidth) << setfill(separator) << "Ngay Cong";
	cout << left << setw(numWidth) << setfill(separator) << "Luong";
	cout << endl;
	for (int i = 0; i < this->size; i++) {
		cout << left << setw(numWidth) << setfill(separator) << this->list.at(i)->getId();
		cout << left << setw(nameWidth) << setfill(separator) << this->list.at(i)->getName();
		cout << left << setw(nameWidth) << setfill(separator) << this->list.at(i)->getAge();
		cout << left << setw(numWidth) << setfill(separator) << this->list.at(i)->getDayWork();
		cout << left << setw(numWidth) << setfill(separator) << this->list.at(i)->getSalary();
		cout << endl;
	}
	cout << endl;
}

void DSNV::showOneEmp(int id)
{
	if (indexEmpById(id) == -1) {
		cout << "KHONG CO NHAN VIEN CO MA " << id << endl;
		return;
	}
	int index = indexEmpById(id);
	cout << left << setw(numWidth) << setfill(separator) << "Ma";
	cout << left << setw(nameWidth) << setfill(separator) << "Ho ten";
	cout << left << setw(nameWidth) << setfill(separator) << "Tuoi";
	cout << left << setw(numWidth) << setfill(separator) << "Ngay cong";
	cout << left << setw(numWidth) << setfill(separator) << "Luong";
	cout << endl;
	cout << left << setw(nameWidth) << setfill(separator) << this->list.at(index)->getId();
	cout << left << setw(nameWidth) << setfill(separator) << this->list.at(index)->getName();
	cout << left << setw(nameWidth) << setfill(separator) << this->list.at(index)->getAge();
	cout << left << setw(numWidth) << setfill(separator) << this->list.at(index)->getDayWork();
	cout << left << setw(numWidth) << setfill(separator) << this->list.at(index)->getSalary();
	cout << endl;
}

void menu() {
	cout << "=================MENU=================" << endl;
	cout << "0. Nhap nhan vien tu file" << endl;
	cout << "1. Them nhan vien" << endl;
	cout << "2. Danh sach tat ca nhan vien" << endl;
	cout << "3. Sua nhan vien theo id" << endl;
	cout << "4. Xoa nhan vien theo id" << endl;
	cout << "5. Thong tin nhan vien theo id" << endl;
	cout << "6. Sap xep nhan vien theo ngay cong" << endl;
	cout << "7. Thoat" << endl;
	cout << "8. Nhap danh sach nhan vien" << endl;
}

void select(DSNV &list) {
	int n = 0, temp;
	menu();
	cout << "Ban chon: ";

//	do {
//		cin >> n;
//		if ((n != 0 && n != 1 && n != 8 && n != 7) && (list.getSize() == 0)) {
//			cout << "Nhap lai: ";
//		}
//	} while ((n != 0 && n != 1 && n != 8 && n != 7) && (list.getSize() == 0));
	cin >> n;
	if (n == 7) {
		return;
	}
	switch (n)
	{
	case 0:
		list.readFromFile("input3.txt");
		system("cls");
		cout << "NHAP NHAN VIEN TU FILE THANH CONG" << endl;
		select(list);
		break;
	case 1:
		list.addEmp();
		system("cls");
		cout << "THEM NHAN VIEN THANH CONG" << endl;
		select(list);
		break;
	case 2:
		system("cls");
		list.showAllEmp();
		select(list);
		break;
	case 3:
		cout << "Nhap ma nhan vien muon sua:"; cin >> temp;
		system("cls");
		list.editEmp(temp);
		select(list);
		break;
	case 4:
		cout << "Nhap ma nhan vien muon xoa:"; cin >> temp;
		system("cls");
		list.delEmp(temp);
		select(list);
		break;
	case 5:
		cout << "Nhap ma nhan vien muon xem:"; cin >> temp;
		system("cls");
		list.showOneEmp(temp);
		select(list);
		break;
    case 6: 
        system("cls");
        list.sortDayWork();
        select(list);
        break;
    case 8:
    	list.inputEmp();
    	system("cls");
    	select(list);	
    	break;
	default:
		system("cls");
		cout << "Nhap sai" << endl;
		select(list);
		break;
	}
}


int main() {
	DSNV list;
	select(list);
	system("pause");
}
