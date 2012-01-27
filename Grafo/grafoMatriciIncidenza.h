/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *                                                                         *
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

/*
 * grafoMatriciIncidenza.h
 *      Author: Domenico Monaco
 *      Descrizione: Grafo orientato con Matrice di Incidenza
 */

#ifndef GRAFOMATRICE_INCIDENZA_H
#define GRAFOMATRICE_INCIDENZA_H

#include <iostream>
using namespace std;
typedef bool boolean;

//#include "grafo.h"
#include "cellaGrafo.h"
#include "arcoGrafo.h"
#include "../Lista/listaBidirezionale.h"

#define RIGHE 100
#define COLONNE 1000

template<class tipoNodo, class tipoArco>
class GrafoMatriceIncidenza {
public:

	int occupy_pos;

	typedef cellaGrafo<tipoNodo> nodoGrafo;

	int matriceIncidenza[RIGHE][COLONNE];

	nodoGrafo* Nodi[RIGHE];
	arcoGrafo<tipoArco>* Archi[COLONNE];

	GrafoMatriceIncidenza();

	void creaGrafo();
	boolean grafoVuoto();

	void insNodo(int indiceNodo, tipoNodo);
	void insArco(int indiceNodoA, int indiceNodoB, int indiceArco, tipoArco);

	void cancNodo(int indiceNodo);
	void cancArco(int indiceNodoA, int indiceNodoB);

	ListaBidirezionale<cellaGrafo<tipoNodo>*, NodoLista<cellaGrafo<tipoNodo>*>*> adiacenti(
			int indiceNodo);

	boolean esisteNodo(int indiceNodo);
	boolean esisteArco(int indiceNodoA, int indiceNodoB);

	//Metodi Aggiuntivi
	void cancArco_by_indice(int indiceArco);
};

template<class tipoNodo, class tipoArco>
GrafoMatriceIncidenza<tipoNodo, tipoArco>::GrafoMatriceIncidenza() {
}

/*
 * creaGrafo()
 *		inizializza il grafo forzando a null array di nodi e matriceIncidenza
 */
template<class tipoNodo, class tipoArco>
void GrafoMatriceIncidenza<tipoNodo, tipoArco>::creaGrafo() {

	occupy_pos = 0;
	int i = 0, j = 0;

	for (i = 0; i < RIGHE; i++) {

		Nodi[i] = NULL;

		for (j = 0; j < COLONNE; j++) {
			//eseguo solo una volta la forzatura su ARCHI
			if (i == 0) {
				Archi[j] = NULL;
			}
			matriceIncidenza[i][j] = NULL;
		}
	}
}

template<class tipoNodo, class tipoArco>
boolean GrafoMatriceIncidenza<tipoNodo, tipoArco>::grafoVuoto() {
	boolean out;
	if (occupy_pos == 0) {
		out = true;
	} else {
		out = false;
	}
	return out;
}

template<class tipoNodo, class tipoArco>
void GrafoMatriceIncidenza<tipoNodo, tipoArco>::insNodo(int indice,
		tipoNodo datoNodo) {

	cellaGrafo<tipoNodo>* nuovoNodo;
	nuovoNodo = new cellaGrafo<tipoNodo>;
	nuovoNodo->setInfo(datoNodo);

	if (occupy_pos < (RIGHE + 1)) {
		Nodi[indice] = nuovoNodo;
		occupy_pos++;
	}
}

template<class tipoNodo, class tipoArco>
void GrafoMatriceIncidenza<tipoNodo, tipoArco>::insArco(int indiceNodoA,
		int indiceNodoB, int indiceArco, tipoArco datoArco) {

	if (esisteNodo(indiceNodoA) && esisteNodo(indiceNodoB)) {
		arcoGrafo<tipoArco>* nuovoArco;
		nuovoArco = new arcoGrafo<tipoArco>;
		nuovoArco->setInfo(datoArco);

		Archi[indiceArco] = nuovoArco;

		matriceIncidenza[indiceNodoA][indiceArco] = 1;
		matriceIncidenza[indiceNodoB][indiceArco] = -1;

	}
}

template<class tipoNodo, class tipoArco>
void GrafoMatriceIncidenza<tipoNodo, tipoArco>::cancNodo(int indice) {
	if (esisteNodo(indice)) {
		int i;
		delete Nodi[indice];
		Nodi[indice] = NULL;
		occupy_pos--;

		for (i = 0; i < COLONNE; i++) {
			if (matriceIncidenza[indice][i] != NULL) {
				cancArco_by_indice(i);
			}
		}
	}
}

template<class tipoNodo, class tipoArco>
void GrafoMatriceIncidenza<tipoNodo, tipoArco>::cancArco_by_indice(
		int indiceArco) {

	delete Archi[indiceArco];
	Archi[indiceArco] = NULL;

	for (int i = 0; i < RIGHE; i++) {
		matriceIncidenza[i][indiceArco] = NULL;
	}

}
template<class tipoNodo, class tipoArco>
void GrafoMatriceIncidenza<tipoNodo, tipoArco>::cancArco(int indiceNodoA,
		int indiceNodoB) {

	boolean check;
	int i = 0;

	//scorro le colonne finchè non trovo un l'arco che ci interessa
	while (i < COLONNE && check != true) {
		if (matriceIncidenza[indiceNodoA][i] != NULL
				&& matriceIncidenza[indiceNodoB][i] != NULL) {
			check = true;
		} else {
			i++;
		}
	}

	if (check == true) {
		cancArco_by_indice(i);
	}

}

template<class tipoNodo, class tipoArco>
ListaBidirezionale<cellaGrafo<tipoNodo>*, NodoLista<cellaGrafo<tipoNodo>*>*> GrafoMatriceIncidenza<
		tipoNodo, tipoArco>::adiacenti(int indice) {

	ListaBidirezionale<cellaGrafo<tipoNodo>*, NodoLista<cellaGrafo<tipoNodo>*>*> ListaNodi;
	ListaNodi.creaLista();

	if (esisteNodo(indice)) {
		int i;
		boolean check;

		NodoLista<cellaGrafo<tipoNodo>*>* pos;

		int j;
		for (int i = 0; i < COLONNE; i++) {
			check = false;
			if (matriceIncidenza[indice][i] == 1) {
				//cout << "Test" << endl;
				j = 0;
				while (j < RIGHE && check != true) {
					if (matriceIncidenza[j][i] == -1) {
						pos = ListaNodi.primoLista();
						ListaNodi.insLista(Nodi[i], pos);
						check = true;
					} else {
						j++;
					}

				}
			}
		}

	}

	return ListaNodi;
}

template<class tipoNodo, class tipoArco>
boolean GrafoMatriceIncidenza<tipoNodo, tipoArco>::esisteNodo(int indice) {
	boolean out;

	if (Nodi[indice] != NULL) {
		out = true;
	} else {
		out = false;
	}

	return out;
}

template<class tipoNodo, class tipoArco>
boolean GrafoMatriceIncidenza<tipoNodo, tipoArco>::esisteArco(int indiceNodoA,
		int indiceNodoB) {
	boolean out;

	if (esisteNodo(indiceNodoA) && esisteNodo(indiceNodoB)) {

		boolean check;
		int i = 0;

		while (i < COLONNE && check != true) {
			if (matriceIncidenza[indiceNodoA][i] != NULL
					&& matriceIncidenza[indiceNodoB][i] != NULL) {
				check = true;
			} else {
				i++;
			}
		}

		if (check == true) {
			out = true;
		}

	} else {
		out = false;
	}
	return out;
}

#endif /* GRAFOMATRICE_INCIDENZA_H */
