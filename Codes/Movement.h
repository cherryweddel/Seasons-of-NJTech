#include<iostream>
#include <graphics.h>
using namespace std;
#ifndef MOVE
#define MOVE
class Movement
{
private:
	pair<IMAGE, IMAGE>* p;//存帧
	int num;//帧数
	int t;//延迟参数
	int startX, startY;//动画输出坐标
	int x, y;//实时坐标
	int i;
	int cntx;
	int step;
public:
	Movement(LPCTSTR a[], LPCTSTR b, int n, int T, int X, int Y)
	{
		num = n;
		t = T;
		startX = X;
		startY = Y;
		x = X;
		y = Y;
		i = 0;
		cntx = 0;
		step = 1;
		if (p)
			delete[]p;
		p = new pair<IMAGE, IMAGE>[num];

		int cnt = 0, ia = 0;
		while (ia < num * 2)
		{
			loadimage(&p[cnt].first, a[ia++]);
			loadimage(&p[cnt].second, a[ia++]);
			cnt++;
		}
		
	}
	~Movement()
	{
		if (p)
			delete[]p;
	}
	void draw(bool flg = true, int stepx = 0)//flg播放模式，stepx X移动步长
	{
		putimage(x, y, &p[i / t].first, SRCAND);
		putimage(x, y, &p[i / t].second, SRCPAINT);
		i += step;
		if (flg)
		{
			if (i == num * t)//顺序循环播放
				i = 0;
		}
		else
			if (i == num * t || i == -1 * t)//来回循环播放
				step *= -1, i += step;

		//移动x
		cntx++;
		if (cntx ==5)
		{
			x += stepx;
			cntx = 0;
		}
		if (x == 1080 && stepx != 0)
			x = startX;
	}
};
#endif
