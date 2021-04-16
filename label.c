/**
 *@file:	label.c
 *@author:	zju3180101729
 */

#include "label.h"

void DrawLabel(Label label) {
	SetFont(label.font);
	SetPointSize(label.pointSize);
	SetPenColor(label.color);
	MovePen(label.x + LABELFRAMEWIDTH, label.y + LABELFRAMEWIDTH + (GetFontAscent() + GetFontDescent()) / 8);
	DrawTextString(label.text);
}

