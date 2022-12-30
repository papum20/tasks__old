#include <iostream>
using namespace std;


int n, m;
string numbers[8];
bool used[8];
string permutation[8];
string sol[8];	//solution



bool pal(){	//palindromi o quasi-palindromi
	for(int x = 0; x < n; x++){
		for(int y = 0; (m%2==0)? (y<m/2):(y<=m/2); y++){
			if(permutation[y][x] != permutation[m-1-y][x] && permutation[y][x] != '0' && permutation[m-1-y][x] != '0')
				return false;
	}	}
	return true;
}



void permute(int pos){

	if(pos == m && pal()){	//if pal.
		for(int y = 0; y < m; y++){
			sol[y] = permutation[y];
		}
	}

	for(int i = 0; i < m; i++){
		if(!used[i]){
			permutation[pos] = numbers[i];
			used[i] = true;
			permute(pos+1);
			used[i] = false;
		}
	}

}




int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> m >> n;

	for(int i = 0; i < m; i++){
		cin >> numbers[i];
	}


	permute(0);

	for(int i = 0; i < m; i++){
		cout << sol[i] << "\n";
	}

}
/*
4 7
1233339
0041414
0000000
2241400

*/
