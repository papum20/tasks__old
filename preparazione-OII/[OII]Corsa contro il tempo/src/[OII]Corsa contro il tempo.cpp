#include <iostream>
#include <unordered_map>
using namespace std;




int N = 100000, K = 20;//, mn = 100000000;
int V[100000], C[100000];
unordered_map <int, int> E;	//energies





//void calc(int pos, int E, int t)	//pos,energy,time
//{
//	if(pos == N)
//		mn = min(t, mn);
//
//	else{
//		if(E >= K)
//			calc(pos+1, 0, t);
//		calc(pos+1, E+C[pos], t+V[pos]);
//	}
//
//}




int minimum(int pos){
	if(pos < K)
		return min((E[pos] > 0)? E[pos]:100000000, minimum(pos+1));
	else
		return (E[K]>0)? E[K]:100000000;
}




void calc(int pos)	//pos,energy,time
{
	for(int i = 0; i <= K; i++)
		cout << E[i] << " ";
	cout <<endl;

	int tmp = 0;
	if(E[K] > 0){
		tmp = E[K];
		E[K] += V[pos];
	}



	for(int i = K-C[pos]; i < K; i++)
		if(E[i] > 0){
			E[K] = min((E[K]>0)? E[K]:100000000, E[i]+V[pos]);
			E[i] = 0;
//			cout << i << "	" << E[K]<<endl;
		}

	for(int i = K-C[pos]-1; i >= 0; i--){
		if(E[i] > 0){
			E[i+C[pos]] = E[i]+V[pos];
			E[i] = 0;
//			cout << i << " " << i+C[pos] << "	"<< E[i+C[pos]] << endl;
//			if(pos == N-1)
//				mn = min(mn, E[i+C[pos]]);
		}
	}

	if(tmp > 0)
		E[0] = tmp;

//	if(pos == N-1)
//		mn = min(mn, min((tmp>0)? tmp:100000000, (E[K]>0)? E[K]:100000000) );



	if(pos < N-1)
		calc(pos+1);

}






int main(){

	cin >> N >> K;

	for(int i = 0; i < N; i++)
		cin >> V[i];
	for(int i = 0; i < N; i++)
		cin >> C[i];



	E[(C[0]<K)? C[0]:K] = V[0];
	if(N > 1)
		calc(1);
	for(int i = 0; i <= K; i++)
		cout << E[i] << " ";
	cout<<endl;
	cout << minimum(0);
//	cout << mn;

}
