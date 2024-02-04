#ifndef TESSERA_H
#define TESSERA_H

typedef struct Tessera {
    int sx;
    int dx;
} Tessera;

extern void set_tessera(Tessera* tessera, int dx, int sx);
extern void set_tessera_random(Tessera* tessera);
extern void swap(Tessera* tessera);
extern void stampa_tessera(Tessera* tessera);

#endif