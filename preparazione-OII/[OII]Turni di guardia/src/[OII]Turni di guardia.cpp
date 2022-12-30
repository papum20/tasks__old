#include <iostream>
#include <set>
using namespace std;


int k, n, spesa = 0;
struct days{
	int from, to;
};
auto finisceDopo = [](const days& a, const days& b){
	return a.to > b.to;
};
auto people = multiset<days, decltype(finisceDopo)>(finisceDopo);



void calc(int pos){
	if(pos == 0){
		for(auto i:people){
			if(i.from == 0){
				spesa++;
				cout <<"A"<< i.from<<i.to<<endl;
				calc(i.to+1);
				break;
		}	}
	}
	else if(pos < k){
		for(auto i:people){
			if(i.from <= pos && i.to >= pos){
				spesa++;
				cout<<i.from<<i.to<<endl;
				calc(i.to+1);
				break;
		}	}
	}

}

/*
void calc(int pos){
	int tmp_pos;
	if(pos == 0){
		for(auto i:people){
			if(i.from == 0){
				spesa++;
				tmp_pos = i.to;
//				cout << i.from<<i.to<<endl;	//
				people.erase(people.find({i.from,i.to}) );
				break;
		}	}
		calc(tmp_pos);
	}
	else if(pos <= k-1){
		for(auto i:people){
			if(i.from <= pos+1 && i.to > pos+1){
				spesa++;
				tmp_pos = i.to;
//				cout << i.from<<i.to<<endl;	//
				people.erase(people.find({i.from,i.to}) );
				break;
		}	}
		calc(tmp_pos);
	}

}
*/





int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> k >> n;
	for(int i = 0; i < n; i++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		people.insert({tmp1,tmp2});
	}

	if(n == 1 || k == 1)
		cout << 1;
	else{
		calc(0);
		cout << spesa;
	}

}
