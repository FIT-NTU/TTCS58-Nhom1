//HO NGOC CHUNG
//58133211
//58-CNTT1

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string a,b;
void nhap()
{
	cout<<"Nhap chuoi A: ";
	cin>>a;
	cout<<"Nhap chuoi B: ";
	cin>>b;
}

void lcs() 
{
	vector <char> arr;
    int m = a.size(), n = b.size(), temp  = 0;
    vector< vector<int> > f(m+1, vector<int>(n+1, 0));
    for (int i=1; i<=m; i++) for (int j=1; j<=n; j++) 
	{
        if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
        else f[i][j] = max(f[i-1][j], f[i][j-1]);
    }
	temp = f[m][n];
    while (temp != 0){
    	if (f[m][n] == temp) {
    		temp -=1;
    		m -= 1;
    		n -= 1;
    		arr.push_back(a[m]);
		} else if (f[m][n] == f[m - 1][n]){
			m -= 1;
		} else if (f[m][n] == f[m][n - 1]) {
			n -=1;
		}
	}
	reverse(arr.begin(), arr.end()); //DAO NGUOC VA XUAT CHUOI RA MAN HINH
	cout << "Do dai chuoi la: " << arr.size() << endl;
	cout<<"Chuoi tim duoc la: ";
	for (int i = 0; i < arr.size(); i++) 
	{
		cout << arr[i] << "";
	}
}

int main() 
{
	nhap();
    ios::sync_with_stdio(false); cin.tie(0);
	lcs();
}
