#include<stdio.h>
#include<iostream>
#include<conio.h>
int a[20];
int n;
void nhap()
{
	FILE*x;
	x=fopen("b2.txt","r");
	fscanf(x,"%d",&n);
	if(n<10)
	{
		printf(" du lieu khong dung theo de bai ");
		exit(0);
	}
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
void in()
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int timkiemnhiphan(int a[], int r, int l, int x)
{
	if(r>l) return -1;
	else 
	if(a[r]==x) return r; 
	else 
	if(a[l]==x) return l;
	else
	{
		int mid;
		mid=(r+l)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) return timkiemnhiphan(a,r,mid-1,x);
		else return timkiemnhiphan(a,mid+1,l,x);
	}
	
}
void tong(int a[])
{
	int s=0;
	int t=0;
	for(int i=0;i<n;i++)
	{
		t = t + a[i];
		if(t<0)
		{
			t=0;		
		}
		if(s<t)
		{
			s=t;
			printf("tong cac phan tu lien ke : %d\n",s);
		}
	}
	printf("tong lon nhat cua cac phan tu lien ke la : %d",s);
	
}

int main()
{
	int k;
	nhap();
	tong(a);
	printf("\nmang sau khi sap xep la : ");
	sapxep(a);
	in();
	printf("\nnhap so can tim : "); scanf("%d",&k);
	if(timkiemnhiphan(a,0,n-1,k)!=-1)
	{
	printf("\nso can tim nam o vi tri  : %d",timkiemnhiphan(a,0,n-1,k));
	}else printf("\nkhong co phan tu can tim");
	getch();
}
