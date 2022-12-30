#include <iostream>
#include <bits/stdc++.h>
#include "fattoriale"
#include "MCD"
#include "prime_dividers"
using namespace std;




int main() {

	int n, m;
	cin >> n >> m;

	cout << fattoriale(n) << endl;
	cout << mcd(n, m) << endl;

}
