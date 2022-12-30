#include <iostream>
#include <math.h>
#include <ctime>
#include <chrono>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include<bits/stdc++.h>
using namespace std;









int main() {

	std::ios::sync_with_stdio(false);




	//RANDOM

//	freopen("output.txt","w",stdout);
//	int n = 100;
//	srand(time(NULL));
//	for(int i = 0; i < n; i++){
//		uint64_t tmp = (rand()+(int)pow(10,10)) %(int)pow(10,18) + (int)pow(10,10);
//		cout << tmp << " ";
//	}


	//MULTISET

//	struct chain{
//		int len, last;
//
//		auto operator==(const chain &a){
//			return len == a.len && last == a.last;
//		};
////		auto operator>(const chain &a){
////			return len > a.len;
////		};
//
//	};
//
//	auto byLen = [](const chain &a, const chain &b){
//		return a.len > b.len;
//	};
//	auto dp = multiset <chain, decltype(byLen)> (byLen);
//
////	 <chain> dp;
//
//
//	dp.insert({1,2});
//	dp.insert({2,3});
//	dp.insert({1,1});
//	for(auto i:dp)
//		cout<<i.len<<i.last<<endl;




}




	//CLOCK

/*
	auto start = chrono::system_clock::now();

	cout << clock();
	clock_t before = clock(), after;


	int a = 0;
	while(a < 100){
		cout << a++ << "\n";
	}

	after = clock();
	printf("clocks: \n%f",(double)(after-before)/(CLOCKS_PER_SEC));
	cout << "\n\n\n" << clock();

	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "E: " << elapsed.count();
*/
#include <bits/stdc++.h>
