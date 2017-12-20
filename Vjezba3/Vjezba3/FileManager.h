#pragma once
#include <stdio.h>
#include <stdlib.h>

const char* ReadFile(char *filepath)
{
	char *buffer = NULL;
	FILE *file = fopen(filepath, "r");
	int file_len = 0;

	if (file == NULL)
	{
		//ErrorHandler(NO_FILE_FOUND, "ReadFile");
		return NULL;
	}
	fseek(file, 0L, SEEK_END);
	file_len = ftell(file);
	fseek(file, 0L, SEEK_SET);

	printf("File length: %d", file_len);
	buffer = (char*)malloc(file_len * sizeof(char));
	if (fgets(buffer, file_len, file) == NULL)
	{
		printf("Could not read file!\n");
		fclose(file);
		free(buffer);
		return NULL;
	}
	fclose(file);
	return buffer;
}