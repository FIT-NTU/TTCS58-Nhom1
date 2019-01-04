#include<string.h>
#include<stdio.h>
#include<iostream>
//#include<graphics>
#include<math.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
//-------------------------
void EnterGraphics()
{ textbackground(1);
clrscr();
int errorcode,gd=0,gm;
gd=0; // 15:ban kinh 3:mauto 4: maubien
initgraph(&gd,&gm,"c:/borlandc/BGI");
//----------------------
errorcode = graphresult();
if (errorcode != grOk)
{ clrscr();
cout<<"\nGraphics error: \n"<< grapherrormsg(errorcode);
cout<<"\nLuu Huynh Chau Pha Khoa CNTT DH KHTN";
cout<<"\nXin nhap lai dung duong dan thu muc BGI";
cout<<"\nXin lien he voi Chau Pha de lay thu muc BGI";
cout<<"\nNhan phim bat ky de thoat ra";
getch();
exit(1);
}
}
void Closegraph()
{ closegraph();}
 
//-------------------------
int delayy=100,flag=0,cotb=30,dongb=30,dau=4,ch,cuoi=1 0,cot[500],dong[500];
//-------------------------
void Draw_sky();
void EnterGraphics();
void Closegraph();
void Start();
void Ball();
void Ve_To(int cot,int dong,int r,int maubien,int mauto);
void Press(int &ch);
void Cham();
void Khung();
void Bom(int &cotb,int &dongb);
void Kiss();
void Delay(int *delayy);
void Random1(int &cotb,int &dongb);
void Random2(int &cotb,int &dongb);
void Random3(int &cotb,int &dongb);
void Random4(int &cotb,int &dongb);
void Pieslice(int x,int y,int gd,int gc,int r,int maubien,int mauto);
void Buom();
void HCN(int x,int y,int maubien,int mauto);
//------------------------------
void HCN(int x,int y,int maubien,int mauto)
{ setcolor(maubien);
setfillstyle(1,mauto);
bar(x-4,y-4,x+4,y+4);
}
void Buom(int x,int y)
{ Pieslice(x,y,30,150,5,2,4);
}
void Pieslice(int x,int y,int gd,int gc,int r,int maubien,int mauto)
{ setcolor(maubien);
//circle(cot,dong,r);
setfillstyle(1,mauto);
//floodfill(x,y,maubien);
pieslice(x,y,gd,gc,r);
}
 
void Delay(int *delayy)
{ if(cuoi<20) *delayy=90;
else
if(cuoi<30) *delayy=60;
else
if(cuoi<45) *delayy=40;
else
if(cuoi<65) *delayy=30;
else
if(cuoi<80) *delayy=10;
else
if(cuoi<100) *delayy=5;
else *delayy=1;
delay(*delayy);
}
void Random1(int &cotb,int &dongb)
{ int a=getmaxx(),b=getmaxy();
cotb=random(a/2/10)*10;
dongb=random(b/2/10)*10;
if(cotb<=5) cotb=10;
if(dongb<=5) dongb=10;
if(cotb>=a) cotb=a-10;
if(dongb>=b) dongb=b-10;
}
void Random2(int &cotb,int &dongb)
{ int a=getmaxx(),b=getmaxy();
cotb=random(a/2/10)*10+a/2/10*10;
dongb=random(a/2/10)*10;
if(cotb<=5) cotb=10;
if(dongb<=5) dongb=10;
if(cotb>=a) cotb=a-10;
if(dongb>=b) dongb=b-10;
 
}
void Random3(int &cotb,int &dongb)
{ int a=getmaxx(),b=getmaxy();
cotb=random(a/2/10)*10;
dongb=random(b/2/10)*10+b/2/10*10;
if(cotb<=5) cotb=10;
if(dongb<=5) dongb=10;
if(cotb>=a) cotb=a-10;
if(dongb>=b) dongb=b-10;
 
}
void Random4(int &cotb,int &dongb)
{ int a=getmaxx(),b=getmaxy();
cotb=random(a/2/10)*10+a/2/10*10;
dongb=random(b/2/10)*10+b/2/10*10;
if(cotb<=5) cotb=10;
if(dongb<=5) dongb=10;
if(cotb>=a) cotb=a-10;
if(dongb>=b) dongb=b-10;
 
}
 
