/**
 *@file:	button.c
 *@author:	zju3180101729
 */

#include "button.h"

void DrawButton(Button button) {
	SetPenColor(button.isUnderMouse ? "Black" : "Button");
	SetPenSize(2);
	MovePen(button.x, button.y);
	DrawLine(button.width, 0);
	DrawLine(0, button.height);
	DrawLine(-button.width, 0);
	DrawLine(0, -button.height);
	SetFont(button.font);
	SetPointSize(button.pointSize);
	MovePen(button.x + BUTTONFRAMEWIDTH, button.y + BUTTONFRAMEWIDTH + (GetFontAscent() + GetFontDescent()) / 8);
	DrawTextString(button.text);
}

bool InButton(double x, double y, Button button) {
	return x >= button.x && x <= button.x + button.width &&
		   y >= button.y && y <= button.y + button.height;
}

