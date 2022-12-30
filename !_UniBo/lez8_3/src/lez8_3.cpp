#include <iostream>
#include <ctime>
using namespace std;



const int L = 20;


void push1(int A[], const int len, int e)
{
	if(A[0]+1 < len-A[len-1]-1)
	{
		A[A[0]+1] = e;
		A[0]++;
	}
	else cout << "overflow" << endl;
}

void pop1(int A[])
{
	if(A[0] > 0) A[0]--;
}

bool is_empty1(int A[])
{
	return A[0]==0;
}

int top1(int A[])	//Precondition: len > 0
{
	return A[A[0]];
}





void push2(int A[], const int len, int e)
{
	if(A[0]+1 < len-A[len-1]-1)
	{
		A[len-A[len-1]-2] = e;
		A[len-1]++;
	}
	else cout << "overflow" << endl;
}

void pop2(int A[], const int len)
{
	if(A[len-1] > 0) A[len-1]--;
}

bool is_empty2(int A[], const int len)
{
	return A[len-1]==0;
}

int top2(int A[], const int len)	//Precondition: len > 0
{
	//if(!is_empty2(A, len))
	return A[len-A[len-1]-1];
}








int main()
{

	srand(time(NULL));

	int arr[L];
	arr[0] = 0;
	arr[L-1] = 0;

	for(int i = 0; i < 12; i++)
	{
		push1(arr, L, rand()%20);
		for(int j = 0; j < L; j++)
			cout << arr[j] << " ";
		cout << endl;
	}

	for(int i = 0; i < 12; i++)
	{
		push2(arr, L, rand()%20);
		for(int j = 0; j < L; j++)
			cout << arr[j] << " ";
		cout << endl;
	}
	cout << top1(arr) << endl;
	cout << top2(arr, L) << endl;

}
