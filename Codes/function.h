#pragma once
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstring>
#include <Windows.h>
#include <Mmsystem.h>
#include<fstream>  
#include<stdio.h>
#include <cstring>
#pragma comment(lib,"winmm.lib")//播放音乐的库文件
#include"button.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
//num , t, startX, startY
//12, 75, -120, 175, 50
LPCTSTR spr[] = { "./kite/1_.png","./kite/1.png","./kite/2_.png", "./kite/2.png","./kite/3_.png","./kite/3.png",
"./kite/4_.png","./kite/4.png","./kite/5_.png","./kite/5.png","./kite/6_.png","./kite/6.png","./kite/7_.png",
"./kite/7.png","./kite/8_.png","./kite/8.png","./kite/9_.png","./kite/9.png","./kite/10_.png","./kite/10.png","./kite/11_.png","./kite/11.png","./kite/12_.png","./kite/12.png" };
//10, 75, -25, 200, 500
LPCTSTR sum[] = { "./sit/1_.png","./sit/1.png","./sit/2_.png", "./sit/2.png","./sit/3_.png","./sit/3.png",
"./sit/4_.png","./sit/4.png","./sit/5_.png","./sit/5.png","./sit/6_.png","./sit/6.png","./sit/7_.png",
"./sit/7.png","./sit/8_.png","./sit/8.png","./sit/9_.png","./sit/9.png","./sit/10_.png","./sit/10.png" };
//12, 75, -220, 170，40//stepx 1
LPCTSTR aut[] = { "./walk/1_.png","./walk/1.png","./walk/2_.png", "./walk/2.png","./walk/3_.png","./walk/3.png",
"./walk/4_.png","./walk/4.png","./walk/5_.png","./walk/5.png","./walk/6_.png","./walk/6.png","./walk/7_.png",
"./walk/7.png","./walk/8_.png","./walk/8.png","./walk/9_.png","./walk/9.png","./walk/10_.png","./walk/10.png","./walk/11_.png","./walk/11.png","./walk/12_.png","./walk/12.png" };
//8, 75, -50, 210
LPCTSTR win[] = { "./snowman/1_.png","./snowman/1.png","./snowman/2_.png", "./snowman/2.png",
"./snowman/3_.png","./snowman/3.png","./snowman/4_.png","./snowman/4.png","./snowman/5_.png","./snowman/5.png",
"./snowman/6_.png","./snowman/6.png","./snowman/7_.png","./snowman/7.png","./snowman/8_.png","./snowman/8.png" };
LPCTSTR Back1 = "./backgrounds/Spring.jpeg";
LPCTSTR Back2 = "./backgrounds/Summer.jpg";
LPCTSTR Back3 = "./backgrounds/Autumn.jpg";
LPCTSTR Back4 = "./backgrounds/Winter.jpg";

#define PI 3.14
void drawLogo(int color, LPCTSTR name)
{
	const POINT pts[] = { {1030, 628}, {1000, 658}, {1060, 658} };
	int c;
	double a;
	int x, y, rr = 30;
	setlinestyle(0, 4);
	for (a = 0; a < PI * 2 + 1.5; a += 0.1)
	{
		x = (int)(rr * cos(a) + 1030 + 0.5);
		y = (int)(rr * sin(a) + 658 + 0.5);
		c = (int)(a * 255 / PI + 0.5);
		setcolor(RGB(0, c, 225));
		line(1030, 658, x, y);
	}
	setlinestyle(0, 5);
	setlinecolor(LIGHTGREEN);
	polygon(pts, 3);
	setlinestyle(0, 2);
	setlinecolor(LIGHTBLUE);
	polygon(pts, 3);

	setlinestyle(0, 1);
	RECT r = { 1002, 660, 1060, 708 };
	RECT r_ = { 1000, 661, 1060, 708 };
	setbkmode(1);
	settextstyle(20, 0, "Arial Black");
	settextcolor(BLUE);
	drawtext("NJTech", &r_, DT_CENTER);

	settextcolor(LIGHTCYAN);
	settextstyle(19, 0, "Arial Black");
	drawtext("NJTech", &r, DT_CENTER);

	RECT r2 = { 910, 660, 980, 708 };
	setbkmode(1);

	settextcolor(color);
	settextstyle(22, 0, "方正粗黑宋简体");
	drawtext("啊对对队", &r2, DT_CENTER);

	RECT r3 = { 810, 660, 910, 708 };
	setbkmode(1);
	settextcolor(color);
	settextstyle(22, 0, "Arial Black");
	drawtext(name, &r3, DT_CENTER);

}


POINT p;
HWND h;
button autumn;
button spring;
button summer;
button winter;
button goBack;
int backx1 = 900;
int backx2 = 1020;
int backy1 = 50;
int backy2 = 85;

void cover(LPCTSTR address)
{
	IMAGE img;
	loadimage(&img, address, 1080, 708);
	putimage(0, 0, &img);
}

void beginBGM()
{
	mciSendString("open ./covers/cover.wav alias bgm type MPEGVideo", 0, 0, 0);//打开音乐文件
	//cout << mciError;
	mciSendString("play bgm repeat", 0, 0, 0);//播放音乐
	//cout << mciError;
}
void endBGM()
{
	mciSendString("close bgm", 0, 0, 0);//关闭音乐文件
}

void drawWord()
{
	settextstyle(40, 0, "方正舒体");//华文琥珀

	settextcolor(BLUE);
	setbkmode(1);
	outtextxy(421, 604, "一切的故事，从这封录取通知书开始...");
	settextstyle(40, 0, "方正舒体");//华文琥珀
	settextcolor(LIGHTCYAN);
	setbkmode(1);
	outtextxy(425, 600, "一切的故事，从这封录取通知书开始...");
}

void initButton()
{
	autumn.setImgAddress("./covers/autumn button.png");
	spring.setImgAddress("./covers/spring button.png");
	summer.setImgAddress("./covers/summer button.png");
	winter.setImgAddress("./covers/winter button.png");

	spring.setLocation(90, 95, 210, 130);
	summer.setLocation(90, 195, 210, 230);
	autumn.setLocation(90, 500, 210, 535);
	winter.setLocation(90, 600, 210, 635);
	goBack.setLocation(backx1, backy1, backx2, backy2);

	spring.setName("Spring");
	autumn.setName("Autumn");
	summer.setName("Summer");
	winter.setName("Winter");
	goBack.setName("Go Back");

	autumn.loadButtonImage();
	spring.loadButtonImage();
	summer.loadButtonImage();
	winter.loadButtonImage();

	autumn.drawButtonWord(WHITE);
	spring.drawButtonWord(BLUE);
	summer.drawButtonWord(BLUE);
	winter.drawButtonWord(WHITE);

}