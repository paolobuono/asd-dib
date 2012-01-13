/*
 * servizo_listaUnidirezionale.h
 *
 *  Created on: 12/gen/2012
 *      Author: Domenico Monaco
 */

#ifndef _SERVIZO_LISTABIDIREZIONALEINTERI_H_
#define _SERVIZO_LISTABIDIREZIONALEINTERI_H_

#include "../Lista/lista.h"
#include "../Lista/nodolista.h"
#include "../Lista/listaBidirezionale.h"

//DEFINIAMO IL TIPO ELEM DA ALLEGARE
typedef NodoLista<int> NodoInteri;

typedef ListaBidirezionale<int> ListaBInteri;

//DICHIARAZIONI DELLE FUNZIONI DI SERVIZIO
void servizio_listaBidirezionale_interi();
ListaBInteri caricaTutto();
void stampaTutto(ListaBInteri);
NodoInteri* cerca(ListaBInteri, int);
void cercaSostituisci(ListaBInteri, int cerca, int sostituisci);

//IMPLEMENTAZIONI
ListaBInteri caricaTutto(ListaBInteri ListaI) {

	NodoInteri* posizione = ListaI.primoLista();
	ListaI.insLista(10, posizione);
	ListaI.insLista(345, posizione);
	posizione = NULL;
	ListaI.insLista(460, posizione);
	posizione = NULL;
	ListaI.insLista(478, posizione);
	posizione = NULL;
	ListaI.insLista(49805, posizione);
	posizione = NULL;
	ListaI.insLista(5, posizione);
	posizione = NULL;
	ListaI.insLista(96, posizione);

	return ListaI;
}

void stampaTutto(ListaBInteri ListaI) {
	NodoInteri* posizione = ListaI.primoLista();
	int i = 0;
	int element;
	cout << "# INIZIO Stampo tutta la Lista" << endl;
	while (posizione != NULL) {
		element = ListaI.leggiLista(posizione);
		cout << "Nodo " << i << ": " << element << endl;
		posizione = ListaI.succLista(posizione);
		i++;
	}
	cout << "# FINE Stampa" << endl;
}

NodoInteri* cerca(ListaBInteri ListaI, int element) {

	int i = 0;
	int check = 0;

	NodoInteri* posizione = ListaI.primoLista();
	check = ListaI.leggiLista(posizione);

	while (posizione != NULL && check != 1) {
		//cout << "recur" << endl;
		if (element != ListaI.leggiLista(posizione)) {
			posizione = ListaI.succLista(posizione);
		} else {
			check = 1;

		}
		i++;
	}
	return posizione;
}

void cercaSostituisci(ListaBInteri ListaI, int in, int sostituisci) {
	NodoInteri* cercapos;
	cercapos = cerca(ListaI, in);

	if (cercapos != NULL) {
		ListaI.scriviLista(sostituisci, cercapos);
	}
}

void servizio_listaBidirezionale_interi() {

	cout << "Inizio Servizio Lista Bidirezionale Interi " << endl;
	ListaBInteri ListaI;

	int element;

	NodoInteri* cercaintero;

	ListaI = caricaTutto(ListaI);

	stampaTutto(ListaI);

	 cercaintero = cerca(ListaI, 49805);
	 element = ListaI.leggiLista(cercaintero);
	 cout << "cercato e trovato l'elemento con dato: " << element << endl;

	 cercaintero = cerca(ListaI, 10);
	 element = ListaI.leggiLista(cercaintero);
	 cout << "cercato e trovato l'elemento con dato: " << element << endl;

	 cercaintero = cerca(ListaI, 6);
	 if (cercaintero != NULL) {
	 element = ListaI.leggiLista(cercaintero);
	 cout << "cercato e trovato l'elemento con dato: " << element << endl;
	 } else {
	 cout << "non trovato 6 " << endl;
	 }


	 cercaSostituisci(ListaI, 10, 11);
	 stampaTutto(ListaI);

	 cercaSostituisci(ListaI, 460, 64);
	 stampaTutto(ListaI);

	 cercaSostituisci(ListaI, 11111, 64);
	 stampaTutto(ListaI);

	 cercaSostituisci(ListaI, 49805, 66);
	 stampaTutto(ListaI);
}

#endif
