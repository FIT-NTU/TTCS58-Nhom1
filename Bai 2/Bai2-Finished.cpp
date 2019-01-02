#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
#include<vector>
using namespace std; 
  
struct nut{
	float row;
	float col;
	float val;
	nut *next;
};

typedef struct nut Node;

Node *dau, *dau2, *dau3, *tong12, *hieu12, *tich13, *thuong13, *ndao1, *ndao3;

void khoiTao(Node *&dau){
	dau = NULL;
}

void append(Node *&dau, Node *target){
	if (dau==NULL)
		dau=target;
	else
		append(dau->next, target);
}

Node *createNode(int row, int col,int val)
{
       Node *p = new Node;
       p->row = row;
       p->col = col;
       p->val = val;
       p->next = NULL;
       return p;
}

void input(Node *&dau){
	int n=0, r, c, v;
	cout<<"Nhap so luong phan tu khac 0 trong ma tran: "; cin>>n;
	for(int i=0; i<n; i++)
	{
		r=0; c=0; v=0;
		cout<<"Nhap hang cua phan tu thu "<<i<<": "; cin>>r;
		cout<<"Nhap cot cua phan tu thu "<<i<<": "; cin>>c;
		cout<<"Nhap gia tri cua phan tu thu "<<i<<": "; cin>>v;
		append(dau, createNode(r, c, v));
	}
}

void outputMatrix(Node *dau, int rows, int cols){
	cout<<"\n";
	Node *curr;
	curr=dau;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if (curr!=NULL)
			{
				if (i==curr->row and j==curr->col)
				{
					cout<<setw(6)<<curr->val;
					curr=curr->next;
				}
				else cout<<setw(6)<<"0";
			}
			else cout<<setw(6)<<"0";
		}
		cout<<"\n";
	}
}

void outputNhanVoiMotSo(Node *&dau, int rows, int cols){
	int target;
	cout<<"Nhap so can nhan voi ma tran: "; cin>>target;
	Node *curr;
	curr=dau;
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if (curr!=NULL)
				{
					if (i==curr->row and j==curr->col)
					{
						cout<<setw(4)<<curr->val*target;
						curr=curr->next;
					}
					else cout<<setw(4)<<"0";
				}
				else cout<<setw(4)<<"0";
			}
			cout<<"\n";
		}
}

void createMatrix(Node *dau, vector< vector< int > > &a, int rows, int cols){
	Node *curr;
	curr=dau;
	a.resize(rows);
	for(int i=0; i<rows; i++) a[i].resize(cols);
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if (curr!=NULL)
			{
				if (i==curr->row and j==curr->col)
				{
					a[i][j]=curr->val;
					curr=curr->next;
				}
				else a[i][j]=0;
			}
			else a[i][j]=0;
		}
	}
}

void matrixToLinkedList(vector< vector< float > > a, Node *&res){
	for(int i=0; i<a.size(); i++)
	{
		for(int j=0; j<a[i].size(); j++)
		{
			if (a[i][j]!=0)
			{
				append(res, createNode(i, j, a[i][j]));
			}
		}
	}
}

int determinant(vector< vector< int > > matrix, int n){
	int s, res= 0;
	if( n == 1 ) return matrix[0][0];
	if( n == 2 ) return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]) ;
		
	for(int k=0; k<n; k++ ){		
		vector< vector< int > > helper;
		helper.resize(n);
		for(int i=0; i<n; i++) helper[i].resize(n);		
		for(int i=0; i<n; i++)
		{		
			for(int j=1; j<n; j++)
			{				
				if (i<k) helper[i][j-1] = matrix[i][j];
				else if (i>k) helper[i-1][j-1] = matrix[i][j];
			}
		}
		
		if (k%2==0) s = 1;
		else s = -1;
		
		res+= matrix[k][0]*s*determinant(helper, n-1);
	}
	return res;
}

void xuatDinhThuc(Node *dau, int rows, int cols){
	if (rows!=cols)
		cout<<"\nMa tran khong co dinh thuc.";
	else
	{
		vector< vector< int > > mt;
		createMatrix(dau, mt, rows, cols);
		cout<<"\nDinh thuc cua ma tran nay bang: "<<determinant(mt, rows);
	}
}

