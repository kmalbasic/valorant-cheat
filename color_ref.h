#pragma once
#include <Windows.h>
#include "mouse.h"
#include <stdio.h>
#include "config.h"
struct vlp data_vlp;

BOOL is_purple(unsigned short red, unsigned short green, unsigned short blue) {

    if (green >= 170) {
        return FALSE;
    }

    if (green >= 120) {
        return abs(red - blue) <= 8 &&
            red - green >= 50 &&
            blue - green >= 50 &&
            red >= 105 &&
            blue >= 105;
    }

    return abs(red - blue) <= 13 &&
        red - green >= 60 &&
        blue - green >= 60 &&
        red >= 110 &&
        blue >= 100;

}

BOOL scan(HDC dc, int area_x, int area_y) {
    COLORREF col;
    for (int y = data_vlp.y * (-1); y < data_vlp.y; ++y) {

        for (int x = data_vlp.x * (-1); x < data_vlp.x; ++x) {

            col = GetPixel(dc, area_x + x, area_y + y);
            if (is_purple((short)GetRValue(col), (short)GetGValue(col), (short)GetBValue(col))) {
                return TRUE;
            }
        }
    }
    return FALSE;
}