#pragma once

#include <stdlib.h>


struct vlp {
	int x;
	int y;
	int d;
    int r;
};

void load_vlp(struct vlp a) {
    FILE* fp;
    errno_t fp_ld;
    char str[MAXCHAR];

    struct vlp default_vlp;

    default_vlp.x = 3;
    default_vlp.y = 8;
    default_vlp.d = 0;
    default_vlp.r = 2;

    const char* filename = "configuration.vlp";

    fp_ld = fopen_s(&fp,filename, "r");
    if (fp == NULL) {
        outputf("[-] could not load your configuration\n", 0);
        Sleep(1000);
        outputf("[*] loading default preset...\n", 0);
        a.x = default_vlp.x;
        a.y = default_vlp.y;
        a.d = default_vlp.d;
        a.r = default_vlp.r;
        Sleep(1000);
        outputf("[+] loaded default preset\n", 0);
        return;
    }

    int pass = 0;
    while (fgets(str, 3, fp) != NULL)
    {
        int temp_val = 0;
        temp_val = atoi(str);
        switch (pass) {
        case 0:
            a.x = temp_val;
            break;
        case 1:
            a.y = temp_val;
            break;
        case 2:
            a.d = temp_val;
            break;
        default:
            outputf("[-] error occured during loading the configuration, loading defaults...\n", 0);
            a.x = default_vlp.x;
            a.y = default_vlp.y;
            a.d = default_vlp.d;

            Sleep(1000);
            outputf("[+] loaded default preset\n", 0);
        }
        if (pass > 2) {
            break;
        }
        pass++;     
    }
    outputf("[vlp] x: 3  y: 8  d: 0  r: 2  \n", 1);

    fclose(fp);
    return;
}