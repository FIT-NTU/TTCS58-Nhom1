#include <iostream>
using namespace std;

char mang[10] = {'o','1','2','3','4','5','6','7','8','9'};
int ng_choi = 1;
int i;
int select;
char mark;

int kiem_tra_thang();
void bang();
void play();
void ket_qua();

int main()
{
	play();
	ket_qua();
}

void play()
{
	do
	{
		bang();
		ng_choi = (ng_choi%2)?1:2;
		cout << "Luot cua nguoi choi " << ng_choi << ", moi nhap vao toa do can danh:  ";
		cin >> select;
		mark=(ng_choi == 1) ? 'X' : 'O';
		if (select == 1 && mang[1] == '1')
			mang[1] = mark;
		else if (select == 2 && mang[2] == '2')
			mang[2] = mark;
		else if (select == 3 && mang[3] == '3')
			mang[3] = mark;
		else if (select == 4 && mang[4] == '4')
			mang[4] = mark;
		else if (select == 5 && mang[5] == '5')
			mang[5] = mark;
		else if (select == 6 && mang[6] == '6')
			mang[6] = mark;
		else if (select == 7 && mang[7] == '7')
			mang[7] = mark;
		else if (select == 8 && mang[8] == '8')
			mang[8] = mark;
		else if (select == 9 && mang[9] == '9')
			mang[9] = mark;
		else
		{
			cout<<"Danh khong hop le!";
			ng_choi--;
			cin.ignore();
			cin.get();
		}
		i=kiem_tra_thang();
		ng_choi++;
	}
	while(i==-1);
	bang();
}

int kiem_tra_thang()
{
	if (mang[1] == mang[2] && mang[2] == mang[3])
		return 1;
	else if (mang[4] == mang[5] && mang[5] == mang[6])
		return 1;
	else if (mang[7] == mang[8] && mang[8] == mang[9])
		return 1;
	else if (mang[1] == mang[4] && mang[4] == mang[7])
		return 1;
	else if (mang[2] == mang[5] && mang[5] == mang[8])
		return 1;
	else if (mang[3] == mang[6] && mang[6] == mang[9])
		return 1;
	else if (mang[1] == mang[5] && mang[5] == mang[9])
		return 1;
	else if (mang[3] == mang[5] && mang[5] == mang[7])
		return 1;
	else if (mang[1] != '1' 
			&& mang[2] != '2' 
			&& mang[3] != '3' 
            && mang[4] != '4' 
			&& mang[5] != '5' 
			&& mang[6] != '6' 
            && mang[7] != '7' 
			&& mang[8] != '8' 
			&& mang[9] != '9')
		return 0;
	else
		return -1;
}

void bang()
{
	system("cls");
	cout << "Nguoi choi 1 danh X."<<endl;
	cout << "Nguoi choi 2 danh O."<<endl;
	cout <<	endl;
	cout << "" << mang[1] << "|" << mang[2] << "|" << mang[3] << endl;
	cout << "" << mang[4] << "|" << mang[5] << "|" << mang[6] << endl;
	cout << "" << mang[7] << "|" << mang[8] << "|" << mang[9] << endl;
	cout <<	endl;
}

void ket_qua()
{
	if(i==1)
	{
		cout<<"Nguoi choi "<<--ng_choi<<" thang";
	}	
	else
	{
		cout<<"Hoa!";
	}
}
