#ifndef PROGETTO_INTERATTIVA_H
#define PROGETTO_INTERATTIVA_H

#include "interattiva.h"

extern int menu_scelta();
extern int scelta_tessera(Lista_doppia* ptr);
extern void gira_tessera(Lista_doppia* ptr, int i);
extern void tabellone(Nodo* ptr, Lista_doppia* a, int left);

#endif //PROGETTO_INTERATTIVA_H
