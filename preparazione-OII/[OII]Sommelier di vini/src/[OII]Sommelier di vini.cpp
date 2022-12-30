#include <iostream>
using namespace std;


int N, n_max = 0;
int wines[99];
int mx[99];




void calc(int i)
{

	if(i == N)
		return;

	mx[i] = 1;
	for(int j = 0; j < i-1; j++)
	{
//		cout << wines[i] << " " <<wines[j] << "    "<<mx[i] << " " <<mx[j]<<endl;
		if(wines[j] <= wines[i] && mx[j] +1 > mx[i]){
			mx[i] = mx[j] + 1;
			n_max = max(n_max, mx[i]);
		}
	}

	calc(i+1);
}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> wines[i];


	mx[0] = 1;
	mx[1] = 1;

	calc(2);
	cout << n_max;


}
