#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;




int T;
struct offer{
	int A;	//fibonacci(A)=bugs, B=money offered
	uint64_t B;
};
auto major = [](const offer&a, const offer& b){
	return a.A > b.A;
};
vector <offer> offers;


int fibonacci[25] =
	{
		1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
		89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
		10946, 17711, 28657, 46368, 75025
	};






//unordered_map <int, unordered_map<int, uint64_t>> guadagni;
//
//uint64_t foo(int index, int used, int K, int N)
//{
////	cout << index << " "<<used<<" "<<K<<endl;
//
//	if(index >= N)
//		return 0;
//
//
//	uint64_t res = 0;
//
//
//	if(guadagni[index][used] != 0)
//		return guadagni[index][used];
//
//	else// if(fibonacci[offers[index].A] <= K-used)
//	{
//		int bugs = fibonacci[offers[index].A];
//		for(int i = (K-used)/bugs; i >= 0; i--)
//		{
//			uint64_t earnt = i*offers[index].B;
//			res = max(res, earnt + foo(index+1, used + i*bugs, K, N));
//		}
//
//		guadagni[index][used] = res;
//	}
//
//
//	return res;
//
//}
//
//



unordered_map <int, uint64_t> dp;

uint64_t earning(int room)
{
//	cout<<"N: "<<room<<endl;

	if(dp[room] != 0)
		return dp[room];

	else{
		for(auto i:offers){
			if(fibonacci[i.A] <= room){
				dp[room] = max(
						dp[room],
						earning(room - fibonacci[i.A]) + i.B
					);
//				cout<<room<<": "<<dp[room]<<endl;
			}
		}
//		cout<<endl;

		return dp[room];
	}

}











int main()
{
	cin >> T;


	for(int t = 0; t < T; t++)
	{
		int N, K;
		cin >> N >> K;

		set <int> duplicated;
		unordered_map <int, uint64_t> gains;
		for(int n = 0; n < N; n++){
			int A;
			uint64_t B;
			cin >> A >> B;
			if(A <= 24 && fibonacci[A] <= K){
				duplicated.insert(A);
				gains[A] = max(gains[A], B);
			}
		}

		for(auto n:duplicated)
			offers.push_back({n, gains[n]});




		if(offers.size() == 0){
			cout << 0 << endl;
			continue;
		}



		sort(offers.begin(), offers.end(), major);


		cout << earning(K) << endl;

		offers.clear();
//		guadagni.clear();
		dp.clear();

	}


}


















//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//
//
//
//int T;
//struct offer{
//	int A;	//fibonacci(A)=bugs, B=money offered
//	uint64_t B;
//};
//auto major = [](const offer&a, const offer& b){
//	return a.A > b.A;
//};
//vector <offer> offers;
//
//
//int fibonacci[25] =
//	{
//		1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
//		89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
//		10946, 17711, 28657, 46368, 75025
//	};
//
//
//
//
//
//
//unordered_map <int, unordered_map<int, uint64_t>> guadagni;
//
//uint64_t foo(int index, int used, int K, int N)
//{
////	cout << index << " "<<used<<" "<<K<<endl;
//
//	if(index >= N)
//		return 0;
//
//
//	uint64_t res = 0;
//
//
//	if(guadagni[index][used] != 0)
//		return guadagni[index][used];
//
//	else// if(fibonacci[offers[index].A] <= K-used)
//	{
//		int bugs = fibonacci[offers[index].A];
//		for(int i = (K-used)/bugs; i >= 0; i--)
//		{
//			uint64_t earnt = i*offers[index].B;
//			res = max(res, earnt + foo(index+1, used + i*bugs, K, N));
//		}
//
//		guadagni[index][used] = res;
//	}
//
//
//	return res;
//
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
//int main()
//{
//	cin >> T;
//
//
//	for(int t = 0; t < T; t++)
//	{
//		int N, K;
//		cin >> N >> K;
//
//		set <int> duplicated;
//		unordered_map <int, uint64_t> gains;
//		for(int n = 0; n < N; n++){
//			int A;
//			uint64_t B;
//			cin >> A >> B;
//			if(A <= 24 && fibonacci[A] <= K){
//				duplicated.insert(A);
//				gains[A] = max(gains[A], B);
//			}
//		}
//
//		for(auto n:duplicated)
//			offers.push_back({n, gains[n]});
//
//
//
//
//		if(offers.size() == 0){
//			cout << 0 << endl;
//			continue;
//		}
//
//
//
//		sort(offers.begin(), offers.end(), major);
//
//
//		cout << foo(0, 0, K, offers.size()) << endl;
//
//		offers.clear();
//		guadagni.clear();
//
//	}
//
//
//}



/*

 1
5 11
1 2
2 2
3 5
4 9
5 50

 56


 2
3 10
1 10
4 60
3 40
2 10
1 30
2 40

 130 300

 */











//int lastIndex = 1;
//uint64_t last1 = 1, last2 = 1;	//last2 < last1
//
//void fibonacciCalc(int index, int mx){
//	if(mx == 0 || mx == 1)
//		fibonacci[mx] = 1;
//
//	if(index == mx+1) {
//		fibonacci[mx] = last1;
//		return;
//	}
//	uint64_t tmp = last1;
//	last1 += last2;
//	last2 = last1;
//	fibonacciCalc(index+1, mx);
//}





//unordered_map <int, uint64_t> fibonacci;
//
//void fibonacciCalc(int index, int mx){
//	fibonacci[index] = fibonacci[index-1] + fibonacci[index-2];
//	if(index < mx) fibonacciCalc(index+1, mx);
//}
