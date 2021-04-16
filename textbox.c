/**
 *@file:	textbox.c
 *@author:	zju3180101729
 */

#include "textbox.h"

void FillSquare(double width, double height, double grayScale);
void DrawTextBox(TextBox textBox) {
	SetPenColor("Black");
	SetPenSize(2);
	MovePen(textBox.x, textBox.y);
	DrawLine(textBox.width, 0);
	DrawLine(0, textBox.height);
	DrawLine(-textBox.width, 0);
	DrawLine(0, -textBox.height);
	SetFont(textBox.font);
	SetPointSize(textBox.pointSize);
	MovePen(textBox.x + TEXTBOXFRAMEWIDTH, textBox.y + TEXTBOXFRAMEWIDTH + (GetFontAscent() + GetFontDescent()) / 8);
	for(ListNode *i = textBox.list->head->next; ; i = i->next) {
		string s;
		s = CharToString(i->c);
		double height = GetFontHeight(), width = TextStringWidth(s);
		if(i == textBox.list->now && textBox.isFlashing) {
			MovePen(GetCurrentX(), GetCurrentY() - height / 5);
			FillSquare(width, height, 1);
			MovePen(GetCurrentX(), GetCurrentY() + height / 5);
			if(i != textBox.list->tail) {
				SetEraseMode(TRUE);
				DrawTextString(s);
				SetEraseMode(FALSE);
			}
		}else if(i != textBox.list->tail)
			DrawTextString(s);
		if(i == textBox.list->tail)
			break;
	}
}

string toString(TextBox textBox) {
	string ret = (string)malloc(textBox.maxSize + 1);
	for(int i = 0; i < textBox.maxSize; ++i)
		ret[i] = ' ';
	ret[textBox.maxSize] = '\0';
	int temp = 0;
	for(ListNode *i = textBox.list->head->next; i != textBox.list->tail; i = i->next)
		ret[temp++] = i->c;
	return ret;
}

