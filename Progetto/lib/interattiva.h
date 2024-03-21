#ifndef PROGETTO_INTERATTIVA_H
#define PROGETTO_INTERATTIVA_H

#include "interattiva.h"

int menu_scelta();
int scelta_tessera(Lista_doppia* ptr);
void gira_tessera(Lista_doppia* ptr, int i);
void tessera_campo(Lista_doppia* mano, Lista_doppia* tavolo, int i);
void tabellone(Nodo* ptr, Lista_doppia* a, int left);
int controllo_dx(Nodo* ptr, Lista_doppia* tavolo);
int controllo_sx(Nodo* ptr, Lista_doppia* tavolo);
void score(Nodo* nuovaTessera);


#endif //PROGETTO_INTERATTIVA_H
