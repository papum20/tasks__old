#include <iostream>
using namespace std;



/*
int solve(int N, int* S){

	int


}
*/




int solve(int N, int* S){

	int tot = 0;

	for(int l = 2; l <= N/2; l++)
	{
		if(N%l != 0)
			continue;

		for(int start = 0; start < N/l; start++){

			bool correct = true;
			int color = S[start];
			for(int i = start + N/l; i < N; i+= N/l){
				if(S[i] != color){
					correct = false;
					break;
				}
			}

			if(correct)
				tot++;
		}

	}



	return tot;

}




int main(){


	int N;
	cin >> N;
	int S[N];
	for(int i = 0; i < N; i++){
		cin >> S[i];
	}


	cout << solve(N,S);

}
