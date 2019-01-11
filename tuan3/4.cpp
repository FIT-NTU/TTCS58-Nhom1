#include <iostream>
#include <algorithm>
#include <string.h>
#include<cstring> 
#include<cstdlib>
using namespace std;

int n, m;
char X[255];
char Y[255];


void nhap()
{
	cout << "Nhap vao chuoi X: ";
	gets(X);
	cout << "Nhap vao chuoi Y: ";
	gets(Y);
}

void xuat()
{
	cout <<"Chuoi X: "<<X<<endl;
	cout <<"Chuoi Y: "<<Y<<endl;
}

void LCS(char *X, char *Y, int m, int n)
{
	m = strlen(X);
	n = strlen(Y);
	int L[n+1][m+1]; // Khoi tao mang LCS co kich thuoc [n+1][m+1]
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i==0 || j==0)
			{
				L[i][j]=0;
			}
			else if (X[i-1] == Y[j-1])
			{
				L[i][j] = L[i-1][j-1]+1;
			}
			else
			{
				L[i][j] = max (L[i-1][j], L[i][j-1]);
			}
		}
	}
	int tam=L[m][n];
	char LCS[tam+1];
	int i = m;
	int j = n;
	while (i>0 && j>0)
	{
		if (X[i-1] == Y[j-1])
		{
			LCS[tam-1] = X[i-1];
			i--;
			j--;
			tam--;
		}
		else if (L[i-1][j] > L[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	cout << "Chuoi ngan nhat cua "<<X<<" va "<<Y<<" la: "<<LCS;	
}

int main ()
{
	nhap ();
	xuat ();
	LCS(X, Y, m, n);
	return 0;
}
