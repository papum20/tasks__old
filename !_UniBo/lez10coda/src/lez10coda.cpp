#include <iostream>
using namespace std;


struct lista {
	int val;
	lista *next;
};

typedef lista *plista;

struct coda{
	plista head;
	plista tail;
};




void stampa(coda c)
{
	plista head = c.head;
	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

coda enqueue(coda c, int e)
{
	plista tmp = new lista;
	tmp->val = e;
	tmp->next = NULL;
	if(c.head == NULL)
	{
		c.head = tmp;
		c.tail = tmp;
	}
	else
	{
		(c.tail)->next = tmp;
		c.tail = tmp;
	}
	return c;
}


coda dequeue(coda c)
{
	if(c.head != NULL) c.head = c.head->next;
	if(c.head == c.tail) c.tail = NULL;
	return c;
}



int main()
{
	coda c = {NULL,NULL};
	stampa(c);
	c = enqueue(c, 0);
	stampa(c);
	c = enqueue(c, 1);
	stampa(c);
	c = enqueue(c, 2);
	stampa(c);
	c = dequeue(c);
	stampa(c);
}
