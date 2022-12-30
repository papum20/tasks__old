#include <iostream>
using namespace std;


int main()
{
	int a, b, c;
	char sign;
	cin >> a >> b >> c >> sign;

	if(sign == '-')
	{
	cout << " " << "\t" << a << "\t" << b << "\t" << c << endl;
	cout << a << "\t" << a-a << "\t" << b-a << "\t" << c-a << endl;
	cout << b << "\t" << a-b << "\t" << b-b << "\t" << c-b << endl;
	cout << c << "\t" << a-c << "\t" << b-c << "\t" << c-c << endl;
	}
	else if(sign == '/')
	{
		cout << " " << "\t" << a << "\t" << b << "\t" << c << endl;
		cout << a << "\t" << a/a << "\t" << b/a << "\t" << c/a << endl;
		cout << b << "\t" << a/b << "\t" << b/b << "\t" << c/b << endl;
		cout << c << "\t" << a/c << "\t" << b/c << "\t" << c/c << endl;
	}
	else
	{
		cout << "invalid sign";
	}

}
