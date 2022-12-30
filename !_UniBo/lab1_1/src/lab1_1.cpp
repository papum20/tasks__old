#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;

	cout << "a+b=" << a+b << endl;
	cout << "a-b=" << a-b << endl;
	cout << "a*b=" << a*b << endl;
	cout << "a/b=" << setprecision(3) << a/b << endl;
	if((int)a==a && (int)b==b)
		cout << "a%b=" << (int)a%(int)b << endl;
	else
		cout << "a e b non sono interi";

}
