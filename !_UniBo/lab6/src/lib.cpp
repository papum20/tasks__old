#include "lib.h"
using namespace std;




void stampa(list l)
{
	while(l != NULL)
	{
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}



list rand_list(int length, int mx)
{
	if(length == 0) return NULL;
	else
	{
		list l = new list_node_t;
		list p = l;
		for(int i = 0; i < length; i++)
		{
			p->val = rand() % mx;
			if(i == length - 1) p->next = NULL;
			else p->next = new list_node_t;
			p = p->next;
		}
		return l;
	}
}


list ins_tail(list l, int val)
{
	if(l != NULL)
	{
		list p = l;
		while(p->next != NULL) p = p->next;
		p->next = new list_node_t;
		p = p->next;
		l->val = val;
		l->next = NULL;
	}
	else
	{
		l = new list_node_t;
		l->val = val;
		l->next = NULL;
	}
	return l;
}



list conc_list(list l1, list l2)
{
	if(l1 == NULL)
		return l2;
	else
	{
		list p1 = l1;
		while(p1->next != NULL) p1 = p1->next;
		while(l2 != NULL)
		{
			p1->next = l2;
			l2 = l2->next;
		}
		return l1;
	}
}




list invert(list l)
{
	if(l == NULL || l->next == NULL)
		return l;
	else
	{
		list p = l;					//pointer for argument list
		list head = new list_node_t;		//head for new list
		head->val = p->val;
		head->next = NULL;
		while(p->next != NULL)
		{
			p = p->next;
			list tmp = head;
			head = new list_node_t;
			head->val = p->val;
			head->next = tmp;
		}
		return head;
	}
}


list remove_dupl(list l)
{
	if(l == NULL)
		return l;
	else
	{
		list p = l;					//controlla il successivo di p
		while(p->next != NULL)
		{
			list q = l;
			bool found = false;
			while(!found && q != p->next)
			{
				if(q->val == p->next->val) found = true;
				else q = q->next;
			}

			if(found) {
				list tmp = p->next->next;
				delete p->next;
				p->next = tmp;
			}
			else p = p->next;
		}

		return l;
	}
}


//////
//////
//////


bilist insert_tail(bilist b, int n)
{
	if(b == NULL)
	{
		b = new bilist_node_t;
		b->current = NULL;
		b->head = NULL;
	}

	if(b->current == NULL)
	{
		b = new bilist_node_t;
		b->current = new list_node_t;
		b->current->val = n;
		b->current->next = NULL;
		b->head = b->current;
	}
	else
	{
		list p = b->current;
		while(p->next != NULL) p = p->next;
		p->next = new list_node_t;
		p = p->next;
		p->val = n;
		p->next = NULL;
	}

	return b;
}

int val(bilist b)
{
	return b->current->val;
}
bilist next(bilist b)
{
	if(b->current->next != NULL)
		b->current = b->current->next;

	return b;
}

bilist prev(bilist b)
{
	if(b->current != b->head)
	{
		list p = b->head;
		while(p->next != b->current) p = p->next;
		b->current = p;
	}
	return b;
}

bilist remove_current(bilist b)
{
    if(b->head == b->current)
    {
		list tmp = b->current;
    	b->current = b->current->next;
        b->head = b->current;
        delete tmp;
        return b;
    }
    else{
        list tmp = b->current;
		b = prev(b);
        b->current->next = tmp->next;
        delete tmp;
        return b;
    }

}
