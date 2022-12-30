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



int main() {

	unsigned int std_moves[1][2] = {{25,10}};
	string c3[3][2] = {{"U","D"}, {"R","L"}, {"F","B"}};
	string c3_ext[6] = {"U","D","R","L","F","B"};
	string signs[3] = {"","'","2"};


	while(true) {

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




		srand(time(NULL));
		for(int scrs = 0; scrs < n_scrmbls; scrs++) {

			string scramble[n_moves] = {c3_ext[rand()%6] + signs[rand()%3]};


			if(pzzl == 1 && n_moves > 1) {

				int ind = 2, i_lst;

				while(true) {
					i_lst = rand()%3;
					scramble[1] = c3[i_lst][rand()%2] + signs[rand()%3];
					if(scramble[1].substr(0,1) != scramble[0].substr(0,1)) {
						break;	}
				}
				string lst[2] = {c3[i_lst][0], c3[i_lst][1]};
				string move = lst[rand()%2];


				while(ind < n_moves) {
					while(!( !(in(scramble[ind-1].substr(0,1),lst)) || (move!=scramble[ind-1].substr(0,1) && in(scramble[ind-1].substr(0,1),lst) && !(in(scramble[ind-2].substr(0,1),lst) ))  ) ) {
						i_lst = rand()%3;
						lst[0] = c3[i_lst][0];
						lst[1] = c3[i_lst][1];
						move = lst[rand()%2];
					}
					scramble[ind++] = move + signs[rand()%3];
				}
			}


			printf("\nscramble n. %d\n", scrs+1);
			for(int i = 0; i < n_moves; i++) {
				cout << scramble[i] << " ";	}
			cout << "\n\n";

}	}	}
