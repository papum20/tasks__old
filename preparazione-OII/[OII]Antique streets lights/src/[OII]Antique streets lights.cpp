#include <iostream>
#include <vector>
using namespace std;



int n, m, k;
int lit = 0, tot = 0;



int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> n >> m >> k;
	vector<bool> win;



	for(int i = 1; i <= n; i++)
	{
		cout<<"i: "<<i<<endl;//
		bool tmp;
		cin >> tmp;

		win.push_back(tmp);
		if(tmp)
			lit++;


		if(i >= m)
		{
			cout<<"LIT: "<<lit<<endl;	//
			for(auto o:win)	//
				cout<<o;	//
			cout<<endl;	//


			if(lit < k)
			{
				tot += k - lit;
				int ind = m -1;
				while(lit < k){
					if(!win.at(ind) ){
//						win.erase(win.begin()+ind);
//						win.insert(win.begin()+ind, 1);
						win.at(ind) = 1;
						lit++;
						ind--;
					}
					else
						ind--;
			}	}

			if(*(win.begin()) )
				lit--;
			win.erase(win.begin());

		}


	}



	cout << tot;



}




/*
		else
		{
			cout<<"tmp"<<tmp;//
			cout<<" lit,m,tot"<<lit<<","<<m<<","<<tot<<endl;//
			win.push(tmp);
			if(tmp)
				lit++;

			if(lit < k)
			{
				int tmp_lit = k - lit;
				tot += tmp_lit;
				m += tmp_lit;
				for(int i = 0; i < tmp_lit; i++){
					win.push(1);
					lit++;
					cout<<"  LIT: "<<lit<<endl;//
				}
			}



			if(win.front())
				lit--;
			win.pop();



		/*	if(lit >= k){
				win.push(tmp);
				if(tmp)
					lit++;
				if(win.front())
					lit--;
				win.pop();
			}
			else{
				tot += k - lit;
				for(int i = 0; i < k-lit; i++){
					win.push(1);
					lit++;
				}
			}*

		}*/
