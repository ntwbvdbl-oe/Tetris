/**
 *@file:	game.c
 *@author:	zju3180101729
 */

#include "game.h"

bool isBlockInGame;
bool flag;		//a temp var

int gameStatus;
int nextBlock;
int level;
int line;
int score;
int nowBlock, nowRotate, nowX, nowY;
int speed[LEVELNUM] = {900, 800, 700, 600, 500, 400, 300};		//ms
int temp;		//a temp var

Label label[LABELNUM];

Button button[BUTTONNUM];

Grid grid[GAMEPLANEWIDTH][GAMEPLANEHEIGHT], nextBlockGrid[4][4];

TextBox textBox[TEXTBOXNUM];

Board boardScore[BOARDSIZE], boardLine[BOARDSIZE];

Element element[ELEMENTNUM];

bool (*CanButtonClick[BUTTONNUM])() = {AlwaysTrue, CanGameLoad, CanLevelSub, CanLevelAdd, AlwaysTrue, AlwaysTrue, AlwaysTrue, isBoardLine, isBoardScore, AlwaysTrue, AlwaysTrue, AlwaysTrue, AlwaysTrue, AlwaysTrue, CanKeyUp, CanKeyDown, CanKeyLeft, CanKeyRight};
void (*ClickButton[BUTTONNUM])() = {GameStart, GameContinue, SubLevel, AddLevel, DisplayBoardScore, DisplayHelpPage, BackMenu, DisplayBoardScore, DisplayBoardLine, WaitForGameQuit, GamePause, GameQuit, GameReturn, GameQuit, KeyUp, KeyDown, KeyLeft, KeyRight};
bool (*CanKeyPress[KEYNUM])() = {CanKeyUp, CanKeyDown, CanKeyLeft, CanKeyRight, CanKeyA, CanKeyD, CanGamePause, CanTextDelete, CanTextBack, CanKeyEnter};
void (*PressKey[KEYNUM])() = {KeyUp, KeyDown, KeyLeft, KeyRight, KeyA, KeyD, KeySpace, KeyDelete, KeyBack, GameQuit};

int cmp(const void *x, const void *y) {
	return (*(Board*)x).data - (*(Board*)y).data;
}
bool AlwaysTrue() {
	return 1;
}
bool AlwaysFalse() {
	return 0;
}
bool isStatusExist(int status) {
	return (status & gameStatus) == gameStatus;
}
void UpdateGameBoard() {
	sprintf(gameLineLabel.text, "LINE  %5d", line);
	sprintf(gameScoreLabel.text, "SCORE %5d", score);
}
void UpdateLevel(int Level) {
	level = Level;
	sprintf(menuLevelLabel.text, "LEVEL %d", level + 1);
	sprintf(gameLevelLabel.text, "LEVEL     %d", level + 1);
}
bool CanLevelSub() {
	return level != 0;
}
void SubLevel() {
	UpdateLevel(level - 1);
}
bool CanLevelAdd() {
	return level != LEVELNUM - 1;
}
void AddLevel() {
	UpdateLevel(level + 1);
}

