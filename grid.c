/**
 *@file:	grid.c
 *@author:	zju3180101729
 */

#include "grid.h"

void DrawGrid(Grid grid) {
	SetPenColor(grid.color);
	SetPenSize(1);
	StartFilledRegion(1);
	MovePen(grid.x, grid.y);
	DrawLine(grid.size, 0);
	DrawLine(0, grid.size);
	DrawLine(-grid.size, 0);
	DrawLine(0, -grid.size);
	EndFilledRegion();
	///*
	SetPenSize(1);
	SetPenColor("Black");
	MovePen(grid.x, grid.y);
	DrawLine(grid.size, 0);
	DrawLine(0, grid.size);
	DrawLine(-grid.size, 0);
	DrawLine(0, -grid.size);
	//*/
}

