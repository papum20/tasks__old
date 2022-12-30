#include <iostream>
using namespace std;


int N = 1000, D_max = 0;
int mx[1000], Ds[1000];





int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> N;



	cin >> mx[0] >> mx[1];
	D_max = max(mx[0], mx[1]);
	Ds[0] = mx[0];
	Ds[1] = mx[1];

	for(int i = 2; i < N-1; i++)
	{
		int D;
		cin >> D;
		mx[i] = D;
		Ds[i] = D;

		for(int j = 0; j < i-1; j++){
			if(D + mx[j] > mx[i])
				mx[i] = D + mx[j];
		}

		D_max = max(D_max, mx[i]);
	}



	cin >> Ds[N-1];

	for(int i = 2; i < N; i++)
	{
		mx[i] = Ds[i];


		if(i == N-1){
			for(int j = 1; j < i-1; j++){
				if( Ds[i] + mx[j] > mx[i]){
					mx[i] = Ds[i] + mx[j];
				}
			}
		}
		else{
			for(int j = 1; j < i-1; j++){
				if(Ds[i] + mx[j] > mx[i])
					mx[i] = Ds[i] + mx[j];
			}
		}
	}





	cout << max(D_max,mx[N-1]);


}








/*#include <iostream>
using namespace std;



int N, mx = 0;
int D[1000];
int Max[1000];
int first[1000];



void calc(int i)
{

	if(i == N)
		return;

	for(int j = 0; j < i-1; j++)
	{
		if(i == N-1){
			cout << j << " " << first[j] << " " << (Max[j] + D[i] - D[0]) << ">" << Max[i] << endl;
			if(first[j] == false){
				if(Max[j] + D[i] > Max[i])
					Max[i] = Max[j] + D[i];
			}
			else{
				if(Max[j] + D[i] - D[0] > Max[i])
					Max[i] = Max[j] + D[i] - D[0];
			}
		}
		else{
			if(Max[j] + D[i] > Max[i]){
				Max[i] = Max[j] + D[i];
				if(first[j])
					first[i] = true;
				else
					first[i] = false;
			}
		}
	}
	cout << i << endl;
	for(int h = 0; h <= i; h++)
		cout << Max[h] << " ";
	cout << endl;
	if(Max[i] > mx){
//		cout<<Max[i]<<endl;
		mx = Max[i];
	}


	calc(i+1);

}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> D[i];
		Max[i] = D[i];
		first[i] = false;
	}
	first[0] = true;



	calc(1);
	cout << max(mx, D[0]);



}

*/
