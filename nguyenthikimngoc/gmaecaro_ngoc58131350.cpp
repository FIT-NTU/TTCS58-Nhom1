                                                      Bai bao cao:
                                                         BAI 5:
                                           Nguyen Thi Kim Ngoc mssv:58131350
-Tro choi caro la tro choi gom 2 nguoi choi, doi thu nay se tim cach gianh chien thang truoc nguoi kia trong mot so huu han nuocc di.
moi nuoc di duoc tao ra tu mot trang thái bat ky cua tran dau.Neu sau mot gioi han nuoc di neu khong ai chien thang coi nhu haa.
Trong tro choi nay moi doi thu trong moi luot di cua minh se chon mot o trong con lai tren ban co(ke san cac o luoi) sao cho tao thanh n con lien tiep de
 chien thang.Ngoai ra cung chung minh duoc ,nguoi di truoc bao gio cung có thuat toan de thang,do do de han che thuan loi cua nguoi di truoc thi ta dat 
 ra cac luat sau:
-Ban co caro co kich thuoc tuy y n*n
-Quan co dau tien phai danh chinh giua luoi ban co
-Neu ton tai dung 5 con lien tiep tren 1 hang la thang(cheo,ngang,doc)
-Neu het cho di thi 2 bên hoa
Code demo
	#include <iostream>

	using namespace std;

	int main(){
                   
	char choice2;
	char xo;
	int choice;
	string plr1;
	string plr2;
	char a =' '; char b= ' '; char c= ' '; char d = ' '; char e = ' '; char f= ' '; char g= ' '; char h = ' '; char i= ' ';


	 //INTRODUCTION - cin player's names
	START:
	cout << "3x3 - 2 PLAYERS - CARO BOARD (Use NumPad for optimal gameplay)" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Insert player 1's name (No space between characters)" << endl;
	cin >> plr1;
	cout << endl;
	cout << "Insert player 2's name (No space between characters)" << endl;
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
           cout << ""<<plr1<<"'s turn " << endl;
           xo = 'X';
       }
       else {
            cout << ""<<plr2<<"'s turn " << endl;
           xo = 'O';
        }
        cout << "Please make your choice by selecting the appropriate number (Use NumPad for optimal  gameplay)" << endl;
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
                    cout << "ERROR: Pick the number within range" << endl;
                    break;
        }

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
                goto QUESTION;
                }
        else if ( a == 'O' && b == 'O' && c == 'O' || d == 'O' && e == 'O' && f == 'O' || g == 'O' && h == 'O' && i == 'O' ||
                a == 'O' && d == 'O' && g == 'O' || b == 'O' && e == 'O' && h == 'O' || c == 'O' && f == 'O' && i == 'O' ||
                a == 'O' && e == 'O' && i == 'O' || g == 'O' && e == 'O' && c == 'O' )   {
                cout << "   "<<plr2<<" WON!!! " << endl;
                goto QUESTION;
                }
       	 }
         cout << "It's a Draw" << endl;

           QUESTION:
          cout << " Do you want to play again? <y/n>" << endl;
         cin >> choice2;
         switch (choice2)
           case 'y' :
                goto START;


            return 0;
             }


