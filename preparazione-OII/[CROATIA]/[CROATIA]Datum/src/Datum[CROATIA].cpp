#include <iostream>
#include <bits/stdc++.h>
using namespace std;


string add_zero(int dat[3]) {
	string date_str[3] = {to_string(dat[0]), to_string(dat[1]), to_string(dat[2])};
	int len[3] = {2, 2, 4};
	for(int i = 0; i < 3; i++) {
		while(date_str[i].length() < len[i]){
			date_str[i] = "0" + date_str[i];
	}	}
	return date_str[0] + date_str[1] + date_str[2];
}


string next_pal(int date[3]) {
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	while(true) {
		if(date[0] < days[date[1]-1] + ((date[1]==2 && date[2]%4==0)? 1:0) ) {
			date[0]++;
		}
		else {
			if(date[1] < 12) {
				date[0] = 1;
				date[1]++;
			}
			else {
				date[0] = 1;
				date[1] = 1;
				date[2]++;
			}
		}

		string day = add_zero(date);
		string day2 = day;
		reverse(day2.begin(), day2.end());
		if(day == day2) {
			return day.substr(0,2) + "." + day.substr(2,2) + "." + day.substr(4,4);
			break;
		}
}	}





int main() {
	int N;
	cin >> N;
	string dates[N];
	for(int i = 0; i < N; i++) {
		cin >> dates[i];
	}


	for(int i = 0; i < N; i++) {
		int date_eee[3] = {stoi(dates[i].substr(0,2)), stoi(dates[i].substr(3,2)), stoi(dates[i].substr(6,4)) };
		cout << next_pal(date_eee) << ".\n";
	}


}
