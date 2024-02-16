#include "tessera.h"
#include "lista.h"
#include "interattiva.h"
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
            printf("Input il numero di tessere con le quali si vuole giocare: ");
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

void stampa_mano(Lista_doppia* ptr) {
    int condizione = 10;
    int i = 1;
    if (ptr == NULL || ptr->testa == NULL) {
        printf("CANNOT PRINT, BECAUSE LIST IS EMPTY");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    Nodo* corrente = ptr->testa;
    while (corrente != NULL) {
        stampa_tessera(corrente->valore);
        corrente = corrente->prossimo;
        if (condizione<=i) {
            printf("\n");
            for (int j = 0; j<10; j++) {
                if (i == 10) printf("    %d     ", j);
                else printf("    %d    ", (i+j)-10);
            }
            printf("\n");
            printf("\n");
            condizione += 10;
        }
        i++;
    }
    printf("\n");
}
