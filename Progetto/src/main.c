#include "tessera.h"
#include "lista.h"
#include "interattiva.h"
#include "controllo.h"
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
    stampa_lista_numerata(&mano);
    Lista_doppia tavolo;
    int scelta = scelta_tessera(&mano);
    gira_tessera(&mano,scelta);
    //Nodo* b = pop_indice(&mano, scelta);
    //Nodo* t = pop_indice(&mano, 6);
    //tabellone(b, &tavolo, 5);
    stampa_lista_numerata(&tavolo);
    //stampa_lista_numerata(&mano);
    return 0;
}
