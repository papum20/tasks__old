#include <iostream>
using namespace std;


const int len = 10;



int foo(int A[], const int length)
{
	int res = -1;

	int i = 0, j;
	while(i < length && res==-1)
	{
		j = i+1;
		while(j<length && res==-1)
		{
			if(A[j]==A[i]) res = i;
			else j += 1;
		}

		i += 1;
	}

	return res;
}



int main()
{

	int arr[len];
	for(int i = 0; i < len; i++)
		cin >> arr[i];

	cout << foo(arr, len);


}
