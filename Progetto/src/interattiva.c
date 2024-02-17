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
            printf("Si prega di selezionare una opzione dall menu :)\n");
    }while(scelta < 0 || scelta > 4);

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
        Nodo *a = pop_indice(mano, i);
        inizializza_valore(a, tavolo);
    } else {
        //Implementare
    }
}

void tabellone(Nodo* ptr, Lista_doppia* a, int left) {
    static int first = 1;
    if (first == 1) {
        inizializza_valore(ptr, a);
        return;
    } else {
        switch (left) {
            case 1: // left
                push_front_valore(ptr, a);
                break;
            case 0: // right
                push_back_valore(ptr, a);
                break;
            default: // error catcher
                fprintf(stderr, "Please select a valid entry for where you want to put your piece");
                exit(EXIT_FAILURE);
        }
    }
    first = 0;
}

int controllo_dx(Nodo* a, Lista_doppia* tavolo) {

}

int controllo_lx(Nodo* a, Lista_doppia* tavolo) {

}