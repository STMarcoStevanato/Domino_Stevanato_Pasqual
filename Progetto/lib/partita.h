#ifndef PROGETTO_PARTITA_H
#define PROGETTO_PARTITA_H

int menu_scelta();
int controllo_dx(Nodo* ptr, Lista_doppia* tavolo);
int controllo_sx(Nodo* ptr, Lista_doppia* tavolo);
void score(Nodo* nuovaTessera);
int game_over(Lista_doppia* tavolo, Lista_doppia* mano);
int get_score();

#endif //PROGETTO_PARTITA_H
