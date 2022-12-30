#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;



int N, S, C;//, tot = 1;
unordered_map <int, int> str;
set <int> res;
struct coord{
	int c, s;	//cell, state
};
unordered_map <int, unordered_map<int, coord> > table;
//coord table[2000000][2000000];








//auto byCell = [](const coord &a, const coord &b){
//	return a.c <= b.c;
//};
unordered_map <int, set <int> > entscheidungs;
unordered_map <int, set <int> > not_entscheidungs;
unordered_map <int, set <int> > passed;

void calc(int pos, int state, int start)
{
	cout<<pos;
	if(pos == N)
		return;
	else if(pos == 0){
		entscheidungs[state].insert(0);
		res.insert(0);
	}


	else if(entscheidungs[state].find(pos) == entscheidungs[state].end() && not_entscheidungs[state].find(pos) == not_entscheidungs[state].end() )
	{
		int pos2 = pos + (table[state][str[pos]]).c, state2 = (table[state][str[pos]]).s;

		if(entscheidungs[state2].find(pos2) != entscheidungs[state2].end() ){
			entscheidungs[state].insert(pos);
			res.insert(pos);
//			cout<<endl<<"entDUE "<<pos <<endl;
			return;
		}
		else if(not_entscheidungs[state2].find(pos2) != not_entscheidungs[state2].end() ){
			not_entscheidungs[state].insert(pos);
//			cout<<endl<<"notentDUE "<<pos <<endl;
			return;
		}
		else if(passed[state].find(pos) != passed[state].end() ){
			not_entscheidungs[state].insert(pos);
//			cout<<endl<<"pasDUE "<<pos <<endl;
			return;
		}

		else{
			passed[state].insert(pos);
//			cout<<endl;
//			for(auto i:passed)
//				cout<<i.c<<i.s<<" ";
//			cout <<endl;
//			cout<<"POS "<<(passed[state].find(pos) != passed.end())<<endl;
			calc(pos2, state2, (start == -1)? pos:start);
			passed[state].erase(pos);
//			cout << endl << pos << "  " << passed.size() << endl;


			if(entscheidungs[state2].find(pos2) != entscheidungs[state2].end() ){
				entscheidungs[state].insert(pos);
				res.insert(pos);
//				cout<<endl<<"ent2DUE "<<pos <<endl;
			}
			else if(not_entscheidungs[state2].find(pos2) != not_entscheidungs[state2].end() ){
				not_entscheidungs[state].insert(pos);
//				cout<<endl<<"notent2DUE "<<pos <<endl;
			}
		}


	}

	if(start == -1) calc(pos+1, 0, -1);

}







//auto byCell = [](const coord &a, const coord &b){
//	return a.c <= b.c;
//};
//auto entscheidungs = multiset <coord, decltype(byCell)> (byCell);
//auto not_entscheidungs = multiset <coord, decltype(byCell)> (byCell);
//auto passed = multiset <coord, decltype(byCell)> (byCell);
//
//void calc(int pos, int state)
//{
//	cout<<pos;
//	if(pos == N)
//		return;
//	else if(pos == 0){
//		entscheidungs.insert({0,0});
////		passed.clear();
//	}
//
//
//	else if(entscheidungs.find({pos,state}) == entscheidungs.end() && not_entscheidungs.find({pos,state}) == not_entscheidungs.end() )
//	{
//		int pos2 = pos + (table[state][str[pos]]).c, state2 = (table[state][str[pos]]).s;
//
//		if(entscheidungs.find({pos2,state2}) != entscheidungs.end() ){
//			entscheidungs.insert({pos,state});
////			passed.clear();
////			tot++;
//			return;
//		}
//		else if(not_entscheidungs.find({pos2,state2}) != not_entscheidungs.end() ){
//			not_entscheidungs.insert({pos,state});
////			passed.clear();
//			return;
//		}
//		else if(passed.find({pos,state}) != passed.end() ){
//			not_entscheidungs.insert({pos,state});
////			passed.clear();
//			return;
//		}
//
//		else{
//			passed.insert({pos,state});
////			passed.insert(pos2);
//			calc(pos2, state2);
//			passed.erase({pos,state});
//
//			if(entscheidungs.find({pos2,state2}) != entscheidungs.end() ){
//				entscheidungs.insert({pos,state});
////				tot++;
//			}
//			else if(not_entscheidungs.find({pos2,state2}) != not_entscheidungs.end() )
//				not_entscheidungs.insert({pos,state});
//		}
//
//
//	}
//
//	if(passed.size() == 0) calc(pos+1, state);
//
//}







//set <int> entscheidungs;
//set <int> not_entscheidungs;
//set <int> passed;
//
//void calc(int pos, int state)
//{
////	cout<<pos;
//	if(pos == N)
//		return;
//	else if(pos == 0){
//		entscheidungs.insert(0);
////		passed.clear();
//	}
//
//
//	else if(entscheidungs.find(pos) == entscheidungs.end() && not_entscheidungs.find(pos) == not_entscheidungs.end() )
//	{
//		int pos2 = pos + (table[state][str[pos]]).c, state2 = (table[state][str[pos]]).s;
//
//		if(state2 == 0 && entscheidungs.find(pos2) != entscheidungs.end() ){
//			entscheidungs.insert(pos);
////			passed.clear();
//			tot++;
//			return;
//		}
//		else if(state2 == 0 && not_entscheidungs.find(pos2) != not_entscheidungs.end() ){
//			not_entscheidungs.insert(pos);
////			passed.clear();
//			return;
//		}
//		else if(passed.find(pos) != passed.end() ){
//			not_entscheidungs.insert(pos);
////			passed.clear();
//			return;
//		}
//
//		else{
//			passed.insert(pos);
////			passed.insert(pos2);
//			calc(pos2, state2);
//			passed.erase(pos);
//
//			if(state2 == 0 && entscheidungs.find(pos2) != entscheidungs.end() ){
//				entscheidungs.insert(pos);
//				tot++;
//			}
//			else if(state2 == 0 && not_entscheidungs.find(pos2) != not_entscheidungs.end() )
//				not_entscheidungs.insert(pos);
//		}
//
//
//	}
//
//	if(passed.size() == 0) calc(pos+1, state);
//	else if(entscheidungs.find(pos) != entscheidungs.end() ){
//		entscheidungs.insert(pos);
//		tot++;
//	}
//	else if(not_entscheidungs.find(pos) != not_entscheidungs.end() )
//		not_entscheidungs.insert(pos);
//	else{
//		if(passed.find(pos) != passed.end() ){
//			not_entscheidungs.insert(pos);
//		}
//		passed.insert(pos);
//		calc();
//		calc(pos+1);
//	}








int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> N >> S >> C;


	for(int i = 0; i < S*C; i++){
		int s1, c1, s2, c2;
		cin >> s1 >> c1 >> s2 >> c2;
		table[s1][c1] = {c2,s2};
	}
	for(int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;
		str[i] = tmp;
	}


	calc(0,0,-1);





	cout << res.size() << "\n";
	for(auto i:res){
		cout << i << "\n";
	}

}
