#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;


struct path{
	int t, l;	//to, length
};

int N, M, C, K, res = -1;
set <int> a;	//air
unordered_map <int, vector<path> > paths;
//unordered_map <int, int> mn;
set <int> passed;






void foo(int pos, int len, int air)
{
	if(pos == C){
		if(res == -1) res = len;
		else res = min(res, len);
	}

	for(auto i:paths[pos])
	{
		if(res != -1 && len >= res) break;
		if(i.l <= air && /*(mn[pos] == 0 || len + i.l < mn[pos]) &&*/ passed.find(i.t) == passed.end() ){
			passed.insert(i.t);
//			mn[pos] = len+i.l;
			if(a.find(i.t) != a.end() ) foo(i.t, len+i.l, 20);
			else foo(i.t, len+i.l, air-i.l);
			passed.erase(i.t);
		}
	}
}







int main(){

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

	cin >> N >> M >> C >> K;

	for(int k = 0; k < K; k++){
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}

	for(int m = 0; m < M; m++){
		int a, b, l;
		cin >> a >> b >> l;
		paths[a].push_back({b,l});
		paths[b].push_back({a,l});
	}

	passed.insert(1);
	a.insert(1);



	foo(1, 0, 20);
	cout << res;


}
