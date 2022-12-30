#include <iostream>
using namespace std;




class abitazione {
	protected:
		int stanze;
		double metri;
	public:
		abitazione (int s, double m) {
			stanze = s;
			metri = m;
		}
		double prezzo_tot (double prezzo_m) {
			return prezzo_m * metri;
		}
};

class appartamento : public abitazione {
	protected:
		int piano;
	public:
		appartamento (int s, double m, int p) : abitazione (s, m) {
			piano = p;
		}
};

class villetta : public abitazione {
	protected:
		double incr;
	public:
		villetta (int s, double m, double i = 1.1) : abitazione(s, m) {
			incr = i;
		}
		double prezzo_tot (double prezzo_m) {
			return abitazione::prezzo_tot(prezzo_m) * incr;
		}
};


////
////
////



class BigliettoUrbano {
	protected:
		double prezzo;
	public:
		BigliettoUrbano(double p = 1) {
			prezzo = p;
		}
		double calcola_prezzo() {
			return prezzo;
		}
};

class BigliettoExtraUrbano : public BigliettoUrbano {
	protected:
		double prezzo_km;
		double km;
	public:
		BigliettoExtraUrbano(double pkm, double k, double p = 1) : BigliettoUrbano(p) {
			prezzo_km = pkm;
			km = k;
		}
		double calcola_prezzo() {
			return BigliettoUrbano::calcola_prezzo() + prezzo_km * km;
		}
		double calcola_distanza() {
			return km;
		}
};

class BigliettoNazionale : public BigliettoExtraUrbano {
	protected:
		double prezzo_km_n;
		double km_n;
	public:
		BigliettoNazionale(double pkm_n, double k_n, double pkm, double k, double p = 1) : BigliettoExtraUrbano(pkm, k, p) {
			prezzo_km_n = pkm_n;
			km_n = k_n;
		}
		double calcola_prezzo() {
			return BigliettoExtraUrbano::calcola_prezzo() + prezzo_km_n * km_n;
		}
		double calcola_distanza() {
			return BigliettoExtraUrbano::calcola_distanza() + km_n;
		}
};

