#pragma once
#include <conio.h>
#include <stdlib.h>
#include "helper_fn.h"

#define PROCESS_NAME L"VALORANT  " 

int start() {
    outputf("VLTBT 1.0.1.1 - obscxrxd - 0 at 0 \n", 0);
    outputf("[*] checking for ghub driver...\n", 0);
    Sleep(1000);
    int toleration = 50;
    struct vlp preset;
    preset.x = 20;
    preset.y = 20;
    preset.d = 0;
    if (!mouse_open()) {
        outputf("[-] failed to open ghub macro driver\n", 0);
        return 0;
    }
    else
    {
        outputf("[+] ghub driver is present\n", 0);
    }
    Sleep(1000);
    outputf("[*] getting display capture...\n", 0); // memes 
    Sleep(1000);
    outputf("[+] display capture module loaded\n", 0);


}

void additional() {
    if (GetAsyncKeyState(VK_F9)) {
        outputf("[vlp]", 2); outputf(" modify preset : \n", 0);
        outputf("[#] Modify X amount (0-99): ", 0);
        scanf_s("%d", &data_vlp.x);
        outputf("[#] Modify Y amount (0-99): ", 0);
        scanf_s("%d", &data_vlp.y);
        outputf("[#] Modify D amount (0-250): ", 0);
        scanf_s("%d", &data_vlp.d);
        outputf("[#] Modify R amount (0-5): ", 0);
        scanf_s("%d", &data_vlp.r);
        outputf("[vlp]", 1); outputf("preset set\n", 0);
    }
}

void run() {
    outputf("[*] modify presets <F9>\n", 0);
    HWND game_window;
    game_window = FindWindowW(NULL, PROCESS_NAME);
    HDC hDC1 = GetDC(game_window);
    POINT pt1;
    COLORREF rgb1;
    BOOL color_check;

    while (1) {
        toggle_check('r');
        additional();
        if (GetAsyncKeyState(VK_LSHIFT)) {
            while (1) {
                if (!GetAsyncKeyState(VK_LSHIFT))
                    break;
                color_check = scan(hDC1, 960, 540);
                if (color_check == TRUE) {
                    mouse_move((char)1, (char)0, (char)0, (char)0);
                    Sleep(1);
                    mouse_move((char)0, (char)0, (char)0, (char)0);
                    Sleep(1);
                    //printf("SHOOT \n");
                    Sleep(100);
                    break;
                }
            }
        }

        if (r) {
            if (GetAsyncKeyState(VK_LBUTTON)) {
                while (1) {
                    if (!GetAsyncKeyState(VK_LBUTTON))
                        break;
                    mouse_move((char)0, (char)0, (char)data_vlp.r, (char)0);
                    Sleep(1);
                }
            }
        }
        Sleep(1);
    }
}

