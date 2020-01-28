#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
void tictac(void);
int condition(char k[]);
void printt(char q[],int,int);
void move(char e,int *w,int *z);
int valid(int,int,char u[]);
int ret(int,int);
int reta(char v[]);
void snake(void);
void prints(int o[100],int m[100],int,int,int);
void move(char,int o1[100],int m1[100],char mo1[100],int);
void food(int p[100],int n[100],int &,int&,int);
void grow(int p1[100],int n1[100],char,int &);
void hangman(void);
void handcricket(void);
void printn(int,int,int);
int bat(int);
int bowl(int);
void tictac()
{
char n1[30],n2[30],a[9],c;
int x,y,t=0;
x=37;
y=10;
clrscr();
printf("Enter player 1's name : ");
gets(n1);
gets(n1);
printf("Enter player 2's name : ");
gets(n2);
for(int i=0;i<9;i++)
a[i]=' ';
printt(a,x,y);
do
{
g:
c=getch();
if(c=='r')
exit(0);
if((c=='w')||(c=='a')||(c=='s')||(c=='d'))
move(c,&x,&y);
else if(c==' ')
if((t==0)&&(valid(x,y,a)==1))
{
a[ret(x,y)]='o';
if(t==0)
t=1;
else
t=0;
}
else if((t==1)&&(valid(x,y,a))==1)
{
a[ret(x,y)]='x';
if(t==0)
t=1;
else
t=0;
}
else
goto g;
printt(a,x,y);
if(condition(a)==3)
break;
}
while(condition(a)==0);
clrscr();
gotoxy(35,12);
if(condition(a)==1)
{
puts(n1);
gotoxy(33,13);
printf(" WINS!!!");
}
else if(condition(a)==2)
{
puts(n2);
gotoxy(33,13);
printf(" WINS!!!");
}
else if(condition(a)==3)
printf("OOPS ITS A DRAW...");
getch();
}
int valid(int x,int y,char a[9])
{
if((((x==37)&&((y==10)||(y==12)||(y==14)))||((x==39)&&((y==10)||(y==12)||(y==14)))||((x==41)&&((y==10)||(y==12)||(y==14))))&&(a[ret(x,y)]==' '))
return 1;
else
return 0;
}
int ret(int x,int y)
{
if((x==37)&&(y==10))
return 0;
if((x==39)&&(y==10))
return 1;
if((x==41)&&(y==10))
return 2;
if((x==37)&&(y==12))
return 3;
if((x==39)&&(y==12))
return 4;
if((x==41)&&(y==12))
return 5;
if((x==37)&&(y==14))
return 6;
if((x==39)&&(y==14))
return 7;
if((x==41)&&(y==14))
return 8;
else
return 9;
}
int condition(char a[9])
{
if((a[0]==a[1])&&(a[0]==a[2])&&(a[0]!=' '))
if(a[0]=='o')
return 1;
else
return 2;
else if((a[3]==a[4])&&(a[3]==a[5])&&(a[3]!=' '))
if(a[3]=='o')
return 1;
else
return 2;
else if((a[6]==a[7])&&(a[6]==a[8])&&(a[6]!=' '))
if(a[6]=='o')
return 1;
else
return 2;
else if((a[0]==a[3])&&(a[0]==a[6])&&(a[0]!=' '))
if(a[0]=='o')
return 1;
else
return 2;
else if((a[1]==a[4])&&(a[1]==a[7])&&(a[1]!=' '))
if(a[1]=='o')
return 1;
else
return 2;
else if((a[2]==a[5])&&(a[2]==a[8])&&(a[2]!=' '))
if(a[2]=='o')
return 1;
else
return 2;
else if((a[0]==a[4])&&(a[0]==a[8])&&(a[0]!=' '))
if(a[0]=='o')
return 1;
else
return 2;
else if((a[2]==a[4])&&(a[2]==a[6])&&(a[2]!=' '))
if(a[2]=='o')
return 1;
else
return 2;
else if(reta(a)==0)
return 3;
else
return 0;
}
int reta(char a[9])
{
int i=0;
for(int j=0;j<9;j++)
if(a[j]==' ')
i=1;
return(i);
}
void move(char c,int *x,int *y)
{
if(c=='w')
*y-=2;
if(c=='s')
*y+=2;
if(c=='a')
*x-=2;
if(c=='d')
*x+=2;
gotoxy(*x,*y);
}
void printt(char a[9],int x,int y)
{
gotoxy(37,10);
printf("%c%c%c%c%c",a[0],char(186),a[1],char(186),a[2]);
gotoxy(37,11);
printf("%c%c%c%c%c",char(205),char(206),char(205),char(206),char(205));
gotoxy(37,12);
printf("%c%c%c%c%c",a[3],char(186),a[4],char(186),a[5]);
gotoxy(37,13);
printf("%c%c%c%c%c",char(205),char(206),char(205),char(206),char(205));
gotoxy(37,14);
printf("%c%c%c%c%c",a[6],char(186),a[7],char(186),a[8]);
gotoxy(x,y);
}
void snake()
{
textcolor(7);
int i,j,x[100],y[100],xf,yf,l=1;
char te,ch='d',mo[100];
x[0]=40;
y[0]=12;
food(x,y,xf,yf,l);
prints(x,y,xf,yf,l);
while(ch!='r')
{
while(!kbhit())
{
if(ch=='w')
move('w',x,y,mo,l);
if(ch=='s')
move('s',x,y,mo,l);
if(ch=='a')
move('a',x,y,mo,l);
if(ch=='d')
move('d',x,y,mo,l);
if((x[0]==xf)&&(y[0]==yf))
{
food(x,y,xf,yf,l);
grow(x,y,mo[l-1],l);
}
for(int h=1;h<l;h++)
if((x[0]==x[h])&&(y[0]==y[h]))
{
textcolor(9+BLINK);
prints(x,y,xf,yf,l);
delay(1000);
goto q;
}
prints(x,y,xf,yf,l);
}
te=ch;
ch=getch();
if((te=='w'&&ch=='s')&&(l!=1))
ch='w';
else if((te=='s'&&ch=='w')&&(l!=1))
ch='s';
else if((te=='a'&&ch=='d')&&(l!=1))
ch='a';
else if((te=='d'&&ch=='a')&&(l!=1))
ch='d';
}
q:
clrscr();
gotoxy(35,15);
textcolor(7+BLINK);
printf("OOPS GAME OVER....!");
delay(1500);
}
void grow(int x[100],int y[100],char ch,int &l)
{
if(ch=='w')
{
x[l]=x[l-1];
y[l]=y[l-1]+1;
}
else if(ch=='s')
{
x[l]=x[l-1];
y[l]=y[l-1]-1;
}
else if(ch=='a')
{
x[l]=x[l-1]+1;
y[l]=y[l-1];
}
else if(ch=='d')
{
x[l]=x[l-1]-1;
y[l]=y[l-1];
}
l++;
}
void food(int x[100],int y[100],int &xf,int &yf,int l)
{
int i;
srand(time(NULL));
xf=rand()%78+2;
yf=rand()%22+2;
for(i=0;i<l;i++)
{
if((xf==x[i])&&(yf==y[i]))
food(x,y,xf,yf,l);
}
}
void move(char ch,int x[100],int y[100],char mo[100],int l)
{
int i,j,temp;
for(int k=l-1;k>=0;k--)
{
if(k==0)
mo[k]=ch;
else
mo[k]=mo[k-1];
if(mo[k]=='w')
{
{
if(y[k]==2)
y[k]=23;
else
y[k]--;
}
}
if(mo[k]=='s')
{
if(y[k]==23)
y[k]=2;
else
y[k]++;
}
if(mo[k]=='d')
{
if(x[k]==79)
x[k]=2;
else
x[k]++;
}
if(mo[k]=='a')
{
if(x[k]==2)
x[k]=79;
else
x[k]--;
}
}
if((mo[0]=='w')||(mo[0]=='s'))
delay(200);
else
delay(100);
}
void prints(int x[100],int y[100],int xf,int yf,int l)
{
int i,j;
clrscr();
gotoxy(1,1);
j=1;
printf("%c",201);
for(i=2;i<80;i++)
{
gotoxy(i,j);
printf("%c",205);
}
printf("%c",187);
for(i=1,j=2;j<24;j++)
{
gotoxy(i,j);
printf("%c",186);
}
gotoxy(1,24);
printf("%c",200);
for(i=2,j=24;i<80;i++)
{
gotoxy(i,j);
printf("%c",205);
}
printf("%c",188);
for(i=80,j=2;j<24;j++)
{
gotoxy(i,j);
printf("%c",186);
}
gotoxy(xf,yf);
printf("@");
for(i=0,j=0;i<l;i++,j++)
{
gotoxy(x[i],y[j]);
cprintf("*");
}
gotoxy(40,25);
printf("SCORE : %d ",l-1);
gotoxy(80,25);
}



