#include<iomanip>

#include <iostream>
using namespace std;
	int d,c;
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
		cout <<"Nhap gia tri khac 0, so 0 de dung ";
		cin >> temp;
		if(temp!=0)
			{
			
				p=new Node;
				p->gtri=temp;
				p->tiep=NULL;
				do{
					cout<<"nhap vi tri hang:";
					cin>>p->dong;
					cout<<"nhap vi tri cot";
					cin>>p->cot;
				}while(p->dong>d||p->cot>c);
				
				
			
		if(dau==NULL) dau=p;
			else q->tiep=p;
			q=p;
			}
	}while(temp!=0);
}

//hien thi ma tran
void DuyetMatran(Node *dau)
{
	Node *p;
	p=dau;
	if(p!=NULL)
	{
	
		for(int i=1;i<=d;i++)
		{
		
			for(int j=1 ;j<=c;j++)
			{
				if(p==NULL) cout<<setw(4)<<0;
					else 
					if((i!=p->dong) || (j!=p->cot))	cout<<setw(4)<<0;				
						else 
							{
							cout<<setw(4)<<p->gtri;
							p=p->tiep;							
							}			 
			}
			cout<<endl; 
		}
	}
}

//nhan ma trna cho 1 so khac 0
void Nhanso(Node *dau,int x)
{
	Node *p;
	p=dau;
	while(p!=NULL)
	{
		p->gtri=p->gtri*x;
		p=p->tiep;
	}
}

//cong matran thua
/*void Cong(Node *dau,Node *begin)
{
	Node *p,*k,*q,*s;
	p=dau;k=begin;
	while(p!=NULL)	p=p->tiep;
	while(k!=NULL)
	{
		p=k;
		p=p->tiep;
		k=k->tiep;
	}
	p=dau;
	while(p!=NULL)
	{
		q=p;	
		while(p->tiep!=NULL)
		{
			p=p->tiep;
			if(q->dong==p->dong && q->cot==p->cot) xoaP() 
		}
	}
	
	
}*/

int main()
{
	Node *a;
	int x;
	KhoiTao(a);
	cout<<"nhap so dong va so cot cua ma tran:";
	cin>>d>>c;
	NhapMatran(a);
	DuyetMatran(a);
	cout<<"nhap 1 so nguyen x: ";
	cin>>x;
	Nhanso(a,x);
	DuyetMatran(a);
	system("pause");
}
