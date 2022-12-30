#include <iostream>
using namespace std;




const int length = 10;



struct queue {
	int data[length];
	int init;
	int num_el;
};

struct queue_shift {
	int data[length];
	int num_el;
};

struct queue_indexes {
	int data[length];
	int init;
	int num_el;
};




queue new_queue()
{
	queue tmp;
	tmp.init = 0;
	tmp.num_el = 0;
	return tmp;
}
bool enqueue(queue& q, int e)
{
	if(q.num_el >= length) return false;
	else
	{
		int new_ind = (q.init + q.num_el) %length;
		q.data[new_ind] = e;
		q.num_el++;
		return true;
	}
}
bool dequeue(queue& q)
{
	if(q.num_el == 0) return false;
	else
	{
		q.init = (q.init + 1) %length;
		q.num_el--;
		return true;
	}
}
//EXTRA
void print_queue(queue q)
{
	if(q.num_el > 0)
	{
		int end = (q.init + q.num_el) %length;
		int i = q.init;
		do {
			cout << q.data[i] << " ";
			i = (i+1) %length;
		} while(i != end);
	}
	cout << endl;
}




queue_shift new_queue_shift()
{
	queue_shift tmp;
	tmp.num_el = 0;
	return tmp;
}
bool enqueue_shift(queue_shift& q, int e)
{
	if(q.num_el >= length) return false;
	else
	{
		q.data[q.num_el] = e;
		q.num_el++;
		return true;
	}
}
bool dequeue_shift(queue_shift& q)
{
	if(q.num_el == 0) return false;
	else
	{
		for(int i = 0; i < q.num_el - 1; i++)
			q.data[i] = q.data[i+1];
		q.num_el--;
		return true;
	}
}
//EXTRA
void print_queue_shift(queue_shift q)
{
	if(q.num_el > 0)
	{
		for(int i = 0; i < q.num_el; i++)
			cout << q.data[i] << " ";
	}
	cout << endl;
}











queue_indexes new_queue_indexes()
{
	queue_indexes tmp;
	tmp.init = 0;
	tmp.num_el = 0;
	return tmp;
}
bool enqueue_indexes(queue_indexes& q, int e)
{
	if(q.init + q.num_el >= length) return false;
	else
	{
		q.data[q.init + q.num_el] = e;
		q.num_el++;
		return true;
	}
}
bool dequeue_indexes(queue_indexes& q)
{
	if(q.num_el == 0) return false;
	else
	{
		q.init++;
		q.num_el--;
		return true;
	}
}
//EXTRA
void print_queue_indexes(queue_indexes q)
{
	if(q.num_el > 0)
	{
		for(int i = q.init; (i < q.init+q.num_el) && i < length; i++)
			cout << q.data[i] << " ";
	}
	cout << endl;
}








int main()
{
	//PROVA QUEUE
	/*
	queue q = new_queue();
	//q.init = 0;
	for(int i = 0; i < 11; i++)
	{
		bool b = enqueue(q, i);
		print_queue(q);
		for(auto j:q.data) cout << j << " ";
		cout << endl;
	}
	for(int i = 0; i < 11; i++)
	{
		bool b = dequeue(q);
		print_queue(q);
		for(auto j:q.data) cout << j << " ";
		cout << endl;
	}
	//*/
	//PROVA SHIFT
	/*
	queue_shift q = new_queue_shift();
	for(int i = 0; i < 11; i++)
	{
		bool b = enqueue_shift(q, i);
		print_queue_shift(q);
		for(auto j:q.data) cout << j << " ";
		cout << endl;
	}
	for(int i = 0; i < 11; i++)
	{
		bool b = dequeue_shift(q);
		print_queue_shift(q);
		for(auto j:q.data) cout << j << " ";
		cout << endl;
	}
	//*/
	//PROVA INDEXES
	/*
	queue_indexes q = new_queue_indexes();
	q.init = 4;
	for(int i = 0; i < 11; i++)
	{
		bool b = enqueue_indexes(q, i);
		print_queue_indexes(q);
		for(auto j:q.data) cout << j << " ";
		cout << endl;
	}
	for(int i = 0; i < 11; i++)
	{
		bool b = dequeue_indexes(q);
		print_queue_indexes(q);
		for(auto j:q.data) cout << j << " ";
		cout << endl;
	}
	//*/
}
