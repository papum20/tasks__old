#include <iostream>
#include <cstring>
#include <ctime>




//Struct
struct studente{
	char nome[20];
	char cognome[20];
	int matricola;
};

//pointer
typedef int *pint;
typedef pint *ppint;

void scambia_ppint(ppint x, ppint y);

//lista
typedef struct list_node{
	int val;
	struct list_node *next;
} list_node_t;
typedef list_node_t *list;


void stampa(list l);
list rand_list(int length, int mx);
list ins_tail(list l, int val);
list conc_list(list l1, list l2);
list invert(list);
list remove_dupl(list);

//lista avanti-indietro
typedef struct bilist_node{
	list current;
	list head;
} bilist_node_t;
typedef bilist_node_t *bilist;

bilist insert_tail(bilist, int);
int val(bilist);
bilist next(bilist);
bilist prev(bilist);
bilist remove_current(bilist);


//libri
typedef struct libro {
	char titolo[20];
	int prezzo;
	int copie;
	libro *next;
} libro_t;
typedef libro_t *libreria;

libreria remove_libro(libreria, libreria);
libreria compra(libreria, char[]);
double media(libreria);
void piu_costoso(libreria, char[]);

void stampa_libri(libreria);



//playlist
typedef struct song{
	char titolo[20];
	double durata;
	int riproduzioni;
	int ascoltatori;
	song *next;
} song_t;
typedef song *playlist;

void stampa_songs(playlist);
playlist insert_song(playlist, char[], double, int, int);
playlist dur3(playlist);
double dur_tot(playlist);
void tasso(playlist, char[]);

