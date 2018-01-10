#pragma once
#include "Directory.h"

typedef struct _Stack
{
	Directory *dir;
	struct _Stack *next;
}Stack;

int IsEmpty(Stack *header);
Stack* CreateNode();
int Push(Stack *header, Directory *dir);
int Pop(Stack *header);
Stack* Top(Stack *header);