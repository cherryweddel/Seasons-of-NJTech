#include<iostream>
#include <graphics.h>
using namespace std;
#ifndef MOVE
#define MOVE
class Movement
{
private:
	pair<IMAGE, IMAGE>* p;//��֡
	int num;//֡��
	int t;//�ӳٲ���
	int startX, startY;//�����������
	int x, y;//ʵʱ����
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
	void draw(bool flg = true, int stepx = 0)//flg����ģʽ��stepx X�ƶ�����
	{
		putimage(x, y, &p[i / t].first, SRCAND);
		putimage(x, y, &p[i / t].second, SRCPAINT);
		i += step;
		if (flg)
		{
			if (i == num * t)//˳��ѭ������
				i = 0;
		}
		else
			if (i == num * t || i == -1 * t)//����ѭ������
				step *= -1, i += step;

		//�ƶ�x
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
