#include <stdio.h>
#include <conio.h>
#include<iostream>
#include<fstream>
int a[100];
using namespace std;
int P;int n;
int dem = 0;
int tam[20];
int b[20][20];
int tong=0,k=0;
void DocFile(){
	ifstream f;
	f.open("input4.txt", ios::in);
	f>>n >>P;// so phan tu mang va so P 
	for(int i=0;i<n;i++){
		f>>a[i];
	}
	f.close();
}
void DemCachChon(){
	for(int i = 0;i<n;i++)
	{
		b[dem][i] = tam[i];
	}
}
void Xuat(){
	for(int i=0;i<dem;i++){
		for(int j=0;j<n;j++){
			cout<<b[i][j]<<" ";
		}
	}
}
void Try(int tong, int k) {
	for (int i = k; i < n; i++) {
		if ((tong + a[i]) <= P) {
			tong = tong + a[i];
			tam[i] = 1;
			if (tong == P) {
				DemCachChon();
				dem++;
			}
			else {
				Try(tong, i + 1);
			}
			tong = tong - a[i];
			tam[i] = 0;
		}
	}
}
void GhiFile(){
	ofstream f;
	f.open("output4.txt", ios::out);
	f <<"So cach chon qua la: "<< dem << endl;
	for (int i = 0; i < dem; i++) {
			for (int j = 0; j < n; j++) {
				f << b[i][j] << " " ;
			}
	}
}
int main()
{
	DocFile();
	Try(tong, k);
	if (dem == 0) {
		cout << "Khong chon duoc" << endl;
	}
	else {
		cout << dem << endl;
		Xuat();
	}
	GhiFile();
	getch();
	return 0;
}
