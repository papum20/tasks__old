#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int N, win = 0, budget = 0, tmp = 0;
	bool onoff = 0;
	cin >> N;
	int V[N], P[N], C[N];
	for(int i = 0; i < N; i++){
		cin >> V[i];	}
	for(int i = 0; i < N; i++){
		cin >> P[i];	}
	for(int i = 0; i < N; i++){
		cin >> C[i];	}



	for(int i = 0; i < N; i++){
		if(V[i]-P[i] > C[i]){
			win += V[i]-P[i];
			onoff = 1;
			tmp += P[i];
		}
		else{
			win += C[i];
			if(onoff == 1){
				if(tmp>0){
					budget += tmp;
					tmp = -C[i];	}
				else{
					tmp -= C[i];	}
				onoff = 0;
			}
			else{
				tmp -= C[i];
			}
	}	}
	budget += (tmp > 0)? tmp:0;



	cout << win << " " << budget;
}
