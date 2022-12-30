#include <iostream>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	string gg, hh, mm, ss, ev;
	getline(cin, gg, ';');
	getline(cin, hh, ':');
	getline(cin, mm, ':');
	getline(cin, ss, ';');
	getline(cin, ev);


	cout << "Il giorno " << gg << " alle ore " << hh << ", " << mm << " minuti e " << ss << " secondi c'è: " << ev;

}
