#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++)
    {
        int n;
        cin>>n;
        long long min_weight=1e18;
        vector<pair<int,int> >ar(n);
        for(int i=0;i<n;i++)
        {
            long long t1,t2;
            cin>>t1>>t2;
            min_weight=min(min_weight,t1);
            ar[t2]={t1,i};
        }
        long long ris=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
           if(vis[i]||ar[i].second==i)continue;
           int start=i;
           int pos=ar[i].second;
           vis[i]=true;
           //cout<<i<<" ";
           vector<long long>ciclo;
           ciclo.push_back(ar[i].first);
           while(start!=pos)
           {
               if(vis[pos])break;
               vis[pos]=true;
               ciclo.push_back(ar[pos].first);
               pos=ar[pos].second;

           }
           long long somma=0;
           long long minimo=1e18;
            for(long long x:ciclo)
            {
                minimo=min(minimo,x);
                somma+=x;
            }
           somma-=minimo;
           long long scambio=2*(min_weight+minimo)+min_weight*(ciclo.size()-1);
           if(scambio<minimo*(ciclo.size()-1))
           {
               ris+=scambio+somma;
           }
            else ris+=somma+minimo*(ciclo.size()-1);
        }
        cout<<"Case #"<<ca<<": "<<ris<<"\n";



    }
    return 0;
}







/*#include <iostream>
using namespace std;




int T, N;
uint64_t s = 0;

struct mobile{
	int i, j, P;
};
mobile mobili[100000];



/*
bool ordered(){
	for(auto i:mobili){
		if(i.i != i.j)
			return false;
	}
	return true;
}
*




int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> T;


	for(int t = 0; t < T; t++)
	{
		s = 0;

		cin >> N;

		for(int n = 0; n < N; n++){
			int tmp_j, tmp_P;
			cin >> tmp_P >> tmp_j;
			mobili[n] = {n, tmp_j, tmp_P};
//			cout<<(*mobili.begin()).P<<endl;
		}
/*		for(auto i:mobili){
			cout<< i.i<<" " <<i.j<<" " <<i.P<<endl;
		}

		cout<<"\n\n\n\n\n";*

	//	while(!ordered()){
			for(int a = 0; a < N; a++){
				if(mobili[a].i == mobili[a].j)
					continue;

				for(int b = 0; b < N; b++){
					if(mobili[b].i == mobili[a].j){
	//					cout << mobili[a].P<<" "<<mobili[a].i<<mobili[a].j << " - " << mobili[b].P<<" " <<mobili[b].i<<mobili[b].j<<endl;
						mobili[b].i = mobili[a].i;
						mobili[a].i = mobili[a].j;
	//					cout << mobili[a].P<<" "<<mobili[a].i<<mobili[a].j << " - " << mobili[b].P<<" " <<mobili[b].i<<mobili[b].j<<endl;

						s += mobili[a].P + mobili[b].P;
//						mobili.erase(i);
//						if(b.i==b.j)
//							mobili.erase(b);
						break;
					}
				}
//				break;
			}
	//	}

//		order();
		cout << "Case #" << t+1 << ": " << s << "\n";



	}

}



*




#include <iostream>
#include <set>
using namespace std;




int T, N, s = 0;

struct mobile{
	int i, j, P;
};
auto weigth = [](const mobile& a, const mobile& b){
	return a.P > b.P;
};

auto mobili = multiset<mobile, decltype(weigth)> (weigth);



/*
bool ordered(){
	for(auto i:mobili){
		if(i.i != i.j)
			return false;
	}
	return true;
}
*/


/*
std::multiset<mobile, decltype(weigth)>::iterator it = mobili.begin();
void order(int pos)
{
	cout<<(*it).P<<endl;
	std::multiset<mobile, decltype(weigth)>::iterator fine = mobili.end();
	if(it == fine)
		return;

	if( (*it).i == (*it).j ){
		cout<<"A";
		it++;
		order(pos +1);
	}
}
*

std::multiset<mobile, decltype(weigth)>::iterator it;
void order()
{
//	cout << "AFAEOUçKFAE(OF"<<mobili.size()<<endl;
//	cout<<(*it).i<<" "<<(*it).j<<" "<<(*it).P<<"\n ";
//	cout<<(*mobili.begin()).i<<" "<<(*mobili.begin()).j<<" "<<(*mobili.begin()).P<<"\n ";
//	cout<<(*mobili.end()).i<<" "<<(*mobili.end()).j<<" "<<(*mobili.end()).P<<"\n ";

	if(it == mobili.end()){
		cout<<"END";
		return;
	}

	if( (*it).i == (*it).j ){
		it++;
		order();
	}

	cout<<(*it).i<<" "<<(*it).j<<" "<<(*it).P<<"\n ";
	for(std::multiset<mobile, decltype(weigth)>::iterator b = it; b != mobili.end(); b++){
		if( (*b).i == (*it).j ){
			cout<<"BBB"<<(*b).i<<" "<<(*b).j<<" "<<(*b).P<<"\n ";
/*			std::multiset<mobile, decltype(weigth)>::iterator it_i = mobili.find(*next(mobili.begin(),i));
			std::multiset<mobile, decltype(weigth)>::iterator it_b = mobili.find(*next(mobili.begin(),pos));
			(*it_b).i = (*it_i).i;
			(*it_i).i = (*it_i).j;
			s += (*it_i).P + (*it_b).P;*
			s += (*it).P + (*b).P;
			mobili.insert({(*it).i,(*b).j,(*b).P});	//new b
			mobili.erase(*b);
			mobili.insert({(*it).j,(*it).j,(*it).P});	//new b
			mobili.erase(*it);
			it = mobili.begin();
			order();
			break;
		}
	}

}





int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> T;


	for(int t = 0; t < T; t++)
	{
		s = 0;

		cin >> N;

		for(int n = 0; n < N; n++){
			int tmp_j, tmp_P;
			cin >> tmp_P >> tmp_j;
			mobili.insert({n, tmp_j, tmp_P});
//			cout<<(*mobili.begin()).P<<endl;
		}
/*		for(auto i:mobili){
			cout<< i.i<<" " <<i.j<<" " <<i.P<<endl;
		}

		cout<<"\n\n\n\n\n";*/

/*		while(!ordered()){
			for(auto i:mobili){
				if(i.i == i.j)
					continue;

				for(auto b:mobili){
					if(b.i == i.j){
						cout << i.P<<" "<<i.i<<i.j << " - " << b.P<<" " <<b.i<<b.j<<endl;
						b.i = i.i;
						i.i = i.j;
						cout << i.P<<" "<<i.i<<i.j << " - " << b.P<<" " <<b.i<<b.j<<endl;
						s += i.P + b.P;
						mobili.erase(i);
						if(b.i==b.j)
							mobili.erase(b);
						break;
					}
				}
				break;
			}
		}
*
//		order();
		it = mobili.begin();
		order();
		cout << "Case #" << t+1 << ": " << s<<"\n";

		mobili.clear();

	}

}

*/
