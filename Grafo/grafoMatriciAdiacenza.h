/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *   Credits:                                                              *
 *   Domenico Monaco                                                       *
 *   This file is part of ASD-dib.                                         *
 *   ASD-dib is free software; you can redistribute it and/or modify       *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   ASD-dib is distributed in the hope that it will be useful,            *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with ASD-dib; if not, see <http://www.gnu.org/licenses/>        *
 ***************************************************************************/

#ifndef GRAFOMATRICE_ADIACENZA_H
#define GRAFOMATRICE_ADIACENZA_H

#include <iostream>
using namespace std;
typedef bool boolean;

//#include "grafo.h"
#include "cellaGrafo.h"
#include "arcoGrafo.h"
#include "../Lista/listaBidirezionale.h"

#define RIGHE 100
#define COLONNE 100

template<class tipoNodo, class tipoArco>
class GrafoMatriceAdiacenza {
public:
	int posizioniOccupate;

	typedef cellaGrafo<tipoNodo> nodoGrafo;

	arcoGrafo<tipoArco>* matriceAdiacenza[RIGHE][COLONNE];
	nodoGrafo* Nodi[RIGHE];

	GrafoMatriceAdiacenza();

	void creaGrafo();
	boolean grafoVuoto();

	void insNodo(int indice, tipoNodo);
	void insArco(int indiceA, int indiceB, tipoArco);

	arcoGrafo<tipoArco>* arco(int indiceA, int indiceB);
	nodoGrafo* nodo(int indiceNodo);

	void cancNodo(int indice);
	void cancArco(int indiceA, int indiceB);

	ListaBidirezionale<int, NodoLista<int>*> adiacenti(int indice);

	boolean esisteNodo(int indice);
	boolean esisteArco(int indiceA, int indiceB);
};

template<class tipoNodo, class tipoArco>
GrafoMatriceAdiacenza<tipoNodo, tipoArco>::GrafoMatriceAdiacenza() {
}

/*
 * creaGrafo()
 *		inizializza il grafo impostando a null gli array di nodi e matriceadiacenza
 */
template<class tipoNodo, class tipoArco>
void GrafoMatriceAdiacenza<tipoNodo, tipoArco>::creaGrafo() {

	posizioniOccupate = 0;
	int i = 0, j = 0;

	for (i = 0; i < RIGHE; i++) {
		Nodi[i] = NULL;
		for (j = 0; j < COLONNE; j++) {
			matriceAdiacenza[i][j] = NULL;
		}
	}
}

template<class tipoNodo, class tipoArco>
boolean GrafoMatriceAdiacenza<tipoNodo, tipoArco>::grafoVuoto() {

	boolean out = false;

	if (posizioniOccupate == 0) {
		out = true;
	}

	return out;
}

template<class tipoNodo, class tipoArco>
void GrafoMatriceAdiacenza<tipoNodo, tipoArco>::insNodo(int indice, tipoNodo datoNodo) {

	//Creao nuovo nodo
	cellaGrafo<tipoNodo>* nuovoNodo;
	nuovoNodo = new cellaGrafo<tipoNodo>;
	nuovoNodo->setInfo(datoNodo);

	//lo inserisco nella posizione indicata
	//O = nessun nodo
	//le righe vanno da 0->n allora (n+1) = posizioniOccupate se fino a n � occupato
	if (posizioniOccupate < (RIGHE + 1)) {

		Nodi[indice] = nuovoNodo;
		//incremento posizione occupate
		posizioniOccupate++;
	}
}

template<class tipoNodo, class tipoArco>
void GrafoMatriceAdiacenza<tipoNodo, tipoArco>::insArco(int indiceA, int indiceB, tipoArco datoArco) {

	if (esisteNodo(indiceA) && esisteNodo(indiceB)) {
		arcoGrafo<tipoArco>* nuovoArco;
		nuovoArco = new arcoGrafo<tipoArco>;
		nuovoArco->setInfo(datoArco);

		matriceAdiacenza[indiceA][indiceB] = nuovoArco;
	}
}

template<class tipoNodo, class tipoArco>
arcoGrafo<tipoArco>* GrafoMatriceAdiacenza<tipoNodo, tipoArco>::arco(int indiceA, int indiceB) {

	if (!(esisteNodo(indiceA) && esisteNodo(indiceB)))
		cout << "arco inesistente" << endl;

			return matriceAdiacenza[indiceA][indiceB];
}

template<class tipoNodo, class tipoArco>
cellaGrafo<tipoNodo>* GrafoMatriceAdiacenza<tipoNodo, tipoArco>::nodo(int indiceNodo){

	if (!(esisteNodo(indiceNodo)))
		cout << "nodo inesistente" << endl;

			return Nodi[indiceNodo];
}



template<class tipoNodo, class tipoArco>
void GrafoMatriceAdiacenza<tipoNodo, tipoArco>::cancNodo(int indice) {

	if (esisteNodo(indice)) {
		for (int i = 0; i < RIGHE; i++) {
			if (esisteArco(i, indice)) {
				cancArco(i, indice);
			}
			if (esisteArco(indice, i)) {
				cancArco(indice, i);
			}
		}

		//Cancello la locazione di memoria del nodo
		delete Nodi[indice];
		//Forzo la presenza di NULL
		Nodi[indice] = NULL;//TODO: verificare che si possa eliminare
		//Drecremento posizioniOccupate
		posizioniOccupate--;
	}
}

template<class tipoNodo, class tipoArco>
void GrafoMatriceAdiacenza<tipoNodo, tipoArco>::cancArco(int indiceA,
		int indiceB) {

	if (esisteArco(indiceA, indiceB)) {
		delete matriceAdiacenza[indiceA][indiceB];
		matriceAdiacenza[indiceA][indiceB] = NULL;//TODO: verificare l'eliminazione di questa riga
	}
}

template<class tipoNodo, class tipoArco>
ListaBidirezionale <int, NodoLista<int>* >
			GrafoMatriceAdiacenza<tipoNodo, tipoArco>::adiacenti(int indice) {

	ListaBidirezionale<int, NodoLista<int>*> ListaNodi;
	ListaNodi.creaLista();

	if (esisteNodo(indice)) {
		NodoLista<int>* pos;
		for (int i = 0; i < RIGHE; i++) {
			if (esisteArco(indice, i)) {
				pos = ListaNodi.primoLista();
				ListaNodi.insLista(i, pos);
			}
		}
	}
	return ListaNodi;
}

template<class tipoNodo, class tipoArco>
boolean GrafoMatriceAdiacenza<tipoNodo, tipoArco>::esisteNodo(int indice) {

	boolean out=false;

	if (Nodi[indice] != NULL) {
		out = true;
	}

	return out;
}

template<class tipoNodo, class tipoArco>
boolean GrafoMatriceAdiacenza<tipoNodo, tipoArco>::esisteArco(int indiceA,
		int indiceB) {
	boolean out=false;

	if (esisteNodo(indiceA) && esisteNodo(indiceB)
			&& matriceAdiacenza[indiceA][indiceB]) {
		out = true;
	}
	return out;
}

#endif /* Grafo matrice adiacenza */
