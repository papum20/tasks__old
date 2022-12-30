#include <iostream>
#include <iomanip>
using namespace std;
int getDigits(int n){
	int digits = 0;
	while(n){
		n /=10;
		digits++;
	}
	return digits;
}
int main(){
	int n, a, b;
	cout<<"Digita l'altezza del triangolo di tartaglia: ";
	cin>>n;
	if(n==1){
		cout<<endl<<"1";
		return 0;
	}
	int t[n][2*n-1];
	a = (2*n-1)/2;
	b = a;
	for (int i=0; i<n; i++){
		for (int j=0; j<2*n-1; j++){
			t[i][j] = 0;
		}
	}
	t[0][a] = 1;
	for (int i=1; i<n; i++){
		for (int j=0; j<2*n-1; j++){
			if(j>a && j<b){
				t[i][j] = t[i-1][j-1] + t[i-1][j+1];
			}
			a--;
			b++;
		}
	}
	t[n-1][2*n-2] = 1;//bug da capire
	int spaces = 4;//numero cifre significative max tollerate per formattazione
	for (int i=0; i<n; i++){
		for (int j=0; j<2*n-1; j++){
			if (t[i][j]==0) cout<<"    ";
			else cout<<setw(spaces-getDigits(t[i][j]))<<t[i][j];
		}
		cout<<endl;
	}
	return 0;
}
