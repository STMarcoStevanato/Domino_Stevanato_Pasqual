#ifndef PROGETTO_INTERATTIVA_H
#define PROGETTO_INTERATTIVA_H

#include "interattiva.h"

extern int menu_scelta();
extern int scelta_tessera(Lista_doppia* ptr);
extern void gira_tessera(Lista_doppia* ptr, int i);
extern void tessera_campo(Lista_doppia* mano, Lista_doppia* tavolo, int i);
extern void tabellone(Nodo* ptr, Lista_doppia* a, int left);
extern int controllo_dx(Nodo* ptr, Lista_doppia* tavolo);
extern int controllo_sx(Nodo* ptr, Lista_doppia* tavolo);

#endif //PROGETTO_INTERATTIVA_H
