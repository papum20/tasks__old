#include <iostream>
#include <set>
using namespace std;



int a[2][5];
int tot = 0;
set<int> used;


void f(int x,int y)
{
	for(int c = 0; c < 2; c++){
		for(int b = 0; b < 5; b++){
			cout<<a[b][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;



	for(int i = 7; i >=1; i--)
	{
		if(used.find(i) != used.end())
			continue;

		if( ((y==0) || (y==1 && i>a[0][x])) && ( (x==0) || (x==1 && i>a[y][0]) || (x==2 && i>a[y][1]) ||(x==3 && i<a[y][2]) || (x==4 && i<a[y][3]) ) )
		{

			a[y][x] = i;
			used.insert(i);

			if(x<4)
				f(x+1,y);
			else if(y==0)
				f(0,1);
			else{
				tot++;
				for(int c = 0; c < 2; c++){
					for(int b = 0; b < 5; b++){
						cout<<a[b][c]<<" ";
					}
					cout<<endl;
				}
				cout<<endl;
			}

			used.erase(i);
			a[y][x] = 0;

		}


	}

}






int main()
{
	for(int i = 0; i <2;i++){
		for(int j = 0; j<5;j++){
			a[i][j] = 0;
		}
	}

	a[0][2] = 10;
	a[0][3] = 9;
	a[0][4] = 8;

	used.insert(10);
	used.insert(9);
	used.insert(8);



	f(0,0);
	cout<<tot;


}
