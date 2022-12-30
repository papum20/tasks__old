#include <iostream>
#include <set>
using namespace std;



int T, N;
uint64_t spesa = 0;
set <double> plants;


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> T;

	for(int t = 0; t < T; t++)
	{
		spesa = 0;
		cin >> N;
		for(uint32_t n = 0; n < N; n++){
			double p;
			cin >> p;
			plants.insert(p);
		}




		cout << "Case #" << t+1 << ": " << N << "\n";
		plants.clear();

	}

}
