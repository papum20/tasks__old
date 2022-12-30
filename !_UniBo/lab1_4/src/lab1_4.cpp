#include <iostream>
using namespace std;


int main()
{
	int dist, h, min, s;	//metri
	cin >> dist >> h >> min >> s;

	int tot_time = h*3600 + min*60 + s;
	cout << "km/h: " << (float)dist/tot_time*3.6 << endl;
	cout << "miglia/minuto: " << (dist/1000/1.61)/(tot_time/60) << endl;
	cout << "miglia/h: " << (dist/1.61)/tot_time*3.6;
}
