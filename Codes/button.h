#pragma once
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstring>
#include <Windows.h>
#include <Mmsystem.h>
#include<fstream>  
class button
{
public:
	void setImgAddress(LPCTSTR);
	void setName(LPCTSTR);
	void setLocation(int, int, int, int);
	void loadButtonImage();
	void drawButtonWord(int);
	void loadButtonB();
	void loadButtonW();
	int getx1();
	int getx2();
	int gety1();
	int gety2();
private:
	IMAGE img;
	LPCTSTR imgAddress;
	LPCTSTR name;
	int x1, x2, y1, y2;
};

