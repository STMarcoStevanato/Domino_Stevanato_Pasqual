/**
 * @file controllo.h
 * @brief Funzioni di utilità per il controllo dei puntatori nulli.
 *
 * Questo file contiene le dichiarazioni delle funzioni di utilità per il controllo dei puntatori nulli
 * e la gestione degli errori di allocazione della memoria.
 *
 */


#ifndef PROGETTO_CONTROLLO_H
#define PROGETTO_CONTROLLO_H

/**
 * @brief Controlla se un puntatore è nullo dopo l'allocazione di memoria.
 *
 * Questa funzione verifica se il puntatore passato è nullo. Se lo è,
 * stampa un messaggio di errore e termina il programma.
 *
 * @param ptr Puntatore da verificare.
 *
 * @warning Assicurarsi che questa funzione sia chiamata subito dopo l'allocazione della memoria.
 */

void puntatore_nullo_memory(void* ptr);

/**
 * @brief Controlla se uno dei due puntatori passati è nullo.
 *
 * Questa funzione verifica se uno dei due puntatori passati è nullo. Se lo è,
 * stampa un messaggio di errore e termina il programma.
 *
 * @param a Primo puntatore da verificare.
 * @param b Secondo puntatore da verificare.
 *
 * @warning Assicurarsi che i puntatori passati non siano nulli prima di procedere con operazioni sulla lista.
 */
void puntatore_nullo_data(void* a, void* b);

#endif //PROGETTO_CONTROLLO_H
