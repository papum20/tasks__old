#include <iostream>
using namespace std;



int N, K;
string words[100000];





void print(int word, int pos)
{
	if(word < N){

		int len = words[word].length();

		if(pos == 0){
			cout << "\n" << words[word];
			print(word+1, len);
		}

		else{
			if(pos + 1 + len <= K){
				cout << " " << words[word];
				print(word+1, pos+1+len);
			}
			else
				print(word, 0);
		}

	}
}





int main(){

	cin >> N >> K;


	for(int i = 0; i < N; i++)
		cin >> words[i];



	cout << words[0];
	print(1, words[0].length());

}
