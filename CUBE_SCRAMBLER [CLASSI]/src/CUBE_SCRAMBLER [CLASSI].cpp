#include <iostream>
#include <ctime>
using namespace std;


bool in(string elem, string arr[], int length = 2) {
	for(int i = 0; i < length; i++) {
		if(arr[i] == elem) {
			return 1;
	}	}
	return 0;
}



#define err 0;

class puzzle {
public:
	string n_moves;
	int moves{}, scrmbls{}, count = 1, pzl{};
};



class c3 : public puzzle {
	string sides[3][2] = {{"U","D"}, {"R","L"}, {"F","B"}};
	string sides_ext[6] = {"U","D","R","L","F","B"};
	string signs[3] = {"","'","2"};

public :
	void scramble() {
		srand(time(NULL));
		for(int i = 0; i < scrmbls; i++) {
			string scramble[moves] = {sides_ext[rand()%6] + signs[rand()%3]};

			if(moves > 1) {
				int ind = 2, i_lst;

				while(true) {
					i_lst = rand()%3;
					scramble[1] = sides[i_lst][rand()%2] + signs[rand()%3];
					if(scramble[1].substr(0,1) != scramble[0].substr(0,1)) {
						break;	}
				}
				string lst[2] = {sides[i_lst][0], sides[i_lst][1]};
				string move = lst[rand()%2];

				while(ind < moves) {
					while(!( !(in(scramble[ind-1].substr(0,1),lst)) || (move!=scramble[ind-1].substr(0,1) && in(scramble[ind-1].substr(0,1),lst) && !(in(scramble[ind-2].substr(0,1),lst)) )  ) ) {
						i_lst = rand()%3;
						lst[0] = sides[i_lst][0];
						lst[1] = sides[i_lst][1];
						move = lst[rand()%2];
					}
					scramble[ind++] = move + signs[rand()%3];
				}
			}

			printf("\n\nscramble n. %d\n", count++);
			for(int i = 0; i < moves; i++) {
				cout << scramble[i] << " ";	}
	}	}
};



int main() {

	while(true) {

		string choice;
		unsigned int std_moves[1][2] = {{25,10}};
		cout << "1 - 3x3\n\n - 'x' to stop -\n\nselect puzzle: ";
		cin >> choice;
		if(choice == "x") {
			break;
		}


		puzzle pzl_all;
		try {
			printf(" - 'a' for %d moves, %d scrambles -\nnumber of moves and scrambles: ", std_moves[stoi(choice)-1][0], std_moves[stoi(choice)-1][1]);
			cin >> pzl_all.n_moves;
			if(pzl_all.n_moves == "a") {
				pzl_all.moves = std_moves[stoi(choice)-1][0];
				pzl_all.scrmbls = std_moves[stoi(choice)-1][1];	}
			else {
				pzl_all.moves = stoi(pzl_all.n_moves);
				cin >> pzl_all.scrmbls;	}
		}
		catch (...) {
			cout << "invalid choice or invalid number of moves or scrambles...\n\n";
			continue;
		}


		switch (stoi(choice)) {
		case 1 :
			c3 pzl;
			pzl.moves = pzl_all.moves, pzl.scrmbls = pzl_all.scrmbls;
			pzl.scramble();
		}

		cout << "\n\n\n\n";
}	}
/*
		int n_scrmbls, n_moves;
		unsigned int err = 0, pzzl;
		string choice, moves, scrmbls;
		cout << "1 - 3x3\n\n - 'x' to stop -\n\nselect puzzle: ";
		cin >> choice;
		if(choice == "x"){
			break;	}

		try {
			pzzl = stoi(choice);
			if(pzzl < 1 || pzzl > 1) {
				throw err;	}

			printf("\n - 'a' for %d moves, %d scrambles -\nnumber of moves: ", std_moves[pzzl-1][0], std_moves[pzzl-1][1]);
			cin >> moves;
			if(moves == "a") {
				n_moves = std_moves[pzzl-1][0];
				n_scrmbls = std_moves[pzzl-1][1];
			}
			else {
				n_moves = stoi(moves);
				cout << "\nnumber of scrambles: ";
				cin >> scrmbls;
				n_scrmbls = stoi(scrmbls);
			}
		}
		catch(...) {
			cout << "\ninvalid choice or number of moves...\n\n\n";
			continue;
		}

*/
