#include "console1.h"
#include <iostream>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
char tem[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',};
int checkwin();
void board();

int main()
{
	int player = 1,i,choice;

	char mark;
	do
	{
		board();
		player=(player%2)?1:2;

		cout << " Player " << player << ", nhap vi tri ban muon di:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')
			{
				square[1] = mark;
				tem[1]=mark;
			}
			
		else if (choice == 2 && square[2] == '2')
			{
				square[2] = mark;
				tem[2]=mark;
			}	
		else if (choice == 3 && square[3] == '3')
			{
				square[3] = mark;
				tem[3]=mark;
			}		
		else if (choice == 4 && square[4] == '4')
			{
				square[4] = mark;
				tem[4]=mark;
			}			
		else if (choice == 5 && square[5] == '5')
			{
				square[5] = mark;
				tem[5]=mark;
			}	
		else if (choice == 6 && square[6] == '6')
			{
				square[6] = mark;
				tem[6]=mark;
			}	
		else if (choice == 7 && square[7] == '7')
			{
				square[7] = mark;
				tem[7]=mark;
			}	
		else if (choice == 8 && square[8] == '8')
			{
				square[8] = mark;
				tem[8]=mark;
			}	
		else if (choice == 9 && square[9] == '9')
			{
				square[9] = mark;
				tem[9]=mark;
			}	
		else
		{
			TextColor(12);
			cout<<" Vi tri ban chon da choi hoac khong co trong ban choi\n Nhan Enter de nhap lai";
			TextColor(3);
			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin(); 

		player++;
	}while(i==-1);
	board();
	if(i==1)
	{
		TextColor(12);
		cout<<"==>\aPlayer "<<--player<<" win ";
	}
		
	else
	{	
		TextColor(12);
		cout<<"==>\aHoa";
	}
	

	cin.ignore();
	cin.get();
	return 0;
}


// tra ve 1 la win
//tra ve -1 la chua co nguoi win va van con o trong de di
//tra ve 0 la het o de di va chua ai than : Hoa;
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}



//thong tin va huong dan choi

void board()
{
	system("cls");
	cout<<"Le Tuan Tai"<<endl;
	cout<<"58131379"<<endl<<endl<<endl;
	TextColor(14);
	cout <<"     TIC TAC TOE"<<endl;
	cout <<"         ===    "<<endl;
	cout <<"      ========="<<endl<<endl<<endl;
	



//bang vi tri
 	TextColor(10);
 	cout<<"BANG VI TRI CAC NUOC DI:"<<endl<<"======================="<<endl;
 	TextColor(15);
	cout << "     |     |     " << endl;
	cout << "  " << "1" << "  |  " << "2" << "  |  " << "3" << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << "4" << "  |  " << "5" << "  |  " << "6"<< endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << "7" << "  |  " << "8" << "  |  " << "9" << endl;

	cout << "     |     |     " << endl << endl<<endl;
	TextColor(10);
	cout<<"HUONG DAN:"<<endl<<"=========="<<endl;
	TextColor(3);
	cout<<"Co 2 player, moi nguoi se duoc tuong trung bang X hoac O, "<<endl;
	cout<<"lan luot moi nguoi choi se nhap vi tri muon di cho den khi "<<endl;
	cout<<"co 3 dau X (hoac O) nam tren cung 1 duong thang thi player"<<endl;
	cout<<"se thang, hoac het o  ma khong co 3 dau nao thang hang "<<endl;
	cout<<"khi do 2 player hoa nhau."<<endl<<endl;
	cout<<endl<<endl;
	

//bang choi
	TextColor(14);
	cout<<"Let's play !!!"<<endl<<endl;
	TextColor(3);
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	TextColor(15);
	cout << "     |     |     " << endl;
	cout << "  " << tem[1] << "  |  " << tem[2] << "  |  " << tem[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << tem[4] << "  |  " << tem[5] << "  |  " << tem[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << tem[7] << "  |  " << tem[8] << "  |  " << tem[9] << endl;

	cout << "     |     |     " << endl << endl;
	TextColor(3);
}

/*******************************************************************
				END OF PROJECT
********************************************************************/
