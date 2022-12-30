#include <iostream>
#include <iomanip>
using namespace std;







int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 0; t < T; t++)
	{
		int N, P;
		float mn = 100000000;
		cin >> N >> P;

		for(int n = 0; n < N; n++)
		{
			int m;
			float k;
			cin >> m >> k;

			float tmp = k * ( (P/(m+1)) * m + P % (m+1) );
//			cout << t << " " << tmp<<endl;
			mn = min(mn, tmp);
		}

		cout << "Case #" << t+1 << ": " << fixed << setprecision(2) << mn << "\n";

	}


}
