#include <iostream>
using namespace std;



const int L = 20;


void parola(char str[], int n, char dest[])		//Precondition: str è riempito completamente
{
	int p = 0;							//parola corrente
	int i = 0;							//indice di str[]
	int j = 0;							//indice di dest[]
	bool in_parola = false;				//ti trovi in una parola (per evitare problemi con spazi consecutivi)

	while(p <= n && i < L)
	{
		if(str[i] == ' ')
			in_parola = false;
		else if(str[i] != ' ' && in_parola == false)
		{
			in_parola = true;
			p++;
		}

		if(p == n && in_parola)
		{
			dest[j] = str[i];
			j++;
		}

		i++;
	}
}



int main()
{
	char str[L], dest[L];



	//PROVE

	string s = "anfikaf   af a s  ss";
	for(int i = 0; i < L; i++)
		str[i] = s[i];
	parola(str, 1, dest);
	cout << endl;
	for(auto i:dest)
		cout << i;

	parola(str, 2, dest);
	cout << endl;
	for(auto i:dest)
		cout << i;

	parola(str, 3, dest);
	cout << endl;
	for(auto i:dest)
		cout << i;

	parola(str, 4, dest);
	cout << endl;
	for(auto i:dest)
		cout << i;

	parola(str, 5, dest);
	cout << endl;
	for(auto i:dest)
		cout << i;

	parola(str, 6, dest);
	cout << endl;
	for(auto i:dest)
		cout << i;

	parola(str, 7, dest);
	cout << endl;
	for(auto i:dest)
		cout << i;
}
