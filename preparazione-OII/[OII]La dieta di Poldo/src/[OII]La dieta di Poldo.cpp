#include <iostream>
using namespace std;



int N, n_max = 1;
int panini[10000];
int quantiPanini[10000] = {1};




void calc(int i)
{

	if(i == N)
		return;

	quantiPanini[i] = 1;
	for(int j = i - 1; j >= 0; j--)
	{
//		cout << panini[i]<<" "<< panini[j] << " " << quantiPanini[j]<<endl;
		if(panini[j] > panini[i] && quantiPanini[j]+1 > quantiPanini[i]){
			quantiPanini[i] = quantiPanini[j] +1;
			if(quantiPanini[i] > n_max)
				n_max = quantiPanini[i];
		}
	}

	calc(i+1);

}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> N;


	for(int i = 0; i < N; i++){
		cin >> panini[i];
	}



	calc(1);

	cout << n_max;


}
