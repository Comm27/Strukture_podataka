#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define NDEBUG
#include <assert.h>
#include "Queue.h"

int main()
{
	Queue *header = CreateNode();
	assert(header);
	Enqueue(header, 5);
	Enqueue(header, 4);
	Enqueue(header, 22);
	Enqueue(header, -12);

	Print(header);
	printf("Peek() : %d\n", Peek(header)->mBroj);
	Dequeue(header);
	Print(header);

	free(header);
	getchar();
	getchar();
	return 0;
}