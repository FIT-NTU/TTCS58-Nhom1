#include<iostream>
using namespace std;
#include<string.h>
int a[3][3]={{0,0,0},
			{0,0,0},
			{0,0,0}};
int b[3][3]={{0,0,0},
			{0,0,0},
			{0,0,0}};
char c[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
void hienThi(int a[3][3],char c[10]);
int kiemTra(int a[3][3]);
void menu(int chon);
void hienThi(int a[3][3],char c[10])
{
	int q=0;
	cout<<"\n\n\n\n\n";
	for(int i=0;i<3;i++)
	{
		cout<<"\t\t\t\t\t";
		for(int j=0;j<3;j++)
		{
			cout<<"    "<<c[++q];
			if(j!=2)
				cout<<"\t|";
		}
		cout<<endl;
		if(i!=2)
		{
			cout<<"\t\t\t\t\t";
			cout<<"--------------------------"<<endl;
		}
	}
}
int kiemTra(int a[3][3])
{
	if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3)
		return 1;
	else if(a[0][0]==1&&a[1][1]==5&&a[2][2]==9)
		return 1;
	else if(a[0][0]==1&&a[1][0]==4&&a[2][0]==7)
		return 1;
	else if(a[0][1]==2&&a[1][1]==5&&a[2][1]==8)
		return 1;
	else if(a[1][0]==4&&a[1][1]==5&&a[1][2]==6)
		return 1;
	else if(a[2][0]==7&&a[2][1]==8&&a[2][2]==9)
		return 1;
	else if(a[0][2]==3&&a[1][1]==5&&a[2][0]==7)
		return 1;
	else if(a[0][2]==3&&a[1][2]==6&&a[2][2]==9)
		return 1;
	else if(a[0][
	0]!=1&&a[0][1]!=2&&a[0][2]!=3&&a[1][0]!=4&&a[1][1]!=5
			&&a[1][2]!=6&&a[2][0]!=7&&a[2][1]!=8&&a[2][2]!=9)
		return 0;
	else
		return -1;
}
void cachChoi(int XO)
{
	int nuocdi,player;
	char xo;
	do
	{
		system("cls");
		hienThi(a,c);
		player=(player%2!=0?1:2);
		if(XO==1)
			xo=(player==1?'X':'O');
		else if(XO==2)
			xo=(player==1?'O':'X');
		cout<<"\n\t\t\t\t\t";
		cout<<"Player "<<player<<" turn :> ";	cin>>nuocdi;
		if(nuocdi==1&&c[1]==' ')
		{
			c[1]=xo;
			if(xo=='X')
				a[0][0]=nuocdi;
			else if(xo=='O')
				b[0][0]=nuocdi;
		}
		else if(nuocdi==2&&c[2]==' ')
		{
			c[2]=xo;
			if(xo=='X')
				a[0][1]=nuocdi;
			else if(xo=='O')
				b[0][1]=nuocdi;
		}
		else if(nuocdi==3&&c[3]==' ')
		{
			c[3]=xo;
			if(xo=='X')
				a[0][2]=nuocdi;
			else if(xo=='O')
				b[0][2]=nuocdi;
		}
		else if(nuocdi==4&&c[4]==' ')
		{
			c[4]=xo;
			if(xo=='X')
				a[1][0]=nuocdi;
			else if(xo=='O')
				b[1][0]=nuocdi;
		}
		else if(nuocdi==5&&c[5]==' ')
		{
			c[5]=xo;
			if(xo=='X')
				a[1][1]=nuocdi;
			else if(xo=='O')
				b[1][1]=nuocdi;
		}
		else if(nuocdi==6&&c[6]==' ')
		{
			c[6]=xo;
			if(xo=='X')
				a[1][2]=nuocdi;
			else if(xo=='O')
				b[1][2]=nuocdi;
		}
		else if(nuocdi==7&&c[7]==' ')
		{
			c[7]=xo;
			if(xo=='X')
				a[2][0]=nuocdi;
			else if(xo=='O')
				b[2][0]=nuocdi;
		}
		else if(nuocdi==8&&c[8]==' ')
		{
			c[8]=xo;
			if(xo=='X')
				a[2][1]=nuocdi;
			else if(xo=='O')
				b[2][1]=nuocdi;
		}
		else if(nuocdi==9&&c[9]==' ')
		{
			c[9]=xo;
			if(xo=='X')
				a[2][2]=nuocdi;
			else if(xo=='O')
				b[2][2]=nuocdi;
		}
		else
		{
			player--;
			cout<<"Vi tri nay da ton tai hoac khong co vi tri nay!"<<endl;
			system("pause");
		}
		player++;
	}while(kiemTra(a)!=1&&kiemTra(b)!=1);
	system("cls");
	hienThi(a,c);
	if(kiemTra(a)==1)
	{
		cout<<"\n\t\t\t\t\t";
		cout<<"Player "<<--player<<" win"<<endl;
	}
	else if(kiemTra(b)==1)
	{
		cout<<"\n\t\t\t\t\t";
		cout<<"Player "<<--player<<" win"<<endl;
	}
	else
	{
		cout<<"\n\t\t\t\t\t";
		cout<<"Draw!"<<endl;
	}
}
void menu()
{
	int chon,a[3][3],XO;
	cout<<endl;
	cout<<"-----------MENU-----------"<<endl;
	cout<<"1 : Play with X"<<endl;
	cout<<"2 : Play with O"<<endl;
	do
	{
		cout<<"3 : Exit"<<endl;
		cout<<"Enter your choise:>";
		cin>>chon;
		switch(chon)
		{
			case 1:
				XO=1;
				cachChoi(XO);
				break;
			case 2:
				XO=2;
				cachChoi(XO);
				break;
			case 3:
				break;
			default:
				cout<<"Muc luc chon khong ton tai!"<<endl;
				break;
		}
	}while(chon!=3);
}
int main()
{
	menu();
	return 0;
}
