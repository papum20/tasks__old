#include <iostream>
using namespace std;




int main()
{
	int n;
	cin >> n;

	cout << "ORE: " << n/3600 << " ";
	n %= 3600;
	cout << "MINUTI: " << n/60 << " ";
	n %= 60;
	cout << "SECONDI: " << n;


}
