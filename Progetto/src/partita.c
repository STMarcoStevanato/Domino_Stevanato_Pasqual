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

int scr = 0;

int menu_scelta() {
    int scelta = 0;
    do {
        printf("\n");
        printf("Selezionare con quante tessere iniziare:\n");
        printf("10        20        30        casuale   personalizzato\n");
        printf("0         1         2         3         4\n");
        printf("\n");
        scanf("%d",&scelta);
        if (scelta < 0 || scelta > 4)
            printf("Si prega di selezionare una opzidcone dall menu :)\n");
    }while(scelta < 0 || scelta > 4);
    system("cls");

    switch (scelta) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 30;
        case 3:
            return rand() % 50 + 10;
        case 4: {
            int tmp = 1;
            int n = 0;
            printf("Selezionare il numero di tessere con le quali si vuole giocare: ");
            do {
                scanf("%d", &n);
                if (n < 0) {
                    printf("Si prega di mettere un numero positivo di tessere");
                    continue;
                } else if (n < 5) {
                    printf("Si prega di mettere almeno 5 tessere");
                    continue;
                }
                tmp = 0;
            } while (tmp);
            return n;
        }
    }
}

int menu_modalita() {
    int scelta = 0;
    do {
        printf("scegliere modalita: \n");
        printf("1 --> itterativa \n");
        printf("2 --> ai \n");
        scanf("%d",&scelta);
        if (scelta != 1 && scelta != 2)
            printf("Inserire un numero valido");
    }while (scelta != 1 && scelta != 2);
    return scelta;
}

int controllo_dx(Nodo* ptr, Lista_doppia* tavolo) {
    puntatore_nullo_memory(tavolo);
    int ptr_sx = 0;
    int ptr_dx = 0;
    int tavolo_dx = 0;
    ptr_sx = ptr->valore->sx;
    ptr_dx = ptr->valore->dx;
    tavolo_dx = tavolo->coda->valore->dx;
    if (ptr_sx == tavolo_dx) {
        return 1;
    }
    else if (ptr_dx == tavolo_dx) {
        return 2;
    }
    else {
        return 0;
    }
}

int controllo_sx(Nodo* ptr, Lista_doppia* tavolo) {
    puntatore_nullo_memory(tavolo);
    int ptr_dx = 0;
    int ptr_sx = 0;
    int tavolo_sx = 0;
    ptr_dx = ptr->valore->dx;
    ptr_sx = ptr->valore->sx;
    tavolo_sx = tavolo->testa->valore->sx;
    if (ptr_dx == tavolo_sx) {
        return 1;
    }
    else if (ptr_sx == tavolo_sx) {
        return 2;
    }
    else {
        return 0;
    }
}

void score(Nodo* nuovaTessera) {
    puntatore_nullo_memory(nuovaTessera);
    scr += nuovaTessera->valore->sx + nuovaTessera->valore->dx;
    system("cls");
    printf("Punteggio ---> %d\n", scr);
    printf("\n");
}

void score_ai(Lista_doppia* ptr) {
    Nodo* corrente = ptr->testa;
    int cnt = 0;
    while(corrente) {
        cnt += val_tessera(corrente->valore);
        corrente = corrente->prossimo;
    }
    scr = cnt;
}

int game_continue(Lista_doppia* tavolo, Lista_doppia* mano) {
    if (!tavolo->testa) {
        return true;
    }

    Nodo* tmp_ptr = mano->testa;
    while(tmp_ptr) {
        if (tmp_ptr->valore->sx == tavolo->testa->valore->sx || tmp_ptr->valore->dx == tavolo->testa->valore->sx) {
            return true;
        } else if (tmp_ptr->valore->sx == tavolo->coda->valore->dx || tmp_ptr->valore->dx == tavolo->coda->valore->dx) {
            return true;
        }
        tmp_ptr = tmp_ptr->prossimo;
    }
    return false;
}

int get_score() {
    return scr;
}

void stampa_punteggio() {
    printf("-------------------------------------------------\n");
    printf("Game Over, your score was %d\n", get_score());
    printf("-------------------------------------------------\n");
}