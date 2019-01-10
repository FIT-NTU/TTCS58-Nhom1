#include <iostream>
#include <string.h>

using namespace std;

string lrs(string str);
int max(int a, int b);

int main() {
    string str = "AABEBCDD";

    string s = lrs(str);
    cout << "Chuoi lap lai dai nhat la: " << s.length() << endl;
    cout << "Chuoi tim duoc la: " << s << endl;
}

string lrs(string str) {
    int n = str.length();

    int L[n + 1][n + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                L[i][j] = 0;
            } else if(str[i - 1] == str[j - 1] && i != j) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    int length = L[n][n];
    string s = "";

    int i = 1;
    while(length) {
        if(L[i][n] != L[i - 1][n]) {
            s += str[i - 1];
            length--;
        }
        i++;
    }
    return s;
}
int max(int a, int b) {
    return a > b ? a:b;
}