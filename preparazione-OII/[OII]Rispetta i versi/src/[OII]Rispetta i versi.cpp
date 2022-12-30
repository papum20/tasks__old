#include <iostream>
using namespace std;


int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	cin.ignore();

	int max = n, min = 1;


	for(int i = 0; i < n; i++){
		char s = getchar();
		cout << ( (s == '>')? (max--):(min++) ) << ( (i == n-1)? "":" ");
	}

}
