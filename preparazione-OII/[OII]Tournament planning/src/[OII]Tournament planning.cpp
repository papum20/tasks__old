#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;



int N = 100000, M0 = 100000;

struct tournament{
	int D, S, E, B, P;	//day,start,end,buy-in,prize
};

auto chronologic = [](tournament a, tournament b){
	return ( (a.D != b.D)? (a.D < b.D):(a.S < b.S) );
};

auto tournaments = multiset <tournament, decltype(chronologic)>(chronologic);

struct play{
	int E, d, T;	//money(earnt),max money,time
};
unordered_map <int, play> money;//[100000];







int main(){

	cin >> N >> M0;


	int mx = 0, day = -1, n = 0, M = M0;
	for(int i = 0; i < N; i++)
	{
		tournament tmp;
		cin >> tmp.D >> tmp.S >> tmp.E >> tmp.B >> tmp.P;
//		cout<<tmp.D <<">" <<day<<endl;

		if(tmp.D > day)
		{
//			cout<<"NEW" <<n<<"\n";
			std::multiset<tournament>::iterator it = tournaments.begin();
			for(int pos = 0; pos < n; pos++)
			{

				if((*it).B > M+mx){
					money[pos] = {0, (*it).D, (*it).E};
					continue;
				}
				money[pos] = {(*it).P-(*it).B, (*it).D, (*it).E};
				mx = max(mx, money[pos].E);

				for(int i = 0; i < pos; i++){
					if(money[i].E-(*it).B+(*it).P > money[pos].E && M+money[i].E >= (*it).B && (*it).S >= money[i].T ){
		//				cout << "I"<<i;
						money[pos] = {money[i].E-(*it).B+(*it).P, (*it).D, (*it).E};
//						cout<<"AFIOHAFO"<<money[pos].E<<" ";
						mx = max(mx, money[pos].E);
//						cout<<mx<<endl;
					}
				}
//				cout << pos << ": " << money[pos].E << "  " << money[pos].d << " " << money[pos].T << endl;

				it++;
			}

//			cout<<"mx: "<<mx<<endl;
			M += mx;
			tournaments.clear();
			mx = 0;
			n = 0;
			day = tmp.D;
		}



		tournaments.insert(tmp);
		n++;
//		cout<<"M: "<<M<<endl;
	}




//	cout<<"new"<<n<<endl;
	std::multiset<tournament>::iterator it = tournaments.begin();
	for(int pos = 0; pos < n; pos++)
	{

		if((*it).B > M+mx){
			continue;
			money[pos] = {0, (*it).D, (*it).E};
		}
		money[pos] = {(*it).P-(*it).B, (*it).D, (*it).E};
		mx = max(mx, money[pos].E);

		for(int i = 0; i < pos; i++){
			if(money[i].E-(*it).B+(*it).P > money[pos].E && M+money[i].E >= (*it).B && (*it).S >= money[i].T ){
//				cout << "I"<<i;
				money[pos] = {money[i].E-(*it).B+(*it).P, (*it).D, (*it).E};
				mx = max(mx, money[pos].E);
			}
		}
//		cout << pos << ": " << money[pos].E << "  " << money[pos].d << " " << money[pos].T << endl;

		it++;
	}

	M += mx;




//	cout << endl;
//	for(auto i:tournaments)
//		cout << i.D << " " << i.S << " " << i.E << " " << i.B << " " << i.P << endl;


	cout << M;

}
















//#include <iostream>
//#include <set>
//#include <unordered_map>
//using namespace std;
//
//
//
//int N = 100000, M = 100000, mx = 0;
//
//struct tournament{
//	int D, S, E, B, P;	//day,start,end,buy-in,prize
//};
//
//auto chronologic = [](tournament a, tournament b){
//	return ( (a.D != b.D)? (a.D < b.D):(a.S < b.S) );
//};
//
//auto tournaments = multiset <tournament, decltype(chronologic)>(chronologic);
//
//struct play{
//	int M, d, T;	//money(available),max money,time
//};
//unordered_map <int, play> money;//[100000];
//
//
//
//
//
//
//
//int main(){
//
//	cin >> N >> M;
//
//	for(int i = 0; i < N; i++){
//		tournament tmp;
//		cin >> tmp.D >> tmp.S >> tmp.E >> tmp.B >> tmp.P;
//		tournaments.insert(tmp);
//	}
//
//
//
//	if( (*tournaments.begin()).B <= M)
//		money[0] = {M-(*tournaments.begin()).B+(*tournaments.begin()).P, (*tournaments.begin()).D, (*tournaments.begin()).E};
//	else
//		money[0] = {M, 0, 0};
//	mx = max(M, money[0].M);
//
//
//
//	std::multiset<tournament>::iterator it = tournaments.begin();
//	it++;
//	for(int pos = 1; pos < N; pos++)
//	{
//		money[pos] = {M,0,0};
//
//		for(int i = pos-1; i >= -1; i--){
////			if(i == -1)
////				money[pos] = {0, 0, 0};
//			if(money[i].M-(*it).B+(*it).P > money[pos].M && money[i].M >= (*it).B && (money[i].d != (*it).D || (*it).S >= money[i].T) ){
////				cout << "I"<<i;
//				money[pos] = {money[i].M-(*it).B+(*it).P, (*it).D, (*it).E};
//				mx = max(mx, money[pos].M);
//			}
//		}
//		cout << pos << ": " << money[pos].M << "  " << money[pos].d << " " << money[pos].T << endl;
//
//		it++;
//	}
//
//
//	cout << endl;
//	for(auto i:tournaments)
//		cout << i.D << " " << i.S << " " << i.E << " " << i.B << " " << i.P << endl;
//
//
//	cout << mx;
//
//}
