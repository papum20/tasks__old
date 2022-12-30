#include <iostream>
using namespace std;



int N, M, tot;
int grid[300][300];
int directions[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };



void delete_island(int y, int x)
{
	for(int i = 0; i < 8; i++){
		int y1 = y+directions[i][0];
		int x1 = x+directions[i][1];

		if(y1 >= 0 && y1 < N && x1 >= 0 && x1 < M && grid[y1][x1] == 1){
			grid[y1][x1] = 0;
			delete_island(y1,x1);
		}
	}

//	if(x < M-1 && grid[y][x+1] == 1){
//		grid[y][x+1] = 0;
//		delete_island(y,x+1);
//	}
//	if(y < N-1 && grid[y+1][x] == 1){
//		grid[y+1][x] = 0;
//		delete_island(y+1,x);
//	}
//	if(x < M-1 && y < N-1 && grid[y+1][x+1] == 1){
//		grid[y+1][x+1] = 0;
//		delete_island(y+1,x+1);
//	}
}




int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int T;
	cin >> T;

	for(int t = 0; t < T; t++)
	{
		cin >> N >> M;
		tot = -1;

		for(int n = 0; n < N; n++){
			for(int m = 0; m < M; m++) cin >> grid[n][m];
		}



		for(int y = 0; y < N; y++){
			for(int x = 0; x < M; x++){
				if(grid[y][x] == 1){
					tot++;
					delete_island(y,x);
				}
			}
		}



		cout <<  "Case #" << t+1 << ": " << tot << endl;
	}

}
