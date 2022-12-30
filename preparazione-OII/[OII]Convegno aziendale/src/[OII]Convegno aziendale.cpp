#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map <int,int> tree;
int tot = 0;



void ricorsiva(int C[], int B)
{

	if(tree[B] > 0){
		tot += tree[B];
		return;
	}

	if(C[B] == -1)
		return;

	ricorsiva(C, C[B]);
	tot++;
	tree[B] = tree[C[B]]+1;
}





int coppie(int N, int C[])
{


	for(int A = 0; A < N; A++)
	{
		if(C[A] == -1)
			continue;

		ricorsiva(C, A);

	}


	return tot;
}





int main(){

	int N;
	cin >> N;

	int C[N];
	for(int i = 0; i < N; i++)
		cin >> C[i];


	 cout << coppie(N, C);

}
