#include <iostream>
using namespace std;



bool is_in(int A[], const int len, int e)
{
	bool res = false;
	int i = 0;
	while(i < len && res==false)
	{
		if(A[i] == e) res = true;
		i++;
	}
	return res;
}




void no_duplicati(int V[], const int length)
{
	int usati[length];
	int n_usati = 0;

	for(int i = 0; i < length; i++)
	{
		if(!is_in(usati, n_usati, V[i]))
		{
			cout << V[i] << " ";
			usati[n_usati] = V[i];
			n_usati++;
		}
	}
}



int main()
{
	const int l = 10;
	int arr[l];
	for(int i = 0; i < l; i++)
		cin >> arr[i];

	no_duplicati(arr, l);
}
