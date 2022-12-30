#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;



int N, B;
vector <int> v;
vector < unordered_map<int,int> > dp;






int foo(int pos, int s)	//spesa
{

	if(pos == N){
		if(s >= B) return s;
		else return numeric_limits<int>::max();
	}


	if(dp[pos][s] != 0) return dp[pos][s];

	int res = min(
		foo(pos+1, s+v[pos]),
		foo(pos+1, s)
	);


	dp[pos][s] = res;
	return res;

}







int main(){

	cin >> N >> B;

	v.resize(N);
	dp.resize(N);

	int sum = 0;
	for(int i = 0; i < N; i++){
		cin >> v[i];
		sum += v[i];
	}


	if(sum <= B) cout << sum;
	else cout << foo(0,0);

}















//#include <iostream>
//using namespace std;
//
//
//
//
//int N,B, mn = 10001, mx = 0;
//int G[100];
//
//
//
//void foo(int pos, int tot)
//{
//	if(tot >= B){
//		mn = min(mn, tot);
//		return;
//	}
//	else if(tot < B) mx = max(mx, tot);
//	if(pos == N) return;
//
//	foo(pos+1, tot+G[pos]);
//	foo(pos+1, tot);
//
//}
//
//
//
//
//int main(){
//
//	cin >> N >> B;
//	for(int i = 0; i < N; i++) cin >> G[i];
//
//
//	foo(0, 0);
//	if(mn != 10001) cout << mn;
//	else cout << mx;
//
//
//}
