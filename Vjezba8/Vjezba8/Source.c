#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define NDEBUG
#include <assert.h>

#include "Direktorij.h"
#include "Stack.h"

int main(int argc, char *argv[])
{
	char name[250], command[10], instr[20], path[100];
	int shouldExit = 0;
	Stack *stack = NULL;
	Direktorij *root = NULL;
	Direktorij *currentDir = NULL;

	memset(name, 0, strlen(name));
	memset(command, 0, strlen(command));
	memset(instr, 0, strlen(instr));
	memset(path, 0, strlen(path));

	root = (Direktorij*)malloc(sizeof(Direktorij));
	assert(root);
	strcpy(root->name, "root");
	root->next = NULL;
	root->child = NULL;

	currentDir = root;

	stack = CreateNodeStack();
	assert(stack);

	while (!shouldExit)
	{
		printf("%s %s", path, ">> ");
		scanf("%s %s", command, instr);
		getchar();

		if (strcmp(command, "exit") == 0)
			shouldExit = 1;
		else if (!strcmp(command, "cd"))
		{
			if (strcmp(instr, "..") == 0)
			{
				ExitDir(currentDir, path, stack);
			}
			else
			{
				EnterDir(currentDir, path, instr, stack);
			}
		}
		else if (!strcmp(command, "mkdir"))
		{
			CreateDir(currentDir, instr);
		}
		else if (!strcmp(command, "dir"))
		{
			PrintDir(currentDir);
		}
		else
		{
			printf("Wrong input!\n");
		}

		memset(command, 0, strlen(command));
		memset(instr, 0, strlen(instr));
		printf("\n");
	}

	printf("%s\n", root->name);
	
	free(stack);
	free(root);
	getchar();
	return 0;
}