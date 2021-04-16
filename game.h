/**
 *@file:	game.h
 *@author:	zju3180101729
 */

#ifndef _GAME_H
#define _GAME_H

#include <time.h>
#include "libgraphics.h"
#include "button.h"
#include "label.h"
#include "grid.h"
#include "block.h"
#include "textbox.h"

//96dpi
#define WIDTH 5.0
#define HEIGHT 5.0
#define GAMEPLANEWIDTH 10
#define GAMEPLANEHEIGHT 20
#define LEVELNUM 7
#define BUTTONNUM 18
#define KEYNUM 10
#define LABELNUM 12
#define TEXTBOXNUM 1
#define ELEMENTNUM 10
#define BOARDSIZE 10

//gameStatus
#define menuStatus 1
#define boardScoreStatus 2
#define boardLineStatus 4
#define helpPageStatus 8
#define gameRunningStatus 16
#define gameOverStatus 32
#define gamePauseStatus 64
#define gameQuitStatus 128
#define allStatus 255

//filename
#define GAMEFILENAME "Tetris.game"
#define BOARDFILENAME "Tetris.board"

//timerid
#define GAMELEVELTIMERID 1
#define TEXTBOXFLASHTIMERID 2

//there is no reference in C
#define menuTitleLabel label[0]
#define menuLevelLabel label[1]
#define boardScoreLabel label[2]
#define boardLineLabel label[3]
#define gameLevelLabel label[4]
#define gameLineLabel label[5]
#define gameScoreLabel label[6]
#define gameTitleLabel label[7]
#define gameOverLabel label[8]
#define gameOverTextBoxLabel label[9]
#define gamePauseLabel label[10]
#define gameQuitLabel label[11]

#define menuStartButton button[0]
#define menuContinueButton button[1]
#define menuSubButton button[2]
#define menuAddButton button[3]
#define menuBoardButton button[4]
#define menuHelpButton button[5]
#define menuBackButton button[6]
#define boardScoreButton button[7]
#define boardLineButton button[8]
#define gameQuitButton button[9]
#define gamePauseButton button[10]
#define gameYesButton button[11]
#define gameNoButton button[12]
#define gameOkButton button[13]
#define gameUpButton button[14]
#define gameDownButton button[15]
#define gameLeftButton button[16]
#define gameRightButton button[17]

#define gameOverTextBox textBox[0]

#define labels element[0]
#define buttons element[1]
#define scoreBoard element[2]
#define lineBoard element[3]
#define helpPage element[4]
#define gamePlaneFrame element[5]
#define grids element[6]
#define nextBlockFrame element[7]
#define nextBlockGrids element[8]
#define TextBoxes element[9]

typedef struct {
	bool isBlockInGame;
	int nextBlock;
	int level;
	int line;
	int score;
	int nowBlock, nowRotate, nowX, nowY;
	bool gridHasBlock[GAMEPLANEWIDTH][GAMEPLANEHEIGHT];
	string gridColor[GAMEPLANEWIDTH][GAMEPLANEHEIGHT];
}Game;

typedef struct {
	int status;
	void (*draw)();
}Element;

typedef struct {
	char name[13];
	int data;
}Board;

//game.c
extern bool isBlockInGame;
extern bool flag;

extern int gameStatus;
extern int nextBlock;
extern int level;
extern int line;
extern int score;
extern int nowBlock, nowRotate, nowX, nowY;
extern int speed[LEVELNUM];
extern int temp;

extern Button button[BUTTONNUM];

extern Label label[LABELNUM];

extern Grid grid[GAMEPLANEWIDTH][GAMEPLANEHEIGHT], nextBlockGrid[4][4];

extern Board boardScore[BOARDSIZE], boardLine[BOARDSIZE];

extern TextBox textBox[TEXTBOXNUM];

extern Element element[ELEMENTNUM];

extern bool (*CanButtonClick[BUTTONNUM])();
extern void (*ClickButton[BUTTONNUM])();
extern bool (*CanKeyPress[KEYNUM])();
extern void (*PressKey[KEYNUM])();

//draw.c
void FillSquare(double width, double height, double grayScale);
void ClearScreen();
void DrawLabels();
void DrawButtons();
void DrawBoardFrame();
void DrawBoard(Board board[]);
void DrawScoreBoard();
void DrawLineBoard();
void DrawHelpPage();
void DrawGamePlaneFrame();
void DrawGrids();
void DrawNextBlockFrame();
void DrawNextBlockGrids();
void DrawTextBoxes();
void DrawElements();
void DrawGame();

//game.c
int cmp(const void *x, const void *y);
bool AlwaysTrue();
bool AlwaysFalse();
bool isStatusExist(int status);
void UpdateGameBoard();
void UpdateLevel(int Level);
bool CanLevelSub();
void SubLevel();
bool CanLevelAdd();
void AddLevel();

void GameStart();
bool CanGameLoad();
void LoadGame();
void SaveGame();
void LoadBoard();
void SaveBoard();
void UpdateBoard();
bool isBoardScore();
void DisplayBoardScore();
bool isBoardLine();
void DisplayBoardLine();
void DisplayHelpPage();
void BackMenu();
void GameContinue();
void WaitForGameQuit();
void GameQuit();
void GameReturn();
void ChangeNextBlock(int blockId);
void ChangeNowBlock(bool hasBlock);
bool CanBlockExist(int blockId, int blockRotate, int x, int y);
bool CanBlockAdd(int blockId);
void AddBlock(int blockId);
bool CanBlockDown();
void DownBlock();
bool CanBlockRotate();
void RotateBlock();
bool CanBlockMove(int dx);
void MoveBlock(int dx);
void DelBlock();
bool CanLineErase(int lineId);
void UpdateGame();
bool CanGamePause();
void GamePause();
void GameOver();
bool CanKeyUp();
void KeyUp();
bool CanKeyDown();
void KeyDown();
bool CanKeyLeft();
void KeyLeft();
bool CanKeyRight();
void KeyRight();
bool CanKeyA();
void KeyA();
bool CanKeyD();
void KeyD();
void KeySpace();
bool CanTextDelete();
void KeyDelete();
bool CanTextBack();
void KeyBack();
bool CanKeyEnter();
void MouseEventProcess(int x, int y, int _button, int _event);
void CharEventProcess(char c);
void KeyboardEventProcess(int key, int event);
void TimerEventProcess(int id);
void startTimer(int id, int timeinterval);
void cancelTimer(int id);

//init.c
void InitColor();
void InitLabel();
void InitButton();
void InitGrid();
void InitTextBox();
void InitElement();
void InitEvent();
void InitGame();
void InitVariable();

//main.c
void Main();

#endif		//_GAME_H

