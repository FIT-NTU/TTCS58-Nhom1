#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[15]={21,34,32,7,19,87,54,56,43,98,32,68,46,21,27};
	int b[15]={21,34,32,7,19,87,54,56,43,98,32,68,46,21,27};
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
//-----------------------------------------------------
int timkiem(int a[], int n, int x)
{
  int i;
  for (i = 0; i < n; i++)
    if (a[i] == x)
      // Tra ve chi so khi tìm thay
      return i;
  // Neu không tìm thay tra ve -1. Vì chi so mang >= 0
  return -1;
}
 //-----------------------------------------------------
 void max(){
 int max_tam=0;
 int max_sum=0;
 	for(int i=0;i<n;i++){
 		max_tam=max_tam+a[i];
 		if(max_tam<0)
 		{
 			max_tam=0;
 			}
 			if(max_sum<max_tam){
 				max_sum=max_tam;
 				}
 				//in ra vet da duyet
 				printf("\ni=%d->max_tam=%d->max_sum=%d\n",i,max,max_tam,max_sum);
 		}
 		printf("\ntong cua cac phan tu lien tiep ke nhau la %d\n",max_sum);
 	}
//------------------------------------------------------
	int main(){
int k;
		sapxep();
		duyet();
		sapxep();
		int a[15]={21,34,32,7,19,87,54,56,43,98,32,68,46,21,27};
			int b[15]={21,34,32,7,19,87,54,56,43,98,32,68,46,21,27};
  int n = sizeof(a) / sizeof(a[0]);
  int x = 32;
  int ketqua = timkiem(a, n, x);
  if (ketqua != -1) {
    printf("%d xuat hien tai chi so %d", x, ketqua);
  } else {
    printf("%d khong co trong mang", x);
  }
  max();
  duyet();
 
  
		getch();
			
			}
	

