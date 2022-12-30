#include <iostream>
using namespace std;


bool in(string elem, string arr[], int len){
	for(int i = 0; i < len; i++){
		if(arr[i] == elem){
			return 1;
		}
	}
	return 0;
}


int main(){
	int K, ind_res = 0;
	cin >> K;
	int res[K];
	for(int a = 0; a < K; a++){
		int N, ind_t = 0;
		cin >> N;
		string T[2][N];
		string tot[N];
		for(int b = 0; b < N; b++){
			cin >> T[0][b];
			getline(cin, T[1][b]);
//			cout << T[1][b];
			if(!(in(T[1][b], tot, N)) ){
				tot[ind_t++] = T[1][b];
//				cout << tot[ind_t-1];
			}
		}
		res[ind_res++] = ind_t;
	}


	cout << "\n";
	for(int i = 0; i < K; i++){
		cout << "Case #" << i+1 << ": " << res[i] << "\n";
	}
}
