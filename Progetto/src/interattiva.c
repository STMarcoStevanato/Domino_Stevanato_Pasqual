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

int scelta_tessera(Lista_doppia* ptr) {
    int tessera = 0;
    int num_tessere = num_elementi(ptr);
    do {
        printf("Selezionare quale tessera posizionare sul campo: ");
        scanf("%d", &tessera);
        if (num_tessere < tessera || tessera < 1)
            printf("Si prega di inserire un numero valido \n");
    }while(num_tessere < tessera || tessera < 1);
    printf("\n");
    return tessera;
}

void gira_tessera(Lista_doppia* ptr, int i) {
    Nodo* a = get_nodo(ptr,i);
    if (a->valore->dx != a->valore->sx) {
        printf("Vuoi girare la tessere che hai selezionato?\n");
        stampa_tessera(a->valore);
        printf("<---> ");
        printf("[ %d | %d ] \n", a->valore->dx,a->valore->sx);
        printf("\n");
        printf("Vuoi girare la tessera? \n");
        int scelta = 0;
        do {
            printf("Digitare 1 per SI. Digitare 0 per NO: ");
            scanf("%d", &scelta);
            if (scelta < 0 || 1 < scelta)
                printf("Si prega di inserire un numero valido \n");
        }while (scelta < 0 || 1 < scelta);

        if (scelta) {
            printf("La tessera e' stata girata\n");
            swap(a->valore);
        }
    }

}


void tessera_campo(Lista_doppia* mano, Lista_doppia* tavolo, int i) {
    if (tavolo->testa == NULL) {
        Nodo* a = get_nodo(mano, i);
        inizializza_valore(a, tavolo);
        score(a);
        pop_indice(mano, i);
    } else {
        Nodo* b = get_nodo(mano, i);
        int dx = controllo_dx(b, tavolo);
        int sx = controllo_sx(b, tavolo);
        int scelta = 0;
        if (dx == 0 && sx == 0)
            printf("La tessera selezionata non e' valida\n");
        else if (dx == 1 && sx == 1) {
            do {
                printf("Inserire tessera a destra = 0 | Inserire tessera a sinistra = 1 | Tornare indietro = 2\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 2 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 2 < scelta);
            if (scelta == 1) {
                push_front_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
            else if (scelta == 0) {
                push_back_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 0 && sx == 1) {
            do {
                printf("La tessera puo essere posizionata solo a sinistra, continuare = 1 e tornare indietro = 0\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 1 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 1 < scelta);
            if (scelta == 1) {
                push_front_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 1 && sx == 0) {
            do {
                printf("La tessera puo essere posizionata solo a destra, continuare = 1 e tornare indietro = 0\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 1 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 1 < scelta);
            if (scelta == 1) {
                push_back_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 1 && sx == 2) {
            do {
                printf("Ruotare tessera e inserire a sinistra = 0 | Inserire tessera a destra = 1 | Tornare indietro = 2\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 2 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 2 < scelta);
            if (scelta == 1) {
                push_back_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
            else if (scelta == 0) {
                swap(b->valore);
                push_front_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 2 && sx == 1) {
            do {
                printf("Ruotare tessera e inserire a destra = 0 | Inserire tessera a sinistra = 1 | Tornare indietro = 2\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 2 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 2 < scelta);
            if (scelta == 1) {
                push_front_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
            else if (scelta == 0){
                swap(b->valore);
                push_back_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 0 && sx == 2) {
            do {
                printf("La tessera puo essere posizionata solo a sinistra, se ruotata, continuare = 1 e tornare indietro = 0\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 1 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 1 < scelta);
            if (scelta == 1) {
                swap(b->valore);
                push_front_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 2 && sx == 0) {
            do {
                printf("La tessera puo essere posizionata solo a destra, se ruotata, continuare = 1 e tornare indietro = 0\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 1 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 1 < scelta);
            if (scelta == 1) {
                swap(b->valore);
                push_back_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 2 && sx == 1) {
            do {
                printf("La tessera puo essere posizionata solo a destra, se ruotata, continuare = 1 e tornare indietro = 0\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 1 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 1 < scelta);
            if (scelta == 1) {
                swap(b->valore);
                push_back_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
        else if (dx == 2 && sx == 2) {
            do {
                printf("Ruotare tessera e inserire a destra = 0 | Ruotare e inserire tessera a sinistra = 1 | Tornare indietro = 2\n");
                scanf("%d", &scelta);
                if (scelta < 0 || 2 < scelta)
                    printf("Numero selezionato non valido\n");
            } while (scelta < 0 || 2 < scelta);
            if (scelta == 1) {
                swap(b->valore);
                push_front_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
            else if (scelta == 0) {
                swap(b->valore);
                push_back_valore(b, tavolo);
                score(b);
                pop_indice(mano, i);
            }
        }
    }
}