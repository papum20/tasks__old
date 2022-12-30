#include <iostream>
#include <ctime>
using namespace std;


struct btree{
	int val;
	btree *ltree, *rtree;
};

typedef btree *ptr_btree;

struct stack{
	ptr_btree t;
	stack *next;
};
typedef stack *p_stack;




p_stack push(p_stack s, ptr_btree e)
{
	p_stack tmp = new stack;
	tmp->t = e;
	tmp->next = s;
	return tmp;
}


ptr_btree top(p_stack s)
{
	return s->t;
}

p_stack pop(p_stack s)
{
	if(s == NULL) return NULL;
	else {
		p_stack tmp = s->next;
		delete(s);
		return tmp;
	}
}








ptr_btree create_btree(ptr_btree t, int n) {
	int x ;
	if (t == NULL) {
		t = new btree ;
		t->val = n ;
		t->ltree = NULL ;
		t->rtree = NULL ;
	} else { x = rand()%2 ;
	 if (x==0) t->ltree = create_btree(t->ltree, n);
	 else t->rtree = create_btree(t->rtree, n);
	}
	return(t) ;
}


ptr_btree new_btree(int p)
{
	if(p == -1) return NULL;
	else {
		ptr_btree new_bt = new btree;
		new_bt->val = rand()%10;
		new_bt->ltree = new_btree(p-1);
		new_bt->rtree = new_btree(p-1);
		return new_bt;
	}
}


void visit(ptr_btree t){
	if (t != NULL) {
		cout << t->val << " [";
		visit(t->ltree) ;
		cout << "] [";
		visit(t->rtree) ;
		cout << "] ";
	}
}

void stampa_prof(ptr_btree t, int p)
//n = profondità attuale, inizializzata a 0; p = profondità da stampare
{
	if(p == 0) cout << t->val << " ";
	else {
		stampa_prof(t->ltree, p-1);
		stampa_prof(t->rtree, p-1);
	}
}


int n_nodi(ptr_btree t)
{
	if(t == NULL) return 0;
	else return 1 + n_nodi(t->ltree) + n_nodi(t->rtree);
}

int n_nodi_it(ptr_btree t)
{
	int res = 0;
	p_stack s = new stack;
	s->t = t;
	s->next = NULL;
	while(s != NULL) {
		ptr_btree tmp = top(s);
		s = pop(s);
		res++;
		if(tmp->ltree != NULL) s = push(s, tmp->ltree);
		if(tmp->rtree != NULL) s = push(s, tmp->rtree);
	}

	return res;
}



struct stack_lr{
	ptr_btree t;
	bool left;		//if can go left
	bool right;		// - right
	stack_lr *next;
};
typedef stack_lr *p_stacklr;




p_stacklr push(p_stacklr s, ptr_btree e)
{
	p_stacklr tmp = new stack_lr;
	tmp->t = e;
	tmp->next = s;
	tmp->left = true;
	tmp->right = true;
	return tmp;
}


ptr_btree top(p_stacklr s)
{
	return s->t;
}

p_stacklr pop(p_stacklr s)
{
	if(s == NULL) return NULL;
	else {
		p_stacklr tmp = s->next;
		delete(s);
		return tmp;
	}
}

void infissa_left_it(ptr_btree t)
{
	p_stacklr s = NULL;
	s = push(s, t);
	int i = 0;
	while(s != NULL && i < 20) {
		ptr_btree tmp = top(s);
		//cout << tmp->val << "," << s->left<<s->right << " " ;
		if(s->left) {
			if(tmp->ltree != NULL) {
				s->left = false;
				s = push(s, tmp->ltree);
			}
			else s->left = false;
		}
		else if(s->right){
			cout << tmp->val << " ";
			if(tmp->rtree != NULL) {
				s->right = false;
				s = push(s, tmp->rtree);
			}
			else s->right = false;
		}
		else s = pop(s);



		i++;
	}


}


void stampa_albero(ptr_btree t, int max_depth)
{
	for(int i = 0; i < max_depth; i++) {
		stampa_prof(t, i);
		cout << endl;
	}
}




int main()
{
	srand(time(NULL));
	ptr_btree bt = new_btree(2);
	visit(bt);
	/*
	cout <<endl;
	stampa_prof(bt, 3);
	cout << endl << n_nodi(bt)<<endl;

	cout << endl << n_nodi_it(bt);

	cout << endl;
	stampa_albero(bt, 5);
*/
	cout << "\n\n\n";
	infissa_left_it(bt);




}
