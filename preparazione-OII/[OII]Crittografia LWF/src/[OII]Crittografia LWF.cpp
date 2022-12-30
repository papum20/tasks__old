#include <iostream>
using namespace std;


int n, tot = 0, tmp_max = 1, ind = 0, ind_max;
bool crypt[30];
//int a = 0, b = 0;

void fibonacci(int a = 1, int b = 0){
//	cout<<ind<<" " <<a<<b<<endl;	//
	if(ind == 0){
		ind++;
		fibonacci(1, 1);
	}
	else if(a <= n-tot){
		tmp_max = a;
		ind++;
		fibonacci(a+b, a);
	}
}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;


	fibonacci(0,0);
/*	for(int i = 0; i < ind; i++){
		crypt[i] = false;
	}*/
	crypt[ind-1] = true;
	tot += tmp_max;
	ind_max = ind;


	while(tot < n){
/*		for(auto i:crypt)
			cout <<i;
		cout<<endl;*/
		ind = 0;
		fibonacci(0,0);
		crypt[ind-1] = true;
		tot += tmp_max;
	}

	for(int i = 0; i < ind_max; i++){
		cout << crypt[i];
	}

}
