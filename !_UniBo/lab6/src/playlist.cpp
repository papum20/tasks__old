#include "lib.h"
using namespace std;






void stampa_songs(playlist p)
{
	while(p != NULL) {
		cout << p->titolo << " " << p->durata << " " << p->riproduzioni << " " << p->ascoltatori << endl;
		p = p->next;
	}
	cout << endl;
}

playlist insert_song(playlist p, char s[], double d, int r, int a)
{
	playlist new_p = new song_t;
	strcpy(new_p->titolo, s);
	new_p->durata = d;
	new_p->riproduzioni = r;
	new_p->ascoltatori = a;
	new_p->next = NULL;

	if(p == NULL) return new_p;
	else {
		playlist t = p;
		while(t->next != NULL) t = t->next;
		t->next = new_p;
		return p;
	}
}

playlist dur3(playlist p)
{
	playlist head = new song_t;
	playlist new_p = head;
	bool first = true;
	while(p != NULL)
	{
		if(p->durata >= 3) {
			if(!first) new_p = new_p->next;
			strcpy(new_p->titolo, p->titolo);
			new_p->durata = p->durata;
			new_p->riproduzioni = p->riproduzioni;
			new_p->ascoltatori = p->ascoltatori;
			new_p->next = new song_t;
			first = false;
		}
		p = p->next;
	}
	if(first) {
		delete head;
		head = NULL;
	}
	else {
		delete new_p->next;
		new_p->next = NULL;
	}

	return head;
}

double dur_tot(playlist p)
{
	double tot = 0;
	while(p != NULL)
	{
		tot += p->durata;
		p = p->next;
	}
	return tot;
}

void tasso(playlist p, char s[])
{
	double mx = -1;
	while(p != NULL)
	{
		double new_tasso = (p->riproduzioni)/(p->ascoltatori);
		if(new_tasso > mx) {
			mx = new_tasso;
			strcpy(s, p->titolo);
		}
		p = p->next;
	}

	if(mx == -1) strcpy(s, "");
}
