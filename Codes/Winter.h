#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"Movement.h"
#include"Season.h"
using namespace std;
#ifndef WIN
#define WIN
class Winter: public Season
{
	private:
		struct Snow
		{
			int	x;
			int	y;
			int	step;
			int radui;
			int cnt;
		}*snow1,*snow2;
		int MAXsnow;
		void InitStar(int i,Snow*snow)
		{
			snow[i].x = rand() % 1080;
			snow[i].y = rand() % 100;
			if(snow==snow1)
				snow[i].radui = rand() % 6 + 4;
			else
				snow[i].radui = rand() % 3 + 1;
			snow[i].cnt = 0;
			snow[i].step = snow[i].radui;
			
		}
		void MoveStar(int i,Snow*snow)
		{
			setlinecolor(RGB(255, 255, 255));
			setfillcolor(RGB(255, 255, 255));
			snow[i].cnt++;
			if (snow[i].cnt == 10)
			{
				snow[i].y += snow[i].step;
				snow[i].cnt = 0;
			}
			
			if (snow[i].y > 708)	InitStar(i,snow);

			fillcircle((int)snow[i].x, snow[i].y, snow[i].radui);
		}
		

	public:
		Winter(LPCTSTR a[], LPCTSTR b, int n, int T, int X, int Y, int M)
		:Season(a, b, n, T, X, Y)
		{
			MAXsnow = M;
			if (snow1)
				delete[]snow1;
			snow1 = new Snow[MAXsnow];
			if (snow2)
				delete[]snow2;
			snow2 = new Snow[MAXsnow];
			for (int i = 0; i < MAXsnow; i++)
				InitStar(i,snow1),InitStar(i, snow2);

		}
		~Winter()
		{
			if (snow1)
				delete[]snow1;
			if (snow2)
				delete[]snow2;
		}

		void Float()
		{							
				putBack();
				for (int i = 0; i < MAXsnow; i++)
					MoveStar(i, snow2);
				this->getMove().draw();
				for (int i = 0; i < MAXsnow; i++)
					MoveStar(i,snow1);
		}
};


#endif
