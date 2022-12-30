#include <iostream>
#include <unordered_map>
using namespace std;





int main()
{
	int N, L;
	cin >> N >> L;

	int M;
	cin >> M;

	string favourite[M];

	for(int i = 0; i < M; i++)
	{
		cin >> favourite[i];
	}



	unordered_map <string, int> occur;
	unordered_map <string, int> lastUsed;

	for(int i = 1; i < N; i++)
	{
		int M;
		cin >> M;

		for(int j = 0; j < M; j++)
		{
			string tmp;
			cin >> tmp;
			if(lastUsed[tmp] < i)
				occur[tmp] += 1;
			lastUsed[tmp] = i;
		}


	}


	for(auto i:favourite)
	{
		cout << occur[i] << " ";
	}


}

