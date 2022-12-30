#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;






int N;
struct frend{
	int f;	//friend
	bool u;	//used
};
unordered_map <int, vector<frend> > F;	//friends
unordered_map <int, int> P;	//key:n, value: l

unordered_map <int, int> done;
//int tot = 0;
set <int> chain;




void ricorsiva(int p)	//p0 = last, p = current
{

	cout << "[ " << p << " ]" << done[N] << "\n";
	for(int i = 0; i <= N; i++) cout << done[p] <<endl;
	cout <<endl;


	if(done[p] >= P[p]){
		cout << "YES\n";
//		tot++;
	}


	else{
		for(int k = 0; k < F[p].size(); k++)
		{
			int i = F[p][k].f;

			cout << done[p] << "/" << P[p] << ";  F: " << i << ": " << done[i] << ",->";

			if(F[p][k].u == true || chain.find(i) != chain.end()){
				cout<<" PASS ";
				continue;
			}


			if(done[i] >= P[i]){
				done[p]++;
				F[p][k] = {i,true};
			}

			else{
				chain.insert(i);
				ricorsiva(i);
				chain.erase(i);
				if(done[i] >= P[i]){
					done[p]++;
					F[p][k] = {i,true};
				}
			}

			cout << "," << p << "->" << done[i] << "\n";


			if(done[p] >= P[p]){
				cout << "OLE\n";
//				tot++;
				return;
			}
		}

	}



}







int main(){

	cin >> N;


	for(int n = 0; n < N; n++){
		int m, l;
		cin >> m >> l;
		P[n] = l;
//		if(l == 0){
//			tot++;
//			chain.insert(n);
//		}
		for(int j = 0; j < m; j++){
			int tmp;
			cin >> tmp;
			F[n].push_back({tmp,false});
		}
	}

	for(int i = 0; i < N; i++) F[N].push_back({i,false});
	P[N] = N;



	ricorsiva(N);
//	if(done[N] >= N) tot--;
//	cout << tot;
	cout << done[N];


}
