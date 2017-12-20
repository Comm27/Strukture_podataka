#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
typedef struct _Direktorij
{
	char name[250];
	struct _Direktorij *next;
	struct _Direktorij *child;
}Direktorij;

int CreateDir(Direktorij *dir, const char *name);

int PrintDir(Direktorij *dir);
Direktorij* EnterDir(Direktorij *dir, const char *path, const char *name, struct _Stack *stack);
Direktorij* ExitDir(Direktorij *dir, const char *path, struct _Stack *stack);