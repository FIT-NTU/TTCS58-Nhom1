#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<fstream>
#include "console1.h"

using namespace std;

struct NhanVien
{
	char nvID[4],hoTen[21];
	int tuoi,luong;	
};

vector<NhanVien> dsNV;

char tenfile[20]="dulieu.txt";


void docDSNV(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::in);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{
			while(!file.eof())
			{	
				NhanVien nv;
						
				file.getline(nv.nvID,4);
				file.ignore();
				file.getline(nv.hoTen,21);
				file>>nv.tuoi;
				file>>nv.luong;
				dsNV.push_back(nv);	
				file.ignore();						
			}
			file.close();		
			int n=dsNV.size();
			for(int i=0;i<n;i++) 
				{
					cout<<dsNV[i].nvID<<endl;
					cout<<dsNV[i].hoTen<<endl;
					cout<<dsNV[i].tuoi<<endl;
					cout<<dsNV[i].luong<<endl;
				}
			
		}
}

void inDSNV()
{
	int n=dsNV.size();
	for(int i=0;i<n;i++)
		{
			cout<<dsNV[i].nvID<<endl;
			cout<<dsNV[i].hoTen<<endl;
			cout<<dsNV[i].tuoi<<endl;
			cout<<dsNV[i].luong<<endl;
		}
}

int main()
{
	docDSNV(tenfile);
//	inDSNV();
	system("pause");
}
