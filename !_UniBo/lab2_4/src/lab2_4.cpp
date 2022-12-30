#include <iostream>
#include <ctime>
using namespace std;




int main()
{
	srand(time(NULL));

	int n = rand()%100;

	bool guessed = false;
	int x;
	do
	{
		cin >> x;
		if(x==n) guessed = true;
		else if(x > n) cout << "TROPPO GRANDE\n";
		else if(x < n) cout << "TROPPO PICCOLO\n";
	} while(guessed == false);

	cout << "INDOVINATO";

}
