#ifndef TESSERA_H
#define TESSERA_H

typedef struct Tessera {
    int sx;
    int dx;
} Tessera;

void set_tessera(Tessera* tessera, int dx, int sx);
void set_tessera_random(Tessera* tessera);
void stampa_tessera(Tessera* tessera);
void swap(Tessera* tessera);
int val_tessera(Tessera* tessera);

#endif