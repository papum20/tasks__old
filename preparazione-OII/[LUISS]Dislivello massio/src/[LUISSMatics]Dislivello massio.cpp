#include <iostream>
using namespace std;





int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;


	for(int t = 0; t < T; t++)
	{
		int N, mx = 0;
		cin >> N;

		int h[N];
		for(int i = 0; i < N; i++)
			cin >> h[i];



		int dp[N];

		for(int a = 0; a < N; a++)
		{
			dp[a] = 0;
			for(int b = a+1; b < N; b++)
				dp[a] = max(dp[a], h[a]-h[b]);

			mx = max(mx, dp[a]);
		}



		cout << "Case #" << t+1 << ": " << mx << "\n";
	}

}
