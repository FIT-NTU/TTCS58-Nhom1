#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // thu vien cua setw()
using namespace std;

int socach = 0, n;

vector< int > givegift; // tao vector rong kieu int.
vector< vector< int > > xuat; // tao vector 2 chieu rong.

void docfile(int &n, int &p, vector< int > &a){
	ifstream inf;
	inf.open("input4.txt");
	inf >> n;
		inf.ignore(256, ' '); // doc ki tu cho den khi gap khoang trang thi dung lai de doc ki tu khac.
		if( n >= 2 && n <= 20 )
		{	cout << n << " ";
			inf >> p; 
				inf.ignore(256, '\n'); // doc ki tu cho den khi gap dau xuong hang thi dung lai.
			cout << p << endl;
			a.resize(n);
			for(int i = 0; i < n-1; i++)
			{
				int temporary;
				inf >> temporary;
				cout << temporary << " ";
				a[i] = temporary;
				inf.ignore(256, ' '); // doc ki tu cho den khi gap khoang trang thi dung lai de doc ki tu khac.
			}
			inf >> a[n-1]; // ki tu cuoi cung khong co khoang trang' nam cuoi nen phai doc rieng.
			cout << a[n-1] << endl << endl;
		}
		else
		{	cout << "\t Gia tri n khong hop le. Yeu cau kiem tra lai gia tri n trong file input4.txt" << endl;
			system("pause");
		}
}

void backtracking( vector< int > a, int binary, int p)
{
    if (binary == n and !p ) // p==0 tuong duong !p
    {
    	//truong hop dung
        socach++;
        xuat.push_back(givegift); // them 1 phan tu vao vi tri sau cung cua vector
    }

    if (binary < n and p >= 0) //chi chay tu 0 toi n-1
	{
		//viet ra tat ca cac truong hop dung
        givegift[binary] = 1;
        backtracking (a, binary+1, p-a[binary]);
        givegift[binary] = 0;
        backtracking (a, binary+1, p);
    }
}

void output(){
	ofstream outf;
	outf.open("output4.txt", ios::out | ios::trunc);
	if (socach == 0)
	{
		cout << "Khong chon duoc...!";
		outf << "Khong chon duoc...!";
	}
    else 
	{
	    cout << " Co  " << socach << "  cach chon qua cho doi dat giai nhat." << endl;
	    outf << " Co  " << socach << "  cach chon qua cho doi dat giai nhat." << endl;
	    for (int i = 0; i < socach; i++)
		{
			cout << "cach " << i+1 << ": ";
			outf << "cach " << i+1 << ": ";
	        for (int j = 0; j < n; j++)
	        {
	        	// setw dung de thay doi do rong cua mang khi xuat ra.
	            cout << setw(4) << xuat[i][j]; 
	            outf << setw(4) << xuat[i][j];
	        }
	        cout << endl;
	        outf << endl;
	    }
    }
    outf.close();
}

int main()
{
    int p;
    vector< int > giftvalue;
    docfile(n, p, giftvalue);
    givegift.resize(n);
    backtracking(giftvalue, 0, p);
    output();
}
