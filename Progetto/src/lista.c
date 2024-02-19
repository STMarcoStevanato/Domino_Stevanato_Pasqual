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

/*MEX devi
 *3) sistemare i warning*/

void inizializza_random(Lista_doppia* ptr) {
    Nodo* nuovoNodo = malloc(sizeof(Nodo));
    puntatore_nullo_memory(nuovoNodo);
    nuovoNodo->valore = malloc(sizeof(Tessera));
    puntatore_nullo_memory(nuovoNodo->valore);
    set_tessera_random(nuovoNodo->valore);
    nuovoNodo->prossimo = NULL;
    nuovoNodo->previo = NULL;
    ptr->testa = nuovoNodo;
    ptr->coda = nuovoNodo;
}

void inizializza_valore(Nodo* ptr, Lista_doppia* a) {
    Nodo* nuovoNodo = malloc(sizeof(Nodo));
    puntatore_nullo_memory(nuovoNodo);
    nuovoNodo->valore = malloc(sizeof(Tessera));
    puntatore_nullo_memory(nuovoNodo->valore);
    nuovoNodo->valore->sx = ptr->valore->sx;
    nuovoNodo->valore->dx = ptr->valore->dx;
    nuovoNodo->prossimo = NULL;
    nuovoNodo->previo = NULL;
    a->testa = nuovoNodo;
    a->coda = nuovoNodo;
    free(ptr);
}

void push_front_random(Lista_doppia* ptr) {
    if (ptr->testa == NULL) {
        inizializza_random(ptr);
    }
    else {
        Nodo* nuovoNodo = malloc(sizeof(Nodo));
        puntatore_nullo_memory(nuovoNodo);
        nuovoNodo->valore = malloc(sizeof(Tessera));
        puntatore_nullo_memory(nuovoNodo->valore);
        set_tessera_random(nuovoNodo->valore);
        nuovoNodo->prossimo = ptr->testa;
        nuovoNodo->previo = NULL;
        ptr->testa->previo = nuovoNodo;
        ptr->testa = nuovoNodo;
    }
}

void push_back_random(Lista_doppia* ptr) {
    if (ptr->testa == NULL) {
        inizializza_random(ptr);
    }
    else {
        Nodo* nuovoNodo = malloc(sizeof(Nodo));
        puntatore_nullo_memory(nuovoNodo);
        nuovoNodo->valore = malloc(sizeof(Tessera));
        puntatore_nullo_memory(nuovoNodo->valore);
        set_tessera_random(nuovoNodo->valore);
        nuovoNodo->prossimo = NULL;
        nuovoNodo->previo = ptr->coda;
        ptr->coda->prossimo = nuovoNodo;
        ptr->coda = nuovoNodo;
    }
}

void push_front_valore(Nodo* ptr, Lista_doppia* a) {
    if (a->testa == NULL) {
        inizializza_valore(ptr, a);
    }
    else {
        Nodo* nuovoNodo = malloc(sizeof(Nodo));
        puntatore_nullo_memory(nuovoNodo);
        nuovoNodo->valore = malloc(sizeof(Tessera));
        puntatore_nullo_memory(nuovoNodo->valore);
        nuovoNodo->valore->sx = ptr->valore->sx;
        nuovoNodo->valore->dx = ptr->valore->dx;
        nuovoNodo->prossimo = a->testa;
        nuovoNodo->previo = NULL;
        a->testa->previo = nuovoNodo;
        a->testa = nuovoNodo;
        free(ptr);
    }
}

void push_back_valore(Nodo* ptr, Lista_doppia* a) {
    if (a->testa == NULL) {
        inizializza_valore(ptr, a);
    }
    else {
        Nodo* nuovoNodo = malloc(sizeof(Nodo));
        puntatore_nullo_memory(nuovoNodo);
        nuovoNodo->valore = malloc(sizeof(Tessera));
        puntatore_nullo_memory(nuovoNodo->valore);
        nuovoNodo->valore->sx = ptr->valore->sx;
        nuovoNodo->valore->dx = ptr->valore->dx;
        nuovoNodo->prossimo = NULL;
        nuovoNodo->previo = a->coda;
        a->coda->prossimo = nuovoNodo;
        a->coda = nuovoNodo;
        free(ptr);
    }
}

