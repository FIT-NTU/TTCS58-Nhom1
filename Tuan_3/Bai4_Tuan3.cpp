//Ho va Ten: Sam Van Quan, lop : 58TH1, MSSV: 58131370
//----------------------------------------------------------------
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
//----------------------------------------------------
// Ham tim gia tri lon nhat cua 2 so dung de so sanh do dai cua 2 chuoi X va Y
int max(int a, int b);
//------------------------------------------------------------
// Ham Tim chuoi con dai nhat
void TimLCS(char *X, char *Y, int XLen, int YLen); 
//---------------------------------------------------------
int main() {
  char X[50] ; // khai bao chuoi X
  cout<<"Nhap vao chuoi X: ";
  gets(X); // Nhap vao chuoi X
  char Y[50] ; // khai bao chuoi Y
  cout<<"Nhap vao chuoi Y: ";
  gets(Y); // Nhap vao chuoi Y
  int XLen = strlen(X);// XLen = do dai chuoi X
  int YLen = strlen(Y);// YLen = do dai chuoi Y
  TimLCS(X, Y, XLen, YLen);// goi ham tim chuoi con dai nhat
  return 0;
}
//--------------------------------------------------------------
//tim gia tri lon nhat cua 2 so dung de so sanh do dai cua 2 chuoi
int max(int a, int b) {
  if(a>b) return a;
  return b;
}
//-------------------------------------------------------------------
// tim chuoi con chung dai nhat
void TimLCS(char *X, char *Y, int XLen, int YLen) {
  int L[XLen + 1][YLen + 1];// khoi tao 1 mang L luu gia tri do dai cua chuoi X va Y
  int r, c, i; // khai bao r la so cot, c la so hang, i la bien de luu tru do dai lon nhat cua chuoi
  for(r = 0; r <= XLen; r++) {   // cot dau tien khoi tao co gia tri bang 0

    for(c = 0; c <= YLen; c++) {	//hang dau tien khoi tao co gia tri bang 0

      if(r == 0 || c == 0) {

        L[r][c] = 0;   // do dai chuoi bang 0

      } else if(X[r - 1] == Y[c - 1]) {

        L[r][c] = L[r - 1][c - 1] + 1;

      } else {

        L[r][c] = max(L[r - 1][c], L[r][c - 1]);
      }
    }
  }
  r = XLen;// cot bang do dai cua chuoi X
  c = YLen;// hang bang do dai cuau chuoi Y
  i = L[r][c];// i dung de luu do dai chuoi con dai nhat
  char LCS[i+1];
  LCS[i] = '\0'; // dat ki tu 0 tai cuoi mang de khi duyet gap ki tu do thi ket thuc mang
  while(r > 0 && c > 0) {

    if(X[r - 1] == Y[c - 1]) {
    	
      LCS[i - 1] = X[r - 1];

      		i--;
      		r--;
      		c--;
    } else if(L[r - 1][c] > L[r][c - 1]) {
      			r--;
    } else {

      		c--;

    }

  }
     cout<<"Chuoi chung co do dai lon nhat la: "<<L[XLen][YLen]<<endl;
     cout<<"Chuoi do la: "<<LCS<<endl;  
}

