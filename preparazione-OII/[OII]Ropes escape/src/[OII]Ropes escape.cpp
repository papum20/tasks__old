#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int N;
	cin >> N;
	int T[N], P[N];
	for(int i = 0; i < N; i++) cin >> P[i];
	for(int i = 0; i < N; i++) cin >> T[i];


	unordered_map <int, int> mx;
	int tot = 0;
	for(int i = 0; i < N; i++){
		if(T[i] > mx[P[i]]){
			tot += mx[P[i]];
			mx[P[i]] = T[i];
		}
		else tot += T[i];
	}

	cout << tot;

}
















//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//
//
//
//int N;
//vector <int> P;
//vector <int> T;
//unordered_map <int, int> mx;
//
//
//
//int tot = 0;
//
//void foo(int pos, int level)
//{
////	cout << pos<<" " <<P[pos] <<endl;
////
////	for(int i = -1; i < N; i++) cout << mx[i] << " ";
////	cout << endl;
//
//	if(P[pos] < level)
//	{
//		for(int i = level; i > P[pos]; i--){
//			tot -= mx[i];
//			mx[i] = 0;
//		}
//	}
//
//	mx[P[pos]] = max(mx[P[pos]], T[pos]);
//	tot += T[pos];
//
//
//	if(pos < N) foo(pos+1, P[pos]);
//
//}
//
//
//
//
//
//
//
//int main(){
//
//	cin >> N;
//	P.resize(N);
//	T.resize(N);
//
//	for(int i = 0; i < N; i++) cin >> P[i];
//	for(int i = 0; i < N; i++) cin >> T[i];
//
//	P.push_back(-1);
//	T.push_back(0);
//
//
//
//	foo(0, 0);
//	cout << tot;
//
//
//}
