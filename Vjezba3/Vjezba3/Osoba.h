#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG
#include <assert.h>
#include <string.h>
#include "ErrorHandler.h"

#define BUFFER_MAX_LENGTH 250

typedef enum _pos {BEFORE, AFTER} pos;

typedef struct _Osoba
{
	char mIme[BUFFER_MAX_LENGTH];
	char mPrezime[BUFFER_MAX_LENGTH];
	int mGodRod;
	struct _Osoba *next;
}
Osoba;

Osoba* CreateNode(int define);
int DefineObj(Osoba *);

int AddFirst(Osoba *header);
int AddLast(Osoba *header);

int AddFirstNode(Osoba *header, Osoba *node);
int AddLastNode(Osoba *header, Osoba *node);

int Print(Osoba *);

Osoba* FindBefore(Osoba *, const char *);
Osoba* Find(Osoba *, const char *);
Osoba* FindAfter(Osoba *, const char *);

int Insert(Osoba *, const char *, pos);	// Do not use on your own
int InsertBefore(Osoba *, const char *);
int InsertAfter(Osoba *, const char *);

int RemoveNode(Osoba *, const char *);

int WriteToFile(Osoba *header, const char *filePath);
int ReadFromFile(Osoba *header, const char *filePath);

int SortList(Osoba *header);