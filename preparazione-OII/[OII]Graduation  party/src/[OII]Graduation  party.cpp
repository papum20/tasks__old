//MCD a tutti







/*
try every divider of the their mcd
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;





int N;
vector <uint64_t> C;
auto degrow = [](const uint64_t &a, const uint64_t &b){
	return a > b;
};





//uint64_t mcd(uint64_t x, uint64_t y){
//	if(x%y == 0) return y;
//	return mcd(y, x%y);
//}





uint64_t mcdT()	//total, i.e. for more than 2 numbers
{

//	for(auto i:C) cout << i << " ";
//	cout << endl;

	if(C.size() == 1) return C[0];

	sort(C.begin(), C.end(), degrow);

	int len = C.size();
	for(int i = 0; i < len-1; i++){
		uint64_t tmp = C[i]%C[len-1];
		if(tmp != 0) C.push_back(tmp);
	}

	C.erase(C.begin(), C.begin()+len-1);

	return mcdT();
}












set <uint64_t> primes;
unordered_map <uint64_t, int> exponents;

void primeNumbers(uint64_t n, uint64_t div)
{
	if(n==1) return;

	else
	{
		uint64_t rad = sqrt(n);

		for(uint64_t i = div; i <= rad; i+=2){
			if(n%i == 0)
			{
				uint64_t tmp = n;
				while(tmp%i == 0){
					exponents[i]++;
					tmp /= i;
				}
				primes.insert(i);
				primeNumbers(tmp, i+2);
				return;

			}
		}

		exponents[n] = 1;
		primes.insert(n);
		return;
	}

}






set <uint64_t> dividers;

void calcDividers(uint64_t n, set<uint64_t>::iterator it)
{
	if(it == primes.end() ) dividers.insert(n);

	else{
		for(int i = 0; i <= exponents[*it]; i++){
			set<uint64_t>::iterator tmp = it;
			tmp++;
			calcDividers(n*(pow(*it,i) ), tmp);
		}
	}
}











int main()
{

	cin >> N;
	C.resize(N);
	for(int i = 0; i < N; i++) cin >> C[i];
//	uint64_t MCD;
//	cin >> MCD;
//	for(int i = 1; i < N; i++){
//		uint64_t tmp;
//		cin >> tmp;
//		MCD = mcd(MCD, tmp);
//	}



	uint64_t MCD = mcdT();


	if(MCD == 1) cout << 1;

	else{
		if(MCD%2 == 0) primes.insert(2);
		while(MCD%2 == 0){
			MCD /= 2;
			exponents[2]++;
		}

		primeNumbers(MCD, 3);
		calcDividers(1, primes.begin() );

		for(auto i:dividers) cout << i << " ";
	}


}

























//MCD a 2 a 2

///*
//try every divider of the their mcd
// */
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <set>
//#include <cmath>
//using namespace std;
//
//
//
//
//
//int N;
////vector <uint64_t> C;
//auto degrow = [](const uint64_t &a, const uint64_t &b){
//	return a > b;
//};
//
//
//
//
//
//uint64_t mcd(uint64_t x, uint64_t y){
//	if(x%y == 0) return y;
//	return mcd(y, x%y);
//}
//
//
//
//
//
////uint64_t mcdT()	//total, i.e. for more than 2 numbers
////{
////	sort(C.begin(), C.end(), degrow);
////	for(auto i:C) cout << i << " ";
////	cout << endl;
////
////	if(C.size() == 1) return C[0];
////
////
////
////	int len = C.size();
////	for(int i = 1; i < len; i++){
////		uint64_t tmp = C[0]%C[i];
////		if(tmp != 0) C.push_back(tmp);
////	}
////
////	C.erase(C.begin(), C.begin()+len-1);
////
////	return mcdT();
////}
//
//
//
//
//
//
//
//
//
//
//
//
//set <uint64_t> primes;
//unordered_map <uint64_t, int> exponents;
//
//void primeNumbers(uint64_t n, uint64_t div)
//{
//	if(n==1) return;
//
//	else
//	{
//		uint64_t rad = sqrt(n);
//
//		for(uint64_t i = div; i <= rad; i+=2){
//			if(n%i == 0)
//			{
//				uint64_t tmp = n;
//				while(tmp%i == 0){
//					exponents[i]++;
//					tmp /= i;
//				}
//				primes.insert(i);
//				primeNumbers(tmp, i+2);
//				return;
//
//			}
//		}
//
//		exponents[n] = 1;
//		primes.insert(n);
//		return;
//	}
//
//}
//
//
//
//
//
//
//set <uint64_t> dividers;
//
//void calcDividers(uint64_t n, set<uint64_t>::iterator it)
//{
//	if(it == primes.end() ) dividers.insert(n);
//
//	else{
//		for(int i = 0; i <= exponents[*it]; i++){
//			set<uint64_t>::iterator tmp = it;
//			tmp++;
//			calcDividers(n*(pow(*it,i) ), tmp);
//		}
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
//int main()
//{
//
//	cin >> N;
////	C.resize(N);
////	for(int i = 0; i < N; i++) cin >> C[i];
//	uint64_t MCD;
//	cin >> MCD;
//	for(int i = 1; i < N; i++){
//		uint64_t tmp;
//		cin >> tmp;
//		MCD = mcd(MCD, tmp);
//	}
//
//
//
////	uint64_t MCD = mcdT();
//
//
//	if(MCD == 1) cout << 1;
//
//	else{
//		if(MCD%2 == 0) primes.insert(2);
//		while(MCD%2 == 0){
//			MCD /= 2;
//			exponents[2]++;
//		}
//
//		primeNumbers(MCD, 3);
//		calcDividers(1, primes.begin() );
//
//		for(auto i:dividers) cout << i << " ";
//	}
//
//
//}
