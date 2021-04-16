/**
 *@file:	draw.c
 *@author:	zju3180101729
 */

#include "game.h"

void FillSquare(double width, double height, double grayScale) {
	StartFilledRegion(grayScale);
	DrawLine(width, 0);
	DrawLine(0, height);
	DrawLine(-width, 0);
	DrawLine(0, -height);
	EndFilledRegion();
}
void ClearScreen() {
	MovePen(0, 0);
	FillSquare(GetWindowWidth(), GetWindowHeight(), 0);
}

void DrawLabels() {
	for(int i = 0; i < LABELNUM; ++i)
		if(isStatusExist(label[i].status))
			DrawLabel(label[i]);
}
void DrawButtons() {
	for(int i = 0; i < BUTTONNUM; ++i)
		if(isStatusExist(button[i].status))
			DrawButton(button[i]);
}
void DrawBoardFrame() {
	SetFont("Consolas");
	SetPointSize(24);
	double width = TextStringWidth("AAAAAAAAAAAA");
	SetPenColor("Button");
	SetPenSize(2);
	for(int i = 1; i <= BOARDSIZE; ++i) {
		MovePen(WIDTH / 2 - width - 0.1, 0.71 + i * (GetFontAscent() + 0.1));
		DrawLine(width * 2 + 0.2, 0);
	}
	SetPenColor("Black");
	SetPenSize(4);
	MovePen(WIDTH / 2 - width - 0.1, 0.7);
	DrawLine(width * 2 + 0.2, 0);
	DrawLine(0, 4.1);
	DrawLine(-width * 2 - 0.2, 0);
	DrawLine(0, -4.1);
}
void DrawBoard(Board board[]) {
	SetFont("Consolas");
	SetPointSize(24);
	SetPenColor("Button");
	char text[13];
	for(int i = 0; i < BOARDSIZE; ++i)
		if(boardScore[i].data) {
			MovePen(WIDTH / 2 - TextStringWidth("AAAAAAAAAAAA"), 0.8 + i * (GetFontAscent() + 0.1));
			sprintf(text, "%s", board[i].name);
			DrawTextString(text);
			MovePen(WIDTH / 2, 0.8 + i * (GetFontAscent() + 0.1));
			sprintf(text, "%12d", board[i].data);
			DrawTextString(text);
		}
}
void DrawScoreBoard() {
	DrawBoardFrame();
	DrawBoard(boardScore);
}
void DrawLineBoard() {
	DrawBoardFrame();
	DrawBoard(boardLine);
}
void DrawHelpPage() {
	SetFont("Consolas");
	SetPenColor("Black");
	SetPointSize(32);
	MovePen(0.1, 4.7);
	DrawTextString("ABOUT:");
	SetPointSize(18);
	MovePen(0.1, 4.5);
	DrawTextString("Tetris is a tile-matching puzzle video game");
	MovePen(0.1, 4.3);
	DrawTextString("designed and programmed by Soviet Russian");
	MovePen(0.1, 4.1);
	DrawTextString("game designer Alexey Leonidovich Pajitnov.");
	SetPointSize(32);
	MovePen(0.1, 3.7);
	DrawTextString("HOW TO PLAY:");
	SetPointSize(24);
	MovePen(0.1, 3.4);
	DrawTextString("1. MOVE");
	SetPointSize(18);
	MovePen(0.1, 3.2);
	DrawTextString("Press A(Left) and D(Right) to move the falling");
	MovePen(0.1, 3.0);
	DrawTextString("Tetrimino in the corresponding direction.");
	SetPointSize(24);
	MovePen(0.1, 2.7);
	DrawTextString("2. ROTATE");
	SetPointSize(18);
	MovePen(0.1, 2.5);
	DrawTextString("Press W(Up) to rotate and determine the best");
	MovePen(0.1, 2.3);
	DrawTextString("fit for the Tetrimino.");
	SetPointSize(24);
	MovePen(0.1, 2.0);
	DrawTextString("3. DROP");
	SetPointSize(18);
	MovePen(0.1, 1.8);
	DrawTextString("Press S(Down) to drop the Tetrimino into place.");
	SetPointSize(32);
	MovePen(0.1, 1.4);
	DrawTextString("GAMEPLAY INFO:");
	SetPointSize(18);
	MovePen(0.1, 1.2);
	DrawTextString("Drop Tetrimino, fill every square within a");
	MovePen(0.1, 1.0);
	DrawTextString("single row to clear a line and earn scores.");
	MovePen(0.1, 0.8);
	DrawTextString("Preview the upcoming Tetrimino to plan ahead.");
	MovePen(0.1, 0.6);
	DrawTextString("Stack the Tetriminos too high and Game Over!");
}
void DrawGamePlaneFrame() {
	SetPenSize(4);
	SetPenColor("Button");
	MovePen(17.0 / 96, 18.0 / 96);
	DrawLine(225.0 / 96, 0);
	DrawLine(0, 445.0 / 96);
	MovePen(18.0 / 96, 18.0 / 96);
	DrawLine(0, 445.0 / 96);
	DrawLine(-1.0 / 96, -1.0 / 96);
	DrawLine(225.0 / 96, 0);
}
void DrawGrids() {
	for(int i = 0; i < GAMEPLANEWIDTH; ++i)
		for(int j = 0; j < GAMEPLANEHEIGHT; ++j)
			if(grid[i][j].hasBlock)
				DrawGrid(grid[i][j]);
}
void DrawNextBlockFrame() {
	SetPenSize(4);
	SetPenColor("Button");
	MovePen(255.0 / 96, 462.0 / 96);
	DrawLine(213.0 / 96, 0);
	DrawLine(0, 1.0 / 96);
	DrawLine(0, -1);
	DrawLine(-213.0 / 96, 0);
	DrawLine(1.0 / 96, 0);
	DrawLine(0, 1);
}
void DrawNextBlockGrids() {
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(nextBlockGrid[i][j].hasBlock)
				DrawGrid(nextBlockGrid[i][j]);
}
void DrawTextBoxes() {
	for(int i = 0; i < TEXTBOXNUM; ++i)
		if(isStatusExist(textBox[i].status))
			DrawTextBox(textBox[i]);
}
void DrawElements() {
	for(int i = 0; i < ELEMENTNUM; ++i)
		if(isStatusExist(element[i].status))
			element[i].draw();
}
void DrawGame() {
	ClearScreen();
	SetPenColor("BackGround");
	FillSquare(WIDTH, HEIGHT, 1);
	DrawElements();
}

