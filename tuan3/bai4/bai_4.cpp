#include<iostream> 
#include<string.h> 
using namespace std; 
void taobang(int table[100][100],char *x,char*y,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 || j==0)  // tai vi tri dau tien cua hang i cot j bang 0
			{
				table[i][j]=0; 
			}
			// truong hop ki tu bang nhau 
		
			if(x[i]==y[j])
			{
				 // vi tri tiep theo = bang vi tri truoc do +1
				table[i+1][j+1]=table[i][j]+1;
			}
			else {
					if(table[i][j+1]>table[i+1][j])
						table[i+1][j+1]=table[i][j+1];
					else table[i+1][j+1]=table[i+1][j];	
			}
		}
	}
}
void xuatbang(int table[100][100],char *x,char *y,int m, int n)
{
	cout<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<table[i][j]<<"\t"; //xuat bang ma ta da tinh dc tren phan taobang();
		}
		cout<<endl;
	}
}
void truy_vet(int table[100][100],char *x,char*y,int m,int n)
{
		for(int i=m;i>0;)
		{
			for(int j=n;j>0;)
			{
				if(x[i-1]==y[j-1] && table[i-1][j-1]==table[i][j-1] && table[i-1][j-1]==table[i-1][j])
				{
					char temp;
					temp=x[i-1];
					cout<<temp;
				}
				if(table[i-1][j-1] >= table[i][j-1] && table[i-1][j-1]>=table[i-1][j])
				{
					i--;
					j--;
				}
				else if(table[i][j-1] > table[i-1][j])
				{
					i--;
				}
				else {
					i--;
				}
				if(table[i][j]==0)
				{
					return ;
				}
			}
		}
}
int main()
{
	char x[] = "CAGATAGAG"; 
  char y[] = "AGCGA"; 
  int m = strlen(x); // do dai cua chuoi x
  int n = strlen(y);// dai cua chuoi y
  int table[100][100] ;
  taobang(table,x,y,m,n);
  cout<<"xuat bang tinh do dai:"<<endl;
  xuatbang(table,x,y,m,n);
  cout<<"do dai cua chuoi la:"<<table[m][n]<<endl;
  cout<<"day ki tu con chung dai nhat: ";
  truy_vet(table,x,y,m,n);	
}
