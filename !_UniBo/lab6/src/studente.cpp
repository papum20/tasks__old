#include "lib.h"
using namespace std;



void insert_studente(studente studenti[], int &length, char nome[], char cognome[], int matricola)
{
	strcpy(studenti[length-1].nome, nome);
	strcpy(studenti[length-1].cognome, cognome);
	studenti[length-1].matricola = matricola;
	length = length+1;
}

void init_studenti(studente studenti[], int length)
{
	for(int i = 0; i < length; i++)
	{
		char n[20];
		char c[20];
		int m;
		cin >> n >> c >> m;
		insert_studente(studenti, length, n, c, m);
	}
}

void stampa_studenti(studente studenti[], const int length)
{
	for(int i = 0; i < length; i++)
		cout << studenti[i].nome << " " <<studenti[i].cognome << ", " << studenti[i].matricola << endl;
}

