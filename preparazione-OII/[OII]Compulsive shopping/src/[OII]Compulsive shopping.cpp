#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;





int N, E;
//int mx = 0;
vector <int> P;
struct s{
	int b, nb;	//bought, not-bought
};
//vector <unordered_map <int, s> > dp;
unordered_map <int, s> dp;







int foo(int pos, int m, bool bought)	//money
{
	if(pos == N) return m;


//	if(m <= mx) return m;

	if(bought == true){
		if(m < dp[pos].b) return 0;
	}
	else{
		if(m < dp[pos].nb) return 0;
	}


	int result;

	if(P[pos] > m) result = foo(pos+1, m, false);
	else{
		if(bought == false) result = foo(pos+1, m-P[pos], true);
		else result = max(
			foo(pos+1, m, false),
			foo(pos+1, m-P[pos], true)
		);
		result = max(result, foo(pos+1, P[pos]-1, false) );
	}



	if(bought == true) dp[m].b = result;
	else dp[m].nb = result;

	return result;

}









int main(){


	cin >> N >> E;
	P.resize(N);
//	dp.resize(N);

	for(int i = 0; i < N; i++) cin >> P[i];



//	for(int i = E; i >= 0; i--){
//		if(i <= mx) break;
//		mx = max(mx, foo(0, i, false) );
//	}


//	cout << mx;



	cout << foo(0,E,false);

}
