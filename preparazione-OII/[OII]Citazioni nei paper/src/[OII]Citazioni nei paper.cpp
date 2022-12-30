//#include <iostream>
//#include <unordered_map>
//#include <set>
//#include <vector>
//using namespace std;
//
//
//
//
//
//int tot = 0;
//unordered_map <int, set<int> > chains;
//unordered_map <int, vector<int> > quoted;
//
//
//set <int> tmp;
//
//void ricorsiva(int pos, int N, int M)
//{
//	for(auto i:quoted[pos]){
//		if(tmp.find(i) == tmp.end() ){
//			for(auto j:tmp) chains[j].insert(i);
//			tmp.insert(i);
//			ricorsiva(i, N,M);
//			tmp.erase(i);
//		}
//	}
//}
//
//
//
//
//
//int paper(int N, int M, int A[], int B[]){
//
//	for(int i = 0; i < M; i++) quoted[A[i]].push_back(B[i]);
//
//	for(int i = 1; i <= N; i++){
//		tmp.insert(i);
//		ricorsiva(i, N,M,A,B);
//		tmp.erase(i);
//	}
//
//	return tot;
//}
//
//
//
//
//
//
//int main(){
//
//	int N, M;
//	cin >> N >> M;
//
//	int A[M], B[M];
//	for(int i = 0; i < M; i++) cin >> A[i] >> B[i];
//
//
//	cout << paper(N, M, A, B);
//
//}
//
//
