#include <iostream>
//using namespace std;

int main(){
std::ios::sync_with_stdio(false);
int H0, M0, H1, M1;
std::cin >> H0 >> M0 >> H1 >> M1;

int t = (H0<=H1 && !(H0==H1 && M0>M1) )? (60*(H1-H0) + M1-M0) : (H1*60+M1 + 60*(24-H0)-M0);
std::cout << t/60 << " " << t%60;

}
