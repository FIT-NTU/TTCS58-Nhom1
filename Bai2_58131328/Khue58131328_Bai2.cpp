#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
#include<fstream>
ofstream k ("output2.txt");
struct matran
{
	int hang;
	int cot;
	int giatri;
	matran *tiep;
};
void khoitao(matran *&dau)
{
	dau=NULL;
}
void nhap(matran *&dau,int _hang,int _cot)
{
	matran *p,*q;
	int giatri;
	for(int i=0;i<_hang;i++)
	{
		for(int j=0;j<_cot;j++)
		{
			printf("[%d][%d] : ",i,j);
			scanf("%d",&giatri);
			p=new matran;
			p->giatri=giatri;
			p->hang=i;
			p->cot=j;
			p->tiep=NULL;
			if(dau==NULL)
				dau=p;
			else
				q->tiep=p;
			q=p;
		}
	}
}
int dem(matran *dau)
{
	if(dau!=NULL)
	{
		if(dau->giatri!=0)
			return dem(dau=dau->tiep);
		return 1+dem(dau->tiep);
	}
}
int kt(matran *dau,int n,int m)
{
	int k=n*m;
	int l=k/2;
	if(l<dem(dau))
		return 1;
	return 0;
}
void taomang(matran *dau,int a[])
{
	int i=0;
	while(dau!=NULL)
	{
		a[i]=dau->giatri;
		i++;
		dau=dau->tiep;
	}
}
void chuyenmang(matran *dau,int b[][50],int n,int m)
{
	int a[50];
	taomang(dau,a);
	int index=0;
	if(index<n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				b[i][j]=a[index++];
	}
}
void matranthua(matran *dau,int a[][50],int n,int m)
{
	do
	{
		dau=NULL;
		nhap(dau,n,m);
		printf("\n");
		if(kt(dau,n,m)!=1)
			printf("Day khong phai ma tran thua!\n");
	}while(kt(dau,n,m)!=1);
	chuyenmang(dau,a,n,m);
}
void xuatds(int a[][50],int n,int m)
{
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				if(a[i][j]!=0)
					printf("%5d",a[i][j]);
				else
					printf("     ",a[i][j]);
			printf("\n");
		}
	}
}
void nhan1so(int a[][50],int b[][50],int n,int m)
{
	int x;
	do
	{
		printf("So can nhan (!=0) : ");
		scanf("%d",&x);
	}while(x==0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			b[i][j]=x*a[i][j];
	}
}
int dinhthucmatran(int a[][50],int n)
{
	int s,sum=0;
	if(n==1)
		return a[0][0];
	if(n==2)
		return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	for(int k=0;k<n;k++)
	{
		int b[50][50];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i<k)
					b[i][j-1]=a[i][j];
				else 
					if(i>k)
						b[i-1][j-1]=a[i][j];
			}
		}
		if(k%2==0)
			s=1;
		else
			s=-1;
		sum+=a[k][0]*s*dinhthucmatran(b,n-1);
	}
	return sum;
}
void nhan2matran(int a[][50],int b[][50],int c[][50],int n,int m,int p,int q)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			int sum=0;
			for(int k=0;k<=n;k++)
			{
				sum=sum+a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}
}
void cong2matran(int a[][50],int b[][50],int c[][50],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			c[i][j]=a[i][j]+b[i][j];
	}
}
void tru2matran(int a[][50],int b[][50],int c[][50],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			c[i][j]=a[i][j]-b[i][j];
	}
}
void ghifile(int a[][50],int n,int m)
{
	ofstream f;
	f.open("input2.txt");
	f<<n<<" "<<m<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			f<<a[i][j]<<" ";
		f<<endl;
	}
	f.close();
}
void ghifile1(int a[][50],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			k<<a[i][j]<<" ";
		k<<endl;
	}
}
void menu()
{
	matran *dau;
	int n,m,p,q,chon;
	int a[50][50],b[50][50],c[50][50];
	khoitao(dau);
	ifstream g;
	g.open("input2.txt");
	if(g!=NULL)
	{
		printf("Du lieu trong file input2.txt\n");
		g>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				g>>a[i][j];
				if(a[i][j]!=0)
					printf("%5d",a[i][j]);
				else
					printf("     ");
			}
			printf("\n");
		}
		do
		{
			printf("1.Tao lai ma tran thua\n");
			printf("2.Hien thi ma tran thua\n");
			printf("3.Nhan ma tran thua voi 1 so khac 0\n");
			printf("4.Tinh dinh thuc cua ma tran thua\n");
			printf("5.Cong hai ma tran thua\n");
			printf("6.Tru hai ma tran thua\n");
			printf("7.Nhan hai ma tran thua\n");
			printf("8.Thoat\n");
			printf("----------------------------------------\n");
			printf("Chon memu (1-5) :",chon);
			scanf("%d",&chon);
			switch(chon)
			{
				case 1:
					do
					{
						printf("So hang cua ma tran : ",n);
						scanf("%d",&n);
						printf("So cot cua ma tran : ",m);
						scanf("%d",&m);
					}while(n<2&&m<2);
					matranthua(dau,a,n,m);
					ghifile(a,n,m);
					printf("\n");
					break;
				case 2:
					xuatds(a,n,m);
					printf("\n");
					break;
				case 3:
					nhan1so(a,c,n,m);
					xuatds(c,n,m);
					k<<"Ket qua cua ma tran thua nhan voi 1 so :\n";
					ghifile1(c,n,m);
					k<<endl;
					printf("\n");
					break;
				case 4:
					if(n==m)
					{
						printf("Dinh thuc cua ma tran thua la : %d",dinhthucmatran(a,n));
						k<<"Dinh thuc cua ma tran thua la : "<<dinhthucmatran(a,n)<<endl<<endl;
					}
					else
						printf("Day khong phai la ma tran vuong!");
					printf("\n\n");
					break;
				case 5:
					do
					{
						printf("So hang cua ma tran : ",p);
						scanf("%d",&p);
						printf("So cot cua ma tran : ",q);
						scanf("%d",&q);
					}while(p<2&&q<2);
					matranthua(dau,b,p,q);
					if(n==p&&m==q)
					{
						printf("A : \n");
						xuatds(a,n,m);
						printf("B : \n");
						xuatds(b,p,q);
						cong2matran(a,b,c,n,m);
						printf("Ket qua : \n");
						xuatds(c,n,m);
						printf("\n\n");
						k<<"Ket qua cong hai ma tran thua :\n";
						k<<"A : "<<endl;
						ghifile1(a,n,m);
						k<<"B : "<<endl;
						ghifile1(b,n,m);
						k<<"Ket qua : "<<endl;
						ghifile1(c,n,m);
						k<<endl;
					}
					else
						printf("Khong the cong 2 ma tran vi so hang cua ma tran A khong bang so hang cua ma tran B hoac so cot cua ma tran A khong bang so cot cua ma tran B");
					printf("\n\n");
					break;
				case 6:
					do
					{
						printf("So hang cua ma tran : ",p);
						scanf("%d",&p);
						printf("So cot cua ma tran : ",q);
						scanf("%d",&q);
					}while(p<2&&q<2);
					matranthua(dau,b,p,q);
					if(n==p&&m==q)
					{
						printf("A : \n");
						xuatds(a,n,m);
						printf("B : \n");
						xuatds(b,p,q);
						tru2matran(a,b,c,n,m);
						printf("Ket qua : \n");
						xuatds(c,n,m);
						printf("\n\n");
						k<<"Ket qua tru hai ma tran thua :\n";
						k<<"A : "<<endl;
						ghifile1(a,n,m);
						k<<"B : "<<endl;
						ghifile1(b,n,m);
						k<<"Ket qua : "<<endl;
						ghifile1(c,n,m);
						k<<endl;
					}
					else
						printf("Khong the cong 2 ma tran vi so hang cua ma tran A khong bang so hang cua ma tran B hoac so cot cua ma tran A khong bang so cot cua ma tran B");
					printf("\n\n");
					break;
				case 7:
					do
					{
						printf("So hang cua ma tran : ",p);
						scanf("%d",&p);
						printf("So cot cua ma tran : ",q);
						scanf("%d",&q);
					}while(p<2&&q<2);
					matranthua(dau,b,p,q);
					if(m==p)
					{
						printf("A : \n");
						xuatds(a,n,m);
						printf("B : \n");
						xuatds(b,p,q);
						nhan2matran(a,b,c,n,m,p,q);
						printf("Ket qua : \n");
						xuatds(c,n,q);
						printf("\n");
						k<<"Ket qua nhan hai ma tran thua :\n";
						k<<"A : "<<endl;
						ghifile1(a,n,m);
						k<<"B : "<<endl;
						ghifile1(b,p,q);
						k<<"Ket qua : "<<endl;
						ghifile1(c,n,q);
						k<<endl;
					}
					else
						printf("Khong the nhan 2 ma tran vi so hang va cot khong bang nhau!\n");
					printf("\n");
					break;
				case 8:
					break;
				default:
					printf("Muc lua chon khong ton tai, xin chon lai menu!\n");
			}
		}while(chon!=8);
	}
	else
	{
		do
		{
			printf("1.Tao ma tran thua\n");
			printf("2.Hien thi ma tran thua\n");
			printf("3.Nhan ma tran thua voi 1 so khac 0\n");
			printf("4.Tinh dinh thuc cua ma tran thua\n");
			printf("5.Cong hai ma tran thua\n");
			printf("6.Tru hai ma tran thua\n");
			printf("7.Nhan hai ma tran thua\n");
			printf("8.Thoat\n");
			printf("----------------------------------------\n");
			printf("Chon memu (1-5) :",chon);
			scanf("%d",&chon);
			switch(chon)
			{
				case 1:
					do
					{
						printf("So hang cua ma tran : ",n);
						scanf("%d",&n);
						printf("So cot cua ma tran : ",m);
						scanf("%d",&m);
					}while(n<2&&m<2);
					matranthua(dau,a,n,m);
					ghifile(a,n,m);
					printf("\n");
					do
					{
						printf("1.Tao lai ma tran thua\n");
						printf("2.Hien thi ma tran thua\n");
						printf("3.Nhan ma tran thua voi 1 so khac 0\n");
						printf("4.Tinh dinh thuc cua ma tran thua\n");
						printf("5.Cong hai ma tran thua\n");
						printf("6.Tru hai ma tran thua\n");
						printf("7.Nhan hai ma tran thua\n");
						printf("8.Thoat\n");
						printf("----------------------------------------\n");
						printf("Chon memu (1-5) :",chon);
						scanf("%d",&chon);
						switch(chon)
						{
							case 1:
								do
								{
									printf("So hang cua ma tran : ",n);
									scanf("%d",&n);
									printf("So cot cua ma tran : ",m);
									scanf("%d",&m);
								}while(n<2&&m<2);
								matranthua(dau,a,n,m);
								ghifile(a,n,m);
								printf("\n");
								break;
							case 2:
								xuatds(a,n,m);
								printf("\n");
								break;
							case 3:
								nhan1so(a,c,n,m);
								xuatds(c,n,m);
								k<<"Ket qua cua ma tran thua nhan voi 1 so :\n";
								ghifile1(c,n,m);
								k<<endl;
								printf("\n");
								break;
							case 4:
								if(n==m)
								{
									printf("Dinh thuc cua ma tran thua la : %d",dinhthucmatran(a,n));
									k<<"Dinh thuc cua ma tran thua la : "<<dinhthucmatran(a,n)<<endl<<endl;
								}
								else
									printf("Day khong phai la ma tran vuong!");
								printf("\n\n");
								break;
							case 5:
								do
								{
									printf("So hang cua ma tran : ",p);
									scanf("%d",&p);
									printf("So cot cua ma tran : ",q);
									scanf("%d",&q);
								}while(p<2&&q<2);
								matranthua(dau,b,p,q);
								if(n==p&&m==q)
								{
									printf("A : \n");
									xuatds(a,n,m);
									printf("B : \n");
									xuatds(b,p,q);
									cong2matran(a,b,c,n,m);
									printf("Ket qua : \n");
									xuatds(c,n,m);
									printf("\n\n");
									k<<"Ket qua cong hai ma tran thua :\n";
									k<<"A : "<<endl;
									ghifile1(a,n,m);
									k<<"B : "<<endl;
									ghifile1(b,n,m);
									k<<"Ket qua : "<<endl;
									ghifile1(c,n,m);
									k<<endl;
								}
								else
									printf("Khong the cong 2 ma tran vi so hang cua ma tran A khong bang so hang cua ma tran B hoac so cot cua ma tran A khong bang so cot cua ma tran B");
								printf("\n\n");
								break;
							case 6:
								do
								{
									printf("So hang cua ma tran : ",p);
									scanf("%d",&p);
									printf("So cot cua ma tran : ",q);
									scanf("%d",&q);
								}while(p<2&&q<2);
								matranthua(dau,b,p,q);
								if(n==p&&m==q)
								{
									printf("A : \n");
									xuatds(a,n,m);
									printf("B : \n");
									xuatds(b,p,q);
									tru2matran(a,b,c,n,m);
									printf("Ket qua : \n");
									xuatds(c,n,m);
									printf("\n\n");
									k<<"Ket qua tru hai ma tran thua :\n";
									k<<"A : "<<endl;
									ghifile1(a,n,m);
									k<<"B : "<<endl;
									ghifile1(b,n,m);
									k<<"Ket qua : "<<endl;
									ghifile1(c,n,m);
									k<<endl;
								}
								else
									printf("Khong the cong 2 ma tran vi so hang cua ma tran A khong bang so hang cua ma tran B hoac so cot cua ma tran A khong bang so cot cua ma tran B");
								printf("\n\n");
								break;
							case 7:
								do
								{
									printf("So hang cua ma tran : ",p);
									scanf("%d",&p);
									printf("So cot cua ma tran : ",q);
									scanf("%d",&q);
								}while(p<2&&q<2);
								matranthua(dau,b,p,q);
								if(m==p)
								{
									printf("A : \n");
									xuatds(a,n,m);
									printf("B : \n");
									xuatds(b,p,q);
									nhan2matran(a,b,c,n,m,p,q);
									printf("Ket qua : \n");
									xuatds(c,n,q);
									printf("\n");
									k<<"Ket qua nhan hai ma tran thua :\n";
									k<<"A : "<<endl;
									ghifile1(a,n,m);
									k<<"B : "<<endl;
									ghifile1(b,p,q);
									k<<"Ket qua : "<<endl;
									ghifile1(c,n,q);
									k<<endl;
								}
								else
									printf("Khong the nhan 2 ma tran vi so hang va cot khong bang nhau!\n");
								printf("\n");
								break;
							case 8:
								break;
							default:
								printf("Muc lua chon khong ton tai, xin chon lai menu!\n");
						}
					}while(chon!=8);
					break;
				case 8:
					break;
				default:
					printf("Du lieu khong ton tai!\n");
			}
		}while(chon!=8);
	}
	g.close();
}
int main()
{
	menu();
	return 0;
}
