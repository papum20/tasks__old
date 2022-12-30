#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct persona{
	string nome, cognome;
	int eta;
};


int main() {
	freopen("input.txt","r",stdin);

	vector<persona>X;
	while(!cin.eof() ){
		persona tmp;
//		cin.ignore();
		getline(cin,tmp.nome,';');
		getline(cin,tmp.cognome,';');
		cin >> tmp.eta;
		X.push_back(tmp);
	}



	auto compare1 = [](const persona a, const persona b){
		return a.cognome < b.cognome;
	};
	sort(X.begin(), X.end(), compare1);

	auto compare2 = [](const persona a, const persona b){
		return a.eta < b.eta;
	};
	sort(X.begin(), X.end(), compare2);



	for(auto x:X){
		cout << x.nome << " " << x.cognome << " " << x.eta << "\n";
	}

}
