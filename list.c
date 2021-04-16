/**
 *@file:	list.c
 *@author:	zju3180101729
 */

#include "list.h"

List *InitList(int _maxSize) {
	List *list = (List*)malloc(sizeof(List));
	list->size = 0, list->maxSize = _maxSize;
	list->head = (ListNode*)malloc(sizeof(ListNode));
	list->tail = (ListNode*)malloc(sizeof(ListNode));
	list->head->c = list->tail->c = ' ';
	list->head->last = list->tail->next = NULL;
	list->head->next = list->tail, list->tail->last = list->head;
	list->now = list->tail;
	return list;
}
int CanInsert(List *list) {
	return list->size < list->maxSize;
}
void Insert(List *list, char c) {
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->c = c;
	node->last = list->now->last, node->next = list->now;
	list->now->last = list->now->last->next = node;
	++list->size;
}
int CanDelete(List *list) {
	return list->now != list->tail;
}
void Delete(List *list) {
	ListNode *temp = list->now;
	list->now->last->next = list->now->next;
	list->now->next->last = list->now->last;
	list->now = list->now->next;
	free(temp);
	--list->size;
}
int CanBackSpace(List *list) {
	return list->now->last != list->head;
}
void BackSpace(List *list) {
	list->now = list->now->last;
	Delete(list);
}
int CanMoveLeft(List *list) {
	return list->now->last != list->head;
}
void MoveLeft(List *list) {
	list->now = list->now->last;
}
int CanMoveRight(List *list) {
	return list->now != list->tail;
}
void MoveRight(List *list) {
	list->now = list->now->next;
}
void ReSet(List *list) {
	list->now = list->head->next;
	while(CanDelete(list))
		Delete(list);
}

