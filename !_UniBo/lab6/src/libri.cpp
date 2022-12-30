#include "lib.h"
using namespace std;





libreria remove_libro(libreria lib, libreria elem)
{
	if(lib == elem)
	{
		lib = lib->next;
		delete elem;
		return lib;
	}
	else
	{
		libreria p = lib;
		bool found = false;
		while(!found && p->next != NULL) {
			if(p->next == elem) found = true;
			else p = p->next;
		}
		if(found) {
			p->next = elem->next;
			delete elem;
		}

		return lib;
	}
}

libreria compra(libreria head, char nome[])
{
	libreria elem = head;
	bool found = false;
	while(!found && elem != NULL)
	{
		if(strcmp(elem->titolo, nome) == 0) {
			elem->copie -= 1;
			if(elem->copie == 0) head = remove_libro(head, elem);
			found = true;
		}
		elem = elem->next;
	}

	return head;
}

double media(libreria lib)
{
	double tot = 0;
	int n = 0;
	while(lib != NULL) {
		tot += lib->prezzo;
		n++;
		lib = lib->next;
	}

	if(n == 0) return 0;
	else return tot/n;
}

void piu_costoso(libreria lib, char nome[])
{
	int mx = -1;
	libreria mx_l = NULL;
	while(lib != NULL) {
		if(lib->prezzo > mx) {
			mx = lib->prezzo;
			mx_l = lib;
		}
		lib = lib->next;
	}

	if(mx_l == NULL) strcpy(nome, "");
	else strcpy(nome, mx_l->titolo);
}


void stampa_libri(libreria lib)
{
	while(lib != NULL)
	{
		cout << lib->titolo << "  " << lib->prezzo << " " << lib->copie << endl;
		lib = lib->next;
	}
}
