#include "Draw.h"

using namespace std;

void Draw::RombDraw(Rhombus *romb, HDC hdc)
{
	RGBTRIPLE frameСolor = romb->GetFrameСolor();
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(frameСolor.rgbtRed, frameСolor.rgbtGreen, frameСolor.rgbtBlue));
	// и выбираем его в контекст отображения,
	// сохраняя предыдущее перо
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	RGBTRIPLE backgroundСolor = romb->GetBackgroundСolor();
	// создаем зеленую кисть
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(backgroundСolor.rgbtRed, backgroundСolor.rgbtGreen, backgroundСolor.rgbtBlue));
	// и выбираем ее в контекст отображения,
	// сохраняя предыдущую кисть
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	int vertDiagonal = romb->GetVertDiagonal();
	int horizDiagonal = romb->GetHorizDiagonal();
	POINT ppt[4] = { { romb->GetXCenter() - horizDiagonal / 2,	romb->GetYCenter() },{ romb->GetXCenter(),	romb->GetYCenter() - vertDiagonal / 2 },{ romb->GetXCenter() + horizDiagonal / 2,	romb->GetYCenter() },{ romb->GetXCenter(),	romb->GetYCenter() + vertDiagonal / 2 } };
	Polygon(hdc, ppt, 4);
	// выбираем в контекст отображения предыдущее перо 
	SelectPen(hdc, hOldPen);
	// выбираем в контекст отображения предыдущую кисть 
	SelectBrush(hdc, hOldBrush);
	// удаляем красное перо
	DeletePen(hRedPen);
	// удаляем зеленую кисть
	DeleteBrush(hGreenBrush);
}