#include "Rhombus.h"

using namespace std;

Rhombus::Rhombus(int tVertDiagonal, int tHorizDiagonal, int x, int y, RGBTRIPLE tbackground—olor, RGBTRIPLE tFrame—olor)
{

	vertDiagonal = tVertDiagonal;								//360
	horizDiagonal = tHorizDiagonal;								//400
	xCenter = x;												//480
	yCenter = y;												//240
	background—olor.rgbtRed = tbackground—olor.rgbtRed;			//255
	background—olor.rgbtGreen = tbackground—olor.rgbtGreen;		//0
	background—olor.rgbtBlue = tbackground—olor.rgbtBlue;		//0
	frame—olor.rgbtRed = tFrame—olor.rgbtRed;					//0
	frame—olor.rgbtGreen = tFrame—olor.rgbtGreen;				//255
	frame—olor.rgbtBlue = tFrame—olor.rgbtBlue;					//0
}
int Rhombus::GetVertDiagonal() { return vertDiagonal; };
int Rhombus::GetHorizDiagonal() { return horizDiagonal; };
RGBTRIPLE Rhombus::GetBackground—olor() { return background—olor; };
RGBTRIPLE Rhombus::GetFrame—olor() { return frame—olor; };
void Rhombus::SetVertDiagonal(int newVertDiagonal)
{
	vertDiagonal = newVertDiagonal;
}
void Rhombus::SetHorizDiagonal(int newHorizDiagonal)
{
	horizDiagonal = newHorizDiagonal;
}
void Rhombus::SetBackground—olor(BYTE red, BYTE green, BYTE blue)
{
	background—olor.rgbtRed = red;
	background—olor.rgbtGreen = green;
	background—olor.rgbtBlue = blue;
}
void Rhombus::SetFrame—olor(BYTE red, BYTE green, BYTE blue)
{
	frame—olor.rgbtRed = red;
	frame—olor.rgbtGreen = green;
	frame—olor.rgbtBlue = blue;
}
void Rhombus::SaveToFile()
{
	ofstream fileRomb;
	fileRomb.open("romb.txt");
	fileRomb.write((char*)&vertDiagonal, sizeof(vertDiagonal));
	fileRomb.write((char*)&horizDiagonal, sizeof(horizDiagonal));
	fileRomb.write((char*)&background—olor, sizeof(background—olor));
	fileRomb.write((char*)&frame—olor, sizeof(frame—olor));
	fileRomb.write((char*)&xCenter, sizeof(xCenter));
	fileRomb.write((char*)&yCenter, sizeof(yCenter));
	fileRomb.close();
}
void Rhombus::LoadFromFile()
{
	ifstream fileRomb;
	fileRomb.open("romb.txt");
	fileRomb.read((char*)&vertDiagonal, sizeof(vertDiagonal));
	fileRomb.read((char*)&horizDiagonal, sizeof(horizDiagonal));
	fileRomb.read((char*)&background—olor, sizeof(background—olor));
	fileRomb.read((char*)&frame—olor, sizeof(frame—olor));
	fileRomb.read((char*)&xCenter, sizeof(xCenter));
	fileRomb.read((char*)&yCenter, sizeof(yCenter));
	fileRomb.close();
}
void Rhombus::MoveX(int move)
{
	xCenter += move;
}
void Rhombus::MoveY(int move)
{
	yCenter += move;
}
int Rhombus::GetXCenter() { return xCenter; };
int Rhombus::GetYCenter() { return yCenter; };