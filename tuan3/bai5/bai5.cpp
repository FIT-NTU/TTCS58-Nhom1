#include <iostream> 
#include <string> 
#include <bits/stdc++.h> 
using namespace std; 
void LRS(string str) 
{ 
		// tinh do dai  cua chuoi lap lai
    int n = str.length();  
    int a[n+1][n+1]; 
    for (int i=0; i<=n; i++) 
        for (int j=0; j<=n; j++) 
            a[i][j] = 0;  // gan 0 vao vi tri truoc  vi tri dau tien cua chuoi
            
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) 
            if (str[i-1] == str[j-1] && i != j) 
                a[i][j] =  1 + a[i-1][j-1]; 
            else
                a[i][j] = max(a[i][j-1], a[i-1][j]); 
  
  // ghi chuoi vao bien res
    string res = ""; 
    int i = n, j = n;  // bat dau chay tu vi tri duoi cung ben phai
    while (i > 0 && j > 0) 
    { 
       
        if (a[i][j] == a[i-1][j-1] + 1) 
        { 
           res = res + str[i-1]; 
           i--; 
           j--; 
        } 

        else if (a[i][j] == a[i-1][j]) 
            i--; 
        else
            j--; 
    }  
    reverse(res.begin(), res.end()); // dao nguoc chuoi res de in ra 
    int m=res.length();
    cout<<"do dai cua chuoi"<<m<<endl;
    cout<< res<<endl;
}
int main() 
{ 
    string str = "AABEBCDD";
	LRS(str); 
    return 0; 
} 

  


  

