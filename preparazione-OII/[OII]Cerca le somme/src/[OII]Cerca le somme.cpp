#include <iostream>
using namespace std;

int n, tot, res;
bool two = true;
string digits[9];
bool signs[8];



void eval(int pos2, int i){
	if(i < n){
//		cout<< "i: "<<i<<" ";	//
//		cout << endl;	//
		if(i == n-1 || signs[i] == true){
			string number;
			for(int x = pos2; x < i+1; x++){
				number += digits[x];
//				cout<<number<<" ";
			}
//			cout<<endl;
			res += stoi(number);
			eval(i+1,i+1);
		}
		else
			eval(pos2,i+1);
	}
}


void permute(int pos){
/*	for(auto x:signs){
		cout << x;}
	cout<<endl;	*/
	if(two){
		res = 0;
		eval(0,0);
		if(res == tot){
			for(int i = 0; i < n-1; i++){
				if(signs[i])
					cout << (i+1) << " ";
			}
			cout << "\n";
		}
	}

	if(pos < n-1){
		if(signs[pos] == false){
			two = true;
			signs[pos] = true;
			for(int i = 0; i < pos; i++){
				signs[i] = false;
			}
			permute(0);
		}
		else{
			two = false;
			permute(pos+1);
		}

	}
}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> digits[i];
	}
	for(int i = 0; i < n-1; i++){
		signs[i] = false;
	}

	cin >> tot;

	permute(0);

}
