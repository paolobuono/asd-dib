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

#include <string>
#include <iostream>

using namespace std;

#include "dizionario.h"
#include "datoDizionario.h"

#include "../Lista/listaBidirezionale.h"
#include "../Lista/nodolista.h"

template<class elemento, class chiave>
class DizionarioLista: public Dizionario<elemento, chiave> {
public:
	void inserisci(elemento, chiave);
	void cancella(chiave);
	elemento cerca(chiave);
	DizionarioLista();
private:
	typedef Dato<elemento> DatoDiz;
	typedef NodoLista<DatoDiz>* posizione;

	ListaBidirezionale<DatoDiz, posizione> lista;

};

template<class elemento, class chiave>
void DizionarioLista<elemento, chiave>::inserisci(elemento e, chiave k) {

	bool trovato = false;

	posizione pos = lista.primoLista();
	NodoLista<DatoDiz> nodo;
	DatoDiz dato;

	while (pos != NULL && trovato != true) {

		dato = lista.leggiLista(pos);

		if (k == dato.chiaveDato) {
			trovato = true;
		} else {
			pos = lista.succLista(pos);
		}
	}

	if (!trovato) {
		dato.chiaveDato = k;
		dato.elementoDato = e;
		pos = lista.primoLista();
		lista.insLista(dato, pos);
	}
}

template<class elemento, class chiave>
DizionarioLista<elemento, chiave>::DizionarioLista() {
	lista.creaLista();
}

template<class elemento, class chiave>
void DizionarioLista<elemento, chiave>::cancella(chiave k) {
	bool trovato;
	posizione pos = lista.primoLista();
	NodoLista<DatoDiz> nodo;
	DatoDiz dato;

	while (pos != NULL && trovato != true) {
		dato = lista.leggiLista(pos);
		if (k == dato.chiaveDato) {
			lista.cancLista(pos);
			trovato = true;
		} else {
			pos = lista.succLista(pos);
		}
	}
}

template<class elemento, class chiave>
elemento DizionarioLista<elemento, chiave>::cerca(chiave k) {

	elemento risposta;
	bool trovato;

	posizione pos = lista.primoLista();
	NodoLista<DatoDiz> nodo;
	DatoDiz dato;

	while (pos != NULL && trovato != true) {
		dato = lista.leggiLista(pos);
		if (k == dato.chiaveDato) {
			risposta = dato.elementoDato;
			trovato = true;
		} else {
			pos = lista.succLista(pos);
		}
	}

	return risposta;
}

#endif
