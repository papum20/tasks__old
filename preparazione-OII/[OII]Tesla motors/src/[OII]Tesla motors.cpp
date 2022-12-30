#include <iostream>
using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	cin >> n;

	int stazione = n, E_accumulata1 = 0, E_accumulata2 = 0, E_stazione;
	for(int i = 1; i <= n; i++){
		cin >> E_stazione;
		E_accumulata1 += E_stazione - 10;
		if(E_accumulata1 < E_accumulata2){
			E_accumulata2 = E_accumulata1;
			stazione = i;
		}
	}

	cout << ((stazione) %n +1);

}
