#include <iostream>
#include <ctime>
using namespace std;


const int length = 5;


int main()
{
	srand(time(NULL));

	//ARRAY RANDOMLY ORDERED
	int random_arr[length];


	//ARRAY OF AVAILABLE INDEXES, NOT USED
	int n_indexes = length;
	int indexes[length];
	for(int i = 0; i < length; i++)
		indexes[i] = i;


	//CODICE
	for(int i = 0; i < length; i++)
	{
		int tmp;
		cin >> tmp;

		int tmp_index = indexes[rand()%n_indexes];
		random_arr[tmp_index] = tmp;

		//TOGLI DA INDEXES GLI INDICI USATI
		bool found = false;
		for(int j = 0; j < n_indexes-1; j++)
		{
			if(found==false && indexes[j]==tmp_index) found=true;
			if(found==true) indexes[j] = indexes[j+1];
		}

		n_indexes--;
	}

	for(int i = 0; i < length; i++)
		cout << random_arr[i] << " ";


}
