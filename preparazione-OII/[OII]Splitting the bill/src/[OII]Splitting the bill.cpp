#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int N, M, n_transfers = 0;
struct lending{
	int A, B, W;	//A lends W to B
};
vector <lending> transfers;


struct debt{
	int A, W;
};

class myClass{
public:
	bool operator() (debt a, debt b){
		if(a.W < b.W)
			return true;
		return false;
	}
};

priority_queue <debt, vector<debt>, myClass> given;
priority_queue <debt, vector<debt>, myClass> received;








int main(){

	cin >> N >> M;

//	lending lendings[M];
	vector <int> countDebts(N, 0);

	for(int i = 0; i < M; i++){
//		cin >> lendings[i].A >> lendings[i].B >> lendings[i].W;
		int A, B, W;	//A lends W to B
		cin >> A >> B >> W;
		countDebts.at(A) -= W;
		countDebts.at(B) += W;
//		countDebts.at(lendings[i].A) -= lendings[i].W;
//		countDebts.at(lendings[i].B) += lendings[i].W;
	}
	for(int i = 0; i < N; i++){
		if(countDebts.at(i) > 0)
			received.push({i,countDebts.at(i)});
		else if(countDebts.at(i) < 0)
			given.push({i,-countDebts.at(i)});
	}


	while(!given.empty())
	{
		n_transfers++;
		if(received.top().W == given.top().W){
			transfers.push_back({received.top().A, given.top().A, given.top().W});
//			cout << received.top().A << " " << given.top().A << " " << given.top().W << "\n";
			received.pop();
			given.pop();
		}
		else if(received.top().W > given.top().W){
			transfers.push_back({received.top().A, given.top().A, given.top().W});
//			cout << received.top().A << " " << given.top().A << " " << given.top().W << "\n";
			debt tmp = {received.top().A,received.top().W-given.top().W};
			received.pop();
			received.push(tmp);
			given.pop();
		}
		else if(received.top().W < given.top().W){
			transfers.push_back({received.top().A, given.top().A, received.top().W});
//			cout << received.top().A << " " << given.top().A << " " << received.top().W << "\n";
			debt tmp = {given.top().A,given.top().W-received.top().W};
			given.pop();
			given.push(tmp);
			received.pop();
		}


	}




	cout << n_transfers << "\n";
	for(auto i:transfers)
		cout << i.A << " " << i.B << " " << i.W << "\n";

/*	while(!given.empty()){
		cout << given.top().A<<" "<<given.top().W<<endl;
		given.pop();
	}
	cout << "\n\n\n";
	while(!received.empty()){
		cout << received.top().A<<" "<<received.top().W<<endl;
		received.pop();
	}
*/






}





/*
#include <iostream>
using namespace std;



bool order(int arr[], int len){
	for(int i = 0; i < len-1; i++){
		if(!(arr[i] <= arr[i+1])){
			return 0;	}	}
	return 1;
}


bool zeros(int arr[], int len){
	for(int i = 0; i < len; i++){
		if(arr[i] != 0){
			return 0;	}	}
	return 1;
}

bool AB(int arr[], int len){
	for(int i = 0; i < len-1; i++){
		if(arr[i] != arr[i+1]){
			return 0;	}	}
	return 1;
}




int main(){
	int N, M, debts = 0;
	cin >> N >> M;

	int debt[3][N-1];
	int people[N];
	for(int i = 0; i < N; i++){
		people[i] = 0;	}
	int lend[3][M];
	for(int i = 0; i < M; i++){
		cin >> lend[0][i] >>  lend[1][i] >> lend[2][i];
		people[lend[0][i]] -= lend[2][i];
		people[lend[1][i]] += lend[2][i];
	}




	if(M < N){
		cout << M << "\n";
		for(int i = 0; i < M; i++){
			cout << lend[1][i] << " " << lend[0][i] << " " << lend[2][i] << "\n";
		}
	}


	else{

		if(AB(lend[0], M)){
			for(int i = 0; i < N; i++){
				if(people[i] == 0 || i == lend[0][0]){
					continue;
				}
				debts++;
			}
			cout << debts << "\n";
			for(int i = 0; i < N; i++){
				if(people[i] == 0 || i == lend[0][0]){
					continue;
				}
				cout << i << " " << lend[0][0] << " " << people[i] << "\n";
			}
		}


		else{

			if(AB(lend[1], M)){
				for(int i = 0; i < N; i++){
					if(people[i] == 0 || i == lend[0][0]){
						continue;
					}
					debts++;
				}
				cout << debts << "\n";
				for(int i = 0; i < N; i++){
					if(people[i] == 0 || i == lend[1][0]){
						continue;
					}
					cout << lend[1][0] << " " << i << " " << abs(people[i]) << "\n";
				}
			}




			else{

				while(!(zeros(people, N))){

					for(int a = 0; a < N-1; a++){
						if(people[a] == 0){
							continue;	}
						for(int b = a+1; b < N; b++){
							if(people[a] == -people[b] && people[b] < 0){
								debt[0][debts] = a;
								debt[1][debts] = b;
							}
							else{
								if(people[a] == -people[b] && people[a] < 0){
								debt[0][debts] = b;
								debt[1][debts] = a;
								}
								else{
									continue;
							}	}
							debt[2][debts++] = abs(people[a]);
							people[a] = 0;
							people[b] = 0;
							break;
					}	}

			/*
					for(int i = 0; i < M; i++){
						if(people[lend[0][i]] != 0 && people[lend[1][i]] != 0){
							debt[0][debts] = lend[1][i];
							debt[1][debts] = lend[0][i];
							debt[2][debts++] = lend[2][i];
							people[lend[1][i]] -= lend[2][i];
							people[lend[0][i]] += lend[2][i];
					}	}
			*
			/*		for(int i = 0; i < N; i++){
						cout<<people[i];
					}
					cout<<"\n";
			*
					for(int a = 0; a < N-1; a++){
						if(people[a] == 0){
							continue;
						}
						for(int b = a+1; b < N; b++){
							int change = ((abs(people[a]) <= abs(people[b]))? abs(people[a]):abs(people[b]));
							if(people[a] < 0 && people[b] > 0){
									people[a] += change;
									people[b] -= change;
									debt[0][debts] = b;
									debt[1][debts] = a;
									debt[2][debts++] = change;
									break;
							}
							if(people[a] > 0 && people[b] < 0){
									people[a] -= change;
									people[b] += change;
									debt[0][debts] = a;
									debt[1][debts] = b;
									debt[2][debts++] = change;
									break;
							}
					}	}

				}


			/*
				//ordine
				int tmp[3];
				while(!(order(debt[2], debts))){
					for(int i = 0; i < debts-1; i++){
						if(debt[2][i] > debt[2][i+1]){
							tmp[0] = debt[0][i];
							tmp[1] = debt[1][i];
							tmp[2] = debt[2][i];
							debt[0][i] = debt[0][i+1];
							debt[1][i] = debt[1][i+1];
							debt[2][i] = debt[2][i+1];
							debt[0][i+1] = tmp[0];
							debt[1][i+1] = tmp[1];
							debt[2][i+1] = tmp[2];
						}
					}
				}
			*


				cout << debts << "\n";
				for(int i = 0; i < debts; i++){
					cout << debt[0][i] << " " << debt[1][i] << " " << debt[2][i] << "\n";
				}

			}	}	}

}
*/
