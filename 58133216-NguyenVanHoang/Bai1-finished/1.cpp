#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

// define
int option;
string s;
string t;
string c;
int count;
char rtnmenu;

void showMenu();
void menuOption();
void enterString();
string trim(string s);
string capitalize(string s);
int statistical(string s);
void writeToInputFile();
void writeToOutputFile();
bool returnMenu();

int main() {
    showMenu();
    menuOption();
}

void showMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t1. Enter a string and save to input file" << endl;
    cout << "\t\t\t\t2. Trim string" << endl;
    cout << "\t\t\t\t3. Proper string" << endl;
    cout << "\t\t\t\t4. Statistical" << endl;
    cout << "\t\t\t\t5. Save to output file" << endl;
    cout << "\t\t\t\t6. Exit" << endl;
}
void menuOption() {
    cout << "\t\t\t\t  Enter your choice: "; cin >> option;

    switch(option) {
        case 1:
            system("cls");
            enterString();
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            }
            break;
        case 2:
            if(!s.empty()) {
                system("cls");
                t = trim(s);
                cout << "Trim string: " << t << endl;
            } else {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is empty" << endl;
                menuOption();
            }
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            }
            break;
        case 3:
            if(!s.empty()) {
                system("cls");
                if(!t.empty()) c = capitalize(t);
                else c = capitalize(s);
                cout << "Proper string: " << c << endl;
            } else {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is empty" << endl;
                menuOption();
            }
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            }
            break;
        case 4:
            if(!s.empty()) {
                system("cls");
                count = statistical(s);
            } else {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is empty" << endl;
                menuOption();
            }
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            }
            break;
        case 5:
            if(!s.empty()) {
                system("cls");
                cout << "Your string: " << s << endl;
                if(!t.empty()) {
                    cout << "Trim string: " << t << endl;
                }
                if(!c.empty()) {
                    cout << "Proper string: " << c << endl;
                }
                writeToOutputFile();
            } else {
                system("cls");
                showMenu();
                cout << "\t\t\t\t  String is empty" << endl;
                menuOption();
            }
            if(returnMenu()) {
                system("cls");
                showMenu();
                menuOption();
            }
            break;
        case 6:
            cout << "\t\t\t\t  Exited";
            break;
        default:
            system("cls");
            showMenu();
            cout << "\t\t\t\t  Wrong option!" << endl;
            menuOption();
    }
}
void enterString() {
    cout << "Enter a string: ";
    fflush(stdin); getline(cin, s);

    cout << "Your string: " << s << endl;

    writeToInputFile();
}
string trim(string s) {
    int n = s.length();
    char char_arr[n + 1];

    strcpy(char_arr, s.c_str());

    // remove space between words
    for(int i = 0; i < n - 1; i++) {
        if(char_arr[i] == ' ' && char_arr[i + 1] == ' ') {
            for(int j = i; j < n; j++) {
                char_arr[j] = char_arr[j + 1];
            }
            n--; i--;
        }
    }
    // remove left space
    if(char_arr[0] == ' ') {
        for(int i = 0; i < n; i++) {
            char_arr[i] = char_arr[i + 1];
        }
        n--;
    }
    // remove right space
    if(char_arr[n - 1] == ' ') n--;

    s = char_arr;
    cout << s << endl;
    return s.substr(0, n);
}
string capitalize(string s) {
    int n = s.length();
    char char_arr[n + 1];

    strcpy(char_arr, s.c_str());

    if(isalpha(char_arr[0]))
        char_arr[0] = toupper(char_arr[0]);

    for(int i = 1; i < n; i++) {
        if(char_arr[i] == ' ' && isalpha(char_arr[i + 1])) {
            char_arr[i + 1] = toupper(char_arr[i + 1]);
        } else {
            char_arr[i + 1] = tolower(char_arr[i + 1]);
        }
    }

    s = char_arr;
    return s;
}
int statistical(string s) {
    int n = s.length();

    count = 0;
    for(int i = 0; i < n; i++) {
        if(isalpha(s[i])) count++;
    }

    if(count) {
        cout << "Have " << count << " characters" << endl;
    } else {
        cout << "Dont have character" << endl;
    }

    return count;
}
void writeToInputFile() {
    ofstream myfile;
    myfile.open("input1.txt");
    myfile << s;
    myfile.close();
    cout << "Writed to file!" << endl;
}
void writeToOutputFile() {
    ofstream myfile;
    myfile.open("output1.txt");
    myfile << s << endl;
    myfile << t << endl;
    myfile << c << endl;
    myfile << count << endl;
    myfile.close();
    cout << "Writed to file!" << endl;
}
bool returnMenu() {
    cout << "Enter H to return to the menu:> "; cin >> rtnmenu;
    if(rtnmenu == 'h' || rtnmenu == 'H') {
        return true;
    } return false;
}