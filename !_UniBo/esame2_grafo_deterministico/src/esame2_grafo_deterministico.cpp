#include <iostream>
using namespace std;




struct node {
	double val;
	int next;
};

/*
const int length = 1000;
char used[length];	//0 not used, 1 used in this cycle, 2 = no loop
char loop_check(node A[], int len, int pos)
{
	if(pos == -1 || used[pos] != '0')
	{
		if(pos == -1) used[pos] = '2';
		return used[pos];
	}
	else{
		used[pos] = '1';
		used[pos] = loop_check(A, len, A[pos].next);
		return used[pos];
	}
}
bool loops(node A[], int len)
{
	bool res = true;
	int i = 0;
	do {
		while(used[i] == '2') i++;
		if(i == len) res = false;
	} while(loop_check(A, len, i) != '1' && i < len);
	return res;
}
*/


bool there_are_loops(node A[], int n)
{
	bool loops = false;
	bool used[n];
	for(int i = 0; i < n; i++) used[i] = false;

	int i = 0;
	while(loops == false && i < n)
	{
		if(used[i] == false)
		{
			cout << "START "<<i<<endl;
			bool visited[n];
			for(int i = 0; i < n; i++) visited[i] = false;
			int j = i, start = i;
			do {
				used[j] = true;
				visited[j] = true;
				cout << j<<endl;
				j = A[j].next;
				if(visited[j] == true) loops = true;
			} while(loops == false && j != -1);
		}
		i++;
	}

	return loops;
}




int main()
{
	/*
	//for(int i = 0; i < 7; i++) used[i] = '0';

	node A[7] = {{0,1},{1,2},{2,4},{3,1},{4,1},{5,1},{6,1}};
	//cout << there_are_loops(A, 7);
	cout << endl<<loops(A, 7)<<endl;
	for(int i = 0; i < 7; i++) cout << used[i];
	*/
}

