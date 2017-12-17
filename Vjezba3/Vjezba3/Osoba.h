#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG
#include <assert.h>
#include <string.h>
//#include "ErrorHandler.h"

typedef enum _pos {BEFORE, AFTER} pos;

typedef struct _Osoba
{
	char mIme[50];
	char mPrezime[50];
	int mGodRod;
	struct _Osoba *next;
}
Osoba;

Osoba* CreateNode(int define);
int DefineObj(Osoba *);

int AddFirst(Osoba *);
int AddLast(Osoba *);

int Print(Osoba *);

Osoba* FindBefore(Osoba *, const char *);
Osoba* Find(Osoba *, const char *);
Osoba* FindAfter(Osoba *, const char *);

int Insert(Osoba *, const char *, pos);	// Do not use on your own
int InsertBefore(Osoba *, const char *);
int InsertAfter(Osoba *, const char *);

int RemoveNode(Osoba *, const char *);

int WriteToFile(Osoba *, const char *);
int ReadFromFile(Osoba *, const char *);