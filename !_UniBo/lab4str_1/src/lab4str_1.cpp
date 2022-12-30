#include "libr.h"
using namespace std;


/*
"A" = 65
"Z" = 90
"a" = 97
"z" = 122
*/






int main()
{
	char S[20] = "CiaOoOlao";
	char sub[20] = "Ci";

	remove_substr(S, sub);

	cout << S;

}
