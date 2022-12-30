#include <iostream>
using namespace std;



void asterischi(int n)
{
	if(n == 0) return;
	else {
		cout << "*";
		asterischi(n-1);
	}
}


void write_vertical(int n)
{
	if(n < 10) cout << n << endl;
	else {
		cout << n%10 << endl;
		write_vertical(n/10);
	}
}


void asterischi_quadrati(int n)
{
	if(n == 0) cout << endl;	//return;
	else if(n > 0) {
		asterischi_quadrati(-n*n);
		asterischi_quadrati(n-1);
	}
	else if(n < 0) {
		cout << "*";
		asterischi_quadrati(n+1);
	}
}


int somma_naturali(int n, int m)
{
	if(m == 0) return n;
	else return 1 + somma_naturali(n, m-1);
}

int prodotto_naturali(int n, int m)
{
	if(m == 0) return 0;
	else return prodotto_naturali(n, m-1) + n;
}



bool palindromo(char A[], int length, int pos)
{
	if(pos < length / 2) return A[pos] == A[length - 1 - pos] && palindromo(A, length, pos+1);
	else return true;
}



typedef struct node{
	int val;
	node *next;
} node_t;
typedef node_t *list;



list insert(list head, list p, int e)
{
	if(head == NULL || e < head->val) {
		list tmp = new node_t;
		tmp->val = e;
		tmp->next = head;
		return tmp;
	}
	else if(p->next == NULL || p->next->val >= e) {
		list tmp = p->next;
		p->next = new node_t;
		p->next->val = e;
		p->next->next = tmp;
		return head;
	}
	else
		return insert(head, p->next, e);
}

list insert_2(list head, int e)
{
	if(head == NULL || head->val >= e) {
		list tmp = new node_t;
		tmp->val = e;
		tmp->next = head;
		return tmp;
	}
	else {
		head->next = insert_2(head->next, e);
		return head;
	}
}


void stampa_list(list p)
{
	if(p != NULL) {
		cout << p->val << " ";
		stampa_list(p->next);
	}
}

list insert_head(list head, int elem)
{
	list tmp = new node_t;
	tmp->val = elem;
	tmp->next = head;
	return tmp;
}


int somma_list(list head)
{
	if(head == NULL) return 0;
	else return head->val + somma_list(head->next);
}

list invert(list head, list prev)
//precondition: prev initialized to NULL
{
	if(head == NULL) return head;
	else if(head->next == NULL) {
		head->next = prev;
		return head;
	}
	else {
		list tmp = head->next;
		head->next = prev;
		return invert(tmp, head);
	}
}

list remove(list head, int e)
{
	if(head == NULL) return head;
	else if(head->val == e) return head->next;
	else {
		head->next = remove(head->next, e);
		return head;
	}
}

list remove_mult(list head, int e)
{
	if(head == NULL) return head;
	else if(head->val %e == 0) {
		head = remove_mult(head->next, e);
		return head;
	}
	else {
		head->next = remove_mult(head->next, e);
		return head;
	}
}




int main()
{
/*
	asterischi(10);
	cout << endl;
	write_vertical(1234);
	cout << endl;
	asterischi_quadrati(5);
*/

	//cout << somma_naturali(2,3) << endl << somma_naturali(4,0) << endl << prodotto_naturali(10,5) << endl << prodotto_naturali(10,0);


	list a = new node_t;
	a->next = NULL;
	a->val = 7;
	a = insert_head(a, 5);
	a = insert_head(a, 3);
	a = insert_head(a, 1);




	a = insert_2(a, 1);
	stampa_list(a);
	cout << endl;

	list b = invert(a, NULL);
	stampa_list(b);
	cout << endl;

	cout << somma_list(b)<<endl;

	list c = remove(b, 7);
	stampa_list(c);
	cout << endl;


	list d = NULL;
	d = insert_2(d, 1);
	d = insert_2(d, 2);
	d = insert_2(d, 6);
	d = insert_2(d, 3);
	d = insert_2(d, 3);
	d = insert_2(d, 4);

	stampa_list(d);
	cout <<endl;

	d = remove_mult(d, 3);
	stampa_list(d);
	cout << endl;




}
