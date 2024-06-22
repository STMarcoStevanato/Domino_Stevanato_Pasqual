/**
 * @file partita.h
 * @brief Dichiarazioni di funzioni che sono utilizzate sia per la modalità interattiva sia per la AI
 *
 */


#ifndef PROGETTO_PARTITA_H
#define PROGETTO_PARTITA_H

/**
 * @brief Funzione che permette di selezionare quante tessere usare nella partita
 *
 * La funzione tramite un menu fa sceglire all'utente con quante tessere usare durante la partita.
 * L'utente può scegliere di usare 10, 20 o 30 tessere. E' anche possibile sceglire un opzione che
 * dove le tessere saranno casuali su un range che va da 10 fino a 59 compresi. Infine l'utente potra
 * scegliere un ultima opzione dove sara' quest'ultimo a decidere con quante tessere usare, tuttavia
 * l'utente non potra' scegliere un numero di tessere inferiori a 5
 *
 */

int menu_scelta();

/**
 * @brief Funzione che permette di selezionare la modalita' del Domino
 *
 * Le modalita' che l'utente puo' sceglire sono la modalita' interattiva oppure la modalita' AI.
 *
 */

int menu_modalita();

/**
 * @brief Funzione controlla se e' possibile fare un push_back
 *
 * Dato un Nodo e una Lista Doppia, la funzione controlla se il Nodo puo' essere inserito come ultimo
 * elemento della lista. Per farlo, la Funzione controlla se il valore dx dell'ultimo elemento della
 * lista e' uguale a il valore sx o dx del Nodo
 *
 * @param ptr Puntatore al nodo.
 * @param tavolo Puntatore alla Lista doppia
 * @return ritorna 0 se non si puo' fare il push_back
 */

int controllo_dx(Nodo* ptr, Lista_doppia* tavolo);

/**
 * @brief Funzione controlla se e' possibile fare un push_front
 *
 * Dato un Nodo e una Lista Doppia, la funzione controlla se il Nodo puo' essere inserito come primo
 * elemento della lista. Per farlo, la Funzione controlla se il valore sx del primo elemento della
 * lista e' uguale a il valore sx o dx del Nodo
 *
 * @param ptr Puntatore al nodo.
 * @param tavolo Puntatore alla Lista doppia
 * @return ritorna 0 se non si puo' fare il push_front
 */

int controllo_sx(Nodo* ptr, Lista_doppia* tavolo);

/**
 * @brief Aggiorna il valore dello score
 *
 * La funzione ogni volta che si aggiunge una tessera al tavolo, aggiorna lo score. Lo score e' dato dalla
 * somma dei valori sx e dx di tutte le tessere nel tavolo
 *
 * @param nuovaTessera Puntatore al nodo.
 */

void score(Nodo* nuovaTessera);

/**
 * @brief Aggiorna il valore dello score
 *
 * La funzione data una Lista doppia calcola lo score. Lo score e' dato dalla
 * somma dei valori sx e dx di tutte le tessere nel tavolo
 *
 * @param nuovaTessera Puntatore alla Lista doppia.
 */

void score_completo(Lista_doppia* nuovaTessera);

/**
 * @brief Funzione controlla se si possono fare ulteriori mosse
 *
 * La funzione controlla che almeno un Nodo nella Lista doppia mano può essere inserito
 * tramite push_back o push_front alla Lista doppia tavolo
 *
 *
 * @param tavolo Puntatore alla Lista doppia dove si inseriscono i Nodi
 * @param mano Puntatore alla Lista doppia dove sono presenti i Nodi da utilizzare
 * @return ritorna 1 (true) se ci sono ancora mosse possibili da fare altrimenti 0 (false)
 */

int game_continue(Lista_doppia* tavolo, Lista_doppia* mano);

/**
 * @brief Funzione che ritorno lo score
 *
 *@return ritorna lo score
 */

int get_score();

/**
 * @brief Funzione che stampa lo score quando la partita finisce.
 *
 */
void stampa_punteggio();

#endif //PROGETTO_PARTITA_H
