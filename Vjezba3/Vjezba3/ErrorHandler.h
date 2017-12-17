#pragma once
#include <stdio.h>

#define ALLOC_FAILED 0x0700
#define NULL_ARG 0x0701

void ErrorHandler(int arg_error)
{
	switch (arg_error)
	{
	case ALLOC_FAILED:
		printf("ERROR::Allocation FAILED!\n");
		break;
	case NULL_ARG:
		break;
	default:
		break;
	}
}