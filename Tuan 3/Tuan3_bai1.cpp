#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 20
#define MIN 10

//nhap 
void nhap (int a[], int &n)
{

	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", &n);
		if(n <= MIN || n > MAX)
		{
			printf("\nSo phan tu khong hop le. Xin kiem tra lai !\n");
		}
	}while(n <= MIN || n > MAX);
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	
}



//Kiem tra X co ton tai
int kt(int a[], int n, int y)
{
   	for(int i = 0; i < n; i++)
	{
		
		if(a[i] == y)
		{
			return true; 
		}
	}
	return false; 
}


//Xuat
void xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

//Hoan vi
void hv(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Sap xep tang dan
void sx(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				hv(a[i], a[j]);
			}
		}
	}
}

//Chen x vao day so
void chenx(int a[], int &n, int x)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		if(x < a[i])
		{
			int temp = x;
			for(j = n; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = temp;
			break;
		}
	}
	n++;
}

//xoa 1 phan tu
void xoapt(int a[], int &n, int vtxoa)
{
	for(int i = vtxoa; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

//xoa x
void xoax(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if((a[i]) == x)
		{
			xoapt(a, n, i);
			i--;
		}
	}
}

int main()
{
	int i;
	int vtxoa, x;
	int n;
	int a[MAX];
	nhap(a, n);
	xuat(a, n);
	sx(a, n);
	int ptmoi;
	printf("\nNhap x kiem tra co trong mang: ");
	scanf("%d", &x);
	void  kt(int a[],int n); 
	if(a[i] == x)
	{
	    printf("\nYES\n");
	}
	else
	{
		printf("\nNO\n");
	}
	xuat(a, n);
	printf("\nNhap X can them: ");
	scanf("%d", &ptmoi);

	chenx(a, n, ptmoi);
	printf("\nKet qua sau khi them:\n");
	xuat(a, n);
	
	printf("\nNhap x can xoa: ");
	scanf("%d", &x);
	xoax(a, n, x);
	printf("\nKet qua sau khi xoa trung voi %d: ", x);
	xuat(a, n);
	
	getch();
	return 0;
}
