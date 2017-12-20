#include "Direktorij.h"
#include "../../libs/mylibs/ErrorHandler.h"

int CreateDir(Direktorij *dir, const char *name)
{
	Direktorij *node = (Direktorij*)malloc(sizeof(Direktorij));
	if (node == NULL)
	{
		ErrorHandler(ALLOC_FAILED, "CreateNode");
		return;
	}

	strcpy(node->name, name);
	node->next = NULL;
	node->child = NULL;

	if (dir->child == NULL)
	{
		dir->child = node;
	}
	else
	{
		node->next = dir->child;
		dir->child = node;
	}
}

int PrintDir(Direktorij * dir)
{
	Direktorij *iter = NULL;
	if (dir == NULL)
	{
		ErrorHandler(NULL_ARG, "PrintDir");
		return -1;
	}

	iter = dir->child;
	while (iter != NULL)
	{
		printf("%s\n", iter->name);
		iter = iter->next;
	}
	return 0;
}

Direktorij* EnterDir(Direktorij * dir, const char * path, const char * name, struct _Stack * stack)
{
	Direktorij *iter = dir->child;

	while (iter != NULL && strcmp(iter->name, name) == 0)
		iter = iter->next;

	if (iter == NULL)
	{
		printf("No such directory exists!\n");
		return dir;
	}
	Push(stack, dir);
	strcat(path, "/");
	strcat(path, iter->name);
	return iter;
}

Direktorij* ExitDir(Direktorij * dir, const char * path, struct _Stack * stack)
{
	Direktorij *temp = NULL;

	temp = Pop(stack);
	if (temp == NULL)
	{
		ErrorHandler(EMPTY_STACK, "ExitDir");
		return dir;
	}

	// Stringove napravit
	return temp;
}
