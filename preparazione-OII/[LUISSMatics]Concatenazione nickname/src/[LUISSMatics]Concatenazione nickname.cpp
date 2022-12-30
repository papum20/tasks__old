//#include <iostream>
//using namespace std;
//
//
//int mx = 0;
//void foo(int pos, string s, int last, int start, int tot)
//{
//	if(pos == s.length()){
//		mx = max(mx, tot);
//		cout<<endl;
//	}
//
//	else{
//		if( s.substr(start, pos-start+1) >= s.substr(last, start-last) ) {
//			cout<<pos+1<< " " ;
//			foo(pos+1, s, start, pos+1, tot+1);
//		}
//		if( (pos-last) >= 3 && (pos-last)%2 == 1 && s.substr(last, (pos-last+1)/2) == s.substr( ((pos-last+1)/2)+1, (pos-last+1)/2 ) ){
//			foo(pos+1, s, ((pos-last+1)/2)+1, pos+1, tot+1);
//			cout<<((pos-last+1)/2)+1<<" " ;
//		}
//		foo(pos+1, s, last, start+1, tot);
//	}
//}
//
//
//
//
//int main(){
//
//	//	freopen("input.txt","r",stdin);
//	//	freopen("output.txt","w",stdout);
//
//	int T;
//	cin >> T;
//
//
//	for(int t = 0; t < T; t++)
//	{
//		string s;
//		cin >> s;
//
//		mx = 0;
//		foo(1, s, 0, 1, 1);
//
//		cout << "Case #" << t+1 << ": " << mx << "\n";
//	}
//
//}








#include <iostream>
using namespace std;




int mx = 0;

void foo(int pos, string s, int last, int start, int start1, int tot)
{
	if(pos == s.length()){
		mx = max(mx, tot);
//		cout<<endl;
	}

	else{
		if(last == -1){
			if(start1 != -1 && s.substr(start1, pos-start1+1) >= s.substr(start, start1-start) ){
//				cout << tot<<"| "<<start<<", "<<pos << ": " << "A" << endl;
				foo(pos+1, s, start, start1, -1, tot+1);
			}
			if( s.substr(pos, 1) >= s.substr(start, pos) ){
//				cout <<tot<<"| "<<start<<", "<< pos << ": " << "B" << endl;
				foo(pos+1, s, start, pos, -1, tot+1);
			}
			else if(start1 == -1 && s[pos] == s[start]){
//				cout <<tot<<"| "<<start<<", "<< pos << ": " << "C" << endl;
				foo(pos+1, s, last, start, pos, tot);
			}
			if( (pos-start) >= 3 && (pos-start)%2 == 1 && s.substr(start, (pos-start+1)/2) == s.substr( start+((pos-start+1)/2), (pos-start+1)/2 ) ){
//				cout <<tot<<"| "<<start<<", "<< pos << ": " << "D" << endl;
				foo(pos+1, s, start, start+((pos-start+1)/2), -1, tot+1);
//				cout<<"B"<<((pos-last+1)/2)+1<<" " ;
			}
			foo(pos+1, s, last, start, start1, tot);
		}

		else{
			if(start1 != -1 && s.substr(start1, pos-start1+1) >= s.substr(start, start1-start) ){
//				cout <<tot<<"| "<<start<<", "<< pos << ": " << "E" << endl;
				foo(pos+1, s, start, start1, -1, tot+1);
			}
			if( s.substr(pos, 1) >= s.substr(start, pos-start) ){
//				cout <<tot<<"| "<<start<<", "<< pos << ": " << "F" << endl;
				foo(pos+1, s, start, pos, -1, tot+1);
			}
			else if(start1 == -1 && s[pos] == s[start]){
//				cout <<tot<<"| "<<start<<", "<< pos << ": " << "G" << endl;
				foo(pos+1, s, last, start, pos, tot);
			}
			if( (pos-start) >= 3 && (pos-start)%2 == 1 && s.substr(start, (pos-start+1)/2) == s.substr( start+((pos-start+1)/2), (pos-start+1)/2 ) && s.substr(start, (pos-start+1)/2) >= s.substr(last, start-last) ){
//				cout <<tot<<"| "<< start<<", "<<pos << ": " << "H" << endl;
				foo(pos+1, s, start, start+((pos-start+1)/2), -1, tot+1);
//				cout<<"B"<<((pos-last+1)/2)+1<<" " ;
			}
			foo(pos+1, s, last, start, start1, tot);
		}
	}
}




int main(){

		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	int T;
	cin >> T;


	for(int t = 0; t < T; t++)
	{
		string s;
		cin >> s;

		mx = 0;
		foo(1, s, -1, 0, -1, 1);

		cout << "Case #" << t+1 << ": " << mx << "\n";
	}

}


