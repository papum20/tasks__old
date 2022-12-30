#include <iostream>
#include <vector>
using namespace std;

int n;
bool spazioInMezzo = false;
struct movement{
	int from, to;
};
vector <movement> moves;





void move_trains(int pos = n){
	if(pos > 3){
		if(spazioInMezzo == true){
			spazioInMezzo = false;
			moves.push_back({2*n+1 -2*(n-pos),pos+1});	//2*n+2-3 -2*(n-pos)
			return move_trains(pos);
		}
		else{
			moves.push_back({pos,2*n+1 -2*(n-pos)});	//2*n+2 -1-2*(n-pos)
			spazioInMezzo = true;
			return move_trains(--pos);
		}
	}
}



int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;


	if(n == 3){
		cout << "4 3\n2 7\n6 2\n4 7\n6 4";
	}

	else{
		move_trains();
		cout << (moves.size()+4) << " " << n << "\n";
		for(auto i:moves){
			cout << i.from << " " << i.to << "\n";
		}
		cout << "2 4\n6 2\n3 6\n";
		cout << 2*n+1 << " " << 3;
	}

}
