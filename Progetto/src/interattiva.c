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
        Nodo* a = pop_indice(mano, i);
        inizializza_valore(a, tavolo);
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
                pop_indice(mano, i);
                push_front_valore(b, tavolo);
            }
            else if (scelta == 0) {
                pop_indice(mano, i);
                push_back_valore(b, tavolo);
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
                pop_indice(mano, i);
                push_front_valore(b, tavolo);
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
                pop_indice(mano, i);
                push_back_valore(b, tavolo);
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
                pop_indice(mano, i);
                push_back_valore(b, tavolo);
            }
            else if (scelta == 0) {
                pop_indice(mano, i);
                swap(b->valore);
                push_front_valore(b, tavolo);
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
                pop_indice(mano, i);
                push_front_valore(b, tavolo);
            }
            else if (scelta == 0){
                pop_indice(mano, i);
                swap(b->valore);
                push_back_valore(b, tavolo);
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
                pop_indice(mano, i);
                swap(b->valore);
                push_front_valore(b, tavolo);
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
                pop_indice(mano, i);
                swap(b->valore);
                push_back_valore(b, tavolo);
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
                pop_indice(mano, i);
                swap(b->valore);
                push_back_valore(b, tavolo);
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
                pop_indice(mano, i);
                swap(b->valore);
                push_front_valore(b, tavolo);
            }
            else if (scelta == 0) {
                pop_indice(mano, i);
                swap(b->valore);
                push_back_valore(b, tavolo);
            }
        }
    }
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