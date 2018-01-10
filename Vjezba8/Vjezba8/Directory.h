#pragma once

struct _Directory;
typedef struct _Directory Directory;

struct _Directory
{
	char name[100];
	char filePath[256];
	Directory *next;
	Directory *child;
};

Directory* CreateDirectoryNode(const char *name);
int AddDirectory(Directory *currentDir, const char *name);

Directory* FindPrevDirectory(Directory *currentDir, const char *name);
Directory* FindDirectory(Directory *currentDir, const char *name);

Directory* ChangeDirectory(Directory *currentDir, const char *name);

int PrintDirectories(Directory *currentDir);
int RemoveDirectory(Directory *currentDir, const char *name);