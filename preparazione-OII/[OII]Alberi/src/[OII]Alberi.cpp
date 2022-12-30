#include <iostream>
#include <math.h>
using namespace std;




int in = 0;
void anticipata(int pre[], int norm[], int len, int pos){
if (pos >= len) return;
norm[pos] = pre[in++];
int lg = (int)(log(pos+1)/log(2));
anticipata(pre, norm, len, pow(2,lg+1)+2*(pos+1-pow(2,lg))-1);
anticipata(pre, norm, len, pow(2,lg+1)+2*(pos+1-pow(2,lg)));
}
void simmetrica(int norm[], int simm[], int len, int pos){
if (pos > len) return;
int lg = (int)(log(pos+1)/log(2));
simmetrica(norm, simm, len, pow(2,lg+1)+2*(pos+1-pow(2,lg))-1);
//cout << norm[pos] << endl;
simm[in++] = norm[pos];
simmetrica(norm, simm, len, pow(2,lg+1)+2*(pos+1-pow(2,lg)));
}
//void posticipata(int A[], int len, int pos){
//if (pos > len) return;
//int lg = (int)(log(pos+1)/log(2));
//posticipata(A, len, pow(2,lg+1)+2*(pos+1-pow(2,lg))-1);
//posticipata(A, len, pow(2,lg+1)+2*(pos+1-pow(2,lg)));
//cout << A[pos] << " ";
//}



void visita(int N, int *PRE, int *POST, int *SIMM )
{
	int NORM[N];	//NORMAL
	in = 0;
	anticipata(PRE, NORM, N, 0);
//	cout << endl;
//	for(auto i:NORM) cout << i << " ";
//	cout << endl;
	in = 0;
	simmetrica(NORM, SIMM, N, 0);
//	int in = 0, ip = 0;	//index normal, pre.
//	int end = pow(2, (int)(log(N-1)/log(2))-1) -1;
//	while(ip != end)
//	{
//		NORM[in++] = PRE[ip];
//		int lg = (int)(log(ip+1)/log(2));
//		ip =
//		anticipata(A, len, pow(2,lg+1)+2*(pos+1-pow(2,lg))-1);
//		anticipata(A, len, pow(2,lg+1)+2*(pos+1-pow(2,lg)));
//	}
}




int main(){

	int N;
	cin >> N;
	int pre[N], post[N], simm[N];
	for(int i = 0; i < N; i++) cin >> pre[i];
	for(int i = 0; i < N; i++) cin >> post[i];



	visita(N, pre, post, simm);
	for(auto i:simm) cout << i << " ";

}
