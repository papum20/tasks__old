#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;




int N, K;
unordered_map <int, int> H;
set <int> visited;


int police(int pos, int len){
	if(pos == K) return len;
	else if(visited.find(H[pos]) != visited.end() ) return -1;
	else{
		visited.insert(H[pos]);
		return police(H[pos], len+1);
	}
}




int main(){

	cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> H[i];

	cout << police(1, 0);

}
