#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;


/*
bool prime(int n){
    if(n%2 == 0){
        return 0;
    }
	for(int i = 3; i <= sqrt(n); i+=2){
		if(n%i == 0){
			return 0;
	}	}
	return 1;
}
*/

bool prime(int n){
	for(int i = 2; i <= sqrt(n); i+=((i==2)?1:2)){
		if(n%i == 0){
			return 0;
	}	}
	return 1;
}


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	bool sp = 0;
	cin >> n;


	for(int i = 3; i <= sqrt(n); i+=((i==2)?1:2)){
		if(n%i == 0 && prime(i)){
			if(prime(n/i)){
				cout << i << " " << n/i;
				sp = 1;
			}
			break;
		}
	}

	if(!sp)
		cout << -1;


}
