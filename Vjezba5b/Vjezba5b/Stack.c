#include "Stack.h"
#include "../../libs/mylibs/ErrorHandler.h"
#include <stdlib.h>

int IsEmpty(Stack * header)
{
	if (header->next == NULL)
		return 1;
	return 0;
}

Stack* CreateNode()
{
	Stack *node = NULL;
	node = (Stack*)malloc(sizeof(Stack));
	if (node == NULL)
	{
		ErrorHandler(ALLOC_FAILED, "CreateNode");
		return NULL;
	}

	node->next = NULL;
	return node;
}

int Push(Stack * header, int x)
{
	Stack *node = NULL;

	node = CreateNode();
	if (node == NULL)
		return -1;

	node->mBroj = x;

	node->next = header->next;
	header->next = node;
	return 0;
}

int Pop(Stack *header)
{
	Stack *node = NULL;
	if (IsEmpty(header))
		return ErrorHandler(EMPTY_STACK, "Pop");

	node = Top(header);
	header->next = node->next;

	free(node);
	return 0;
}

Stack* Top(Stack *header)
{
	return header->next;
}

int Print(Stack *header)
{
	Stack *iter = header->next;

	while (iter != NULL) 
	{
		printf("%d\n", iter->mBroj);
		iter = iter->next;
	}

	return 0;
}