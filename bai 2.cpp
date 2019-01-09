#include<iostream>


using namespace std;

struct node
{
int data,cot,hang;
struct node *pnext;	
};

struct list
{
	node *phead;
	node *ptail;
};

node* getnode(int x , int i , int j)
{
	node *p=new node;
	if(p==NULL)
	{
		return NULL;
	}
	p->data=x;
	p->hang=i;
	p->cot=j;
	p->pnext=NULL;
	return p;
	
}
void init(list &l)
{
	l.phead=l.ptail=NULL;

}


void addtail(list &l,node *p)
{
	if(l.phead==NULL)
	{
		l.phead=l.ptail=p;
	}
	else
	{
		l.ptail->pnext=p;
		l.ptail=p;
	}
}
void input(list &l,int m, int n)
{

	for(int i=1;i<=n;i++)
	{
	for(int j = 1;j<=m;j++)
	{
		int x;
		cout<<"nhap a["<<i<<"]["<<j<<"] = "; cin>>x;
		node *p = getnode(x,i,j);
		addtail(l, p);
	}
	}
}
void output(list l,int m,int n)
{
	int k,g,h;
	int a[n][m];
	for(node *p=l.phead;p!=NULL;p=p->pnext)
	{	
		k=p->data;
		g=p->hang;
		h=p->cot;
		a[g][h]=k;
	}
	for(g=1;g<=n;g++)
	{
		for(h=1;h<=m;h++)
		{
			cout<<" "<<a[g][h];
		}
		cout<<endl;
	}
}
void nhan1so(list &l,int m,int n)
{
	int b;
	int k,g,h;
	int a[n][m];
	cout<<"nhap so de nhan voi ma tran : ";cin>>b; cout<<endl;
	for(node *p=l.phead;p!=NULL;p=p->pnext)
	{	
		k=p->data*b;
		g=p->hang;
		h=p->cot;
		a[g][h]=k;
	}
		for(g=1;g<=n;g++)
	{
		for(h=1;h<=m;h++)
		{
			cout<<" "<<a[g][h];
		}
		cout<<endl;
	}

}

int main()
{
	list l;
	list l2;
	init(l);
	init(l2);
	int m,n,i,j;
	cout<<"nhap so luong dong : " ; cin>>n; cout<<endl;
	cout<<"nhap so luong cot : " ; cin>>m ; cout<<endl;
	input(l,n,m);
	cout<<"nhap so luong dong : " ; cin>>j; cout<<endl;
	cout<<"nhap so luong cot : " ; cin>>i ; cout<<endl;
	input(l2,i,j);
	output(l,n,m);
	output(l2,i,j);
	nhan1so(l,n,m);
	system("pause");
}
