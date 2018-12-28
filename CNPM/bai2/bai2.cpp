#include<iomanip>

#include <iostream>
using namespace std;
#define MAX 50
int y[MAX][MAX];
int z[MAX][MAX];
//cau truc struct
struct nut
{
	int gtri,dong,cot;
	nut *tiep;
};

//khoi tao danh sach rong
typedef nut Node;
void KhoiTao(Node *&dau)
{
	dau=NULL;
}


//nhap ma tran
void NhapMatran(Node *&dau)
{
	
	Node *p,*q;
	int temp;


	do{
		cout <<"Nhap gia tri khac 0, so 0 de dung: ";
		cin >> temp;
		if(temp!=0)
			{
			
				p=new Node;
				p->gtri=temp;
				p->tiep=NULL;
				
					cout<<"nhap vi tri hang: ";
					cin>>p->dong;
					cout<<"nhap vi tri cot: ";
					cin>>p->cot;
				
				
			
		if(dau==NULL) dau=p;
			else q->tiep=p;
			q=p;
			}
	}while(temp!=0);
}

//hien thi ma tran
void DuyetMatran(Node *dau,int a[][MAX])
{
	Node *p;
	p=dau;
	p=p->tiep;
	if(p!=NULL)
	{
		for(int i=1;i<=dau->dong;i++)
			for(int j=1 ;j<=dau->cot;j++)
			{
				a[i][j]=0;
			}
	
		for(int i=1;i<=dau->dong;i++)
		{
		
			for(int j=1 ;j<=dau->cot;j++)
			{
				
				while(p!=NULL)
				{
					if((i==p->dong) && (j==p->cot)) a[i][j]=p->gtri	;				
					
				p=p->tiep;
				}
				p=dau->tiep;		
					 
			}
		}
	}
	
	for(int i=1;i<=dau->dong;i++)
	{
			for(int j=1 ;j<=dau->cot;j++)
			{
				cout<<setw(4)<<a[i][j];
			}
			cout<<endl;
	}
}

//nhan ma trna cho 1 so khac 0
void Nhanso(Node *dau,int x)
{
	Node *p;
	p=dau;
	p=p->tiep;
	while(p!=NULL)
	{
		p->gtri=p->gtri*x;
		p=p->tiep;
	}
}

//cong matran thua
void Cong(Node *dau,Node *begin)
{
	if(dau->dong==begin->dong && dau->cot==begin->cot)
	{
		
		DuyetMatran(dau,y);
		cout<<endl;
		DuyetMatran(begin,z);
		cout<<endl;
		for(int i=1;i<=dau->dong;i++)
			for(int j=1 ;j<=dau->cot;j++) y[i][j]=y[i][j]+z[i][j];
			
		for(int i=1;i<=dau->dong;i++)
		{
			for(int j=1 ;j<=dau->cot;j++)
			{
				cout<<setw(4)<<y[i][j];
			}
			cout<<endl;
		}		
		
		
	}else cout<<"khong cong duoc 2 ma tran k cung kich co ";
	
	
}

// tinh dinh thuc
double Dinhthuc(Node *dau)
{
	if(dau->dong==dau->cot)
	{
// phan ra A=L*U
	DuyetMatran(dau,y);
	int L[MAX][MAX],U[MAX][MAX];
	 int n=dau->cot;
	for(int k = 1; k<=n;k++) 
		{
		 U[k][k] = y[k][k];
		 L[k][k] = 1;
		 for(int i=k+1; i<=n; i++) {
		 L[i][k] = y[i][k]/U[k][k];
		 U[k][i] = y[k][i];
		 U[i][k] = 0;
		 L[k][i] = 0;
		 }
		 for(int i = k+1; i<=n; i++)
	 	for(int j = k+1; j<=n; j++)
	 		y[i][j] = y[i][j]-L[i][k]*U[k][j];
		}
			double temp = 1;
		for(int i = 1; i<=n; i++)
		temp*=y[i][i];
		return temp;
	}
	else return 9999;
	
}


/// tru 2 ma tran 
void Tru(Node *dau,Node *begin)
{

	if(dau->dong==begin->dong && dau->cot==begin->cot)
	{
		
		DuyetMatran(dau,y);
		cout<<endl;
		DuyetMatran(begin,z);
		cout<<endl;
		for(int i=1;i<=dau->dong;i++)
			for(int j=1 ;j<=dau->cot;j++) y[i][j]=y[i][j]-z[i][j];
			
		for(int i=1;i<=dau->dong;i++)
		{
			for(int j=1 ;j<=dau->cot;j++)
			{
				cout<<setw(4)<<y[i][j];
			}
			cout<<endl;
		}		
		
		
	}else cout<<"khong tru duoc 2 ma tran k cung kich co ";
}

// nhan 2 ma tran
void Nhan(Node *dau,Node *begin)
{
	if(dau->cot==begin->dong)
	{
		int tam[MAX][MAX];
		DuyetMatran(dau,y);
		cout<<endl<<endl;
		DuyetMatran(begin,z);
		cout<<endl;
		for(int i=1;i<=dau->dong;i++)
			for(int j=1 ;j<=begin->cot;j++) 
			{
				tam[i][j]=0;
				int k=1;
				
				while(k<=begin->dong)	
				{																
				tam[i][j]=tam[i][j]+y[i][k]*z[k][j];
				k++;
				}	
			}
		for(int i=1;i<=dau->dong;i++)
		{
			for(int j=1 ;j<=begin->cot;j++)
			{
				cout<<setw(4)<<tam[i][j];
			}
			cout<<endl;
		}		
		
		
	}else cout<<"khong nhan duoc  ma tran ";
}
int main()
{
	double dt;
	Node *a,*b;
	int x;
	KhoiTao(a);
	KhoiTao(b);
	
	//nhap danh sach
	cout<<"\nnhap ma tran (dau.dong la tong dong ,dau.cot la togn cot ,dau.gtri tuy y) :\n";
	NhapMatran(a);
	DuyetMatran(a,y);
	cout<<endl;
	
	//nhan ma tran voi x
//	cout<<"nhap 1 so nguyen x: ";
//	cin>>x;
//	Nhanso(a,x);
//	cout<<endl;
//	DuyetMatran(a,y);
	
	
//	//tinh dinh thuc
//	dt=Dinhthuc(a);
//	if(dt==9999) cout<<"ma tran k phai ma tran vuong;";
//		else cout<<"dinh thuc: "<<dt<<endl;
		
	
	//+ - * /
	cout<<"\nnhap ma tran moi de thuc hien tinh toan cong, tru, nhan, chia voi ma tran ban dau: \n";
	NhapMatran(b);
	cout<<endl;
	DuyetMatran(b,z);
	cout<<endl<<endl;
	
	//+ 
//	Cong(a,b);
//	cout<<endl<<endl;
//	
	Nhan(a,b);
	
	system("pause");
}
