#include <iostream>
#include <set>
using namespace std;


uint32_t N;





void foo(){
	if(N == 1)
		cout << "FRED";
	else if(N == 2)
		cout << "FRACNESCO";
	else if(N%2 == 1)
		cout << "FRANCESCO";
	else{	//if N%2 == 0

	}
}


int main(){

	cin >> N;

	foo();

}




/*

#include <iostream>
#include <set>
#include <cmath>
using namespace std;


int T;
uint32_t N;
int n_div = 0;
set <uint64_t> dividers;
string player = "FRED";



void findDividers(uint64_t m){
	for(uint64_t d = 3; d <= sqrt(m); d+=2){
		if(m%d == 0){
			dividers.insert(d);
			n_div++;
	}	}
}


/*
void palloncini(uint32_t n)
{
	player = (player == "FRED")? "FRANCESCO":"FRED";
	if(n == 1)
		return;

	else
	{
		if(n%2 == 0){
			n_div = 0;
			findDividers(n-1);
			palloncini(n-1);
		}
		else{

		}
	}

}*
bool primo(uint64_t mm){
	for(int i = 2; i < sqrt(mm); i+=(i%2 == 0)?1:2){
			if(i % i == 0){
				return false;
			}
		}
	return true;
}


std::set<uint64_t>::iterator it;
void primi(){
	if(primo(*it)){
		n_div--;
		dividers.erase(*it);
		primi();
	}
	else{
		if(it != dividers.begin()){
		it++;
		primi();
	}}
}


int twos = 0;
void two(uint64_t m){
	if(m%2 == 0){
		twos++;
		two(m/2);
	}
}




int main(){

//	freopen("output.txt";"w",stdout);

	cin >> T;


	for(int t = 0; t < T; t++)
	{

		cin >> N;

		it = dividers.begin();
		findDividers(N);
		primi();
		two(N);

		string win;
		if(twos == 1 || twos %2 == 2)
			win = (n_div > 0)? ""

		cout << "Case #" << t+1 << ": " << player << "\n";

	}

}
*/
