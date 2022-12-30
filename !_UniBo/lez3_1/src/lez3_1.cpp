#include <iostream>
using namespace std;


int main()
{
	char x, y;
	cin >> x >> y;

	//EX 1
//	char tmp = x;
//	x = y;
//	y = tmp;


	//EX 2
//	x = (char)((int)x - (int)y);
//	y = (char)((int)y + (int)x);
//	x = (char)((int)y - (int)x);

	x = x-y;
	y = y + x;
	x = y - x;

	cout << x << y;
}
