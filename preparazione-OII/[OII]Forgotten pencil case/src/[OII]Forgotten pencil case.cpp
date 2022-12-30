#include <iostream>
using namespace std;



int n, tot = 0, pens = 0;
bool needed = false;




int main(){

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;


		if(!needed)
		{
			if(tmp == 1)
				pens = 0;
			else if(tmp > 1)
				pens = 1;
			else if(tmp == 0){
				if(i == n - 1 && pens < 1)
					tot++;
				else if(pens == 0)
					needed = true;
				pens = 0;
			}
		}
		else
		{
			if(tmp == 1){
				tot++;
				pens = 0;
				needed = false;
			}
			else if(tmp == 2){
				pens = 0;
				needed = false;
			}
			else if (tmp > 2){
				pens = 1;
				needed = false;
			}
			else if(tmp == 0){
				tot++;
				if(i == n - 1)
					tot++;
				pens = 0;
			}

		}

	}


	cout << tot;

}
