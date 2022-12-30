#include <iostream>
using namespace std;



const int len = 5;



bool palindromo(int arr[], const int length)
{
	bool res = true;

	for(int i = 0; i < length/2 && res; i++)
		if(arr[i]!=arr[length-1-i]) res = false;

	return res;
}




int main()
{
	int input[len];
	for(int i = 0; i < len; i++)
		cin >> input[i];

	cout << palindromo(input, len);
}
