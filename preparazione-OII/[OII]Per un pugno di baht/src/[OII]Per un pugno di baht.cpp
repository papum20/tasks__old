#include <iostream>
#include <set>
using namespace std;


int p, n;
uint64_t ind = 0;

multiset<uint32_t> m;


bool permutation[10000];

void permute(int pos){

	if(pos == n){
		return;
	}

	else if(!permutation[pos]){
		permutation[pos] = true;
		for(int i = 0; i < pos; i++){
			permutation[i] = false;
		}

/*		for(int i = 0; i<n;i++){
			cout<<permutation[i];
		}cout<<endl;*/

//		ind++;

		uint64_t tmp = 0;
		multiset<uint32_t>::iterator it = m.begin();
		for(int i = 0; i <= n; i++){
			if(permutation[i]){
				tmp += *(it);
			}
			it++;
		}
//		cout<<tmp<<endl;	//

		if(tmp > ind+1){
			ind++;
			return;
		}
		else if(tmp == ind+1)
			ind = tmp;

		permute(0);
	}

	else{
		permute(pos+1);
	}

}



int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	cin >> p;

	for(int t = 0; t < p; t++){
//		cout<<t;

		cin >> n;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			m.insert(tmp);

			permutation[i] = false;
		}

		ind = 0;
		permute(0);
		cout << ind << "\n";


		m.clear();

	}

}
