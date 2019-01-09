#include <iostream>
using namespace std;

int n, player; //bien n de lua chon menu, player de xac dinh nguoi choi 1 hay 2
int dem=0; //dem so luot choi
char a[10] = {'o','1','2','3','4','5','6','7','8','9'}; //mang a luu cac gia tri so tren ban co

int kiemtra() //dieu kien ket thuc game:3 o lien tiep theo chieu ngang, doc, cheo
{
	if (a[1] == a[2] && a[2] == a[3])  	   //hang ngang

		return 1;
	else if (a[4] == a[5] && a[5] == a[6])

		return 1;
	else if (a[7] == a[8] && a[8] == a[9])

		return 1;
	else if (a[1] == a[4] && a[4] == a[7]) //hang doc

		return 1;
	else if (a[2] == a[5] && a[5] == a[8])

		return 1;
	else if (a[3] == a[6] && a[6] == a[9])

		return 1;
	else if (a[1] == a[5] && a[5] == a[9]) //hang cheo

		return 1;
	else if (a[3] == a[5] && a[5] == a[7])

		return 1;
	else if (a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' 
				&& a[7] != '7' && a[8] != '8' && a[9] != '9')

		return 0;
	else
		return -1; //di xong 1 o thi den nguoi khac di
}
void menu() //ham menu
{
	cout<< "--------MENU--------"<<endl;
	cout<<"1.Choi voi X"<<endl;
	cout<<"2.Choi voi O"<<endl;
	cout<<"3.Thoat"<<endl;
	cout<<"Moi ban chon: "<<endl;
}
void inmanhinh() //ve khung
{
	system("cls"); //xoa man hinh
	//in ra ban co
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout <<"\t\t\t\t\t"<< "     |     |     " << endl;
	cout <<"\t\t\t\t\t"<< "  " << a[1] << "  |  " << a[2] << "  |  " << a[3] << endl;

	cout <<"\t\t\t\t\t"<< "_____|_____|_____" << endl;
	cout <<"\t\t\t\t\t"<< "     |     |     " << endl;

	cout <<"\t\t\t\t\t"<< "  " << a[4] << "  |  " << a[5] << "  |  " << a[6] << endl;

	cout <<"\t\t\t\t\t"<< "_____|_____|_____" << endl;
	cout <<"\t\t\t\t\t"<< "     |     |     " << endl;
	
	cout <<"\t\t\t\t\t"<< "  " << a[7] << "  |  " << a[8] << "  |  " << a[9] << endl;

	cout <<"\t\t\t\t\t"<< "     |     |     " << endl << endl; 
	cout<<"Luot choi thu:"<<dem<<endl;
}

int main()
{
	int i;
	int k;  //bien lua chon
	char mark;
	menu();
	cin>>n;
	if(n==1 || n==2) //neu n=1 thi nguoi thu nhat choi, n=2 thi nguoi thu 2 choi
		player=n;
	else exit(n); //neu n khac 1 va khac 2 thi se ket thuc chuong trinh.
	do
	{
		inmanhinh();
		if(player%2) //neu player bang 1 thi nguoi thu nhat di
			player=1;
		else
			player=2;	
		cout << "Nguoi choi " << player << " " << "chon so:  ";
		cin >> k;
		if (mark=(player == 1))
			mark='X';
		else 
			mark='O';	
		if (k == 1 && a[1] == '1') //neu bam phim 1 thi danh vao o so 1

			a[1] = mark;
		else if (k == 2 && a[2] == '2')

			a[2] = mark;
		else if (k == 3 && a[3] == '3')

			a[3] = mark;
		else if (k == 4 && a[4] == '4')

			a[4] = mark;
		else if (k == 5 && a[5] == '5')

			a[5] = mark;
		else if (k == 6 && a[6] == '6')

			a[6] = mark;
		else if (k == 7 && a[7] == '7')

			a[7] = mark;
		else if (k == 8 && a[8] == '8')

			a[8] = mark;
		else if (k == 9 && a[9] == '9')

			a[9] = mark;
		else
		{
			cout<<"Khong the danh vao o da danh";
			player--; //danh lai
			cin.ignore(); 
			cin.get(); //dung man hinh
		}
		i=kiemtra();
		player++; //nguoi tiep theo se di
		dem++;
	}while(i==-1);  //i khac -1 se dung lai
	inmanhinh();
	if(i==1) //in ket qua nguoi chien thang
		cout<<"==>\aNguoi choi "<<--player<<" chien thang "<<endl;
	else
		cout<<"Game ket thuc!"<<endl;
	system("pause");
}



