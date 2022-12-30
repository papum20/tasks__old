#include <iostream>
using namespace std;


int n;
int first = 0, n_max = 0;



int main(){

	cin >> n;

	for(int a = 1; a <= n; a++){

		int tmp1 = 0;
		for(int b = 0; b < n+1; b++){

			int tmp2;
			cin >> tmp2;
//			cout<<"tmp "<<tmp2<<" "<<tmp1<<endl;
			if(tmp2 == -1)
				continue;

			tmp1 += tmp2;
//			cout<<"TMP "<<tmp2<<endl;

		}

		if(tmp1 > n_max){
			first = a;
			n_max = tmp1;
		}

		cout << first << "\n";
	}


}
