#include <iostream>
using namespace std;



typedef struct list_n{
	int val;
	struct list_n *next;
} list_n_t;
typedef list_n_t *list;


void insert(list &l, int val)
{
	list tmp = new list_n_t;
	tmp->val = val;
	tmp->next = l;
	l = tmp;
}


int main()
{
	list l = new list_n_t;
	l->val = 0;
	l->next = NULL;
	insert(l, 1);
	cout << l->val << " " << l->next->val;
}
