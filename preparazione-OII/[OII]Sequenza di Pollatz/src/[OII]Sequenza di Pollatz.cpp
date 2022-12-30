#include <iostream>
using namespace std;



int col(int n){
	int c = 1;
	while(n != 1){
		if(n %2 == 0){
			n /= 2;	}
		else{
			n = n*3 +1;	}
		c++;
	}
	return c;
}

int pol(int n, int col){
	int c = 1;
	while(n != 1 && c < col){
		if(n %2 == 0){
			n /= 2;	}
		else{
			n = n*5 +1;	}
		c++;
	}
	return c;
}



int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int a, b, t = 0;
	cin >> a >> b;

	for(int i = a; i <= b; i++){
		int coll = col(i);
		int poll = pol(i, coll);

		t += (poll < coll)? 1:0;
	}

	cout << t;

}
