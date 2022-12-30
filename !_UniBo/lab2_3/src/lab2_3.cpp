#include <iostream>
using namespace std;


int main()
{
	int x, y;
	cin >> x >> y;





	double res = (int)(x/y);
	int div = 10;

	int tmp_x = x % y;

	for(int i = 0; i < 10; i++)
	{
		tmp_x *= 10;
		int tmp_res = tmp_x / y;
		res += (double)tmp_res / div;
		div *= 10;
		cout << tmp_x << " " <<tmp_res<<endl;
	}


	cout << res;

}
