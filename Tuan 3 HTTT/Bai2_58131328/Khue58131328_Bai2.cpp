#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
#include<fstream>
void nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d] : ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%3d",a[i]);
	printf("\n");
}
void ghifile(char *file,int a[],int n)
{
	ofstream f;
	f.open(file);
	f<<n<<endl;
	for(int i=0;i<n;i++)
		f<<" "<<a[i];
	f.close();
}
void sapxep(int a[],int n)
{
	int tam;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
	}
}
int timkiemnhiphan(int a[],int n,int l,int r,int x)
{
	if(l>r)
		return -1;
	else
	{
		int k=(l+r)/2;
		if(a[k]==x)
			return k;
		else
			if(a[k]>x)
				timkiemnhiphan(a,n,l,k-1,x);
			else
				timkiemnhiphan(a,n,k+1,r,x);
	}
}
void tongln(int a[],int n)
{
	int max_tong=0,max_tam=0;
	for(int i=0;i<n;i++)
	{
		max_tam=max_tam+a[i];
		if(max_tam<0)
		{
			max_tam=0;
		}
		if(max_tong<=max_tam)
		{
			max_tong=max_tam;
		}
	}
	printf("Tong lon nhat cua cac phan tu lien tiep nhau trong mang la %d\n",max_tong);
}
void menu()
{
	int a[50],n,chon,l,r,x;
	ifstream g;
	g.open("input2.txt");
	if(g!=NULL)
	{
		g>>n;
		cout<<"So luong phan tu : "<<n<<endl;
		for(int i=0;i<n;i++)
		{
			g>>a[i];
			cout<<" "<<a[i];
		}
		cout<<endl;
		system("pause");
		do
		{
			system("cls");
			cout<<"1.Sap xep phan tu."<<endl;	
			cout<<"2.Tim kiem phan tu."<<endl;
			cout<<"3.Tim tong lon nhat cua day so lien tuc trong mang."<<endl;
			cout<<"0.Thoat."<<endl;
			cout<<"Chon :>";	cin>>chon;
			switch(chon)
			{
				case 0:
					break;
				case 1:
					sapxep(a,n);
					xuat(a,n);
					system("pause");
					break;
				case 2:
					l=0,r=n-1;
					sapxep(a,n);
					printf("X : ",x);
					scanf("%d",&x);
					if(timkiemnhiphan(a,n,l,r,x)==-1)
					{
						printf("Khong ton tai phan tu can tim kiem\n");
						system("pause");
					}
					else
					{
						xuat(a,n);
						printf("Vi tri cua %d la %d\n",x,timkiemnhiphan(a,n,l,r,x));
						system("pause");
					}
					break;
				case 3:
					tongln(a,n);
					system("pause");
					break;
				default:
					cout<<"Muc nay khong ton tai"<<endl;
					break;
			}
		}while(chon!=0);
	}
	else
	{
		printf("n : ",n);
		scanf("%d",&n);
		nhap(a,n);
		ghifile("input2.txt",a,n);
		do
		{
			system("cls");
			cout<<"1.Sap xep phan tu."<<endl;	
			cout<<"2.Tim kiem phan tu."<<endl;
			cout<<"3.Tim tong lon nhat cua day so lien tuc trong mang."<<endl;
			cout<<"0.Thoat."<<endl;
			cout<<"Chon :>";	cin>>chon;
			switch(chon)
			{
				case 0:
					break;
				case 1:
					sapxep(a,n);
					system("pause");
					break;
				case 2:
					l=0,r=n-1;
					sapxep(a,n);
					printf("X : ",x);
					scanf("%d",&x);
					if(timkiemnhiphan(a,n,l,r,x)==-1)
					{
						printf("Khong ton tai phan tu can tim kiem\n");
						system("pause");
					}
					else
					{
						xuat(a,n);
						printf("Vi tri cua %d la %d\n",x,timkiemnhiphan(a,n,l,r,x));
						system("pause");
					}
					break;
				case 3:
					tongln(a,n);
					system("pause");
					break;
				default:
					cout<<"Muc nay khong ton tai"<<endl;
					break;
			}
		}while(chon!=0);
	}
	g.close();
}
int main()
{
	menu();
	return 0;
}
