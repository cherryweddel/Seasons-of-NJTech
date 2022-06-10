#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"Movement.h"
#include"Season.h"
using namespace std;
#ifndef SUM
#define SUM
class Summer:public Season
{
	private:
		struct Rain
		{
			int	x;
			int	y;
			int	step;
			int	length;
			int cnt;
		}*rain1,*rain2;
		int MAXrain;
		void InitStar(int i,Rain* rain)
		{
			rain[i].x = rand() % 1080;
			rain[i].y = rand() % 100;
			if (rain == rain1)
				rain[i].step = rand() % 6 + 1;
			else
				rain[i].step = rand() % 3 + 1;
			rain[i].cnt = 0;
	
			rain[i].length = rand()%(rain[i].step*5)+ rain[i].step * 5-5;	// 速度越快，颜色越亮
			rain[i].cnt = 0;
		}
		void MoveStar(int i,Rain*rain)
		{
			rain[i].cnt++;
			setlinecolor(RGB(255, 255, 255));
			if (rain[i].cnt == 1)
			{
				rain[i].cnt = 0;
				rain[i].y += rain[i].step;
			}		
			if (rain[i].y > 708)	InitStar(i,rain);

			line(rain[i].x, rain[i].y, rain[i].x, rain[i].y + rain[i].length);
		}

	public:
		Summer(LPCTSTR a[], LPCTSTR b, int n, int T, int X, int Y, int M)
		:Season(a, b, n, T, X, Y)
		{
			MAXrain = M;
			if (rain1)
				delete[]rain1;
			rain1 = new Rain[MAXrain];
			if (rain2)
				delete[]rain2;
			rain2 = new Rain[MAXrain];
			for (int i = 0; i < MAXrain; i++)
				InitStar(i,rain1), InitStar(i, rain2);
		}
		~Summer()
		{
			if (rain1)
				delete[]rain1;
			if (rain2)
				delete[]rain2;
		}

		void Float()
		{
				putBack();
				//for (int i = 0; i < MAXrain; i++)
					//MoveStar(i,rain2);
				this->getMove().draw(false);
				for (int i = 0; i < MAXrain; i++)
					MoveStar(i,rain1);
			
		}
};


#endif
