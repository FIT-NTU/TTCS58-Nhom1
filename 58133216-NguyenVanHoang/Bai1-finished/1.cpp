#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

// define
int mo; // menu option
string s = "";
string t; // trim string
string p; // proper string
char rtnmenu; // return to the menu
int count; // count different characters

void showMenu();
void menuOption();
void writeToInputFile(string s);
void writeToOutputFile();
void enterString();
string trim(string s);
string capitalize(string s);
int statistical(string s);
bool returnToMenu();


int main() {
    showMenu();
    menuOption();
}

void showMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t1. Enter string and save to input file" << endl;
    cout << "\t\t\t\t2. Trim string" << endl;
    cout << "\t\t\t\t3. Proper string" << endl;
    cout << "\t\t\t\t4. Statistical letter" << endl;
    cout << "\t\t\t\t5. Save string to output file" << endl;
    cout << "\t\t\t\t6. Exit" << endl;
}

void menuOption() {
    cout << "\t\t\t\t  Enter your choice:> "; cin >> mo;

    switch(mo) {
        case 1:
            system("cls");
            enterString();
            if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 2:
            system("cls");
            if(s == "") {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is null!" << endl;
                menuOption();
            } else {
                t = trim(s);
                cout << "[] to mark the string, not in the string" << endl;
                cout << "Trim string :> [" << t << "]" << endl;
                writeToInputFile(p);
                if(returnToMenu()) {
                    system("cls");
                    showMenu();
                    menuOption();
                } else {
                    cout << "Exited" << endl;
                }
            }
            break;
        case 3:
            system("cls");
            if(s == "") {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is null!" << endl;
                menuOption();
            } else {
                p = capitalize(s);
                cout << "Proper string :> " << p << endl;
                writeToInputFile(s);
                if(returnToMenu()) {
                    system("cls");
                    showMenu();
                    menuOption();
                } else {
                    cout << "Exited" << endl;
                }
            }
            break;
        case 4:
            system("cls");
            if(s == "") {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is null!" << endl;
                menuOption();
            } else {
                count = statistical(s);
                if(returnToMenu()) {
                    system("cls");
                    showMenu();
                    menuOption();
                } else {
                    cout << "Exited" << endl;
                }
            }
            break;
        case 5:
            system("cls");
            if(s == "") {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is null!" << endl;
                menuOption();
            } else {
                t = trim(s);
                cout << "[] to mark the string, not in the string" << endl;
                cout << "Trim string :> [" << t << "]" << endl;
                p = capitalize(s);
                cout << "Proper string :> " << p << endl;
                count = statistical(s);
                writeToOutputFile();
                if(returnToMenu()) {
                    system("cls");
                    showMenu();
                    menuOption();
                } else {
                    cout << "Exited" << endl;
                }
            }
            break;
        case 6:
            cout << "\t\t\t\t  Exited" << endl;
            break;
        default:
            system("cls");
            showMenu();
            cout << "\t\t\t\t  Wrong Option!" << endl;
            menuOption();
    }
}

void enterString() {
    fflush(stdin);
    cout << "Enter a string: "; getline(cin, s);
    cout << "Your string: " << s << endl;
    writeToInputFile(s);
}

void writeToInputFile(string s) {
    ofstream myfile;
    myfile.open("input1.txt");
    myfile << s;
    myfile.close();
    cout << "\nWrited to input1.txt\n\n";
}

void writeToOutputFile() {
    fstream myfile;
    myfile.open("output1.txt", ios::app);

    myfile << "======================" << endl;
    myfile << "Trim string: " << t << endl;
    myfile << "Proper string: " << p << endl;
    myfile << "Have " << count << " different characters" << endl;

    myfile.close();
    cout << "\nSaved to output1.txt\n\n";
}

string trim(string s) {
    
    int n = s.length();
    int m = n;
    char char_arr[n + 1];

    strcpy(char_arr, s.c_str());

    // remove left space
    while(char_arr[0] == ' ') {
        for(int i = 0; i < n - 1; i++) {
            char_arr[i] = char_arr[i + 1];
        }
        n--;
    }

    // remove right space
    while(char_arr[n - 1] == ' ') {
        n--;
    }

    // remove space between words
    for(int i = 0; i < n - 1; i++) {
        if(char_arr[i] == ' ' && char_arr[i + 1] == ' ') {
            for(int j = i; j < n - 1; j++) {
                char_arr[j] = char_arr[j + 1];
            }
            n--;
            i--;
        }
    }

    s = char_arr;
    return s.substr(0, s.size() - m + n);
}

string capitalize(string s) {

    int n = s.length();
    char char_arr[n + 1];

    strcpy(char_arr, s.c_str());

    if(isalpha(char_arr[0])) {
        char_arr[0] = toupper(char_arr[0]);
    }
    for(int i = 0; i < n; i++) {
        if(char_arr[i] == ' ' && isalpha(char_arr[i + 1]))
            char_arr[i + 1] = toupper(char_arr[i + 1]);
    }
    s = char_arr;
    return s;
}

int statistical(string s) {
    
    int n = s.length();
    count = 0;

    for(int i = 0; i < n; i++) {
        if(isalpha(s[i])) {
            count++;
        }
    }
    if(count) {
        cout << "Have " << count << " characters" << endl;
    } else {
        cout << "Dont have characters" << endl;
    }
    return count;
}
bool returnToMenu() {
    cout << "Enter H to return to the menu:> "; cin >> rtnmenu;
    if(rtnmenu == 'h' || rtnmenu == 'H') {
        return true;
    } return false;
}
