#include <iostream>
using namespace std;



string f(string n, bool riporto, int pos)
{
	if(pos == 5)
		return n;

	string us = n.substr(n.length()-1-pos, 1);
	int u = stoi(us);

	if(u < 5)
	{
		f(n.substr(0, n.length()-pos) + "0" + n.substr(n.length()-pos, pos), false, pos+1);
	}
	else
	{

	}

}



int main ()
{

	for(int i = 1; i < 10000; i++)
	{
		string b = to_string(i);
		string a = b.substr(0,1) + "0000";


	}

}
