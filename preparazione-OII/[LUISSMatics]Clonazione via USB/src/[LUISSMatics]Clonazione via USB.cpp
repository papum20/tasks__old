#include <iostream>
using namespace std;



//int foo(int tot, int N, int f, int c, int mx, uint64_t F, uint64_t C)
//{
//	if(tot >= N) return 0;
//	else if(F == C) return mx + foo(tot+2, N, f, c, mx, f, c);
//	else if(F > C) return c + foo(tot+1, N, f, c, mx, F, C+c);
//	else return f + foo(tot+1, N, f, c, mx, F+f, C);
//}




uint64_t foo(int tot, int f, int c, uint64_t F, uint64_t C)
{
	uint64_t f2 = F+f, c2 = C+c;
//	cout << tot << ": " << f2 << " " << c2 << endl;
	if(tot == 0) return max(F,C);
//	else if(f2 == c2) return foo(tot+2, f, c, f2, c2);
	else if(f2 > c2) return foo(tot-1, f, c, F, c2);
	else return foo(tot-1, f, c, f2, C);
}







int mcd(int x, int y) {
  while (y > 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

















int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);



	int T;
	cin >> T;

	for(int t = 0; t < T; t++)
	{
		uint64_t N, f, c;
		cin >> N >> f >> c;


//		uint64_t time = min(f,c) + foo(1, N, f, c, 0, 0);
		uint64_t time = min(f,c);
		N--;
		uint64_t mcm = f*c / mcd(f,c);
		uint64_t fatte = mcm/f + mcm/c;
		time += mcm * (N/fatte);
		N %= fatte;
//		cout << "\nNJG " << N << " " << fatte << " " << mcd <<" " << mcm << endl;
		time += foo(N, f, c, 0, 0);


		cout << "Case #" << t+1 << ": " << time << "\n";

	}

}
