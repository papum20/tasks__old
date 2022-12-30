#include <iostream>
using namespace std;





int N = 100000, P = 1000000, tot = 0;
int H[100000];
int level1[100000];	//left
int level2[100000];	//right
bool eq[100000];	//equal heights





bool growing = false;

void heights(int pos)
{

	if(H[pos] > H[pos-1]){
		level1[pos] = 0;
		growing = true;
		if(pos == N-1){
			int i = pos-1;
			while(i >= 0 && H[i] < H[i+1]){
				level2[i] = pos -i;
				i--;
			}
			level2[pos] = 0;
		}
	}

	else if((H[pos] == H[pos-1])){
		eq[pos] = true;
		eq[pos-1] = true;
		if(growing){
			int i = pos-2;
			while(i >= 0 && H[i] < H[i+1]){
				eq[i] = true;
				i--;
		}	}
		growing = false;
	}

	else if((H[pos] < H[pos-1])){
		if(growing){
			int i = pos-2;
			while(i >= 0 && H[i] < H[i+1]){
				level2[i] = pos-1 -i;
				i--;
			}
			growing = false;
			level2[pos-1] = 0;
		}

		if(eq[pos-1] == true)
			eq[pos] = true;
		else
			level1[pos] = level1[pos-1] +1;
	}



	if(pos < N-1)
		heights(pos+1);
}




int main(){

	cin >> N >> P;


	for(int i = 0; i < N; i++)
		cin >> H[i];



	level1[0] = 0;
	level2[0] = 0;
	level2[N-1] = 0;
	heights(1);




	for(int i = 0; i < N; i++){
		if(eq[i] == false && max(level1[i],level2[i]) < P)
			tot++;
	}

//	for(int i = 0; i < N; i++)
//		cout<<level1[i]<<" " ;
//	cout<<endl;
//	for(int i = 0; i < N; i++)
//		cout<<level2[i]<<" " ;
//	cout<<endl;
//	for(int i = 0; i < N; i++)
//		cout<<eq[i]<<" " ;
//	cout<<endl;


	cout << tot;




}
