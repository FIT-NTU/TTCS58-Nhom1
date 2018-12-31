#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;

int n, p, dem;

vector<int> mang, kq;

void docFile();
int kiemTra(vector<int> nhi_phan);
void quaylui(vector<int> nhi_phan, int n, int i = 0);
void showkq();
void ghi();
void output();

void docFile() 
{
    ifstream doc;
    doc.open("input4.txt");
    if(doc.is_open()) 
	{
        string dong;
        getline(doc, dong);
        stringstream a(dong);
        a >> n >> p;
        getline(doc, dong);
        stringstream b(dong);
        mang.resize(n);
        for(int i = 0; i < n; i++) 
		{
            b >> mang[i];
        }
    } 
	else 
	{
        cout << "Ko mo duoc file" << endl;
    }
	doc.close();
}

int kiemTra(vector<int> nhi_phan) 
{
    int chon = 0;
    for(int i = 0; i < n; i++) 
	{
        chon = nhi_phan[i] * mang[i] + chon;
    }
    if(chon == p)
        return true;
    return false;
}

void quaylui(vector<int> nhi_phan, int n, int i) 
{
    for(int j = 0; j <= 1; j++) 
	{
        nhi_phan[i] = j;
        if(i == n - 1) 
		{
            if(kiemTra(nhi_phan)) 
			{
                kq.insert(kq.begin(), nhi_phan.begin(), nhi_phan.end());
                dem++;
            }
        }
		else 
		{
            quaylui(nhi_phan, n, i + 1);
        }
    }
}

void showkq() 
{
    int tam = kq.size();
    for(int i = 0; i < tam; i++) 
	{
        if(i % n == 0) 
		{
            cout << endl;
        }
        cout << kq[i] << " ";
    } 
	cout << endl;
}

void output()
{
	if(dem) 
	{
        cout << dem;
        showkq();
    } 
	else
	{
        cout << "Khong chia duoc" << endl;
    }
}

void ghi() 
{
    ofstream ghi;
    ghi.open("output4.txt");
    if(dem) 
	{
        ghi << dem;
        int tam = kq.size();
        for(int i = 0; i < tam; i++) 
		{
            if(i % n == 0) 
			{
                ghi<< endl;
            }
            ghi<< kq[i] << " ";
        }
    } 
	else 
	{
        ghi << "Khong chia duoc" << endl;
    }
    ghi.close();
    cout << "ghi ket qua ra output4.txt";
}


int main() 
{
    docFile();
    cout << n << " " <<  p << endl;
    vector<int> nhi_phan;
    nhi_phan.resize(n);
    quaylui(nhi_phan, n);
    output();
    ghi();
}
