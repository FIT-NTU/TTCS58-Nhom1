#include<iostream>
using namespace std;
int n;
struct node{
	float giatri;
	node *tiep;
};

void khoitao(node *&dau)
{
	dau = NULL;
}

void taonut(node *&dau) 
{
	cout << "Nhap ma tran vuong n*n: ";
	cin >> n;
	int temp = n*n;
	node *p, *q;
	for (int i = 0; i < temp; i++) 
	{
		p = new node;
		p->giatri = 0;
		p->tiep = NULL;
		if (dau == NULL)
			dau = p;
		else
			q->tiep = p;
		q = p;
	}
}
void duyet(node *dau) 
{
	node *p;
	p = dau;
	int i = 0;
	while (p != NULL)
	{
		i++;
		cout << "\t" << p->giatri;
		if (i == n) 
		{
			i = 0;
			cout << endl;
		}
		p = p->tiep;
	}
}
void nhap(node *&dau)
{
	int x;
	int hangDL, cotDL;
	do {
		cout << "Nhap mot so nguyen, nhap 0 de dung: ";
		cin >> x;
		if (x != 0)
		{
			node *p, *q;
			q = dau;
			p = new node;
			cout << "Nhap hang va cot: ";
			cin >> hangDL >> cotDL;
			int vitri = 0;
			vitri = hangDL * n + cotDL;
			if (vitri >= n*n) 
			{
				cout << "Vi tri nhap khong hop le" << endl;
				cout << "Moi nhap lai: " << endl;
			}
			else {
				int i = 0;
				while (i<vitri)
				{
					i++;
					q = q->tiep;
				}
				p->tiep = q->tiep;
				q->giatri = x;
			}
		}
	} while (x != 0);
}
void nhan(node *dau, int k) 
{
	node *p = dau;
	while (p != NULL) 
	{
		p->giatri = p->giatri*k;
		p = p->tiep;
	}
}
int main() {
	node *dau;
	int k;
	khoitao(dau);
	taonut(dau);
	duyet(dau);
	nhap(dau);
	duyet(dau);
	cout << "Nhap gia tri can nhan: ";
	cin >> k;
	nhan(dau, k);
	duyet(dau);
	cout << endl;
	system("pause");
}
