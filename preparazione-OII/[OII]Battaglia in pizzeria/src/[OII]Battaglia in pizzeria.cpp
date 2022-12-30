#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;





//fare due tabelle, una per persona, ognuna grande N**2, come i modi di scegliere start e end, e riempirla a partire dai piu piccoli


struct piece{
	int s, e;	//start, end
};



int contentezza(int N, int V[])
{
	int mx = 0;
//	vector <piece> piecesFirst;
	vector <piece> pieces;
//	vector <int> cFirst[2];
	vector <int> c[2];


	int turn = N%2;
	int tolti = 0;


	if(N == 1) return V[0];


	for(int l = 2; l <= N; l++)	//length
	{
		cout << "L"<<l<<endl;
		bool maximum = (l%2 == turn);

//		if(l == 1){
//			for(int i = 0; i < N; i++){
//				cFirst[l%2].push_back(V[i]);
//				piecesFirst.push_back({i,i+1});
////				if(maximum) mx = max(mx, V[i]);
////				cout << mx<<endl;
//			}
//		}

		if(l == 2){
			for(int i = 0; i < N; i++){
				cout << i <<endl;
				if( (i > 0 && V[i-1] >= V[i]) || (i+1 < N && V[i+1] >= V[i]) )
				{
					c[(l+1)%2].push_back(V[i]);

					cout << i+1<<">="<<N<<" "<<i<<">"<<"0 "<<V[i-1]<<">="<<V[i+1]<<endl;
					if(i+1 >= N || (i > 0 && V[i-1] >= V[i+1]) )
					{
						pieces.push_back({i-1,i+1});
						c[l%2].push_back(V[i-1]);
					}
					else{
						pieces.push_back({i,i+2});
						c[l%2].push_back(V[i+1]);
					}

					if(maximum) mx = max(mx, c[l%2][i-tolti]);
					cout << l<<": "<<mx<<endl;
				}
				else tolti++;
			}
		}

		else{
			for(auto i:pieces) cout << i.s<<i.e<<" ";
			cout << endl;
			for(auto i:c[0]) cout << i << " ";
			cout << endl;
			for(auto i:c[1]) cout << i << " ";
			cout << endl;


			for(int i = 0; i < N-tolti; i++)
			{
				cout << i<<endl;
				if(pieces[i].e >= N || (pieces[i].s > 0 && V[pieces[i].s-1] >= V[pieces[i].e]) ){
					c[l%2][i] += V[pieces[i].s-1];
					pieces[i].s--;
				}
				else{
					c[l%2][i] += V[pieces[i].e];
					pieces[i].e++;
				}

				if(maximum) mx = max(mx, c[l%2][i]);
				cout << l<<": "<<mx<<endl;
			}
		}


	}


	return mx;
}








int main(){

	int N;
	cin >> N;
	int V[N];
	for(int i = 0; i < N; i++) cin >> V[i];

	cout << contentezza(N, V);

}
