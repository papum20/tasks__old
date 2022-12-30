#include <iostream>
#include <set>
using namespace std;


int N = 100000, K = 100000;
struct athlet{
	int n, v;	//value, number
};
auto mostV = [](athlet a, athlet b){
	return a.v > b.v;
};
auto athlets = multiset <athlet, decltype(mostV)> (mostV);




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);



	cin >> N >> K;

	for(int i = 0; i < N; i++){
		int f, p;
		cin >> f >> p;
		athlets.insert({i+1, f - p*3/2});
	}


	std::multiset<athlet>::iterator it = athlets.begin();
	for(int i = 0; i < K; i++){
		cout << (*it).n << "\n";
		it++;
	}

}
