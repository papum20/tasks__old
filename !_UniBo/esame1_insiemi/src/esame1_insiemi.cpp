#include <iostream>
using namespace std;



const int length = 100;


struct insieme {
	int num;
	int data[length];
};


insieme new_insieme(int A[], int len)
{
	insieme tmp;
	tmp.num = len;
	for(int i = 0; i < len; i++)
		tmp.data[i] = A[i];

	//SORTING
	/*for(int i = 0; i < len-1; i++)
	{
		int l =
	}*/
}





int cardinalita_unione(insieme A, insieme B)	//PRECONDITION: A e B ordinati
{
	int res = 0;
	int i = 0, j = 0;
	bool incr_i = false;
	while(i < A.num-1 || j < B.num-1)
	{
		incr_i = false;

		if(j == B.num-1 || (i < A.num-1 && A.data[i] <= B.data[j]) )
			incr_i = true;
		if(i == A.num-1 || (j < B.num-1 && B.data[j] <= A.data[i]) )
			j++;

		if(incr_i) i++;
		res++;
		cout << i <<" " << j << " "<<A.data[i] << " " << B.data[j] << " " ;
		cout << res<<endl;
	}

	return res;
}







int main()
{
	insieme A, B;
	cin >> A.num >> B.num;
	for(int i = 0; i < A.num; i++)
		cin >> A.data[i];
	for(int i = 0; i < B.num; i++)
		cin >> B.data[i];


	cout << cardinalita_unione(A, B);
}
