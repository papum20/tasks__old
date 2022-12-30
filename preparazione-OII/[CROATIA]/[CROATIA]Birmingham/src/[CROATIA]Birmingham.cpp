#include <iostream>
#include <cmath>
using namespace std;


bool in(string elem, int len, string list[]){
	for(int k = 0; k < len; k++){
		if(elem == list[k]){
			return 1;	}	}
	return 0;
}


//template <int N>
int index(string elem2, int len2, string list2[][99], int passi){
	for(int j = 0; j < len2; j++){
		if( in(elem2, len2, list2[j]) ){
			float jj=j;
			return ceil(jj/passi);	}
}	}


int main() {
	int houses, roads, know, steps;
	cin >> houses >> roads >> know >> steps;
	string l_know[know], l_roads[roads][2], map[houses][99/*houses-know*/], ok[houses];
	for(int i = 0; i < know; i++) {
		cin >> l_know[i];
		map[0][i] = l_know[i];
		ok[i] = l_know[i];
	}
	for(int i = 0; i < roads; i++) {
		cin >> l_roads[i][0] >> l_roads[i][1];
	}




	int ind_ok = know, ind_map1 = 1;
	while(true){

		int ind_map2 = 0, ind_tmp = 0;
		string tmp[houses-know];
		for(int i = 0; i < roads; i++){
//			cout << i << " "<< ind_ok<< " "<<ind_map1<<ind_map2<<"\n";
			if( in(l_roads[i][0],ind_ok+1,ok) && !(in(l_roads[i][1],ind_ok+1,ok)) ){
				map[ind_map1][ind_map2++] = l_roads[i][1];
				tmp[ind_tmp++] = l_roads[i][1];
//				cout << "OP1  ";
			}
			if( in(l_roads[i][1],ind_ok+1,ok) && !(in(l_roads[i][0],ind_ok+1,ok)) ){
				map[ind_map1][ind_map2++] = l_roads[i][0];
				tmp[ind_tmp++] = l_roads[i][0];
//				cout << "OP2  ";
			}
		}

		for(int c = 0; c < ind_tmp; c++){
			if(!(in(tmp[c], ind_ok+1, ok))){
				ok[ind_ok++] = tmp[c];
		}}

		ind_map1 ++;

		if(ind_ok == houses){
			break;
		}
	}

/*	for(int a = 0; a < houses; a++){
		for(int b = 0; b < 99; b++){
			cout << map[a][b];
		}
		cout << " ";
	}
*/



	for(int i = 1; i <= houses; i++){
		cout << index(to_string(i), houses-know, map, steps) << ( (i != houses)? " ":"");
	}


}


/*
  		for(int i = 0; i < roads; i++){
			cout << i << " "<< ind_ok<< " "<<ind_map1<<ind_map2<<"\n";
			if( in(l_roads[i][0],1,map[ind_map1-1]) && !(in(l_roads[i][1],1,map[ind_map1-1])) ){
				map[ind_map1][ind_map2++] = l_roads[i][1];
				ok[ind_ok++] = l_roads[i][1];
				cout << "OP1  ";
			}
			if( in(l_roads[i][1],1,map[ind_map1-1]) && !(in(l_roads[i][0],1,map[ind_map1-1])) ){
				map[ind_map1][ind_map2++] = l_roads[i][0];
				ok[ind_ok++] = l_roads[i][0];
				cout << "OP2  ";
			}
		}
		/*
 */
/*
for(int i = 0; i < roads; i++){
	cout << i << " "<< ind_ok<< " "<<ind_map1<<ind_map2<<"\n";
	if( in(l_roads[i][0],ind_ok+1,ok) && !(in(l_roads[i][1],ind_ok+1,ok)) ){
		map[ind_map1][ind_map2++] = l_roads[i][1];
		ok[ind_ok++] = l_roads[i][1];
		cout << "OP1  ";
	}
	if( in(l_roads[i][1],ind_ok+1,ok) && !(in(l_roads[i][0],ind_ok+1,ok)) ){
		map[ind_map1][ind_map2++] = l_roads[i][0];
		ok[ind_ok++] = l_roads[i][0];
		cout << "OP2  ";
	}
}
*/
