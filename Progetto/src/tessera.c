#include "tessera.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

void set_tessera(Tessera* tessera, int dx, int sx) {
    tessera->dx = dx;
    tessera->sx = sx;
}

void set_tessera_random(Tessera* tessera) {
    int sx = rand() % 6 + 1; // min = 1, max = 6
    int dx = rand() % (7 - sx) + sx; // min = sx, max = 6
    tessera->sx = sx;
    tessera->dx = dx;
}

void swap(Tessera* tessera) {
    int tmp = tessera->dx;
    tessera->dx = tessera->sx;
    tessera->sx = tmp;
}

void stampa_tessera(Tessera* tessera) {
    printf("[ %d | %d ] ", tessera->sx,tessera->dx);
}