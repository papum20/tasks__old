#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int N, M, boxes = 0;
	cin >> N >> M;
	int P[N], C[N];
	for(int i = 0; i < N; i++){
		cin >> P[i];	}
	for(int i = 0; i < N; i++){
			cin >> C[i];	}


	for(int i = 0; i < N; i++){
		if(M >= P[i]){
			M -= P[i];
			boxes++;
		}
		else{
			M += C[i];
		}
	}

	cout << boxes << " " << M;

}
