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
			printf("\nSo phan tu khong hop le. Moi nhap lai!\n");
		}
	}while(n <= MIN || n > MAX);
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	
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


//Ham tim kiem nhi phan
int timkiem(int a[], int l, int r, int x) 
{
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (a[mid] == x)
    return mid;
    if (a[mid] > x)
    return timkiem(a, l, mid - 1, x);
    return timkiem(a, mid + 1, r, x);
  }

 	return -1;
}

//Tinh tong
int tong(int a[],int n)
{
    int i,s;
    for(i=0,s=0;i<n;i++) s=s+a[i];
    return s;
}


int main()
{
	int s;
	int x;
	int n; 
	int a[MAX];
	nhap(a, n);
	printf("\nMang sau khi sap xep la: ");
	sx(a, n);
	xuat(a, n);
  	printf("\nNhap x co trong mang de kiem tra : ");
	scanf("%d", &x);
  	int result = timkiem(a, 0, n - 1, x);
  	if (result == -1)
    printf("\n%d xuat hien tai chi so %d", x, result);
  	else
    printf("%d xuat hien tai chi so %d", x, result);
	s=tong(a,n);
	printf("\nTong cac phan tu trong mang la: %5d",s);
	return 0;
  	
}
