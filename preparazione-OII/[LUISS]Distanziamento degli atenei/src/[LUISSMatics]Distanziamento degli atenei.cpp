#include <iostream>
using namespace std;





double mn = 0;
bool atenei[100];

void foo(int n, float x[], int nAtenei, int pos)
{
//	for(int i = 0; i < n; i++)
//		cout << atenei[i];
//	cout << nAtenei << endl;
	if(nAtenei == 0)
	{
		double tmp = 0;
		for(int i = 0; i < n; i++){
			int a = -1, b = -1;
			if(!atenei[i]){
				for(int j = i-1; j >= 0; j--){
					if(atenei[j])
						a = j;
				}
				for(int j = i+1; j < n; j++){
					if(atenei[j])
						b = j;
				}

			if(a != -1){
				int d1 = x[i] - x[a];
//				cout << "D1 " << d1 << endl;
				if(b != -1){
					int d2 = x[b] - x[i];
//					cout << "D2 " << d2 << endl;
					tmp += min(d1,d2);
				}
				else tmp += d1;
			}
			else tmp += x[b] - x[i];
//			cout << x[b] - x[i] << endl;

			}
		}
		mn = min(mn, tmp);
	}

	else if(pos < n)
	{
		if(atenei[pos] == false){
			atenei[pos] = true;
			foo(n, x, nAtenei-1, pos+1);
			atenei[pos] = false;
		}
		if(nAtenei > 0) foo(n, x, nAtenei, pos+1);
	}

}







int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);



	int T;
	cin >> T;


	for(int t = 0; t < T; t++)
	{
		int N, M;
		mn = 0;
		cin >> N >> M;

		float X[N];
		for(int i = 0; i < N; i++){
			cin >> X[i];
			mn += X[i];
			atenei[i] = false;
		}



		foo(N, X, M, 0);


		cout << "Case #" << t+1 << ": " << mn << "\n";
	}


}
