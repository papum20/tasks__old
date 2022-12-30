#include <iostream>
#include <set>
#include <vector>
using namespace std;




int N;
bool ok = true;
set <int> used;
vector <int> path1;
vector <int> path2;





void foo(int pos, bool n2){
	if(path1.size() + path2.size() == N) return;

	int f1, f2;
	if(pos%2 == 0){
		f1 = pos/2;
		f2 = (pos+N)/2;
	}
	else{
		f1 = (pos+1)/2;
		f2 = (pos+N+1)/2;
	}

	if(!n2){
		if(used.find(f1) == used.end()){
			used.insert(f1);
			path1.insert(path1.begin(),f1);
			foo(f1,n2);
		}
		else if(f2 != N && used.find(f2) == used.end()){
			used.insert(f2);
			path1.insert(path1.begin(),f2);
			foo(f2,n2);
		}
		else foo(N/2, true);
	}

	else{
		if(used.find(f1) == used.end()){
			used.insert(f1);
			path2.insert(path2.begin(),f1);
			foo(f1,n2);
		}
		else if(f2 != N && used.find(f2) == used.end()){
			used.insert(f2);
			path2.insert(path2.begin(),f2);
			foo(f2,n2);
		}
		else{
			ok = false;
			return;
		}
	}

}







//void foo(int pos){
//	cout << pos << "\n ";
//	if(used.size() == N){
//		ok = true;
//		return;
//	}
//
//	int tmp = (pos*2)%N;
//	if(tmp < 0) tmp += N;
////	cout <<tmp;
//	if(used.find(tmp) == used.end()){
//		used.insert(tmp);
//		path.push_back(tmp);
//		foo(tmp);
//		if(ok) return;
//		used.erase(tmp);
//		path.erase(path.begin()+path.size()-1);
//	}
//
//	tmp = (pos*2-1)%N;
//	if(tmp < 0) tmp += N;
//	if(used.find(tmp) == used.end()){
//		used.insert(tmp);
//		path.push_back(tmp);
//		foo(tmp);
//		if(ok) return;
//		used.erase(tmp);
//		path.erase(path.begin()+path.size()-1);
//	}
//
//}









int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;




	for(int t = 0; t < T; t++)
	{
		cin >> N;

		if(N == 4){
			cout << "Case #" << t+1 << ": "<<"3, 1, 2, 0\n";
			continue;
		}



		used.clear();
		path1.clear();
		path2.clear();
		used.insert(0);
		used.insert(1);
		used.insert(2);
		used.insert(N/2);
		used.insert(N/2+1);
		used.insert(N-1);
		path1.push_back(N/2+1);
		path1.push_back(1);
		path1.push_back(2);
		path2.push_back(N/2);
		path2.push_back(0);
		path2.push_back(N-1);


		foo(N/2+1,false);



//		for(auto i:path1) cout << i << " ";
//		cout << endl;
//
//		for(auto i:path2) cout << i << " ";
//		cout << endl;



		if(ok){
			ok = false;
			for(int a = 0; a < path2.size(); a++){
				int b = (a == 0)? (path2.size()-1):(a-1);
//				cout <<"AB  "<< a << " "<< b <<endl;
				int a1 = path2[a], b1 = (path2[b]*2)%N, b2 = (path2[b]*2-1)%N;
				if(b1 < 0) b1 += N;
				if(b2 < 0) b2 += N;
//				cout << a1 << " " << b1 << " " << b2 << endl;

				for(int i = 0; i < path1.size(); i++){
					int j = (i==path1.size()-1)?0:(i+1);
//					cout << "IJ  "<<i << " "<<j<<endl;
					int i1 = (path1[i]*2)%N, i2 = (path1[i]*2-1)%N, j1 = path1[j];
					if(i1 < 0) i1 += N;
					if(i2 < 0) i2 += N;
//					cout << i1 << " " <<i2 << " " <<j1 << endl;
					if( (a1 == i1 || a1 == i2) && (b1 == j1 || b2 == j1) ){
						path1.insert( path1.begin()+i+1, path2.begin(), path2.end() );
						ok = true;
						break;
					}
				}

				if(ok) break;
			}
		}




		if(!ok) cout << "Case #" << t+1 << ": -1" << endl;
		else{
			cout <<  "Case #" << t+1 << ": ";
			for(int i = 0; i < N; i++){
				cout << path1[i];
				if(i != N-1) cout << ", ";
			}
			cout << "\n";
		}

	}


}

















//#include <iostream>
//#include <set>
//#include <vector>
//using namespace std;
//
//
//
//
//int N;
//bool ok = false;
//set <int> used;
//vector <int> path;
//
//
//void foo(int pos){
//	cout << pos << "\n ";
//	if(used.size() == N){
//		ok = true;
//		return;
//	}
//
//	int tmp = (pos*2)%N;
//	if(tmp < 0) tmp += N;
////	cout <<tmp;
//	if(used.find(tmp) == used.end()){
//		used.insert(tmp);
//		path.push_back(tmp);
//		foo(tmp);
//		if(ok) return;
//		used.erase(tmp);
//		path.erase(path.begin()+path.size()-1);
//	}
//
//	tmp = (pos*2-1)%N;
//	if(tmp < 0) tmp += N;
//	if(used.find(tmp) == used.end()){
//		used.insert(tmp);
//		path.push_back(tmp);
//		foo(tmp);
//		if(ok) return;
//		used.erase(tmp);
//		path.erase(path.begin()+path.size()-1);
//	}
//
//}
//
//
//
//
//
//
//int main(){
//
////	freopen("input.txt","r",stdin);
////	freopen("output.txt","w",stdout);
//
//
//	int T;
//	cin >> T;
//
//
//
//
//	for(int t = 0; t < T; t++)
//	{
//		cin >> N;
//
//
//		for(int i = N/2; i < N; i++){
//			cout << "A"<<endl;
//			used.clear();
////			cout << "B"<<endl;
////			used.insert(1);
////			cout << "C"<<endl;
////			cout << used.size();
////			cout << "D"<<endl;
//			path.clear();
////			cout << "E"<<endl;
////			cout << path.size();
////			cout << "F"<<endl;
//			used.insert(i);
////			cout << "G"<<endl;
//			path.push_back(i);
////			cout << "H"<<endl;
////			cout << used.size() << path.size();
////			cout << "I"<<endl;
//			ok = false;
////			cout << i<<endl;
//			foo(i);
////			cout <<"J"<<endl;
//			if(ok) break;
//		}
//
//		if(!ok) cout << "Case #" << t+1 << ": -1";
//		else{
//			cout <<  "Case #" << t+1 << ": ";
//			for(int i = 0; i < N; i++){
//				cout << path[i];
//				if(i != N-1) cout << ", ";
//			}
//		}
//
//	}
//
//
//}
