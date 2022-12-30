#include <iostream>
using namespace std;


int main()
{
	double n;
	cin >> n;


	if(n <= 0)
		cout << "error";
	else if(n < 1)
	{
		int log = -1;
		double pow = 0.5;
		while(pow/2 >= n)
		{
			pow /= 2;
			log--;
		}
		cout << log;
	}
	else
	{
		int log = 0, pow = 1;
		while(pow*2 <= n)
		{
			pow *= 2;
			log++;
		}

		cout << log;
	}
}
