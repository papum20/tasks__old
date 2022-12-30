#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int res = 0;

	for(int i = 1; i <= 2021; i++)
	{
	//	cout<<i<<endl;
		uint64_t a = pow(i,2);
		uint64_t b = pow(i,3);

		for(int j = 1; j <= a; j++)
		{
			uint64_t n = (j+(j+i-1))*i/2;
		//	cout<<"j"<<j<<" "<<n <<endl;
			if(n>a) break;

			if(n == a)
			{
				bool x = false;

				for(int k = 1; k <=b; k++)
				{
					uint64_t m = (k+(k+i-1))*i/2;
		//			cout<<"k"<<k<<" "<<m <<endl;

					if(m>b){
						x=true;
						break;
					}

					if(m==b)
					{
						cout<<i<<" "<<j<<" "<<k<<endl;
						res++;
						x=true;
						break;
					}
				}

				if(x==true)
					break;
			}

		}

	}

	cout<<res;
}
