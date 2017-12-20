#pragma once
#include <stdio.h>
#include <string.h>

#include "conmanip\consoleInfo.h"

void center_line(const char *text)
{
    int size_text, text_center, text_start;
    int buffer_rows, buffer_cols, buffer_center;
    int i;

    getBufferInfo(&buffer_rows, &buffer_cols);
    size_text = strlen(text);

    buffer_center = buffer_cols / 2;
    text_center = size_text / 2;
    text_start = buffer_center - text_center;

    for(i = 1; i  < text_start; ++i)
    {
        printf(" ");
    }

    printf("%s\n", text);
}