#include <iostream>
using namespace std;



//Mux8Way16
/*
int bin[3] = {0,0,0};
void binIncrement(int pos, int length=3)
{
	if(pos >= length)
		return;

	if(bin[pos] == 0)
	{
		bin[pos] = 1;
		for(int i = 0; i < pos; i++)
			bin[i] = 0;
	}
	else
		binIncrement(pos+1);
}

const string names[4] = {"notSel0", "notSel1", "notSel2"};
const string numbers[8] = {"sel0", "sel1", "sel2", "sel3", "sel4", "sel5", "sel6", "sel7"};
const string letters = "abcdefgh";
*/

//DMux4Way7
/*
int bin[2] = {0,0};
void binIncrement(int pos, int length=2)
{
	if(pos >= length)
		return;

	if(bin[pos] == 0)
	{
		bin[pos] = 1;
		for(int i = 0; i < pos; i++)
			bin[i] = 0;
	}
	else
		binIncrement(pos+1);
}
const string letters = "abcd";
*/

//DMux8Way
int bin[3] = {0,0,0};
void binIncrement(int pos, int length=3)
{
	if(pos >= length)
		return;

	if(bin[pos] == 0)
	{
		bin[pos] = 1;
		for(int i = 0; i < pos; i++)
			bin[i] = 0;
	}
	else
		binIncrement(pos+1);
}
const string letters = "abcdefgh";
const string names[4] = {"notSel0", "notSel1", "notSel2"};





int main() {



	freopen("output.txt", "w", stdout);

	//Mux4Way16
	/*
	int counter = 0;
	for(int i = 0; i < 16; i++)
	{
		cout << "\t" << "Or(a=out" << i << "a, b=out" << i << "b, out=tmp" << counter << ");" << endl;
		cout << "\t" << "Or(a=tmp" << counter++ << ", b=out" << i << "c, out=tmp" << counter << ");" << endl;
		cout << "\t" << "Or(a=tmp" << counter++ << ", b=out" << i << "d, out=out[" << i << "]); " << endl;
	}
	*/


	//Mux8Way16
	/*
	int counter = 0;

	cout << "//not sel\n";
	for(int i = 0; i < 3; i++)
	{
		cout << "\tNot(in=sel[" << i << "], out=notSel" << i << ");\n";
	}

	cout << "\n//select channel\n";
	for(int i = 0; i < 8; i++)
	{
		cout << "\tAnd(a=" << ((bin[0])?("sel["+to_string(0)+"]"):names[0]) << ", b=" << ((bin[1])?("sel["+to_string(1)+"]"):names[1]) << ", out=tmp" << counter << ");\n";
//		cout << "\tAnd(a=tmp" << counter++ << ", b=" << ((bin[2])?("sel["+to_string(2)+"]"):names[2]) << ", out=tmp" << counter << ");\n";
		cout << "\tAnd(a=tmp" << counter++ << ", b=" << ((bin[2])?("sel["+to_string(2)+"]"):names[2]) << ", out=" << numbers[i] << ");\n";

		binIncrement(0);
	}

	for(int i = 0; i < 8; i++)
	{
		cout << "\n//" << letters[i] << " value\n";
		for(int j = 0; j < 16; j++)
		{
			cout << "\tAnd(a=" << letters[i] << "[" << j << "], b=" << numbers[i] << ", out=tmp" << j << letters[i] << ");\n";
		}
	}

	cout << "\n//or\n";
	for(int i = 0; i < 16; i++)
	{
		cout << "\tOr8Way(";
		for(int j = 0; j < 8; j++)
			cout << "in[" << j << "]=tmp" << i << letters[j] << ", ";

		cout << "out=out[" << i << "]);\n";

		/*
		for(int j = 0; j < 7; j++)
		{
			if(j == 0)
				cout << "\tOr(a=a[" << i << "], b=b[" << i << "], out=tmp" << counter << ");\n";
			else if(j < 6)
				cout << "\tOr(a=" << letters[j+1] << "[" << i << "], b=tmp" << counter++ << ", out=tmp" << counter << ");\n";
			else
				cout << "\tOr(a=" << letters[j+1] << "[" << i << "], b=tmp" << counter++ << ", out=out[" << i << "]);\n";
		}*
	}
	 */


	//DMux4Way
	/*
	int counter = 0;

	cout << "//not sel\n";
	for(int i = 0; i < 2; i++)
		cout << "\tNot(in=sel[" << i << "], out=notSel" << i << ");\n";

	cout << "\n//select channel\n";
	for(int i = 0; i < 4; i++){
		cout << "\tAnd(a=" << ((bin[0])?"sel[0]":"notSel0") << ", b=" << ((bin[1])?"sel[1]":"notSel1") << ", out=sel" << i << ");\n";
		binIncrement(0);
	}

	cout << "\n//output\n";
	for(int i = 0; i < 4; i++)
	{
		cout << "\tAnd(a=in, b=sel" << i << ", out=" << letters[i] << ");\n";
	}
	*/



	//DMux8Way
	int counter = 0;

	cout << "//not sel\n";
	for(int i = 0; i < 3; i++)
		cout << "\tNot(in=sel[" << i << "], out=notSel" << i << ");\n";

	cout << "\n//select channel\n";
	for(int i = 0; i < 8; i++)
	{
		cout << "\tAnd(a=" << ((bin[0])?("sel[0]"):names[0]) << ", b=" << ((bin[1])?("sel[1]"):names[1]) << ", out=tmp" << counter << ");\n";
		cout << "\tAnd(a=tmp" << counter++ << ", b=" << ((bin[2])?("sel[2]"):names[2]) << ", out=sel" << i << ");\n";

		binIncrement(0);
	}

	cout << "\n//output\n";
	for(int i = 0; i < 8; i++)
	{
		cout << "\tAnd(a=in, b=sel" << i << ", out=" << letters[i] << ");\n";
	}


}
