#include <iostream>
#include <string.h>

using namespace std;

string lrs(string str);
int max(int a, int b);

int main() {
    string str = "AABBAAB";

    string s = lrs(str);
    cout << "Chuoi lap lai dai nhat la: " << s.length() << endl;
    cout << "Chuoi tim duoc la: " << s << endl;
}

string lrs(string str) {
    int n = str.length();

    int L[n + 1][n + 1];
    int truyvet[n + 1][n + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                L[i][j] = 0;
                truyvet[i][j] = 0;
            } else if(str[i - 1] == str[j - 1] && i != j) {
                L[i][j] = L[i - 1][j - 1] + 1;
                truyvet[i][j] = 0; // cheo
            } else if(str[i - 1] == str[j - 1] && i == j) {
                L[i][j] = L[i][j - 1];
                truyvet[i][j] = 1; // trai
            } else if(str[i - 1] != str[j - 1] && L[i][j - 1] >= L[i - 1][j]) {
                L[i][j] = L[i][j - 1];
                truyvet[i][j] = 1; // trai
            } else {
                L[i][j] = L[i - 1][j];
                truyvet[i][j] = 2; // tren
            }
        }
    }
    
    int length = L[n][n];
    int x = n, y = n;
    string s = "";
    
    while(length) {
        if(truyvet[x][y] == 0) {
            s += str[x - 1];
            length--;
            x--;
            y--;
        } else if(truyvet[x][y] == 1) {
            y--;
        } else {
            x--;
        }
    }
    string res = "";
    for(int i = s.length() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}
int max(int a, int b) {
    return a > b ? a:b;
}