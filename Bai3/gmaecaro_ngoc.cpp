                                                      Bài báo cáo:
                                                         BÀI 5:
                                           Nguyên Thi Kim Ngoc mssv:58131350
-Trò choi caro là trò choi gom 2 nguoi choi, doi thu này se tìm cách giành chien thang truoc nguoi kia trong mot so huu han nuocc di.
moi nuoc di duoc tao ra tu mot trang thái bat ky cua tran dau.Neu sau mot gioi han nuoc di nêu không ai chiên thang coi nhu hòa.
Trong trò choi này moi doi thu trong moi luot di cua mình se chon mot ô trong còn lai trên bàn co(ke san các ô luoi) sao cho tao thành n con liên tiep de
 chien thang.Ngoài ra cung chung minh duocc ,nguoi di truoc bao gio cung có thuat toán de thang,do dó de han che thuan loi cua nguoi di truoc thì ta dat 
 ra các luat sau:
-Bàn co caro có kích thuoc tùy ý n*n
-Quân co dau tiên phai dánh chính giua luoi bàn co
-Neu ton tai dúng 5 con liên tiep trên 1 hàng là thang(chéo,ngang,doc)
-Neu het cho di thì 2 bên hòa
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


