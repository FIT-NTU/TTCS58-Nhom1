/* Dynamic Programming implementation of LCS problem */
#include<iostream> 
#include<cstring> 
#include<cstdlib> 
using namespace std; 

/* Tra ve do dài cua LCS cho X [0..m-1], Y [0..n-1] */
void lcs( char *X, char *Y, int m, int n ) 
{ 
int L[m+1][n+1]; 

/* cac buoc xay dung L[m+1][n+1] tu duoi len. 
	 L[i][j] chua do dai LCS cua X[0..i-1] va Y[0..j-1] */
for (int i=0; i<=m; i++) 
{ 
	for (int j=0; j<=n; j++) 
	{ 
	if (i == 0 || j == 0) 
		L[i][j] = 0; 
	else if (X[i-1] == Y[j-1]) 
		L[i][j] = L[i-1][j-1] + 1; 
	else
		L[i][j] = max(L[i-1][j], L[i][j-1]); 
	} 
} 
for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++) cout<<L[i][j]<<"  ";
		cout<<endl;
	}
	
	

//ma duoc dung de in LCS 
int index = L[m][n]; 

// tao mang de chua chuoi lcs 
char lcs[index]; 

// bat dau tu goc duoi cung ben phai va tung ki tu luu tru tron Lcs[]

int i = m, j = n; 
while (i > 0 && j > 0) 
{ 
	//neu ki tu hien tai cua X[] va Y[] giong nhau, thi ki tu la 1 phan cua Lcs;
	
	if (X[i-1] == Y[j-1]) 
	{ 
		lcs[index-1] = X[i-1]; // dat ki tu hien tai vao ket qua
		i--; j--; index--;	  
	} 	
	//neu k giong nhau thi tim gia tri lon hon va di theo huong do
	else if (L[i-1][j] > L[i][j-1]) 
		i--; 
	else
		j--; 
} 


cout << "LCS cua " << X << " va " << Y << " la: " << lcs; 
} 


int main() 
{ 
char X[] = "AGGTAB"; 
char Y[] = "GXTAYCB"; 
int m = strlen(X); 
int n = strlen(Y); 
lcs(X, Y, m, n); 
return 0; 
} 

