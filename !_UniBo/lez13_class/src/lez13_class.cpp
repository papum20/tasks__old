#include <iostream>
using namespace std;



class stack {
	typedef stack *p_stack;

	protected:
		int val;
		p_stack next;

	public:
		stack(){
			val = 0 ;
			next = NULL;
		};

		bool is_empty(){
			return(next == NULL);
		};

		void push(int e){
			p_stack tmp = new stack();
			tmp->val = e;
			tmp->next = next;
			next = tmp;
		};

		void pop(){
			if (next != NULL){
				p_stack tmp = next;
				 next = next->next;
				delete(tmp);
			}
		};

		int top(){
			if (next != NULL) return(next->val);
		};

		void stampa_stack(){
			p_stack p = next;
			while(p != NULL) {
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		};
};




class frazione {
	protected:
		int numeratore;
		int denominatore;

	public:
		frazione (int n, int d) {
			numeratore = n;
			denominatore = d;
		}
		void inverso () {
			int tmp = numeratore;
			numeratore = denominatore;
			denominatore = tmp;
		}
		void stampa () {
			cout << (double)(numeratore) / (denominatore) << endl;
		}
		void moltiplica (frazione a, frazione b) {
			numeratore = a.numeratore * b.numeratore;
			denominatore = a.denominatore * b.denominatore;
		}
};



class contoBanca{
	protected:
		double saldo;
	public:
		contoBanca(double n = 0) {
			saldo = n;
		}
		void versa(double n) {
			saldo += n;
		}
		double preleva(double n) {
			if(n <= saldo) saldo -= n;
			else {
				n = saldo;
				saldo = 0;
			}
			return n;
		}
		double get_saldo() {
			return saldo;
		}
};

class contoInteressi: public contoBanca {
	public:
		contoInteressi(double n) {
			saldo = n;
		}
		void saldo2percent() {
			saldo = saldo * 102 / 100;
		}
};




int main()
{
	/*
	frazione x(2,3);
	x=frazione(1,2);
	x=frazione(2,4);
	x.stampa();
	x.inverso();
	x.stampa();

	frazione a(4,5), b(2,4);
	x.moltiplica(a, b);
	x.stampa();
	*/
/*
	stack s = stack();
	//cout << s.top() << " ";
	s.push(1);
	s.push(2);
	s.stampa_stack();
	*/

	contoBanca b(10);
	b.versa(2);
	cout << b.preleva(5) << endl;
	cout << b.preleva(10) << endl;
	contoInteressi i(4);
	cout << i.get_saldo() << endl;
	i.saldo2percent();
	cout << i.get_saldo();
}
