#include <iostream>
#include <iomanip>
using namespace std;






int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	int N;
	int64_t E;
	cin >> N >> E;


	double tot = E*1000;
	bool piu = false;

	for(int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;


		if(tmp > 0){
			if(!piu) tot /= E;
			piu = true;
		}
		else{
			if(piu) tot *= E;
			piu = false;
		}
		E += tmp;

		cout << tot/1000<<endl;

	}

	if(piu) tot *= E;


	cout << fixed << setprecision(8) << tot/1000;

}
