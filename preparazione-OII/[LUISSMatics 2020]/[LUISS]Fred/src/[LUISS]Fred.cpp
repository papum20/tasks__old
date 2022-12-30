#include <iostream>
using namespace std;


int words(string s[], int len){
	int spaces = len;
	for(int a = 0; a < len; a++){
		for(int i = 0; i < s[a].length(); i++){
			if(s[a][i] == ' '){
				spaces++;
	}	}	}
	return spaces;
}


int likesuo(string s[], string name, int n){
	int len = name.length(), his = 0;
	for(int a = 0; a < n; a++){
		if(s[a].length() <= len){
			if(name == s[a]){
				his++;
		}	}
		else{
			for(int i = 0; i < s[a].length()-len; i++){
				if(s[a].substr(i, len) == name){
					his++;
		}	}
	}	}
	return his;
}


int main() {
	int T;
//	cout << "T:\n";	//
	cin >> T;
	string res[T];

	for(int i = 0; i < T; i++){
//		cout << "\ni: "<<i<<" N:\n";//
		int N;
		cin >> N;
//		cout << "n: "<<N<<"\n";//
		int dati[3][N];
		for(int k = 0; k < N; k++){
			dati[0][k] = 0;
			dati[1][k] = 0;
			dati[2][k] = 0;
		}
		string M[2][N];	//user, n post, like
		for(int k = 0; k < N; k++){
			cin >> M[0][k];
		}
		for(int k = 0; k < N; k++){
			cin >> M[1][k];
		}
//		for(int z = 0; z < N; z++){//
//			cout << M[0][z] <<" "<<M[1][z]<<"\n";
//		}


//		cout << "P\n";//
		for(int p = 0; p < N; p++){
			string post[2][stoi(M[1][p])] = {};
			for(int x = 0; x < stoi(M[1][p]); x++){
//				cout << "x: "<<x<<"\n";//
				cin.ignore();
				getline(cin, post[0][x]);
//				cout << post[0][x];
//				cout << "aegw\n";
				getline(cin, post[1][x]);
			}
			cout << "POST"<<post[0][0]<<"-"<<post[1][0]<<"POST";
//			cout << "OK\n";//
			dati[0][p] = words(post[0], stoi(M[1][p]));	//L di parole
			dati[1][p] = words(post[1], stoi(M[1][p])) - likesuo(post[1], M[0][p], stoi(M[1][p]));	//R di like ricevuti
			for(int k = 0; k < stoi(M[1][p]); k++){
				for(int j = 0; j < N; j++){
					dati[2][j] += likesuo(post[1], M[0][j], stoi(M[1][p]));
			}	}
//			cout << "dati: "<<dati[0][p]<< dati[1][p]<<dati[2][p]<<"\n";//
		}

/*		for(int p = 0; p < N; p++){
			cout << "dati: "<<dati[0][p]<< dati[1][p]<<dati[2][p]<<"\n";//
		}	*/

		float max[2] = {0,0};
		for(int k = 0; k < N; k++){
			float tmp = (dati[0][k] * dati[1][k]) / (dati[2][k] + 1);
//			cout <<k<<"K"<< tmp << "   ";//
			if(tmp > max[1]){
				max[0] = k;
				max[1] = tmp;
//				cout << max[0] << " "<< max[1] << "\n";
		}	}
		res[i] = M[0][(int)max[0]];
	}



	cout << "\n";
	for(int i = 0; i < T; i++){
		cout << "Case #" << i+1 << ": " << res[i] << "\n";
	}

}
