#include <iostream>
using namespace std;


int res[3];

void f()
{
	for(int a = 10; a < 100; a++)
	{
		for(int b = 10; b < 100; b++)
		{
			for(int c = 10; c < 100; c++)
			{
				if( 4*a+4*b+4*c+a*b*c == 2439+2*(a*b+b*c+c*a) ){
					res[0] = a;
					res[1] = b;
					res[2] = c;
					return;
				}
			}
		}
	}
}




int main()
{

	f();

	cout<<res[0]<<" "<<res[1]<<" "<<res[2];

}
