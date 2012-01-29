/*
 * servizio_listaVettore.h
 *
 *  Created on: 13/gen/2012
 *      Author: Domenico Monaco
 */

#ifndef _SERVIZIO_LISTAVETTOREINTERI_H_
#define _SERVIZIO_LISTAVETTOREINTERI_H_

#include <iostream>
using namespace std;

#include "../Lista/lista.h"
#include "../Lista/cellalistavettore.h"
#include "../Lista/cellalistavettore.cpp"

#include "../Lista/listaVettore.h"

typedef listaVettore<int, int> ListaInteri;

//DICHIARAZIONI DELLE FUNZIONI DI SERVIZIO
void servizio_listaVettore_interi();
ListaInteri caricaTutto();
void stampaTutto(ListaInteri);
int cerca(ListaInteri, int);

void cercaSostituisci(ListaInteri*, int, int);
//void cercaCancella(ListaInteri, int);

ListaInteri caricaTutto() {
	ListaInteri ListaVI;

	int a;
	a = 0;
	ListaVI.insLista(888, (a));
	a++;
	ListaVI.insLista(10, a);
	a++;
	ListaVI.insLista(102, a);
	a++;
	ListaVI.insLista(103, a);
	a++;
	ListaVI.insLista(44, a);
	a++;
	ListaVI.insLista(347, a);
	a++;
	ListaVI.insLista(44128, a);
	a++;
	ListaVI.insLista(4003, a);
	a++;

	//inserimento fuori lista
	//ListaVI.insLista(99, 10);

	return ListaVI;
}

void stampaTutto(ListaInteri ListaVI) {
	if (!ListaVI.listaVuota()) {
		int i = 0;
		cout << "#INIZIO STAMPA LISTA" << endl;
		while (i < ListaVI.lunghezzaLista()) {
			cout << "Posizione " << i << ": " << ListaVI.vet[i].leggi_valore()
					<< endl;
			i++;
		}
		cout << "#FINE STAMPA" << endl;

	} else {
		cout << "La lista vuota" << endl;
	}
}

int cerca(ListaInteri ListaVI, int c) {
	//int a;
	int i = 0;
	int out = NULL;

	if (!ListaVI.listaVuota()) {

		while (i < ListaVI.lunghezzaLista()
				&& ListaVI.vet[i].leggi_valore() != c) {
			i++;
		}
		if (ListaVI.vet[i].leggi_valore() == c) {
			out = i;
		}

	}

	return out;
}

void cercaSostituisci(ListaInteri * ListaVI, int interodacercare,
		int interodasostituire) {

	int into;
	into = cerca((*ListaVI), interodacercare);
	ListaVI->scriviLista(interodasostituire, into);
}

void servizio_listaVettore_interi() {
	ListaInteri ListaVI;
	stampaTutto(ListaVI);

	ListaVI = caricaTutto();
	stampaTutto(ListaVI);

	int intcerca;
	intcerca = cerca(ListaVI, 888);

	if (intcerca != -1) {
		cout << "trovato: " << ListaVI.vet[intcerca].leggi_valore() << endl;
	} else {
		cout << "NON trovato " << "888" << endl;
	}

	intcerca = cerca(ListaVI, 10);

	if (intcerca != -1) {
		cout << "trovato: " << ListaVI.vet[intcerca].leggi_valore() << endl;
	} else {
		cout << "NON trovato " << "10" << endl;
	}

	intcerca = cerca(ListaVI, 99);

	if (intcerca != -1) {
		cout << "trovato: " << ListaVI.vet[intcerca].leggi_valore() << endl;
	} else {
		cout << "NON trovato " << "99" << endl;
	}

	//cercaSostituisci(ListaInteri, int interodacercare, int interodasostituire);
	cercaSostituisci(&ListaVI, 102, 1222);
	stampaTutto(ListaVI);


	cercaSostituisci(&ListaVI, 4003, 999);
	stampaTutto(ListaVI);

	ListaVI.cancLista(1);
	stampaTutto(ListaVI);

	ListaVI.cancLista(6);
	stampaTutto(ListaVI);

	cout << "La posizione 5  fine lista? " << ListaVI.fineLista(5) << endl;
	cout << "La posizione 6  fine lista? " << ListaVI.fineLista(6) << endl;
}
#endif /* SERVIZIO_LISTAVETTORE_H_ */
