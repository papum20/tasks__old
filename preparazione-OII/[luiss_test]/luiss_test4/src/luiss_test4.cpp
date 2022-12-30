#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	bool pr = 1;
	cin >> n;
	int primi = (n > 1)? 1:0;


	for(int a = 1; a <= n; a+=2){
		if(a%2 == 0){
			continue;
		}
		for(int b = 3; b <= sqrt(a); b+=2){
			if(a%b == 0){
				pr = 0;
				break;
		}	}
		if(pr){
			primi++;
		}
		pr = 1;
	}

	cout << primi;
}
