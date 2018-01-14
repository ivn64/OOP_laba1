#pragma once
#include <iostream>
#include <windows.h>
#include <windowsx.h>

#include "Rhombus.h"

class Draw
{
	Rhombus *romb;

public:
	void RombDraw(Rhombus *newRomb, HDC);
};