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

#ifndef CODAPUNT_H
#define CODAPUNT_H
#include "../Dati/nodo.h"
using namespace std;

typedef bool boolean;

template<class T>
class Coda {
public:
	void creaCoda();
	boolean codaVuota();
	T leggiCoda();
	void fuoriCoda();
	void inCoda(T);
	Coda();
private:
	Nodo<T>* testa;
	Nodo<T>* fondo;
};

template<class T>
void Coda<T>::creaCoda() {
	testa = NULL;
	fondo = NULL;
}

template<class T>
boolean Coda<T>::codaVuota() {
	return testa == NULL;
}

template<class T>
T Coda<T>::leggiCoda() {
	return testa->leggiElem();
}

template<class T>
void Coda<T>::inCoda(T a) {
	if (codaVuota()) {
		fondo = new (Nodo<T> );
		testa = fondo;
	} else {
		fondo->scriviSucc(new (Nodo<T> ));
		fondo = fondo->leggiSucc();
	}
	fondo->scriviElem(a);
	fondo->scriviSucc(NULL);
}

template<class T>
void Coda<T>::fuoriCoda() {
	Nodo<T> * temp;
	if (!codaVuota()) {
		temp = testa;
		testa = testa->leggiSucc();
		delete temp;
	}
}

template<class T>
Coda<T>::Coda() {
	creaCoda();
}

#endif //CODA_PUNT_H
