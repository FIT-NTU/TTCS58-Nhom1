#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

// define
struct Employee {
    int empCode;
    string firstName; // ten
    string lastName; // ho
    int salary;
} empF, empS; // employee finded, employee have max of salary
class empList {
    private:
        int n; //numbers of employee;
    public:
    	vector<Employee> ds;
        void enterEmpList();
        void showEmpList();
        Employee findEmp();
        Employee maxOfSalary();
        void sort();
};
empList emps;
int mo; // menu option
char rtnMenu; // return to menu

void showMenu();
void menuOption();
void enterEmps();
void writeToInputFile(empList emps);
void writeToOutputFile(Employee empF, Employee empS, empList emps);
bool returnToMenu();

int main() {
    showMenu();
    menuOption();
}

void empList::enterEmpList() {
    cout << "Enter quantity: "; cin >> n;
    ds.resize(n);
    for(int i = 0; i < n; i++) {
        cout << "======================" << endl;
        cout << "Employee code: ";
        cin >> ds[i].empCode;
        cout << "\nFirst name: ";
        fflush(stdin);
        getline(cin, ds[i].firstName);
        cout << "\nLast name: ";
        fflush(stdin);
        getline(cin, ds[i].lastName);
        cout << "\nSalary: ";
        cin >> ds[i].salary;
    }
}
void empList::showEmpList() {
    if(n) {
        for(int i = 0; i < n; i++) {
            cout << "======================" << endl;
            cout << "Employee code: " << ds[i].empCode;
            cout << "\nFirst name: " << ds[i].firstName << endl;
            cout << "\nLast name: " << ds[i].lastName << endl;
            cout << "\nSalary: " << ds[i].salary << endl;
        }
    } else {
        cout << "======================" << endl;
        cout << "Employees is empty" << endl;
    }
}
Employee empList::findEmp() {
    int empCode;
    cout << "Enter employee code:> "; cin >> empCode;

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(ds[i].empCode == empCode) {
            return ds[i];
        }
    }
    return empF;
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
        }
        return ds[key];
    } else {
        return empS;
    }
}
void empList::sort() {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            if(ds[i].firstName.compare(ds[j].firstName) > 0) {
                // if ds[i].firstName > ds[i + 1].firstName
                // ASCII greater
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
void showMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t1. Enter employees" << endl;
    cout << "\t\t\t\t2. Find employee" << endl;
    cout << "\t\t\t\t3. Max of salary" << endl;
    cout << "\t\t\t\t4. Sort employee list by name" << endl;
    cout << "\t\t\t\t5. Save to output file" << endl;
    cout << "\t\t\t\t6. Exit" << endl;
}
void menuOption() {
    cout << "\t\t\t\t  Enter your choice:> "; cin >> mo;

    switch(mo) {
        case 1:
            system("cls");
            emps.enterEmpList();
            writeToInputFile(emps);
            if(returnToMenu()) {
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
                cout << "Employee code: " << empF.empCode;
                cout << "\nFirst name: " << empF.firstName << endl;
                cout << "\nLast name: " << empF.lastName << endl;
                cout << "\nSalary: " << empF.salary << endl;
                cout << "======================" << endl;
            } else {
                cout << "======================" << endl;
                cout << "Not found" << endl;
            }
            if(returnToMenu()) {
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
                cout << "Employee code: " << empS.empCode;
                cout << "\nFirst name: " << empS.firstName << endl;
                cout << "\nLast name: " << empS.lastName << endl;
                cout << "\nSalary: " << empS.salary << endl;
                cout << "======================" << endl;
            } else {
                cout << "======================" << endl;
                cout << "Employees is empty" << endl;
            }
            if(returnToMenu()) {
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
            if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 5:
            writeToOutputFile(empF, empS, emps);
            if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 6:
            cout << "\t\t\t\t  Exited" << endl;
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
    int len = emps.ds.size();
    for(int i = 0; i < len; i++) {
        myfile << "======================" << endl;
        myfile << "Emp code: " << emps.ds[i].empCode << endl;
        myfile << "First name: " << emps.ds[i].firstName << endl;
        myfile << "Last name: " << emps.ds[i].lastName << endl;
        myfile << "Salary: " << emps.ds[i].salary << endl;
    }
    myfile.close();
    cout << "\nWrited to input1.txt\n\n";
}
void writeToOutputFile(Employee empF, Employee empS, empList emps) {
    fstream myfile;
    myfile.open("output3.txt", ios::app);

    myfile << "Find employees result: " << endl;
    if(empF.empCode) {
        myfile << "Employee code: " << empF.empCode;
        myfile << "\nFirst name: " << empF.firstName << endl;
        myfile << "\nLast name: " << empF.lastName << endl;
        myfile << "\nSalary: " << empF.salary << endl;
        myfile << "======================" << endl;
    } else {
        myfile << "Not found\n\n";
    }

    myfile << "Max of salary result: " << endl;
    if(empS.empCode) {
        // block empty list
        myfile << "Employee code: " << empS.empCode;
        myfile << "\nFirst name: " << empS.firstName << endl;
        myfile << "\nLast name: " << empS.lastName << endl;
        myfile << "\nSalary: " << empS.salary << endl;
        myfile << "======================" << endl;
    } else {
        myfile << "Employees is empty\n\n";
    }
    myfile << "Employees after sorted: " << endl;
    int tmp = emps.ds.size();
    if(tmp) {
        for(int i = 0; i < tmp; i++) {
            myfile << "======================" << endl;
            myfile << "Employee code: " << emps.ds[i].empCode;
            myfile << "\nFirst name: " << emps.ds[i].firstName << endl;
            myfile << "\nLast name: " << emps.ds[i].lastName << endl;
            myfile << "\nSalary: " << emps.ds[i].salary << endl;
        }
    } else {
        myfile << "Employees is empty\n\n";
    }

    myfile.close();
    cout << "\nWrited to output1.txt\n\n";
}
bool returnToMenu() {
    cout << "Enter H to return to the menu:> "; cin >> rtnMenu;

    if(rtnMenu == 'H' || rtnMenu == 'h') {
        return true;
    } return false;
}