#include <iostream>
#include <cmath>
using namespace std;


int main(){
	int ip1[4], ip2[4];
	uint64_t n1, n2;//,n;

	string tmp;
	for(int i = 0; i < 4; i++){
		getline(cin, tmp, (i == 3)?'\n':'.');
		ip1[i] = stoi(tmp);
	}
	for(int i = 0; i < 4; i++){
		getline(cin, tmp, (i == 3)?'\n':'.');
		ip2[i] = stoi(tmp);
	}

	n1 = ip1[3] + ip1[2]*pow(2,8) + ip1[1]*pow(2,16) + ip1[0]*pow(2,24);
	n2 = ip2[3] + ip2[2]*pow(2,8) + ip2[1]*pow(2,16) + ip2[0]*pow(2,24);
//	n = -(ip1[3] + ip1[2]*pow(2,8) + ip1[1]*pow(2,16) + ip1[0]*pow(2,24) ) + ( ip2[3] + ip2[2]*pow(2,8) + ip2[1]*pow(2,16) + ip2[0]*pow(2,24) );


	cout << (n2 - n1 + 1);//<<(n+1);
}


/*
int main(){
	long long int n = 1;

	string tmp;
	for(int a = 0; a < 2; a++){
		for(int i = 3; i >= 0; i--){
			getline(cin, tmp, (i == 0)?'\n':'.');
			n += (a == 1)? (stoi(tmp)*pow(2,8*i)):-(stoi(tmp)*pow(2,8*i));
		}
	}
	cout << n;
}
*/
