#include <iostream>
using namespace std;


const string letters = "abcdefghijklmnopqrstuvwxyz";

int main()
{
	char a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;



	for(int i = 0; i < 26; i++)
	{
		if(letters[i] == a){
			cout << a << " ";
			break;
		}
	}

	for(int i = 0; i < 26; i++)
	{
		if(letters[i] == b){
			cout << b << " ";
			break;
		}
	}

	for(int i = 0; i < 26; i++)
	{
		if(letters[i] == c){
			cout << c << " ";
			break;
		}
	}
}
