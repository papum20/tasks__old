#include <iostream>
#include <vector>
using namespace std;


int R = 1000, C = 1000, n = 0;
char grid[1000][1000];
vector <int> columns;
vector <int> rows;




void count(int a, int b, int c, int d)
{
	int y0 = rows[a]+1, x0 = columns[b]+1, y1 = rows[c], x1 = columns[d];

	bool safe = false;
	for(int y = y0; y < y1; y++){
		for(int x = x0; x < x1; x++)
			if(grid[y][x] == '@'){
				safe = true;
				break;
			}
		if(safe)
			break;
	}


	if(!safe)
		n++;




	if(x1 < C -1)
		count(a, b+1, c, d+1);
	else if(y1 < R-1)
		count(a+1, 0, c+1, 1);

}





int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> R >> C;

	for(int y = 0; y < R; y++)
		for(int x = 0; x < C; x++)
			cin >> grid[y][x];


	for(int x = 0; x < C; x++)
		if(grid[1][x] == '#')
			columns.push_back(x);

	for(int y = 0; y < R; y++)
		if(grid[y][1] == '#')
			rows.push_back(y);


	for(auto i:rows)
		cout << i;
	cout << endl;
	for(auto i:columns)
		cout << i;
	cout << endl;

	count(0, 0, 1, 1);




	cout << n;

}
