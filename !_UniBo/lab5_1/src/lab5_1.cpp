#include <iostream>
#include <string.h>
using namespace std;


int search(char A[], int l)
{
	int ind = -1;
	bool found = false;

	int i = 0;
	while(!found && i < l-1)
	{
		if(A[i] == A[i+1])
		{
			ind = i;
			found = true;
		}
		i++;
	}

	return ind;
}


int main()
{
	char arr[] = "aasfnakk";
	cout << search(arr, strlen(arr));

}
