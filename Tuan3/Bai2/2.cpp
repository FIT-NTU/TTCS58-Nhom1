#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

using namespace std;

void readFile(vector<int> &ints);
void typingVectorInteger(vector<int> &ints);
void showVectorInteger(vector<int> ints);
void sortVector(vector<int> &ints);
int findX(vector<int> ints, int x);
int maxConsecutive(vector<int> ints);

int main() {
    vector<int> intList;
    vector<int> intList2;

    readFile(intList);
	// typingVectorInteger(intList);
    cout << "--Vector vua nhap" << endl;
    showVectorInteger(intList);

    // Copy intList to intList2
    for(int i = 0; i < intList.size(); i++) {
        intList2.push_back(intList[i]);
    }

    // Sap xep day so theo chieu tang dan
    sortVector(intList2);
    cout << "--Vector sau khi sap xep" << endl;
    showVectorInteger(intList2);

    // tim x (da sap xep)
    int x;
    cout << "Nhap x: "; cin >> x;
    if(findX(intList2, x) != -1) {
        cout << "Vi tri cua " << x << " : " << findX(intList2, x) << endl;
    } else {
        cout << "Khong tim thay " << x << endl;
    }
    // max
    cout << "Tong lon nhat lien tiep: " << maxConsecutive(intList) << endl;

}
// Lay du lieu tu file txt
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
// Tim kiem x thi nhi phan
int findX(vector<int> ints, int x) {
	
    int left = 0;
	int right = ints.size();
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == ints[mid]) 
			return mid;
		else if (x < ints[mid]) 
			right = mid - 1;
		else if (x > ints[mid]) 
			left = mid + 1;
	} 
	return -1;
}
// Tong lien tiep lon nhat
int maxConsecutive(vector<int> ints) {
    // Xoa so am ben trai
    while(ints[0] < 0) {
        ints.erase(ints.begin());
    }
    // Xoa so am ben phai
    int n = ints.size();

    while(ints[n - 1] <= 0) {
        ints.erase(ints.end() - 1);
        n--;
    }

    n = ints.size();
    int tmp;
    int arr[n][n];
    for(int i = 0; i < n; i++) {
        tmp = 0;
        for(int j = i; j < n; j++) {
            tmp += ints[j];
            arr[i][j] = tmp;
        }
    }
    int MAX = arr[0][0];
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(arr[i][j] > MAX) MAX = arr[i][j];
        }
    }
    return MAX;
}
