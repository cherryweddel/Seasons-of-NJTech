#include "function.h"
#include "Spring.h"
#include "Season.h"
#include "Summer.h"
#include "Autumn.h"
#include "Winter.h"
#pragma comment(lib,"winmm.lib")//�������ֵĿ��ļ�
using namespace std;
void While(Season* P, int butnc,int flg);
int main()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);
	
	SetWindowPos(initgraph(1080, 708), HWND_TOP, 350, 100, 1080, 708, SWP_NOSIZE);
start:
	beginBGM();//��ʼ��������
	cover("./covers/cover.jpg");//��ʾ����ͼƬ

	drawWord();//��ʾ����

	initButton();
	
	while (1) {//���水ťѭ��
		h = GetForegroundWindow();
		GetCursorPos(&p);
		ScreenToClient(h, &p);
		if (p.x >= autumn.getx1() && p.x <= autumn.getx2() && p.y >= autumn.gety1() && p.y <= autumn.gety2()) {//����
			autumn.loadButtonB();
			if (KEY_DOWN(VK_LBUTTON)) {		//�������������ʵ����Ӧ����.
				endBGM();//������������

				//��ʼ��������
				/*ʵ�ִ���*/
				Season* P = new Autumn(aut, Back3, 12, 38, -220, 170, 12);

				mciSendString("open ./music/autumn.wav alias aut type MPEGVideo", 0, 0, 0);//�������ļ�
				mciSendString("play aut repeat", 0, 0, 0);//��������

				While(P, YELLOW,3);

				mciSendString("close aut", 0, 0, 0);//�ر������ļ�
				goto start;
			}						
		}
		else if (p.x >= spring.getx1() && p.x <= spring.getx2() && p.y >= spring.gety1() && p.y <= spring.gety2())//����
		{
			spring.loadButtonB();
			if (KEY_DOWN(VK_LBUTTON)) {		//�������������ʵ����Ӧ����.
				endBGM();//������������
				//��ʼ��������
				/*ʵ�ִ���*/
				Season* P = new Spring(spr, Back1, 12, 40, -120, 175, 20);

				mciSendString("open ./music/spring.wav alias spr type MPEGVideo", 0, 0, 0);//�������ļ�
				mciSendString("play spr repeat", 0, 0, 0);//��������

				While(P, RED,1);

				mciSendString("close spr", 0, 0, 0);//�ر������ļ�
				goto start;
			}
		}
		else if (p.x >= summer.getx1() && p.x <= summer.getx2() && p.y >= summer.gety1() && p.y <= summer.gety2())//����
		{
			summer.loadButtonB();
			if (KEY_DOWN(VK_LBUTTON)) {		//�������������ʵ����Ӧ����.
				endBGM();//������������

				//��ʼ��������
				/*ʵ�ִ���*/
			
				Season* P = new Summer(sum, Back2, 10, 25, -25, 200, 300);
				
				mciSendString("open ./music/summer.wav alias sum type MPEGVideo", 0, 0, 0);//�������ļ�
				mciSendString("play sum repeat", 0, 0, 0);//��������

				While(P, LIGHTGREEN,2);
				
				mciSendString("close sum", 0, 0, 0);//�ر������ļ�
				goto start;
			}
		}
		else if (p.x >= winter.getx1() && p.x <= winter.getx2() && p.y >= winter.gety1() && p.y <= winter.gety2())//����
		{
			winter.loadButtonB();
			if (KEY_DOWN(VK_LBUTTON)) {		//�������������ʵ����Ӧ����.
				endBGM();//������������
				//��ʼ��������
				/*ʵ�ִ���*/

				//���ذ�ť��ʼ
				Season* P = new Winter(win, Back4, 8, 35, -50, 210, 75);

				mciSendString("open ./music/winter.wav alias win type MPEGVideo", 0, 0, 0);//�������ļ�
				mciSendString("play win repeat", 0, 0, 0);//��������

				While(P, WHITE,4);

				mciSendString("close win", 0, 0, 0);//�ر������ļ�
				goto start;				
			}

		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			autumn.loadButtonW();
			spring.loadButtonW();
			summer.loadButtonW();
			winter.loadButtonW();
		}
	}
	return 0;
}
void While(Season* P, int butnc,int flg)
{
	while (1) {
		//��������ѭ�������ݱ������������
		BeginBatchDraw();
		
		P->Float();

		goBack.drawButtonWord(butnc);
		//drawLogo(LIGHTRED, "��Spring��");
		switch (flg)
		{
		case 1:
			drawLogo(LIGHTGREEN, "��Spring��"); break;
		case 2:
			drawLogo(BLUE, "��Summer��"); break;
		case 3:
			drawLogo(LIGHTCYAN, "��Autumn��"); break;
		case 4:
			drawLogo(BLUE, "��Winter��"); break;
		default:
			break;
		}
		//���ذ�ť��ʼ
		h = GetForegroundWindow();
		GetCursorPos(&p);
		ScreenToClient(h, &p);
		if (p.x >= backx1 && p.x <= backx2 && p.y >= backy1 && p.y <= backy2) {

			goBack.loadButtonB();
			if (KEY_DOWN(VK_LBUTTON)) {		//�������������ʵ����Ӧ����.��

				EndBatchDraw();
				return;

			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			goBack.loadButtonW();
		}
		EndBatchDraw();
	}//���ذ�ť����
}