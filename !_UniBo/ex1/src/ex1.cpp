#include <iostream>
#include <ctime>
using namespace std;


struct node{
	int val;
	node *next;
};
typedef node *list;




void print_l(list l)
{
	while(l != NULL) {
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}


list selection_sort(list l)
{
	list head = NULL;
	list p = l;
	list win = NULL;
	while(p == l || (head != NULL && head->next != NULL))
	{
		print_l(l);
		if(head != NULL) p = head;
		win = NULL;
		while(p->next != NULL) {
			if(win == NULL || p->next->val < win->next->val) win = p;
			p = p->next;
		}
		cout<<"\n" <<win->val<<"\n" ;
		if(head == NULL) {
			if(win->next->val < l->val) {
				p = win->next;
				win->next = p->next;
				p->next = l;
				head = p;
				l = p;
			}
			else head = l;
		}
		else {
			if(win->next->val < head->next->val) {
				p = win->next;
				win->next = p->next;
				p->next = head->next;
				head->next = p;
			}
			head = head->next;
		}
	}
	return l;
}




void merge(int A[], int start, int length) {
	int i = start, j = (start+length)/2 + 1;
	int B[length - start];
	int ind = 0;
	while(i != (start+length)/2 + 1 && j != length) {
		if(A[i] <= A[j]) {
			B[ind] = A[i];
			i++;
		}
		else {
			B[ind] = A[j];
			j++;
		}
		ind++;
	}

	//PARTE RIMANENTE
	while(i < (start+length)/2 + 1) {
		B[ind] = A[i];
		ind++;
		i++;
	}
	while(j < length) {
		B[ind] = A[j];
		ind++;
		j++;
	}


	//COPY
	for(int k = 0; k < start - length; k++)
		A[start + k] = B[k];

}


void merge_sort(int A[], int length, int start = 0) {
	if(length - start > 1) {
		merge_sort(A, (start+length)/2 + 1, start);
		merge_sort(A, length, (start+length)/2 + 1);
		merge(A, start, length);
	}
}




/*
plista selection_sort(plista head){
plista k=head;
plista i=head;
plista p=head;
plista h=head;
while(p!=NULL){
    if(p->val<head->val){
        plista tmp3=head;
        plista tmp4=head->next;
        plista tmp5=p->next;
        head=p;
        p=tmp3;

        head->next=tmp5;
        p->next=tmp4;
        h=p;
        h->next=p->next;
    }
    p=p->next;
}
while(k->next!=NULL){
    while(i->next!=NULL){
        if(k->next->val<i->next->val){
            plista tmp=k->next;
            plista tmp1=k->next->next;
            plista tmp2=i->next->next;
            k->next->next=tmp2;
            k->next=i->next;
            i->next->next=tmp1;
            i->next=tmp;
        }
        i=i->next;
    }
    i=k;
    k=k->next;
}
return h;
}*/





/*
list selection_sort_it(list head)
{
	if(head == NULL) return NULL;
	else
	{
		list result = head;

		list new_head = head;
		list winner = NULL;
		list p;
		while(new_head->next != NULL)
		{
		print_l(head);
			p = new_head;
			if(p != NULL)
			{
				while(p->next != NULL) {
					if(winner == NULL || p->next->val < winner->next->val) winner = p;
					p = p->next;
				}
			}

			if(winner != NULL && winner->next->val < new_head->val) {
				list tmp_head = winner->next;
				winner->next = tmp_head->next;
				if(new_head == head) {
					tmp_head->next = new_head;
					head = tmp_head;
				}
				else {
					tmp_head->next = new_head->next;
					new_head->next = tmp_head;
				}
					new_head = tmp_head;
			}
			else new_head = new_head->next;
		}

		return head;
	}

}



void foo(list *p,list *q) {
	*p=*q;
}
*/



void Bubblesort(int A[], int length, int pos = 0)
{
	if(length <= 1) return;
	else if(pos >= length - 1) Bubblesort(A, length-1, 0);
	else {
		if(A[pos] > A[pos + 1]) {
			int tmp = A[pos];
			A[pos] = A[pos + 1];
			A[pos + 1] = tmp;
		}
		Bubblesort(A, length, pos + 1);
	}
}



////////////////
// 19_02_2020 //
////////////////

void foo(int A[], int length, int pos = 0, int conf = 1)
{
	if(pos >= length - 1) return;
	else if(conf >= length) return;
	else if(A[pos] > 1000) foo(A, length, pos+1, pos+2);
	else if(A[pos] < 0) {
		if(A[conf] >= 0) {
			int tmp = A[pos];
			A[pos] = A[conf];
			A[conf] = tmp;
			foo(A, length, pos, pos+1);
		}
		else foo(A, length, pos, conf+1);
	}
	else {
		if(A[length-1] < 0 || A[length-1] > 1000) {
			int tmp = A[pos];
			A[pos] = A[length-1];
			A[length-1] = tmp;
			foo(A, length-1, pos, pos+1);
		}
		else foo(A, length-1, pos, pos+1);
	}
}


struct tree_t{
	int val;
	tree_t *ltree;
	tree_t *rtree;
};
typedef tree_t *tree;


tree ric_it(list l)
{
	if(l == NULL) return NULL;
	else
	{
		tree root = new tree_t;
		root->val = l->val;
		root->ltree = NULL;
		root->rtree = NULL;
		tree p = root;
		l = l->next;
		while(l != NULL)
		{
			if(l->val < p->val) {
				if(p->ltree != NULL) p = p->ltree;
				else {
					p->ltree = new tree_t;
					p = p->ltree;
					p->val = l->val;
					p->ltree = NULL;
					p->rtree = NULL;
					p = root;
					l = l->next;
				}
			}
			else {
				if(p->rtree != NULL) p = p->rtree;
				else {
					p->rtree = new tree_t;
					p = p->rtree;
					p->val = l->val;
					p->ltree = NULL;
					p->rtree = NULL;
					p = root;
					l = l->next;
				}
			}
		}
		return root;
	}

}


#define MN 0
#define MX 2147483647
tree ric(list l, int mn = MN, int mx = MX)
{
	if(l == NULL) return NULL;
	else if(l->val >= mn && l->val < mx) {
		tree t = new tree_t;
		t->val = l->val;
		t->ltree = ric(l->next, mn, t->val);
		t->rtree = ric(l->next, t->val, mx);
		return t;
	}
	else return ric(l->next, mn, mx);

}



list gen_list(int len, int mx)
{
	if(len <= 0) return NULL;
	else {
		list t = new node;
		t->val = rand() %mx;
		cout << t->val << " ";
		t->next = gen_list(len - 1, mx);
		return t;
	}
}

void print_tree(tree t, int level = 0)
{
	cout << "\n";
	for(int i = 0; i < level; i++) cout << "\t";
	if(t == NULL) cout << "-";
	else {
		cout << t->val;
		print_tree(t->ltree, level+1);
		print_tree(t->rtree, level+1);
	}
}

int foglie(tree t)
{
	if(t == NULL) return 0;
	else if(t->ltree == NULL && t->rtree == NULL) return 1;
	else return foglie(t->ltree) + foglie(t->rtree);
}


struct stack_t{
	tree t;
	stack_t *next;
};
typedef stack_t *stack;

tree top(stack s) {
	if(s == NULL) return NULL;
	else return s->t;
}
stack pop(stack s) {
	if(s == NULL) return NULL;
	else {
		stack tmp = s->next;
		delete s;
		return tmp;
	}
}
stack push(stack s, tree t) {
	stack tmp = new stack_t;
	tmp->t = t;
	tmp->next = s;
	return tmp;
}

int foglie_it(tree t)
{
	if(t == NULL) return 0;
	else
	{
		int res = 0;
		stack s = push(NULL, t);
		while(s != NULL) {
			tree tmp = top(s);
			s = pop(s);
			if(tmp->ltree == NULL && tmp->rtree == NULL) res++;
			else {
				if(tmp->ltree != NULL) s = push(s, tmp->ltree);
				if(tmp->rtree != NULL) s = push(s, tmp->rtree);
			}
		}
		return res;
	}
}










int main()
{

	// 19_02_2020

	srand(time(NULL));

	list l = gen_list(10, 100);
	cout << "\n\n";
	tree t = ric(l);
	print_tree(t);
	cout << "\n\n" << foglie(t) << " " << foglie_it(t);


/*
	int arr[10] = {500, 1001, -100, 500, 1001, 500, 1001, 1001, -200, 1001};
	foo(arr, 3);
	for(auto i:arr) cout << i << " ";
*/
/*
	list l = new node;
	list p = l;
	p->val = 3;
	p->next = new node;
	p = p->next;
	p->val = 2;
	p->next = new node;
	p = p->next;
	p->val = 6;
	p->next = new node;
	p = p->next;
	p->val = 5;
	p->next = new node;
	p = p->next;
	p->val = 2;
	p->next = new node;
	p = p->next;
	p->val = 4;
	p->next = new node;
	p = p->next;
	p->val = 1;
	p->next = NULL;

	print_l(l);

	l = selection_sort(l);

	print_l(l);
*/
/*
	list a = new node;
	list b = new node;
	a->val = 2;
	b->val = 3;
	foo(&a,&b);
	cout<<a->val;
*/
/*
	const int n = 0;
	int arr[10] = {4,1,5,6,43,3,5,3,6,10};
	Bubblesort(arr, n);
	for(int i = 0; i < 10; i++) cout << arr[i] << " ";
*/
}
