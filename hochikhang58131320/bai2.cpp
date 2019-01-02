#include<iostream>
#define max 10
using namespace std;
int h=0, c=0;

struct Node
{ 
    int giatri, hang, cot;
	Node *next; //con tro tiep tro toi cac vi tri tiep theo
}; 
typedef struct Node nut; //dinh nghia lai cau truc 

void khoitao(nut *&dau) //gia tri nut dau tien = rong
{
	dau==NULL;
}
void nhap()
{
	do 
	{
		cout << "Nhap vao so hang: "; 
		cin >> h;
		if (h == 0)
			cout << "Nhap sai! Nhap lai: " << endl;
	}while (h == 0);
	do {
		cout << "Nhap so cot: "; 
		cin >> c;
		if (c == 0)
		cout << "Nhap sai! Nhap lai: " << endl;
	}while (c == 0);
}
void nhapmatran(nut *&dau)
{
	float t; //bien tam
	nut *p, *q;
	
	do //chua xac dinh dc so lan lap
	{
		cout<<"Nhap 1 gia tri bat ky:"<<endl; //cac gia tri tiep sau do phai tang len
		cin>>t;
		if(t!=0)
		{
			p=new nut;
			p->giatri=t;
			p->next=NULL;
			cout<<"Nhap toa do hang:";  //toa do hang va cot phai tang dan theo t
			cin>>p->hang; //dua nut p den vi tri hang
			cout<<"Nhap toa do cot:";
			cin>>p->cot; //dua nut p den vi tri cot
			if(dau==NULL) dau=p;
			else q->next=p;
				q=p;
		}
	}while(t!=0); //t=0 ket thuc;		
}
void xuatmatran(nut *dau)
{
	nut *p;
	p=dau;
	if(p!=NULL)
	{
		for(int i=1;i<=h;i++) //da biet dc so hang
		{
			for(int j=1 ;j<=c;j++) //da biet dc so cot
			{
				if(p==NULL) cout<<"\t"<<0;
				else if((i!=p->hang) || (j!=p->cot))	
					cout<<"\t"<<0;				
				else 
				{
					cout<<"\t"<<p->giatri;
					p=p->next;							
				}			 
			}
			cout<<endl; 
		}
	}
}
/*void nghichdao(nut *dau)
{
	nut *p;
	p=dau;
	if(p!=NULL)
	{
		for(int i=1;i<=c;i++) //da biet dc so hang
		{
			for(int j=1 ;j<=h;j++) //da biet dc so cot
			{
				if(p==NULL) cout<<"\t"<<0;
				else if((i!=p->cot) || (j!=p->hang))	
					cout<<"\t"<<0;				
				else 
				{
					cout<<"\t"<<p->giatri;
					p=p->next;							
				}			 
			}
			cout<<endl; 
		}
	}
}*/
void nhan1so(nut *dau) 
{
	int k; //k la 1 so nguyen bat ky
	cout<<"Nhap 1 so nguyen de nhan:";
	cin>>k;
	nut *p;
	p=dau;
	while(p!=NULL)
	{
		p->giatri=p->giatri*k; 
		p=p->next; //lan luot nhan voi cac nut tiep theo
	}
}

void nhap2()
{
	cout<<"Nhap so hang ma tran 2:"<<endl;
	cin>>h;
	cout<<"Nhap so cot ma tran 2:"<<endl;
	cin>>c;
}
void chon(nut *dau)
{
	int k;
	do
	{
		cout<<"Chon 0 de ket thuc"<<endl;
		cout<<"Chon 1 de nhap ma tran 2 va tiep tuc"<<endl;
		cout<<"Moi chon:";
		cin>>k;
		switch(k)
		{
			case 0:break;
			case 1:
				nhap2();
				nhapmatran(dau);
	 			xuatmatran(dau);
		}
	}while (k!=0);
}
int main()
{
	int h, c;
	nut *s, *v;
	nhap();
	khoitao(s);
	nhapmatran(s);
	xuatmatran(s);
	nhan1so(s);
	xuatmatran(s);
	//cout<<"Ma tran sau khi nghich dao la:"<<endl;
	//nghichdao(s);
	chon(v);
	system("pause");
}


