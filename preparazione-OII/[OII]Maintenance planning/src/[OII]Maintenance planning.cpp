#include <iostream>
#include <unordered_map>
using namespace std;



int C, D, Y;	//cost, duration, years
unordered_map <int, int> M;
unordered_map <int, int> P;
unordered_map <int, int64_t> dp;


int64_t tot = 0, mn = 0;
int iMn = 1;	//index max



int foo(int y)
{
//	cout<<P[0]<<" ";
//	cout <<"Y: "<<y<<endl<<endl;
//	if(y == 0) return 0;


	mn = M[0] - P[0];
	tot = M[0];
	iMn = 1;


//	cout << "tot: "<<tot<<" "<<P[1]<<" "<<tot-P[1]<<" "<<tot-P[1] + C*(Y/(1+1))<<" "<<mn<<" "<<iMn<<" "<<mn + C*(Y/iMn)<<endl;

	for(int i = 1; i < min(D, y); i++){
		tot += M[i];
//		cout << "tot: "<<tot<<" "<<P[i]<<" "<<tot-P[i]<<" "<<tot-P[i] + C*(Y/(i+1))<<" "<<mn<<" "<<iMn<<" "<<mn + C*(Y/iMn)<<endl;
		if( (tot-P[i] + C)*(y/(i+1)) + dp[y%(i+1)] <= (mn + C)*(y/iMn) + dp[y%iMn] ){
			mn = tot-P[i];
			iMn = i+1;
			cout << mn << " "<<iMn<<endl;;
		}
	}

	cout << y << ": " << (mn+C)*(y/iMn)<<" "<<iMn<<endl;

	return (mn+C)*(y/iMn) + dp[y%iMn];
}




int main(){

	cin >> C >> D >> Y;

	for(int i = 0; i < D; i++){
		int tmp;
		cin >> tmp;
		M[i] = tmp;
	}
	for(int i = 0; i < D; i++){
		int tmp;
		cin >> tmp;
		P[i] = tmp;
//		cout << tmp << P[i]<<endl;
	}
//	cout << P[0];



	//per uno

	for(int i = 1; i <= min(D, Y); i++)
	{
		dp[i] = foo(i);
		cout <<"I: "<< i <<": " << dp[i]<<endl;
//		for(int j = 0; j < i; j++) dp[i] = min(dp[i], dp[j]);
	}


	cout << foo(Y);

}
