#include <iostream>
using namespace std;


const int length = 10;




void stampa_pila(int A[])
{
	for(int i = 0; i <= A[0]; i++)
		cout << A[i] << ".";
}


void push(int A[], const int maxL, int e)
{
	if(A[0] < maxL)
	{
		A[A[0]+1] = e;
		A[0] += 1;
	}
	else cout << "out of bounds";
}


int top(int A[])	//Precondition: l>0
{
	return A[A[0]-1];
}

void pop(int A[])
{
	if(A[0] > 0) A[0] -= 1;
	//else cout << "pila già vuota";
}



int main()
{
	int Pila[length];
	Pila[0] = 0;


}
