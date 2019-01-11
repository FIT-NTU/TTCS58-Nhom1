#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include <iostream>
using namespace std; 

char chuoi[300];
void nhap()
{	 
    cout<<"Nhap chuoi: "; 
    cin>>chuoi; 
}

void lap(char *p) 
{ 
        int i,j,n,xh,imax,u; 
        n = strlen(p); 
        char max[n];		//LUU CAC VI TRI LAP LAI NHIEU NHAT
        int trung[n];		//XAC DINH CAC VI TRI DA KIEM TRA HAY CHUA? 
        for(i=0;i<n;i++) 
		trung[i] = 0;	
        imax = 0;			//CHUA CO KI TU LAP LAI NHIEU NHAT
        u = 0;				//KI TU LAP LAI NHIEU NHAT HIEN TAI 
        for(i=0;i<n;i++) 
        { 
            if(trung[i]==0)					
            { 
                xh = 1; 
                for(j=i+1;j<n;j++) 
                { 
                    if(p[i]==p[j]) 
                    { 
                        trung[j] = 1;		
                        xh++; 
                    } 
                } 
                if(xh>u) 
                { 
                    int v; 
                    for(v=0;v<=imax;v++) max[v] = '\0';			//TIM CAC KI TU XUAT HIEN LON HON VA XOA CAC KI TU  
                    imax = 0; 
                    max[imax] = p[i]; 
                    imax++; 
                    u = xh; 
                    
                } 
                if(xh==u&&max[imax-1]!=p[i]) 
                { 
                    max[imax] = p[i]; 
                    imax++; 
                    u = xh; 
                } 
            } 
        } 
        max[imax] = '\0'; 
        cout<<"Chuoi tim duoc la: "<<max;
        
        //DEM DO DAI CUA KET QUA
    	int slength;	
		slength=strlen(max);
		cout << "\nDo dai cua chuoi la: " << slength;
} 

int main() 
{ 
 	nhap(); 
    lap(chuoi);
	return 0;
}
