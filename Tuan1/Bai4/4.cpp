#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;

int n, p, count;
vector<int> arr, result;

void readFile();
bool check(vector<int> bin);
void backtracking(vector<int> bin, int n, int i = 0);
void pushToResult(vector<int> bin);
void showResult();
void writetoFile();

int main() {
    readFile();
    cout << n << " " <<  p << endl;
    vector<int> bin;
    bin.resize(n);
    backtracking(bin, n);
    if(count) {
        cout << count;
        showResult();
    } else {
        cout << "Khong chia duoc" << endl;
    }
    writetoFile();
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
//		if(bin[0] == 1) break;
        if(i == n - 1) {
            if(check(bin)) {
                pushToResult(bin);
                count++;
            }
        } else {
            backtracking(bin, n, i + 1);
        }
    }
}
void pushToResult(vector<int> bin) {
    result.insert(result.begin(), bin.begin(), bin.end());
}
void showResult() {
    int tmp = result.size();
    for(int i = 0; i < tmp; i++) {
        if(i % n == 0) {
            cout << endl;
        }
        cout << result[i] << " ";
    } cout << endl;
}
void writetoFile() {
    ofstream myfile;
    myfile.open("output4.txt");

    if(count) {
        myfile << count;

        int tmp = result.size();
        for(int i = 0; i < tmp; i++) {
            if(i % n == 0) {
                myfile << endl;
            }
            myfile << result[i] << " ";
        }
    } else {
        myfile << "Khong chia duoc" << endl;
    }
    myfile.close();
    cout << "Writted result to output4.txt";
}
