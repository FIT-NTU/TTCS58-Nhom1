#include <iostream> 
#include<bits/stdc++.h>

using namespace std; 

int main()
{
	string s; // khoi tao chuoi s
	cout << "Nhap vao chuoi: ";
	getline (cin, s); // ghi chuoi vao s
	int n = s.length(); 
	int a[n+1][n+1]; // tao ma tran vuong a
	// khoi tao cac gia tri cua mang bang 0
    for (int i=0; i<=n; i++)
	{
    	for (int j=0; j<=n; j++)
    	{
    		a[i][j] = 0; 
		}
	}
	
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=n; j++) 
        { 
            if (s[i-1] == s[j-1] && i != j) // neu ki tu giong nhau va i != j
			{
                a[i][j] = a[i-1][j-1] + 1;  // gia tri tai diem do bang gia tri cheo tren trai cua no +1      
            }
            else
            {
            	a[i][j] = max(a[i][j-1], a[i-1][j]); // gia tri tai diem do bang gia tri lon hon trong hai gia tri tren va trai cua no
			}
        } 
    } 
    string kq = ""; // tao chuoi kq de luu tru chuoi ket qua
	int i = n; 
	int j = n;
	while (i > 0 && j > 0) // Kiem tra dieu kien
	{
   		if (a[i][j] == a[i-1][j-1] + 1) // Kiem tra gia tri tai diem do co bang gia tri tai diem cheo tren trai +1 hay khong
		{
        	kq = kq + s[i-1]; // Them ki tu tai vi tri s[i-1] vao chuoi
        	i--; // giam i
       		j--; // giam j
   		}
		else if (a[i][j] == a[i-1][j]) //Kiem tra gia tri tai diem do co bang gia tri tai diem do co bang gia tri ben trai no khong
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	reverse(kq.begin(), kq.end()); // In chuoi theo chieu nguoc lai
	int m = kq.length();
	cout<<"Do dai cua chuoi: "<<m<<endl;
	cout<<"Chuoi con dai nhat la: "<<kq<<endl;
	system("pause");
}

