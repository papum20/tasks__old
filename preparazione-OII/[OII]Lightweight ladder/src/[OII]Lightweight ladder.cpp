#include <iostream>
using namespace std;



int main(){
	int N;
	cin >> N;

	int a, b;
	cin >> a;
	int mx = a;
	for(int i = 1; i < N; i++){
		cin >> b;
		mx = max(mx, b-a);
		a = b;
	}

	cout << mx;
}
