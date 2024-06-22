/**
 * @file ai.h
 * @brief Dichiarazioni di funzioni per la modalita' AI
 *
 */

#ifndef PROGETTO_AI_H
#define PROGETTO_AI_H

/**
 * @brief Setup per la funzione ricorsiva.
 *
 * funzione che realizza i preparativi delle strutture dati per le tessere del giocatore (mano),
 * le combinazioni in tempo reale (risultante) e la combinazione salvata come miglior combinazione
 * (salvata), inoltre la funzione, tramite score_completo, calcola lo score della combinazione piu alta
 *
 * @param mano Puntatore alla Lista doppia.
 * @param salvata Puntatore alla Lista doppia con la migliore combinazione.
 */

void settare(Lista_doppia* mano, Lista_doppia* salvata);

/**
 * @brief Funzione che calcola la combinazione migliore.
 *
 * funzione che effetivamente calcola in modo ricorsivo tutte le possibili combinazioni, con controlli
 * per rispettare le regole di gioco, delle tessere, disponendole a sinistra, destra, non girate
 * e girate, la funzione scorre la lista contenente le tessere da disporre completamente e crea nuove
 * liste completamente independenti per evitare dipendenze e continuare a chiamare se stessa
 * poi ce la condizione di terminazione che salva la miglior combinazione dentro il puntatore alla lista che
 * tiene traccia di questa il memory leak viene gestito con i free che liberano la memoria allocata per
 * ogni lista
 *
 * @param mano Puntatore alla Lista doppia.
 * @param risultante Puntatore alla Lista doppia che contiene la combinazione corrente.
 * @param salvata Puntatore alla Lista doppia con la migliore combinazione.
 */

void combinazioni(Lista_doppia* mano, Lista_doppia* risultante, Lista_doppia* salvata);

#endif //PROGETTO_AI_H
