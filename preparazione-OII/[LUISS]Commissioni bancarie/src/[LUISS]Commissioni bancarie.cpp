#include <iostream>
#include <set>
using namespace std;



int T;
uint32_t N;
uint64_t spesa = 0;

multiset <int> p;



int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> T;

	for(int t = 0; t < T; t++)
	{
		spesa = 0;
		cin >> N;
		for(uint32_t n = 0; n < N; n++){
			int pi;
			cin >> pi;
			p.insert(pi);
		}



		while(p.size() > 1)
		{
			multiset<int>::iterator itA = p.begin();
			multiset<int>::iterator itB = p.begin();
			itB++;
//			cout << *itA << " "<<*itB<<endl;
			spesa += (*itA + *itB)/100;
			p.insert(*itA + *itB);
			p.erase(*itA);
			p.erase(*itB);

		}



		cout << "Case #" << t+1 << ": " << spesa << "\n";
		p.clear();

	}

}
