#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>
#include<time.h>
#include<graphics.h>

union REGS in,out;

class bank
{
	private:
		long int accno;
		long double balance;
		char name[50];
		char pass[17];
		char type[11];
		char mobile[11];
		void deposit();	
		void withdrawl();
	public:
		bank()
		{}
		bank(int a, char b, float c, char d, char e, char f)
		{
			accno=a;
			name[0]=b;name[1]='\0';
			balance=c;
			pass[0]=d;pass[1]='\0';
			type[0]=e;type[1]='\0';
			mobile[0]=f;mobile[1]='\0';
		}

void new_acc();
void trans();
void transfer();
void enq(int);
void display();
void modify();
void change_pass();
void delete_acc();
int ispass();
int acc(int);
\
long int retaccno();
};
bank account;
bank dummy;
bank garbage(0,'n',0.0,'n','n','n');
void update(bank);
void save_account();
void credit();
void menu();
int callmouse();
void mouseposi(int &xpos,int &ypos,int &click);
int mousehide();
void setposi(int &xpos,int &ypos);
void opensub(int,int,int);
long int bank::retaccno()
{
return accno;
}
void save_account()
{
ofstream fout;
fout.open("bank.dat",ios::binary|ios::app);
fout.write((char*) &account, sizeof(account));
fout.close();
account=garbage;
}
int callmouse()
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}
void mouseposi(int &xpos,int &ypos,int &click)
{
in.x.ax=3;
int86(51,&in,&out);
click=out.x.bx;
xpos=out.x.cx;
ypos=out.x.dx;
}
int mousehide()
{
in.x.ax=2;

int86(51,&in,&out);
return 1;
}
void setposi(int &xpos,int &ypos)
{
in.x.ax=4;
in.x.cx=xpos;
in.x.dx=ypos;
int86(51,&in,&out);
}
void bank::new_acc()
{
clrscr();
randomize();
int x,y,click;
account.accno=(rand() % 99999)+10000;
delay(300);
mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
setfillstyle(1,8);
bar(20,60,620,445);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(239,16,"NEW ACCOUNT");
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
settextstyle(2,0,7);
setcolor(0);
outtextxy(130,83,"Your account number is:");
setfillstyle(1,4);
bar(152,108,487,130);
setfillstyle(1,0);
bar(154,110,485,128);
outtextxy(130,133,"Enter your name:");
setfillstyle(1,4);
bar(152,156,487,178);
setfillstyle(1,0);
bar(154,158,485,176);
outtextxy(130,181,"Enter the type of account(current/saving):");
setfillstyle(1,4);
bar(152,204,487,226);
setfillstyle(1,0);
bar(154,206,485,224);
outtextxy(130,229,"enter you mobile number:");
setfillstyle(1,4);
bar(152,252,487,274);
setfillstyle(1,0);
bar(154,254,485,272);
outtextxy(130,277,"Enter a password(max 16):");
setfillstyle(1,4);
bar(152,300,487,322);
setfillstyle(1,0);
bar(154,302,485,320);
outtextxy(130,325,"Initial account opening balance is:");
setfillstyle(1,4);
bar(152,348,487,370);
setfillstyle(1,0);
bar(154,350,485,368);

callmouse();
gotoxy(22,8);
cout<<'|'<<'\b';
cout<<account.accno;
gotoxy(22,11);
cout<<'|'<<'\b';
gets(account.name);
gotoxy(22,14);
cout<<'|'<<'\b';
gets(account.type);
gotoxy(22,17);
cout<<'|'<<'\b';
gets(account.mobile);
gotoxy(22,20);
cout<<'|'<<'\b';
for (int i=0;;i++)
{
int ch;
ch=getch();
if (ch!=13 && ch!=8)
{
account.pass[i]=ch;
cout<<'*';
}
else if(ch==8)
{
if(i>0)
{
cout<<'\b'<<" "<<'\b';
i-=2;
}
else
i--;

}
else
{
account.pass[i]='\0';
break;
}
}
account.balance=10000;
gotoxy(22,23);
cout<<account.balance;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
void bank::enq(int a=1)
{ mousehide();
char temp[50];
if (a==1)
{
clrscr();
setfillstyle(6,7);
bar(0,0,640,480);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);

bar(14,14,626,46);
outtextxy(219,16,"ACCOUNT ENQUIRY");
}
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
setfillstyle(1,8);
bar(20,60,620,445);
settextstyle(2,0,7);
setcolor(4);
setfillstyle(1,4);
bar(190,100,465,130);
setfillstyle(1,0);
bar(192,102,463,128);
outtextxy(280,100,"Loading");
delay(1000);
outtextxy(362,100,".");
delay(1000);
outtextxy(367,100,".");
delay(1000);
outtextxy(362,100,".");
delay(1000);
setfillstyle(1,8);
bar(20,60,620,445);
setcolor(15);
outtextxy(40,100,"Holders name ");
outtextxy(40,130,"Account number ");
outtextxy(40,160,"Account type ");
outtextxy(40,190,"Mobile number ");
outtextxy(40,220,"Current balance");
outtextxy(222,100,":");

outtextxy(222,130,":");
outtextxy(222,160,":");
outtextxy(222,190,":");
outtextxy(222,220,":");
settextstyle(2,0,6);
setcolor(0);
setfillstyle(1,4);
bar(228,100,520,123);
setfillstyle(1,7);
bar(230,102,518,121);
outtextxy(232,100,account.name);
ltoa(account.accno,temp,10);
setfillstyle(1,4);
bar(228,130,520,153);
setfillstyle(1,7);
bar(230,132,518,151);
outtextxy(232,130,temp);
setfillstyle(1,4);
bar(228,160,520,183);
setfillstyle(1,7);
bar(230,162,518,181);
outtextxy(232,160,account.type);
setfillstyle(1,4);
bar(228,190,520,213);
setfillstyle(1,7);
bar(230,192,518,211);
outtextxy(232,190,account.mobile);
ltoa(account.balance,temp,10);
setfillstyle(1,4);
bar(228,220,520,243);
setfillstyle(1,7);
bar(230,222,518,241);
outtextxy(232,220,temp);

callmouse();
}
void bank::trans()
{
clrscr();
mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(245,16,"TRANSACTION");
account.enq(0);
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
setfillstyle(1,4);
bar(80,301,260,386);
setfillstyle(1,7);
bar(82,303,258,384);
outtextxy(103,333,"DIPOSITE MONEY");
setfillstyle(1,4);
bar(380,301,560,386);
setfillstyle(1,7);
bar(382,303,558,384);
outtextxy(396,333,"WITHDRAWL MONEY");

callmouse();
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if(x>=80 && y>=301 && x<=260 && y<=386 && click==1 )
{
delay(100);
account.deposit();
}
if(x>=380 && y>=301 && x<=560 && y<=386 && click==1 )
{
delay(100);
account.withdrawl();
}
if (click==1)
{
delay(100);
break;
}
}
}
void bank::deposit()
{
long double amt;
char temp[20];
clrscr();
mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
setfillstyle(1,8);
bar(20,60,620,445);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(222,16,"DIPOSITE MONEY");
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
settextstyle(2,0,7);
setcolor(0);
callmouse();
outtextxy(40,172,"Enter Amount :");
setfillstyle(1,4);
bar(225,172,520,195);
setfillstyle(1,0);
bar(227,174,518,193);
gotoxy(31,12);
cin>>amt;
account.balance+=amt;
delay(700);
setcolor(4);
setfillstyle(1,4);
bar(190,100,465,130);
setfillstyle(1,0);
bar(192,102,463,128);
outtextxy(260,100,"Money Added");
setcolor(0);
setfillstyle(1,4);

bar(225,219,520,242);
setfillstyle(1,7);
bar(227,221,518,240);
ltoa(account.balance,temp,10);
outtextxy(40,219,"Account balance:");
outtextxy(229,219,temp);
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
void bank::withdrawl()
{
long double amt;
char temp[20];
clrscr();
mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
setfillstyle(1,8);
bar(20,60,620,445);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(199,16,"WITHDRAWL MONEY");

settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
settextstyle(2,0,7);
setcolor(0);
callmouse();
outtextxy(40,172,"Enter Amount :");
setfillstyle(1,4);
bar(225,172,520,195);
setfillstyle(1,0);
bar(227,174,518,193);
gotoxy(31,12);
cin>>amt;
if(amt<=account.balance)
{
setcolor(4);
setfillstyle(1,4);
bar(190,100,465,130);
setfillstyle(1,0);
bar(192,102,463,128);
outtextxy(240,100,"Withdrawling");
account.balance-=amt;
delay(500);
setfillstyle(1,0);
bar(192,102,463,128);
outtextxy(260,100,"Sucessfull");
setcolor(0);
setfillstyle(1,4);
bar(225,219,520,242);
setfillstyle(1,7);

bar(227,221,518,240);
ltoa(account.balance,temp,10);
outtextxy(40,219,"Account balance:");
outtextxy(229,219,temp);
}
else
{
setcolor(4);
setfillstyle(1,4);
bar(165,100,490,130);
setfillstyle(1,0);
bar(167,102,488,128);
outtextxy(172,100,"You dont have enough money");
}
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
void bank::transfer()
{
clrscr();
fstream fio;
char temp[20];
bank tempacc,rec,&sen=account;
long double amt;
long int recaccno;
int c=0,pos;
fio.open("bank.dat",ios::binary|ios::out|ios::in);
mousehide();

setfillstyle(6,7);
bar(0,0,640,480);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(219,16,"TRANSFER MONEY");
sen.enq(0);
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
callmouse();
setposi(getmaxx()/2,getmaxy()/2);
settextstyle(2,0,7);
outtextxy(40,258,"Enter the benifitiary (reciver's) account number:");
setfillstyle(1,4);
bar(228,283,520,306);
setfillstyle(1,0);
bar(230,285,518,304);
gotoxy(30,19);
cin>>recaccno;
while(fio.read((char *)&rec,sizeof(rec)))
{
if(rec.accno==recaccno)
{
c++;
break;
}

}
delay(1000);
if(c==0)
{
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,358,455,388);
setfillstyle(1,0);
bar(192,360,453,386);
outtextxy(200,358,"Account not found");
}
else
{
setfillstyle(1,8);
bar(20,60,620,445);
outtextxy(40,172,"Enter Amount :");
setfillstyle(1,4);
bar(225,172,520,195);
setfillstyle(1,0);
bar(227,174,518,193);
gotoxy(31,12);
cin>>amt;
if (sen.balance>=amt)
{
sen.balance-=amt;
rec.balance+=amt;
delay(1000);
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,100,455,130);
setfillstyle(1,0);
bar(192,102,453,128);
outtextxy(207,100,"Money transfered");

settextstyle(2,0,7);
setcolor(0);
setfillstyle(1,4);
bar(225,219,520,242);
setfillstyle(1,7);
bar(227,221,518,240);
ltoa(account.balance,temp,10);
outtextxy(40,219,"Account balance:");
outtextxy(229,219,temp);
update(rec);
}
else
{
settextstyle(2,0,7);
setcolor(4);
setfillstyle(1,4);
bar(165,100,490,130);
setfillstyle(1,0);
bar(167,102,488,128);
outtextxy(172,100,"You dont have enough money");
}
}
fio.close();
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
void bank::display()
{
clrscr();

mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
setfillstyle(1,8);
bar(0,60,640,454);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(219,16,"ALL ACCOUNT DATA");
setfillstyle(1,0);
bar(0,60,640,62);
bar(0,82,640,84);
bar(0,452,640,454);
settextstyle(2,0,7);
outtextxy(10,60,"Acc.Num");
outtextxy(115,60,"Holder's Name");
outtextxy(305,60,"Acc.type");
outtextxy(410,60,"Balance");
outtextxy(520,60,"Mobile");
settextstyle(2,0,6);
setcolor(0);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
int i=0;
char temp[50];
ifstream fin("bank.dat");

while(fin.read((char *)&account,sizeof(account)))
{
setcolor(15);
ltoa(account.accno,temp,10);
outtextxy(20,i*15+84,temp);
setcolor(0);
outtextxy(115,i*15+84,account.name);
setcolor(15);
outtextxy(305,i*15+84,account.type);
setcolor(0);
ltoa(account.balance,temp,10);
outtextxy(410,i*15+84,temp);
setcolor(15);
outtextxy(520,i*15+84,account.mobile);
i++;
}
fin.close();
delay(1000);
callmouse();
setposi(getmaxx()/2,getmaxy()/2);
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}

void bank::modify()
{
clrscr();
setfillstyle(6,7);
bar(0,0,640,480);
mousehide();
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(303,16,"MODIFY");
account.enq(0);
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
callmouse();
setfillstyle(1,4);
bar(35,301,215,386);
setfillstyle(1,7);
bar(37,303,213,384);
outtextxy(59,333,"NAME");
setfillstyle(1,4);
bar(230,301,410,386);
setfillstyle(1,7);
bar(232,303,408,384);
outtextxy(262,333,"ACCOUNT TYPE");
setfillstyle(1,4);
bar(425,301,605,386);
setfillstyle(1,7);
bar(427,303,603,384);
outtextxy(449,333,"MOBILE");
int x,y,click;
while(1)
{
mouseposi(x,y,click);
if(x>=35 && y>=301 && x<=215 && y<=386 && click==1 )
{
setfillstyle(1,8);
bar(20,300,620,445);
outtextxy(40,331,"Enter New Name :");
setfillstyle(1,4);
bar(228,331,520,354);
setfillstyle(1,0);
bar(230,333,518,352);
gotoxy(31,22);
gets(account.name);
settextstyle(2,0,7);
setcolor(4);
setfillstyle(1,4);
bar(190,385,465,415);
setfillstyle(1,0);
bar(192,387,463,413);
outtextxy(215,385,"Updation Sucessfull");
break;
}
if(x>=230 && y>=301 && x<=410 && y<=386 && click==1 )
{
setfillstyle(1,8);
bar(20,300,620,445);
outtextxy(40,331,"Enter Account type :");
setfillstyle(1,4);
bar(228,331,520,354);

setfillstyle(1,0);
bar(230,333,518,352);
gotoxy(31,22);
gets(account.type);
settextstyle(2,0,7);
setcolor(4);
setfillstyle(1,4);
bar(190,385,465,415);
setfillstyle(1,0);
bar(192,387,463,413);
outtextxy(215,385,"Updation Sucessfull");
break;
}
if(x>=425 && y>=301 && x<=605 && y<=386 && click==1 )
{
setfillstyle(1,8);
bar(20,300,620,445);
outtextxy(40,331,"Enter Mobile Number:");
setfillstyle(1,4);
bar(228,331,520,354);
setfillstyle(1,0);
bar(230,333,518,352);
gotoxy(31,22);
gets(account.mobile);
settextstyle(2,0,7);
setcolor(4);
setfillstyle(1,4);
bar(190,385,465,415);
setfillstyle(1,0);
bar(192,387,463,413);
outtextxy(215,385,"Updation Sucessfull");
break;
}
}
while(!kbhit())
{

mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
void bank::change_pass()
{
char pass[17];
mousehide();
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(219,16,"Change Password");
settextstyle(2,0,6);
setcolor(15);
setfillstyle(1,4);
bar(185,266,520,289);
setfillstyle(1,0);
bar(187,268,518,287);
outtextxy(40,266,"New password:");
settextstyle(2,0,5);
setcolor(7);
outtextxy(189,223,"Enter current password now");
callmouse();
gotoxy(27,15);
for (int i=0;;i++)
{
int ch;
ch=getch();

if(i==0)
{
setfillstyle(1,0);
bar(187,221,518,240);
}
if (ch!=13&&ch!=8)
{
pass[i]=ch;
cout<<'*';
}
else if(ch==8)
{
if(i>0)
{
cout<<'\b'<<" "<<'\b';
i-=2;
}
else
i--;
}
else
{
pass[i]='\0';
break;
}
}
if(strcmp(pass,account.pass))
{
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,100,465,130);
setfillstyle(1,0);
bar(192,102,463,128);
outtextxy(197,100,"Incorrect password");
}
else
{
gotoxy(27,18);
outtextxy(189,268,"Enter new password now");
for (int i=0;;i++)
{
int ch;
ch=getch();
if(i==0)
{
setfillstyle(1,0);
bar(187,268,518,287);
}
if (ch!=13&&ch!=8)
{
account.pass[i]=ch;
cout<<'*';
}
else if(ch==8)
{
if(i>0)
{
cout<<'\b'<<" "<<'\b';
i-=2;
}
else
i--;
}
else
{
account.pass[i]='\0';
break;
}
}
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,100,465,130);
setfillstyle(1,0);
bar(192,102,463,128);
outtextxy(220,100,"Password Update");
}
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
int bank::ispass()
{
char pass[17];
cout<<"|\b";
for (int i=0;;i++)
{
int ch;
ch=getch();
if (ch!=13&&ch!=8)
{
pass[i]=ch;
cout<<'*';
}
else
{
if(ch==8)
{
if(i>0)
{
cout<<'\b'<<" "<<'\b';
i-=2;
}
else
i--;
}
else
{
pass[i]='\0';
break;
}
}
}
if(strcmp(pass,account.pass))
return(0);
else
return(1);
}
int bank::acc(int a)
{
long int acc;
bank tempacc;
clrscr();
mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
setfillstyle(1,8);
bar(20,60,620,445);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(222,16," Account Login");
settextstyle(2,0,6);
setcolor(0);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
outtextxy(40,172,"Account number:");
setfillstyle(1,4);
bar(185,172,520,195);
setfillstyle(1,0);
bar(187,174,518,193);
outtextxy(40,219,"Password :");
setfillstyle(1,4);
bar(185,219,520,242);
setfillstyle(1,0);
bar(187,221,518,240);
callmouse();
gotoxy(27,12);
cin>>acc;
ifstream fin;
fin.open("bank.dat",ios::binary);
while(1)
{
if(fin.read((char *) &tempacc, sizeof(tempacc)))
{
if(tempacc.accno==acc)
{
account=tempacc;
break;
}
}
else
{
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,100,455,130);
setfillstyle(1,0);
bar(192,102,453,128);
outtextxy(200,100,"Account not found");
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
return 0;
}
}
if(a==1)
{
return 1;
}
else
{
gotoxy(27,15);
if(account.ispass())
{
return 1;
}
else
{
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,100,465,130);
setfillstyle(1,0);
bar(192,102,463,128);
outtextxy(197,100,"Incorrect Password");
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{

delay(100);
break;
}
}
account=garbage;
return 0;
}
}
}
void update(bank save_acc=account)
{
fstream fio("bank.dat",ios::binary|ios::in|ios::out);
bank tempacc;
while(fio.read((char *) &tempacc,sizeof(tempacc)))
{
if(tempacc.retaccno()==save_acc.retaccno())
{
int pos=(-1)*sizeof(save_acc);
fio.seekp(pos,ios::cur);
fio.write((char *) &save_acc,sizeof(save_acc));
break;
}
}
fio.close();
}
void bank::delete_acc()
{
char c;
long int temp_accno;
clrscr();
mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
settextstyle(2,0,8);
setcolor(0);
setfillstyle(1,4);

bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(219,16,"DELETE ACCOUNT");
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
account.enq(0);
settextstyle(2,0,7);
outtextxy(40,243,"Enter your account number (For Confermation):");
setfillstyle(1,4);
bar(228,268,520,291);
setfillstyle(1,0);
bar(230,270,518,289);
callmouse();
gotoxy(30,18);
cin>>temp_accno;
if(account.retaccno()==temp_accno)
{
settextstyle(2,0,6);
outtextxy(40,300,"ARE YOU SURE YOU WANT TO DELETE YOUR ACCOUNT (Y/N):");
setfillstyle(1,4);
bar(542,299,567,322);
setfillstyle(1,0);
bar(544,301,565,320);
gotoxy(70,20);
cin>>c;

if (c=='Y'||c=='y')
{
bank tempacc;
ifstream fin;
ofstream fout;
fin.open("bank.dat",ios::binary);
fout.open("temp.dat",ios::binary);
while(fin.read((char *)&tempacc,sizeof(tempacc)))
{
if(tempacc.retaccno()!=temp_accno)
{
fout.write((char
*)&tempacc,sizeof(tempacc));
}
}
fin.close();
fout.close();
remove("bank.dat");
rename("temp.dat","bank.dat");
delay(500);
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,330,465,360);
setfillstyle(1,0);
bar(192,332,463,358);
outtextxy(210,330,"Account DELETED!!");
}
else
{
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(190,330,465,360);
setfillstyle(1,0);
bar(192,332,463,358);
outtextxy(217,330,"Deletion cancled");
}
}

