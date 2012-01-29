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

#ifndef _listabidirezionale_h
#define _listabidirezionale_h

#include <cstdlib>
#include <iostream>
using namespace std;

typedef bool boolean;

#include "lista.h"
#include "nodolista.h"

template<class tipoelem, class posizione>
class ListaBidirezionale: public Lista<tipoelem, posizione> {
public:
	//posizione come untatore a nodo
	//typedef NodoLista<tipoelem> * posizione;

	ListaBidirezionale();

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
ListaBidirezionale<T, posizione>::ListaBidirezionale() {
	creaLista();
}

template<class T, class posizione>
void ListaBidirezionale<T, posizione>::creaLista() {
	testa = NULL;
}

template<class T, class posizione>
boolean ListaBidirezionale<T, posizione>::listaVuota() {
	return (testa == NULL);
}

template<class T, class posizione>
T ListaBidirezionale<T, posizione>::leggiLista(posizione p) {
	return p->leggiElem();
}

template<class tipoelem, class posizione>
void ListaBidirezionale<tipoelem, posizione>::scriviLista(tipoelem t,
		posizione p) {
	p->scriviElem(t);
}

template<class T, class posizione>
posizione ListaBidirezionale<T, posizione>::primoLista() {
	return testa;
}

/**
 * @title: insLista
 * @param: tipoelem t
 * @param: posizione &p
 *
 * @desc:Inserisce l'elemento t in posizione p
 * se la posizione é NULL assumo per scelta che venga posto a fine lista,
 * questo perchè è facile recuperare il primo lista pertanto risulta altrettanto facile
 * posizionarlo volontariamente in cima alla lista
 */
template<class tipoelem, class posizione>
void ListaBidirezionale<tipoelem, posizione>::insLista(tipoelem t,
		posizione &p) {

	NodoLista<tipoelem> *temp = new NodoLista<tipoelem>();
	posizione prec;

	temp->scriviElem(t);
	temp->scriviSucc(p);

	if (p == primoLista()) {
		testa = temp;

		//se P è DIVERSO da NULL vuol dire che ce almeno un elemento in LISTA
		// va sostituito il PREC di P con TEMP, che sta ora in testa
		if (p != NULL) {
			p->scriviPrec(temp);
		}
	} else {

		if (p != NULL) {
			prec = predLista(p);
			prec->scriviSucc(temp);
			temp->scriviPrec(prec);
			p->scriviPrec(temp);

		} else if (p == NULL) {

			p = primoLista();

			while (!fineLista(p)) {
				p = succLista(p);
			}

			prec = predLista(p);

			if (primoLista() != p) {
				p->scriviSucc(temp);
				temp->scriviPrec(p);
			} else {
				temp->scriviPrec(p);
				p->scriviSucc(temp);
				temp->scriviSucc(NULL);
			}
		} else {
			temp->scriviPrec(predLista(p));
			p->scriviPrec(temp);
		}
	}
}

template<class T, class posizione>
void ListaBidirezionale<T, posizione>::cancLista(posizione p) {

	NodoLista<T> *tempprec;
	NodoLista<T> *tempsucc;

	if (!(p == primoLista() || fineLista(p))) {

		tempprec = predLista(p);
		tempsucc = succLista(p);

		tempprec->scriviSucc(tempsucc);
		tempsucc->scriviPrec(tempprec);

	} else if ((p == primoLista() && fineLista(p))) {
		testa = NULL;

	} else if ((p == primoLista() && !fineLista(p))) {

		tempsucc = succLista(p);
		testa = tempsucc;
		tempsucc->scriviPrec(NULL);

	} else if ((!(p == primoLista()) && fineLista(p))) {
		tempprec = predLista(p);
		tempprec->scriviSucc(NULL);
	}

	delete p;
}

template<class T, class posizione>
boolean ListaBidirezionale<T, posizione>::fineLista(posizione p) {
	return (succLista(p) == NULL) ? true : false;
}

template<class T, class posizione>
posizione ListaBidirezionale<T, posizione>::succLista(posizione p) {
	return p->leggiSucc();
}

template<class T, class posizione>
posizione ListaBidirezionale<T, posizione>::predLista(posizione p) {
	return p->leggiPrec();
}

#endif //_listabidirezionale_h
