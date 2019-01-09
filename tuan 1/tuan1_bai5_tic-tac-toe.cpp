// code by Nguyen Van Hoang 58131303.
#include <iostream>
using namespace std;

char square[3][3]=
{
	{' ',' ',' '}, //hang 1
	{' ',' ',' '}, // hang 2
	{' ',' ',' '}  // hang 3
};
int player, n;
int checkwin();
void board();
// ham menu dung cho int main() va ham board()
void menu()
{
	cout << "Code by Hoang Toni...!" << endl;
	cout << "--------MENU--------" << endl;
	cout << "1 : Play with X" << endl;
	cout << "2 : Play with O" << endl;
	cout << "3 : Exit" << endl;
	cout << "Enter your choice:> ";
}

int main()
{
	int i,choice;
	char mark;
	menu();
	// lua chon nguoi di truoc
	cin >> n;
	player = n; // gan player bang n vi player se thay doi con n thi khong.
				// neu gan n = player thi gia tri n se bi thay doi theo player.
				// Nhu vay cho 'Ennter your choice' se bi sai.
	do
	{
		board();
		player=(player%2)?1:2; // neu chia cho 2 ma du la player 1 danh truoc. va nguoc lai thi player 2 danh truoc.

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;
		
		mark=(player == 1) ? 'X' : 'O';
		
		// nhap so tren ban phim de dien vao mang 2 chieu.
		if (choice == 1 && square[0][0] == ' ')
			square[0][0] = mark;
			
		else if (choice == 2 && square[0][1] == ' ')
			square[0][1] = mark;
			
		else if (choice == 3 && square[0][2] == ' ')
			square[0][2] = mark;
			
		else if (choice == 4 && square[1][0] == ' ')
			square[1][0] = mark;
			
		else if (choice == 5 && square[1][1] == ' ')
			square[1][1] = mark;
			
		else if (choice == 6 && square[1][2] == ' ')
			square[1][2] = mark;
			
		else if (choice == 7 && square[2][0] == ' ')
			square[2][0] = mark;
	
		else if (choice == 8 && square[2][1] == ' ')
			square[2][1] = mark;
			
		else if (choice == 9 && square[2][2] == ' ')
			square[2][2] = mark;
			
		else
		{
			cout<<"Invalid move "; // tra ve cau lenh nay khi nhap sai gia tri
			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();

		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win "; // nguoi choi win
	else
		cout<<"==>\aGame draw"; // 2 player se hoa nhau vi da danh het so o tren ban co.
	cin.ignore();
	cin.get();
	return 0;
}

// ham kiem tra dieu kien de win
int checkwin()
{
	if (square[0][0] == square[0][1] && square[0][1] == square[0][2] && square[0][0] != ' ')

		return 1;
	else if (square[1][0] == square[1][1] && square[1][1] == square[1][2] && square[1][0] != ' ')

		return 1;
	else if (square[2][0] == square[2][1] && square[2][1] == square[2][2] && square[2][0] != ' ')

		return 1;
	else if (square[0][0] == square[1][0] && square[1][0] == square[2][0] && square[0][0] != ' ')

		return 1;
	else if (square[0][1] == square[1][1] && square[1][1] == square[2][1] && square[0][1] != ' ')

		return 1;
	else if (square[0][2] == square[1][2] && square[1][2] == square[2][2] && square[0][2] != ' ')

		return 1;
	else if (square[0][0]== square[1][1] && square[1][1] == square[2][2] && square[0][0] != ' ')

		return 1;
	else if (square[0][2] == square[1][1] && square[1][1] == square[2][0] && square[0][2] != ' ')

		return 1;
	else if (square[0][0] != ' ' && square[0][1] != ' ' && square[0][2] != ' ' 
                    && square[1][0] != ' ' && square[1][1] != ' ' && square[1][2] != ' ' 
                  && square[2][0] != ' ' && square[2][1] != ' ' && square[2][2] != ' ')

		return 0;
	else
		return -1;
}

// bang hien thi ban co va menu
void board()
{
	system("cls");
	menu();
	cout << n << endl;
	
	cout << "\t\t     |     |     " << endl;
	cout << "\t\t  " << square[0][0] << "  |  " << square[0][1] << "  |  " << square[0][2] << endl;

	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;

	cout << "\t\t  " << square[1][0] << "  |  " << square[1][1] << "  |  " << square[1][2] << endl;

	cout << "\t\t_____|_____|_____" << endl;
	cout << "\t\t     |     |     " << endl;

	cout << "\t\t  " << square[2][0] << "  |  " << square[2][1] << "  |  " << square[2][2] << endl;

	cout << "\t\t     |     |     " << endl << endl;
}