void GameStart() {
	isBlockInGame = 0;
	ChangeNextBlock(rand() % BLOCKNUM);
	line = score = 0;
	for(int i = 0; i < GAMEPLANEWIDTH; ++i)
		for(int j = 0; j < GAMEPLANEHEIGHT; ++j)
			grid[i][j].hasBlock = 0;
	UpdateGameBoard();
	startTimer(GAMELEVELTIMERID, speed[level]);
	gameStatus = gameRunningStatus;
}
bool CanGameLoad() {
	FILE *file = fopen(GAMEFILENAME, "r");
	Game game;
	return file != NULL && fread(&game, sizeof(Game), 1, file);
}
void LoadGame() {
	FILE *file = fopen(GAMEFILENAME, "r");
	Game game;
	fread(&game, sizeof(Game), 1, file);
	isBlockInGame = game.isBlockInGame;
	nextBlock = game.nextBlock;
	level = game.level;
	line = game.line;
	score = game.score;
	nowBlock = game.nowBlock;
	nowRotate = game.nowRotate;
	nowX = game.nowX;
	nowY = game.nowY;
	for(int i = 0; i < GAMEPLANEWIDTH; ++i)
		for(int j = 0; j < GAMEPLANEHEIGHT; ++j) {
			grid[i][j].hasBlock = game.gridHasBlock[i][j];
			grid[i][j].color = game.gridColor[i][j];
		}
}
void SaveGame() {
	FILE *file = fopen(GAMEFILENAME, "w");
	Game game;
	game.isBlockInGame = isBlockInGame;
	game.nextBlock = nextBlock;
	game.level = level;
	game.line = line;
	game.score = score;
	game.nowBlock = nowBlock;
	game.nowRotate = nowRotate;
	game.nowX = nowX;
	game.nowY = nowY;
	for(int i = 0; i < GAMEPLANEWIDTH; ++i)
		for(int j = 0; j < GAMEPLANEHEIGHT; ++j) {
			game.gridHasBlock[i][j] = grid[i][j].hasBlock;
			game.gridColor[i][j] = grid[i][j].color;
		}
	fwrite(&game, sizeof(Game), 1, file);
	fclose(file);
}
void LoadBoard() {
	FILE *file = fopen(BOARDFILENAME, "r");
	if(file == NULL || !fread(boardScore, sizeof(Board), BOARDSIZE, file) || !fread(boardLine, sizeof(Board), BOARDSIZE, file))
		for(int i = 0; i < BOARDSIZE; ++i) {
			strcpy(boardScore[i].name, " ");
			strcpy(boardLine[i].name, " ");
			boardScore[i].data = boardLine[i].data = 0;
		}
	else
		fclose(file);
}
void SaveBoard() {
	FILE *file = fopen(BOARDFILENAME, "w");
	if(file != NULL) {
		fwrite(boardScore, sizeof(Board), BOARDSIZE, file);
		fwrite(boardLine, sizeof(Board), BOARDSIZE, file);
		fclose(file);
	}
}
void UpdateBoard() {
	if(score > boardScore[0].data) {
		strcpy(boardScore[0].name, toString(gameOverTextBox));
		boardScore[0].data = score;
		qsort(boardScore, BOARDSIZE, sizeof(Board), cmp);
	}
	if(line > boardLine[0].data) {
		strcpy(boardLine[0].name, toString(gameOverTextBox));
		boardLine[0].data = line;
		qsort(boardLine, BOARDSIZE, sizeof(Board), cmp);
	}
	ReSet(gameOverTextBox.list);
	SaveBoard();
}
bool isBoardScore() {
	return gameStatus == boardScoreStatus;
}
void DisplayBoardScore() {
	gameStatus = boardScoreStatus;
}
bool isBoardLine() {
	return gameStatus == boardLineStatus;
}
void DisplayBoardLine() {
	gameStatus = boardLineStatus;
}
void DisplayHelpPage() {
	gameStatus = helpPageStatus;
}
void BackMenu() {
	gameStatus = menuStatus;
}
void GameContinue() {
	LoadGame();
	UpdateGameBoard();
	startTimer(1, speed[level]);
	gameStatus = gameRunningStatus;
}
void WaitForGameQuit() {
	gameStatus = gameQuitStatus;
}
void GameQuit() {
	if(gameStatus == gameOverStatus)
		UpdateBoard();
	else if(gameStatus == gameQuitStatus)
		SaveGame();
	cancelTimer(1);
	gameStatus = menuStatus;
}
void GameReturn(){
	gameStatus = gameRunningStatus;
}
void ChangeNextBlock(int blockId) {
	nextBlock = blockId;
	for(int i = 1; i < 4; ++i)
		for(int j = 0; j < 4; ++j) {
			nextBlockGrid[i][j].hasBlock = blocks[nextBlock][0][nextBlock == 6 ? i - 1 : i][j];
			nextBlockGrid[i][j].color = blockColor[nextBlock];
		}
}
void ChangeNowBlock(bool hasBlock) {
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(blocks[nowBlock][nowRotate][i][j]) {
				grid[nowX + j][nowY - i].hasBlock = hasBlock;
				grid[nowX + j][nowY - i].color = blockColor[nowBlock];
			}
}
bool CanBlockExist(int blockId, int blockRotate, int x, int y) {
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(blocks[blockId][blockRotate][i][j] && (x + j < 0 || x + j >= GAMEPLANEWIDTH || y - i < 0 || y - i >= GAMEPLANEHEIGHT || grid[x + j][y - i].hasBlock))
				return 0;
	return 1;
}
bool CanBlockAdd(int blockId) {
	return CanBlockExist(blockId, 0, 3, blockId == 6 ? 19 : 20);
}
void AddBlock(int blockId) {
	isBlockInGame = 1;
	nowBlock = blockId;
	nowRotate = 0;
	nowX = 3, nowY = nowBlock == 6 ? 19 : 20;
	ChangeNowBlock(1);
}
bool CanBlockDown() {
	ChangeNowBlock(0);
	bool ret = CanBlockExist(nowBlock, nowRotate, nowX, nowY - 1);
	ChangeNowBlock(1);
	return ret;
}
void DownBlock() {
	ChangeNowBlock(0);
	--nowY;
	ChangeNowBlock(1);
}
bool CanBlockRotate() {
	ChangeNowBlock(0);
	bool ret = nowBlock == 1 ? 0 : CanBlockExist(nowBlock, (nowRotate + 1) % blockRotateNum[nowBlock], nowX, nowY);
	ChangeNowBlock(1);
	return ret;
}
void RotateBlock() {
	ChangeNowBlock(0);
	nowRotate = (nowRotate + 1) % blockRotateNum[nowBlock];
	ChangeNowBlock(1);
}
bool CanBlockMove(int dx) {
	ChangeNowBlock(0);
	bool ret = CanBlockExist(nowBlock, nowRotate, nowX + dx, nowY);
	ChangeNowBlock(1);
	return ret;
}
void MoveBlock(int dx) {
	ChangeNowBlock(0);
	nowX += dx;
	ChangeNowBlock(1);
}
void DelBlock() {
	isBlockInGame = 0;
	score += nowBlock == 6 ? 20 - nowY : 19 - nowY;
}
bool CanLineErase(int lineId) {
	for(int i = 0; i < GAMEPLANEWIDTH; ++i)
		if(!grid[i][lineId].hasBlock)
			return 0;
	return 1;
}
void UpdateGame() {
	int sum = 0;
	for(int j = 0; j < GAMEPLANEHEIGHT; ++j)
		if(CanLineErase(j)) {
			for(int k = j + 1; k < GAMEPLANEHEIGHT; ++k)
				for(int i = 0; i < GAMEPLANEWIDTH; ++i) {
					grid[i][k - 1].hasBlock = grid[i][k].hasBlock;
					grid[i][k - 1].color = grid[i][k].color;
				}
			for(int i = 0; i < GAMEPLANEWIDTH; ++i)
				grid[i][19].hasBlock = 0;
			--j;
			++sum;
		}
	line += sum;
	score += 20 * sum + sum * (sum - 1) / 2 * 5;
	UpdateGameBoard();
}
bool CanGamePause() {
	return gameStatus == gameRunningStatus || gameStatus == gameQuitStatus || gameStatus == gamePauseStatus;
}
void GamePause() {
	if(gameStatus == gameRunningStatus || gameStatus == gameQuitStatus)
		gameStatus = gamePauseStatus;
	else if(gameStatus == gamePauseStatus)
		gameStatus = gameRunningStatus;
}
void GameOver() {
	gameStatus = gameOverStatus;
}
bool CanKeyUp() {
	return gameStatus == gameRunningStatus && isBlockInGame && CanBlockRotate();
}
void KeyUp() {
	RotateBlock();
}
bool CanKeyDown() {
	return gameStatus == gameRunningStatus && isBlockInGame && CanBlockDown();
}
void KeyDown() {
	DownBlock();
}
bool CanKeyLeft() {
	if(gameStatus == gameRunningStatus)
		return isBlockInGame && CanBlockMove(-1);
	else
		for(int i = 0; i < TEXTBOXNUM; ++i)
			if(isStatusExist(textBox[i].status))
				return CanMoveLeft(textBox[i].list);
	return 0;
}
void KeyLeft() {
	if(gameStatus == gameRunningStatus)
		MoveBlock(-1);
	else
		for(int i = 0; i < TEXTBOXNUM; ++i)
			if(isStatusExist(textBox[i].status))
				MoveLeft(textBox[i].list);
}
bool CanKeyRight() {
	if(gameStatus == gameRunningStatus)
		return isBlockInGame && CanBlockMove(1);
	else
		for(int i = 0; i < TEXTBOXNUM; ++i)
			if(isStatusExist(textBox[i].status))
				return CanMoveRight(textBox[i].list);
	return 0;
}
void KeyRight() {
	if(gameStatus == gameRunningStatus)
		MoveBlock(1);
	else
		for(int i = 0; i < TEXTBOXNUM; ++i)
			if(isStatusExist(textBox[i].status))
				MoveRight(textBox[i].list);
}
bool CanKeyA() {
	return gameStatus == gameRunningStatus && isBlockInGame && CanBlockMove(-1);
}
void KeyA() {
	MoveBlock(-1);
}
bool CanKeyD() {
	return gameStatus == gameRunningStatus && isBlockInGame && CanBlockMove(1);
}
void KeyD() {
	MoveBlock(1);
}
void KeySpace() {
	GamePause();
}
bool CanTextDelete() {
	for(int i = 0; i < TEXTBOXNUM; ++i)
		if(isStatusExist(textBox[i].status))
			return CanDelete(textBox[i].list);
	return 0;
}
void KeyDelete() {
	for(int i = 0; i < TEXTBOXNUM; ++i)
		if(isStatusExist(textBox[i].status))
			Delete(textBox[i].list);
}
bool CanTextBack() {
	for(int i = 0; i < TEXTBOXNUM; ++i)
		if(isStatusExist(textBox[i].status))
			return CanBackSpace(textBox[i].list);
	return 0;
}
void KeyBack() {
	for(int i = 0; i < TEXTBOXNUM; ++i)
		if(isStatusExist(textBox[i].status))
			BackSpace(textBox[i].list);
}
bool CanKeyEnter() {
	return gameStatus == gameOverStatus;
}
void MouseEventProcess(int x, int y, int _button, int _event) {
	switch(_button * 8 + _event) {
		case LEFT_BUTTON * 8 + BUTTON_DOWN:
		case MOUSEMOVE * 8 + MOUSEMOVE:
			flag = 0;
			for(int i = 0; i < BUTTONNUM; ++i) {
				if(isStatusExist(button[i].status)) {
					bool temp = InButton(ScaleXInches(x), ScaleYInches(y), button[i]);
					if(temp && !CanButtonClick[i]())
						temp = 0;
					if(temp != button[i].isUnderMouse)
						flag = 1;
					button[i].isUnderMouse = temp;
				}else
					button[i].isUnderMouse = 0;
				if(_button * 8 + _event == LEFT_BUTTON * 8 + BUTTON_DOWN && button[i].isUnderMouse) {
					ClickButton[i]();
					flag = 1;
					break;
				}
			}
			if(flag) {
				for(int i = 0; i < BUTTONNUM; ++i)
					button[i].isUnderMouse = isStatusExist(button[i].status) && InButton(ScaleXInches(x), ScaleYInches(y), button[i]) && CanButtonClick[i]();
				DrawGame();
			}
			break;
	}
}
void CharEventProcess(char c) {
	if(c >= 32 && c <= 126) {
		bool flag = 0;
		for(int i = 0; i < TEXTBOXNUM; ++i)
			if(isStatusExist(textBox[i].status) && CanInsert(textBox[i].list))
				Insert(textBox[i].list, c), flag = 1;
		if(flag)
			DrawGame();
	}
}
void KeyboardEventProcess(int key, int event) {
	if(event == KEY_DOWN) {
		bool flag = 0;
		switch(key) {
			case 0x26:		//VK_UP
			case 0x57:		//VK_W
				if(flag = CanKeyPress[0]())
					PressKey[0]();
				break;
			case 0x28:		//VK_DOWN
			case 0x53:		//VK_S
				if(flag = CanKeyPress[1]())
					PressKey[1]();
				break;
			case 0x25:		//VK_LEFT
				if(flag = CanKeyPress[2]())
					PressKey[2]();
				break;
			case 0x27:		//VK_RIGHT
				if(flag = CanKeyPress[3]())
					PressKey[3]();
				break;
			case 0x41:		//VK_A
				if(flag = CanKeyPress[4]())
					PressKey[4]();
				break;
			case 0x44:		//VK_D
				if(flag = CanKeyPress[5]())
					PressKey[5]();
				break;
			case 0x20:		//VK_SPACE
				if(flag = CanKeyPress[6]())
					PressKey[6]();
				break;
			case 0x2E:		//VK_DELETE
				if(flag = CanKeyPress[7]())
					PressKey[7]();
				break;
			case 0x08:		//VK_BACK
				if(flag = CanKeyPress[8]())
					PressKey[8]();
				break;
			case 0x0D:		//VK_RETURN
				if(flag = CanKeyPress[9]())
					PressKey[9]();
				break;
		}
		if(flag)
			DrawGame();
	}
}
void TimerEventProcess(int id) {
	if(id == GAMELEVELTIMERID) {
		if(gameStatus == gameRunningStatus) {
			if(isBlockInGame) {
				if(CanBlockDown())
					DownBlock();
				else {
					DelBlock();
					UpdateGame();
				}
			}else {
				if(CanBlockAdd(nextBlock)) {
					AddBlock(nextBlock);
					ChangeNextBlock(rand() % BLOCKNUM);
				}else
					GameOver();
			}
			DrawGame();
		}
	}else if(id == TEXTBOXFLASHTIMERID) {
		bool flag = 0;
		for(int i = 0; i < TEXTBOXNUM; ++i)
			if(isStatusExist(textBox[i].status))
				textBox[i].isFlashing = !textBox[i].isFlashing, flag = 1;
		if(flag)
			DrawGame();
	}
}

