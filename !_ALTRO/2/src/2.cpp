#include <iostream>
#include <math.h>
using namespace std;



int n[6] = {};
int tot = 0;



int tr()
{
	int tmp = 0;
	for(int i = 0; i < 6; i++)
	{
		if(n[i] == 1){
			tmp += pow(2, i);
			tmp += pow(2, 11-i);
		}
	}

	return tmp;
}






void f(int pos)
{


	if(pos == 6)
		return;

	if(n[pos] == 0)
	{
		n[pos] = 1;
		for(auto i:n)
			cout<<i;
		cout<<" "<<tr()<<"\n";
		tot += tr();
		f(0);
	}

	else
	{
		for(int i = 0; i <= pos; i++)
			n[i] = 0;
		f(pos+1);
	}


}





int main()
{


	for(int i = 0; i < 6; i++)
		n[i] = 0;


	f(0);

	cout << tot;

}
