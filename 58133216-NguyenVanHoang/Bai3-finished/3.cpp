#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// define
struct Employee {
    int empCode;
    string firstName; // ten
    string lastName; // ho
    int salary;
} empF, empS; // employee finded, employee have max of salary
class empList {
    public:
        int n;
    	vector<Employee> ds;
        void enterEmps();
        void showEmpList();
        Employee findEmp();
        Employee maxOfSalary();
        void sort();
};
empList emps;
int option;
char rtnmenu;

void readFile();
void showMenu();
void menuOption();
void writeToInputFile(empList emps);
void writeToOutputFile(Employee empF, Employee empS, empList emps);
bool returnMenu();
void goTo(int x, int y) {
    COORD co = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}

int main() {
    readFile();
    showMenu();
    menuOption();
}

void empList::enterEmps() {
    int tmp;
    cout << "Enter quantity: "; cin >> tmp;
    int m = n;
    n += tmp;
    ds.resize(n);
    // cout << m << " " << n << endl;
    for(int i = m; i < n; i++) {
        cout << "Employee code: ";
        cin >> ds[i].empCode;

        cout << "First name: ";
        fflush(stdin);
        getline(cin, ds[i].firstName);

        cout << "Last name: ";
        fflush(stdin);
        getline(cin, ds[i].lastName);

        cout << "Salary: ";
        cin >> ds[i].salary;
    }
}
void empList::showEmpList() {
    if(n) {
        cout << "STT\t" << "Emp code\t" << "Ho ten";
        goTo(50, 1);
        cout << "Salary" << endl;
        for(int i = 0; i < n; i++) {
            cout << i + 1 << "\t" << ds[i].empCode << "\t\t";
            cout << ds[i].lastName << " " << ds[i].firstName;
            goTo(50, 2 + i);
            cout << ds[i].salary << endl;
        }
    } else {
        cout << "======================" << endl;
        cout << "Employees is empty" << endl;
    }
}
Employee empList::findEmp() {
    int empCode;
    cout << "Enter employee code: "; cin >> empCode;
    for(int i = 0; i < n; i++) {
        if(ds[i].empCode == empCode)
            return ds[i];
    }
    return empF; // not found
}
Employee empList::maxOfSalary() {
    if(ds.size()) {
        int max = ds[0].salary;
        int key = 0;
        for(int i = 1; i < n; i++) {
            if(ds[i].salary > max) {
                max = ds[i].salary;
                key = i;
            }
        } return ds[key];
    } else {
        return empS;
    }
}
void empList::sort() {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            if(ds[i].firstName.compare(ds[j].firstName) > 0) {
                Employee tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            } else if(ds[i].firstName.compare(ds[j].firstName) == 0) {
                if(ds[i].lastName.compare(ds[j].lastName) > 0) {
                    Employee tmp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = tmp;
                }
            }
        }
}
void readFile() {
    ifstream myfile;
    myfile.open("input3.txt");
    
    if(myfile.is_open()) {
        string line;
        int i = 0;
        int tmp;
        while(getline(myfile, line)) {
            tmp = i / 4;
            emps.ds.resize(tmp + 1);
            switch(i % 4) {
                case 0:
                    emps.ds[tmp].empCode = atoi(line.c_str());
                    i++;
                    break;
                case 1:
                    emps.ds[tmp].lastName = line;
                    i++;
                    break;
                case 2:
                    emps.ds[tmp].firstName = line;
                    i++;
                    break;
                case 3:
                    emps.ds[tmp].salary = atoi(line.c_str());
                    i++;
                    break;
            }
        } emps.n = tmp + 1;
    } else {
        // cout << "Unable open to file" << endl;
    }

    myfile.close();
}
void showMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t1. Add employees" << endl;
    cout << "\t\t\t\t2. Find employee" << endl;
    cout << "\t\t\t\t3. Max of salary" << endl;
    cout << "\t\t\t\t4. Sort employee list" << endl;
    cout << "\t\t\t\t5. Save to file" << endl;
    cout << "\t\t\t\t6. Exit" << endl;
}
void menuOption() {
    cout << "\t\t\t\t  Enter your choice: "; cin >> option;

    switch(option) {
        case 1:
            system("cls");
            emps.enterEmps();
            writeToInputFile(emps);
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 2:
            system("cls");
            empF = emps.findEmp();
            if(empF.empCode) {
                cout << "======================" << endl;
                cout << "Employee code: " << empF.empCode << endl;
                cout << "First name: " << empF.firstName << endl;
                cout << "Last name: " << empF.lastName << endl;
                cout << "Salary: " << empF.salary << endl;
            } else {
                cout << "======================" << endl;
                cout << "Not found" << endl;
            }
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 3:
            system("cls");
            empS = emps.maxOfSalary();
            if(empS.empCode) {
                // block empty list
                cout << "======================" << endl;
                cout << "Employee code: " << empS.empCode << endl;
                cout << "First name: " << empS.firstName << endl;
                cout << "Last name: " << empS.lastName << endl;
                cout << "Salary: " << empS.salary << endl;
            } else {
                cout << "======================" << endl;
                cout << "Employees is empty" << endl;
            }
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 4:
            system("cls");
            emps.sort();
            cout << "After sorted" << endl;
            emps.showEmpList();
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 5:
            system("cls");
            writeToOutputFile(empF, empS, emps);
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 6:
            cout << "\t\t\t\t  Exited";
            break;
        default:
            system("cls");
            showMenu();
            cout << "\t\t\t\t  Wrong option!" << endl;
            menuOption();
    }
}
void writeToInputFile(empList emps) {
    ofstream myfile;
    myfile.open("input3.txt");
    for(int i = 0; i < emps.n; i++) {
        myfile << emps.ds[i].empCode << endl;
        myfile << emps.ds[i].lastName << endl;
        myfile << emps.ds[i].firstName << endl;
        myfile << emps.ds[i].salary << endl;
    }
    myfile.close();
    cout << "Writed to file" << endl;
}
void writeToOutputFile(Employee empF, Employee empS, empList emps) {
    ofstream myfile;
    myfile.open("output3.txt");

    myfile << "======================" << endl;
    myfile << "Find employees result: " << endl;
    cout << "======================" << endl;
    cout << "Find employees result: " << endl;
    if(empF.empCode) {
        myfile << "Employee code: " << empF.empCode << endl;
        myfile << "First name: " << empF.firstName << endl;
        myfile << "Last name: " << empF.lastName << endl;
        myfile << "Salary: " << empF.salary << endl;
        cout << "Employee code: " << empF.empCode << endl;
        cout << "First name: " << empF.firstName << endl;
        cout << "Last name: " << empF.lastName << endl;
        cout << "Salary: " << empF.salary << endl;
    } else {
        myfile << "Not found" << endl;
        cout << "Not found" << endl;
    }

    myfile << "======================" << endl;
    myfile << "Max of salary result: " << endl;
    cout << "======================" << endl;
    cout << "Max of salary result: " << endl;
    if(empS.empCode) {
        // block empty list
        myfile << "Employee code: " << empS.empCode << endl;
        myfile << "First name: " << empS.firstName << endl;
        myfile << "Last name: " << empS.lastName << endl;
        myfile << "Salary: " << empS.salary << endl;
        cout << "Employee code: " << empS.empCode << endl;
        cout << "First name: " << empS.firstName << endl;
        cout << "Last name: " << empS.lastName << endl;
        cout << "Salary: " << empS.salary << endl;
    } else {
        myfile << "Employees is empty" << endl;
        cout << "Employees is empty" << endl;
    }
    myfile << "======================" << endl;
    myfile << "Employees after sorted: " << endl;
    cout << "======================" << endl;
    cout << "Employees after sorted: " << endl;
    int tmp = emps.ds.size();
    if(tmp) {
        for(int i = 0; i < tmp; i++) {
            myfile << "Employee code: " << emps.ds[i].empCode << endl;
            myfile << "First name: " << emps.ds[i].firstName << endl;
            myfile << "Last name: " << emps.ds[i].lastName << endl;
            myfile << "Salary: " << emps.ds[i].salary << endl;
            cout << "Employee code: " << emps.ds[i].empCode << endl;
            cout << "First name: " << emps.ds[i].firstName << endl;
            cout << "Last name: " << emps.ds[i].lastName << endl;
            cout << "Salary: " << emps.ds[i].salary << endl;
        }
    } else {
        myfile << "Employees is empty" << endl;
        cout << "Employees is empty" << endl;
    }

    myfile.close();
    cout << endl << "Writed to output1.txt" << endl;
}
bool returnMenu() {
    cout << "Enter H to return to the menu:> "; cin >> rtnmenu;
    if(rtnmenu == 'h' || rtnmenu == 'H') {
        return true;
    } return false;
}
