#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"Movement.h"
#include"Season.h"
using namespace std;
#ifndef SPR
#define SPR
class Spring:public Season
{
private:
	struct Flower
	{
		int	x;
		int	y;
		int	step;
		int cnt;
	}*flower1,*flower2;
	int MAXflower;
	pair<IMAGE, IMAGE>img[6];
	void InitStar(int i,Flower*flower)
	{
		flower[i].x = rand() % 1080;
		flower[i].y = rand() % 100;
		if(flower==flower1)
			flower[i].step = rand() % 6 + 4;
		else
			flower[i].step = rand() % 3 + 1;
		flower[i].cnt = 0;
	}
	void MoveStar(int i,Flower*flower)
	{
		flower[i].cnt++;
		if (flower[i].cnt == 9)
		{
			flower[i].y += flower[i].step;  //ÏÂÂä·ù¶È
			flower[i].cnt = 0;
		}
		if (flower[i].y > 708)	InitStar(i,flower);

		putimage(flower[i].x, flower[i].y, &img[flower[i].step - 1].first, SRCAND);
		putimage(flower[i].x, flower[i].y, &img[flower[i].step - 1].second, SRCPAINT);
	}
public:
	Spring(LPCTSTR a[], LPCTSTR b, int n, int T, int X, int Y,int M)
	:Season(a, b, n, T, X, Y)
	{
		MAXflower = M;
		if (flower1)
			delete []flower1;
		flower1 = new Flower[MAXflower];
		if (flower2)
			delete[]flower2;
		flower2 = new Flower[MAXflower];
		for (int i = 0; i < MAXflower; i++)
			InitStar(i,flower1), InitStar(i, flower2);
		loadimage(&img[0].first, "./flower/1_.png");
		loadimage(&img[0].second, "./flower/1.png");
		loadimage(&img[1].first, "./flower/2_.png");
		loadimage(&img[1].second, "./flower/2.png");
		loadimage(&img[2].first, "./flower/3_.png");
		loadimage(&img[2].second, "./flower/3.png");
		loadimage(&img[3].first, "./flower/4_.png");
		loadimage(&img[3].second, "./flower/4.png");
		loadimage(&img[4].first, "./flower/5_.png");
		loadimage(&img[4].second, "./flower/5.png");
		loadimage(&img[5].first, "./flower/6_.png");
		loadimage(&img[5].second, "./flower/6.png");
	}
	~Spring()
	{
		if (flower1)
			delete[]flower1;		
		if (flower2)
			delete[]flower2;		
	}
	void Float()
	{
			putBack();
			for (int i = 0; i < MAXflower; i++)
				MoveStar(i, flower2);
			this->getMove().draw();
			for (int i = 0; i < MAXflower; i++)
				MoveStar(i,flower1);					
	}
};


#endif
