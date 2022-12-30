#include <iostream>
//#include <stack>
//#include <unordered_map>
//#include <vector>
#include <set>
using namespace std;



struct chain{	//growing chain
	int len, last;
};



int main()
{

	int N;
//	unsigned int mx = 0;
	cin >> N;

	int S[N], C[N];
	for(int i = 0; i < N; i++)
		cin >> S[i];
	for(int i = 0; i < N; i++)
		cin >> C[i];




	auto byLen = [](const chain &a, const chain &b){
		return a.len > b.len;
	};
	auto dp = multiset <chain, decltype(byLen)> (byLen);
	dp.insert({1,0});


	for(int i = 1; i < N; i++)	//for each S
	{
		for(auto a:dp)
			cout<<a.len<< " " << a.last << " / ";
		cout << endl;
		cout<<"i"<<i<<" ";
		bool done = false;
		for(auto j:dp)	//for each chain in dp
		{
			int i0 = j.last;
			if(S[i] > S[i0] || S[i] == C[S[i0]-1]){
				cout<<j.len<<" "<<j.last<<endl;
				done = true;
				dp.insert({j.len+1, i});
				break;
			}
		}

		if(!done)
			dp.insert({1,i});
	}

	cout << (*dp.begin()).len;



}




//
//	unordered_map <int, stack<int> > dp;
//	int ind = 1;
//	dp[0].push(0);
//
//	for(int i = 1; i < N; i++)
//	{
//		for(int j = 0; j < ind; j++)
//		{
//			int i0 = dp[j].top();
//			if(S[i] > S[i0] || S[i] == C[i0])
//				dp[j].push(i);
//		}
//
//		dp[ind++].push(i);
//	}
//
//
//
//	for(int i = 0; i < ind; i++)
////	    unsigned int tmp = dp[i].size();
////		mx = (tmp > mx)? tmp:mx;
//		mx = max(mx, dp[i].size());
//
//	cout << mx;
//
//
////	cout<<endl;
////	for(int i = 0; i < ind; i++){
////		while(!dp[i].empty()){
////			cout<<dp[i].top();
////			dp[i].pop();
////		}
////		cout<<endl;
////	}
















//#include <iostream>
//using namespace std;
//
//
//
//int N, mx = 0;
//int S[100000], C[100000];
//
//
//
//
//
//bool deleted[100000];
//
//int index(int pos, bool forwards){	//if(!forwards) backwards
//	if(pos == -1) return -1;
//	else if(pos == N) return N;
//	else if(deleted[pos] == false) return pos;
//	else return index((forwards)? (pos+1):(pos-1), forwards);
//}
//
//
//
//
//
//void foo(int pos = 1, int len = 1)
//{
//
////	for(int i = 0; i < N; i++)
////		cout<<deleted[i];
////	cout<<endl;
//
////	if(pos == 0)
////		return;
//
//	if(pos == N){
////		for(int i = 0; i < N; i++)
////			cout<<deleted[i];
////		cout<<endl;
//		mx = max(mx, len);
//	}
//
//	else{
//		int last = index(pos-1, false);
//
//		if(last == -1 || (S[pos] > S[pos-1] || S[pos] == C[pos-1]) )
//			foo(index(pos+1, true), len+1);
//		else{
//			if(last > -1){
//				deleted[last] = true;
//				foo(index(last-1, false), len-2);
//				deleted[last] = false;
//			}
//			deleted[pos] = true;
//			foo((last == -1)? index(pos+1, true):last, len-1);
//			deleted[pos] = false;
//		}
//	}
//
//}
//
//
//
//
//int main(){
//
//	cin >> N;
//
//	for(int i = 0; i < N; i++)
//		cin >> S[i];
//	for(int i = 0; i < N; i++)
//		cin >> C[i];
//
//
//	for(int i = 0; i < N; i++)
//		deleted[i] = false;
//
//	foo();
//	cout << mx;
//
//}
