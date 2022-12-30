#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;




int N;
long long tot = 0;
struct bridge{
	int t, l;	//to, length
};
unordered_map <int, vector<bridge> > bridges;



int nConnected = 0;
unordered_map <int, set<int> > connected;
set <int> used;

void connect(int pos){	//index
	for(auto j:bridges[pos]){
		if(connected[nConnected].find(j.t) == connected[nConnected].end() ){
			connected[nConnected].insert(j.t);
			used.insert(j.t);
			connect(j.t);
		}
	}
}





//unordered_map <int, long long> mn;
set <int> visited;
long long res = 0;

void path(int pos, long long len)
{
	res = max(res, len);

	for(auto i:bridges[pos]){
		if(visited.find(i.t) == visited.end()/* && (mn[i.t] == 0 || len+i.l > mn[i.t])*/ ){
			visited.insert(i.t);
			path(i.t, len+i.l);
			visited.erase(i.t);
		}
	}
}










int main(){

	cin >> N;

	for(int i = 1; i <= N; i++){
		int to, length;
		cin >> to >> length;
		bridges[i].push_back({to, length});
		bridges[to].push_back({i, length});
	}



	//divide islands in groups

	for(int i = 1; i <= N; i++){
		if(used.find(i) == used.end() ){
			used.insert(i);
			connected[nConnected].insert(i);
			connect(i);
			nConnected++;
		}
	}


	//path

	for(int g = 0; g < nConnected; g++)	//group
	{
//		bool single = false;
//		for(auto i:connected[g]){
//			if(bridges[i].size() == 1){
//				single = true;
//				break;
//			}
//		}
		res = 0;
		for(auto i:connected[g])	//island
		{
//			if(single && bridges[i].size() > 1) continue;
			visited.clear();
	//		mn.clear();
			visited.insert(i);
			path(i, 0);
		}
		cout << res<<endl;
		tot += res;
	}




	for(int g = 0; g < nConnected; g++){
		for(auto i:connected[g]) cout << i << " ";
		cout << endl;
	}




	cout << tot;


}

