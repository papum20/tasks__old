#include <iostream>
using namespace std;



int main()
{
	int a, b, c;
	cin >> a >> b >> c;


	cout << ((a%b==0 && a%c==0) || (b%a==0 && b%c==0) || (c%a==0 && c%b==0));

}
