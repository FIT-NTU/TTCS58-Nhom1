#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void LRS(string s)
{
    int n=s.length();
    int LV[n+1][n+1];	//Luu vet
    int TS[n+1][n+1];	//Trong so
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
        	LV[i][j]=0;
        	TS[i][j]=0;
		}
	}
	
	for(int i=0;i<=n;i++)
		cout<<" "<<s[i];
	cout<<endl;
	for(int j=0;j<=n;j++)
		cout<<s[j]<<endl;
	cout<<endl;
	
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (s[i-1]==s[j-1]&&i!= j)
            {
            	TS[i][j]=TS[i-1][j-1]+1;
            	LV[i][j]=i;
			}
            else
            {
            	if(TS[i][j-1]>TS[i-1][j])
            		TS[i][j]=TS[i][j-1];
            	else
            		TS[i][j]=TS[i-1][j];
			}
			cout<<" "<<TS[i][j];
        }
        cout<<endl;
    }
    cout<<"Ma tran luu vet : "<<endl;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
			cout<<" "<<LV[i][j];
		cout<<endl;
	}

	cout<<"Chuoi tim duoc la : ";
	for(int k=1;k<=n;k++)
	{
		for(int h=1;h<=n;h++)
		{
			if(LV[k][h]!=0)
			{
				int max=LV[k][h];
				if(max<LV[k+1][h-1])
				{
					max=LV[k+1][h-1];
					k++;
					h--;
				}
				else
				{
					while(k<n&&h>0)
					{
						if(max<LV[k+1][h-1])
							max=LV[k+1][h-1];
						k++;
						h--;
					}
				}
				int tam=max;
				cout<<s[tam-1];
			}
		}
	}
	cout<<endl;
	cout<<"Chuoi lap lai dai nhat la : "<<TS[n][n];
}
int main() 
{
    string s;
    ifstream g;
    g.open("input5.txt");
    if(g!=NULL)
    {
    	getline(g,s);
    	cout<<"Du lieu tu file : "<<s<<endl;
    	LRS(s);
	}
	else
	{
		cout<<"Nhap du lieu cho chuoi X : ";	getline(cin,s);
		LRS(s);
	    ofstream f;
	    f.open("input5.txt");
	    f<<s;
	   f.close();
	}
	g.close();
    return 0;
}
