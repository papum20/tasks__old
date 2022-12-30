#include <iostream>
using namespace std;


int main()
{
	int h, b_max, b_min;
	cout << "altezza, base maggiore, base minore\n";
	cin >> h >> b_max;

	do{
		cin >> b_min;
		if(b_min > b_max) cout << "base minore maggiore di base maggiore, reinserisci\n";
		else if((b_max - b_min)%2 != 0) cout << "base maggiore - base minore deve esere pari, reinserisci\n";
	} while(b_min > b_max || (b_max - b_min)%2 != 0);



	double incr = (float)(b_max-b_min) / (2*(h-1));	//increment
	double c = 0;	//counter
	int hor_l = b_min;	//horizontal line
	int hor_s = (b_max-b_min) / 2;	//horizontal space
	bool allowed = true;

	for(int y = 0; y < h; y++)
	{
//		cout << incr << " " << c << " " << hor_l << " " << hor_s << endl;
		if(c >= 1.5)
		{
			hor_l += (int)c *2;
			hor_s -= (int)c;
			c -= (int)c;
		}
		else if(c >= 0.5 && allowed)
		{
			hor_l += 2;
			hor_s -= 1;
			allowed = false;
		}
		for(int x = 0; x < hor_s+hor_l; x++)
		{
			if(x < hor_s) cout << " ";
			else cout << "*";
		}
		cout << endl;
		c += incr;
	}



}






/*
label:
	cin >> b_min;
	if(b_min > b_max)
	{
		cout << "base minore maggiore di base maggiore, reinserisci\n";
		goto label;
	}
	else if((b_max - b_min)%2 != 0)
	{
		cout << "base maggiore - base minore deve esere pari, reinserisci\n";
		goto label;
	}
*/
