#include <iostream>
using namespace std;



int main()

{

	int res = 0;
	int tot = 0;

	for(int a = 1; a <= 37; a++)
	{
		for(int b = a+1; b <= 38; b++)
		{
			for(int c = b+1; c <= 39; c++)
			{
				for(int d = c+1; d <= 40; d++)
				{
					tot++;

					if((a+b+c+d) % 5 == 0)
					{
						cout<<a+b+c+d<<endl;
						res++;
					}
				}
			}
		}
	}

	cout << res << " " << tot;

}
