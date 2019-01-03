#include<iostream>

using namespace std;

//MA TRAN THUA
struct Node
{
	Node*nextrow; // Con tro nextrow tro toi hang tiep theo
    Node*nextcol; // Con tro nextcol tro toi cot tiep theo
    int row;
    int col;
    double value;
};
       
//CLASS CUA MA TRAN THUA
class sparse_matrix
{
private:
	Node**rowhead;
	Node**colhead;
    int rows;  // So hang cua ma tran
	int cols; // So cot cua ma tran
public:
	sparse_matrix(int x,int y);
public:
    void multiply(sparse_matrix a); // Nhan hai ma tran
 	void mul(int**&A,int m,int n);
	void display(); // Hien thi ham ma tran

};

sparse_matrix::sparse_matrix(int x, int y) 
{
	rows=x;
	cols=y;
    rowhead=new Node*[x];// Con tro toi 1 mang gom x phan tu
   	colhead=new Node*[y];// Con tro toi 1 mang gom y phan tu
   	for(int i=0;i<x;i++)
    {
    	rowhead[i]=new Node;
    	rowhead[i]->nextcol=NULL;
    	rowhead[i]->row=i;
    }
    for(int j=0;j<y;j++)
    {
    	colhead[j]=new Node;
    	colhead[j]->nextrow=NULL;
    	colhead[j]->col=j;
    }
}

//---------------Ham nhan 2 ma tran thua------------------- //
void sparse_matrix::multiply(sparse_matrix a)
{
    Node *lead1, *lead2;
    int m,n,k;
    double sum;
    m=rows;
    n=a.cols;
    if(cols!=a.rows)
        {
            cout<<"Khong thoa man dieu kien nhan hai ma tran."<<endl;
            exit(0);
        }
               
        sparse_matrix c(m,n);        // Tao ma tran tich //
        for(int i=0;i<m;i++)
            {
                if(rowhead[i]->nextcol!=NULL)
                for(k=0;k<n;k++)
                {
	                sum=0;
                    lead1=rowhead[i]->nextcol;
                    while(lead1!=NULL)
                    {
                        lead2=colhead[k]->nextrow;
                        while(lead2!=NULL)
                        {
                            if(lead1->col==lead2->row)
                            sum+=lead1->value*lead2->value;
                            lead2=lead2->nextrow;
                        }
      		            lead1=lead1->nextcol;
                        }
                        if(sum!=0)
                        c.insert_remove(i+1,k+1,sum);
              	        }
}
              
int main ()
{
	
	
	return 0;
}
