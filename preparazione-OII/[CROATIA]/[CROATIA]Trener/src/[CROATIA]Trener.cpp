#include <iostream>
using namespace std;

bool arr_cmp(int arr1[], int arr2[], int len){	//compare arrays
	for(int l = 0; l < len; l++){
		if(arr1[l] != arr2[l]){
			return 0;	}	}
	return 1;
}


bool check(string teamm[], int n){
	for(int t = 0; t < n-1; t++){
		string a = teamm[t+1], b = teamm[t];
		if( !(b == a.substr(0,t+1) || b == a.substr(1,t+1)) ){
			return 0;
	}	}
	return 1;
}




int main() {
	int N, K, count = 0;
	cin >> N >> K;
	string names[N][K];
	for(int a = 0; a < N; a++){
		for(int b = 0; b < K; b++){
			cin >> names[a][b];
		}
	}





	int ind = 0;
	int map[N], comparator[N];
	for(int n = 0; n < N; n++){
		map[n] = 0;
		comparator[n] = K-1;
	}
	string team[N];
	for(int n = 0; n < N; n++){
		team[n] = names[n][map[n]];
	}
	if(check(team, N)){
		count++;
	}


	while(!(arr_cmp(map, comparator, N)) ){
		for(int n = 0; n < N; n++){
			team[n] = names[n][map[n]];
		}
		if(check(team, N)){
			count++;
		}
		while(true){
		if(map[ind] < K-1){
			map[ind]++;
			for(int i = 0; i < ind; i++){
				map[i] = 0;	}
			ind = 0;
			break;
		}
		ind++;
		}

	}




	cout <<"\n\n"<< count;

}
