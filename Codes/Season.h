#include<iostream>
#include <graphics.h>
#include"Movement.h"
using namespace std;
#ifndef SEASON
#define SEASON
class Season
{
	private:
		Movement move;
		IMAGE back;//����
	public:
		Movement& getMove()
		{
			return move;
		}
		Season(LPCTSTR a[], LPCTSTR b, int n, int T, int X, int Y)
		:move(a,b,n,T,X,Y)
		{loadimage(&back, b);}
		virtual void Float() = 0;
		virtual ~Season()
		{
			move.~Movement();//��Ա������?
		}	
		void putBack()
		{
			
			putimage(0, 0, &back);
			//move.draw();
			
		}
};
#endif