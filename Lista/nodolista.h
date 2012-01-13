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

#ifndef _nodo_lista_h
#define _nodo_lista_h

/*MODIFY BY Minerva Fabio ON 11-Dec-27*/
/*MODIFY BY DomenicoMOnaco ON 12-Gen-12*/

template<class T>
class NodoLista {
private:
	T elemento;
	NodoLista<T>* succ;
	NodoLista<T>* prec;
public:
	T leggiElem();
	NodoLista<T>* leggiSucc();
	NodoLista<T>* leggiPrec();
	void scriviElem(T);
	void scriviSucc(NodoLista<T>*);
	void scriviPrec(NodoLista<T>*);
};

template<class T>
T NodoLista<T>::leggiElem() {
	return elemento;
}

template<class T>
NodoLista<T>* NodoLista<T>::leggiSucc() {
	return succ;
}

template<class T>
NodoLista<T>* NodoLista<T>::leggiPrec() {
	return prec;
}

template<class T>
void NodoLista<T>::scriviElem(T e) {
	elemento = e;
}

template<class T>
void NodoLista<T>::scriviSucc(NodoLista<T>* s) {
	succ = s;
}

template<class T>
void NodoLista<T>::scriviPrec(NodoLista<T>* p) {
	prec = p;
}

#endif
