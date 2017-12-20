#include "Queue.h"
#include <stdlib.h>
#include "../../libs/mylibs/ErrorHandler.h"

int IsEmpty(Queue * header)
{
	if (header->next == NULL)
		return 1;
	return 0;
}

Queue* CreateNode()
{
	Queue *node = NULL;
	node = (Queue*)malloc(sizeof(Queue));
	if (node == NULL)
	{
		ErrorHandler(ALLOC_FAILED, "CreateNode");
		return NULL;
	}

	node->next = NULL;
	return node;
}

int Enqueue(Queue * header, int x)
{
	Queue *iter = NULL, *node = NULL;

	node = CreateNode();
	if (node == NULL)
		return -1;

	node->mBroj = x;
	iter = header;

	while (iter->next != NULL)
		iter = iter->next;
	
	iter->next = node;
	return 0;
}

int Dequeue(Queue * header)
{
	Queue *node = NULL;
	if (IsEmpty(header))
		return ErrorHandler(EMPTY_QUEUE, "Dequeue");

	node = Peek(header);
	header->next = node->next;

	free(node);
	return 0;
}

Queue * Peek(Queue * header)
{
	return header->next;
}

int Print(Queue * header)
{
	Queue *iter = header->next;

	while (iter != NULL)
	{
		printf("%d\n", iter->mBroj);
		iter = iter->next;
	}
	return 0;
}