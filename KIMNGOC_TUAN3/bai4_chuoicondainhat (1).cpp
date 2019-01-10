#include<stdio.h>
#include<conio.h>
#include<string.h>
char x[255];
char y[255];
int c[255][255]; //Mang c dung de tim max
int b[255][255]; //Mang b dung de luu vet (so ptu cua mang b=x*y)
int m; //chieu dai cua chuoi x
int n; //chieu dai cua chuoi y
//-----------------------------------------------------------------------------------------------------
void NhapDuLieu()
{
	//khai bao bien
	printf("\nNhao du lieu cho chuoi x: ");
	fflush(stdin);
	gets(x);
	printf("\nNhao du lieu cho chuoi y: ");
	fflush(stdin);
	gets(y);
}
//------------------------------------------------------------------------------------------------------
//tim max cua 2 so a, b
int Max(int a, int b)
{
	if(a>b)	return a;
	else 	return b;
}
//-------------------------------------------------------------------------------------------------------
//khoi tao 2 mang c(ma tran trong so) va b(ma tran luu vet)
void KhoiTao()
{
	int i, j;
	//tao ra ma tran b, c co so ptu m+1 hang, n+1 cot.
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			c[i][j] = 0;
			b[i][j] = 0;
		}
	}
}
//---------------------------------------------------------------------------------------------------------
//in ra ma tran b va c
void InKQ()
{
	int i,j;
	//in ra ma tran trong so
	printf("\n In ra ma tran trong so \n");
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			printf("%5d", c[i][j]);
		}
		printf("\n");
	}
	
	//in ra ma tran luu vet
	printf("\n In ra ma tran luu vet \n");
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			printf("%5d", b[i][j]);
		}
		printf("\n");
	}
}
//----------------------------------------------------------------------------------------------------------
//LCS trong quy hoat dong
void LCS()
{
	int i,j;
	m = strlen(x);
	n = strlen(y);
	//xay dung hang de tim max
	//khoi tao ma tran b va c
	//chen them 1 cot va gan gia tri tuong ung
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			if(x[i] == y[j])
			{
				c[i+1][j+1] = c[i][j] + 1;
				b[i+1][j+1] = 0; //Gan phan tu CHEO
			}
			else{
				if(c[i+1][j]>=c[i][j+1])
				{
					c[i+1][j] = c[i+1][j];
					b[i+1][j+1] = 1; //gan phan tu ben TRAI
				}
				else
				{
					c[i+1][j+1] = c[i][j+1];
					b[i+1][j+1] = 2; //gan phan tu ben TREN
				}
			}
		}
	}
	//In ra ma tran b va c
	InKQ();
}
//------------------------------------------------------------------------------------------------------
//in chuoi ket qua
int InChuoiKQ()
{
	int i,j;
	char tam[255]; //Chuoi dung de luu ket qua
	int itam = 0;
	i = m; j = n;
	
	printf("\nChuoi tim duoc la: "); 
	
	while(i>0 && j>0)
	{
		if(b[i][j] == 0)
		{
			//Nhung vi tri duoc tinh toan tu duong CHEO
			tam[itam] = x[i-1];
			itam++;
			i--;
			j--;
		}
		else
		{
			//Nhung vi tri duoc tinh toan tu ben trai
			if(b[i][j] == 1)	j--;
				
			else 	i--;	//Nhung vi tri duoc tinh toan tu ben tren (b[i][j]=2)
		}
	}
	//----------------------------------------------------------------------------------------------------
	//in ra chuoi ket qua theo chieu thuan

	for(i=itam-1; i>=0; i--)
		printf("%c", tam[i]);
		printf("\n");
			printf("chuoi chung co do dai lon nhat la: %d",itam);
}
//-------------------------------------------------------------------------------------------------------
int main()
{
	NhapDuLieu();
	LCS();
	InChuoiKQ();
	
}
