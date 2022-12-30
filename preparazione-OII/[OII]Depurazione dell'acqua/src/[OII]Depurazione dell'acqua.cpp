#include <iostream>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;



int tot = 1;
set <int> k;
unordered_map <int, stack<int> > A;




bool impossible = false;

void ricorsiva(int pos)
{
	if(k.find(pos) == k.end() && A[pos].empty()) impossible = true;

	else{
		while(!A[pos].empty() ){
			if(impossible) return;
			else if(k.find(A[pos].top()) != k.end() ) A[pos].pop();
			else{
				tot += 1;
				ricorsiva(A[pos].top());
				A[pos].pop();
			}
		}
		k.insert(pos);
	}
}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	int K, R;
	cin >> K >> R;

	for(int i = 0; i < K; i++){
		int tmp;
		cin >> tmp;
		k.insert(tmp);
	}

	for(int i = 0; i < R; i++){
		int tmp, n;
		cin >> tmp;
		cin >> n;
		for(int j = 0; j < n; j++){
			int tmp1;
			cin >> tmp1;
			A[tmp].push(tmp1);
		}
	}




	if(k.find(1) != k.end()) cout << 0;
	else{
		ricorsiva(1);
		if(impossible) cout << -1;
		else cout << tot;
	}



}
