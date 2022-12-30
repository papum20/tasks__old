#include <iostream>
using namespace std;


//1
void bin_to_dec()
{
	long long int bin;
	cin >> bin;
	int dec = 0;
	int potenza = 1;

	while(bin > 0)
	{
		if(bin%10 == 1) dec += potenza;
		potenza *= 2;
		bin /= 10;
	}

	cout << dec;
}


//2
void f2()
{
	long long int x, y;
	cin >> x >> y;
	long long int somma = 0, prodotto = 0;

	//SOMMA
	long long int x1 = x, y1 = y;
	long long int mult = 1;	//mult=moltiplicatore
	int riporto = 0;

	while(x1 > 0 || y1 > 0)
	{
		long long int tmp = x1%10 + y1%10 + riporto;
		if(tmp%2 == 1) somma += mult;
		if(tmp >= 2) riporto = 1;
		else riporto = 0;
		mult *= 10;
		x1 /= 10;
		y1 /= 10;
	}
	if(riporto == 1)
		somma += mult;

	//PRODOTTO
	long long int mult2 = 1;
	while(y > 0)
	{
		if(y%10 == 1)
		{
			long long int x2 = x*mult2, somma_tmp = 0;
			riporto = 0, mult = 1;
			while(x2 > 0 || prodotto > 0)
			{
				long long int somma_bit = x2%10 + prodotto%10 + riporto;
				if(somma_bit%2 == 1) somma_tmp += mult;
				if(somma_bit >= 2) riporto = 1;
				else riporto = 0;
				x2 /= 10;
				prodotto /= 10;
				mult *= 10;
			}
			if(riporto == 1)
				somma_tmp += mult;
			prodotto = somma_tmp;
		}
		y /= 10;
		mult2 *= 10;
	}

	cout << somma << " " << prodotto;
}



//3
void f3()
{
	int x, y;
	cin >> x >> y;
	cout << x*x+y*y << " " << x*x*y;
}


//4
void f4()
{
	int n;
	cin >> n;
	int res = 0;

	while(n > 0)
	{
		res = res*10 + (n%10);
		n /= 10;
	}

	cout << res;
}




int main()
{
//	bin_to_dec();
	f2();
//	f3();
//	f4();
}