void hangman()
{
clrscr();
int e=0,f=0,i,l,c=7;
char ch,h[10],ans[50],ques[50],p1[50],p2[50];
strcpy(ans,"*");
strcpy(h,"HANGMAN");
printf("Enter the Player 1's name : ");
gets(p1);
gets(p1);
printf("Enter the Player 2's name : ");
gets(p2);
clrscr();
printf("%s Enter the question : ",p1);
gets(ques);
l=strlen(ques);
clrscr();
for(i=0;i<l;i++)
ans[i]='*';
for(;c>=0;)
{
e=0;
for(i=0;i<l;i++)
{
if(ans[i]=='*')
e++;
}
puts(h);
puts(ans);
if(e==0)
{
printf("YOU WIN....!!!");
getch();
break;
}

f=0;
if(c!=7)
h[7-c]=tolower(h[7-c]);
ch=getch();
for(i=0;i<l;i++)
{
if((ch==ques[i])&&(ans[i]=='*'))
{
ans[i]=ch;
f=1;
}
}
if(f==0)
c--;
}
printf("YOU LOOSE....!!");
getch();
}
int cows(void)
{
int l,c=0,b=0,k=1;
char n1[30],n2[30],w[50],g[50];
printf("Player 1 Name : ");
gets(n1);
printf("Player 2 Name : ");
gets(n2);
printf("%s enter the word :",n1);
gets(w);
l=strlen(w);
clrscr();
printf("Clue The Number Of Letters is : %d",l);
while(k<11)
{
printf("\n%s chance %d : ",n2,k);
c=0;
b=0;
gets(g);
for(int i=0;i<l;i++)
{
for(int j=0;j<l;j++)
{
if(tolower(w[i])==tolower(g[j]))
if(i==j)
{
b++;
}
else
{
c++;
}
}
}
printf("%d cows & %d bulls",c,b);
if(b==l)
{
clrscr();
gotoxy(25,10);
printf("Woah %s Wins....!",n2);
getch();
return 0;
}
k++;
}
clrscr();
gotoxy(25,10);
printf("Oops %s Lost....!",n2);
getch();
}
void handcricket()
{
clrscr();
textcolor(13);
int ch,scoreh,scorec;
char name[50];
cprintf("Enter your Name :");
gets(name);
gets(name);
u:
gotoxy(25,10);
cprintf("Choose your preference");
gotoxy(30,12);
cprintf("1: Batting");
gotoxy(30,13);
cprintf("2: Bowling");
gotoxy(25,20);
cprintf("Enter Your Choice :  ");
scanf("%d",&ch);
switch(ch)
{
case 1:{
	scoreh=bat(10000);
	cprintf("You have to bowl now !");
	getch();
	scorec=bowl(scoreh);
	break;
	}
case 2:{
	scorec=bowl(10000);
	cprintf("You have to chase his score now !!");
	getch();
	scoreh=bat(scorec);
	break;
	}
default :
	clrscr();
	cprintf("\nPlease enter again");
	goto u;
}
clrscr();
gotoxy(25,15);
if(scoreh>scorec)
cprintf("Hurray!! You win...!");
else if(scoreh==scorec)
cprintf("Oops its a draw....");
else
cprintf("Better luck next time...You Lost");
getch();
}
int bat(int r)
{
int score=0,h=0,b=1;
clrscr();
for(;h!=b;)
{
d:
clrscr();
printf("Hit!!\n");
scanf("%d",&h);
if((h>6)||(h<0))
goto d;
printn(h,20,5);
gotoxy(15,12);
printf("Woah its a %d !!",h);
srand(time(NULL));
b=rand()%6+1;
printn(b,50,5);
gotoxy(45,12);
printf("He put a %d !! ",b);
if(b!=h)
score+=h;
gotoxy(30,20);
printf("Your score is : %d",score);
getch();
if(score>r)
return(score);
}
clrscr();
printf("Oops You are Out !!!!\nYour total score is : %d \n",score);
return(score);
}
int bowl(int r)
{
int score=0,h=0,b=1;
clrscr();
for(;h!=b;)
{
d:
clrscr();
printf("Throw!!\n");
scanf("%d",&h);
if((h>6)||(h<0))
goto d;
printn(h,20,5);
gotoxy(15,12);
printf("Woah you put a %d !!",h);
srand(time(NULL));
b=rand()%6+1;
printn(b,50,5);
gotoxy(45,12);
printf("OMG he hit a %d !! ",b);
if(b!=h)
score+=b;
gotoxy(30,20);
printf("His score is : %d",score);
getch();
if(score>r)
return(score);
}
clrscr();
printf("Great you took a wicket !!!!\nHis total score is : %d \n",score);
return(score);
}
void printn(int a,int i,int j)
{
if(a==1)
{
gotoxy(i,j);
printf("  *  ");
gotoxy(i,j+1);
printf(" **  ");
gotoxy(i,j+2);
printf("  *  ");
gotoxy(i,j+3);
printf("  *  ");
gotoxy(i,j+4);
printf(" *** ");
}
if(a==2)
{
gotoxy(i,j);
printf(" *** ");
gotoxy(i,j+1);
printf("*   *");
gotoxy(i,j+2);
printf("   * ");
gotoxy(i,j+3);
printf("  *  ");
gotoxy(i,j+4);
printf("*****");
}
if(a==3)
{
gotoxy(i,j);
printf("**** ");
gotoxy(i,j+1);
printf("    *");
gotoxy(i,j+2);
printf("  ** ");
gotoxy(i,j+3);
printf("    *");
gotoxy(i,j+4);
printf("**** ");
}
if(a==4)
{
gotoxy(i,j);
printf("   * ");
gotoxy(i,j+1);
printf("  ** ");
gotoxy(i,j+2);
printf(" * * ");
gotoxy(i,j+3);
printf("*****");
gotoxy(i,j+4);
printf("   * ");
}
if(a==5)
{
gotoxy(i,j);
printf("*****");
gotoxy(i,j+1);
printf("*    ");
gotoxy(i,j+2);
printf("*****");
gotoxy(i,j+3);
printf("    *");
gotoxy(i,j+4);
printf("*****");
}
if(a==6)
{
gotoxy(i,j);
printf("*****");
gotoxy(i,j+1);
printf("*    ");
gotoxy(i,j+2);
printf("*****");
gotoxy(i,j+3);
printf("*   *");
gotoxy(i,j+4);
printf("*****");
}
}


