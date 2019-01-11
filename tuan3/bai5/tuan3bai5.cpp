#include<iostream>
#include<string>
using namespace std;
void LRS(string &x,string &y)
{
	int dem = 0;
	int n = x.length();
	for(int i = 0; i< n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(x[i]==x[j] && y.find(x[i])==-1)
			{
				y += x[i];
				dem++;
			}
		}
	}
	cout <<"Do dai chuoi lap lai la: "<<dem<<endl;
	cout <<"Chuoi lap lai la: "<<y<<endl;
}
int main()
{
	string y;
	string s;
	cout <<"Nhap chuoi s: ";
	getline(cin,s);
	LRS(s,y);
}
