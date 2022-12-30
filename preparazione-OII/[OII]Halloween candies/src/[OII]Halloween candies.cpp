#include <iostream>
using namespace std;






int main(){

	int N;
	uint64_t M;
	cin >> N >> M;


	uint64_t takenCandies[N];

	cin >> takenCandies[0];
	for(int i = 1; i < N; i++)
	{
		uint64_t tmp;
		cin >> tmp;
		takenCandies[i] = takenCandies[i-1]+tmp;
	}


	M %= takenCandies[N-1];

	if(M == 0) cout << N-1;
	else{
		for(int i = 0; i < N; i++){
			if(takenCandies[i] >= M){
				cout << i;
				break;
			}
		}
	}

}
