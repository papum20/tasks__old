#include <iostream>
using namespace std;



int R = 1000, C = 1000, islands = 0;
int M[1000][1000];



struct coord{
	int y, x;
};
coord directions[4] = {{-1,0},{0,1},{1,0},{0,-1} };
bool island = false;
bool peninsula = false;

void count(int y = 0, int x = 0)
{
	if(M[y][x] == 1){

		if(island == false)
		{
			if(( (y == 0 || y == R-1) || (x == 0 || x == C-1) ))
				peninsula = true;
			else
				islands++;
			island = true;
			M[y][x] = 2;
			for(int d = 0; d < 4; d++){
				if( (y+directions[d].y >= 0 && y+directions[d].y < R) && (x+directions[d].x >= 0 && x+directions[d].x < C) ){
					count(y+directions[d].y, x+directions[d].x);
			}	}
			island = false;
			peninsula = false;
		}

		else if(island == true)
		{
			M[y][x] = 2;
			if(peninsula == false && ( (y == 0 || y == R-1) || (x == 0 || x == C-1) )){
				islands--;
				peninsula = true;
			}
			for(int d = 0; d < 4; d++){
				if( (y+directions[d].y >= 0 && y+directions[d].y < R) && (x+directions[d].x >= 0 && x+directions[d].x < C) ){
					count(y+directions[d].y, x+directions[d].x);
			}	}
		}

	}

	else if(island == true)
		return;




	if(x == C-1 && y == R-1)
		return;
	else if(x == C-1)
		count(y+1, 0);
	else
		count(y, x+1);
}





int main(){

	cin >> R >> C;

	for(int y = 0; y < R; y++)
		for(int x = 0; x < C; x++)
			cin >> M[y][x];



	count();

	cout << islands;

}
