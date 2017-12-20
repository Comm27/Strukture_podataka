#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define NDEBUG
#include <assert.h>

#include "BST.h"


int main()
{
	BST *header = NULL;
	header = Insert(header, 50);
	Insert(header, 4);
	Insert(header, 120);
	Insert(header, 1);
	Insert(header, 20);
	Insert(header, 80);
	Insert(header, 30);
	Insert(header, 121);
	Insert(header, 90);
	Insert(header, 21);
	Insert(header, 35);
	Insert(header, 130);
	Insert(header, 34);

	Delete(header, 1);
	Delete(header, 4);
	Print(header);
	printf("Max: %d\n", FindMax(header)->x);
	printf("Min: %d\n", FindMin(header)->x);

	free(header);
	getchar();
	getchar();
	return 0;
}