#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[15]={21,34,32,7,19,87,54,56,43,98,32,68,46,21,27};
int n=15;
int X;
void Nhapdl(){
	int i;
		printf("nhap vao so phan tu cua mang:");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
		}
			}
//-------------------------------------------------------------------------------
void sapxep(){
	int i,j;
	int tam;
	for(int i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(a[j]<a[i])
	{
		tam=a[i];
		a[i]=a[j];
		a[j]=tam;
	}
	}
	//-------------------------------------
	void duyet(){
		int i=0;
		while((a[i]!=0)||(i<n))
		{
			printf("%3d",a[i]);
			i=i+1;
		}
		}
//-----------------------------------------------------------------------------------------------------------------------------
int Ktra(int a[],int x){
	int i=0;
	while ((a[i]!=x)&&(i<n))
	i=i+1;
	if(i>=n)
	return -1;
	else return i;
}
//--------------------------------------------------------------------------------------------------------------------------------

void HoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SapXepTangDan(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
/*
Cho chay tu cuoi ve dau, neu thay so nào lon hon x thì cho nó dich ve sau 1 vi trí.
*/
void ChenXVaoMangTang(int a[], int &n, int x)
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
//--------------------------------------------------------
//xoa cac phan tu co gia tri la x
void Xoa1PhanTu(int a[], int &n, int ViTriXoa)
{
	for(int i = ViTriXoa; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void XoaCacPhanTuTrungVoiX(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if((a[i]) == x)
		{
			Xoa1PhanTu(a, n, i);
			i--;
		}
	}
}
//--------------------------------------------------
//xoa cac phan tu trung nhau
void XoaCacPhanTuTrungNhau(int a[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] == a[j])
			{
				Xoa1PhanTu(a, n, j);
				j--;
			}
		}
	}
}
//------------------------------------------------------
	int main(){
		int x;
		sapxep();
		duyet();
		SapXepTangDan(a, n);
		int PhanTuThem;
		printf("\nNhap vao phan tu can them: ");
		scanf("%d", &PhanTuThem);

		ChenXVaoMangTang(a, n, PhanTuThem);
		printf("\nMang sau khi them:\n");
		duyet();
		int n;
		
		int ViTriXoa;
		printf("\nNhap x: ");
		scanf("%d", &x);
	
		XoaCacPhanTuTrungVoiX(a, n, x);
		printf("\nMang sau khi xoa tat cac cac gia tri trung voi %d: ", x);
		duyet();
		
		XoaCacPhanTuTrungNhau(a, n);
		printf("\nMang sau khi xoa tat cac cac gia tri trung nhau: ");
		duyet();
		//kiem tra
		printf("\n nhap x:");
		scanf("%d",&X);
		printf("\n kiem tra phan tu mang gia tri %d",Ktra(a,X));
		getch();
			
			}
	

