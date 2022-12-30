#include <iostream>
#include <ctime>
#include <cstring>



struct node{
	int val;
	node *next;
};
typedef node *list;


list gen_list(int, int);

void print_list(list);

int min_list(list);
//precondition: length(list) > 0
int min_list_2(list, int);
//int min inizializzato a -1

list dec2bin(int, list head = NULL);

bool prime(int, int d = 2);


//ESAMI
bool ex1(char[], int);
