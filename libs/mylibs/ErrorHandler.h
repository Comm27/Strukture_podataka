#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <stdio.h>

#define ALLOC_FAILED 0x0700
#define NULL_ARG 0x0701
#define NO_OBJECT_FOUND 0x0702
#define UNDEFINED_POSITION 0x0703
#define NO_FILE_FOUND 0x0704
#define WRONG_INPUT 0x0705
#define EMPTY_STACK 0x0706
#define EMPTY_QUEUE 0x0707

int ErrorHandler(int arg_error, const char *funcName)
{
	switch (arg_error)
	{
	case ALLOC_FAILED:
		printf("ERROR::%s::Allocation FAILED!\n", funcName);
		break;
	case NULL_ARG:
		printf("ERROR::%s::NULL ARGUMENT SENT!\n", funcName);
		break;
	case NO_OBJECT_FOUND:
		printf("%s: No object with specified last name found!\n", funcName);
		break;
	case UNDEFINED_POSITION:
		printf("ERROR::%s::Allocation FAILED!\n", funcName);
		break;
	case NO_FILE_FOUND:
		printf("ERROR::%s: No file found!\n", funcName);
		break;
	case EMPTY_STACK:
		printf("ERROR::%s: Stack is empty!\n", funcName);
		break;
	default:
		printf("ERROR::%s::Undefined error message type!\n", funcName);
		break;
	}

	return -1;
}
#endif