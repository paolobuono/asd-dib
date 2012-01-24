#ifndef SERVIZI_H
#define SERVIZI_H
#include <cstdlib>
#include <iostream>

using namespace std;
typedef nodo<studente>* Nodo;

void carica(albero<studente>&, Nodo&);
void previsita(albero<studente>, Nodo);
void postvisita(albero<studente>, Nodo);
void ampiezza(albero<studente>, Nodo);
int contanodi(albero<studente> &, Nodo, int);
int contaFoglie(albero<studente> &, Nodo, int);
Nodo ricercaCodice(albero<studente>, int);
int altezza(albero<studente> &, Nodo);
int calcolo(albero<studente> &, Nodo, int, int);

void carica(albero<studente> &a, Nodo &n1) {
	Nodo n2, n3, n4, n5, n6, n7, n8, n9;
	studente s;

	s.scriviCodice(1);
	a.insRadice(s);
	n1 = a.Radice();

	s.scriviCodice(2);
	a.insPrimofg(s, n1);
	n2 = a.primoFiglio(n1);

	s.scriviCodice(3);
	a.insFratellosucc(s, n2);
	n3 = a.succFratello(n2);

	s.scriviCodice(4);
	a.insFratellosucc(s, n3);
	n4 = a.succFratello(n3);

	s.scriviCodice(5);
	a.insPrimofg(s, n2);
	n5 = a.primoFiglio(n2);

	s.scriviCodice(6);
	a.insFratellosucc(s, n5);
	n6 = a.succFratello(n5);

	s.scriviCodice(7);
	a.insPrimofg(s, n3);
	n7 = a.primoFiglio(n3);

	s.scriviCodice(8);
	a.insFratellosucc(s, n7);
	n8 = a.succFratello(n7);

	s.scriviCodice(9);
	a.insFratellosucc(s, n8);
	n9 = a.succFratello(n8);

}

void previsita(albero<studente> a, Nodo u) {
	Nodo c;
	cout << "" << a.leggiNodo(u).leggiCodice() << endl;
	if (!a.Foglia(u)) {
		c = a.primoFiglio(u);
		while (!a.ultimoFratello(c)) {
			previsita(a, c);
			c = a.succFratello(c);
		}
		previsita(a, c);
	}
}

void postvisita(albero<studente> a, Nodo u) {
	Nodo c;
	if (!a.Foglia(u)) {
		c = a.primoFiglio(u);
		while (!a.ultimoFratello(c)) {
			postvisita(a, c);
			c = a.succFratello(c);
		}
		postvisita(a, c);
	}
	cout << "" << a.leggiNodo(u).leggiCodice() << endl;
}

void invisita(albero<studente> a, Nodo u) {
	Nodo c;
	if (a.Foglia(u))
		cout << "" << a.leggiNodo(u).leggiCodice() << endl;
	else {
		c = a.primoFiglio(u);
		invisita(a, c);
		cout << "" << a.leggiNodo(u).leggiCodice() << endl;
		while (!a.ultimoFratello(c)) {
			c = a.succFratello(c);
			invisita(a, c);

		}
	}
}

void ampiezza(albero<studente> a, Nodo u) {
	studente stud;
	Nodo st;
	coda<Nodo> cod;
	cod.inCoda(u);
	while (!cod.Codavuota()) {
		st = cod.leggiCoda();
		stud = st->leggiInfo();
		cout << "" << stud.leggiCodice() << endl;
		cod.fuoriCoda();
		if (!a.Foglia(st)) {
			st = a.primoFiglio(st);
			while (!a.ultimoFratello(st)) {
				cod.inCoda(st);
				st = a.succFratello(st);
			}
			cod.inCoda(st);
		}
	}
}

int contanodi(albero<studente>& t, Nodo u, int cont) // restituisce il numero di sottoalberi dell'albero
		{

	if (!t.alberoVuoto()) {
		Nodo c;
		cont++;

		if (!t.Foglia(u)) {
			c = t.primoFiglio(u);

			while (!t.ultimoFratello(c)) {
				cont = contanodi(t, c, cont);
				c = t.succFratello(c);
			}
			cont = contanodi(t, c, cont);
		}
	}
	return cont;
}
;

int contaFoglie(albero<studente>& t, Nodo u, int cont) //restituisce il numero delle foglie dell'albero
		{
	if (!t.alberoVuoto() && u != NULL) {
		Nodo c;

		if (t.Foglia(u))
			cont++;

		else {
			c = t.primoFiglio(u);

			while (!t.ultimoFratello(c)) {
				cont = contaFoglie(t, c, cont);
				c = t.succFratello(c);
			}
			cont = contaFoglie(t, c, cont);
		}
	}
	return cont;
}
;

/*Modifica parametrei del metodo altezza*/

int altezza(albero<studente>& t, Nodo u) //restituisce l'altezza dell'albero
		{
	int max, temp;
	max = temp = 0;
	if (!t.alberoVuoto())
		max = calcolo(t, u, temp, max);
	return max;
}
;

int calcolo(albero<studente>& t, Nodo u, int temp, int max) {
	Nodo c;
	if (t.Foglia(u)) {
		if (temp >= max)
			max = temp;
	}

	else {
		temp++;
		{
			c = t.primoFiglio(u);
			while (!t.ultimoFratello(c)) {
				max = calcolo(t, c, temp, max);
				c = t.succFratello(c);
			}
			max = calcolo(t, c, temp, max);
		}
	}
	return max;
}

Nodo ricercaCodice(albero<studente> a, int c) {
	studente s;
	bool trovato = false;
	Nodo temp, rad;
	coda<Nodo> cod;
	rad = a.Radice();
	/*controllo subito se ho trovato l'elemento ritorno rad altrimenti faccio visita in ampiezza */
	if (rad->leggiInfo().leggiCodice() == c)
		return rad;
	cod.inCoda(rad);
	while (!cod.Codavuota() && trovato == false) {
		temp = cod.leggiCoda();
		s = temp->leggiInfo();
		cod.fuoriCoda();
		if (s.leggiCodice() == c) {
			trovato = true;
			return temp;
		} else if (!a.Foglia(temp)) {
			temp = a.primoFiglio(temp);
			while (!a.ultimoFratello(temp)) {
				cod.inCoda(temp);
				temp = a.succFratello(temp);
			} //end while
			cod.inCoda(temp);
		} //end if

	}
	if (cod.Codavuota()) {
		cout << "Nessun elemento trovato!" << endl;
		return NULL;
	}
}

#endif
