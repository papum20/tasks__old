#include <iostream>
using namespace std;

int main(){



	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int g, p, n = 1, t = 0;
	cin >> g >> p;
	p--;


	while(g > 0){
		t += (g > n)? n:g;
		g -= n++;
		g -= p;
	}

	cout << t;

}
