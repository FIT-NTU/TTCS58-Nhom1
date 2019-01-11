#include<iostream>
using namespace std;
// nhap vao so phan tu cua mang
void Nhap(int a[],int &n){
	do{
		cout<<"Nhap vao n so nguyen: ";
		cin>>n;
	}while(n<=7 || n>=20);
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
// in mang ra man hinh
void Xuat(int a[],int n){
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
}
// sap xep mang theo thu tu tang dan
void SapXep(int a[],int n){
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(a[j] < a[i])
			swap(a[i],a[j]);
}
// ham tim kiem bang tim kiem nhi phan
int Tk(int a[],int l,int r, int x){
	if(r>=l){
		int m = (l+r)/2;
	if(a[m]==x) return m;
		 if(a[m] >x) return Tk(a,l,m-1,x);
			 return Tk(a,m+1,r,x);
	}	
}
int tong(int a[],int n)
{
      if(n==1) return a[0];
      return (a[n-1]+tong(a,n-1));
}
// tim tong lon nhat cua cac phan tu lien tiep trong mang
void tongmax(int a[],int n)
{
	int maxsum = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        
			sum += a[i];
        	if (sum < 0) sum = 0;
        	maxsum = max(sum, maxsum);
    }
    cout<<"Tong lon nhat la: "<<maxsum<<endl;
}
// chuong trinh chinh 
int main(){
	int a[100],n;
	Nhap(a,n);
	tongmax(a,n);
	cout<<"\nMang sau khi sap xep la: ";
	SapXep(a,n);
	Xuat(a,n);
	int x;
	cout<<"\nNhap vao phan tu can tim kiem: ";
	cin>>x;
	int c = Tk(a,0,n-1,x);
	if(c == false)
		cout<<"khong tim thay phan tu "<<x<<endl;
	else
		cout<<"Tim duoc phan tu "<< x <<" tai vi tri: "<<c<<endl;
	system("pause");
}
