#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;






unordered_map <int, long long> h;	//skyscrapers heights
struct grattacielo{
	int i;	//index
	long long b;	//budget
};
auto byBudget = [](const grattacielo &a, const grattacielo &b){
	return a.b < b.b;
};
auto G = multiset <grattacielo, decltype(byBudget)> (byBudget);	//g for skyscrapers (in order of budget from the smallest)
struct limit{
	int i, d;	//index, difference
};
unordered_map <int, vector<limit> > L1;	//limits1
unordered_map <int, vector<limit> > L2;	//limits2



void ricorsiva(int in)	//index
{
	for(auto i:L1[in]){
		if(h[i.i] != 0 && h[in]+i.d < h[i.i]){
			h[i.i] = h[in]+i.d;
			ricorsiva(i.i);
	}	}
}



long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C)
{
	std::ios::sync_with_stdio(false);

	for(int i = 0; i < H.size(); i++)
		G.insert({i,H[i]});
	for(int i = 0; i < M; i++){
		L1[A[i]].push_back({B[i],C[i]});
		L2[B[i]].push_back({A[i],C[i]});
	}


	std::multiset<grattacielo>::iterator it = G.begin();
	h[(*it).i] = (*it).b;
	it++;

	//	for(int i = 0; i < N; i++) ricorsiva(i);


	while(it != G.end())
	{

		h[(*it).i] = (*it).b;

		bool changed = false;
		for(auto i:L2[(*it).i]){
			if(h[i.i] != 0 && h[(*it).i] > h[i.i]+i.d){
				h[(*it).i] = h[i.i]+i.d;
				changed = true;
			}
		}
		if(changed) ricorsiva((*it).i);


		it++;
	}





////	cout<<endl;//
//	long long tot = 0;
//	for(int i = 0; i < N; i++){//
//		tot += h[i];
////		cout<<h[i]<<" ";//
//	}//
////	cout<<endl;//

	long long tot = 0;
	for(int i = 0; i < N; i++) tot += h[i];

	return tot;

}






int main(){

	int N, M;
	cin >> N >> M;
	vector <long long> H;
	vector <int> A;
	vector <int> B;
	vector <int> C;
	for(int i = 0; i < N; i++){
		long long tmp;
		cin >> tmp;
		H.push_back(tmp);
	}
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
	}



	cout << costruisci(N, M, H, A, B, C);

}
