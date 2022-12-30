#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;







int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 0; t < T; t++)
	{
		int N;
		vector <float> p;	//people
		auto order = [](const float &a, const float &b){
			return a < b;
		};
		cin >> N;



		for(int i = 0; i < N; i++){
			float tmp;
			cin >> tmp;
			p.push_back(tmp);
		}
		sort(p.begin(),p.end(),order);



		int tot = 0;
		bool mask[N];
		mask[0] = false;
		for(int i = 1; i < N; i++){
//			bool need = false;
//			cout << i <<endl;
			for(int j = i-1; j >= 0; j--){
				if(p[i]-p[j] < 2 && !mask[j]){
//					need = true;
//					cout << j << " ";
					mask[i] = true;
					tot++;
					break;
				}
			}


		}


		cout <<  "Case #" << t+1 << ": " << tot << endl;
	}

}
