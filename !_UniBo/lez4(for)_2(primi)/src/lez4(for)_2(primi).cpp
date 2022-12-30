#include <iostream>
using namespace std;




int main()
{
//	for(int j = 0; j <= 100; j++)
//	{
		double m;
		cin >> m;
		int n = m;

		if(n != m)
			cout << "non intero";
		else if(n < 2 || (n%2 == 0 && n!=2) )
			cout << "non_primo";
		else if(n == 2 || n == 3)
			cout << "primo";
		else
		{
			/*
			int div = 3;
			bool primo = false;
			while(n%div != 0)
			{
				div += 2;
				if(div*div >= n)
				{
					primo = true;
					cout << "primo";
					div = n;
				}
			}

			if(primo == false)
				cout << "non_primo";
			*/
			bool primo = true;
			for(int div = 3; div*div <= n; div+=2)
			{
				if(n%div == 0)
				{
					primo = false;
					cout << "non_primo";
					div = n;
				}
			}
			if(primo == true)
				cout << "primo";
		}

//	}
}
