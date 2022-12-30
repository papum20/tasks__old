#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main(){
	unordered_map <string,string> decoder(11);
	int n;
	cin >> n;
	string codes[n];

/*	queue <string> codes;

	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		codes.push(tmp);
	}
*/

	for(int i = 0; i < n; i++){
		cin >> codes[i];
	}

	for(int i = 0; i < 10; i++){
		string tmp;
		cin >> tmp;
		decoder[tmp] = to_string(i);
	}
	decoder["end"] = "x";



	for(int t = 0; t < n; t++){
		string code = codes[t], res = "";
//		string code = codes.front(), res = "";
		int i = 0;
		while(i < code.length()){
			for(int l = 1; l <= code.length() - i; l++){
				if(decoder.find(code.substr(i, l)) != decoder.end() ){
					res += decoder[code.substr(i, l)];
//					cout << res << " " << code.substr(i,l) << "\n";
					i += l;
					break;
			}	}
		}

		cout << res << "\n";
//		codes.pop();
	}
}
