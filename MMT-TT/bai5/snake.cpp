#include<iostream>
#include<stdio.h>
#include<time.h>
#include <conio.h>
#include<windows.h>
#include "console1.h"

#define consoleWidth 25
#define consoleHeight 25
using namespace std;

enum TrangThai { UP,DOWN,LEFT,RIGHT};
int dokho;
struct ToaDo
{
	int x,y;	
};

struct Snake
{
	ToaDo dot[31];
	int n;
	TrangThai tt;	
};

struct HoaQua
{
	ToaDo td;
};

void KhoiTao(Snake &snake,HoaQua &hq)
{

// 	snake.n=1;
// 	snake.dot[0].x=0;
// 	snake.dot[0].y=0;

 	snake.n=3;
 	snake.dot[0].x=2;
 	snake.dot[0].y=0;
	snake.dot[1].x=1;
 	snake.dot[1].y=0;
	snake.dot[2].x=0;
 	snake.dot[2].y=0;
 	snake.tt = RIGHT;
 	
 	hq.td.x=10;
 	hq.td.y=10;
}

void HienThi(Snake snake,HoaQua hq)
{
	clrscr();
	TextColor(10);
	
	gotoXY(consoleWidth+5,1);
	cout<<"Di chuyen :";
	
	gotoXY(consoleWidth+5,2);
	cout<<"A hoac a : ";
	putchar(27);
	
	gotoXY(consoleWidth+5,3);
	cout<<"D hoac d : ";
	putchar(26);
	
	gotoXY(consoleWidth+5,4);
	cout<<"W hoac w : ";
	putchar(24);
	
	gotoXY(consoleWidth+5,5);
	cout<<"S hoac s : ";
	putchar(25);
	
	gotoXY(consoleWidth+5,8);
 	TextColor(9);
 	cout<<"Do kho: "<<dokho;
	TextColor(15);
	for(int i = 0;i<consoleHeight;i++)
	{
		gotoXY(consoleWidth,i);
		putchar(178);
	
	}
	
	
	
	gotoXY(hq.td.x, hq.td.y);
	TextColor(10);
	putchar(64);
	gotoXY(snake.dot[0].x,snake.dot[0].y);
	TextColor(12);
	cout<<"O";
	for(int i =1 ;i<snake.n;i++)
	{
		gotoXY(snake.dot[i].x,snake.dot[i].y);
		TextColor(14);
		cout<<"*";
	}
}

void DieuKhien(Snake &snake)
{
	//trang thai dot cu
	for(int i=snake.n-1;i>0;i--) snake.dot[i] =snake.dot[i-1];
	
	if(kbhit()) //
	{
		int key=_getch();
		
		//dieu khien dau ;
		if((key=='A'||key=='a')&&(snake.tt!=RIGHT)) snake.tt=LEFT;
		else if((key=='W'||key=='w')&&(snake.tt!=DOWN)) snake.tt=UP;
		else if((key=='D'||key=='d')&&(snake.tt!=LEFT)) snake.tt=RIGHT;
		else if((key=='S'||key=='s')&&(snake.tt!=UP)) snake.tt=DOWN;
		
	}
	if(snake.tt==LEFT) snake.dot[0].x--;
	else if(snake.tt==UP) snake.dot[0].y--;
	else if(snake.tt==RIGHT) snake.dot[0].x++;
	else if(snake.tt==DOWN) snake.dot[0].y++;
}

// 0 neu k thua, -1 thua game
int XuLy(Snake &snake,HoaQua &hq)
{
	//an hoa qua
	if(snake.dot[0].x==hq.td.x&&snake.dot[0].y==hq.td.y)
	{
		for(int i=snake.n;i>0;i--)
			snake.dot[i]=snake.dot[i-1];
		snake.n++;
			if(snake.tt==LEFT) snake.dot[0].x--;
	else if(snake.tt==UP) snake.dot[0].y--;
	else if(snake.tt==RIGHT) snake.dot[0].x++;
	else if(snake.tt==DOWN) snake.dot[0].y++;
		
		hq.td.x= rand() % consoleWidth;
		hq.td.y=rand() % consoleHeight;
	}
	//thua game;
	if(snake.dot[0].x<0||snake.dot[0].x>=consoleWidth||snake.dot[0].y<0||snake.dot[0].y>=consoleHeight) 
		return -1;
	for(int i=1;i<snake.n;i++)
		if(snake.dot[0].x == snake.dot[i].x && 
		   snake.dot[0].y == snake.dot[i].y)
			return -1;
	
}
 int main()
 {
 	srand(time(NULL)); //khoi tao sinh so ngau nhien
 	Snake snake;
 	HoaQua hq;
 	KhoiTao(snake,hq);
 	int ma=0;
 
 	gotoXY(consoleWidth/2,10);
 	TextColor(9);
 	do{
 		cout<<"Moi chon do kho tu 100 den 250:";
 		cin>>dokho;
	 }while(dokho<100||dokho>250);
 	while(1)
 	{
 		
 		//Hien thi
 		HienThi(snake,hq);
 		//dieu khien
 		DieuKhien(snake);
 		// xu ly
 		ma=XuLy(snake,hq);
 		//thang ,thua
 		if(ma==-1)
 		{
 			gotoXY(consoleWidth+5,10);
 			TextColor(9);
 			cout<<"Diem cua ban la: "<<snake.n-3;
 			while(_getch()!=13);
 			break;
		}
	 Sleep(300-dokho);
	}
 	
 	
 	gotoXY(0,consoleHeight-2);
 	return 0;
 }
 
