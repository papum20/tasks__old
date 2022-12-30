#include <iostream>
using namespace std;






int tempo_massimo(int N, int A[], int B[])
{
	int tot = 0;
	int H[2] = {0,0};	//H[0] = on odd numbers, H[1] on even numbers (alternatively)
	int lastS = 0;	//last SuperFast
	int Hs = 0;	//number of HyperFast taken in a row



	lastS = max(A[0],B[0]);
//	cout<<A[0]<<B[0]<<max(A[0],B[0])<<endl;


	for(int i = 1; i < N; i++)
	{
//		cout << tot<<endl;
//		cout<<i << " " <<tot<<" "<<H[0]<<" "<<H[1]<<" "<<lastS<<" "<<Hs<<endl;
		if(Hs == 0)
		{
			if(B[i] > A[i] + lastS){
				H[0] = B[i];
				Hs = 1;
				//lastS remains the same
			}
			else{
				tot += lastS;
				lastS = A[i];
			}
		}

		else
		{
			int mod = Hs%2;
			if(H[mod] + B[i] > H[(mod+1)%2] + A[i] + ((mod==0)? lastS:(-lastS)) ){
				H[mod] += B[i];
				Hs++;
				//same lastS
			}
			else{
//				cout<<"    "<<tot<<endl;
				tot += H[(mod+1)%2];
//				cout<<"    "<<tot<<endl;
				if(mod == 0) tot += lastS;

				Hs = 0;
				H[0] = 0;
				H[1] = 0;
				lastS = A[i];
			}
		}


	}


	if(Hs > 0){
		tot += H[(Hs+1)%2];
		if(Hs%2 == 0) tot += lastS;
	}
	else
		tot += lastS;



	return tot;
}







int main()
{
	int N;
	cin >> N;

	int A[N];	//SuperFast
	int B[N];	//HyperFast


	for(int i = 0; i < N; i++) cin >> A[i] >> B[i];


	cout << tempo_massimo(N, A, B);


}





/*

3
2 5
3 2
2 8

13

4
3 2
3 3
3 1
3 4


12
 */
