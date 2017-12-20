#pragma once
typedef struct _Stack
{
	int mBroj;
	struct _Stack *next;
}Stack;

int IsEmpty(Stack *header);
Stack* CreateNode();
int Push(Stack *header, int x);
int Pop(Stack *header);

Stack* Top(Stack *header);
int Print(Stack *header);