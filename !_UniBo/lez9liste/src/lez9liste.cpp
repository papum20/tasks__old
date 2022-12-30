#include <iostream>
#include <ctime>
using namespace std;



struct lista{
	int val;
	lista *next;
};

typedef lista *plista;


void stampa(plista head)
{
	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

plista insert_head(plista head, int elem)
{
	plista tmp = new lista;
	tmp->val = elem;
	tmp->next = head;
	return tmp;
}
//2
plista crea_head(int length, int mx)
{
	plista head = NULL;
	for(int i = 0; i < length; i++)
		head = insert_head(head, rand()%mx);

	return head;
}

plista crea_tail(int length, int mx)	//PRECONDITION: length>0
{
	plista tmp = new lista;
	plista head = tmp;
	for(int i = 0; i < length; i++)
	{
		tmp->val = rand()%mx;
		if(i < length-1)
		{
			plista tmp2 = new lista;
			tmp->next = tmp2;
			tmp = tmp2;
		}
		else tmp->next = NULL;
	}

	return head;
}

//3
void media(plista head, int media)
{
	if(head != NULL)
	{
		int closest = head->val;
		int diff = media - closest;
		if(diff < 0) diff = -diff;
		head = head->next;

		while(head != NULL)
		{
			int newDiff = head->val - media;
			if(newDiff < 0) newDiff = -newDiff;
			if(newDiff < diff)
			{
				closest = head->val;
				diff = newDiff;
			}
			head = head->next;
		}
		cout << closest << endl;
	}
	else
		cout << "lista vuota\n";
}

//4
plista inverti(plista head)
{
	plista newHead = NULL;
	while(head != NULL)
	{
		newHead = insert_head(newHead, head->val);
		head = head->next;
	}
	return newHead;
}

plista remove_el(plista p, int e)
{
	plista i = p;
	plista afteri = i->next;
	if(i->val == e)
	{
		p = afteri;
//		i->next=NULL;
//		delete i;
	}
	else if(i != NULL && afteri != NULL)
	{
		bool found = false;
		while(!found && afteri != NULL)
		{
			if(i->next->val == e)
			{
				i->next = afteri->next;
				delete afteri;
				found = true;
			}
			else
			{
				i = afteri;
				afteri = afteri->next;
			}
		}
	}
	return p;
}


//PROF
/*
plista remove_el(plista p, int e)
{
	if(p == NULL) return p;
	else if(p->next == NULL) return p->next;
	else{
	plista i = p;
	plista afteri = i->next;

	bool found = false;
	while(!found && afteri != NULL)
	{
		if(i->next->val == e)
		{
			i->next = afteri->next;
			delete afteri;
			found = true;
		}
		else
		{
			i = afteri;
			afteri = afteri->next;
		}
	}
	}
	return p;
}
*/

//2_2
//rimuove interi multipli di n
plista rimuovi_multipli(plista head, int n)
{
	while(head != NULL && head->val %n == 0)
	{
		plista tmp = head;
		head = head->next;
		delete tmp;
	}

	if(head == NULL) return head;

	plista p = head, pafter = head->next;
	while(pafter->next != NULL)
	{
		if(pafter->val %n == 0)
		{
			plista tmp = pafter;
			p->next = pafter->next;
			pafter = pafter->next;
			delete tmp;
		}
		else
		{
			p = pafter;
			pafter = pafter->next;
		}
	}
	if(pafter->val %n == 0)
	{
		p->next = NULL;
		delete pafter;
	}

	return head;
}

//2_3
//crivello eratostene
plista init_crivello(int mx)
{
	if(mx == 0) return NULL;
	else
	{
		plista head = new lista, p = head;
		for(int i = 1; i <= mx; i++)
		{
			p->val = i;
			if(i == mx) p->next = NULL;
			else
			{
				p->next = new lista;
				p = p->next;
			}
		}
		return head;
	}
}

plista crivello(plista head)
{
	if(head != NULL)
	{
		plista p = head;
		while(p->next != NULL)
		{
			plista q = p, qafter = q->next;
			while(qafter->next != NULL)
			{
				if((p->val != 1) && (qafter->val % (p->val) == 0))
				{
					plista tmp = qafter;
					q->next = qafter->next;
					qafter = qafter->next;
					delete tmp;
				}
				else
				{
					q = qafter;
					qafter = qafter->next;
				}
			}
			if(qafter->val % (p->val) == 0)
			{
				q->next = NULL;
				delete qafter;
			}

			p = p->next;
		}
	}
	return head;
}

//2_4
struct lista_plus{
	int val;
	lista_plus *head;
	lista_plus *next;
};
typedef lista_plus *plistaPlus;
/*
struct lista_plus{
	plista head;
	plista corr;
};
*/
//aggiungi in fondo
plistaPlus aggiungi(plistaPlus p, int e)
{
	plistaPlus end = new lista_plus;
	end->val = e;
	end->next = NULL;
	if(p == NULL)
	{
		end->head = end;
		p = end;
	}
	else
	{
		plistaPlus c = p;
		while(c->next != NULL)
			c = c->next;
		end->head = p;
		c->next = end;
	}
	return p;
}

plistaPlus indietro(plistaPlus p)
{
	if(p != p->head)
	{
		plistaPlus q = p->head;
		while(q->next != p)
			q = q-> next;
		return q;
	}
	else return p;
}

plistaPlus elim_current(plistaPlus p)
{
	if(p == p->head)
	{
		plistaPlus q = p->next;
		while(q != NULL)		//CHANGE HEAD FOR ALL
		{
			q->head = p->next;
			q = q->next;
		}
		q = p->next;
		delete p;
		return q;
	}
	else
	{
		plistaPlus q = p->head, c = q;
		while(c->next != p)
			c = c-> next;
		plistaPlus tmp = c->next;
		c->next = tmp->next;
		delete tmp;
		return c;
	}
}


int main()
{
	/*
	srand(time(NULL));
	plista p = crea_tail(5, 10);
	stampa(p);
	p = rimuovi_multipli(p, 2);
	stampa(p);
	*/
	/*
	plista p = init_crivello(100);
	stampa(p);
	p = crivello(p);
	stampa(p);
	*/

	plistaPlus p = NULL;
	p = aggiungi(p, 0);
	cout << p->val << " " << p->head->val << endl;
	p = aggiungi(p, 1);
	cout << p->val << " " << p->head->val << endl;
	p = aggiungi(p, 2);
	cout << p->val << " " << p->head->val << endl;
	p = aggiungi(p, 3);
	cout << p->val << " " << p->head->val << endl;
	p = p->next;
	cout << p->val << " " << p->head->val << endl;
	p = p->next;
	cout << p->val << " " << p->head->val << endl;
	p = elim_current(p);
	cout << p->val << " " << p->head->val << endl;
	p = p->next;
	cout << p->val << " " << p->head->val << endl;
	p = indietro(p);
	cout << p->val << " " << p->head->val << " INDIETRO" << endl;
	p = elim_current(p);
	cout << p->val << " " << p->head->val << endl;
	p = elim_current(p);
	cout << p->val << " " << p->head->val << endl;

}
