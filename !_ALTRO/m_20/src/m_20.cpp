#include <iostream>
#include <set>
using namespace std;



int res = 0;
int n = 0;

set<int> used;
int grid[3][3];


void f(int y, int x)
{

	if(x < 2)
	{
		for(int i = 1; i <= 9; i++)
		{
			if(used.find(i) == used.end())
			{
				grid[y][x] = i;
				used.insert(i);
				f(y, x+1);
				used.erase(i);
			}
		}
	}
	else
	{
		for(int i = 1; i <= 9; i++)
		{
			if(used.find(i) == used.end())
			{
				grid[y][x] = i;
				used.insert(i);

				if(y < 2)
				{
					f(y+1, 0);
				}
				else
				{



					int r = 100;	//PIU PICCOLO DEI PIU GRANDI
					for(int riga = 0; riga < 3; riga++)
					{
						int r_tmp = 0;

						for(int pos = 0; pos < 3; pos++)
						{
							r_tmp = max(r_tmp, grid[riga][pos]);
							//cout<<"RIGA, COL" << riga << ", "<<pos<<": " <<r_tmp<<endl;
						}
						r = min(r, r_tmp);
						//cout<<r<<endl;
					}

					int c = 0;	//PIU GRANDE DEI PIU PICCOLI

					for(int col = 0; col < 3; col++)
					{
						int c_tmp = 100;

						for(int pos = 0; pos < 3; pos++)
						{
							c_tmp = min(c_tmp, grid[pos][col]);
							//cout<<"RIGA, COL" << pos << ", "<<col<<": " <<c_tmp<<endl;
						}
						c = max(c, c_tmp);
						//cout<<c<<endl;
					}

					n++;
					if(r <= c && c <= 4)
					{
						res++;
						for(int a = 0; a < 3; a++)
						{
							for(int b = 0; b < 3; b++)
							{
								cout<<grid[a][b];
							}
							cout<<endl;
						}
					}

				}

				used.erase(i);
			}
		}
	}
}




int main()
{

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			grid[i][j] = 0;
		}
	}



	f(0, 0);

	cout << res<<" "<<n;


}
