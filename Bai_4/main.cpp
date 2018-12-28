#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n, p, q=0; // q la so mang tim dc, n la so luong phan tu 
int a[10], temp[10];
int kq[10][10];

void readFile(string path) {
	ifstream file;
	file.open(path.c_str(), ios_base::in);
	if (file.is_open()) {
		file >> n >> p;
		for (int i = 0; i < n; i++) {
			file >> a[i];
		}
	}
	file.close();
}

void luuKQ() {
	for (int i = 0; i < n; i++) {
		kq[q][i] = temp[i];
	}
}

void xuat() {
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < n; j++) {
			cout << kq[i][j] << " ";
		}
		cout << endl;
	}
}

// n: so 
void backtrack(int s, int k) {
	for (int i = k; i < n; i++) {
		if ((s + a[i]) <= p) {
			s += a[i];
			temp[i] = 1;
			if (s == p) {
				luuKQ();
				q = q + 1;
			}
			else {
				backtrack(s, i + 1);
			}
			s -= a[i];
			temp[i] = 0;
		}
	}
}

void writeFile(string path) {
	ofstream file(path.c_str(), ios::out);
//	file.open(path, ios::out);
	if (file.is_open()) {
		file << q << endl;
		for (int i = 0; i < q; i++) {
			for (int j = 0; j < n; j++) {
				file << kq[i][j] << " " ;
			}
			file << endl;
		}
	}
}


int main() {
	int s = 0, k = 0;
	readFile("input4.txt");

	backtrack(s, k);
	if (q == 0) {
		cout << "Khong chon duoc" << endl;
	}
	else {
		cout << q << endl;
		xuat();
		writeFile("output4.txt");
	}
	system("pause");
}
