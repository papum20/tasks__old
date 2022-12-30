#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int N, M;
int mx = 0;
vector <int> V;
vector <int> G;


unordered_map <int, set<int> > d;


void foo(int v, int g, int tot)
{
	cout << "B"<<v <<" " <<g<<" "<<tot<<endl;
	if(v == N) mx = max(mx, tot);

	else if(g >= M) foo(N, g, tot + N - v);

	else{
		if(G[g] > V[v]) foo(v+1, g+1, tot+2);

		else{
			int tmp = -1;
			for(int i = g; i < M; i++){
//				cout << v << " " << i << " " << tot << endl;
				if(G[i] > V[v]){
//					cout << "A"<< v << " " << i << " " << tot << endl;
					tmp = i;
					foo(v+1, i+1, tot+2);
					break;
				}
			}

			int jj;
			bool b = true;
			if(tmp != -1){
				for(int j = v+1; j < N; j++){
					cout << j << ": "<<endl;
					for(auto i:d[j]){
						cout << i << " ";
						if(i > g){
							cout << "C";
							std::set<int>::iterator it = d[j].find(i);
							it++;
							if(*it < tmp){
								cout << "D";
								b = false;
								jj = j;
								break;
							}
						}
					}
					if(!b) break;
				}
			}

			else{
				if(tmp == -1) foo(v+1, g, tot+1);
				else if(b == false) foo(jj, g, tot+jj-v);
			}

		}

	}

}







int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{

		cin >> N >> M;

		mx = 0;
		V.clear();
		G.clear();

		for(int i = 0; i < N; i++){
			int tmp;
			cin >> tmp;
			V.push_back(tmp);
		}
		for(int i = 0; i < M; i++){
			int tmp;
			cin >> tmp;
			G.push_back(tmp);
			for(int j = 0; j < N; j++)
				if(tmp > V[j]) d[j].insert(i);
		}





		foo(0, 0, 0);


		cout << "Case #" << t << ": " << mx << endl;


	}

}




//for(int t = 1; t <= T; t++)
//	{
//		int N, M;
//		cin >> N >> M;
//
//		int tot = 0;
//
//		multiset <int> V;
////		auto foo = [](const int &a, const int &b){
////			return a < b;
////		};
////		auto G = multiset <int, decltype(foo)> (foo);
//		vector <int> G;
//
//		for(int i = 0; i < N; i++){
//			int tmp;
//			cin >> tmp;
//			V.insert(tmp);
//		}
//		for(int i = 0; i < M; i++){
//			int tmp;
//			cin >> tmp;
//			G.push_back(tmp);
//		}
//
//		auto foo = [](const int &a, const int &b){
//			return a < b;
//		};
//		sort(G.begin(), G.end(), foo);
//
//
//
////		int ind = 0;
//		for(auto i:V)
//		{
//			if(G.size() == 0) tot++;
//
//			else{
////				std::multiset <int>::iterator it = G.begin();
////
////				bool done = false;
////				while(it != G.end()){
////					if(*it > i){
////						cout << i << " " << *it << endl;
////						tot += 2;
////						done = true;
////						break;
////					}
////					else it++;
////				}
////				if(done) G.erase(*it);
////				else tot++;
//
//				int ind = 0;
//
//				bool done = false;
//				while(ind < G.size()){
//					if(G[ind] > i){
//						cout << i << " " << G[ind] << endl;
//						tot += 2;
//						done = true;
//						break;
//					}
//					else ind++;
//				}
//				if(done) G.erase(G.begin()+ind);
//				else tot++;
//			}
//		}
//
//
//
//		cout << "Case #" << t << ": " << tot << endl;
//
//
//	}
