#include <iostream>
#include <set>
using namespace std;


int tot = 0;
int a[3][3];
set<int> used;


void ricorsiva(int y, int x)
{

	if(y==0 && x == 1)
		ricorsiva(0,2);

	else{
		for(int i = 8; i >=1; i--){
			if(used.find(i) == used.end())
			{
				if((y==0 || a[y-1][x] > i) && ( (x==1 && i > a[y][0]) || (x==0) || (x==2 && a[y][1] > i) ) ){
					used.insert(i);
					a[y][x] = i;

					if(x<2)
						ricorsiva(y,x+1);
					else if(y<2)
						ricorsiva(y+1,0);
					else{
						cout<<endl;
						for(int c = 0; c < 3;c++){
							for(int b = 0; b < 3; b++)
								cout << a[c][b];
							cout<<endl;
						}
						cout<<endl;
						tot++;
					}

					used.erase(i);

				}
			}
		}


	}



}







int main()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			a[i][j] = 0;
	}

	a[0][1] = 9;
	used.insert(9);



	ricorsiva(0,0);

	cout<<tot;

}
