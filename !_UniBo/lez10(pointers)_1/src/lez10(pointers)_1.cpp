#include <iostream>
using namespace std;


//4
struct s{
	int a,b,c,d,e;
};





int main()
{
	//1
	int *n1 = new int;
	*n1 = 1;
	int *n2 = n1;
	*n1 = *n2+1;
	*n2 = *n1+1;
//	int *n1 = &n;
//	*n1 += 1;
//	int *n2 = n1;
//	*n2 += 1;
	cout << *n2 << "\n\n";

	//2
	int *m1 = new int;
	*m1 = 1;
	*m1 = *m1+1;
	cout << *m1<< "\n\n";
	delete m1;
	m1 = NULL;

	//3
	int arr[10];
	/*
	int *p = arr;
	for(int i = 0; i < 10; i++)
	{
		int tmp;
		cin >> tmp;
		*p = tmp;
		p = p+1;
	}
	*/
	int *p;
	for(int i = 0; i < 10; i++)
	{
		p = &arr[i];
		cin >> *p;
	}
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << "\n\n";

	//4
	s *q = new s;
	(*q).a = 1;
	(*q).b = 2;
	(*q).c = 3;
	(*q).d = 4;
	(*q).e = 5;
	cout << (*q).a << " " << (*q).b << " " << (*q).c << " " << (*q).d << " " << (*q).e;


}
