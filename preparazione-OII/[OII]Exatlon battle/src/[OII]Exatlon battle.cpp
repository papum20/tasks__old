#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;




//R=red, A=blue
int N, mxRed = 0, mxBlue = 0;
unordered_map <int, string> board;




//struct horizontal{
//	int len;	//length
//	set<int> x;	//rows
//};
//unordered_map <int, horizontal> lengthPerRow;


int maxArea(char letter)
{
	int mx = 0;
	unordered_map <int, int> horizontal;	//key: row, value: horizontal length



	for(int column = 0; column < N; column++)
	{
//		cout << "COLUMN "<<column<<endl;

		unordered_map <int, int> length;	//key: length, value: number
		int mxLength = 0;

		for(int row = 0; row < N; row++)
		{
//			cout << "ROW "<<row<<endl;
			if(board[row][column] == letter){
//				cout<<row<<"R ";
				horizontal[row]++;
				mxLength = max(mxLength, horizontal[row]);
				length[horizontal[row]]++;
//				for(int i = 1; i <= horizontal[row]; i++)
//					length[i]++;
			}
			else{
//				cout<<row<<"A ";
				horizontal[row] = 0;
			}
		}

//		for(int i = 0; i <N;i++)cout<<horizontal[i]<<" ";
//		cout<<endl;
//		for(int i = 1; i <=mxLength;i++)cout<<i<<":"<<length[i]<<" ";
//		cout<<endl;


		int numberPerLength = 0;
		for(int i = mxLength; i >= 1; i--){
			numberPerLength += length[i];
			mx = max(mx, i*numberPerLength);
		}

	}



	return mx;
}








int main()
{
	cin >> N;

	for(int y = 0; y < N; y++){
		string tmp;
		cin >> tmp;
		board[y] = tmp;
	}




	mxRed = maxArea('R');
	mxBlue = maxArea('A');



	if(mxRed > mxBlue) cout << "1 " << mxRed;
	else if(mxBlue > mxRed) cout << "2 " << mxBlue;
	else cout << "0 " << mxRed;


}





/*

6
RARRRA
RRAARA
RARRRR
AAARAA
RAAARA
RRRRRR

[1 9]


2
RA
AR

[0 1]

 */
