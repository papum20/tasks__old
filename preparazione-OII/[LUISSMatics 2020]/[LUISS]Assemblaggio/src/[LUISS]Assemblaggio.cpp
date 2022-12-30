#include <iostream>
using namespace std;

/*
bool escl(string elem, string s[], int l){
	for(int b = 0; b < l; b++){
		if(s[b] == "x" || s[b].length() < elem.length() ){continue;	}
		for(int lun = 1; lun < elem.length()-1; lun++){
			for(int i = 0; i < s[b].length() - lun; i++){
				if(elem.substr(0,lun) == s[b].substr(s[b].length()-lun,lun) || elem.substr(elem.length()-lun,lun) == s[b].substr(0,lun) ){
					return 1;
	}	}	}	}
	return 0;
}*/






int main() {
	int T;
	cin >> T;
	int res[T];

	for(int t = 0; t < T; t++){
		int N;
		cin >> N;
		string dna[N];
		for(int i = 0; i < N; i++){
			cin >> dna[i];
		}


		for(int a = 0; a < N-1; a++){
			if(dna[a] == "x"){
				continue;
			}

			for(int b = a+1 ; b < N; b++){

				if(a == b || dna[b] == "x"){
					continue;
				}
				if(dna[a] == "x"){
					break;
				}
				cout << "DNA " << dna[a] << " "<< dna[b] << "\n";	//

				if(dna[a].length() > dna[b].length() ){
					cout << "CASE 1\n";
					for(int l = dna[b].length(); l > 0; l--){

						cout << "L:" << l <<"\n";	//
						cout << dna[a].substr(0, l) << " " << dna[a].substr(dna[a].length()-l, l) << "\n";	//
						cout << dna[b].substr(dna[b].length()-l, l) << " " << dna[b].substr(0, l) << "\n";	//

						if(l == dna[b].length() ){
							for(int i = 0; i < dna[a].length()-l; i++){
								if(dna[b] == dna[a].substr(i, l) ){
									dna[b] = "x";
								}
							}
							if(dna[b] == "x"){
								break;
							}
							continue;
						}

						if(dna[b].substr(0, l) == dna[a].substr(dna[a].length()-l, l) ){
							dna[a] += dna[b].substr(l, dna[b].length()-l);
							dna[b] = "x";
							break;
						}
						else{
							if(dna[b].substr(dna[b].length()-l, l) == dna[a].substr(0, l) ){
								dna[a] = dna[b].substr(0, dna[b].length()-l) + dna[a];
								dna[b] = "x";
								break;
							}
						}
					}
				}

				else{
					cout << "CASE 2\n";

					for(int l = dna[a].length(); l > 0; l--){

						cout << "L:" << l <<"\n";	//
						cout << dna[a].substr(0, l) << " " << dna[a].substr(dna[a].length()-l, l) << "\n";	//
						cout << dna[b].substr(dna[b].length()-l, l) << " " << dna[b].substr(0, l) << "\n";	//


						if(l == dna[a].length() ){
							for(int i = 0; i < dna[b].length()-l; i++){
								if(dna[a] == dna[b].substr(i, l) ){
									dna[a] = "x";
								}
							}
							if(dna[a] == "x"){
								break;
							}
							continue;
						}

						if(dna[a].substr(0, l) == dna[b].substr(dna[b].length()-l, l) ){
							dna[b] += dna[a].substr(l, dna[a].length()-l);
							dna[a] = "x";
							break;
						}
						else{
							if(dna[a].substr(dna[a].length()-l, l) == dna[b].substr(0, l) ){
								dna[b] = dna[a].substr(0, dna[a].length()-l) + dna[b];
								dna[a] = "x";
								break;
							}
						}
					}
				}

			}
		}


		res[t] = 0;
		for(int i = 0; i < N; i++){
			if(dna[i] == "x"){
				continue;
			}
			res[t] += dna[i].length();
		}

	}



	cout << "\n";
	for(int i = 0; i < T; i++){
		cout << "Case #" << i+1 << ": " << res[i] << "\n";
	}
}







/*
		//completamente inclusi
		for(int a = 0; a < N; a++){
			if(dna[a] == "x"){continue;	}
			for(int b = 0; b < N; b++){
				if(dna[a] == "x" || dna[b].length() < dna[a].length() ){continue;	}
				for(int i = 0; i < dna[b].length() - dna[a].length(); i++){
					if(dna[a] == dna[b].substr(i, dna[a].length()) ){
						dna[a] = "x";
		}	}	}	}

/*
		//completamente esclusi
		for(int a = 0; a < N; a++){
			if(dna[a] == "x"){continue;	}
			if(escl(dna[a],dna, N ) ){
				max += dna[a].length();
				dna[a] = "x";
		}	}
*


		for(int a = 0; a < N; a++){
			if(dna[a] == "x"){continue;	}
			int tmp[3] = {0,-1};
			for(int b = 0; b < N; b++){
				if(dna[b] == "x" || dna[b].length() < dna[a].length() ){continue;	}
				for(int lun = 0; lun < dna[a].length(); lun++){
					for(int ind = 0; ind < dna[b].length()-lun; ind++){
						if(dna[a].substr(0,lun) == dna[b].substr(dna[b].length()-lun,lun)){
							if(dna[a].length()-lun > tmp[0]){
								tmp[0] = dna[a].length()-lun;
								tmp[1] = b;
								tmp[2] = 1;
							}
						}
						if(dna[a].substr(dna[a].length()-lun,lun) == dna[b].substr(0,lun) ){
							if(dna[a].length()-lun > tmp[0]){
								tmp[0] = dna[a].length()-lun;
								tmp[1] = b;
								tmp[2] = 2;
							}
						}
					}
				}
			}

			if(tmp[1] == -1){
				continue;
			}
			else{
				if(tmp[2] == 1){
					dna[tmp[1]] += dna[a].substr(dna[a].length()-tmp[0],tmp[0]);
					dna[a] = "x";
				}
				else{
				if(tmp[2] == 2){
					dna[a] += dna[tmp[1]].substr(dna[tmp[1]].length()-tmp[0],tmp[0]);
					dna[a] = "x";
				}
				}	}
		}

		for(int i = 0; i < N; i++){
			if(dna[i] == "x"){continue;	}
			max += dna[i].length();
		}

		res[t] = max;



*/
