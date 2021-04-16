/**
 *@file:	label.h
 *@author:	zju3180101729
 */

#ifndef _LABEL_H
#define _LABEL_H

#include "libgraphics.h"

#define LABELFRAMEWIDTH 0.06

typedef struct {
	double x, y, width, height;
	string text, font, color;
	int status, pointSize;
}Label;

void DrawLabel(Label);

#endif		//_LABEL_H

