#include <iostream>
using namespace std;


bool in(string elem, string arr[], int l){
	for(int i = 0; i < l; i++){
		if(arr[i] == elem){
			return 1;
	}	}
	return 0;
}



int main(){
	int b, g, email, b_e = 0, g_e = 0;
	cin >> b;
	string bad[b];
	for(int i = 0; i < b; i++){
		cin >> bad[i];
	}
	cin >> g;
	string good[g];
	for(int i = 0; i < g; i++){
			cin >> good[i];
	}


	cin >> email;
	for(int i = 0; i < email; i++){
		bool gud = 0, bed = 0;
		int word;
		cin >> word;

		for(int w = 0; w < word; w++){
			string tmp;
			cin >> tmp;

			if(!bed){
				if(in(tmp, bad, b))
					bed = 1;
			}
			if(!gud){
				if(in(tmp, good, g))
					gud = 1;
			}
		}


		if(gud && !bed){
			g_e++;
		}
		else if(bed && !gud){
			b_e++;
		}

	}


	cout << b_e << " " << g_e;

}
