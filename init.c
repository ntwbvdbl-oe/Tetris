/**
 *@file:	init.c
 *@author:	zju3180101729
 */

#include "game.h"

void InitColor() {
	DefineColor("Orange", 255.0 / 255, 102.0 / 255, 0);
	DefineColor("BackGround", 221.0 / 255, 238.0 / 255, 255.0 / 255);
	DefineColor("GameBackGround", 190.0 / 255, 207.0 / 255, 234.0 / 255);
	DefineColor("Button", 119.0 / 255, 136.0 / 255, 170.0 / 255);
}
void InitLabel() {
	//menuTitleLabel
	SetFont("Consolas");
	SetPointSize(60);
	menuTitleLabel.width = TextStringWidth("Tetris") + LABELFRAMEWIDTH * 2;
	menuTitleLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	menuTitleLabel.x = (WIDTH - menuTitleLabel.width) / 2;
	menuTitleLabel.y = 3.0;
	menuTitleLabel.text = "Tetris";
	menuTitleLabel.font = "Consolas";
	menuTitleLabel.color = "Button";
	menuTitleLabel.status = menuStatus;
	menuTitleLabel.pointSize = 60;
	//menuLevelLabel
	SetFont("Consolas");
	SetPointSize(24);
	menuLevelLabel.width = TextStringWidth("LEVEL 0") + LABELFRAMEWIDTH * 2;
	menuLevelLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	menuLevelLabel.x = (WIDTH - menuLevelLabel.width) / 2;
	menuLevelLabel.y = HEIGHT / 2 - menuLevelLabel.height * 5 / 2 - 0.2;
	menuLevelLabel.text = (string)malloc(8);
	menuLevelLabel.font = "Consolas";
	menuLevelLabel.color = "Button";
	menuLevelLabel.status = menuStatus;
	menuLevelLabel.pointSize = 24;
	//boardScoreLabel
	SetFont("Consolas");
	SetPointSize(36);
	boardScoreLabel.width = TextStringWidth("SCORE") + LABELFRAMEWIDTH * 2;
	boardScoreLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	boardScoreLabel.x = 0.8;
	boardScoreLabel.y = 4.19;
	boardScoreLabel.text = "SCORE";
	boardScoreLabel.font = "Consolas";
	boardScoreLabel.color = "Black";
	boardScoreLabel.status = boardScoreStatus;
	boardScoreLabel.pointSize = 36;
	//boardLineLabel
	SetFont("Consolas");
	SetPointSize(36);
	boardLineLabel.width = TextStringWidth("LINE") + LABELFRAMEWIDTH * 2;
	boardLineLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	boardLineLabel.x = boardScoreLabel.x;
	boardLineLabel.y = boardScoreLabel.y;
	boardLineLabel.text = "LINE";
	boardLineLabel.font = "Consolas";
	boardLineLabel.color = "Black";
	boardLineLabel.status = boardLineStatus;
	boardLineLabel.pointSize = 36;
	//gameLevelLabel
	SetFont("Consolas");
	SetPointSize(36);
	gameLevelLabel.width = TextStringWidth("LEVEL     0") + LABELFRAMEWIDTH * 2;
	gameLevelLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gameLevelLabel.x = 246.0 / 96;
	gameLevelLabel.y = 366.0 / 96 - 0.1 - gameLevelLabel.height;
	gameLevelLabel.text = (string)malloc(8);
	gameLevelLabel.font = "Consolas";
	gameLevelLabel.color = "Black";
	gameLevelLabel.status = gameRunningStatus + gameOverStatus + gamePauseStatus + gameQuitStatus;
	gameLevelLabel.pointSize = 36;
	//gameLineLabel
	SetFont("Consolas");
	SetPointSize(36);
	gameLineLabel.width = TextStringWidth("LINE  99999") + LABELFRAMEWIDTH * 2;
	gameLineLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gameLineLabel.x = gameLevelLabel.x;
	gameLineLabel.y = gameLevelLabel.y - 0.1 - gameLineLabel.height;
	gameLineLabel.text = (string)malloc(12);
	gameLineLabel.font = "Consolas";
	gameLineLabel.color = "Black";
	gameLineLabel.status = gameRunningStatus + gameOverStatus + gamePauseStatus + gameQuitStatus;
	gameLineLabel.pointSize = 36;
	//gameScoreLabel
	SetFont("Consolas");
	SetPointSize(36);
	gameScoreLabel.width = TextStringWidth("SCORE 99999") + LABELFRAMEWIDTH * 2;
	gameScoreLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gameScoreLabel.x = gameLevelLabel.x;
	gameScoreLabel.y = gameLineLabel.y - 0.1 - gameScoreLabel.height;
	gameScoreLabel.text = (string)malloc(12);
	gameScoreLabel.font = "Consolas";
	gameScoreLabel.color = "Black";
	gameScoreLabel.status = gameRunningStatus + gameOverStatus + gamePauseStatus + gameQuitStatus;
	gameScoreLabel.pointSize = 36;
	//gameTitleLabel
	SetFont("Consolas");
	SetPointSize(60);
	gameTitleLabel.width = TextStringWidth("Tetris") + LABELFRAMEWIDTH * 2;
	gameTitleLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gameTitleLabel.x = 2.69;
	gameTitleLabel.y = 0.1;
	gameTitleLabel.text = "Tetris";
	gameTitleLabel.font = "Consolas";
	gameTitleLabel.color = "Button";
	gameTitleLabel.status = gameRunningStatus + gameOverStatus + gamePauseStatus + gameQuitStatus;
	gameTitleLabel.pointSize = 60;
	//gameOverLabel
	SetFont("Consolas");
	SetPointSize(36);
	gameOverLabel.width = TextStringWidth("Game Over") + LABELFRAMEWIDTH * 2;
	gameOverLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gameOverLabel.x = 0.37;
	gameOverLabel.y = 2.8;
	gameOverLabel.text = "Game Over";
	gameOverLabel.font = "Consolas";
	gameOverLabel.color = "Black";
	gameOverLabel.status = gameOverStatus;
	gameOverLabel.pointSize = 36;
	//gameOverTextBoxLabel
	SetFont("Consolas");
	SetPointSize(24);
	gameOverTextBoxLabel.width = TextStringWidth("Your Name:") + LABELFRAMEWIDTH * 2;
	gameOverTextBoxLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gameOverTextBoxLabel.x = 0.4;
	gameOverTextBoxLabel.y = 2.33;
	gameOverTextBoxLabel.text = "Your Name:";
	gameOverTextBoxLabel.font = "Consolas";
	gameOverTextBoxLabel.color = "Black";
	gameOverTextBoxLabel.status = gameOverStatus;
	gameOverTextBoxLabel.pointSize = 24;
	//gamePauseLabel
	SetFont("Consolas");
	SetPointSize(36);
	gamePauseLabel.width = TextStringWidth("PAUSE") + LABELFRAMEWIDTH * 2;
	gamePauseLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gamePauseLabel.x = 0.77;
	gamePauseLabel.y = (HEIGHT - gamePauseLabel.height) / 2;
	gamePauseLabel.text = "PAUSE";
	gamePauseLabel.font = "Consolas";
	gamePauseLabel.color = "Button";
	gamePauseLabel.status = gamePauseStatus;
	gamePauseLabel.pointSize = 36;
	//gameQuitLabel
	SetFont("Consolas");
	SetPointSize(36);
	gameQuitLabel.width = TextStringWidth("QUIT GAME?") + LABELFRAMEWIDTH * 2;
	gameQuitLabel.height = GetFontAscent() + LABELFRAMEWIDTH * 2;
	gameQuitLabel.x = 0.26;
	gameQuitLabel.y = 2.8;
	gameQuitLabel.text = "QUIT GAME?";
	gameQuitLabel.font = "Consolas";
	gameQuitLabel.color = "Black";
	gameQuitLabel.status = gameQuitStatus;
	gameQuitLabel.pointSize = 36;
}
void InitButton() { 
    //menuStartButton
	SetFont("Consolas");
	SetPointSize(24);
	menuStartButton.width = TextStringWidth("START") + BUTTONFRAMEWIDTH * 2;
	menuStartButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	menuStartButton.x = (WIDTH - menuStartButton.width) / 2;
	menuStartButton.y = (HEIGHT - menuStartButton.height) / 2;
	menuStartButton.text = "START";
	menuStartButton.font = "Consolas";
	menuStartButton.isUnderMouse = 0;
	menuStartButton.status = menuStatus;
	menuStartButton.pointSize = 24;
	//menuContinueButton
	SetFont("Consolas");
	SetPointSize(24);
	menuContinueButton.width = TextStringWidth("CONTINUE") + BUTTONFRAMEWIDTH * 2;
	menuContinueButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	menuContinueButton.x = (WIDTH - menuContinueButton.width) / 2;
	menuContinueButton.y = HEIGHT / 2 - menuStartButton.height * 3 / 2 - 0.1;
	menuContinueButton.text = "CONTINUE";
	menuContinueButton.font = "Consolas";
	menuContinueButton.isUnderMouse = 0;
	menuContinueButton.status = menuStatus;
	menuContinueButton.pointSize = 24;
	//menuSubButton
	SetFont("Consolas");
	SetPointSize(24);
	menuSubButton.width = TextStringWidth("-") + BUTTONFRAMEWIDTH * 2;
	menuSubButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	menuSubButton.x = menuLevelLabel.x - menuSubButton.width - 0.1;
	menuSubButton.y = HEIGHT / 2 - menuSubButton.height * 5 / 2 - 0.2;
	menuSubButton.text = "-";
	menuSubButton.font = "Consolas";
	menuSubButton.isUnderMouse = 0;
	menuSubButton.status = menuStatus;
	menuSubButton.pointSize = 24;
	//menuAddButton
	SetFont("Consolas");
	SetPointSize(24);
	menuAddButton.width = TextStringWidth("+") + BUTTONFRAMEWIDTH * 2;
	menuAddButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	menuAddButton.x = menuLevelLabel.x + menuLevelLabel.width + 0.1;
	menuAddButton.y = HEIGHT / 2 - menuAddButton.height * 5 / 2 - 0.2;
	menuAddButton.text = "+";
	menuAddButton.font = "Consolas";
	menuAddButton.isUnderMouse = 0;
	menuAddButton.status = menuStatus;
	menuAddButton.pointSize = 24;
	//menuBoardButton
	SetFont("Consolas");
	SetPointSize(24);
	menuBoardButton.width = TextStringWidth("BOARD") + BUTTONFRAMEWIDTH * 2;
	menuBoardButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	menuBoardButton.x = (WIDTH - menuBoardButton.width) / 2;
	menuBoardButton.y = HEIGHT / 2 - menuBoardButton.height * 7 / 2 - 0.3;
	menuBoardButton.text = "BOARD";
	menuBoardButton.font = "Consolas";
	menuBoardButton.isUnderMouse = 0;
	menuBoardButton.status = menuStatus;
	menuBoardButton.pointSize = 24;
	//menuHelpButton
	SetFont("Consolas");
	SetPointSize(24);
	menuHelpButton.width = TextStringWidth("HELP") + BUTTONFRAMEWIDTH * 2;
	menuHelpButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	menuHelpButton.x = (WIDTH - menuHelpButton.width) / 2;
	menuHelpButton.y = HEIGHT / 2 - menuHelpButton.height * 9 / 2 - 0.4;
	menuHelpButton.text = "HELP";
	menuHelpButton.font = "Consolas";
	menuHelpButton.isUnderMouse = 0;
	menuHelpButton.status = menuStatus;
	menuHelpButton.pointSize = 24;
	//menuBackButton
	SetFont("Consolas");
	SetPointSize(24);
	menuBackButton.width = TextStringWidth("BACK") + BUTTONFRAMEWIDTH * 2;
	menuBackButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	menuBackButton.x = (WIDTH - menuBackButton.width) / 2;
	menuBackButton.y = HEIGHT / 2 - menuBackButton.height * 11 / 2 - 0.5;
	menuBackButton.text = "BACK";
	menuBackButton.font = "Consolas";
	menuBackButton.isUnderMouse = 0;
	menuBackButton.status = boardScoreStatus + boardLineStatus + helpPageStatus;
	menuBackButton.pointSize = 24;
	//boardScoreButton
	SetFont("Consolas");
	SetPointSize(24);
	boardScoreButton.width = TextStringWidth("SCORE") + BUTTONFRAMEWIDTH * 2;
	boardScoreButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	boardScoreButton.x = WIDTH / 2 + TextStringWidth("AAAAAAAAAAAA") - boardScoreButton.width;
	boardScoreButton.y = 4.24;
	boardScoreButton.text = "SCORE";
	boardScoreButton.font = "Consolas";
	boardScoreButton.isUnderMouse = 0;
	boardScoreButton.status = boardLineStatus;
	boardScoreButton.pointSize = 24;
	//boardLineButton
	SetFont("Consolas");
	SetPointSize(24);
	boardLineButton.width = TextStringWidth("LINE") + BUTTONFRAMEWIDTH * 2;
	boardLineButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	boardLineButton.x = WIDTH / 2 + TextStringWidth("AAAAAAAAAAAA") - boardLineButton.width;
	boardLineButton.y = boardScoreButton.y;
	boardLineButton.text = "LINE";
	boardLineButton.font = "Consolas";
	boardLineButton.isUnderMouse = 0;
	boardLineButton.status = boardScoreStatus;
	boardLineButton.pointSize = 24;
	//gameQuitButton
	SetFont("Consolas");
	SetPointSize(24);
	gameQuitButton.width = TextStringWidth("QUIT") + BUTTONFRAMEWIDTH * 2;
	gameQuitButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameQuitButton.x = 4.0677;
	gameQuitButton.y = gameScoreLabel.y - 0.1 - gameQuitButton.height;
	gameQuitButton.text = "QUIT";
	gameQuitButton.font = "Consolas";
	gameQuitButton.isUnderMouse = 0;
	gameQuitButton.status = gameRunningStatus + gamePauseStatus + gameQuitStatus;
	gameQuitButton.pointSize = 24;
	//gamePauseButton
	SetFont("Consolas");
	SetPointSize(24);
	gamePauseButton.width = TextStringWidth("PAUSE") + BUTTONFRAMEWIDTH * 2;
	gamePauseButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gamePauseButton.x = 4.0;
	gamePauseButton.y = 0.87;
	gamePauseButton.text = "PAUSE";
	gamePauseButton.font = "Consolas";
	gamePauseButton.isUnderMouse = 0;
	gamePauseButton.status = gameRunningStatus + gamePauseStatus + gameQuitStatus;
	gamePauseButton.pointSize = 24;
	//gameYesButton
	SetFont("Consolas");
	SetPointSize(24);
	gameYesButton.width = TextStringWidth("YES") + BUTTONFRAMEWIDTH * 2;
	gameYesButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameYesButton.x = gameQuitLabel.x + gameQuitLabel.width / 2 - 0.1 - gameYesButton.width;
	gameYesButton.y = 2 * gamePauseLabel.y - gameOverLabel.y + gamePauseLabel.height - gameYesButton.height;
	gameYesButton.text = "YES";
	gameYesButton.font = "Consolas";
	gameYesButton.isUnderMouse = 0;
	gameYesButton.status = gameQuitStatus;
	gameYesButton.pointSize = 24;
	//gameNoButton
	SetFont("Consolas");
	SetPointSize(24);
	gameNoButton.width = TextStringWidth("NO") + BUTTONFRAMEWIDTH * 2;
	gameNoButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameNoButton.x = gameQuitLabel.x + gameQuitLabel.width / 2 + 0.1;
	gameNoButton.y = 2 * gamePauseLabel.y - gameOverLabel.y + gamePauseLabel.height - gameNoButton.height;
	gameNoButton.text = "NO";
	gameNoButton.font = "Consolas";
	gameNoButton.isUnderMouse = 0;
	gameNoButton.status = gameQuitStatus;
	gameNoButton.pointSize = 24;
	//gameOkButton
	SetFont("Consolas");
	SetPointSize(24);
	gameOkButton.width = TextStringWidth("OK") + BUTTONFRAMEWIDTH * 2;
	gameOkButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameOkButton.x = 1.16;
	gameOkButton.y = 1;
	gameOkButton.text = "OK";
	gameOkButton.font = "Consolas";
	gameOkButton.isUnderMouse = 0;
	gameOkButton.status = gameOverStatus;
	gameOkButton.pointSize = 24;
	//gameUpButton
	SetFont("Consolas");
	SetPointSize(24);
	gameUpButton.width = TextStringWidth("W") + BUTTONFRAMEWIDTH * 2;
	gameUpButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameUpButton.x = 4.0677 - 0.9;
	gameUpButton.y = gameScoreLabel.y - 0.1 - gameQuitButton.height;
	gameUpButton.text = "W";
	gameUpButton.font = "Consolas";
	gameUpButton.isUnderMouse = 0;
	gameUpButton.status = gameRunningStatus + gamePauseStatus + gameQuitStatus;
	gameUpButton.pointSize = 24;
	//gameDownButton
	SetFont("Consolas");
	SetPointSize(24);
	gameDownButton.width = TextStringWidth("S") + BUTTONFRAMEWIDTH * 2;
	gameDownButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameDownButton.x = 4.0677 - 0.9;
	gameDownButton.y = 0.87;
	gameDownButton.text = "S";
	gameDownButton.font = "Consolas";
	gameDownButton.isUnderMouse = 0;
	gameDownButton.status = gameRunningStatus + gamePauseStatus + gameQuitStatus;
	gameDownButton.pointSize = 24;
	//gameLeftButton
	SetFont("Consolas");
	SetPointSize(24);
	gameLeftButton.width = TextStringWidth("A") + BUTTONFRAMEWIDTH * 2;
	gameLeftButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameLeftButton.x = 4.0677 - 1.3;
	gameLeftButton.y = (gameUpButton.y + gameDownButton.y) / 2;
	gameLeftButton.text = "A";
	gameLeftButton.font = "Consolas";
	gameLeftButton.isUnderMouse = 0;
	gameLeftButton.status = gameRunningStatus + gamePauseStatus + gameQuitStatus;
	gameLeftButton.pointSize = 24;
	//gameRightButton
	SetFont("Consolas");
	SetPointSize(24);
	gameRightButton.width = TextStringWidth("D") + BUTTONFRAMEWIDTH * 2;
	gameRightButton.height = GetFontAscent() + BUTTONFRAMEWIDTH * 2;
	gameRightButton.x = 4.0677 - 0.5;
	gameRightButton.y = (gameUpButton.y + gameDownButton.y) / 2;
	gameRightButton.text = "D";
	gameRightButton.font = "Consolas";
	gameRightButton.isUnderMouse = 0;
	gameRightButton.status = gameRunningStatus + gamePauseStatus + gameQuitStatus;
	gameRightButton.pointSize = 24;
}
void InitGrid() {
	for(int i = 0; i < GAMEPLANEWIDTH; ++i)
		for(int j = 0; j < GAMEPLANEHEIGHT; ++j) {
			grid[i][j].x = (20.0 + i * 22) / 96;
			grid[i][j].y = (21.0 + j * 22) / 96;
			grid[i][j].size = 21.0 / 96;
			grid[i][j].color = "BackGround";
			grid[i][j].hasBlock = 0;
		}
	for(int i = 1; i < 4; ++i)
		for(int j = 0; j < 4; ++j) {
			nextBlockGrid[i][j].x = 3.3 + j * 21.0 / 96;
			nextBlockGrid[i][j].y = 4.54 - i * 21.0 / 96;
			nextBlockGrid[i][j].size = 21.0 / 96;
			nextBlockGrid[i][j].color = "BackGround";
			nextBlockGrid[i][j].hasBlock = 0;
		}
}
void InitTextBox() {
	//gameOverTextBox
	SetFont("Consolas");
	SetPointSize(24);
	gameOverTextBox.width = TextStringWidth("AAAAAAAAAAAAA") + TEXTBOXFRAMEWIDTH * 2;
	gameOverTextBox.height = GetFontAscent() + TEXTBOXFRAMEWIDTH * 2;
	gameOverTextBox.x = 0.4;
	gameOverTextBox.y = 2;
	gameOverTextBox.maxSize = 12;
	gameOverTextBox.pointSize = 24;
	gameOverTextBox.status = gameOverStatus;
	gameOverTextBox.isFlashing = 0;
	gameOverTextBox.font = "Consolas";
	gameOverTextBox.list = InitList(gameOverTextBox.maxSize);
}
void InitElement() {
	//labels
	labels.status = allStatus;
	labels.draw = DrawLabels;
	//buttons
	buttons.status = allStatus;
	buttons.draw = DrawButtons;
	//scoreBoard
	scoreBoard.status = boardScoreStatus;
	scoreBoard.draw = DrawScoreBoard;
	//lineBoard
	lineBoard.status = boardLineStatus;
	lineBoard.draw = DrawLineBoard;
	//helpPage
	helpPage.status = helpPageStatus;
	helpPage.draw = DrawHelpPage;
	//gamePlaneFrame
	gamePlaneFrame.status = gameRunningStatus + gameOverStatus + gamePauseStatus + gameQuitStatus;
	gamePlaneFrame.draw = DrawGamePlaneFrame;
	//grids
	grids.status = gameRunningStatus;
	grids.draw = DrawGrids;
	//nextBlockFrame
	nextBlockFrame.status = gameRunningStatus + gameOverStatus + gamePauseStatus + gameQuitStatus;
	nextBlockFrame.draw = DrawNextBlockFrame;
	//nextBlockGrids
	nextBlockGrids.status = gameRunningStatus + gameOverStatus + gamePauseStatus + gameQuitStatus;
	nextBlockGrids.draw = DrawNextBlockGrids;
	//TextBoxes
	TextBoxes.status = allStatus;
	TextBoxes.draw = DrawTextBoxes;
}
void InitEvent() {
	registerMouseEvent(MouseEventProcess);
	registerCharEvent(CharEventProcess);
	registerKeyboardEvent(KeyboardEventProcess);
	registerTimerEvent(TimerEventProcess);
}
void InitVariable() {
	srand((unsigned)time(NULL));
	gameStatus = menuStatus;
	UpdateLevel(0);
	startTimer(TEXTBOXFLASHTIMERID, 500);
	LoadBoard();
}
void InitGame() {
	InitColor();
	InitLabel();
	InitButton();
	InitGrid();
	InitTextBox();
	InitElement();
	InitEvent();
	InitVariable();
}

