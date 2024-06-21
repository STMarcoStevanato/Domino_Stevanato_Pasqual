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
    int a = menu_scelta();
    Lista_doppia mano;
    crea_lista(a, &mano);
    stampa_lista_numerata(&mano);
    Lista_doppia tavolo;
    crea_lista_vuota(&tavolo);
    int scelta = 0;
    printf("scegliere modalita: \n");
    printf("1 --> itterativa \n");
    printf("2 --> ai \n");
    char option;
    do {
        scanf()
    }
    /*
    while (game_continue(&tavolo, &mano)) {
        //system("cls");
        scelta = scelta_tessera(&mano);
        // gira_tessera(&mano,scelta);
        tessera_campo(&mano, &tavolo, scelta);
        stampa_lista_numerata(&tavolo);
        if(mano.testa) stampa_lista_numerata(&mano);
    }
    */
    stampa_lista_numerata(settings(&mano));
    printf("-------------------------------------------------\n");
    printf("Game Over, your score was %d\n", get_score());
    printf("-------------------------------------------------\n");
    return 0;
}
