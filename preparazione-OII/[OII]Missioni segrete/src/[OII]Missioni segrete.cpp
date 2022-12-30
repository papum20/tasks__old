#include <iostream>
using namespace std;



int N, n_max = 1;
struct mission{
	int d, s;	//durata, scadenza
};
mission missions[100];
struct mx{
	int mx, e;	//end, max
};
mx maxMissions[100];




void calc(int i)
{

	if(i == N)
		return;

	maxMissions[i] = {1, missions[i].d};
	for(int j = 0; j < i; j++)
	{
		cout <<  missions[i].d << " " << missions[i].s << "    " <<  missions[j].d << " " << missions[j].s << "  "<< maxMissions[j].mx << " " << maxMissions[j].e <<endl;
		if(maxMissions[j].mx +1 > maxMissions[i].mx && maxMissions[j].e + missions[i].d <= missions[i].s){
			maxMissions[i] = {maxMissions[j].mx + 1, maxMissions[j].e + missions[i].d};
			if(maxMissions[i].mx > n_max)
				n_max = maxMissions[i].mx;
		}
	}

	calc(i+1);

}





int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> missions[i].d >> missions[i].s;

	maxMissions[0] = {1, missions[0].d};


	calc(1);

	cout << n_max;

}
