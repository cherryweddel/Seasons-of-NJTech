#include "button.h"

void button::setImgAddress(LPCTSTR Address)
{
	imgAddress = Address;
	loadimage(&img, Address, 120, 35);
}

void button::setName(LPCTSTR n)
{
	name = n;
}

void button::setLocation(int a, int b, int c, int d)
{
	x1 = a; y1 = b; x2 = c; y2 = d;
}

void button::loadButtonImage()
{
	putimage(x1, y1, &img);
}

void button::drawButtonWord(int color)
{
	RECT r = { x1, y1+5, x2, y2 };
	setbkmode(1);
	settextcolor(color);
	settextstyle(25, 0, "Algerian");//·½Õý´ÖºÚËÎ¼òÌåBritannic Bold
	drawtext(name, &r, DT_CENTER);
}

void button::loadButtonB()
{
	setlinecolor(BLUE);
	rectangle(x1, y1, x2, y2);
}

void button::loadButtonW()
{
	setlinecolor(LIGHTGREEN);
	rectangle(x1, y1, x2, y2);
}

int button::getx1()
{
	return x1;
}

int button::getx2()
{
	return x2;
}

int button::gety1()
{
	return y1;
}

int button::gety2()
{
	return y2;
}
