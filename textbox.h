/**
 *@file:	textbox.h
 *@author:	zju3180101729
 */

#ifndef _TEXTBOX_H
#define _TEXTBOX_H

#include "list.h"
#include "libgraphics.h"

#define TEXTBOXFRAMEWIDTH 0.06

typedef struct TextBox {
	double x, y, width, height;
	int maxSize, pointSize, status;
	bool isFlashing;
	string font;
	List *list;
}TextBox;

void DrawTextBox(TextBox textBox);
string toString(TextBox textBox);

#endif		//_TEXTBOX_H

