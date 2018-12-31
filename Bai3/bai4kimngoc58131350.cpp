#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

int dem=0, n;
vector< int > cachTang;
vector< vector< int > > xuat;

void docFile(int &n, int &m, vector< int > &a){
	ifstream infile;
	infile.open("input4.txt");
	infile>>n; infile.ignore(255, ' ');
	infile>>m; infile.ignore(255, '\n');
	a.resize(n);
	for(int i=0; i<n-1; i++)
	{
		int temp;
		infile>>temp;
		a[i]=temp;
		infile.ignore(255, ' ');
	}
	infile>>a[n-1];
}

void QLui(vector< int > a, int control, int m)
{
    if (control==n and m==0)
    {
    	// t/h dung
        dem++;
        xuat.push_back(cachTang);
    }

    if (control<n and m>=0) // chay tu 0 toi n-1
	{
		//vet can tat ca cac truong hop
        cachTang[control] = 1;
        QLui (a, control+1, m-a[control]);
        cachTang[control] = 0;
        QLui (a, control+1, m);
    }
}

void Ghifile(){
	ofstream outfile;
	outfile.open("output4.txt", ios::out | ios::trunc);
	if (dem==0)
	{
		cout<<"Khong chon duoc.";
		outfile<<"Khong chon duoc.";
	}
    else 
	{
	    cout<<"So cach chon : "<<dem<<"\n";
	    outfile<<"So cach chon : "<<dem<<"\n";
	    for (int i=0; i<dem; i++)
		{
	        for (int j=0;j<n;j++)
	        {
	            cout<<setw(3)<<xuat[i][j];
	            outfile<<setw(3)<<xuat[i][j];
	        }
	        cout<<"\n";
	        outfile<<endl;
	    }
    }
    outfile.close();
}

int main()
{
    int M;
    vector< int > GTMonQua;
    docFile(n, M, GTMonQua);
    cachTang.resize(n);
    QLui(GTMonQua, 0, M);
    Ghifile();
}

