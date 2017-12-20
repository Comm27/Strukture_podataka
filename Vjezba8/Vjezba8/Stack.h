#pragma once
#include "Direktorij.h"

typedef struct _Direktorij Dirktorij;

typedef struct _Stack
{
	struct _Direktorij *mDir;
	struct _Stack *next;
}Stack;

int IsEmpty(Stack *header);
Stack* CreateNodeStack();
int Push(Stack *header, struct _Direktorij *x);
int Pop(Stack *header);

Stack* Top(Stack *header);