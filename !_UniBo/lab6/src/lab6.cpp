#include "lib.h"
using namespace std;







int main()
{
/*
	int x_i = 2;
	int y_i = 3;
	pint x_p = &x_i;
	pint y_p = &y_i;
	ppint x_pp = &x_p;
	ppint y_pp = &y_p;

	cout << *(*x_pp) << " " << *(*y_pp)<<endl;
	scambia_ppint(x_pp, y_pp);
	cout << *(*x_pp) << " " << *(*y_pp)<<endl;
*/
/*
	srand(time(NULL));
	list a = rand_list(5, 10);
	list b = rand_list(4, 10);
	stampa(a);
	stampa(b);
	ins_tail(a, 4);
	stampa(a);
	list c = conc_list(a, b);
	stampa(c);

*/
/*
	list a = rand_list(10, 10);
	stampa(a);
	list b = invert(a);
	a = remove_dupl(a);
	stampa(a);
	stampa(b);
	*/


/*	bilist a = NULL;
	//stampa(a->head);

	a = insert_tail(a, 1);
	stampa(a->head);
	stampa(a->current);
	cout << endl;


	a = insert_tail(a, 2);
	stampa(a->head);
	stampa(a->current);
	cout << endl;

	a = insert_tail(a, 3);
	stampa(a->head);
	stampa(a->current);
	cout << endl;

	a = prev(a);
	stampa(a->head);
	stampa(a->current);
	cout << endl;

	a = next(a);
	stampa(a->head);
	stampa(a->current);
	cout << endl;

	a = next(a);
	stampa(a->head);
	stampa(a->current);
	cout << endl;

	a = next(a);
	stampa(a->head);
	stampa(a->current);
	cout << endl;


	a = next(a);
	stampa(a->head);
	stampa(a->current);
	cout << endl;


	a = prev(a);
	stampa(a->head);
	stampa(a->current);
	cout << endl << "DELETE\n";

	a = remove_current(a);
	stampa(a->head);
	stampa(a->current);
	cout << endl;
*/
/*
	char a[] = "aa";
	char b[] = "bb";
	char c[] = "cc";
	char d[] = "dd";
	char e[] = "ee";


	libreria l1 = new libro_t;
	strcpy(l1->titolo, a);
	l1->prezzo = 2;
	l1->copie = 3;

	libreria l2 = new libro_t;
	strcpy(l2->titolo, b);
	l2->prezzo = 7;
	l2->copie = 1;

	libreria l3 = new libro_t;
	strcpy(l3->titolo, c);
	l3->prezzo = 10;
	l3->copie = 2;

	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;



	stampa_libri(l1);
	cout << endl;


////	l1 = remove_libro(l1, l2);
//	stampa_libri(l1);


	char t[] = "bb";
	l1 = compra(l1, b);

	stampa_libri(l1);
	cout << endl;

	cout << media(l1) << endl;

	char s[20];
	piu_costoso(l1, s);
	cout << s << endl;
*/

	playlist p = NULL;
	p = insert_song(p, "aa", 5, 2, 3);
	p = insert_song(p, "bb", 3.2, 7, 6);
	p = insert_song(p, "cc", 3, 2, 10);
	p = insert_song(p, "dd", 4, 11, 2);
	stampa_songs(p);
	cout << endl;

	playlist t = dur3(p);
	stampa_songs(t);
	stampa_songs(p);

	cout << dur_tot(p) << endl;

	char s[20];
	tasso(p, s);
	cout << s;




}
