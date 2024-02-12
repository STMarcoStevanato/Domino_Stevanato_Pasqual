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
    int a = menu_scelta();
    Lista_doppia mano;
    crea_lista(a, &mano);
    stampa_lista(&mano);
    return 0;
}
