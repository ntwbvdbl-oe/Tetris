/**
 *@file:	block.c
 *@author:	zju3180101729
 */

#include "block.h"

string blockColor[BLOCKNUM] = {"Orange", "Red", "Blue", "Magenta", "Cyan", "Green", "Yellow"};
int blockRotateNum[BLOCKNUM] = {2, 1, 4, 4, 2, 2, 4};
int blocks[BLOCKNUM][4][4][4] = {{{{0, 0, 0, 0},
								   {1, 1, 1, 1},
								   {0, 0, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 1, 0, 0},
								   {0, 1, 0, 0},
								   {0, 1, 0, 0},
								   {0, 1, 0, 0}}},
								 {{{0, 0, 0, 0},
								   {1, 1, 0, 0},
								   {1, 1, 0, 0},
								   {0, 0, 0, 0}}},
								 {{{0, 0, 0, 0},
								   {1, 1, 1, 0},
								   {1, 0, 0, 0},
								   {0, 0, 0, 0}},
								  {{1, 1, 0, 0},
								   {0, 1, 0, 0},
								   {0, 1, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 0, 1, 0},
								   {1, 1, 1, 0},
								   {0, 0, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 1, 0, 0},
								   {0, 1, 0, 0},
								   {0, 1, 1, 0},
								   {0, 0, 0, 0}}},
								 {{{0, 0, 0, 0},
								   {1, 1, 1, 0},
								   {0, 0, 1, 0},
								   {0, 0, 0, 0}},
								  {{0, 1, 0, 0},
								   {0, 1, 0, 0},
								   {1, 1, 0, 0},
								   {0, 0, 0, 0}},
								  {{1, 0, 0, 0},
								   {1, 1, 1, 0},
								   {0, 0, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 1, 1, 0},
								   {0, 1, 0, 0},
								   {0, 1, 0, 0},
								   {0, 0, 0, 0}}},
								 {{{0, 0, 0, 0},
								   {1, 1, 0, 0},
								   {0, 1, 1, 0},
								   {0, 0, 0, 0}},
								  {{0, 0, 1, 0},
								   {0, 1, 1, 0},
								   {0, 1, 0, 0},
								   {0, 0, 0, 0}}},
								 {{{0, 0, 0, 0},
								   {0, 1, 1, 0},
								   {1, 1, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 1, 0, 0},
								   {0, 1, 1, 0},
								   {0, 0, 1, 0},
								   {0, 0, 0, 0}}},
								 {{{0, 1, 0, 0},
								   {1, 1, 1, 0},
								   {0, 0, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 1, 0, 0},
								   {0, 1, 1, 0},
								   {0, 1, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 0, 0, 0},
								   {1, 1, 1, 0},
								   {0, 1, 0, 0},
								   {0, 0, 0, 0}},
								  {{0, 1, 0, 0},
								   {1, 1, 0, 0},
								   {0, 1, 0, 0},
								   {0, 0, 0, 0}}}};

