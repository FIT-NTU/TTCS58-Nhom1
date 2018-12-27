/*
	Other display
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <windows.h>

using namespace std;

int n, p, count;
vector<int> arr, result;

void readFile();
bool check(vector<int> bin);
void backtracking(vector<int> bin, int n, int i = 0);
void pushToResult(vector<int> bin);
void showBinaryString(vector<int> bin);
void textColor(int n) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

int main() {
    readFile();
    vector<int> bin;
    bin.resize(n);
    backtracking(bin, n);
    // if(count) cout << count;
}

void readFile() {
    ifstream myfile;
    myfile.open("input4.txt");

    if(myfile.is_open()) {
        string line;
        getline(myfile, line);
        stringstream ss(line);
        ss >> n >> p;

        getline(myfile, line);
        stringstream sss(line);
        arr.resize(n);
        for(int i = 0; i < n; i++) {
            sss >> arr[i];
        }
    } else {
        cout << "Unable open to file" << endl;
    }

    myfile.close();
}
bool check(vector<int> bin) {

    int selected = 0;
    for(int i = 0; i < n; i++) {
        selected += bin[i] * arr[i];
    }
    if(selected == p)
        return true;
    return false;
}
void backtracking(vector<int> bin, int n, int i) {
    for(int j = 0; j <= 1; j++) {
        bin[i] = j;
        if(i == n - 1) {
            if(check(bin)) {
                textColor(12);
                count++;
            }
            showBinaryString(bin);
        } else {
            backtracking(bin, n, i + 1);
        }
    }
}
void pushToResult(vector<int> bin) {
    result.insert(result.begin(), bin.begin(), bin.end());
}
void showBinaryString(vector<int> bin) {
    for(int i = 0; i < n; i++) {
        cout << bin[i] << " ";
    } cout << endl;
    textColor(7);
}
