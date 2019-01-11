#include<iostream>
using namespace std;
int a[20]={21,34,32,7,19,87,25,6,5,6,4,2,3,7,8,0,0,0,0,0};
int n=15; int x;
//--------------------------------------------------------------------------------------------
void NhapMang(int a[] , int &n)
{
    cout<<" Nhap so phan tu mang : ";
    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"A["<<i<<"] = ";
       cin>>a[i];
    }
}
//---------------------------------------------------------------------------------------------------
void XuatMang(int a[] , int n)
{
	int i = 0;
	while((a[i]!=0)||(i<n)){
		cout<<"  "<<a[i];
		i=i+1;
	}
}
//----------------------------------------------------------------------------------------------------
void SapXep (int a[] , int n)
{
    int i,j;
    for(i = 0;i<n-1 ; i++)
       for(j = n-1 ; j>i ; j--)
          if(a[j] < a[j-1])
         swap(a[j] , a[j-1]);
}
//------------------------------------------------------------------------------------------
int Kt(int a[],int k)// ham kiem tra xem phan tu k ton tai chua
{  
	for(int i = 0;i<n;i++){
		if(a[i]==k)
			return i;
	} 
	return -1;
	
}
//-------------------------------------------------------------------------------------------------------------
// chen phan tu x 
void chen(int a[],int x,int i){
	int j=0;
	while(a[j]!=0)
	j=j+1;
	n=j+1;
	// dich chuyen cac phan tu ke tu vi tri i va  1 vi tri
	for(j=n-1;j>=i;j--)
	a[j+1]=a[j];
	// chen phan tu x vao vi tri thu i
	a[i]=x;
}
//-----------------------------------------------------------------------------------------------
int TimPhanTu(int a[], int n, int x)
{
	for(int i=0; i<n; i++)
		if(a[i] == x)
			return i; //tim thay tai vi tri i
	return -1; //khong tim thay x trong mang
}
//=======================================================================
void XoaPhanTu(int a[], int &n, int x)
{
	int vt=TimPhanTu(a, n, x); //Tìm vi tri x trong mang
	if(vt==-1)
		printf("\nKhong tim thay phan tu %d muon xoa.", x);
	else
	{
		for(int i=vt; i<=n-1; i++)
			a[i] = a[i+1]; 
		n--; //giam so phan tu
	}			
}
// xoa 1 phan tu
void Xoa1PhanTu(int a[],int &n,int vitri){
	for(int i=vitri;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
//------------------------------------------------------------------
// xoa tat ca cac phan tu mang gia tri = x
void XoaTatCaGiaTri(int a[],int &n,int x){
	int i=0;
	while(i<n){
		if(a[i]==x)
		{
			XoaPhanTu(a,n,i);
		}
		else 
		i++;
	}
}
//------------------------------------------------------------------------
// xoa cac phan tu trung voi nhau trong mang
void XoaPhanTuTrung(int a[],int &n){
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				Xoa1PhanTu(a,n,j);
				i--;
			}
		}
	}
}
int main(){
	//NhapMang(a,n);
	int vitri;
	cout<<"Mang sau khi sap xep la: "<<endl;
	SapXep(a,n);
	cout<<endl;
	XuatMang(a,n);
	cout<<endl;
	int k,i;
	cout<<"Nhap vao phan tu can chen: ";
	cin>>k;
	cout<<"Nhap vao vi tri can chen: ";
	cin>>i;
	chen(a,k,i);
	cout<<endl;
	cout<<"Mang sau khi chen la: "<<endl;
	SapXep(a,n);
	XuatMang(a,n);
	cout<<endl;
	cout<<"nhap vao so can xoa: ";
	cin>>x;
	XoaTatCaGiaTri(a,n,x);
	XuatMang(a,n);
	XuatMang(a,n);
	cout<<endl;
	XoaPhanTuTrung(a,n);
	cout<<"Mang sau khi xoa cac phan tu trung la: "<<endl;
	system("pause");
	return  0;
}
