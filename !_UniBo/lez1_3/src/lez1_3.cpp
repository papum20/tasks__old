#include <iostream>
using namespace std;

int main()
{
	int max_cifre=4-1;

	int a,b_int;
	cin >> a >> b_int;

	string b_string = to_string(b_int);
	while(b_string.length() <= max_cifre)
		b_string += "0";
	int b[max_cifre];
	int ind = 0;
	for(int j = max_cifre; j >= 0; j--)
		b[ind++] = stoi(b_string.substr(j,1));



	int i = 0, moltiplicatore_cifra = 1, prodotto = 0;

	while(i <= max_cifre)
	{
		int cifra_b = b[i];

		int somma_tmp = a*cifra_b*moltiplicatore_cifra;
		prodotto += somma_tmp;

		i++;
		moltiplicatore_cifra *= 10;
	}


	cout << prodotto;

}
