#include<iostream>
#include<string>
#include <algorithm>
using namespace std; 
//--------------------------------------------------
//Ham tim ra do dai chuoi lap dai nhat
int TimDoDaiChuoi(string x) 
{ 
    int n = x.length(); //Gan n bang do dai cua chuoi 
    // Khoi tao bang DP
    int dp[n+1][n+1]; 
    for (int i=0; i<=n; i++) 
        for (int j=0; j<=n; j++) 
            dp[i][j] = 0; 
   
    // Dien vao bang dp
    for (int i=1; i<=n; i++)  //khoi tao gia tri hang i
    { 
        for (int j=1; j<=n; j++)  // khoi tao gia tri cot j
        { 
            // Neu cac so la giong nhau va chi so khac nhau 
            if (x[i-1] == x[j-1] && i != j) 
                dp[i][j] =  1 + dp[i-1][j-1];           
                        
            //Neu cac ki tu khong giong nhau
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
        } 
    } 
   return dp[n][n]; 
} 
//------------------------------------------------
// Ham in ra chuoi lap dai nhat
string LRS(string x) 
{ 
	int n = x.length(); // gan n bang do dai chuoi x
	int dp[n+1][n+1]; // khai bao mang dp[][] de luu tru lai chuoi lap dai nhat 
	for (int i=0; i<=n; i++) 
		for (int j=0; j<=n; j++) 
			dp[i][j] = 0; 
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) 
			if (x[i-1] == x[j-1] && i != j) 
				dp[i][j] = 1 + dp[i-1][j-1]; 
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
	string res = ""; // khoi tao ket qua bang rong
	int i = n, j = n; // gan hang i va cot j bang  n tuc bang do dai chuoi x
//-------------- Duyet mang dp[][] tu duoi cung ben phai --------------------------
	while (i > 0 && j > 0) 
	{ 
		// neu o nay giong duong cheo o lien ke ngay phia tren no thi noi hai o do de thu duoc ket qua 
		if (dp[i][j] == dp[i-1][j-1] + 1) 
		{ 
		res = res + x[i-1]; 
		i--; 
		j--; 
		} 

		// di chuyen sang 1 ben de thu ket qua toi da khac
		else if (dp[i][j] == dp[i-1][j]) 
			i--; 
		else
			j--; 
	} 

	reverse(res.begin(), res.end()); // duyet mang dp[][] tu duoi len nen ghi lai ket qua theo thu tu nguoc lai
	// su dung reverse de ghi lai dao nguoc thu tu cua chuoi lap vua tim duoc 
	return res; 
} 
//-------------------------------------------------------------------
//Chuong trinh chinh
int main() 
{ 
	string x;
	cout<<"Nhap vao 1 chuoi: ";
	getline(cin,x);
	cout <<"Chuoi lap lai dai nhat la: " <<LRS(x)<<endl;
	cout<<"//---------------------------------------------------------------//"<<endl;
	cout<<"do dai cua chuoi do la: "<<TimDoDaiChuoi(x)<<endl;
	system("pause");
	return 0; 
} 

