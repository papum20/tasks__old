#include <iostream>
using namespace std;



int main(){

	int N, tot = 0;
	cin >> N;

	bool bold  = false, italic = false;
	for(int i = 0; i < N; i++){
		char c;
		cin >> c;

		if(!bold && (c == 'I' || c == 'N') )
			bold = true;
		if(!italic && (c == 'i' || c == 'I') )
			italic = true;
		if(bold && (c == 'i' || c == 'n') ){
			bold = false;
			tot++;
		}
		if(italic && (c == 'N' || c == 'n') ){
			italic = false;
			tot++;
		}

	}

	if(bold)
		tot++;
	if(italic)
		tot++;



	cout << tot;

}
