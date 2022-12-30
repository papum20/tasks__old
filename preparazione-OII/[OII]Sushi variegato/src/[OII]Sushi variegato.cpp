#include <iostream>
//#include <set>
#include <vector>
#include <unordered_map>
using namespace std;





bool find(int a[], int elem, int start, int end){
	for(int i = start; i < end; i++)
		if(a[i] == elem) return true;
	return false;
}



struct striscia{
	int q, s;	//quantità, start striscia sushi
};


vector <striscia> sushi;


//int taglia(int n, int v[])
//{
//	int tot = 1;
//
//
//	sushi.push_back({1,0});
//
//	for(int piece = 1; piece < n; piece++)
//	{
//		int tmp = sushi.size();
//		int split = 0;
//		for(int strip = 0; strip < tmp; strip++)
//		{
//			if(!find(v, v[piece], sushi[strip].s, piece) ){
//				sushi.push_back({sushi[strip].q, sushi[strip].s});
//				tot += sushi[strip].q;
//				tot %= 1000000007;
//			}
//			split += sushi[strip].q;
//			split %= 1000000007;
//		}
//
//		sushi.push_back({split, piece});	//split%1000000007
//		sushi.erase(sushi.begin(),sushi.begin()+tmp);
//	}
//
//
//	//return tot;
//	return (tot < 0)? ((tot+1000000007)%1000000007):tot;
//}



unordered_map <int, int> last;

int taglia(int n, int v[])
{
	int tot = 1;


	sushi.push_back({1,0});
	last[v[0]] = 0;

	for(int piece = 1; piece < n; piece++)
	{
		int tmp = sushi.size();
		int split = 0;
		for(int strip = 0; strip < tmp; strip++)
		{
			if(last[v[piece]] == 0 && last[v[0]] == 0 && v[piece] != v[0])
				last[v[piece]] = -1;
			if(last[v[piece]] < sushi[strip].s ){
				sushi.push_back({sushi[strip].q, sushi[strip].s});
				tot += sushi[strip].q;
				tot %= 1000000007;
			}
			split += sushi[strip].q;
			split %= 1000000007;
		}

		last[v[piece]] = piece;
		sushi.push_back({split, piece});	//split%1000000007
		sushi.erase(sushi.begin(),sushi.begin()+tmp);
	}


	//return tot;
	return (tot < 0)? ((tot+1000000007)%1000000007):tot;
}





int main(){

	int n;
	cin >> n;
	int v[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];

	cout << taglia(n, v);

}
