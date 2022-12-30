#include <iostream>
#include <cstring>
using namespace std;


//1_1

void stampa_piu_lunga(char A[], char B[], char C[])
{
	int a = strlen(A);
	int b = strlen(B);
	int c = strlen(C);
	if((a>=b)&&(a>=c)) cout << A;
	else if ((b>=a)&&(b>=c)) cout << B;
	else cout << C;
}


//1_2
void primo_alfabetico(char A[], char B[])
{
	if(strcmp(A, B) < 0)
		cout << A;
	else if(strcmp(A, B) > 0)
		cout << B;
	else
		cout << "sono uguali";
}


//1_3
void parola(char str[], char c, char dest[])	//Precondition: dest è abbastanza grande
{
	bool space = true, found = false, completed = false;
	int i = 0, j = 0;

	while(i < strlen(str) && !completed)
	{
		if(str[i] == ' ')
			{
			if(found) completed = true;
			space = true;
			found = false;
			}
		else
		{
			if(space && str[i] == c) found = true;
			space = false;
		}

		if(found)
		{
			dest[j] = str[i];
			j++;
		}
		i++;
	}

	dest[j] = '\0';
}


//1_4

bool find(char s[], const int len)	//len=strlen(s)
{
	int i = 0;
	bool found_first = false, found_second = false;
	while(found_second == false && i < len)
	{
		if(!found_first && (s[i] == 'g' || s[i] == 'c')) found_first = true;
		else if(found_first && s[i] == 'h') found_second = true;
		else if(found_first && s[i] != 'h' && s[i] != 'c' && s[i] != 'g') found_first = false;
		i += 1;
	}
	return found_second;
}


//prende str e inverte

void inverti(char A[])
{
	int len = strlen(A);
	for(int i = 0; i < len/2; i++)
	{
		char tmp = A[i];
		A[i] = A[len-1-i];
		A[len-1-i] = tmp;
	}
}



//stringa A, due valori l e r, stringa B, memorizza in B caratteri di A da l a r

void f(char A[], int l, int r, char B[])	//r escluso; Precondition: A,B stringhe, l <= r
{
	if(r > strlen(A))
		cout << "out of bound";
	else if(sizeof(B)-1 < r-l)
		cout << "B troppo piccolo";
	else
	{
		int j = 0;		//indice di B
		for(int i = l; i < r; i++)
		{
			B[j] = A[i];
			j = j+1;
		}
		B[j] = '\0';
	}
}


//2_1
void conc(char A[], char B[])
{
	int i = strlen(A);
	for(int j = 0; j < strlen(B); j++)
		A[i+j] = B[j];
}


//2_2
bool maiusc(char A[])
{
	bool maiusc = true;
	int i = 0;
	while(i < strlen(A) && maiusc)
	{
		if(A[i] > 'Z' || A[i] < 'A') maiusc = false;
		i++;
	}
	return maiusc;
}

//2_3
void elim(char A[], int n)
{
	A[n] = '\0';
}



int main()
{

	char a[20], b[20];
	cin >> a >> b;
	elim(a, 4);
	cout << a;

}
