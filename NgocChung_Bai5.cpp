#include <iostream>

using namespace std;

int main()
{
    char choice2;
    char xo;
    int choice;
    string plr1;
    string plr2;
    char a =' '; char b= ' '; char c= ' '; char d = ' '; char e = ' '; char f= ' '; char g= ' '; char h = ' '; char i= ' ';


    //INTRODUCTION - cin player's names
    START:
    cout << "3x3 - 2 PLAYERS - TIC TAC TOE" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Nhap ten nguoi choi 1: " << endl;
    cin >> plr1;
    cout << endl;
    cout << "Nhap ten nguoi choi 2: " << endl;
    cin >> plr2;
    cout << endl;
    //GAMEPLAY
	
    cout << " ___________________" << endl;
    cout << " | (7) | (8) | (9) |" << endl;
    cout << " |_____|_____|_____|" << endl;
    cout << " | (4) | (5) | (6) |" << endl;
    cout << " |_____|_____|_____|" << endl;
    cout << " | (1) | (2) | (3) |" << endl;
    cout << " |_____|_____|_____|" << endl;
    cout << endl;
    cout << endl;
    for ( int k = 1; k < 10 ; k ++) {
        if ( k % 2 == 0) {
            cout << ""<<plr1 << endl;
            xo = 'X';
        }
        
        else 
		{
            cout << ""<<plr2 << endl;
            xo = 'O';
        }
        cout << "Nhap so ki tu de danh: " << endl;
        cin >> choice;
        switch (choice) {
                case 7:
                    a=xo;
                    break;
                case 8:
                    b=xo;
                    break;
                case 9:
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
                case 1:
                    g=xo;
                    break;
                case 2:
                    h=xo;
                    break;
                case 3:
                    i=xo;
                    break;
                default:
                    cout << "ERROR: Chon so trong pham vi <3" << endl;
                    break;
        }
        system("cls");//xoa mang hinh

        cout << " ___________________" << endl;
        cout << " |  "<<a<<"  |  "<<b<<"  |  "<<c<<"  |" << endl;
        cout << " |_____|_____|_____|" << endl;
        cout << " |  "<<d<<"  |  "<<e<<"  |  "<<f<<"  |" << endl;
        cout << " |_____|_____|_____|" << endl;
        cout << " |  "<<g<<"  |  "<<h<<"  |  "<<i<<"  |" << endl;
        cout << " |_____|_____|_____|" << endl;
        cout << endl;
        cout << endl;

        if ( a == 'X' && b == 'X' && c == 'X' || d == 'X' && e == 'X' && f == 'X' || g == 'X' && h == 'X' && i == 'X' ||
             a == 'X' && d == 'X' && g == 'X' || b == 'X' && e == 'X' && h == 'X' || c == 'X' && f == 'X' && i == 'X' ||
             a == 'X' && e == 'X' && i == 'X' || g == 'X' && e == 'X' && c == 'X' ) {
                cout << "   "<<plr1<<" WON!!! " << endl;
                	system("cls");//xoa mang hinh
                goto QUESTION;
                }
        else if ( a == 'O' && b == 'O' && c == 'O' || d == 'O' && e == 'O' && f == 'O' || g == 'O' && h == 'O' && i == 'O' ||
                a == 'O' && d == 'O' && g == 'O' || b == 'O' && e == 'O' && h == 'O' || c == 'O' && f == 'O' && i == 'O' ||
                a == 'O' && e == 'O' && i == 'O' || g == 'O' && e == 'O' && c == 'O' )   {
                cout << "   "<<plr2<<" WON!!! " << endl;
                goto QUESTION;
                
                }
    }
    cout << "2 NGUOI CHOI HOA" << endl;

    QUESTION:
        cout << " Ban muon choi lai <y/n>" << endl;
        cin >> choice2;
        switch (choice2)
            case 'y' :
                goto START;


    return 0;
}

