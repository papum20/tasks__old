#include <iostream>
using namespace std;

struct persona{
	string n, c;
	int e;
};

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	persona a, b, c;
	cin >> a.n >> a.c >> a.e;
	cin >> b.n >> b.c >> b.e;
	cin >> c.n >> c.c >> c.e;
	cout << (a.e+b.e+c.e)/3;


}
