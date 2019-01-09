#include <iostream>

using namespace std;

//define
// char data[3][3] = {
//     {'X', 'O', 'X'},
//     {'O', 'O', 'X'},
//     {'X', 'X', 'O'}
// };
char data[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
int option;
char player;
int c; // choice

void showMenu();
void menuOption();
void menuOptioned();
void drawBoard();
void playGame(int whoIs);
void choice();
void lastChoice();
void mark(int x, int y, char d[3][3]);
void changePlayer();
int checkWin();
void quit();

int main() {
    showMenu();
    menuOption();
}

// Hien thi menu
void showMenu() {
    system("clear");
    cout << "--------MENU--------" << endl;
    cout << "1 : Play with X" << endl;
    cout << "2 : Play with O" << endl;
    cout << "3 : Exit" << endl;
}
// Lua chon tren menu
void menuOption() {
    cout << "Enter your choice:> "; cin >> option;

    switch(option) {
        case 1:
            playGame(1);
            break;
        case 2:
            playGame(2);
            break;
        case 3:
            quit();
            break;
        default:
            showMenu();
            cout << "Wrong option!" << endl;
            menuOption();
    }
}
// Da lua chon
void menuOptioned() {
    cout << "Enter your choice:> " << option;
}
// Ve khung
void drawBoard() {
    cout << endl;
    cout << "\t\t\t\t       |       |       " << endl;
    cout << "\t\t\t\t   " << data[0][0] << "   |   " << data[0][1] << "   |   " << data[0][2] << "   " << endl;
    cout << "\t\t\t\t-----------------------" << endl;
    cout << "\t\t\t\t       |       |       " << endl;
    cout << "\t\t\t\t   " << data[1][0] << "   |   " << data[1][1] << "   |   " << data[1][2] << "   " << endl;
    cout << "\t\t\t\t-----------------------" << endl;
    cout << "\t\t\t\t       |       |       " << endl;
    cout << "\t\t\t\t   " << data[2][0] << "   |   " << data[2][1] << "   |   " << data[2][2] << "   " << endl;
}
// Choi game
void playGame(int whoIs) {
    if(whoIs == 1) {
        player = 'X';
    } else {
        player = 'O';
    }

    do {
        showMenu();
        menuOptioned();
        drawBoard();
        choice();
    } while(checkWin() == 0);

    showMenu();
    menuOptioned();
    drawBoard();
    lastChoice();
    switch(checkWin()) {
        case 1:
            cout << "\t\t\t\t  X chien thang" << endl;
            break;
        case 2:
            cout << "\t\t\t\t  O chien thang" << endl;
            break;
        case 3:
            cout << "\t\t\t\t  Game hoa" << endl;
            break;
    }
}
// Lua chon vi tri danh dau tren ban co
void choice() {   
    cout << "\t\t\t\t  Your turn: "; cin >> c;

    switch(c) {
        case 1:
            mark(0, 0, data);
            break;
        case 2:
            mark(0, 1, data);
            break;
        case 3:
            mark(0, 2, data);
            break;
        case 4:
            mark(1, 0, data);
            break;
        case 5:
            mark(1, 1, data);
            break;
        case 6:
            mark(1, 2, data);
            break;
        case 7:
            mark(2, 0, data);
            break;
        case 8:
            mark(2, 1, data);
            break;
        case 9:
            mark(2, 2, data);
            break;
        default:
            showMenu();
            menuOptioned();
            drawBoard();
            cout << "\t\t\t\t  Invalid move" << endl;
            choice();
    }
}
// Lua danh cuoi cung
void lastChoice() {
    cout << "\t\t\t\t  Your turn: " << c << endl;
}
// Danh dau XO
void mark(int x, int y, char d[3][3]) {
    if(d[x][y] != ' ') {
        showMenu();
        menuOptioned();
        drawBoard();
        cout << "\t\t\t\t  Invalid move" << endl;
        choice();
    } else {
        d[x][y] = player;
        changePlayer();
    }
}
// Doi nguoi choi
void changePlayer() {
    if(player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}
// Kiem tra chien thang
// 1 : X thang
// 2 : O thang
// 3 : Hoa
// 0 : Chua ket thuc
int checkWin() {
    if(
        (data[0][0] == data[0][1] && data[0][1] == data[0][2] && data[0][0] == 'X') ||
        (data[1][0] == data[1][1] && data[1][1] == data[1][2] && data[1][0] == 'X') ||
        (data[2][0] == data[2][1] && data[2][1] == data[2][2] && data[2][0] == 'X') ||
        (data[0][0] == data[1][0] && data[1][0] == data[2][0] && data[0][0] == 'X') ||
        (data[0][1] == data[1][1] && data[1][1] == data[2][1] && data[0][1] == 'X') ||
        (data[0][2] == data[1][2] && data[1][2] == data[2][2] && data[0][2] == 'X') ||
        (data[0][0] == data[1][1] && data[1][1] == data[2][2] && data[0][0] == 'X') ||
        (data[0][2] == data[1][1] && data[1][1] == data[2][0] && data[0][2] == 'X')
    ) return 1;
    if(
        (data[0][0] == data[0][1] && data[0][1] == data[0][2] && data[0][0] == 'O') ||
        (data[1][0] == data[1][1] && data[1][1] == data[1][2] && data[1][0] == 'O') ||
        (data[2][0] == data[2][1] && data[2][1] == data[2][2] && data[2][0] == 'O') ||
        (data[0][0] == data[1][0] && data[1][0] == data[2][0] && data[0][0] == 'O') ||
        (data[0][1] == data[1][1] && data[1][1] == data[2][1] && data[0][1] == 'O') ||
        (data[0][2] == data[1][2] && data[1][2] == data[2][2] && data[0][2] == 'O') ||
        (data[0][0] == data[1][1] && data[1][1] == data[2][2] && data[0][0] == 'O') ||
        (data[0][2] == data[1][1] && data[1][1] == data[2][0] && data[0][2] == 'O')
    ) return 2;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(data[i][j] == ' ')
                return 0;
        }
    }
    return 3;
}
// Thoat
void quit() {
    cout << "Tam biet, hen gap lai" << endl;
}