void tinhTong(Node *dau1, Node *dau2, Node *&tong, int rows, int cols){
	Node *curr1; curr1=dau1;
	Node *curr2; curr2=dau2;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (curr1!=NULL and curr2!=NULL)
			{
				if (curr1->row==i and curr1->col==j and curr2->row==i and curr2->col==j)
				{
					int temp = curr1->val + curr2->val;
					append(tong, createNode(i, j, temp));
					curr1=curr1->next;
					curr2=curr2->next;
				}
				else if (curr1->row==i and curr1->col==j)
				{
					int temp = curr1->val;
					append(tong, createNode(i, j, temp));
					curr1=curr1->next;
				}
				else if (curr2->row==i and curr2->col==j)
				{
					int temp = curr2->val;
					append(tong, createNode(i, j, temp));
					curr2=curr2->next;
				}
			}
			else if (curr1!=NULL)
			{
				if (curr1->row==i and curr1->col==j)
				{
					int temp = curr1->val;
					append(tong, createNode(i, j, temp));
					curr1=curr1->next;
				}
			}
			else if (curr2!=NULL)
			{
				if (curr2->row==i and curr2->col==j)
				{
					int temp = curr2->val;
					append(tong, createNode(i, j, temp));
					curr2=curr2->next;
				}
			}
		}
	}
}

void tinhHieu(Node *dau1, Node *dau2, Node *&hieu, int rows, int cols){
	Node *curr1; curr1=dau1;
	Node *curr2; curr2=dau2;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			if (curr1!=NULL and curr2!=NULL)
			{
				if (curr1->row==i and curr1->col==j and curr2->row==i and curr2->col==j)
				{
					int temp = curr1->val - curr2->val;
					append(hieu, createNode(i, j, temp));
					curr1=curr1->next;
					curr2=curr2->next;
				}
				else if (curr1->row==i and curr1->col==j)
				{
					int temp = curr1->val;
					append(hieu, createNode(i, j, temp));
					curr1=curr1->next;
				}
				else if (curr2->row==i and curr2->col==j)
				{
					int temp = 0 - curr2->val;
					append(hieu, createNode(i, j, temp));
					curr2=curr2->next;
				}
			}
			else if (curr1!=NULL)
			{
				int temp = curr1->val;
				append(hieu, createNode(i, j, temp));
				curr1=curr1->next;
			}
			else if (curr2!=NULL)
			{
				int temp = 0 - curr2->val;
				append(hieu, createNode(i, j, temp));
				curr2=curr2->next;
			}
		}
	}
}

int tinhTichHelper(vector< vector< int > > m1, vector< vector< int > > m2, int hang1, int cot1, int cot2){
//	hang2==cot1
	int res=0;
	for (int i=0; i<cot1; i++)
		res+= m1[hang1][i] * m2[i][cot2];
	return res;
}

void tinhTich(Node *dau1, Node *dau2, Node *&tich, int rows1, int cols1, int cols2){
	vector< vector< int > > mt1;
	vector< vector< int > > mt2;
	vector< vector< float > > mtt;
	createMatrix(dau1, mt1, rows1, cols1);
	createMatrix(dau2, mt2, cols1, cols2);
	mtt.resize(rows1);
	for(int i=0; i<rows1; i++)
		mtt[i].resize(cols2);
	for(int i=0; i<rows1; i++)
	{
		for (int j=0; j<cols2; j++)
		{
			mtt[i][j]=0;
		}
	}
	for(int i=0; i<rows1; i++)
	{
		for (int j=0; j<cols2; j++)
		{
			mtt[i][j] += tinhTichHelper(mt1, mt2, i, cols1, j);
		}
	}
	matrixToLinkedList(mtt, tich);
}

int determinantOfFloats(vector< vector< float > > matrix, int n){
	int s, res= 0;
	if( n == 1 ) return matrix[0][0];
	if( n == 2 ) return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]) ;
		
	for(int k=0; k<n; k++ ){		
		vector< vector< float > > helper;
		helper.resize(n);
		for(int i=0; i<n; i++) helper[i].resize(n);		
		for(int i=0; i<n; i++)
		{		
			for(int j=1; j<n; j++)
			{				
				if (i<k) helper[i][j-1] = matrix[i][j];
				else if (i>k) helper[i-1][j-1] = matrix[i][j];
			}
		}
		
		if (k%2==0) s = 1;
		else s = -1;
		
		res+= matrix[k][0]*s*determinantOfFloats(helper, n-1);
	}
	return res;
}

