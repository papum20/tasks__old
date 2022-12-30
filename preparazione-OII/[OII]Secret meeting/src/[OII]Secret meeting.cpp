#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;





int main()
{
	int T;
	cin >> T;

	for(int t = 0; t < T; t++)
	{
		double xa, ya, xb, yb, xc, yc, R;
		cin >> xa >> ya >> xb >> yb >> xc >> yc >> R;

		double ab = sqrt(pow(xa-xb,2)+pow(ya-yb,2)), ac = sqrt(pow(xa-xc,2)+pow(ya-yc,2)), bc = sqrt(pow(xb-xc,2)+pow(yb-yc,2));

		if(ac <= R && bc <= R)
			cout << fixed << setprecision(6) << 0.0 << endl;
		else if(ac > R && bc > R)
			cout << fixed << setprecision(6) << (floor(min(ab, ac + bc - R*2)*pow(10,6)) /pow(10,6)) << endl;
		else if(ac <= R && bc > R)
			cout << fixed << setprecision(6) << (floor((bc - R)*pow(10,6)) /pow(10,6)) << endl;
		else if(ac > R && bc <= R)
			cout << fixed << setprecision(6) << (floor((ac - R)*pow(10,6)) /pow(10,6)) << endl;
	}


}
