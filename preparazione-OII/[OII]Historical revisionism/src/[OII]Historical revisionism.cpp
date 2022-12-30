#include <iostream>
//#include <unordered_map>
//#include <vector>
using namespace std;





int N, mn = 299;
int V[300];

//unordered_map <int, vector <int> > dpMn;	//estremi mn
//unordered_map <int, vector <int> > dpMx;	//estremi mx






void ricorsiva(int pos, int used, bool high, int higher, int lower)	//bool high/low
{
	cout << high << "    " << used << " " << pos << ": "<<V[pos]<<endl;

	if(high)
	{
		int dpMn = -1;
		for(int i = pos+1; i < N; i++){
			if(i-used >= mn) return;
			if(V[i] < higher && V[i] > lower && (V[i] < dpMn || dpMn == -1) ){
				ricorsiva(i, used+1, false, higher, V[i]);
				dpMn = V[i];
			}
		}
	}

	else
	{
		int dpMx = -1;
		for(int i = pos+1; i < N; i++){
			if(i-used >= mn) return;
			if( (V[i] < higher || higher == -1) && V[i] > lower && V[i] > dpMx ){
				ricorsiva(i, used+1, true, V[i], lower);
				dpMx = V[i];
			}
		}
	}


	mn = min(mn, N-used);
	cout << endl;

}









//int dp_mn = -1, dp_mx = -1;

//void ricorsiva(int pos, int last, int tolti, bool high, int start, int lower, int higher)	//bool high/low
//{
//	cout << high << "    " << tolti << " " << pos << ": "<<V[pos]<<endl;
//	if(pos == N){ mn = min(mn, tolti);
//	cout << tolti<<endl;
//	}
//
//	else if(start == pos-1)
//		for(int i = pos; i < N && i-1 < mn; i++){
//			if(V[i] > V[last] && (dp_mx == -1 || V[i] > dp_mx) ){	//
//				ricorsiva(i+1, i, i-1, true, start, V[start], V[i]);
////				dp_mx = V[i];	//
//			}
//			else if(V[i] < V[last] && (dp_mn == -1 || V[i] < dp_mn) ){	//
//				ricorsiva(i+1, i, i-1, false, start, V[i], V[start]);
////				dp_mn = V[i];
//			}
//		}
//
//	else{
//		if(tolti >= mn) return;
//		if(V[pos] > lower && V[pos] < higher) ricorsiva(pos+1, pos, tolti, !high, start, (high)? V[pos]:lower, (!high)? V[pos]:higher);
//		if(tolti >= mn) return;
//		ricorsiva(pos+1, last, tolti+1, high, start, lower, higher);
//	}
//}






int main(){

	std::ios::sync_with_stdio(false);

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);


	cin >> N;
	for(int i = 0; i < N; i++) cin >> V[i];


//	//estremi
//	for(int i = N-2; i >= 0; i--)
//	{
//		bool Mx = false, Mn = false;
//
//		for(int j = i+1; j < N; j++)
//		{
//			if(!Mx && V[j] > V[i]){
//				dpMx[i].push_back(j);
//				for(auto k:dpMx[j]) dpMx[i].push_back(k);
//				Mx = true;
//			}
//			if(!Mn && V[j] < V[i]){
//				dpMn[i].push_back(j);
//				for(auto k:dpMn[j]) dpMn[i].push_back(k);
//				Mn = true;
//			}
//			if(Mx && Mn) break;
//		}
//	}


//	for(int i = 0; i < N; i++){
//		cout << i << ": ";
//		for(auto j:dpMn[i]) cout << V[j] << " ";
//		cout << endl;
//		for(auto j:dpMx[i]) cout << V[j] << " ";
//		cout << endl << endl;
//	}
//	cout << "\n\n\n\n\n\n";



	int dp_mn = -1, dp_mx = -1;
	for(int i = 0; i < N; i++){
		if(V[i] > dp_mx || dp_mx == -1){
			ricorsiva(i, 1, true, V[i], -1);
			dp_mx = V[i];
		}
		cout << endl;
		if(V[i] < dp_mn || dp_mn == -1){
			ricorsiva(i, 1, false, -1, V[i]);
			dp_mn = V[i];
		}
		cout << "\n\n\n";
//		cout << endl << endl;
	}
//	for(int i = 0; i < N; i++){
//		ricorsiva(i+1, i, i, true, i, -1, -1);
//		cout << endl << endl;
//	}

	cout << mn;

}
