#include "library.h"
using namespace std;


const int length = 20;
const int mx = 30;


int main()
{

	srand(time(NULL));

	/*
	int a[length], b[length], c[length*2];
//	inizializza_array(arr, length);
//	stampa_array(arr, length);
	genera_elementi(a, length, mx);
	stampa_array(a, length);
	genera_elementi(b, length, mx);
	stampa_array(b, length);

	concatena_array(a, b, c, length, length);
	stampa_array(c, length*2);


	ordina_array(a, length);
	stampa_array(a, length);

	cout << mediano_array(a, length);
*/





	//4 - NO DUPLICATI
/*
	int n_univoci = 0;
	int from[length], dup[length], dest[length];
	genera_elementi(from, length, mx);

	trova_univoci(from, dup, dest, length, n_univoci);
*/

	//5 - UNIONE

	int A[length], B[length], U[2*length];
	genera_elementi(A, length, mx);
	genera_elementi(B, length, mx);
	stampa_array(A, length);
	stampa_array(B, length);

	unione(A, B, U, length, length);

}













/*
	const int mxRand = 30;
	int N;
	cin >> N;
	int d[N];

	genera_elementi(d, N, mxRand);
	for(int i = 0; i < N; i++)
	{
		cout << setw(2) << i << "(" << setw(2) << d[i] << "):" << " ";
		for(int j = 0; j < d[i]; j++) cout << "X";
		cout << endl;
	}
*/

