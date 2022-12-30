#include <iostream>
#include <ctime>
#include <iomanip>



//inizalizza a 0
void inizializza_array(int [], int);

//dimensione n di numeri casuali
//mettere srand fuori
void genera_elementi(int [], int, int);

//stampa
void stampa_array(const int [], int);

//1
void concatena_array(const int [], const int [], int [], int, int);

//2 - STAMPA ISTOGRAMMA
void stampa_istogramma();

//void ordina_array(int [], const int);
void scambia(int&, int&);
void bubble_sort(int[], int);

//3
int mediano_array(const int [], const int);

//4
void trova_duplicati(const int[], int[], int, int&);
void copia_univoci(const int[], const int[], int[], int);
void trova_univoci(const int[], int[], int[], int, int&);

//5
void unione(const int[], const int[], int[], int, int);
