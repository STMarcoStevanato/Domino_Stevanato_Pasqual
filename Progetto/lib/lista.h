/**
 * @file lista.h
 * @brief Dichiarazioni di funzioni per la lista.
 *
 */


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

/**
 * @brief inizializza una lista con nodo casuale.
 *
 * Data una lista vuota, la funzione aggiunge come primo elemento della lista un nodo,
 * dove la tessera avra' valori dx e sx casuali
 *
 * @param ptr Puntatore alla lista doppia.
 */

void inizializza_random(Lista_doppia* ptr);

/**
 * @brief inizializza una lista con un nodo.
 *
 * Data una lista vuota e un nodo, la funzione aggiunge come primo elemento della lista il nodo
 * passato in parametro
 *
 * @param ptr Puntatore al nodo che diventera' il primo elemento della lista.
 * @param a Puntatore alla lista doppia
 */

void inizializza_valore(Nodo* ptr, Lista_doppia* a);

/**
 * @brief inizializza una lista.
 *
 * La funzione impostera' la testa e la coda della lista doppia a null
 *
 * @param ptr Puntatore alla lista doppia
 */

void inizializza_vuota(Lista_doppia* ptr);

/**
 * @brief Aggiungi Nodo all'inizio della lista.
 *
 * La funzione aggiungera' un Nodo all'inizio della lista, la Tessera avra'
 * valori casuali per dx e sx
 *
 * @param ptr Puntatore alla lista doppia
 */

void push_front_random(Lista_doppia* ptr);

/**
 * @brief Aggiungi Nodo alla fine della lista.
 *
 * La funzione aggiungera' un Nodo alla fine della lista, la Tessera avra'
 * valori casuali per dx e sx
 *
 * @param ptr Puntatore alla lista doppia
 */

void push_back_random(Lista_doppia* ptr);

/**
 * @brief Aggiungi Nodo all'inizio della lista.
 *
 * Data una Lista doppia e un Nodo, la funzione aggiungera' all'inizio della lista il nodo
 *
 * @param ptr Puntatore al Nodo che verra' inserito all'inizio della lista
 * @param a Puntatore alla Lista Doppia
 */

void push_front_valore(Nodo* ptr, Lista_doppia* a);

/**
 * @brief Aggiungi Nodo alla fine della lista.
 *
 * Data una Lista doppia e un Nodo, la funzione aggiungera' alla fine della lista il nodo
 *
 * @param ptr Puntatore al Nodo che verra' inserito alla fine della lista
 * @param a Puntatore alla Lista Doppia
 */

void push_back_valore(Nodo* ptr, Lista_doppia* a);

/**
 * @brief Elimina il Nodo in posizione i della lista doppia.
 *
 * Data una Lista doppia e un indice, la funzione eliminera' il nodo in posizione i della lista doppia.
 * La funzione non fara' nulla se l'indice e' troppo grande o minore di 0
 *
 * @param ptr Puntatore alla lista doppia
 * @param a indice che rappresenta la posizione del Nodo da eliminare
 */

void pop_indice(Lista_doppia* ptr, int i);

/**
 * @brief Elimina il Nodo .
 *
 * Questa funzione rimuove il nodo specificato dalla lista doppia.
 *
 * @param ptr Puntatore alla lista doppia da cui rimuovere il nodo.
 * @param remove Puntatore al nodo da rimuovere dalla lista doppia.
 * @warning Assicurarsi che il nodo da rimuovere esista nella lista.
 */

void pop_tessera(Lista_doppia* ptr, Nodo* remove);

/**
 * @brief crea una Lista doppia composta da n elementi.
 *
 * Questa funzione crea una Lista Doppia di n elementi. i valori dx e sx delle tessere sono casuali
 *
 * @param n Numero di elementi da aggiungere alla Lista doppia.
 * @param a Puntatore alla lista doppia.
 */

void crea_lista(int n, Lista_doppia* a);

/**
 * @brief crea una Lista doppia vuota
 *
 * Questa funzione imposta la testa e la coda della Lista doppia a null
 *
 * @param a Puntatore alla lista doppia.
 */

void crea_lista_vuota(Lista_doppia* a);

/**
 * @brief Stampa i Nodi della Lista doppia
 *
 * Questa funzione stampa i Nodi della Lista doppia
 *
 * @param ptr Puntatore alla lista doppia.
 */

void stampa_lista(Lista_doppia* ptr);

/**
 * @brief Stampa i Nodi della Lista doppia
 *
 * Questa funzione stampa i Nodi della Lista doppia e i loro indici
 *
 * @param ptr Puntatore alla lista doppia.
 */

void stampa_lista_numerata(Lista_doppia* ptr);

/**
 * @brief Stampa i Nodi della Lista doppia
 *
 * Questa funzione stampa i Nodi della Lista in modo ordinato e differente
 *
 * @param ptr Puntatore alla lista doppia.
 */

void stampa(Lista_doppia* ptr);

/**
 * @brief ritorna il numero degli elementi di una Lista doppia
 *
 * Questa funzione ritorna un intero che corrisponde al numero degli elementi di una Lista doppia
 *
 * @param ptr Puntatore alla lista doppia.
 * @return numero elementi della Lista
 */

int num_elementi(Lista_doppia* ptr);

/**
 * @brief ritorna il Nodo di una Lista doppia in posizione i
 *
 * Questa funzione ritorna il Nodo di una Lista doppia in posizione i
 * @warning accertarsi che l'indice sia maggiore di 0 e minore del numero totale degli elementi
 * della  lista doppia, altrimenti la funzione ritornera' il primo Nodo se i < 0 e l'ultimo Nodo se
 * i > numero elementi della lista
 *
 * @param ptr Puntatore alla lista doppia.
 * @param i Indice del Nodo
 * @return Puntatore al Nodo in posizione i di una Lista doppia
 */

Nodo* get_nodo(Lista_doppia* ptr, int i);

/**
 * @brief Elimina i tutti i Nodi di una lista
 *
 * Questa funzione libera tutta la memoria occupata dai nodi di una lista doppia
 * e imposta i puntatori testa e coda della lista a NULL.
 *
 * @param ptr Puntatore alla lista doppia.
 */

void free_lista(Lista_doppia* ptr);

/**
 * @brief Crea una copia di una lista doppia esistente.
 *
 * Questa funzione crea una nuova lista doppia che è una copia della lista doppia passata
 * come parametro. Ogni nodo della lista originale viene copiato nella nuova lista.
 *
 * @param a Puntatore alla lista doppia da copiare.
 * @return Una nuova lista doppia che è una copia della lista originale.
 *
 */

Lista_doppia copyList(Lista_doppia* a);

/**
 * @brief Calcola il valore totale delle tessere contenute nella Lista doppia.
 *
 * Questa funzione scorre tutta la lista, ad ogni Nodo si calcola la somma dei valori
 * sx e dx delle tessere.
 *
 * @param prt Puntatore alla lista doppia.
 * @return somma dei valori dx e sx di tutte le tessere della Lista doppia.
 *
 */

int valore_lista(Lista_doppia* ptr);

#endif
