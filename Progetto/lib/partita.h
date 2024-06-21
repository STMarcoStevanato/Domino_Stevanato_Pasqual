#ifndef PROGETTO_PARTITA_H
#define PROGETTO_PARTITA_H

int menu_scelta();
int menu_modalita();
int controllo_dx(Nodo* ptr, Lista_doppia* tavolo);
int controllo_sx(Nodo* ptr, Lista_doppia* tavolo);
void score(Nodo* nuovaTessera);
void score_ai(Lista_doppia* nuovaTessera);
int game_continue(Lista_doppia* tavolo, Lista_doppia* mano);
int get_score();
void stampa_punteggio();

#endif //PROGETTO_PARTITA_H
