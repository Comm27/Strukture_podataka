#pragma once
#include <signal.h>

#define LINUX 1
#define WINDOWS 2

#ifdef __linux__
    #include <sys/ioctl.h>
    #include <unistd.h>
    #define OS LINUX
#elif _WIN32
    #include <Windows.h>
    #define OS WINDOWS
#endif

void getBufferInfo(int *rows, int *cols)
{
    #if OS == LINUX
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        *rows = w.ws_row;
        *cols = w.ws_col;
    #elif OS == WINDOWS
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        *cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        *rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    #endif
}

void handle_winch(int sig)
{
    int i = 0;
#if OS == LINUX
    signal(SIGWINCH, SIG_IGN);
#endif
}