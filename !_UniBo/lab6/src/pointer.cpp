#include "lib.h"
using namespace std;





void scambia_ppint(ppint x, ppint y)
{
	int tmp = **x;
	**x = **y;
	**y = tmp;
}

