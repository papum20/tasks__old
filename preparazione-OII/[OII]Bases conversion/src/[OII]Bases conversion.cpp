//aumento di uno alla volta entrambi, conservando i risultati


#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;




int numberOfSpecials = 1;

int sumTwo = 1, sumThree = 1;
unordered_map <int, int> two;
unordered_map <int, int> three;


auto minor = [](const int& a, const int& b){
	return a > b;
};
priority_queue <int, vector<int>, decltype(minor)> numbers(minor);



//done once
void baseTwo(int pos){
	if(two[pos] == 0){
		two[pos] = 1;
		sumTwo++;
	}
	else{
		two[pos] = 0;
		sumTwo--;
		baseTwo(pos+1);
	}
}


//done N-last times, recalling baseTwo()
void baseThree(int pos, int number, int upTo){
	if(number > upTo) return;
	if(three[pos] < 2){
		three[pos]++;
		baseTwo(0);
//		cout<<endl<<"TWO: ";
//		for(int i = 0; i < two.size(); i++) cout<<two[i];
//		cout<<endl;
//		for(int i = 0; i < three.size(); i++) cout<<three[i];
//		cout<<endl;
		if(++sumThree == sumTwo){
//			cout<<sumThree<<sumTwo<<endl;
			numberOfSpecials++;
		}
		baseThree(0, number+1, upTo);
	}
	else{
		three[pos] = 0;
		sumThree -= 2;
		baseThree(pos+1, number, upTo);
	}
}







int main()
{
	int T;
	cin >> T;

	vector <int> N(T,0);


	two[0] = 1;
	three[0] = 1;


	for(int i = 0; i < T; i++){
		cin >> N[i];
		numbers.push(N[i]);
	}




	unordered_map <int, int> solutions;
	solutions[1] = 1;
	int last = 2;

	while(!numbers.empty())
	{
		if(numbers.top() == 1){
			numbers.pop();
			continue;
		}
		baseThree(0, last, numbers.top());
		last = numbers.top()+1;
		solutions[numbers.top()] = numberOfSpecials;
		numbers.pop();
	}


	for(auto i:N) cout << solutions[i] << " ";


}













//vector<solution> N, senza unordered_map<int,int> solutions
////aumento di uno alla volta entrambi, conservando i risultati
//
//
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <queue>
//#include <set>
//using namespace std;
//
//
//
//
//int numberOfSpecials = 1;
//
//int sumTwo = 1, sumThree = 1;
//unordered_map <int, int> two;
//unordered_map <int, int> three;
//
//struct xqueue{
//	int number, index;
//};
//struct number{
//	int number, solution;
//};
//auto minor = [](const xqueue& a, const xqueue& b){
//	return a.number > b.number;
//};
//priority_queue <xqueue, vector<xqueue>, decltype(minor)> numbers(minor);
//
//
//
////done once
//void baseTwo(int pos){
//	if(two[pos] == 0){
//		two[pos] = 1;
//		sumTwo++;
//	}
//	else{
//		two[pos] = 0;
//		sumTwo--;
//		baseTwo(pos+1);
//	}
//}
//
//
////done N-last times, recalling baseTwo()
//void baseThree(int pos, int number, int upTo){
//	if(number > upTo) return;
//	if(three[pos] < 2){
//		three[pos]++;
//		baseTwo(0);
////		cout<<endl<<"TWO: ";
////		for(int i = 0; i < two.size(); i++) cout<<two[i];
////		cout<<endl;
////		for(int i = 0; i < three.size(); i++) cout<<three[i];
////		cout<<endl;
//		if(++sumThree == sumTwo){
////			cout<<sumThree<<sumTwo<<endl;
//			numberOfSpecials++;
//		}
//		baseThree(0, number+1, upTo);
//	}
//	else{
//		three[pos] = 0;
//		sumThree -= 2;
//		baseThree(pos+1, number, upTo);
//	}
//}
//
//
//
//
//
//
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	vector <number> N;
//
//
//	two[0] = 1;
//	three[0] = 1;
//
//
//	for(int i = 0; i < T; i++){
//		int tmp;
//		cin >> tmp;
//		N.push_back({tmp, 0});
//		numbers.push({tmp,i});
//	}
//
//
//
//	int last = 2;
//
//	while(!numbers.empty())
//	{
//		if(numbers.top().number == 1){
//			N[numbers.top().index] = {1, 1};
//			numbers.pop();
//			continue;
//		}
//		baseThree(0, last, numbers.top().number);
//		last = numbers.top().number+1;
//		N[numbers.top().index] = {numbers.top().number, numberOfSpecials};
//		numbers.pop();
//	}
//
//
//	for(auto i:N) cout << i.solution << " ";
//
//
//}




































////li faccio tutti, conservando i risultati
//
//
//#include <iostream>
//#include <unordered_map>
//#include <cmath>
//using namespace std;
//
//
//
//
//int T;
//unordered_map <int, int> specials;
//
//
//
//
//
//
//int sumTwo(int n)
//{
////	cout << "TWO"<<n<<endl;
//	if(n == 0) return 0;
////	cout << n <<";"<<(int)(log(n)/log(2))<<","<<pow(2,(int)(log(n)/log(2)) )<<endl;
//	return 1+sumTwo(n-pow(2,(int)(log(n)/log(2)) )  );
//}
//
//
//int sumThree(int n)
//{
////	cout<<"THREE"<<n<<endl;
//	if(n == 0) return 0;
//	int power = pow(3,(int)(log(n)/log(3)) );
//	return (n/power) + sumThree(n%power);
//}
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
//	cin >> T;
//	specials[1] = 1;
//
//
////	int lastSpecial = 1;
//	int ind = 2;	//new index
//
//	for(int n = 0; n < T; n++)
//	{
//		int N;
//		cin >> N;
//
////		cout<<"N: "<<N<<endl;
//
//
//		if(N <= specials[ind-1])
//		{
//			for(int i = ind-1; i > 0; i--){
////				cout << "OAJF"<<i << " " <<specials[i]<<endl;;
//				if(N >= specials[i]){
//					cout << i << " ";
//					break;
//				}
//			}
//		}
//		else
//		{
//			int b = specials[ind-1]+1;
////			cout <<"B"<< b<<endl;
//			while(b <= N)
//			{
////				cout<<endl;
//				if(sumTwo(b) == sumThree(b))//{
//					specials[ind++] = b;//cout<<"OLE"<<b<<endl;}
//				b++;
//			}
//
//			cout << ind-1 << " ";
//		}
//
//
//	}
//
////	cout<<endl;
////	for(int i = 1; i < ind; i++) cout << specials[i]<<" ";
//
//
//
//}
