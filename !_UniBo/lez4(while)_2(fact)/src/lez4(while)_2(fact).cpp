#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	if(n == 0)
		cout << 1;
	else if(n < 0)
		cout << "error";
	else
	{
		int fact = 1;
		while(n > 0)
		{
			fact *= n;
			n--;
		}
		cout << fact;
	}
}
