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

void puntatore_nullo_memory(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "ERRORE NELLA ALLOCAZIONE DI MEMORIA");
        exit(EXIT_FAILURE);
    }
}

void puntatore_nullo_data(void* a, void* b) {
    if (a == NULL || b == NULL) {
        fprintf(stderr, "ERRORE LISTA VUOTA");
        exit(EXIT_FAILURE);
    }
}