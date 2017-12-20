#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Polinom
{
	float k;	// Koeficjent
	float p;	// Potencija
	struct _Polinom *next;
}Polinom;

Polinom * CreateNode(float k, float p);
int AddFirst(Polinom *header, float k, float p);
int AddLast(Polinom *header, float k, float p);

int ReadFromFile(Polinom *header, const char *filepath);

int Print(Polinom *header);

int SortList(Polinom * header);