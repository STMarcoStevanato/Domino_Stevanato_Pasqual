#ifndef LISTA_H
#define LISTA_H

#include "tessera.h"

typedef struct Nodo {
    Tessera* valore;
    struct Nodo* prossimo;
    struct Nodo* previo;
} Nodo;

typedef struct Lista_doppia {
    Nodo* testa;
    Nodo* coda;
} Lista_doppia;

extern void inizializza_random(Lista_doppia* ptr);
extern void inizializza_valore(Nodo* ptr, Lista_doppia* a);
extern void push_front_random(Lista_doppia* ptr);
extern void push_back_random(Lista_doppia* ptr);
extern void push_front_valore(Nodo* ptr, Lista_doppia* a);
extern void push_back_valore(Nodo* ptr, Lista_doppia* a);
extern Nodo* pop_indice(Lista_doppia* ptr, int i);
extern void crea_lista(int n, Lista_doppia* a);
extern void crea_lista_vuota(Lista_doppia* a);
extern void stampa_lista(Lista_doppia* ptr);
extern void stampa_lista_numerata(Lista_doppia* ptr);
extern int num_elementi(Lista_doppia* ptr);
extern Nodo* get_nodo(Lista_doppia* ptr, int i);
extern void free_lista(Lista_doppia* ptr);

#endif
