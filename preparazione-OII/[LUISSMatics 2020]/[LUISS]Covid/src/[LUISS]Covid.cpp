#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	int res[T];

	for(int i = 0; i < T; i++){
		int N, Z;
		int max[2] = {0,0};
		float D;
		cin >> N;
		float sani[2][N];
		for(int k = 0; k < N; k++){
			cin >> sani[0][k] >> sani[1][k];
		}
		cin >> Z;
		float malati[3][Z];
		for(int k = 0; k < Z; k++){
			cin >> malati[0][k] >> malati[1][k] >> malati[2][k];
		}
		cin >> D;


		for(int a = 0; a < N; a++){
			int tmp = 0;
			for(int b = 0; b < Z; b++){
				if( sqrt( pow(sani[0][a]-malati[0][b],2) + pow(sani[1][a]-malati[1][b],2) ) <= D ){
					tmp += malati[2][b];
				}
			}
			if(tmp > max[1]){
				max[1] = tmp;
				max[0] = a;
			}
		}

		res[i] = max[0]+1;

	}



	cout << "\n";
	for(int i = 0; i < T; i++){
		cout << "Case #" << i+1 << ": " << res[i] << "\n";
	}

}
