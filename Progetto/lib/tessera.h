/**
 * @file tessera.h
 * @brief Dichiarazioni di funzioni per la struct Tessera.
 *
 */


#ifndef TESSERA_H
#define TESSERA_H

typedef struct Tessera {
    int sx;
    int dx;
} Tessera;

/**
 * @brief Imposta i valori di una tessera.
 *
 * Questa funzione prende un puntatore a una struct Tessera e due interi
 * e imposta i valori di destra e di sinistra delle Tessera
 *
 * @param tessera Puntatore alla struct Tessera da impostare.
 * @param dx Il valore da assegnare.
 * @param sx Il valore da assegnare.
 */

void set_tessera(Tessera* tessera, int dx, int sx);

/**
 * @brief Imposta i valori di una tessera in modo casuale.
 *
 * Questa funzione prende un puntatore a una struct Tessera e due interi
 * e imposta i valori di destra e di sinistra delle Tessera
 *
 * @param tessera Puntatore alla struct Tessera da impostare.
 */

void set_tessera_random(Tessera* tessera);

/**
 * @brief Stampa una tessera.
 *
 * Questa funzione Stampa il valore destro e il valore sinistro
 * di una Tessera in questo modo [ sx | dx ].
 *
 * @param tessera Puntatore alla struct Tessera da stampare.
 */

void stampa_tessera(Tessera* tessera);

/**
 * @brief swap dei valori di una tessera.
 *
 * Questa funzione cambia il valore di destra con quello di sinistra
 * e il valore di sinistra con quello di destra
 *
 * @param tessera Puntatore alla struct Tessera da stampare.
 */

void swap(Tessera* tessera);

/**
 * @brief calcola la somma tra dx e sx.
 *
 * Questa funzione calcola la somma tra il valore di sinistra
 * e quello di destra delle tessera
 *
 * @param tessera Puntatore alla struct Tessera.
 * @return somma tra dx e sx.
 *
 */

int val_tessera(Tessera* tessera);

#endif