/*
FUNZIONA PER N MINORE O UGUALE A 30, CIOÈ 30 RIGHE; OLTRE 30 VA IN OVERFLOW PER ALCUNI VALORI
 */





#include <iostream>
using namespace std;




int main()
{
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	//SE INPUT=0 NON STAMPA NIENTE
	if(n == 0)
		return 0;


	int spaces = n-1;	//SPAZI PRIMA DEL PRIMO NUMERO DELLA RIGA

	//STAMPA PRIMA RIGA
	for(int i = 0; i < spaces; i++)
		cout << " \t";
	cout << 1 << endl;
	spaces--;

	//STAMPA DALLA SECONDA RIGA
	for(int i = 1; i < n; i++)	//PER OGNI RIGA DALLA SECONDA
	{
		for(int j = 0; j < spaces; j++)	//STAMPA SPAZI PRIMA DEL PRIMO NUMERO
			cout << " \t";

		for(int j = 0; j <= i; j++)	//STAMPA NUMERI, CALCOLATI CON LE COMBINAZIONI
		{
			uint64_t combinazione = 1;	//LONG LONG UNSIGNED INT

			if(j >= i-j)
			{
				for(int k = j+1; k<=i; k++)
					combinazione *= k;
				for(int k = 2; k <= i-j; k++)
					combinazione /= k;
			}
			else
			{
				for(int k = i-j+1; k<=i; k++)
					combinazione *= k;
				for(int k = 2; k <= j; k++)
					combinazione /= k;
			}


			if(combinazione < 10000000) cout << combinazione << "\t\t";
			else cout << combinazione << "\t";
		}

		cout << endl;
		spaces--;
	}

}






//			for(int k = 2; k<=i; k++)
//			{
////				if(!((k%2==0 && k<=i/2) || (k%2==1 && k<=i/2)) )
////					combinazione *= k;
//				if(k>j)
//					combinazione *= k;
//				if(k <= i-j)
//					combinazione /= k;
//			}
			/*
			for(int k = 2; k<=i; k++)
				combinazione *= k;
			for(int k = 2; k<=j; k++)
				combinazione /= k;
			for(int k = 2; k <=i-j; k++)
				combinazione /= k;
			*/
