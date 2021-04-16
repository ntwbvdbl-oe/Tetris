/**
 *@file:	list.h
 *@author:	zju3180101729
 */

#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

typedef struct ListNode {
	char c;
	struct ListNode *last, *next;
}ListNode;

typedef struct List {
	int size, maxSize;
	struct ListNode *head, *tail, *now;
}List;

List* InitList(int _maxSize);
int CanInsert(List *list);
void Insert(List *list, char c);
int CanDelete(List *list);
void Delete(List *list);
int CanBackSpace(List *list);
void BackSpace(List *list);
int CanMoveLeft(List *list);
void MoveLeft(List *list);
int CanMoveRight(List *list);
void MoveRight(List *list);
void ReSet();

#endif		//_LIST_H

