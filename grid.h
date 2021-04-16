/**
 *@file:	grid.h
 *@author:	zju3180101729
 */

#ifndef _GRID_H
#define _GRID_H

#include "libgraphics.h"

typedef struct {
	double x, y, size;
	string color;
	bool hasBlock;
}Grid;

void DrawGrid(Grid);

#endif		//_GRID_H

