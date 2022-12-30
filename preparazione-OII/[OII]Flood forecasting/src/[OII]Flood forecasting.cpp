#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;




int N, M, res;
struct road{
	int fro, to, r;	//from, to, rain
};
set <int> visitable;
auto byRain = [](const road &a, const road &b){
	return a.r > b.r;
};
auto roads = multiset <road, decltype(byRain)> (byRain);
unordered_map <int, vector <int> > subC;	//sub-connected




void sub(int pos){
		for(auto i:subC[pos]){
			if(visitable.find(i) == visitable.end()){
				visitable.insert(i);
				sub(i);
			}
	}
}









int main(){

	cin >> N >> M;


	for(int i = 0; i < M; i++){
		int a, b, r;
		cin >> a >> b >> r;
		roads.insert({a,b,r});
	}



	std::multiset <road>::iterator it = roads.begin();
	visitable.insert((*it).fro);
	visitable.insert((*it).to);
	res = (*it).r;
	it++;


	while(visitable.size() < N)
	{
		cout << visitable.size() << " " << (*it).r << endl;
		for(auto i:visitable) cout << i;
		cout << endl;
		int f = (*it).fro, t = (*it).to;
		bool bf = (visitable.find(f) != visitable.end()), bt = (visitable.find(t) != visitable.end());
		if((bf && !bt) || (!bf && bt)){
			visitable.insert((bf)?t:f);
			sub((bf)?t:f);
		}
		else if(!bf && !bt){
			subC[f].push_back(t);
			subC[t].push_back(f);
		}

		res = (*it).r;
		it++;
	}





	cout << res;

}








//#include <iostream>
//#include <queue>
//#include <set>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//
//
//
//
//int N, M, res;
//struct road{
//	int to, r;	//destination, rain max
//};
//set <int> visitable;
//unordered_map <int, vector <road> > roads;
//priority_queue <int> R;	//rain
//
//
//
//
//void reach(int rain, int pos){
//	for(auto j:roads[pos]){
//		if(j.r >= rain && visitable.find(j.to) == visitable.end()){
//			visitable.insert(j.to);
//			reach(rain,j.to);
//		}
//	}
//}
//
//
//
//
//
//
//
//
//int main(){
//
//	cin >> N >> M;
//
//
//	for(int i = 0; i < M; i++){
//		int a, b, r;
//		cin >> a >> b >> r;
//		roads[a].push_back({b,r});
//		roads[b].push_back({a,r});
//		R.push(r);
//
//	}
//
//
//
//
//	visitable.insert(0);
//	int last = -1;
//
//	while(!R.empty())
//	{
//		if(R.top() == last){
//			R.pop();
//			continue;
//		}
//
//		for(auto i:visitable){
//			reach(R.top(),i);
//			if(visitable.size() == N) break;
//		}
//
//		if(visitable.size() == N){
//			res = R.top();
//			break;
//		}
//		last = R.top();
//		R.pop();
//	}
//
//
//
//
//
//	cout << res;
//
//}
