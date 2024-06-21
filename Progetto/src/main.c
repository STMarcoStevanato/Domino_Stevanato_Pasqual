#include "lista.h"
#include "controllo.h"
#include "ai.h"
#include "partita.h"
#include "tessera.h"
#include "interattiva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numero_tessere = menu_scelta();
    Lista_doppia mano;
    crea_lista(numero_tessere, &mano);
    stampa_lista_numerata(&mano);
    Lista_doppia tavolo;
    crea_lista_vuota(&tavolo);
    int scelta = menu_modalita();

    if (scelta == 1) {
        while (game_continue(&tavolo, &mano)) {
            scelta = scelta_tessera(&mano);
            // gira_tessera(&mano,scelta);
            tessera_campo(&mano, &tavolo, scelta);
            stampa_lista_numerata(&tavolo);
            if (mano.testa) stampa_lista_numerata(&mano);
        }
    } else stampa_lista_numerata(settings(&mano));

    stampa_punteggio();
    return 0;
}
