#include<iostream>
using namespace std;
#include<fstream>
int a[20],b[20],n,p;
ofstream g ("output4.txt");
void nhap(int a[],int n)
{
	ofstream f;
	f.open("Input4.txt");
	f<<n<<endl;
	for(int i=0;i<n;i++)
	{
		printf("a[%d] : ",i);
		scanf("%d",&a[i]);
		f<<a[i]<<"\t";
	}
}
void duyet()
{
	int tong=0,i,j;
	for(i=0;i<n;i++)
		if(b[i]==1)
			tong=tong+a[i];
	if(tong==p)
	{
		for(j=0;j<n;j++)
		{
			if(b[j]==1)
			{
				printf("1");
				g<<"1";
			}
			else
			{
				printf("0");
				g<<"0";
			}
		}
		printf("\n");
		g<<endl;
	}
}
void kt(int i)
{
	int j,tong=0;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(i<n-1)
			kt(i+1);
		else
			duyet();
	}
}
int main()
{
	ifstream k;
	k.open("input4.txt");
	if(k!=NULL)
	{
		k>>n;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		{
			k>>a[i];
			cout<<a[i]<<" ";
		}
	}
	else
	{
		do
		{
			cout<<"n : ";
			cin>>n;
		}while(n<2||n>20);
		nhap(a,n);
	}
	printf("\n");
	printf("P : ",p);
	scanf("%d",&p);
	kt(0);
	k.close();
	g.close();
	return 0;
}
