#include <iostream>
using namespace std;


int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << " " << "\t" << a << "\t" << b << "\t" << c << endl;
	cout << a << "\t" << a-a << "\t" << a-b << "\t" << a-c << endl;
	cout << b << "\t" << b-a << "\t" << b-b << "\t" << b-c << endl;
	cout << c << "\t" << c-a << "\t" << c-b << "\t" << c-c << endl;

}
