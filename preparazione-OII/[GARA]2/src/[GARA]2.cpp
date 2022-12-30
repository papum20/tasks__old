#include <iostream>
#include<bits/stdc++.h>
using namespace std;





int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;
		int A[N], F[N];

		struct p{
			int p, f;	//person, followers
		};
		auto byP = [](const p &a, const p &b){
			return a.f > b.f;
		};
		vector <p> P;

//		auto P = multiset <p, decltype(byP)> (byP);

		for(int i = 0; i < N; i++){
			cin >> A[i];
			P.push_back({i, A[i]});
		}
		sort(P.begin(),P.end(),byP);

//		for(auto i:P) cout << i.p<<","<<i.f << " ";
//		cout << endl;

		bool used[N];
		for(int i = 0; i < N; i++) used[i] = false;



		bool one = true;
		for(int i = 0; i < N; i++){
			if(A[i] != 1){
				one = false;
				break;
			}
		}
		if(one){
			cout << "Case #" << t << ": "<<N-1<<" ";
			for(int i = 0; i < N-1; i++) cout << i << " ";
			cout << endl;
		}


		else{

		for(int i = 0; i < N; i++)
		{
			int in = P[i].p;
//			if(i == 1){
//				for(int j = 0; j < N; j++)
//				{
//					if(j == 1) continue;
//
//					int jin = P[j].p;
//					if(A[in] <= 0) break;
//
//					if(!used[jin]){
//						used[jin] = true;
//						A[in]--;
//						F[jin] = in;
//					}
//				}
//				continue;
//			}
//
//			for(int j = i+1; j < N; j++)
//			{
//				int jin = P[j].p;
//				if(A[in] <= 0) break;
//
//				if(!used[jin]){
//					used[jin] = true;
//					A[in]--;
//					F[jin] = in;
//				}
//			}

			for(int j = 0; j < N; j++)
			{
				if(j == i) continue;

				int jin = P[j].p;
				if(A[in] <= 0) break;

				if(!used[jin]){
					used[jin] = true;
					A[in]--;
					F[jin] = in;
				}
			}
		}




		cout << "Case #" << t << ": ";
		for(auto i:F) cout << i << " ";
		cout << endl;

		}


	}

}
