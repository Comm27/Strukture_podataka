#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "Directory.h"
#include "Stack.h"

int main(int argc, char *argv[])
{
	Directory *rootDir = NULL;
	Directory *currentDir = NULL, *tempDir = NULL;
	Stack *stack = NULL;

	char command[10], argument[100];

	rootDir = CreateDirectoryNode("root");
	currentDir = rootDir;
	stack = CreateNode();


	while (1)
	{
		memset(command, 0, 10);
		memset(argument, 0, 100);
		printf("%s >>", currentDir->filePath);
		scanf("%s %s", command, argument);

		if (strcmp(command, "exit") == 0)
			break;
		else if (strcmp(command, "cd") == 0)
		{
			if (strcmp(argument, "..") == 0)
			{
				if (Top(stack) == NULL)
				{
					printf("Stack is empty! You are in root folder!\n");
					continue;
				}
				currentDir = Top(stack)->dir;
				Pop(stack);
			}
			else
			{
				tempDir = ChangeDirectory(currentDir, argument);
				if (tempDir == NULL)
					printf("No such directory exists!\n");
				else
				{
					Push(stack, currentDir);
					currentDir = tempDir;
				}
			}
		}
		else if (!strcmp(command, "mkdir"))
		{
			if (AddDirectory(currentDir, argument) < 0)
			{
				printf("Could not allocate new memory block!\n");
			}
		}
		else if (strcmp(command, "ls") == 0)
		{
			PrintDirectories(currentDir);
		}
		else if (strcmp(command, "pwd") == 0)
		{
			printf("%s\n", currentDir->filePath);
		}
		else
		{
			printf("No such command exists!\n");
		}
	}

	free(stack);
	free(rootDir);

	return 0;
}