int con(vector< vector< int > > a, int n, int h, int c)
{
	vector< vector< float > > b;
	b.resize(100);
	for(int i=0; i<100; i++) b[i].resize(100);
	int i,j,x=-1,y;
	for(i=0;i<n;i++)
	{
		if(i==h) continue;
		x++;y=-1;
		for(j=0;j<n;j++)
		{
   			if(j==c)continue;
   			y++;
   			b[x][y]=a[i][j];
  		}
 	}
 	if((h+c)%2==0) return determinantOfFloats(b,n-1);
 	return -determinantOfFloats(b,n-1);
}
void nghichdao(vector< vector< int > > a, int n, Node *&ndao){
	vector< vector< float > > b;
	b.resize(100);
	for(int i=0; i<100; i++) b[i].resize(100);
	for(int i=0;i<n;i++)
	{
  		for(int j=0;j<n;j++)
  		{
   			b[i][j]=con(a,n,i,j);
  		}
 	}
 	for(int i=0;i<n-1;i++)
  		for(int j=i+1;j<n;j++)
  		{
   			int t=b[i][j];
   			b[i][j]=b[j][i];
   			b[j][i]=t;
  		}
 	int k=determinant(a,n);
 	for(int i=0;i<n;i++)
  		for(int j=0;j<n;j++)
   			b[i][j]/=k;
 	if(k==0) cout<<"\nkhong co ma tran nghich dao!";
 	else
 	{
 		cout<<endl;
 		for(int i=0; i<n; i++)
 		{
		 	for(int j=0; j<n; j++)
 			{
 				cout<<setw(3)<<b[i][j];
			}
			cout<<endl;
		}
	}
	matrixToLinkedList(b, ndao);
}

int main(){
	int number_of_rows=0, number_of_cols=0;
	cout<<"Nhap tong so hang cua ma tran: "; cin>>number_of_rows;
	cout<<"Nhap tong so cot cua ma tran: "; cin>>number_of_cols;
	khoiTao(dau);
	input(dau);
	outputMatrix(dau, number_of_rows, number_of_cols);
	outputNhanVoiMotSo(dau, number_of_rows, number_of_cols);
	if (number_of_rows == number_of_cols)
	{
		khoiTao(ndao1);
		vector< vector< int > > nd;
		createMatrix(dau, nd, number_of_rows, number_of_cols);
		cout<<"\nMa tran nghich dao cua ma tran 1:\n";
		nghichdao(nd, number_of_rows, ndao1);
	}
	else "\nMa tran 1 khong co ma tran nghich dao.";
	xuatDinhThuc(dau, number_of_rows, number_of_cols);

	khoiTao(dau2);
	cout<<"\n";
	cout<<"Ma tran 2 se tu dong co kich thuoc bang voi ma tran 1.\n";
	cout<<"Nhap thong tin cho ma tran 2 de cong, tru voi ma tran 1.\n";
	input(dau2);
	cout<<"Ma tran 2:\n";
	outputMatrix(dau2, number_of_rows, number_of_cols);
	khoiTao(tong12);
	khoiTao(hieu12);
	tinhTong(dau, dau2, tong12, number_of_rows, number_of_cols);
	cout<<"Ma tran 1 + Ma tran 2:\n";
	outputMatrix(tong12, number_of_rows, number_of_cols);
	tinhHieu(dau, dau2, hieu12, number_of_rows, number_of_cols);
	cout<<"Ma tran 1 - Ma tran 2:\n";
	outputMatrix(hieu12, number_of_rows, number_of_cols);
	
	khoiTao(dau3);
	cout<<"\n";
	cout<<"Ma tran 3 se tu dong co kich thuoc phu hop de nhan voi ma tran 1.\n";
	int cols3;
	cout<<"Nhap so cot cua ma tran 3: "; cin>>cols3;
	cout<<"Nhap thong tin cho ma tran 3 de nhan (va chia, neu co) voi ma tran 1.\n";
	input(dau3);
	cout<<"Ma tran 3:\n";
	outputMatrix(dau3, number_of_cols, cols3);
	khoiTao(tich13);
	tinhTich(dau, dau3, tich13, number_of_rows, number_of_cols, cols3);
	cout<<"Ma tran 1 * Ma tran 3:\n";
	outputMatrix(tich13, number_of_rows, cols3);
	
	if (cols3 == number_of_cols)
	{
		khoiTao(ndao3);
		vector< vector< int > > nd3;
		createMatrix(dau3, nd3, number_of_cols, cols3);
		cout<<"Ma tran nghich dao cua ma tran 3:\n";
		nghichdao(nd3, number_of_cols, ndao3);
		tinhTich(dau, ndao3, thuong13, number_of_rows, number_of_cols, cols3);
		cout<<"Ma tran 1 / Ma tran 3:\n";
		outputMatrix(thuong13, number_of_rows, cols3);
	}
	else "\nKhong the lay ma tran 1 chia cho ma tran 3.";
	
	getch();
	return 0;
}
