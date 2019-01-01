#include<iostream>
#include<fstream>
using namespace std;
int a[50],b[50];
int n,S,P;
ofstream outfile("output4.txt");
void Docfile()
{
	ifstream infile("input4.txt");
	infile >> n;
	infile >> P;
	for(int i = 0; i < n; i++)
	{
		infile >> a[i];
	}
}
void InKQ()
{
	int temp=0;
	int j;
	for(j = 0 ;j < n; j++) 
	if (b[j] == 1) 
	temp = temp + a[j];
	if (temp==P)
		{for (j = 0;j < n; j++)
			if(b[j] == 1)
			{
				cout << "1";
				outfile << "1";
			}
			else
			{
				cout << "0";
				outfile << "0";
			}
		cout << endl;
		outfile << endl;
		}
}
void Try(int i)
{
	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(b[i]==1)
			S =S + a[i];
		if((i<n-1)&&( S < P)) 
			Try(i+1);
		else  
		{
			InKQ();
		}
		if (b[i]==1) 
			S=S - a[i];
		b[i]=0;	
	}
}

int main()
{
	Docfile();
	Try(0);
	system("pause");
	return 0;
}
