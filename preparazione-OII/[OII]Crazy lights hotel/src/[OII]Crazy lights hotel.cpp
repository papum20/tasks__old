#include <iostream>
using namespace std;



int N, K, mn = 999999999;
bool lights[20];
int t[20];
int turnoff[20][20];



int on = 0;

void ricorsiva(int pos, int tot)
{
	cout << pos<<" " <<on<<endl;
	for(int i = 0; i<N; i++)
		cout<<lights[i];
	cout<<endl;
	if(pos == N)
		return;

	else if(on == 1 && lights[K-1] == 1)
		mn = min(mn, tot);

	else{
		if(lights[pos] == 0){

			bool tmp[20];
			for(int i = 0; i < N; i++)
				tmp[i] = lights[i];

			for(int i = 0; i < t[pos]; i++){
				if(lights[turnoff[pos][i]-1] == 1){
					lights[turnoff[pos][i]-1] = 0;
					on--;
				}
			}
			lights[pos] = 1;
			on++;

			ricorsiva(0, tot+1);

			for(int i = 0; i < N; i++){
				if(lights[i] == 0 && tmp[i] == 1){
					lights[i] = tmp[i];
					on++;
				}
			}
			lights[pos] = 0;
			on--;

		}
		if(pos < N-1)
			ricorsiva(pos+1, tot);
	}
}





int main(){

//	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	cin >> N >> K;

	for(int i = 0; i < N; i++){
		cin >> lights[i];
		if(lights[i] == 1) on++;
	}

	for(int i = 0; i < N; i++){
		cin >> t[i];
		for(int j = 0; j < t[i]; j++)
			cin >> turnoff[i][j];
	}



	ricorsiva(0, 0);
	cout << mn;

}
