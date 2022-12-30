#include <iostream>
using namespace std;



int main()
{

	int n;
	cin >> n;


	int first = 1;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(j==0) first += j;
			cout << first + j << "\t";
		}
		cout << endl;
		first += i;
	}

}
