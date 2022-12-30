#include <iostream>
using namespace std;


int main()
{
	int n, div;
	cin >> n;
	cout << "\ndimmi un divisore di n\n";

	do{
		cin >> div;
		cout << "\n";
	} while(n%div != 0);
}
