#include "Directory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Directory* CreateDirectoryNode(char * name)
{
	char tempfilePath[256];
	Directory *node = (Directory*)malloc(sizeof(Directory));
	if (node == NULL)
	{
		return NULL;
	}

	strcpy(tempfilePath, name);
	strcat(tempfilePath, "/");

	strcpy(node->name, name);
	strcpy(node->filePath, tempfilePath);

	node->child = NULL;
	node->next = NULL;

	return node;
}

int AddDirectory(Directory * currentDir, const char * name)
{
	char tempfilePath[256];
	Directory *node = CreateDirectoryNode(name);
	if (node == NULL)
		return -1;

	strcpy(tempfilePath, currentDir->filePath);
	strcat(tempfilePath, node->filePath);

	strcpy(node->filePath, tempfilePath);
	node->next = currentDir->child;
	currentDir->child = node;
	
	return 0;
}

Directory* FindPrevDirectory(Directory * currentDir, const char * name)
{
	Directory *iter = currentDir->child;
	if (iter == NULL)
		return NULL;
	if (strcmp(iter->name, name) == 0)
		return iter;

	while (iter->next != NULL && strcmp(iter->next->name, name))
		iter = iter->next;

	return iter;
}

Directory* FindDirectory(Directory * currentDir, const char * name)
{
	Directory *temp = NULL;
	temp = FindPrevDirectory(currentDir, name);
	if (temp == NULL)
		return NULL;
	if (strcmp(temp->name, name) == 0)
		return temp;

	return temp->next;
}

Directory* ChangeDirectory(Directory * currentDir, const char * name)
{
	return FindDirectory(currentDir, name);
}

int PrintDirectories(Directory * currentDir)
{
	Directory *iter = currentDir->child;
	if (iter == NULL)
	{
		printf("Empty directory.\n");
		return -1;
	}
	while (iter != NULL)
	{
		printf("%s\n", iter->name);
		iter = iter->next;
	}
	return 0;
}

int RemoveDirectory(Directory * currentDir, const char * name)
{
	Directory *toRemove = NULL;
	Directory *tempNode = FindPrevDirectory(currentDir, name);
	if (tempNode == NULL)
	{
		printf("Could not find directory with name: %s\n", name);
		return -1;
	}

	toRemove = tempNode->next;
	tempNode->next = toRemove->next;
	free(toRemove);
	toRemove = NULL;
	return 0;
}