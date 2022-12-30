#include <iostream>
using namespace std;

int main()
{
	double x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;


	if(x0==x1 && y0==y1)
		cout << "I punti coincidono";
	else if(x0==x1)
		cout << "x = " << x0;
	else
	{
		double m = (y0-y1)/(x0-x1);
		double q = y0 - m * x0;
		cout << "y = " << m << "x + " << q;
	}

}