else
{
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(175,330,480,360);
setfillstyle(1,0);
bar(177,332,478,358);
outtextxy(188,330,"Account not matched");
}
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
void main()
{
clrscr();
int gDriver=DETECT, gMode, error;
initgraph(&gDriver,&gMode,"..\\BGI");
error = graphresult();
if (error != grOk)
{
cout<<"Graphics Error \n";
cout<<"Press any key to exit...\n";
getch();
return ;
}
menu();
closegraph();
return ;
}

void credit()
{
clrscr();
int x1,y1,click;
int x=getmaxx(),y=getmaxy();
mousehide();
setfillstyle(6,7);
bar(0,0,640,480);
setviewport(0,0,0,0,0);
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(279,16,"CREDITS");
settextstyle(2,0,6);
setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
setviewport(60,85,x-60,y-30,1);
setfillstyle(1,0);
bar(60,85,x-60,y-30);
settextstyle(2,0,7);
callmouse();
delay(100);
for(int m=330;m>=-520;m--)
{
setcolor(15);

outtextxy(x/2-100,m,"Project By:-");
setcolor(4);
outtextxy(x/2-200,m+40,"1.Desh Deepak Suthar");
outtextxy(x/2-200,m+80,"2.Himanshu Chaudhary");
outtextxy(x/2-200,m+120,"3.Prateek Shrivastav");
outtextxy(x/2-200,m+160,"4.Somitra Swarnakar");
setcolor(15);
outtextxy(x/2-100,m+280,"Reference:-");
setcolor(15);
outtextxy(x/2-200,m+320,"1.Computer Science with C++");
outtextxy(x/2-200,m+340," Book for class XII");
outtextxy(x/2-200,m+360," By Sumita Arora");
outtextxy(x/2-200,m+400,"2.Internet");
outtextxy(x/2-200,m+440,"3.BGIDEMO");
outtextxy(x/2-200,m+460," Pre made graphics program");
outtextxy(x/2-200,m+480," in C++");
setcolor(4);
outtextxy(x/2-130,m+520,"THANK YOU");
delay(20);
setfillstyle(1,0);
bar(0,0,640,480);
mouseposi(x1,y1,click);
if(kbhit()||click==1)
{
return;
}
}
delay(500);
}
void menu()
{
clrscr();
callmouse();
int x,y,click;
int xmax,ymax;
xmax=getmaxx()/2;
ymax=getmaxy()/2;
setposi(xmax,ymax);

regraph:
mousehide();
setviewport(0,0,0,0,0);
setfillstyle(6,7);
bar(0,0,640,480);
settextstyle(2,0,8);
setcolor(4);
setfillstyle(1,4);
bar(10,10,630,50);
setfillstyle(1,0);
bar(12,12,628,48);
setfillstyle(1,15);
bar(14,14,626,46);
outtextxy(14,14," Welcome to the Bank Management Software");
settextstyle(2,0,6);
setcolor(15);
setfillstyle(1,4);
bar(20,60,200,145);
setfillstyle(1,8);
bar(22,62,198,143);
outtextxy(32,92,"SHOW ALL ACCOUNT");
setfillstyle(1,4);
bar(20,160,200,245);
setfillstyle(1,8);
bar(22,162,198,243);
outtextxy(32,192,"BALANCE ENQUIRY");
setfillstyle(1,4);
bar(20,260,200,345);
setfillstyle(1,8);
bar(22,262,198,343);
outtextxy(32,292,"MODIFY");
setfillstyle(1,4);
bar(20,360,200,445);
setfillstyle(1,8);

bar(22,362,198,443);
outtextxy(32,392,"CREDITS");
setfillstyle(1,4);
bar(230,117,410,203);
setfillstyle(1,8);
bar(232,119,408,201);
outtextxy(242,149,"OPEN NEW ACCOUNT");
setfillstyle(1,4);
bar(230,317,410,403);
setfillstyle(1,8);
bar(232,319,408,401);
outtextxy(242,349,"MAKE TRANSACTION");
setfillstyle(1,4);
bar(440,60,620,145);
setfillstyle(1,8);
bar(442,62,618,143);
outtextxy(452,92,"DELETE ACCOUNT");
setfillstyle(1,4);
bar(440,160,620,245);
setfillstyle(1,8);
bar(442,162,618,243);
outtextxy(452,192,"TRANSFER MONEY");
setfillstyle(1,4);
bar(440,260,620,345);
setfillstyle(1,8);
bar(442,262,618,343);
outtextxy(452,292,"CHANGE PASSWORD");
setfillstyle(1,4);
bar(440,360,620,445);
setfillstyle(1,8);
bar(442,362,618,443);
outtextxy(454,394,"EXIT");
settextstyle(2,0,6);

setcolor(BLACK);
setfillstyle(1,12);
bar(0,455,640,480);
outtextxy(142,457,"Right Click on the Operation to Select");
callmouse();
while(1)
{
if(kbhit())
{
char a;
a=getch();
if(a==27)
return;
}
mouseposi(x,y,click);
if(x>=20 && y>=60 && x<=200 && y<=145 && click==1 )
{
dummy.display();
goto regraph;
}
if(x>=20 && y>=160 && x<=200 && y<=245 && click==1 )
{
if(dummy.acc(0))
{
account.enq();
int x,y,click;
while(!kbhit())
{
mouseposi(x,y,click);
if (click==1)
{
delay(100);
break;
}
}
}
goto regraph;
}
if(x>=20 && y>=260 && x<=200 && y<=345 && click==1 )
{
if(dummy.acc(0))
{
account.modify();
update();
}
goto regraph;
}
if(x>=20 && y>=360 && x<=200 && y<=445 && click==1 )
{
credit();
goto regraph;
}
if(x>=230 && y>=117 && x<=410 && y<=203 && click==1 )
{
account.new_acc();
save_account();
goto regraph;
}
if(x>=230 && y>=317 && x<=410 && y<=403 && click==1 )
{
if(dummy.acc(0))
{
account.trans();
update();
}
goto regraph;
}
if(x>=440 && y>=60 && x<=620 && y<=145 && click==1 )
{
if(dummy.acc(0))
{

account.delete_acc();
}
goto regraph;
}
if(x>=440 && y>=160 && x<=620 && y<=245 && click==1 )
{
if(dummy.acc(0))
{
account.transfer();
update();
}
goto regraph;
}
if(x>=440 && y>=260 && x<=620 && y<=345 && click==1 )
{
if(dummy.acc(1))
{
account.change_pass();
update();
}
goto regraph;
}
if(x>=440 && y>=360 && x<=620 && y<=445 && click==1 )
return;
}
}