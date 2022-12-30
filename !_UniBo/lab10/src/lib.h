#include <iostream>
#include <cstring>
using namespace std;




struct rifornimento {
	char nome[20];
	int litri;
	int mx_litri;
};


class Self {
	protected:
		rifornimento benzina;
		rifornimento diesel;
	public:
		Self (int b_mxl = 10, int d_mxl = 10, int b_l = 0, int d_l = 0) {
			strcpy(benzina.nome, "benzina");
			benzina.litri = b_l;
			benzina.mx_litri = b_mxl;
			strcpy(diesel.nome, "diesel");
			diesel.litri = d_l;
			diesel.mx_litri = d_mxl;
		}

		bool aggiungi_litri(char tipo[], int l) {
			if(strcmp(tipo, benzina.nome) == 0) {
				if(benzina.litri + l <= benzina.mx_litri) {
					benzina.litri += l;
					return true;
				}
				else return false;
			}
			else if(strcmp(tipo, diesel.nome) == 0) {
				if(diesel.litri + l <= diesel.mx_litri) {
					diesel.litri += l;
					return true;
				}
				else return false;
			}
			else return false;
		}

		bool decrementa_litri(char tipo[], int l) {
			if(strcmp(tipo, benzina.nome) == 0) {
				if(benzina.litri - l >= 0) {
					benzina.litri -= l;
					return true;
				}
				else return false;
			}
			else if(strcmp(tipo, diesel.nome) == 0) {
				if(diesel.litri - l >= 0) {
					diesel.litri -= l;
					return true;
				}
				else return false;
			}
			else return false;
		}

};


class Servito : public Self {
	protected:
		rifornimento metano;
	public:
		Servito (int b_mxl = 10, int d_mxl = 10, int m_mxl = 10, int b_l = 0, int d_l = 0, int m_l = 0) : Self(b_mxl, d_mxl, b_l, d_l) {
			strcpy(metano.nome, "metano");
			metano.litri = m_l;
			metano.mx_litri = m_mxl;
		}

		bool aggiungi_litri (char tipo[], int l) {
			if(strcmp(tipo, metano.nome) == 0) {
				if(metano.litri + l <= metano.mx_litri) {
					metano.litri += l;
					return true;
				}
				else return false;
			}
			else return Self::aggiungi_litri(tipo, l);
		}

		bool decrementa_litri (char tipo[], int l) {
			if(strcmp(tipo, metano.nome) == 0) {
				if(metano.litri - l >= 0) {
					metano.litri -= l;
					return true;
				}
				else return false;
			}
			else return Self::decrementa_litri(tipo, l);
		}

};




////
////
////



struct sala {
	int disponibili;
	int prenotati;
	bool is3D;
	sala *next;
};
typedef sala *psala;




class MultiSala {
	protected:
		psala sale;
		double ticket;
		double incr;
	public:
		MultiSala (psala s, double t, double i) {
			if(s != NULL) {
				sale = new sala;
				while(s != NULL) {
					sale->disponibili = s->disponibili;
					sale->prenotati = s->prenotati;
					sale->is3D = s->is3D;
					s = s->next;
					if(s != NULL) {
						sale->next = new sala;
						sale = sale->next;
					}
					else sale->next = NULL;
				}
			}
			else sale = NULL;

			ticket = t;
			incr = i;
		}

		bool prenota_posto(int n) {
			int i = 0;
			psala p = sale;
			bool prenotato = false;
			while(!prenotato && p != NULL) {
				if(i == n) {
					if(p->disponibili > 0) {
						p->prenotati += 1;
						p->disponibili -= 1;
					}
					prenotato = true;
				}
				else {
					i++;
					p = p->next;
				}
			}

			return prenotato;
		}

		int conta_ticket(bool c3d) {
			int res = 0;
			psala p = sale;
			while(p != NULL) {
				if(c3d == p->is3D) res += p->prenotati;
				p = p->next;
			}

			return res;
		}

		double incasso_totale () {
			int res = 0;
			psala p = sale;
			while(p != NULL) {
				int n_ticket = conta_ticket(p->is3D);
				if(p->is3D) res += n_ticket * (ticket + incr);
				else res += n_ticket * ticket;
				p = p->next;
			}

			return res;
		}
};


struct ristorante {
	int consumazioni;
	int prezzo;
	ristorante *next;
};
typedef ristorante *p_ristorante;


class MultiSalaPlus : public MultiSala {
	protected:
		p_ristorante ristoranti;
	public:
		MultiSalaPlus (p_ristorante r) {
			if(r != NULL) {
				ristoranti = new ristorante;
				while(r != NULL) {
					ristoranti->consumazioni = r->consumazioni;
					ristoranti->prezzo = r->prezzo;
					r = r->next;
					if(r != NULL) {
						ristoranti->next = new ristorante;
						ristoranti = ristoranti->next;
					}
					else ristoranti->next = NULL;
				}
			}
			else ristoranti = NULL;
		}

		double incasso_totale () {
			int res = 0;
			p_ristorante p = ristoranti;
			while(p != NULL) {
				res += p->consumazioni * p->prezzo;
				p = p->next;
			}

			return res + MultiSala::incasso_totale();
		}
};

