#include <iostream>
using namespace std;



int N;
char mp[100][100];
int mn[100][100];
struct coord{
	int y,x;
};
coord directions[8]{ {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1} };





void foo(int y, int x, int len)
{
	if(mn[y][x] <= len) return;
	else mn[y][x] = len;

	if(y == N-1 && x == N-1) return;

	for(int i = 0; i < 8; i++){
		int y1 = y + directions[i].y, x1 = x + directions[i].x;
		if( ( (y1>=0 && y1<N) && (x1>=0 && x1<N) ) && mp[y1][x1] == '*'){
			mp[y][x] = 'x';
			foo(y1, x1, len+1);
			mp[y][x] = '*';
		}
	}

}







int main(){

	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mp[i][j];
			mn[i][j] = 10000;
		}
	}


	foo(0,0,1);
	cout << mn[N-1][N-1];

}
