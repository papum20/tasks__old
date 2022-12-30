#include <iostream>
#include <vector>
using namespace std;


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int n, pari = 0, dispari = 0, tot = 0, tmp;
	vector<int> res;
	cin >> n;


	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp%2 == 0 && pari == dispari){
			tot++;
			res.push_back(tmp);
		}
		if(tmp%2 == 0) pari++;
		if(tmp%2 == 1) dispari++;
	}

	cout << tot << "\n";
	for(int x:res)
		cout << x << " ";

}
