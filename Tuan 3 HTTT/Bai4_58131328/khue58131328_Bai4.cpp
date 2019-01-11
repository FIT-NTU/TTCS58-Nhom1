#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#include<fstream>
void lcs(char *X,char *Y,int m,int n)
{ 
	int L[m+1][n+1]; 
	for(int i=0;i<=m;i++) 
	{ 
		for(int j=0;j<=n;j++) 
		{ 
			if(i==0||j==0) 
				L[i][j]=0; 
			else if(X[i-1]==Y[j-1]) 
				L[i][j]=L[i-1][j-1]+1; 
			else
			{
				if(L[i-1][j]>L[i][j-1])
					L[i][j]=L[i-1][j];
				else
					L[i][j]=L[i][j-1];
			}
		} 
	}
	int index=L[m][n]; 
	char lcs[index+1]; 
	lcs[index]=' ';
	int i=m,j=n; 
	while(i>0&&j>0) 
	{ 
		if(X[i-1]==Y[j-1]) 
		{ 
			lcs[index-1]=X[i-1];
			i--;
			j--;
			index--;
		}
		else if(L[i-1][j]>L[i][j-1]) 
			i--; 
		else
			j--;
	}
	cout<<endl;
	cout<<"Chuoi chung co do dai lon nhat la : "<<L[m][n]<<endl;
	cout<<"Chuoi tim duoc la : "<<lcs<<endl;
} 
int main() 
{ 
	char X[255],Y[255],s[255];
	ifstream f;
	f.open("input4.txt");
	if(f!=NULL)
	{
		f.getline(s,255);	strcpy(X,s);
		f.getline(s,255);	strcpy(Y,s);
		cout<<X<<endl<<Y;
		int m=strlen(X);
		int n=strlen(Y);
		lcs(X,Y,m,n);
	}
	else
	{
		cout<<"Chuoi X : ";	cin.getline(X,255);
		cout<<"Chuoi Y : ";	cin.getline(Y,255);
		ofstream g;
		g.open("input4.txt");
		g<<X<<endl<<Y<<endl;
		int m=strlen(X);
		int n=strlen(Y);
		lcs(X,Y,m,n);
	}
	return 0;
}
