#include <iostream>
using namespace std;





int foo1(int A[], int length)
{
	int max = -1;

	for(int i = 0; i < length-1; i++)
	{
		bool found = false;
		int j = i+1;
		while(!found && j < length)
		{
			if(A[i] == A[j])
			{
				found = true;
				if(j-i > max) max = j-i;
			}
			else j++;
		}
	}

	return max;
}




int foo(int A[], int length)
{
	int dist = length-1;
	bool found = false;

	while(!found && dist > 0)
	{
		int i = 0;
		while(!found && i < length - dist)
		{
			if(A[i] == A[i + dist]) found = true;
			else i++;
		}

		dist--;
	}

	if(!found) return -1;
	else return dist + 1;
}



int main()
{
	int A[6] = {2,1,2,3,4,2};
	cout << foo1(A, 6);
}
