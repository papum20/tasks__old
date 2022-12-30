#include <iostream>
//#include <set>
#include <vector>
#include <unordered_map>
using namespace std;







int tot = 0;
unordered_map <int, vector<int> > posPiatti;



int check1(int person, int pos, int P, int p[]){
	if(person == P) return pos;

	for(auto i:posPiatti[p[person]])
		if(i > pos) return check1(person+1, i, P, p);

	return -1;
}


int check2(int person, int pos, int P, int p[]){
	if(person == -1) return pos;

	if(pos >= 0){
		for(int i = posPiatti[p[person]].size()-1; i >= 0; i--)
			if(posPiatti[p[person]][i] < pos) return check2(person-1, posPiatti[p[person]][i], P, p);
	}

	return -1;
}




long long conta(int S, int s[], int P, int p[])
{
	for(int i = 0; i < S; i++) posPiatti[s[i]].push_back(i);


	int first1 = posPiatti[0][0];
	cout << first1<<endl;
	int last1 = check1(1, first1, P, p);
	cout<<last1<<endl;
	int last2 = posPiatti[p[P-1]][posPiatti[p[P-1]].size()-1];
	cout<<last2<<endl;
	int first2 = check2(P-2, last2, P, p);
	cout<<first2<<endl;


	if(last1 != -1) tot += (first1+1)*(S-last1) + (first2-first1)*(last2-last1) + (first2-first1)*(S-last2);
	else tot += (first1+1);


//	int previous = -1;
//	for(auto i:posPiatti[0])
//	{
//		int last = check(1,i,P,p);
//		if(last != -1){
//			tot += (i-previous)*(S-last);
//			cout << tot << " " << i << last << endl;
//			cout << "("<<i<<"-"<<previous<<")*("<<S<<"-"<<last<<") = "<<((i-previous)*(S-last))<<endl;
//			previous = i;
//		}
//		else break;
//	}

	return tot;
}











//int tot = 0;
//unordered_map <int, set<int> > posPiatti;
//
//
//
//int check(int person, int pos, int P, int p[]){
//	if(person == P) return pos;
//
//	for(auto i:posPiatti[p[person]])
//		if(i > pos) return check(person+1, i, P, p);
//
//	return -1;
//}
//
//
//
//
//long long conta(int S, int s[], int P, int p[])
//{
//	for(int i = 0; i < S; i++) posPiatti[s[i]].insert(i);
//
//	int previous = -1;
//	for(auto i:posPiatti[0])
//	{
//		int last = check(1,i,P,p);
//		if(last != -1){
//			tot += (i-previous)*(S-last);
//			cout << tot << " " << i << last << endl;
//			cout << "("<<i<<"-"<<previous<<")*("<<S<<"-"<<last<<") = "<<((i-previous)*(S-last))<<endl;
//			previous = i;
//		}
//		else break;
//	}
//
//	return tot;
//}









//RICORSIVA LENTISSIMA
//
//int tot = 0;
//unordered_map <int, set<int> > posPiatti;
//
//
//
//bool ricorsiva(int person, int pos, int mn, int mx, int P, int p[]){
//	if(person == P) return true;
//	for(auto i:posPiatti[p[person]]){
//		if(i >= mx) return false;
//		else if(i > pos) return ricorsiva(person+1, i, mn, mx, P, p);
//	}
//	return false;
//}
//
//
//
//long long conta(int S, int s[], int P, int p[])
//{
//	for(int i = 0; i < S; i++) posPiatti[s[i]].insert(i);
//
//
//	for(int i = -1; i < S; i++){
//		for(int j = i; j <= S; j++){
//			if(ricorsiva(0,i,i,j,P,p) ){
//				cout << i << j << endl;
//				tot++;
//			}
//		}
//	}
//
//
//	return tot;
//
//}







//QUELLO VELOCE CHE NON FUNZIONA
//
//long long conta(int S, int s[], int P, int p[])
//{
//	long long tot = 0;
//	int start = 0;
//	unordered_map <int, set<int> > piatti;
//	for(int i = 0; i < S; i++)
//		piatti[s[i]].insert(i);
//
//
//	for(auto i:piatti[p[0]])
//	{
//
//	int last;
//	bool ok = false;
//	int pos = i;
//
//	for(int j = 1; j < P; j++){
//		int pref = p[j];
//		for(auto k:piatti[pref] ){
//			if(k > pos){
//				pos = k;
//				if(j == P-1){
//					ok = true;
//					last = k;
//				}
//				break;
//			}
//		}
//		piatti[pref].erase(piatti[pref].begin(),piatti[pref].find(pos));
////		piatti[pref].erase(piatti[pref].begin());
//	}
//
//
//	if(ok){
//		tot += (i-start+1)*(S-last);
//		start = i+1;
////		piatti[p[0]].erase(piatti[p[0]].begin());
////		cout << i << " "<<last<<endl;
//	}
//	else break;
//
//	}
//
//
//
//	return tot;
//}




//QUELLO DA 63
//
//long long conta(int S, int s[], int P, int p[])
//{
//	long long tot = 0;
//	int start = 0;
//
//	for(int i = 0; i <= S-P; i++)
//	{
//	if(s[i] != p[0]) continue;
//
//	int person = 1, last;
//	bool ok = false;
//	for(int j = i+1; j < S; j++){
//		if(s[j] == p[person]) person++;
//		if(person == P){
//			ok = true;
//			last = j;
//			break;
//		}
//	}
//
//	if(ok){
//		tot += (i-start+1)*(S-last);
//		start = i+1;
//	}
////		cout << i << " "<<last<<endl;
//	else break;
//
//	}
//
//
//
//	return tot;
//}




//QUELLO VECCHIO E DA 13
//
//long long conta(int S, int s[], int P, int p[])
//{
//	long long tot = 0;
//
//	for(int m = 0; m <= S-P; m++)	//quello prima
//	{
//		for(int c = m+P-1; c < S; c++)	//quello dopo
//		{
//			int person = 0;
//			bool ok = false;
//			for(int i = m; i <= c; i++)
//			{
//				if(s[i] == p[person]) person++;
//				if(person == P){
//					ok = true;
//					break;
//				}
//			}
//			if(ok){
//				tot += S-c;
//				break;
//				}
////				cout<<m<<" "<<c<<endl;
////			}
//
//		}
//	}
//
//
//	return tot;
//}






int main(){

	int S, P;
	cin >> S >> P;
	int s[S], p[P];
	for(int i = 0; i < S; i++)
		cin >> s[i];
	for(int i = 0; i < P; i++)
		cin >> p[i];



	cout << conta(S,s,P,p);

}
