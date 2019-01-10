#include <iostream>
#include <string.h>

using namespace std;

string lcs(string str1, string str2);
int max(int a, int b);

int main() {
    string str1 = "XMJYAUZ";
    string str2 = "MZJAWXU";
    string s = lcs(str1, str2);
    cout << "Chuoi chung co do dai lon nhat la: " << s.length() << endl;
    cout << "Chuoi tim duoc la: " << s << endl;
}

string lcs(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    int L[m + 1][n + 1];
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                L[i][j] = 0;
            } else if(str1[i - 1] == str2[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            cout << L[i][j] << " ";
        } cout << endl;
    }
    int length = L[m][n];
    string str = "";

    while(length) {
        while(L[m][n] == L[m - 1][n]) {
            m--;
        }
        while(L[m][n] == L[m][n - 1]) {
            n--;
        }
        str += str2[n - 1];
        m--; n--;
        length--;
    }
    return str;
}
int max(int a, int b) {
    return a > b ? a:b;
}