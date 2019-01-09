#include<stdio.h>
#include<conio.h>
int a[100];
int b[20];
int n;

void nhap(int a[])
{
	FILE*x;
	x=fopen("b1.txt","r");
	fscanf(x,"%d",&n);
	for(int i=0;i<n;i++)
	{
		fscanf(x,"%d",&a[i]);
	}
	fclose(x);
	
}

void sapxep(int a[])
{
	int tam;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i;j<n;j++)
		if(a[i]>a[j])
		{
			tam=a[i];
			a[i]=a[j];
			a[j]=tam;
		}
	}
}

int ktra(int a[],int x)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			return i;
			break;
		}
	}
	return -1;
}

void chew(int a[],int x, int i)
{
	int j=0;
	//so luong phan tu thuc su
	while(a[j]!=0)
	{
		j=j+1;
	}
	n=j+1;
	//dich chuyen cac phan tu ke tu vi tri i 1 vi tri
	for(j=n-1;j>=i;j--)
	{
		a[j+1]=a[j];
	}
	//chen phan tu x vao vi tri i;
	a[i]=x;
	
}
int tim(int a[],int x)
{
	int i=0;
	if(ktra(a,x)==-1)
	{
		while(i<n)
		{
			if((x>a[i])&&(x<a[i+1]))
			{
				return i+1;
				break;
			}else
			i++;
		}
	}else
	printf("\n da co trong mang");
}
void timxoa(int a[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				b[i]=1;
			}
			
		}
	}	
}


void xoa(int a[],int k)
{
	for(int i=k;i<n-1;i++)
		a[i]=a[i+1];
		n--;
}
void xoatrunglap(int a[])
{
	timxoa(a);
	for(int i=n-1;i>=0;i--)
	{
		if(b[i]==1)
		{
			xoa(a,i);
		}
	}
}

void in()
{
	for(int i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
}

int main()
{
	int z;
	nhap(a);
	sapxep(a);
	in();
	printf("\nnhap x : "); scanf("%d",&z);
	if(ktra(a,z)!=-1)
	{
		printf("ktra phan tu mang gia tri %d ",ktra(a,z));
		xoa(a,ktra(a,z));
		printf("\nmang sau khi xoa :");
		in();
	}else
	{
	chew(a,z,tim(a,z));
	printf("\nmang sau khi them : ");
	in();
	}
	xoatrunglap(a);
	printf("\nmang sau khi xoa trung lap : ");
	in();
	getch();
}
