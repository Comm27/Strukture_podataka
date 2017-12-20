#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define NDEBUG
#include <assert.h>

#include "Stack.h"

int main(int argc, char *argv[])
{
	Stack *header = CreateNode();
	assert(header);

	Push(header, 5);
	Push(header, 50);
	Push(header, 15);
	Push(header, 3);

	Print(header);

	free(header);
	getchar();
	return 0;
}