#pragma once
#include <Windows.h>
#include "values.h"

void toggle_check(char value){

        if (GetAsyncKeyState(VK_INSERT))
        {
            r = TRUE;
        }
        if (GetAsyncKeyState(VK_HOME))
        {
            r = FALSE;
        }
}

void textcolor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        color + (__BACKGROUND << 4));
}

void outputf(char* s, int spec)
{
    int i = 0;
    while (*(s + i) != '\0')
    {
        if (*(s + i) == '+')
        {
            textcolor(2);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == '-')
        {
            textcolor(4);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == '*')
        {
            textcolor(14);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == 'v' && spec == 1)
        {
            textcolor(2);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == 'l' && spec == 1)
        {
            textcolor(2);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == 'p' && spec == 1)
        {
            textcolor(2);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == 'v' && spec == 2)
        {
            textcolor(14);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == 'l' && spec == 2)
        {
            textcolor(14);
            _cprintf("%c", *(s + i));
        }
        else if (*(s + i) == 'p' && spec == 2)
        {
            textcolor(14);
            _cprintf("%c", *(s + i));
        }
        else
        {
            textcolor(15);
            _cprintf("%c", *(s + i));
        }
        i++;
    }
}