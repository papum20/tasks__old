#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;




int N;
unordered_map <int, int> C;




set <int> notUsed;
unordered_map <int, vector<int> > cycles;
unordered_map <int, int> cyclic;
set <int> cycle;

void findCycles(int pos, int n)
{
	if(cycle.find(C[pos]) == cycle.end()){
		cycles[n].push_back(C[pos]);
		notUsed.erase(C[n]);
	}
	else{
		cyclic[n] = C[pos];
		if(notUsed.size() != 0){
			int tmp = *notUsed.begin();
			cycles[n+1].push_back(tmp);
			cyclic[n+1] = -1;
			notUsed.erase(tmp);
			cycle.clear();
			cycle.insert(tmp);
			findCycles(tmp, n+1);
		}
	}

}









int main(){

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> C[i];
		notUsed.insert(C[i]);
	}



	cycles[0].push_back(0);
	notUsed.erase(0);
	cyclic[0] = -1;
	findCycles(0,0);



}
