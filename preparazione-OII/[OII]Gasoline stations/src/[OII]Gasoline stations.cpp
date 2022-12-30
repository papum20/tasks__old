#include <iostream>
using namespace std;

int main(){

	uint64_t n, price, km, tot = 0;
	cin >> n;

	uint64_t prices[n];
	for(uint64_t i = 0; i < n; i++){
		cin >> prices[i];
	}


	price = prices[0];
	for(uint64_t i = 0; i < n; i++){
		cin >> km;
		if(prices[i] < price) price = prices[i];
		tot += km*price;
	}

	cout << tot;
}
