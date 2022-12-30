#include <iostream>
using namespace std;


int n;
struct tessera{
	int s, d;
};
tessera t[10];
tessera r[10];	//rovesciate
tessera permutazione[10];
bool usate[10];
int lunghezza = 0;	//max



void permutazioni(int pos){
	if(pos > lunghezza){
		lunghezza = pos;
	}
	for(int i = 0; i < n; i++){
		if(pos == 0 || (usate[i] == false && permutazione[pos-1].d == t[i].s) ){
			permutazione[pos] = t[i];
			usate[i] = true;
			permutazioni(pos +1);
			usate[i] = false;
		}
		if(pos == 0 || (usate[i] == false && permutazione[pos-1].d == r[i].s) ){
			permutazione[pos] = r[i];
			usate[i] = true;
			permutazioni(pos +1);
			usate[i] = false;
		}
	}
}




int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i].s >> t[i].d;
		r[i] = {t[i].d, t[i].s};
		usate[i] = 0;
	}


	permutazioni(0);
	cout << lunghezza;

}

