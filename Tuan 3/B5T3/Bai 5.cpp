#include<stdio.h>
#include<conio.h>
#include<string.h>

char x[255];
char y[255];
int m;
int c[255][255];
int b[255][255];

void nhap()
{
	FILE *o;
	o=fopen("b5.txt","r");
	fgets(x,255,o);
	printf("da nhap chuoi thanh cong !!!\n");
	fclose(o);
	m=strlen(x);	 
	for(int i=0;i<m;i++)
	{
		y[i]=x[i];
	}
	for(int i=0;i<m;i++)
	{
		printf("%c",y[i]);
	}
}
/*int max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}*/

void khoitao()
{
	int i ;
	int j ;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
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
	for(int i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d",c[i][j]);
		}
		printf("\n");
	}
	printf("\nma tran luu vet\n");
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d",b[i][j]);
		}
		printf("\n");
	}
}
void LRS()
{
	int i,j;
	m=strlen(x);
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		{
			if((x[i]==y[j])&&(i==j))
			{
				c[i+1][j+1]=c[i+1][j];
				b[i+1][j+1]=1;//trai
			}
			if((x[i]!=y[j])&&(c[i+1][j]>c[i][j+1]))
			{
				c[i+1][j+1]=c[i+1][j];
				b[i+1][j+1]=1;//trai
			}else{
				c[i+1][j+1]=c[i][j+1];
				b[i+1][j+1]=2;//tren
			}
			if((x[i]==y[j])&&(i!=j))
			{
				c[i+1][j+1]=c[i][j]+1;
				b[i+1][j+1]=0;//cheo
			}
			
		}
	}
	inmatran();
	printf("chuoi lap lai dai nhat : %d\n",c[i][j]);
}
void inketqua()
{
	int i;
	int j;
	int itam=0;
	char tam[3];
	m=strlen(x);
	printf("\nchuoi tim duoc la : ");
	i=m;j=m;
	while(i>0&&j>0)
	{
		if(b[i][j]==0)
		{
			//printf("%c",x[i-1]);
			itam++;
			tam[itam]=x[i-1];
			i--;
			j--;
		}else
		if(b[i][j]==2)
		{
			i--;
		}else
		{
			j--;
		}	
	}
	
	while(itam>0)
	{
		printf("%c",tam[itam]);
		itam--;
	}
}	
	



int main()
{
	nhap();
	khoitao();
	LRS();
	inketqua();
	getch();
}
