/*
FUNZIONA PER N MINORE O UGUALE A 30, CIOÈ 30 RIGHE; OLTRE 30 VA IN OVERFLOW
 */





#include <iostream>
using namespace std;




int main()
{
	int n;
	cin >> n;

	//SE INPUT=0 NON STAMPA NIENTE
	if(n == 0)
		return 0;


	int spaces = n-1;	//SPAZI PRIMA DEL PRIMO NUMERO DELLA RIGA

	//STAMPA PRIMA RIGA
	int i = 0;
	while(i < spaces)
	{
		cout << " \t";
		i++;
	}
	cout << 1 << endl;
	spaces--;


	//STAMPA DALLA SECONDA RIGA
	i = 1;
	while(i < n)	//PER OGNI RIGA DALLA SECONDA
	{
		int j = 0;
		while(j < spaces)	//STAMPA SPAZI PRIMA DEL PRIMO NUMERO
		{
			cout << " \t";
			j++;
		}

		j = 0;
		while(j <= i)	//STAMPA NUMERI, CALCOLATI CON LE COMBINAZIONI
		{
			uint64_t combinazione = 1;	//long long unsigned int

			if(j >= i-j)
			{
				int k = j+1;
				while(k<=i)
				{
					combinazione *= k;
					k++;
				}
				k = 2;
				while(k<=i-j)
				{
					combinazione /= k;
					k++;
				}
			}
			else
			{
				int k = i-j+1;
				while(k<=i)
				{
					combinazione *= k;
					k++;
				}
				k = 2;
				while(k<=j)
				{
					combinazione /= k;
					k++;
				}
			}

			if(combinazione < 10000000) cout << combinazione << "\t\t";
			else cout << combinazione << "\t";
			j++;
		}

		cout << endl;
		spaces--;
		i++;
	}

}





/*
while(k <= i)
{
	combinazione *= k;
	k++;
}
k = 2;
while(k <= j)
{
	combinazione /= k;
	k++;
}
k = 2;
while(k <= i-j)
{
	combinazione /= k;
	k++;
}
*/
