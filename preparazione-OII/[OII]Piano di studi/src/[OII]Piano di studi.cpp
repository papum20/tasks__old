#include <iostream>
#include <vector>
#include <set>
using namespace std;




int mn = 0;
set <int> passed;

void ricorsiva(int n, int k, int c[], vector<pair<int,int>> h[], int pos, int credits, int tot)
{
	if(credits >= k)
		mn = min(mn, tot);
	else{
		for(auto i:h[pos]){
			if(passed.find(i.first) == passed.end() ){
				passed.insert(i.first);
				ricorsiva(n,k,c,h, i.first, credits+c[i.first], tot+i.second);
				passed.erase(i.first);
			}
		}
	}

}








int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);



	int K, N;	//crediti necessari, esami
	cin >> K >> N;

	int C[N];	//crediti per esame
	for(int i = 0; i < N; i++)
		cin >> C[i];

	vector<pair<int,int> > H[N];	//hours+
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			int tmp;
			cin >> tmp;
			mn += tmp;
			if(tmp != 0) H[i].push_back({j,tmp});
		}




	for(int i = 0; i < N; i++){
		passed.insert(i);
		ricorsiva(N,K,C,H, i, C[i], 0);
		passed.erase(i);
	}


	cout << mn;

}
