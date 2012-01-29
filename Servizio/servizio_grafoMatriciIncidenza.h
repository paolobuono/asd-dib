/*
 * servizio_grafoMatriciAdiacenza.h
 *
 *  Created on: 25/gen/2012
 *      Author: Domenico Monaco
 */

#ifndef SERVIZIO_GRAFIMATRICE_INCIDENZA_H
#define SERVIZIO_GRAFIMATRICE_INCIDENZA_H

#include <iostream>
using namespace std;
typedef bool boolean;

#include "../Grafo/grafo.h"
#include "../Grafo/cellaGrafo.h"
#include "../Grafo/arcoGrafo.h"
#include "../Lista/listaBidirezionale.h"

#include "../Grafo/grafoMatriciIncidenza.h"

void servizio_grafoMatriciIncidenza();

void servizio_grafoMatriciIncidenza() {

	GrafoMatriceIncidenza<int, int> grafoInteri;
	grafoInteri.creaGrafo();

	if (grafoInteri.grafoVuoto()) {
		cout << "Il grafo  vuoto" << endl;
	} else {
		cout << "Il grafo NON  vuoto" << endl;
	}

	cout << "Inserisco 6 Nodi (ID:0-5)" << endl;
	grafoInteri.insNodo(0, 0); //#0
	grafoInteri.insNodo(1, 1); //#1
	grafoInteri.insNodo(2, 2); //#2
	grafoInteri.insNodo(3, 3); //#3
	grafoInteri.insNodo(4, 4); //#4
	grafoInteri.insNodo(5, 5); //#5

	cout << "Inserisco 6 Archi (ID:0-5)" << endl;
	grafoInteri.insArco(0, 1, 0, 0);
	grafoInteri.insArco(1, 3, 1, 1);
	grafoInteri.insArco(3, 5, 2, 2);
	grafoInteri.insArco(5, 4, 3, 3);
	grafoInteri.insArco(4, 2, 4, 4);
	grafoInteri.insArco(2, 0, 5, 5);

	cout << "#### TEST Di esistenza ###" << endl;
	if (grafoInteri.grafoVuoto()) {
		cout << "Il grafo  vuoto" << endl;
	} else {
		cout << "Il grafo NON  vuoto" << endl;
	}
	if (grafoInteri.esisteArco(2, 0)) {
		cout << "Arco(2,0) Esiste" << endl;
	} else {
		cout << "Arco(2,0) Non Esiste" << endl;
	}
	if (grafoInteri.esisteArco(0, 1)) {
		cout << "Arco(0,1) Esiste" << endl;
	} else {
		cout << "Arco(0,1) Non Esiste" << endl;
	}
	if (grafoInteri.esisteArco(1, 3)) {
		cout << "Arco(1,3) Esiste" << endl;
	} else {
		cout << "Arco(1,3) Non Esiste" << endl;
	}
	if (grafoInteri.esisteArco(5, 4)) {
		cout << "Arco(5, 4) Esiste" << endl;
	} else {
		cout << "Arco(5, 4) Non Esiste" << endl;
	}

	cout << "###ÊTest afiacenti ###" << endl;
	ListaBidirezionale<cellaGrafo<int>*, NodoLista<cellaGrafo<int>*>*> listaNodiAdi;

	NodoLista<cellaGrafo<int>*>* pos;
	pos = listaNodiAdi.primoLista();

	listaNodiAdi = grafoInteri.adiacenti(3);

	if (listaNodiAdi.listaVuota()) {
		cout << "il nodo 3 non ha adiacenti" << endl;
	} else {
		cout << "il  3 ha adiacenti" << endl;

		pos = listaNodiAdi.primoLista();
		int tmp;
		while (pos != NULL) {
			tmp = listaNodiAdi.leggiLista(pos)->getInfo();
			cout << "il 3 ha adiacente: " << tmp << endl;
			pos = listaNodiAdi.succLista(pos);
		}
	}

	listaNodiAdi = grafoInteri.adiacenti(5);
	if (listaNodiAdi.listaVuota()) {
		cout << "il nodo 5 non ha adiacenti" << endl;
	} else {
		cout << "il  5 ha adiacenti" << endl;
		pos = listaNodiAdi.primoLista();
		int tmp;
		while (pos != NULL) {
			tmp = listaNodiAdi.leggiLista(pos)->getInfo();
			cout << "il 5 ha adiacente: " << tmp << endl;
			pos = listaNodiAdi.succLista(pos);
		}
	}

	listaNodiAdi = grafoInteri.adiacenti(4);
	if (listaNodiAdi.listaVuota()) {
		cout << "il nodo 4 non ha adiacenti" << endl;
	} else {
		cout << "il  4 ha adiacenti" << endl;
		pos = listaNodiAdi.primoLista();
		int tmp;
		while (pos != NULL) {
			tmp = listaNodiAdi.leggiLista(pos)->getInfo();
			cout << "il 4 ha adiacente: " << tmp << endl;
			pos = listaNodiAdi.succLista(pos);
		}
	}

	grafoInteri.cancNodo(5);
	cout << "###ÊTest Adiacenti Senza 5 ###" << endl;
	pos = listaNodiAdi.primoLista();

	listaNodiAdi = grafoInteri.adiacenti(3);

	if (listaNodiAdi.listaVuota()) {
		cout << "il nodo 3 non ha adiacenti" << endl;
	} else {
		cout << "il  3 ha adiacenti" << endl;

		pos = listaNodiAdi.primoLista();
		int tmp;
		while (pos != NULL) {
			tmp = listaNodiAdi.leggiLista(pos)->getInfo();
			cout << "il 3 ha adiacente: " << tmp << endl;
			pos = listaNodiAdi.succLista(pos);
		}
	}

	listaNodiAdi = grafoInteri.adiacenti(5);
	if (listaNodiAdi.listaVuota()) {
		cout << "il nodo 5 non ha adiacenti" << endl;
	} else {
		cout << "il  5 ha adiacenti" << endl;
		pos = listaNodiAdi.primoLista();
		int tmp;
		while (pos != NULL) {
			tmp = listaNodiAdi.leggiLista(pos)->getInfo();
			cout << "il 5 ha adiacente: " << tmp << endl;
			pos = listaNodiAdi.succLista(pos);
		}
	}

	listaNodiAdi = grafoInteri.adiacenti(4);
	if (listaNodiAdi.listaVuota()) {
		cout << "il nodo 4 non ha adiacenti" << endl;
	} else {
		cout << "il  4 ha adiacenti" << endl;
		pos = listaNodiAdi.primoLista();
		int tmp;
		while (pos != NULL) {
			tmp = listaNodiAdi.leggiLista(pos)->getInfo();
			cout << "il 4 ha adiacente: " << tmp << endl;
			pos = listaNodiAdi.succLista(pos);
		}
	}

}

#endif /* SERVIZIO_GRAFIMATRICE_INCIDENZA_H */
