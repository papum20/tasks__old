#include <iostream>
#include <queue>
using namespace std;


int n, r, steps = 0;
struct coord{
	int y, x;
};
class comparison{
	public:
	bool operator() (coord a, coord b){	//by column
		if(a.x > b.x)
			return true;
		return false;
	}
};
priority_queue<coord, vector<coord>, comparison> army;




int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	cin >> n >> r;

	bool used[n] = {};
	for(int i = 0; i < n; i++){
		used[i] = false;
	}

	for(int i = 0; i < n; i++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		if(tmp1 == r)
			used[tmp2-1] = true;
		else
			army.push({tmp1-1,tmp2-1});
	}
	r -= 1;

/*
	for(auto i:army){
		cout << i.y<<i.x <<" ";
	}cout <<endl;
*/
	int pos = 0;

	while(!army.empty()){
		if(used[pos] == true){
			pos++;
			continue;
		}
//		cout << army.top().y << army.top().x << " " <<endl;
		steps += abs( army.top().y - r);
//		cout << abs( army.top().y - r) << " ";
		steps += abs( army.top().x - pos);
//		cout << abs( army.top().x - pos) <<endl;
		army.pop();
		used[pos++] = true;
/*		for(auto i:used)
			cout << i;
		cout<<endl;	*/
	}


	cout << steps;

}
