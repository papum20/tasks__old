#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	double m = (a+b+c)/3.;

	bool ab = (abs(m-a) <= abs(m-b));
	bool ac = (abs(m-a) <= abs(m-c));
	bool bc = (abs(m-b) <= abs(m-c));

	if(ab)
	{
		if(ac)
		{
			if(bc) cout << a << " " << b << " " << c;
			else cout << a << " " << c << " " << b;
		}
		else
			cout << c << " " << a << " " << b;
	}
	else
	{
		if(bc)
		{
			if(ac) cout << b << " " << a << " " << c;
			else cout << b << " " << c << " " << a;
		}
		else
			cout << c << " " << b << " " << a;
	}

}