// cancellazione di tessera tramite indice e poi return di nodo in indice cancellato
/*Nodo* pop_indice(Lista_doppia* ptr, int i) {
    Nodo* a = ptr->testa->prossimo;
    Nodo* corrente = ptr->testa;//PROBLEMA
    //printf("%d\n", corrente->valore->dx);
    Nodo* b = NULL;
    while(i) {
        b = corrente;
        corrente = corrente->prossimo;
        a = corrente->prossimo;
        i--;
    }
    b->prossimo = a;
    a->previo = b;
    return corrente;
}*/

Nodo* pop_indice(Lista_doppia* ptr, int i) {
    Nodo* corrente = ptr->testa;
    Nodo* a = NULL;
    Nodo* b = NULL;
    while(i > 0 && corrente != NULL) {
        b = corrente;
        corrente = corrente->prossimo;
        //a = corrente->prossimo;
        i--;
    }
    a = corrente->prossimo;

    // Gestione del primo elemento della lista
    if (b == NULL) {
        ptr->testa = a;
        if (a != NULL) {
            a->previo = NULL;
        }
    } else {
        b->prossimo = a;
        if (a != NULL) {
            a->previo = b;
        }
    }

    // Gestione dell'ultimo elemento della lista
    if (a == NULL) {
        // Se a è NULL, corrente è l'ultimo elemento della lista, aggiorna la coda
        ptr->coda = b;
    }

    return corrente;
}

void crea_lista(int n, Lista_doppia* a) {
    a->testa = NULL;
    a->coda = NULL;
    inizializza_random(a);
    for (int i = 1; i<n; i++) push_back_random(a);
}

void crea_lista_vuota(Lista_doppia* a) {
    a->testa = NULL;
    a->coda = NULL;
}

void stampa_lista(Lista_doppia* ptr) {
    puntatore_nullo_data(ptr, ptr->testa);
    Nodo* corrente = ptr->testa;
    while (corrente != NULL) {
        stampa_tessera(corrente->valore);
        corrente = corrente->prossimo;
    }
}

void stampa_lista_numerata(Lista_doppia* ptr) {
    puntatore_nullo_data(ptr, ptr->testa);
    printf("\n");
    int condizione = 10;
    int i = 1;
    Nodo* corrente = ptr->testa;
    while (corrente != NULL) {
        stampa_tessera(corrente->valore);
        corrente = corrente->prossimo;
        if (condizione<=i) { //Ogni 10 tessere andare a capo e numerarle
            printf("\n");
            for (int j = 1; j<=10; j++) {
                if (i == 10) printf("    %d     ", j);
                else printf("    %d    ", (i+j)-10);
            }
            printf("\n");
            printf("\n");
            condizione += 10;
        }
        i++;
    }
    i--;
    if (i != condizione-10) {
        printf("\n");
        int num_tessere = i-(condizione-10);
        for (int j = 1; j<=num_tessere; j++) {
            if (i < 10) printf("    %d     ", j);
            else printf("    %d    ", (i+j)-num_tessere);
        }
        printf("\n");
    }
}

int num_elementi(Lista_doppia* ptr) {
    int i = 0;
    Nodo* corrente = ptr->testa;
    while (corrente != NULL) {
        corrente = corrente->prossimo;
        i++;
    }
    return  i;
}

Nodo* get_nodo(Lista_doppia* ptr, int i) {
    int j = 1;
    Nodo* corrente = ptr->testa;
    while (corrente != NULL && j < i) {
        corrente = corrente->prossimo;
        j++;
    }
    return corrente;
}

void free_lista(Lista_doppia* ptr) {
    puntatore_nullo_data(ptr, ptr->testa);
    Nodo* a = ptr->testa;
    Nodo* b = NULL;

    while (a) {
        b = a;
        a = a->prossimo;
        free(b->valore);
        free(b);
    }
    ptr->testa = NULL;
    ptr->coda = NULL;
}