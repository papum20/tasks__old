#include <iostream>
using namespace std;




int main()
{
	uint64_t tot = 0;

	for(int a = 2; a <= 2019; a++)
	{
		for(int b = a+1; b <= 2020; b++)
		{
			for(int c = b+1; c <= 2021; c++)
			{
				int a1 = a-1;
				int b1 = b-1-2;
				int c1 = c-1-4;
				if(a1<0) a1=0;
				if(b1<0) b1=0;
				if(c1<0) c1=0;

				tot += a1*b1*c1;

				a1 = 2021-a;
				b1 = 2021-b-2;
				c1 = 2021-c-4;
				if(a1<0) a1=0;
				if(b1<0) b1=0;
				if(c1<0) c1=0;

				tot += a1*b1*c1;
			}
		}
	}


	cout << tot;

}
