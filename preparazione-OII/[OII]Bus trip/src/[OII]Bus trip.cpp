#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;




int N, S, E, M;
int tot = 0;
struct bus{
	int c1, t0, t1;	//city1,time0/1
};
unordered_map <int, vector<bus> > buses;
unordered_map <int, int> mn;


void ricorsiva(int pos, int time)
{
	if(pos == E){
		if(tot != 0) tot = min(tot, time);
		else tot = time;
	}

	else if(tot != 0 && time >= tot) return;

	else{
		for(auto i:buses[pos])
			if( (mn[i.c1] == 0 || i.t1 < mn[i.c1]) && i.t0 >= time){
				mn[i.c1] = i.t1;
				ricorsiva(i.c1,i.t1);
			}
	}
}





int main(){

	cin >> N >> S >> E >> M;

	for(int i = 0; i < M; i++){
		int c0, t0, c1, t1;
		cin >> c0 >> t0 >> c1 >> t1;
		buses[c0].push_back({c1,t0,t1});
	}


	mn[S] = 0;
	ricorsiva(S,0);
	if(tot != 0) cout << tot;
	else cout << "IMPOSSIBLE";

}
