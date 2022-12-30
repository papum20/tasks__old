#include "lib.h"
using namespace std;





list gen_list(int length, int mx)
{
	if(length == 0) return NULL;
	else {
		list l = new node;
		l->val = rand() % mx;
		l->next = gen_list(length - 1, mx);
		return l;
	}
}


void print_list(list l)
{
	if(l != NULL) {
		cout << l->val << " ";
		print_list(l->next);
	}
	else cout << endl;
}



int min_list(list l)
{
	if(l->next == NULL) return l->val;
	else {
		int mn = min_list(l->next);
		if(l->val < mn) return l->val;
		else return mn;
	}
}


int min_list_2(list l, int mn)
{
	if(l == NULL) return mn;
	else if(mn == -1 || l->val < mn) return min_list_2(l->next, l->val);
	else return min_list_2(l->next, mn);
}





list dec2bin(int n, list head)
{
	if(n == 0) return head;
	else {
		list tmp = new node;
		tmp->val = n % 2;
		tmp->next = head;
		return dec2bin(n / 2, tmp);
	}
}




bool prime(int n, int d)
{
	if(n == 1) return false;
	if(n == d) return true;
	if(n % d == 0) return false;
	else return prime(n, d+1);
}

//ESAMI
bool ex1(char s[], int length)
{
	if(length == 1 || length == 0) return false;
	else if(s[length-1] == 'h' && (s[length-2] == 'c' || s[length-2] == 'g') ) return true;
	else return ex1(s, length - 1);
}

