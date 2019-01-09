#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void readFile(vector<int> &ints);
void typingVectorInteger(vector<int> &ints);
void showVectorInteger(vector<int> ints);
void sortVector(vector<int> &ints);
bool haveX(vector<int> ints, int x);
void insertToVector(vector<int> &ints, int x);
void deleteInVector(vector<int> &ints, int x);
void deleteSame(vector<int> &ints);

int main() {
    vector<int> intList;

    // typingVectorInteger(intList);
    // cout << "--Vector vua nhap" << endl;
    readFile(intList);
    showVectorInteger(intList);

    // Sap xep day so theo chieu tang dan
    sortVector(intList);
    cout << "--Vector sau khi sap xep" << endl;
    showVectorInteger(intList);

    // Nhap vao 1 so X va kiem tra X co ton tai khong, neu X chua ton tai thi chen x vao
    int x;
    cout << "Nhap vao X: "; cin >> x;
    if(haveX(intList, x)) {
        cout << x << " ton tai trong day so" << endl;
        deleteInVector(intList, x);
        cout << "--Vector sau khi xoa " << x << endl;
        showVectorInteger(intList);
    } else {
        cout << x << " khong ton tai trong day so" << endl;
        insertToVector(intList, x);
        cout << "--Vector sau khi them " << x << endl;
        showVectorInteger(intList);
    }
    // Xoa cac phan tu trung lap
    deleteSame(intList);
    cout << "--Vector sau khi xoa trung lap" << endl;
    showVectorInteger(intList);
}
// Nhap vector tu file
void readFile(vector<int> &ints) {
    ifstream myfile;
    myfile.open("data.txt");
    
    string line;
    getline(myfile, line);
    int n = atoi(line.c_str());

    for(int i = 0; i < n; i++) {
        getline(myfile, line);
        int tmp = atoi(line.c_str());
        ints.push_back(tmp);
    }
}

// Nhap vao 1 vector so nguyen
void typingVectorInteger(vector<int> &ints) {
    int tmp;
    cout << "So luong phan tu: "; cin >> tmp;
    ints.resize(tmp);
    for(int i = 0; i < tmp; i++) {
        cout << "Phan tu thu " << i + 1 << " : ";
        cin >> ints[i];
    }
}
// Hien thi vector so nguyen
void showVectorInteger(vector<int> ints) {
    int n = ints.size();
    for(int i = 0; i < n; i++) {
        cout << ints[i] << " ";
    } cout << endl;
}
// Sap xep vector
void sortVector(vector<int> &ints) {
    sort(ints.begin(), ints.end());
}
// Tim kiem x trong vector so nguyen
bool haveX(vector<int> ints, int x) {
    int n = ints.size();
    for(int i = 0; i < n; i++) {
        if(ints[i] == x) return true;
    } return false;
}
// Chen 1 phan tu vao vector
void insertToVector(vector<int> &ints, int x) {
    int n = ints.size();
    for(int i = 0; i < n; i++) {
        if(ints[i] > x) {
            ints.insert(ints.begin() + i, x);
            break;
        }
    }
}
// Xoa phan tu chi dinh
void deleteInVector(vector<int> &ints, int x) {
    for(int i = 0; i < ints.size(); i++) {
        if(ints[i] == x) {
            ints.erase(ints.begin() + i);
            i--;
        }
    }
}
// Xoa phan tu trung lap
void deleteSame(vector<int> &ints) {
    sortVector(ints);
    for(int i = 0; i < ints.size() - 1; i++) {
        if(ints[i] == ints[i + 1]) {
            ints.erase(ints.begin() + i);
            i--;
        }
    }
}