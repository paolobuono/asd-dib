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

#ifndef _dizionarioLista_h
#define _dizionarioLista_h

#include "dizionario.h"
#include "../Lista/listaUnidirezionale.h"

template<class elemento, class chiave>
class DizionarioLista: public Dizionario<elemento, chiave> {
public:
	void inserisci(elemento, chiave);
	void cancella(chiave);
	elemento cerca(chiave);
	DizionarioLista();
private:
	ListaUnidirezionale<Dato<elemento> > lista;
};

template<class elemento, class chiave>
void DizionarioLista<elemento, chiave>::inserisci(elemento e, chiave k) {
	Dato<string> d;
	d.elementoDato = e;
	d.chiaveDato = k;
	NodoLista<Dato<string> > *posizione;
	boolean trovato = false;
	posizione = lista.primoLista();
	while (!lista.fineLista(posizione)) {
		if (lista.leggiLista(posizione).chiaveDato == d.chiaveDato)
			trovato = true;
		posizione = lista.succLista(posizione);
	}
	//inserisce sempre in testa, ottimizzare effettuando l'inserimento ordinato della lista
	if (!trovato) {
		posizione = lista.primoLista();
		lista.insLista(d, posizione);
	}
}

template<class elemento, class chiave>
DizionarioLista<elemento, chiave>::DizionarioLista() {
	lista.creaLista();
}

template<class elemento, class chiave>
void DizionarioLista<elemento, chiave>::cancella(chiave k) {
	boolean trovato = false;
	NodoLista<Dato<elemento> > *posizione;
	posizione = lista.primoLista();
	while ((!lista.fineLista(posizione)) && (!trovato)) {
		if (lista.leggiLista(posizione).chiaveDato == k) {
			lista.cancLista(posizione);
			trovato = true;
		}
		posizione = lista.succLista(posizione);
	}
	cout << "Dato con chiave " << k << " cancellato" << endl;
}

template<class elemento, class chiave>
elemento DizionarioLista<elemento, chiave>::cerca(chiave k) {
	boolean trovato = false;
	NodoLista<Dato<elemento> > *posizione;
	posizione = lista.primoLista();
	elemento e;
	while ((!lista.fineLista(posizione)) && (!trovato)) {
		if (lista.leggiLista(posizione).chiaveDato == k) {
			e = (lista.leggiLista(posizione)).elementoDato;
			trovato = true;
		}
		posizione = lista.succLista(posizione);
	}
	return e;
}

#endif

