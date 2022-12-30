#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int N, A, B;





//void foo(int l)	//level
//{
//	for(auto i:dist[l-1])
//	{
//		for(auto j:b[i])
//		{
//			if(used.find(j) == used.end()){
//				used.insert(j);
//				dist[l].insert(j);
//			}
//		}
//	}
//
//}





int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		cin >> N >> A >> B;


		set <int> a;
		unordered_map <int, set<int> > b;


		unordered_map <int, set<int> > dist;
		set <int> used;



		for(int i = 0; i < A; i++){
			int tmp;
			cin >> tmp;
			a.insert(tmp);
			dist[0].insert(tmp);
			used.insert(tmp);
		}

		for(int i = 0; i < B; i++){
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			b[tmp1].insert(tmp2);
			b[tmp2].insert(tmp1);
		}



//		for(auto i:a) cout << i;
//		cout << endl;
//		for(int i = 0; i < N; i++){
//			for(auto j:b[i])cout << j;
//			cout << endl;
//		}
//		for(auto i:used) cout << i;
//		cout << endl;
//
//			for(auto j:dist[0])cout << j;
//			cout << endl;




		int l = 1;

		while(used.size() < N){
//			cout << l << " " <<used.size() << endl;
			for(auto i:dist[l-1])
			{
				for(auto j:b[i])
				{
//					cout << j<<" "<<(used.find(j)==used.end())<<" ";
					if(used.find(j) == used.end()){
//						cout << "A"<< j << " ";
						used.insert(j);
						dist[l].insert(j);
					}

				}
//				cout << endl;
			}

			l++;
		}

//cout << endl<<endl;
//		for(int i = 0; i < l; i++){
//			for(auto j:dist[i]) cout << j;
//			cout << endl;
//		}



		cout << "Case #" << t << ": " << *(dist[l-1].begin()) << " " << l << endl;


	}

}
