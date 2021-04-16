/**
 *@file:	main.c
 *@author:	zju3180101729
 */

#include "game.h"

void Main() {
	SetWindowTitle("Tetris");
	SetWindowSize(WIDTH, HEIGHT);
	InitGraphics();
	//InitConsole();
	InitGame();
	DrawGame();
}

