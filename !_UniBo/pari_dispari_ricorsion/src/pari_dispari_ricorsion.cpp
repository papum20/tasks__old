#include <iostream>
using namespace std;




const int len = 20;
/*
void ricorsiva(int A[], const int length, int pos, bool forward, int start)
{
	cout << pos << ":\t";
	for(int i = 0; i < length; i++) cout << A[i] << " ";
	cout << endl;
	if(forward)
	{
		if(A[pos]%2 == 1) ricorsiva(A, length, length-1, false, pos);
		else if(pos < length-1) ricorsiva(A, length, pos+1, true, start);
	}
	else
	{
		if(A[pos]%2 == 0)
		{
			int tmp = A[pos];	//SCAMBIA
			A[pos] = A[start];	//SCAMBIA
			A[start] = tmp;		//SCAMBIA
			ricorsiva(A, length, start, true, start);
		}
		else if(pos > start+1) ricorsiva(A, length, pos-1, false, start);
	}
}
*/
void ricorsiva(int A[], const int length, int pos, bool forward, int start, int last)	//last = last ordered
{
	cout << pos << ":\t";
	for(int i = 0; i < length; i++) cout << A[i] << " ";
	cout << endl;
	if(forward && pos < last-1)
	{
		if(A[pos]%2 == 1) ricorsiva(A, length, last-1, false, pos, last);
		else ricorsiva(A, length, pos+1, true, start, last);
	}
	else if(pos > start)
	{
		if(A[pos]%2 == 0)
		{
			int tmp = A[pos];	//SCAMBIA
			A[pos] = A[start];	//SCAMBIA
			A[start] = tmp;		//SCAMBIA
			ricorsiva(A, length, start+1, true, start, pos);
		}
		else ricorsiva(A, length, pos-1, false, start, last);
	}
}



int main()
{

	int a[len] = {0,0,1,1,0,0,0,1,1,1,0,1,1,1,0,1,0,0,0};
	ricorsiva(a, len, 0, true, 0, len);
	for(auto i:a) cout << i << " ";

}
