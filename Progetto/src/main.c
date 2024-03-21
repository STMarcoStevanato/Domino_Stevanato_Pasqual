#include "tessera.h"
#include "lista.h"
#include "interattiva.h"
#include <stdio.h>
#include "controllo.h"
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
    crea_lista_vuota(&tavolo);
    int scelta = 0;
    while (true) {
        //system("cls");
        scelta = scelta_tessera(&mano);
        // gira_tessera(&mano,scelta);
        tessera_campo(&mano, &tavolo, scelta);
        stampa_lista_numerata(&tavolo);
        stampa_lista_numerata(&mano);
    }
    return 0;
}
