#include "lib.h"
using namespace std;



int search_a_r(char s[], int start)
{
	if(s[start] == '\0') return 0;
	else if(s[start] == 'a') return 1 + search_a_r(s, start + 1);
	else return search_a_r(s, start + 1);
}


bool dupl(int A[], int length, int to_check, int pos)
{
	if(to_check == length) return false;
	else if(pos >= length) return dupl(A, length, to_check + 1, to_check + 2);
	else if(A[pos] == A[to_check]) return true;
	else return dupl(A, length, to_check, pos + 1);
}


void ordina1(int A[], int length, int pos)
{
	if(length == 0 || length <= pos + 1) return;
	else if(A[pos] %2 == 1) {
		if(A[length - 1] %2 == 0) {
			int tmp = A[pos];
			A[pos] = A[length - 1];
			A[length - 1] = tmp;
			ordina1(A, length - 1, pos + 1);
		}
		else ordina1(A, length - 1, pos);
	}
	else ordina1(A, length, pos + 1);
}
