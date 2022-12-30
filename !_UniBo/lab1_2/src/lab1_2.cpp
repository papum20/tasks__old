#include <iostream>
#include <ctime>
using namespace std;





int main()
{
	srand(time(NULL));
	int a, b;
	cin >> a >> b;

	int rval = rand()%5;
	if(rval == 0) cout << "a+b=" << a+b;
	else if(rval == 1) cout << "a-b=" << a-b;
	else if(rval == 2) cout << "a*b=" << a*b;
	else if(rval == 3) cout << "a/b=" << a/b;
	else if(rval == 4) cout << "a%b=" << a%b;
	}
