#include "library.h"
using namespace std;





//inizalizza a 0
void inizializza_array(int A[], int length)
{
	for(int i = 0; i < length; i++) A[i] = 0;
}

//dimensione n di numeri casuali
void genera_elementi(int A[], int length, int max)
{
	//srand(time(NULL));
	for(int i = 0; i < length && i < length; i++) A[i] = rand()%max;
}

//stampa
void stampa_array(const int A[], int length)
{
	for(int i = 0; i < length; i++) cout << A[i] << " ";
	cout << endl;
}

//1

void concatena_array(const int A[], const int B[], int C[], int len_a, int len_b)
{
	for(int i = 0; i < len_a; i++) C[i] = A[i];
	for(int i = 0; i < len_b; i++) C[len_a+i] = B[i];
}

//2

void stampa_istogramma()
{
	int num;					//number of points
	const int hist_size = 10;	//histogram size
	int hist[hist_size];
	inizializza_array(hist, hist_size);

	cin >> num;
	int points[num];
	genera_elementi(points, num, hist_size);
	stampa_array(points, num);

	for(int i = 0; i < num; i++) hist[points[i]]++;

	for(int i = 0; i < hist_size; i++)
	{
		cout << "\n" << i << "(" << setw(2) << "): ";
		for(int j = 0; j < hist[i]; j++)
			cout << "X";
	}
}


void scambia(int& a, int& b)
{
	int tmp = a;
	a = b;
	b  = tmp;
}

//void ordina_array(int A[], int len)
void bubble_sort(int A[], int len)
{

	for (int i = 0 ; i < len ; i++){
		for (int j = 0; j < len-1-i; j++)
			if (A[j] > A[j+1]) scambia(A[j], A[j+1]);
	}
}

//3

int mediano_array(const int A[], const int len)
{
	if(len == 0) return -1;
	else if(len%2 == 1) return A[len/2];
	else return (A[len/2-1] + A[len/2])/2;
}

//4

void trova_duplicati(const int from[], int dup[], int len, int& len_u)
{
	inizializza_array(dup, len);

	for(int i = 0; i < len - 1; i++)
	{
		if(dup[i] == 0)
		{
			len_u++;
			for(int j = i+1; j < len; j++)
				if(from[j] == from[i]) dup[j] = 1;
		}
	}
}

void copia_univoci(const int from[], const int dup[], int dest[], int len)
{
	int ind = 0;
	for(int i = 0; i < len; i++)
	{
		if(dup[i] == 0)
		{
			dest[ind] = from[i];
			 ind++;
		}
	}
}

void trova_univoci(const int from[], int dup[], int dest[], int len, int& n_univoci)
{
	trova_duplicati(from, dup, len, n_univoci);
	copia_univoci(from, dup, dest, len);

	stampa_array(from, len);
	stampa_array(dup, len);
	stampa_array(dest, n_univoci);
}


//5 - unione

void unione(const int A[], const int B[], int U[], int len1, int len2)
{
	int len3 = len1 + len2;
	inizializza_array(U, len3);

	int conc[len3];
	concatena_array(A, B, conc, len1, len2);
	stampa_array(conc, len3);

	int n_univoci = 0;
	int dup[len3];
	trova_duplicati(conc, dup, len3, n_univoci);
	stampa_array(dup, len3);
	copia_univoci(conc, dup, U, len3);
	stampa_array(U, n_univoci);

	bubble_sort(U, n_univoci);
	stampa_array(U, n_univoci);
}

