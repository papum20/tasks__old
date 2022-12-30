#include <iostream>
//#include <vector>
//#include <algorithm>
using namespace std;







int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 0; t < T; t++)
	{
		int N;
		int64_t mx = 0,	mn;
		cin >> N;

		int64_t A,B,C;
		cin >> A >> B >> C;

		int64_t Z[N];
		for(int i = 0; i < N; i++){
			cin >> Z[i];
			mx = max(mx,Z[i]);
		}

		mn = mx*(A+B+C);





		int64_t mn1 = Z[0]*A, mn2 = 0, mn3 = 0;

		for(int i = 1; i < N; i++){
			int a = 1;
			int64_t z = Z[i];
//			cout << "i: "<<i << ": " << mn1 << " "<<mn2 << " " <<mn3<<endl;
			if(mn3 != 0 && i-a >= 2) mn3 = min(mn3, mn2 + z*C);
			if(mn2 != 0 && mn3 == 0) mn3 = mn2 + z*C;
			if(mn2 != 0) mn2 = min(mn2, mn1 + z*B);
			if(mn2 == 0) mn2 = mn1 + z*B;
			mn1 = min(mn1, z*A);


			if(mn3 != 0) mn = min(mn, mn3);
		}





//		for(int a = 0; a < N-2; a++){
//			int mn1 = Z[a]*A, mn2 = 0, mn3 = 0;
//
//			for(int i = a+1; i < N; i++)
//			{
////				cout << "i: "<<i << ": " << mn1 << " "<<mn2 << " " <<mn3<<endl;
//				if(mn3 != 0) mn3 = min(mn3, mn2 + Z[i]*C);
//				if(mn2 != 0 == mn3 == 0) mn3 = mn2 + Z[i]*C;
//				if(mn2 != 0) mn2 = min(mn2, mn1 + Z[i]*B);
//				if(mn2 == 0) mn2 = mn1 + Z[i]*B;
//			}
//
//			mn = min(mn, mn3);
//		}





//		for(int a = 0; a < N-2; a++){
//			for(int b = a+1; b < N-1; b++){
//				for(int c = b+1; c < N; c++){
////					cout << mn <<": " << a << " " << b << " " << c<<endl;
//					mn = min(mn, A*Z[a]+B*Z[b]+C*Z[c]);
//				}
//			}
//		}



		cout <<  "Case #" << t+1 << ": " << mn << endl;
	}

}
