#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

int n, p, dem;
vector< int > cachTangQua;
vector <int> GiaTri, KetQua, bin;

void docfile(){
	ifstream doc;
	doc.open("input4.txt");
	
	if(doc.is_open())
	{
		doc>> n >> p;
		GiaTri.resize(n); 
		for(int i = 0 ;i < n; i++){
			doc>> GiaTri[i];
		}
		cout<< n<<" "<< p<< endl;
		for(int i = 0; i< n; i++)
		cout<<"gia tri qua:"<< GiaTri[i]<< endl;
		
	}
	else{
		cout<<"ko the doc duoc file: "<<endl;
	}
}
void quaylui(vector< int > a, int control, int p)
{
    if (control==n and p==0)
    {
    	//truong hop dung
        dem++;
        xuat.push_back(cachTangQua);
    }

    if (control<n and p>=0) //chi chay tu 0 toi n-1
	{
		//vet can tat ca cac truong hop
        cachTangQua[control] = 1;
        quaylui (a, control+1, p-a[control]);
        cachTangQua[control] = 0;
        quaylui (a, control+1, p);
    }
}
void output() {
    ofstream file;
    file.open("output4.txt");

    if(Dem) {
        file << Dem;

        int tmp = KetQua.size();
        for(int i = 0; i < tmp; i++) {
            if(i % n == 0) {
                file << endl;
            }
            file << KetQua[i] << " ";
        }
    } 
	else {
        file << "Khong chia duoc" << endl;
    }
    file.close();
    cout << "da luu ket qua output4.txt";
}
int main()
{
    int P;
    vector< int > giaTriCacMonQua;
    docFile(n, P, giaTriCacMonQua);
    cachTangQua.resize(n);
    quaylui(giaTriCacMonQua, 0, P);
    output();
}

