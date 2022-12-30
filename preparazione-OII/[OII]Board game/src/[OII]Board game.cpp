#include <iostream>
using namespace std;



int N = 120, X = 1000000000;
int board[120][120];
uint64_t tot = 0;
int rowSum[120], columnSum[120];



void calc(int c0, int c1, int r0, int r1){		//row0,row1,column0,column1


	if(r0 < r1 && c0 < c1){
		if(rowSum[r0] >= X){
			for(int x = c0; x < c1; x++)
				columnSum[x] -= board[r0][x];
			calc(c0, c1, r0+1, r1);
			for(int x = c0; x < c1; x++)
				columnSum[x] += board[r0][x];
		}
		if(rowSum[r1-1] >= X){
			for(int x = c0; x < c1; x++)
				columnSum[x] -= board[r1-1][x];
			calc(c0, c1, r0, r1-1);
			for(int x = c0; x < c1; x++)
				columnSum[x] += board[r1-1][x];
		}
		if(columnSum[c0] >= X){
			for(int y = r0; y < r1; y++)
				rowSum[y] -= board[y][c0];
			calc(c0+1, c1, r0, r1);
			for(int y = r0; y < r1; y++)
				rowSum[y] += board[y][c0];
		}
		if(columnSum[c1-1] >= X){
			for(int y = r0; y < r1; y++)
				rowSum[y] -= board[y][c1-1];
			calc(c0, c1-1, r0, r1);
			for(int y = r0; y < r1; y++)
				rowSum[y] += board[y][c1-1];
		}
	}


	tot++;
	if(tot == 1000000007)
		tot = 0;

}



/*
int rowSum(int row, int x0, int x1){
	int sum = 0;
	for(int x = x0; x < x1; x++){
		sum += board[row][x];
	}
	return sum;
}

int columnSum(int column, int y0, int y1){
	int sum = 0;
	for(int y = y0; y < y1; y++){
		sum += board[y][column];
	}
	return sum;
}




void calc(int c0, int c1, int r0, int r1){		//row0,row1,column0,column1

	/*
	cout << c0 << c1 << " " << r0 << r1 << "\n";
	for(int a = r0; a < r1; a++){
		for(int b = c0; b < c1; b++){
			cout << board[a][b]<< " ";
		}cout<<endl;
	}
	cout << endl << endl;
	*

	if(r0 < r1 && c0 < c1){
		if(rowSum(r0, c0, c1) >= X)
			calc(c0, c1, r0+1, r1);
		if(rowSum(r1-1, c0, c1) >= X)
			calc(c0, c1, r0, r1-1);
		if(columnSum(c0, r0, r1) >= X)
			calc(c0+1, c1, r0, r1);
		if(columnSum(c1-1, r0, r1) >= X)
			calc(c0, c1-1, r0, r1);
	}

//	cout << c0 << c1 << " " << r0 << r1 << "\n";


	tot++;
//	cout << "TOT: "<<tot<<endl;
	if(tot == 1000000007)
		tot = 0;

}

*/



int main(){

	cin >> N >> X;

	for(int a = 0; a < N; a++){
			rowSum[a] = 0;
			columnSum[a] = 0;
	}

	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){
			cin >> board[a][b];
			rowSum[a] += board[a][b];
			columnSum[b] += board[a][b];
	}	}


	calc(0, N, 0, N);

	cout << tot;

}
