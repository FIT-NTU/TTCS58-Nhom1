#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

int n, p, Dem;
vector <int> GiaTri, KetQua, bin;

void docfile();
bool Check_GiaTri(vector<int> bin);
void Ghifile();
void QuayLui(vector<int> bin, int n,int i = 0);
void ShowKetQua();
void update(vector<int> bin);

int main(){
	docfile();
	vector<int> bin;
    bin.resize(n);
    QuayLui(bin, n);
     if(Dem) {
        cout << Dem;
        ShowKetQua();
    } 
	else {
        cout << "Khong chia duoc" << endl;
    }
    Ghifile();
}

bool check_GiaTri(vector<int> bin) {
    int selected = 0;
    for(int i = 0; i < n; i++) {
        selected += bin[i] * GiaTri[i];
    }
    if(selected == p)
        return true;
    return false;
}

void update(vector<int> bin) {
    KetQua.insert(KetQua.begin(), bin.begin(), bin.end());
}

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

void QuayLui(vector<int> bin, int n,int i)
	{
	for (int j=0;j<=1;j++){
		bin[i]=j;
	if (i==n-1)
	{
		if(check_GiaTri(bin))
		{
			update(bin);
			Dem++;
		}
	}
	else {
			QuayLui(bin,n,i+1);
		}
	}
}

void ShowKetQua() {
    int tmp = KetQua.size();
    for(int i = 0; i < tmp; i++) {
        if(i % n == 0) {
            cout << endl;
        }
        cout << KetQua[i] << " ";
    } cout << endl;
}

void Ghifile() {
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

