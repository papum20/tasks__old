#include <iostream>
#include <set>
using namespace std;

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n, costo = 0;
	cin >> n;

	multiset<int> numbers;
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		numbers.insert(stoi(tmp));
	}


	while(numbers.size() > 1){
		int somma = 0;
		somma += *numbers.begin();
		numbers.erase(numbers.begin());
		somma += *numbers.begin();
		numbers.erase(numbers.begin());
		numbers.insert(somma);
		costo += somma;
	}

	cout << costo;

}
