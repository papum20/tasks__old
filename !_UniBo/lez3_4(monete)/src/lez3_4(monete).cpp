#include <iostream>
using namespace std;





int main()
{
	double euro;
	cin >> euro;
	euro*=100;

	if(euro >= 200)
	{
		int tmp = euro/200;
		cout << "monete da 2 euro: " << tmp << endl;
		euro -= tmp * 200;
	}
	if(euro >= 100)
	{
		cout << "monete da 1 euro: " << 1 << endl;
		euro -= 100;
	}


	if(euro >= 50)
	{
		cout << "monete da 50 cent: " << 1 << endl;
		euro -= 50;
	}
	if(euro >= 20)
	{
		int tmp = euro/20;
		cout << "monete da 20 cent: " << tmp << endl;
		euro -= tmp * 20;
	}
	if(euro >= 10)
	{
		cout << "monete da 10 cent: " << 1 << endl;
		euro -= 10;
	}
	if(euro >= 5)
	{
		cout << "monete da 5 cent: " << 1 << endl;
		euro -= 5;
	}
	if(euro >= 2)
	{
		int tmp = euro/2;
		cout << "monete da 2 cent: " << tmp << endl;
		euro -= tmp * 2;
	}
	if(euro >= 1)
	{
		cout << "monete da 1 cent: " << 1 << endl;
		euro -= 1;
	}

}
