#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	if(n == 0)
		cout << 0;
	else if(n < 0)
		cout << "error";
	else
	{
		int res = 0;
		int parziale;

		//quante volte eseguirò il programma, ovvero quanti gruppi di due cifre ci sono in n, e cento_counter...
		int counter = 0, cento_counter = 1;
		while (cento_counter*100 <= n){
			counter++;
			cento_counter *= 100;
		}


		//algoritmo di Bombelli
		while(counter >= 0)
		{
			//calcolo parziale, con coppia di cifre di n; diminuisco cento_counter
			parziale = n / cento_counter;

			//trovo minimo mult tale che mult(20*res+mult) sia il più alto possibile ma minore di parziale
			int mult = 1, da_sottrarre;	//multiplier
			while(mult * (20*res + mult) <= parziale)
				mult++;
			mult--;
			da_sottrarre = mult * (20*res + mult);
			//aggiorno risultato
			res = res*10 + mult;

			//aggiorno n
			n -= da_sottrarre * cento_counter;
			counter--;
			cento_counter /= 100;
		}

		cout << res;
	}



}
