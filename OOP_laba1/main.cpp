#define _CRT_SECURE_NO_WARNINGS
using namespace std;


#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "Rhombus.h"
#include "Draw.h"

void Test(int &x, int &y, int &v, int &h, Rhombus &romb, RECT rt)
{
	try
	{
		if (romb.GetXCenter() + x + h / 2 > rt.right || romb.GetXCenter() + x - h / 2 < rt.left || romb.GetYCenter() + y - v / 2 < rt.top || romb.GetYCenter() + y + v / 2 > rt.bottom)

		{
			throw 0;
		}
	}
	catch (int thr)
	{
		cout << "Ошибка: ромб за пределами окна. Координаты и диагонали не изменены" << endl;
		x = thr;
		y = thr;
		v = thr;
		h = thr;
	}
}
void Change(Rhombus &romb, RECT rt)
{
	int x, y, vertDiagonal, horizDiagonal;
	cout << "Введите смещение по x: ";
	cin >> x;
	cout << "Введите смещение по y: ";
	cin >> y;
	cout << "Введите диагональ по вертикали: ";
	cin >> vertDiagonal;
	cout << "Введите диагональ по горизонтали: ";
	cin >> horizDiagonal;
	int R, G, B;
	cout << "Меняем цвет заливки (RGB через пробел):";
	cin >> R >> G >> B;
	romb.SetBackgroundСolor(R, G, B);
	cout << "Меняем цвет границы (RGB через пробел):";
	cin >> R >> G >> B;
	Test(x, y, vertDiagonal, horizDiagonal, romb, rt);
	if (vertDiagonal != 0 || horizDiagonal != 0)
	{
		romb.SetVertDiagonal(vertDiagonal);
		romb.SetHorizDiagonal(horizDiagonal);
	}
	romb.SetFrameСolor(R, G, B);
	romb.MoveX(x);
	romb.MoveY(y);
}

void main()
{
	setlocale(LC_ALL, "rus");
	// получаем идентификатор окна
	HWND hwnd = GetConsoleWindow();
	// получаем контекст отображения
	HDC hdc = GetDC(hwnd);
	RECT rt;
	// получаем размер окна
	GetClientRect(hwnd, &rt);
	RGBTRIPLE backgroundСolor{ 255,0,0 };
	RGBTRIPLE frameСolor{ 0,255,0 };
	Rhombus romb(360, 400, 480, 240, backgroundСolor, frameСolor);
	romb.LoadFromFile();
	Draw paint;
	paint.RombDraw(&romb, hdc);
	do {
		cout << "Координаты центра: x= " << romb.GetXCenter() << " y= " << romb.GetYCenter() << endl;
		cout << "Длина диагонали по вертикали " << romb.GetVertDiagonal() << " по горизонтали " << romb.GetHorizDiagonal() << endl;
		Change(romb, rt);
		paint.RombDraw(&romb, hdc);
		cout << "esc - выход" << endl;
	} while (_getch() != 27);
	romb.SaveToFile();
	// освобождаем контекст отображения
	ReleaseDC (hwnd, hdc);
}