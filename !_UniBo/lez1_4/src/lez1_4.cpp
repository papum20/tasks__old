#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	float media = (a+b+c+d)/4.0;
	float differenza_max = abs(media-a);
	int numero = a;

	if(abs(media-b) < differenza_max)
	{
		differenza_max = abs(media-b);
		numero = b;
	}
	if(abs(media-c) < differenza_max)
	{
		differenza_max = abs(media-c);
		numero = c;
	}
	if(abs(media-d) < differenza_max)
	{
		cout << d;
	}

	else
		cout << numero;
}
