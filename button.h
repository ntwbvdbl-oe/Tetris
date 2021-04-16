/**
 *@file:	button.h
 *@author:	zju3180101729
 */

#ifndef _BUTTON_H
#define _BUTTON_H

#include "libgraphics.h"

#define BUTTONFRAMEWIDTH 0.06

typedef struct {
	double x, y, width, height;
	string text, font;
	bool isUnderMouse;
	int status, pointSize;
}Button;

void DrawButton(Button button);

bool InButton(double x, double y, Button button);

#endif		//_BUTTON_H

