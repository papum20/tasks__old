#include <iostream>
using namespace std;



int main(){

	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);

	int N;
	cin >> N;

	int parent[N];
//	int reverse[N];
	long long monete[N];
//	long long tot[N];
	for(int i = 0; i < N; i++)
		cin >> monete[i];
	parent[0] = -1;
	for(int i = 1; i < N; i++){
		cin >> parent[i];
		parent[i]--;
//		tot[i] = 0;
//		reverse[graph[i]] = i;
	}



	int tot = 0;
	for(int i = N-1; i >= 0; i--)
	{
		cout << "i"<<i<<": ";
//		tot[parent[i]] += abs(monete[i] -1);
		if(monete[i] < 1){
			tot += 1-monete[i];
			if(i != 0) monete[parent[i]] -= 1-monete[i];
		}
		else if(monete[i] > 1){
			tot += monete[i]-1;
			if(i != 0) monete[parent[i]] += monete[i]-1;
		}
		cout <<tot<< endl;
	}





	cout << tot;

}
