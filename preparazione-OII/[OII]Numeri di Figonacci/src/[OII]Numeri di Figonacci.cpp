#include <iostream>
using namespace std;


int N = 1000000, M = 40000;
int64_t Gn = 0, Gn1 = 0;
int64_t tot = -1;



void calc(int n){

	Gn1 = Gn;


//	Gn = ( (n-1) * Gn1 - tot) % M;
	Gn = ((n-1)%M * Gn1) % M;
	Gn = (Gn - tot) % M;
	if(Gn < 0)
		Gn += M;
//	Gn = ((n-1) * Gn1) % M - tot;
//	Gn %= M;

	tot += Gn1;
	if(tot > 0)
		tot %= M;
	cout<<Gn<<" "<<Gn1<<" "<<tot<<"\n";

	if(n < N)
		calc(n+1);

}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> N >> M;

	calc(2);
	cout << Gn;

}
