#include<stdio.h>
#include<conio.h>

FILE *x;
FILE *y;
int n;
int w[100];
int dem=0;
int b[100];
int pmax;
void docfile()
{
	int i,j;
	x=fopen("input4.txt","r");
	fscanf(x,"%d",&n);
	fscanf(x,"%d",&pmax);
	for(i=1;i<=n;i++)
	{		
		fscanf(x,"%d",&w[i]);
	}
	fclose(x);
}
void inkq()
{
	int s=0;
	int j;
	for(j=1;j<=n;j++)
	{
		s=s+b[j]*w[j];	
	}
	if(s==pmax)
	{ 	
		dem++;
		for(j=1;j<=n;j++)
	{
		fprintf(y,"%d ",b[j]);
	}
	fprintf(y,"\n----------------------------------------\n");
	}
}
void inkqdem()
{
	int s=0;
	int j;
	for(j=1;j<=n;j++)
	{
		s=s+b[j]*w[j];	
	}
	if(s==pmax)
	{ 	
		dem++;
	}
}
void thu(int i)
{
	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(i<n) {
		thu(i+1);
		}
		else
		 inkq();
	}
}
void thudem(int i)
{
	int j;
	for(j=0;j<=1;j++)
	{
		b[i]=j;
		if(i<n) {
		thudem(i+1);
		}
		else
		 inkqdem();
	}
}
void ghifile()
{
	y = fopen("output4.txt","w");
	thudem(1);
	if(dem==0)
	{
		fprintf(y,"khong chon duoc");
	}else 
	fprintf(y,"%d\n",dem);
	thu(1);	
}
int main()
{
	docfile();
	ghifile();
	getch();
}