void Bom(int &cotb,int &dongb)
{ int i;
Pieslice(cotb,dongb,0,270,5,0,0);
if(flag==0)
{ randomize();
i=random(4);
randomize();
if(i==0) Random1(cotb,dongb);
if(i==1) Random2(cotb,dongb);
if(i==2) Random3(cotb,dongb);
if(i==3) Random4(cotb,dongb);
 
}
//Ve_To(cotb,dongb,5,4,2);
Pieslice(cotb,dongb,0,270,5,random(getmaxcolor()), random(getmaxcolor()));
//Buom(cotb,dongb);
}
void Kiss()
{ int i=cuoi+1;
if(cot[cuoi]==cotb&&dong[cuoi]==dongb)
{ cot=cotb;
dong=dongb;
cuoi=i;flag=0;
}
else flag=1;
}
void Khung()
{ setcolor(1);
setfillstyle(11,9);
rectangle(1,1,getmaxx(),getmaxy());
}
void Cham(int ch,int *dau)
{ for(int i=0;i<cuoi-3;i++)
{ if(ch==77&&((cot[cuoi]==cot-10&&dong[cuoi]==dong)||cot[cuoi]<cot[cuoi-1]||cot[cuoi]>=getmaxx()-10))
{ *dau=5;
break;
}
if(ch==75&&((cot[cuoi]==cot+10&&dong[cuoi]==dong)||cot[cuoi]>cot[cuoi-1]||cot[cuoi]<=10))
{ *dau=5;
break;
}
if(ch==72&&((dong[cuoi]==dong+10&&cot[cuoi]==cot)||dong[cuoi]>dong[cuoi-1]||dong[cuoi]<=10))
{ *dau=5;
break;
}
if(ch==80&&((dong[cuoi]==dong-10&&cot[cuoi]==cot)||dong[cuoi]<dong[cuoi-1]||dong[cuoi]>=getmaxy()-10))
{ *dau=5;
break;
}
}
}
void Press(int &ch)
{ int i;
Cham(ch,&dau);
switch(ch)
{
case 77:
if(cot[cuoi-1]<=cot[cuoi])
if(dau!=5)
{ HCN(cot[0],dong[0],0,0);
//Ve_To(cot[0],dong[0],5,0,0);
for(i=0;i<cuoi;i++)
{ cot=cot[i+1];
dong=dong[i+1];
}
cot[cuoi]+=10;
}
break;
 
case 75:
if(cot[cuoi-1]>=cot[cuoi])
if(dau!=5)
{ HCN(cot[0],dong[0],0,0);
//Ve_To(cot[0],dong[0],5,0,0);
for(i=0;i<cuoi;i++)
{ cot=cot[i+1];
dong=dong[i+1];
}
cot[cuoi]-=10;
}
break;
 
case 72:
if(dong[cuoi-1]>=dong[cuoi])
if(dau!=5)
{ HCN(cot[0],dong[0],0,0);
//Ve_To(cot[0],dong[0],5,0,0);
for(i=0;i<cuoi;i++)
{ dong=dong[i+1];
cot=cot[i+1];
}
dong[cuoi]-=10;
}
break;
 
case 80:
if(dong[cuoi-1]<=dong[cuoi])
if(dau!=5)
{ HCN(cot[0],dong[0],0,0);
//Ve_To(cot[0],dong[0],5,0,0);
for(i=0;i<cuoi;i++)
{ dong=dong[i+1];
cot=cot[i+1];
}
dong[cuoi]+=10;
}
break;
}
}
 
void Start()
{ int k=0;
for(int i=0;i<=cuoi;i++)
{ cot=200+k;
dong=200;
k+=10;
}
}
void Ball(int &dau)
{ for(int i=0;i<cuoi;i++)
//Ve_To(cot,dong,5,6,8);
HCN(cot,dong,6,9);
//Ve_To(cot,dong,5,9,dau);
HCN(cot,dong,4,dau);
dau=4;
}
//--------------------------
void Ve_To(int cot,int dong,int r,int maubien,int mauto)
{
setcolor(maubien);
circle(cot,dong,r);
setfillstyle(1,mauto);
floodfill(cot,dong,maubien);
}
//--------------------------
void Draw_sky()
{ int x[601],y[602];
int i;
setcolor (15);
for(i=1;i<=600;i++) //so ngoi sao tren bau troi
{
x=random(getmaxx());
y=random(getmaxy());
 
putpixel(x,y,random(getmaxcolor()));
}
}
//--------------------------
void Draw()
{ int i,j;
setcolor (15);
int k=15,a,b;
for(i=cuoi;i>=0;i--)
{ HCN(cot,dong,1,8);
for(j=0;j<=k;j++)
{ dong-=15;
cot-=15;
if(i!=cuoi)
HCN(cot,dong,6,9);
else
HCN(cot,dong,4,4);
sound(3000);
delay(20);
nosound();
HCN(cot,dong,0,0);
}
k-=1;
if(k==0) k=10;
}
delay(3000);
}
//-------------------
void main()
{
//-------------------
EnterGraphics();
//-------------------------
ch=121;int cuoi1=cuoi;
while(ch=='y'){
if(ch=='y') cuoi=10;
Start();
//--------------------------
cleardevice();
Khung();
while(ch!=27)
{ gotoxy(1,1);
cout<<"Luu Huynh Chau Pha 03CT1C\n";
cout<<"Chao cac ban...Chuc cac ban nam moi vui ve";
gotoxy(60,8);
cout<<"So diem: "<<(cuoi-cuoi1);
//-----------------------------------------
Bom(cotb,dongb);
Ball(dau);
if(kbhit())
{ ch=getch();}
Press(ch);
Kiss();
Delay(&delayy);
if(dau==5) break;
}
Draw();
cout<<"\nBan da thua \nBan co muon choi lai khong (y/n)";
getch();
ch=getch();
}getch();
//---------------------------
Closegraph();
 
cout<<"Chuc ban nam moi vui ve";
 
getch();
}
