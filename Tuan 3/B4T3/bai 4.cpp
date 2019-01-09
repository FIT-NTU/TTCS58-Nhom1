#include<stdio.h>
#include<conio.h>
#include<string.h>

char x[255];
char y[255];
int m, n;
int c[255][255];
int b[255][255];

void nhap()
{
	FILE *o;
	o=fopen("b4.txt","r");
	fgets(x,255,o);
	fgets(y,255,o);
	printf("da nhap chuoi thanh cong !!!\n");
	fclose(o);
	m=strlen(x);
	n=strlen(y);	 
	for(int i=0;i<m;i++)
	{
		printf("%c",x[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%c",y[i]);
	}
}
int max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}

void khoitao()
{
	int i ;
	int j ;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			c[i][j]=0;
			b[i][j]=0;
		}
	}
}

void inmatran()
{
	int i;
	int j;
	printf("\nma tran trong so\n");
	for(int i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d",c[i][j]);
		}
		printf("\n");
	}
	printf("\nma tran luu vet\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d",b[i][j]);
		}
		printf("\n");
	}
}
void LCS()
{
	int i,j;
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(x[i]==y[j])
			{
				c[i+1][j+1]=c[i][j]+1;
				b[i+1][j+1]=0;
			}else
			{
				if(c[i+1][j]>=c[i][j+1])
				{
					c[i+1][j+1]=c[i+1][j];
					b[i+1][j+1]=1;
				}else
				{
					c[i+1][j+1]=c[i][j+1];
					b[i+1][j+1]=2;
				}
			}
		}
	}
	inmatran();
}
void inketqua()
{
	int i;
	int j;
	int itam=0;
	i=m=strlen(x);
	j=n=strlen(y);
	printf("\nchuoi tim duoc la :");
	while(i>0&&j>0)
	{
		if(b[i][j]==0)
		{
			printf("%c",x[i-1]);
			itam++;
			i--;
			j--;
		}
		else 
		{
			if(b[i][j]==1)
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	printf("\nchuoi chung co do dai lon nhat : %d",itam);

}

int main()
{
	nhap();
	khoitao();
	LCS();
	inketqua();
	getch();
}
