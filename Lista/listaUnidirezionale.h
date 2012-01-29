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

#ifndef _listaunidirezionale_h
#define _listaunidirezionale_h

#include <cstdlib>
#include <iostream>

#include "lista.h"
#include "nodolista.h"

using namespace std;

typedef bool boolean;

template<class tipoelem, class posizione>
class ListaUnidirezionale: public Lista<tipoelem, posizione> {
public:
	//posizione come untatore a nodo
	//typedef NodoLista<tipoelem> * posizione;

	ListaUnidirezionale();

	void creaLista();

	boolean listaVuota();

	tipoelem leggiLista(posizione);

	void scriviLista(tipoelem, posizione);

	void insLista(tipoelem, posizione&);

	posizione primoLista();

	boolean fineLista(posizione);

	posizione succLista(posizione);

	posizione predLista(posizione);

	void cancLista(posizione);

private:
	posizione testa;
};

template<class T, class posizione>
ListaUnidirezionale<T,posizione>::ListaUnidirezionale() {
	creaLista();
}


template<class T, class posizione>
void ListaUnidirezionale<T,posizione>::creaLista() {
	testa = NULL;
}


template<class T, class posizione>
boolean ListaUnidirezionale<T,posizione>::listaVuota() {
	return (testa == NULL);
}


template<class T, class posizione>
T ListaUnidirezionale<T,posizione>::leggiLista(posizione p) {
	return p->leggiElem();
}


template<class tipoelem, class posizione>
void ListaUnidirezionale<tipoelem,posizione>::scriviLista(tipoelem t, posizione p) {
	p->scriviElem(t);
}


template<class T, class posizione>
posizione ListaUnidirezionale<T,posizione>::primoLista() {
	return testa;
}


template<class tipoelem, class posizione>
void ListaUnidirezionale<tipoelem,posizione>::insLista(tipoelem t, posizione &p) {
	posizione temp = new NodoLista<tipoelem>();
	temp->scriviElem(t);
	temp->scriviSucc(p);
	if (p == primoLista()) {
		testa = temp;
	} else {
		posizione prec = predLista(p);
		prec->scriviSucc(temp);
	}
}



template<class T, class posizione>
void ListaUnidirezionale<T,posizione>::cancLista(posizione p) {
	NodoLista<T> * temp;
	temp = predLista(p);
	temp->scriviSucc(p->leggiSucc());
	delete p;
}


template<class T, class posizione>
boolean ListaUnidirezionale<T,posizione>::fineLista(posizione p) {
	return (succLista(p) == NULL) ? true : false; //todo: da specifiche: vero se posizione è oltre l'ultimo elemento (n+1)
}


template<class T, class posizione>
posizione ListaUnidirezionale<T,posizione>::succLista(posizione p) {
	return p->leggiSucc();
}


template<class T, class posizione>
posizione ListaUnidirezionale<T,posizione>::predLista(posizione p) {
	posizione p1 = primoLista();
	while (!fineLista(p1) && (p1->leggiSucc() != p)) {
		p1 = succLista(p1);
	}
	return p1;
}

#endif //listaunidir_h
