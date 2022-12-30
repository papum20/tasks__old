#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void printArr(string* arr, int len){
	for(int h = 0; h < len; h++){
	cout << arr[h] << ((h == len-1)? "\n\n":", ");
}	}


string c3[3][2] = {{"U","D"}, {"R","L"}, {"F","B"}};

int main() {
while(true){
	int scrmbls, moves;
	cout << "insert n of scrambles and moves: ";
	cin >> scrmbls >> moves;

	for(int k = 0; k < scrmbls; k++){
		srand(time(NULL)+k);
		int m = rand()%3, n = rand()%2;
		string scr[moves] = {c3[m][n], ( (m==n)? c3[(n+1)%2][m]:c3[n][m]) };

		for(int i = 2; i < moves; i++){
			int m = rand()%3, n = rand()%2;

			if(scr[i-1]==c3[m][n]){
				if(scr[i-2]==c3[m][(n+1)%2]){
					scr[i] = c3[(m+1)%3][n];	}
				else{
					scr[i] = c3[m][(n+1)%2];	}
			}
			else{
				if(scr[i-1]!=c3[m][(n+1)%2]){
					scr[i] = c3[m][n];	}
				else{
					if(scr[i-2]==c3[m][n]){
						scr[i] = c3[(m+1)%3][n];	}
					else{
						scr[i] = c3[m][(n+1)%2];	}
				}
			}
		}
			printArr(scr, moves);
	}

	cout << "\n\n\n";
}	}
