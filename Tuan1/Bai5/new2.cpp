#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

//define
char data[11][11];
int option = 1;
int x, y, m, n, i;
char key;

void start();
void setData();
void changeColorMenu();
void controlMenu();
void playGame();
void guide();
void exit();
void drawBoard();
void goTo(int x, int y);
void textColor(int col);
void gameInfo();
void cursor(int x, int y);
void control();
void markXO(int x, int y);
bool winX();
bool winO();
void checkWin();
void toLeft();
void toRight();
void toUp();
void toDown();
void rePlay();

int main() {
    start();
}
/*
    Bat dau chuong trinh
*/
void start() {
    changeColorMenu();
    while(getch() != 13) {
        controlMenu();
    }
    switch(option) {
        case 1:
            setData();
            playGame();
            break;
        case 2:
            guide();
            break;
        case 3:
            exit();
            break;
    }
}
/*
    Khoi tao du lieu tro choi
*/
void setData() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            data[i][j] = ' ';
        }
    }
}
/*
    Doi mau chu menu theo option
*/
void changeColorMenu() {
    system("cls");
    cout << "\n\n";
    if(option == 1) {
        textColor(12);
        cout << "\t\t\t\tPlay game" << endl;
        textColor(11);
        cout << "\t\t\t\tGuide" << endl;
        cout << "\t\t\t\tExit" << endl;

    } else if(option == 2) {
        cout << "\t\t\t\tPlay game" << endl;
        textColor(12);
        cout << "\t\t\t\tGuide" << endl;
        textColor(11);
        cout << "\t\t\t\tExit" << endl;
    } else if(option == 3) {
        cout << "\t\t\t\tPlay game" << endl;
        cout << "\t\t\t\tGuide" << endl;
        textColor(12);
        cout << "\t\t\t\tExit" << endl;
        textColor(11);
    }
    goTo(0, 0);
}
/*
    Thao tac tren menu
*/
void controlMenu() {
    key = getch();
    if((int)key == 72) {
        option--;
        if(option == 0) option = 3;
    } else if((int)key == 80) {
        option++;
        if(option == 4) option = 1;
    }
    changeColorMenu();
}
/*
    Ve khung
*/
void drawBoard() {
    system("cls");
    // top
    goTo(12, 2);
    for(int i = 0; i <= 10; i++) {
        // 11 sao
        cout << "* ";
        Sleep(3);
    }
    // left
    goTo(12, 3);
    for(int i = 0; i <= 10; i++) {
        // 11 sao
        cout << "*";
        goTo(12, 4 + i);
        Sleep(3);
    }
    // bottom
    goTo(14, 13);
    for(int i = 0; i <= 10; i++) {
        // 11 sao
        cout << "* ";
        Sleep(3);
    }
    // right
    goTo(34, 2);
    for(int i = 0; i <= 10; i++) {
        // 11 sao
        cout << "*";
        goTo(34, 3 + i);
        Sleep(3);
    }
}
/*
    Hien thi thong tin tran dau
*/
void gameInfo() {
    goTo(12, 0);
    cout << "Toa do: " << (x - 12) / 2 << " - " << y - 2 << "    M: Danh dau." << endl;
    goTo(12, 1);
    cout << "Q: Thoat." << "\t     Luot: " << i;
}
/*
    Hien thi con tro
*/
void cursor(int x, int y) {
    goTo(x, y);
}
/*
    Choi game
*/
void playGame() {
    textColor(7);
    drawBoard();
    x = 14, y = 3;
    i = 0;
    do {
        gameInfo();
        cursor(x, y);
        checkWin();
        control();
    } while(toupper(key) != 'Q');
    exit();
}
/*
    Doi mau chu
*/
void textColor(int col) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}
/*
    Di chuyen con tro
*/
void goTo(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
    Tuong tac phim
*/
void control() {
    key = getch();

    if((int)key == 72) toUp();
    else if((int)key == 80) toDown();
    else if((int)key == 75) toLeft();
    else if((int)key == 77) toRight();
    else if(toupper(key) == 'M') markXO(x, y);
}
/*
    Luot cua ai
*/
char OX(int i) {
    if(i % 2) {
        return 'O';
    } return 'X';
}
/*
    Danh dau
*/
void markXO(int x, int y) {
    m = (x - 12) / 2 - 1;
    n = y - 2 - 1;

    if(data[m][n] == ' ') {
        if(i % 2) textColor(11);
        else textColor(12);
        data[m][n] = OX(i);
        i++;
        cout << data[m][n];
        textColor(7);
    }
}
/*
    X chien thang
*/
bool winX() {
    int m1, n1;

    // Win by row
    m1 = m;
    while(data[m1][n] == 'X') m1--;
    m1++;
    if( data[m1][n] == 'X' &&
        data[m1 + 1][n] == 'X' &&
        data[m1 + 2][n] == 'X' &&
        data[m1 + 3][n] == 'X' &&
        data[m1 + 4][n] == 'X' &&
        (data[m1 - 1][n] != 'O' || data[m1 + 5][n] != 'O')) return true;
    // Win by col
    n1 = n;
    while(data[m][n1] == 'X') n1--;
    n1++;
    if( data[m][n1] == 'X' &&
        data[m][n1 + 1] == 'X' &&
        data[m][n1 + 2] == 'X' &&
        data[m][n1 + 3] == 'X' &&
        data[m][n1 + 4] == 'X' &&
        (data[m][n1 - 1] != 'O' || data[m][n1 + 5] != 'O')) return true;
    // Win by main diagonal
    m1 = m; n1 = n;
    while(data[m1][n1] == 'X') {
        m1--;
        n1--;
    }
    m1++; n1++;
    if( data[m1][n1] == 'X' &&
        data[m1 + 1][n1 + 1] == 'X' &&
        data[m1 + 2][n1 + 2] == 'X' &&
        data[m1 + 3][n1 + 3] == 'X' &&
        data[m1 + 4][n1 + 4] == 'X' &&
        (data[m1 - 1][n1 - 1] != 'O' || data[m1 + 5][n1 + 5] != 'O')) return true;
    // Win by extra diagonal
    m1 = m; n1 = n;
    while(data[m1][n1] == 'X') {
        m1--;
        n1++;
    }
    m1++; n1--;
    if( data[m1][n1] == 'X' &&
        data[m1 + 1][n1 - 1] == 'X' &&
        data[m1 + 2][n1 - 2] == 'X' &&
        data[m1 + 3][n1 - 3] == 'X' &&
        data[m1 + 4][n1 - 4] == 'X' &&
        (data[m1 - 1][n1 + 1] != 'O' || data[m1 + 5][n1 - 5] != 'O')) return true;
    return 0;
}
/*
    O chien thang
*/
bool winO() {
    int m1, n1;

    // Win by row
    m1 = m;
    while(data[m1][n] == 'O') m1--;
    m1++;
    if( data[m1][n] == 'O' &&
        data[m1 + 1][n] == 'O' &&
        data[m1 + 2][n] == 'O' &&
        data[m1 + 3][n] == 'O' &&
        data[m1 + 4][n] == 'O' &&
        (data[m1 - 1][n] != 'X' || data[m1 + 5][n] != 'X')) return true;
    // Win by col
    n1 = n;
    while(data[m][n1] == 'O') n1--;
    n1++;
    if( data[m][n1] == 'O' &&
        data[m][n1 + 1] == 'O' &&
        data[m][n1 + 2] == 'O' &&
        data[m][n1 + 3] == 'O' &&
        data[m][n1 + 4] == 'O' &&
        (data[m][n1 - 1] != 'X' || data[m][n1 + 5] != 'X')) return true;
    // Win by main diagonal
    m1 = m; n1 = n;
    while(data[m1][n1] == 'O') {
        m1--;
        n1--;
    }
    m1++; n1++;
    if( data[m1][n1] == 'O' &&
        data[m1 + 1][n1 + 1] == 'O' &&
        data[m1 + 2][n1 + 2] == 'O' &&
        data[m1 + 3][n1 + 3] == 'O' &&
        data[m1 + 4][n1 + 4] == 'O' &&
        (data[m1 - 1][n1 - 1] != 'X' || data[m1 + 5][n1 + 5] != 'X')) return true;
    // Win by extra diagonal
    m1 = m; n1 = n;
    while(data[m1][n1] == 'O') {
        m1--;
        n1++;
    }
    m1++; n1--;
    if( data[m1][n1] == 'O' &&
        data[m1 + 1][n1 - 1] == 'O' &&
        data[m1 + 2][n1 - 2] == 'O' &&
        data[m1 + 3][n1 - 3] == 'O' &&
        data[m1 + 4][n1 - 4] == 'O' &&
        (data[m1 - 1][n1 + 1] != 'X' || data[m1 + 5][n1 - 5] != 'X')) return true;
    return 0;
}
/*
    Xu ly khi co nguoi chien thang
*/
void checkWin() {
    if(winX()) {
        goTo(12, 14);
        cout << "X chien thang. Nhap R de choi lai. Nhan Q de thoat.";
        key = getch();
        if(toupper(key) == 'R') {
            rePlay();
        } else if(toupper(key) == 'Q') {
            exit();
        }
    } else if(winO()) {
        goTo(12, 14);
        cout << "O chien thang. Nhap R de choi lai. Nhan Q de thoat.";
        key = getch();
        if(toupper(key) == 'R') {
            rePlay();
        } else if(toupper(key) == 'Q') {
            exit();
        }
    }
    if(i == 100) {
        goTo(12, 14);
        cout << "Hoa. Nhap R de choi lai. Nhan Q de thoat.";
        key = getch();
        if(toupper(key) == 'R') {
            rePlay();
        } else if(toupper(key) == 'Q') {
            exit();
        }
    }
}
/*
    Di chuyen vi tri tren ban co
*/
void toLeft() {
    x -= 2;
    if(x < 14) x = 14;
}
void toRight() {
    x += 2;
    if(x > 32) x = 32;
}
void toUp() {
    y--;
    if(y < 3) y = 3;
}
void toDown() {
    y++;
    if(y > 12) y = 12;
}
/*
    Choi lai
*/
void rePlay() {
    system("cls");
    setData();
    playGame();
}
/*
    Huong dan choi game
*/
void guide() {
    system("cls");
    cout << "Su dung phim mui ten de di chuyen" << endl;
    cout << "Phim 'M' de danh dau vi tri" << endl;
    cout << "Phim 'Q' de thoat game" << endl;
    cout << "Phim 'R' de choi lai, tao tran moi" << endl;
    system("pause");
    start();
}
void exit() {
	goTo(12, 14);
    cout << "Tam biet, hen gap lai"; 
}
