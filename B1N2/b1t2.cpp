#include <iostream>

using namespace std;


int plr1;
int plr2;
int a;
void nhap()
{
	cout << "------MENU------" << endl;   
    cout << "1.PLAY WITH X" << endl;
    cout << "2.PLAY WITH O" << endl;
    cout << "3.EXIT"<<endl;
    cin>>a;
	if(a==1)
	{
		plr1=a ; plr2=2;
	}else if(a==2) 
	{
		plr1=a ; plr2=1;
	}else
	if(a==3)
	{
	 cout<<"bye!!!"<<endl;	
	}else 
	{
	cout<<"Nhap sai "<<endl; nhap();
	}
}

void luatchoivahienthi()
{
	
	cout << " ___________________" << endl;
    cout << " | (1) | (2) | (3) |" << endl;
    cout << " |_____|_____|_____|" << endl;
    cout << " | (4) | (5) | (6) |" << endl;
    cout << " |_____|_____|_____|" << endl;
    cout << " | (7) | (8) | (9) |" << endl;
    cout << " |_____|_____|_____|" << endl;
    cout << endl;
    cout << endl;
	int k;
	char choice2;
    char xo;
    int choice;
    char a =' '; char b= ' '; char c= ' '; char d = ' '; char e = ' '; char f= ' '; char g= ' '; char h = ' '; char i= ' ';
    int dem=0;
	
    for ( int k = 1; k < 10 ; k ++) {
    	
    	dem++;

		if(plr1%2==0)
		{
			if ( k % 2 == 0) {
            cout << "luot cua : "<<plr2<< endl;
            xo = 'X';
        }
        else {
            cout << "luot cua : "<<plr1 << endl;
            xo = 'O';
        }
		}else
        if ( k % 2 == 0) {
            cout << "luot cua : "<<plr2<< endl;
            xo = 'O';
        }
        else {
            cout << "luot cua : "<<plr1 << endl;
            xo = 'X';
        }
        cout << "Nhap so de danh vi tri : " << endl;
        cin >> choice;
        switch (choice) {
                case 1:
                    a=xo;
                    break;
                case 2:
                    b=xo;
                    break;
                case 3:
                    c=xo;
                    break;
                case 4:
                    d=xo;
                    break;
                case 5:
                    e=xo;
                    break;
                case 6:
                    f=xo;
                    break;
                case 7:
                    g=xo;
                    break;
                case 8:
                    h=xo;
                    break;
                case 9:
                    i=xo;
                    break;
                default:
                    cout << "Nhap sai so !" << endl;
                    
        }
        system("cls");
        cout << "------MENU------" << endl;   
    	cout << "1.PLAY WITH X" << endl;
     	cout << "2.PLAY WITH O" << endl;

        cout << " ___________________" << endl;
        cout << " |  "<<a<<"  |  "<<b<<"  |  "<<c<<"  |" << endl;
        cout << " |_____|_____|_____|" << endl;
        cout << " |  "<<d<<"  |  "<<e<<"  |  "<<f<<"  |" << endl;
        cout << " |_____|_____|_____|" << endl;
        cout << " |  "<<g<<"  |  "<<h<<"  |  "<<i<<"  |" << endl;
        cout << " |_____|_____|_____|" << endl;
        cout << endl;
        cout << endl;
        
		cout << " ___________________" << endl;
   		cout << " | (1) | (2) | (3) |" << endl;
    	cout << " |_____|_____|_____|" << endl;
    	cout << " | (4) | (5) | (6) |" << endl;
    	cout << " |_____|_____|_____|" << endl;
    	cout << " | (7) | (8) | (9) |" << endl;
    	cout << " |_____|_____|_____|" << endl;
   		cout << endl;
    	cout << endl;

        if ( a == 'X' && b == 'X' && c == 'X' || d == 'X' && e == 'X' && f == 'X' || g == 'X' && h == 'X' && i == 'X' ||
             a == 'X' && d == 'X' && g == 'X' || b == 'X' && e == 'X' && h == 'X' || c == 'X' && f == 'X' && i == 'X' ||
             a == 'X' && e == 'X' && i == 'X' || g == 'X' && e == 'X' && c == 'X' ) {
                cout << "   "<<plr1<<" THANG!!! " << endl;
               	a=' ',b=' ',c=' ',d=' ',e=' ',f=' ',g=' ',h=' ',i=' ';
            	cout<<"ban co muon choi lai : \nNhap so '1' de choi lai\nNhap so '0' de ket thuc\n";cin>>k;
				if(k==1) 
				{
				nhap(); luatchoivahienthi();
				}
				else cout<<"ket thuc"<<endl; break; 
                }
        else if ( a == 'O' && b == 'O' && c == 'O' || d == 'O' && e == 'O' && f == 'O' || g == 'O' && h == 'O' && i == 'O' ||
                a == 'O' && d == 'O' && g == 'O' || b == 'O' && e == 'O' && h == 'O' || c == 'O' && f == 'O' && i == 'O' ||
                a == 'O' && e == 'O' && i == 'O' || g == 'O' && e == 'O' && c == 'O' )   {
                cout << "   "<<plr2<<" THANG!!! " << endl;
                a=' ',b=' ',c=' ',d=' ',e=' ',f=' ',g=' ',h=' ',i=' ';
                cout<<"ban co muon choi lai : \nNhap so '1' de choi lai\nNhap so '0' de ket thuc\n";cin>>k;
				if(k==1) 
				{
				nhap(); luatchoivahienthi();
				}
				else cout<<"ket thuc"<<endl; break;
                }
        
    }
    			if(dem>=9)
    			{
       		 	a=' ',b=' ',c=' ',d=' ',e=' ',f=' ',g=' ',h=' ',i=' ';
    			cout << "Hoa !" << endl;
   				cout<<"ban co muon choi lai : \nNhap so '1' de choi lai\nNhap so '0' de ket thuc\n";cin>>k;
				if(k==1) 
				{
				nhap(); luatchoivahienthi();
				}
				else cout<<"ket thuc"<<endl; 
				}
    

    
}


int main()
{
	nhap();
	if(a==3)
	{
		return 0;
	}
	luatchoivahienthi();
	system("pause");
}
