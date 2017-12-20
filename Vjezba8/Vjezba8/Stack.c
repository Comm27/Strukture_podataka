#include "Stack.h"
#include <stdlib.h>

int IsEmpty(Stack * header)
{
	if (header->next == NULL)
		return 1;
	return 0;
}

Stack* CreateNodeStack()
{
	Stack *node = NULL;
	node = (Stack*)malloc(sizeof(Stack));
	if (node == NULL)
	{
		//ErrorHandler(ALLOC_FAILED, "CreateNodeStack");
		return NULL;
	}

	node->next = NULL;
	return node;
}

int Push(Stack * header, struct _Direktorij *x)
{
	Stack *node = NULL;

	node = CreateNodeStack();
	if (node == NULL)
		return -1;

	node->mDir = x;

	node->next = header->next;
	header->next = node;
	return 0;
}

int Pop(Stack *header)
{
	Stack *node = NULL;
	if (IsEmpty(header))
		return -1; //ErrorHandler(EMPTY_STACK, "Pop");

	node = Top(header);
	header->next = node->next;

	free(node);
	return 0;
}

Stack* Top(Stack *header)
{
	return header->next;
}