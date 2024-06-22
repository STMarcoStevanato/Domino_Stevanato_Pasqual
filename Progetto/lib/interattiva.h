/**
 * @file interattiva.h
 * @brief Dichiarazioni di funzioni per la modalita' interattiva
 *
 */

#ifndef PROGETTO_INTERATTIVA_H
#define PROGETTO_INTERATTIVA_H

/**
 * @brief Funzione che fa sceglire all'utente una tessere nella Lista.
 *
 * Questa funzione permette all'utente di scegliere una tessera nella lista
 *
 * @param ptr Puntatore alla Lista doppia.
 * @return Indice tessera scelta dall'utente
 */

int scelta_tessera(Lista_doppia* ptr);

/**
 * @brief Funzione che gira una tessera.
 *
 * Questa funzione data una Lista doppia e un indice i, permette di cambiare se l'utente lo desidersa, il
 * valore dx con quello sx della Tessera del Nodo in posizione i.
 *
 * @warning Questa funzione non viene usata nel programma
 *
 * @param ptr Puntatore alla Lista doppia.
 * @param i indice del nodo
 */

void gira_tessera(Lista_doppia* ptr, int i);

/**
 * @brief Funzione elimina un Nodo dalla Lista della mano e lo aggiunge alla Lista tavolo.
 *
 * Questa funzione fa scegliere all'utente quale Nodo appartenente alla lista mano deve essere inserito
 * nella lista tavolo. Se la tessera scelta dall'utente può essere inserita nella lista Tavolo e si
 * decide di confermare, la funzione eliminera' il Nodo selezionato dall'utente nella lista Mano e
 * l'aggiungera' alla lista Tavolo.
 *
 * @param mano Puntatore alla Lista doppia che rappresenta la mano.
 * @param tavolo Puntatore alla Lista doppia che rappresenta il tavolo.
 * @param i indice del nodo
 */

void tessera_campo(Lista_doppia* mano, Lista_doppia* tavolo, int i);
void tabellone(Nodo* ptr, Lista_doppia* a, int left);


#endif //PROGETTO_INTERATTIVA_H
