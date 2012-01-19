/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *   Created by Sasso Patrizia                                             *
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

#ifndef _LISTAVETTORE_H
#define _LISTAVETTORE_H

#include <iostream>
using namespace std;

#include "lista.h"
#include "cellalistavettore.h"

#define SIZE 100

template<class tipoelem, class posizione>
class listaVettore: public Lista<tipoelem, posizione> {
private:
	int primo;
	int lunghezza;
public:

	CellaListaVettori<int> vet[SIZE];

	listaVettore();
	void creaLista();
	bool listaVuota();
	tipoelem leggiLista(posizione);
	void scriviLista(tipoelem, posizione);
	posizione primoLista();
	bool fineLista(posizione);
	posizione succLista(posizione);
	posizione predLista(posizione);
	void insLista(tipoelem, posizione&);

	void cancLista(posizione);

	//CLASSI AGGIUNTIVE
	int lunghezzaLista();
};

template<class tipoelem, class posizione>
listaVettore<tipoelem, posizione>::listaVettore() {
	creaLista();
}

template<class tipoelem, class posizione>
void listaVettore<tipoelem, posizione>::creaLista() {
	primo = 0;
	lunghezza = 0;
}

template<class tipoelem, class posizione>
bool listaVettore<tipoelem, posizione>::listaVuota() {
	return (lunghezza == 0);
}

template<class tipoelem, class posizione>
tipoelem listaVettore<tipoelem, posizione>::leggiLista(posizione i) {
	tipoelem out;
	if (!listaVuota()) {
		out = vet[i].leggi_valore();
	}
	return out;
}

template<class tipoelem, class posizione>
void listaVettore<tipoelem, posizione>::scriviLista(tipoelem v, posizione i) {
	if (!listaVuota()) {
		vet[i].scrivi_valore(v);
	}
}

template<class tipoelem, class posizione>
posizione listaVettore<tipoelem, posizione>::primoLista() {
	return primo;
}

template<class tipoelem, class posizione>
bool listaVettore<tipoelem, posizione>::fineLista(posizione i) {
	return (i == (lunghezzaLista() - 1));
}

template<class tipoelem, class posizione>
posizione listaVettore<tipoelem, posizione>::succLista(posizione i) {
	posizione out;
	if (!fineLista(i)) {
		out = (i + 1);
	}
	return out;
}

template<class tipoelem, class posizione>
posizione listaVettore<tipoelem, posizione>::predLista(posizione i) {
	posizione out;
	if (i != primoLista()) {
		out = (i - 1);
	}
	return out;
}

template<class tipoelem, class posizione>
void listaVettore<tipoelem, posizione>::insLista(tipoelem v, posizione& p) {
	int i = p;
	if (lunghezza < SIZE) {
		if (listaVuota()) {
			lunghezza = 1;
			vet[i].scrivi_valore(v);
		} else if ((i > lunghezza)) {
			vet[i].scrivi_valore(v);
			lunghezza++;
		} else {
			lunghezza++;
			for (int k = lunghezza; k > i; k--) {
				vet[k].scrivi_valore((vet[k - 1].leggi_valore()));
			}
			vet[i].scrivi_valore(v);
		}
	}
}

template<class tipoelem, class posizione>
void listaVettore<tipoelem, posizione>::cancLista(posizione n) {
	if (!listaVuota()) {
		if (n < (lunghezza-1)) {
			for (int i = n; i < lunghezza; i++)
				scriviLista(vet[i + 1].leggi_valore(), i);
			lunghezza--;
		} else if (n == (lunghezza-1))
			lunghezza--;
	}
}

//CLASSI AGGIUNTIVE
template<class tipoelem, class posizione>
int listaVettore<tipoelem, posizione>::lunghezzaLista() {
	return lunghezza;
}

#endif
