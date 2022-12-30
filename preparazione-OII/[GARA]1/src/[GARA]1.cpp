#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int N, K;



int foo(int n){
	if(n == 0) return 0;
	return (n/K)+foo(n/K);
}




int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 0; t < T; t++){

		cin >> N >> K;

		cout << "Case #" << t+1 << ": " << N+foo(N) << endl;


	}

}
