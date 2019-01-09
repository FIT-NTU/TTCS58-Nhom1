#include <iostream>
#include <math.h>
#define N 4
using namespace std;

struct Node {
    int x;
    int y;
    int value;
    struct Node *next;
};

int r = 0, c = 0, size = 0;
Node *list;
int option;

void init() {
    list = NULL;
}
Node *createNode(int x, int y, int value) {
    Node *p = new Node;
    p->x = x;
    p->y = y;
    p->value = value;
    p->next = NULL;
    return p;
}
void addNode(Node *p) {
    if(list == NULL) {
        list = p;
        p->next = NULL;
    } else {
        Node *last = list;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void showMenu();
void menuOption();
void createMatrix();
void showMatrix();
void multiplicationWithANumber();
void invertibleMatrix();
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n);
int determinantOfMatrix(int mat[N][N], int n);
void returnMenu();

int main() {
    showMenu();
    menuOption();
}

void showMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t1. Create matrix" << endl;
    cout << "\t\t\t\t2. Show matrix" << endl;
    cout << "\t\t\t\t3. Multiplication with a number" << endl;
    cout << "\t\t\t\t4. Invertible matrix" << endl;
    cout << "\t\t\t\t5. Determinant" << endl;
    cout << "\t\t\t\t6. Operations with matrix" << endl;
    cout << "\t\t\t\t7. Exit" << endl;
}
void menuOption() {
    cout << "\t\t\t\t  Enter your choice: "; cin >> option;

    switch(option) {
        case 1:
            system("cls");
            createMatrix();
            returnMenu();
            break;
        case 2:
            system("cls");
            showMatrix();
            returnMenu();
            break;
        case 3:
            system("cls");
            multiplicationWithANumber();
            cout << "Matrix: " << endl;
            showMatrix();
            returnMenu();
            break;
        case 4:
        case 5:
        case 6:
            system("cls");
            cout << "Chuc nang chua hoan thanh" << endl;
            returnMenu();
            break;
        case 7:
            cout << "\t\t\t\t  Exited" << endl;
            break;
        default:
            system("cls");
            showMenu();
            cout << "\t\t\t\t  Wrong option!" << endl;
            menuOption();
    }
}
void createMatrix() {
    init();
    cout << "Enter size of matrix" << endl;
    cout << "Row: "; cin >> r;
    cout << "Column: "; cin >> c;
    size = r * c;

    // Input
    int tmp;
    int count = size / 2;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << "A[" << i << "][" << j << "]= "; cin >> tmp;
            if(tmp) {
                Node *p = createNode(i, j, tmp);
                addNode(p);
                count--;
            }
            // if(count == 0) {
            //     cout << "Matrix is full" << endl;
            //     break;
            // }
        }
        // if(count == 0) {
        //     break;
        // }
    }
}
void showMatrix() {
    if(list != NULL) {
        int arr[r][c];

        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                arr[i][j] = 0;

        Node *p = list;
        while(p != NULL) {
            arr[p->x][p->y] = p->value;
            p = p->next;
        }
        
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cout << arr[i][j] << "\t";
            } cout << endl;
        }
    } else {
        cout << "Dont have matrix" << endl;
    }
}
void multiplicationWithANumber() {
    if(list != NULL) {
        int num;
        do {
            cout << "Enter a number (!= 0): "; cin >> num;
        } while(num == 0);

        Node *p = list;
        while(p != NULL) {
            p->value *= num;
            p = p->next;
        }
    } else {
        cout << "Dont have matrix" << endl;
    }
}
// void invertibleMatrix() {
//     int arr[4][4];

//     Node *p = list;
//     while(p != NULL) {
//         arr[p->x][p->y] = p->value;
//         p = p->next;
//     }
//     for(int i = 1; i <= r; i++) {
//         for(int j = 1; j <= c; j++) {
//             cout << arr[i][j] << "\t";
//         } cout << endl;
//     }
//     // int d = determinantOfMatrix(arr, r);
//     // cout << d << endl;
//     // if(d) {
//     //     int** newArr;
//     //     // chuyển vị
//     //     for(int i = 1; i <= c; i++) {
//     //         for(int j = 1; j <= r; j++) {
//     //             newArr[i][j] = arr[j][i];
//     //         }
//     //     }
//     //     // phụ hợp
//     //     int** newArr2;
//     //     for(int i = 1; i <= c; i++) {
//     //         for(int j = 1; j <= r; j++) {
//     //             newArr2[i][j] = newArr[c - i - 1][r - j - 1];
//     //         }
//     //     }
//     //     // nghịch đảo
//     //     cout << "Matrix: " << endl;
//     //     for(int i = 1; i <= r; i++) {
//     //         for(int j = 1; j <= c; j++) {
//     //             newArr2[i][j] *= float(1) / d;
//     //             cout << newArr2[i][j] << "\t";
//     //         } cout << endl;
//     //     }
//     // } else {
//     //     cout << "Dont have inverse matrix" << endl;
//     // }
// }
// void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) { 
//     int i = 0, j = 0; 
  
//     // Looping for each element of the matrix 
//     for (int row = 0; row < n; row++) {
//         for (int col = 0; col < n; col++) {
//             //  Copying into temporary matrix only those element 
//             //  which are not in given row and column 
//             if (row != p && col != q) {
//                 temp[i][j++] = mat[row][col]; 
  
//                 // Row is filled, so increase row index and 
//                 // reset col index 
//                 if (j == n - 1) 
//                 { 
//                     j = 0; 
//                     i++; 
//                 } 
//             } 
//         } 
//     } 
// } 
// int determinantOfMatrix(int mat[N][N], int n) { 
//     int D = 0; // Initialize result 
  
//     //  Base case : if matrix contains single element 
//     if (n == 1) 
//         return mat[0][0]; 
  
//     int temp[N][N]; // To store cofactors 
  
//     int sign = 1;  // To store sign multiplier 
  
//      // Iterate for each element of first row 
//     for (int f = 0; f < n; f++) {
//         // Getting Cofactor of mat[0][f] 
//         getCofactor(mat, temp, 0, f, n); 
//         D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 
  
//         // terms are to be added with alternate sign 
//         sign = -sign; 
//     }
//     return D; 
// }
void returnMenu() {
    system("pause");
    system("cls");
    showMenu();
    menuOption();
}
