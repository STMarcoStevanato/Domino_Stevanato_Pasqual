#include "tessera.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));
    Lista_doppia i;
    i.testa = NULL;
    i.coda = NULL;
    inizializza(&i);
    push_front(&i);
    push_front(&i);
    push_back(&i);
    stampa_lista(&i);
    pop_casuale(&i, 2);
    printf("\n");
    stampa_lista(&i);
    return 0;
}
