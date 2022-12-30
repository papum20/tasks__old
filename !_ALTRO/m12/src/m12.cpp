#include <iostream>
#include <cmath>
using namespace std;


int64_t res[2];

void f()
{
	for(int64_t x = -101; x <= 100; x++)
	{
		for(int64_t y = -101; y <= 100; y++)
		{
			double a = x*x+36*y*y+4*x*x*y*y+4*x*x*y-24*x*y*y+48*x*y+30*x-180*y+232;
			if(a < 0)
				continue;
			float tmp = pow(a, 0.5);
			cout << a << " " << tmp <<endl;
			if(tmp == (int)tmp){
				res[0] = x;
				res[1] = y;
				return;
			}
		}
	}
}



int main()
{

	f();

	cout << res[0] << " " << res[1];

}
