#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"Movement.h"
#include"Season.h"
using namespace std;
#ifndef AUT
#define AUT
class Autumn :public Season
{
private:
	struct Leaf
	{
		int	x;
		int	y;
		int	step;
		int cnt;
	}*leaf1, * leaf2;
	int MAXleaf;
	pair<IMAGE, IMAGE>img[6];
	void InitStar(int i, Leaf* leaf)
	{
		leaf[i].x = rand() % 1080;
		leaf[i].y = rand() % 100;
		if (leaf == leaf1)
			leaf[i].step = rand() % 6 + 4;
		else
			leaf[i].step = rand() % 3 + 1;
		leaf[i].cnt = 0;
	}

	void MoveStar(int i, Leaf* leaf)
	{
		leaf[i].cnt++;
		if (leaf[i].cnt == 10)
		{
			leaf[i].y += leaf[i].step;  //ÏÂÂä·ù¶È
			leaf[i].cnt = 0;
		}

		if (leaf[i].y > 708)	InitStar(i, leaf);

		putimage(leaf[i].x, leaf[i].y, &img[leaf[i].step - 1].first, SRCAND);
		putimage(leaf[i].x, leaf[i].y, &img[leaf[i].step - 1].second, SRCPAINT);
	}
public:
	Autumn(LPCTSTR a[], LPCTSTR b, int n, int T, int X, int Y, int M)
		:Season(a, b, n, T, X, Y)
	{
		MAXleaf = M;
		if (leaf1)
			delete[]leaf1;
		leaf1 = new Leaf[MAXleaf];
		if (leaf2)
			delete[]leaf2;
		leaf2 = new Leaf[MAXleaf];
		for (int i = 0; i < MAXleaf; i++)
			InitStar(i, leaf1), InitStar(i, leaf2);
		
		loadimage(&img[0].first, "./leaf/1_.png");
		loadimage(&img[0].second, "./leaf/1.png");
		loadimage(&img[1].first, "./leaf/2_.png");
		loadimage(&img[1].second, "./leaf/2.png");
		loadimage(&img[2].first, "./leaf/3_.png");
		loadimage(&img[2].second, "./leaf/3.png");
		loadimage(&img[3].first, "./leaf/4_.png");
		loadimage(&img[3].second, "./leaf/4.png");
		loadimage(&img[4].first, "./leaf/5_.png");
		loadimage(&img[4].second, "./leaf/5.png");
		loadimage(&img[5].first, "./leaf/6_.png");
		loadimage(&img[5].second, "./leaf/6.png");
	}
	~Autumn()
	{
		if (leaf1)
			delete[]leaf1;
		if (leaf2)
			delete[]leaf2;
	}
	void Float()
	{
		putBack();
		for (int i = 0; i < MAXleaf; i++)
			MoveStar(i, leaf2);
		this->getMove().draw(1, 1);
		for (int i = 0; i < MAXleaf; i++)
			MoveStar(i, leaf1);
	}
};


#endif
