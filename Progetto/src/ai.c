#include "tessera.h"
#include "lista.h"
#include "interattiva.h"
#include "partita.h"
#include "controllo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "ai.h"


void settare(Lista_doppia* mano, Lista_doppia* salvata) {
    printf("settare\n");
    Lista_doppia risultante;
    inizializza_vuota(&risultante);
    inizializza_vuota(salvata);
    combinazioni(mano, &risultante, salvata);
    score_completo(salvata);
    return;
}
void combinazioni(Lista_doppia* mano, Lista_doppia* risultante, Lista_doppia* salvata) {
    printf("combinazioni\n");
    if(!game_continue(risultante, mano)) {
        printf("game\n");
        if(valore_lista(salvata) < valore_lista(risultante)) {
            *salvata = copyList(risultante);
        }
        stampa(risultante);
        stampa(salvata);
        return;
    }
    Nodo* corrente = mano->testa;
    while(corrente) {
        printf("while\n");
        if(!risultante->testa) {
            printf("0\n");
            Lista_doppia nuovoRisultante;
            inizializza_valore(corrente, &nuovoRisultante);
            Lista_doppia nuovaMano = copyList(mano);
            pop_tessera(&nuovaMano, corrente);
            combinazioni(&nuovaMano, &nuovoRisultante, salvata);
            free_lista(&nuovoRisultante);
            free_lista(&nuovaMano);
        }
        if(risultante->testa) {
            printf("-\n");
            if(corrente->valore->dx == risultante->testa->valore->sx) {
                printf("1\n");
                stampa_tessera(corrente->valore);
                printf("\n");
                stampa(mano);
                stampa(risultante);
                Lista_doppia nuovoRisultante = copyList(risultante);
                push_front_valore(corrente, &nuovoRisultante);
                Lista_doppia nuovaMano = copyList(mano);
                pop_tessera(&nuovaMano, corrente);
                combinazioni(&nuovaMano, &nuovoRisultante, salvata);
                free_lista(&nuovoRisultante);
                if(nuovaMano.testa) {
                    free_lista(&nuovaMano);
                }
            }
            if(corrente->valore->dx == risultante->coda->valore->dx) {
                printf("2\n");
                stampa_tessera(corrente->valore);
                printf("\n");
                stampa(mano);
                stampa(risultante);
                Lista_doppia nuovoRisultante = copyList(risultante);
                swap(corrente->valore);
                push_back_valore(corrente, &nuovoRisultante);
                swap(corrente->valore);
                Lista_doppia nuovaMano = copyList(mano);
                pop_tessera(&nuovaMano, corrente);
                combinazioni(&nuovaMano, &nuovoRisultante, salvata);
                free_lista(&nuovoRisultante);
                if(nuovaMano.testa) {
                    free_lista(&nuovaMano);
                }
            }
            if(corrente->valore->sx == risultante->testa->valore->sx) {
                printf("3\n");
                stampa_tessera(corrente->valore);
                printf("\n");
                stampa(mano);
                stampa(risultante);
                Lista_doppia nuovoRisultante = copyList(risultante);
                swap(corrente->valore);
                push_front_valore(corrente, &nuovoRisultante);
                swap(corrente->valore);
                Lista_doppia nuovaMano = copyList(mano);
                pop_tessera(&nuovaMano, corrente);
                combinazioni(&nuovaMano, &nuovoRisultante, salvata);
                free_lista(&nuovoRisultante);
                if(nuovaMano.testa) {
                    free_lista(&nuovaMano);
                }
            }
            if(corrente->valore->sx == risultante->coda->valore->dx) {
                printf("4\n");
                stampa_tessera(corrente->valore);
                printf("\n");
                stampa(mano);
                stampa(risultante);
                Lista_doppia nuovoRisultante = copyList(risultante);
                push_back_valore(corrente, &nuovoRisultante);
                Lista_doppia nuovaMano = copyList(mano);
                pop_tessera(&nuovaMano, corrente);
                combinazioni(&nuovaMano, &nuovoRisultante, salvata);
                free_lista(&nuovoRisultante);
                if(nuovaMano.testa) {
                    free_lista(&nuovaMano);
                }
            }
        }
        corrente = corrente->prossimo;
    }
}