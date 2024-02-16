#include "tessera.h"
#include "lista.h"
#include "interattiva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int a = menu_scelta();
    Lista_doppia mano;
    crea_lista(a, &mano);
    stampa_mano(&mano);
    Lista_doppia tab;
    Nodo* tmp = pop_casuale(&mano, 5);
    tabellone(tmp, &tab, 5);
    stampa_lista(&tab);
    return 0;
}