void main()
{clrscr();
 int ch1,ch2,ch3,c;
 char rep='y';
 while(rep=='y')
{
 w1:
 clrscr();
 textcolor(10);
 gotoxy(30,11);
 cprintf("1.SINGLE-PLAYER !!");
 gotoxy(30,12);
 cprintf("2.MULTI-PLAYER !!");
 gotoxy(25,20);
 cprintf("ENTER CHOICE :  ");
 scanf("%d",&ch1);
 clrscr();
 textcolor(11);
 switch(ch1)
 {
  case 1 :
	    m3:
	    clrscr();
	    gotoxy(30,10);
	    cprintf("\n1.HAND-CRICKET");
	    gotoxy(30,11);
	    cprintf("\n2.SNAKE");
	    gotoxy(25,20);
	    cprintf("\nENTER CHOICE : ");
	    scanf("%d",&ch2);
	    if(ch2==1)
	    handcricket();
	    else if(ch2==2)
	    snake();
	    else
	    goto m3;
	    break;
  case 2 :
	    m2:
	    clrscr();
	    gotoxy(30,10);
	    cprintf("1.TIC-TAC-TOE");
	    gotoxy(30,11);
	    cprintf("2.HANGMAN");
	    gotoxy(30,12);
	    cprintf("3.COWS AND BULLS");
	    gotoxy(25,20);
	    cprintf("ENTER CHOICE :  ");
	    scanf("%d",&ch3);
	    if(ch3==1)
	    tictac();
	    else if(ch3==2)
	    hangman();
	    else if(ch3==3)
	    c=cows();
	    else
	    goto m2;
	    break;
  default : goto w1;
  }
 clrscr();
 textcolor(15);
 gotoxy(25,13);
 cprintf("WANNA PLAY AGAIN ??(y/n) :  ");
 //rep=getch();
 scanf("%c",&rep);
 scanf("%c",&rep);
 }
 getch();
 }


