#include <iostream>
using namespace std;






int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	int N, top = 0;
	cin >> N;
	int mx[N];



	for(int i = 0; i < N; i++)
	{
		int i1;
		for(int n = 0; n <= i; n++)
		{
			int tmp;
			cin >> tmp;

			if(i > 0){

				if(n == 0){
					i1 = mx[n];
					mx[n] += tmp;
				}
				else if(n > 0 && n < i){
					int i2 = mx[n];
					mx[n] = tmp + max(i1, mx[n]);
					i1 = i2;
				}
				else if(n == i)
					mx[n] = i1 + tmp;

			}

			else{
				mx[n] = tmp;
			}


			top = max(top, mx[n]);
		}
	}



	cout << top;

}
