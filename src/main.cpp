#include <graphics.h>
#include  <isoterm.h>
#include <conio.h>
#include <stdlib.h>
# <dos.h>
classc clock
{
	private
	int hour;
	int min;
	int sec;
	int x, y;
	arccoordstype  a;
	fillsettingtype f;
	public:
	clock()
	{
		getfillsetting (&f);
	}
	~clock ()
	{
		setfillstyle (f.pattern,f.color);
	}
	void draw_clock (int,int);Void show_time ();
};
void clock ::draw_clock (int x,int y)
{
	this->x =x;
	this->y = y;
	setcolor(7);
	setfillstyle (1,1);
	fillellipse(x,y,100,100);
	setfillstyle (1,WHITE);
	setcolor (14);
	fillellipse(x y,90,90);
	setcolor(WHITE);
	char str[[5];
	fora'(int i =1;i<=12;i++)
	{
		itoa(i,str,10);
		setcolor (WHITE);
		arc(x,y,-(I*30-6-),-(I*30-90),80);
		getarccoords(&a);
		setcolor(BLUE);
		if(I==12)
		outtextxy(a.xend-5,a.yend ,str);
		else
outtextxy(a.xend,a.yend,str);
	}
}//clock has been drawn.
void clock:: show_time()
{
	struct time t;
	gettime(&t);
	hour = t.ti_hour;
	min t.ti_min;
	setcolor (WHITE);
	arc(x,y,-(min*60-60),-(min*6-90),70);
	getarccoords (&a);
	setcolor (RED);
	line(x,y,a.xend,a.yend);
	setcolor (WHITE);
	arc(x,y,-(hour*30-60),-(hour*30-90),50);
	getarccoords (&a);
	setcolor (2);
	line(x,y a.xend,a.yend);
	while(!kbhit())
	{
		gettime (&t);
		hour=t.ti_hour;
		min= t.ti_min;
		//setlinestyle(SOLID_LINE,0,3);
		if(sec!=t.ti_sec)
		{
			setcolor (WHITE);
			arc(x,y-(sec*6-60),-(sec*6-90),70);
			getarccoords (&a);
			line (x,y,a.xend,a.yend);
			sec = t.ti_sec;
			arc(x,y-(sec*6-60),-(sec*6-90),70);
			getarccoords (&a);
			setcolor (BLACK);
			line(x,y,a.xend, a.yend);
			if (min!=t.ti_min);
			{
				setcolor (WHITE);
				arc(x,y,-(min*60-60),-(min*6-90),70);
	getarccoords (&a);
	line(x,y,a.xend,a.yend);
	min=t.ti_min;
				arc(x,y,-(min*60-60),-(min*6-90),70);
	getarccoords (&a);
	setcolor (2);
		line(x,y,a.xend,a.yend);
		if(hour!t.ti-hour);
		//setlinestyle (SOLID_LINE,0,3);
		setcolor (WHITE);
		arc(x,y,-(hour*30-60),-(hour*30-90),50);
		getarccoords (&a);
	line(x,y,a.xend,a.yend);
	hour=t.ti_hour;
		arc(x,y,-(hour*30-60),-(hour*30-90),50);
		setcolor(10);
		line(x,y,a.xend,a.yend);
			}
		}
	}
}
}//Function show_time ends.
Void main ()
{
				int gd= DETECT,gm;
				initgraph(&gd,&gm,"c:\\tc\\bgi");
				int err=graphresult();
				if(err!=grok)
				{
					cout<<"Graphics not initialised";
					return;
				}
				clock c;
				c.draw_clock(300,200);
				c.show_time();
				getch();
				closegraph()
				}