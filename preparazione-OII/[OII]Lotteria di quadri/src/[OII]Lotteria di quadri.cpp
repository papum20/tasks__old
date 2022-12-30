#include <iostream>
using namespace std;

//int tot;
/*
int quadri(int N, long long int M, int V[]){

	for(int B = N; B > 0; B--)
	{
//		cout<<"B: "<<B<<endl;
		uint64_t sum = 0;
		for(int i = 0; i <= N; i++)
		{
//			cout<<"i: "<<i<< ", "<<sum<<endl;
			if(sum > M)
				break;
			if(i == N){
//				tot = B;
				return B;
			}
//			cout<<"  min "<<i<<" "<< (N-1)<<" "<<(i<=N-1)<<"  ";
			if(i <= B - 1)
				sum += V[i];
			else{
				sum += V[i];
				sum -= V[i-B];
			}
		}
	}

	return 0;
}
*/


int quadri(int N, long long int M, int V[])
{
	int B = 0;
	bool changed = false;
	long long int sum = 0;

	for(int i = 0; i < N; i++)
	{
		if(!changed){
			sum += V[i];
			B++;
		}
		else{
			sum += V[i];
			sum -= V[i-B];
		}
		cout<<sum<<endl;
		while(sum > M){
			changed = true;
			sum -= V[i-B+1];
			B--;
		}
		cout<<sum<<endl;

	}

	return B;

}




int main(){
	int n;
	long long int m;
	cin>>n>>m;
	int V[n];
	for(int i = 0; i < n; i++){
		cin >> V[i];
	}
	cout << quadri(n,m,V);
}
