#include <iostream>
using namespace std;





int harmony(int s, int g[], int last, int pos, int tot)
{
//	cout << pos << "  " << last << "  " << tot <<endl;
	if(pos == s)
		return tot;
	else if(g[pos] == last)
		return -1;
	else
		return harmony(s, g, pos, g[pos], tot+1);
}





int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int N, M, H, S;
	cin >> N >> M >> H >> S;
	H--;
	S--;


	int tunnel[N];
	int lightness[N];

	for(int i = 0; i < N; i++)
		lightness[i] = -1;

	for(int i = 0; i < M; i++){
		int A, B, L;
		cin >> A >> B >> L;
		A--;
		B--;
		if(lightness[A] == -1 || L < lightness[A]){
			tunnel[A] = B;
			lightness[A] = L;
		}
		if(lightness[B] == -1 || L < lightness[B]){
			tunnel[B] = A;
			lightness[B] = L;
		}
	}



	cout << harmony(S, tunnel, -1, H, 0);

}
