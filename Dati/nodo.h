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

#ifndef ASD_nodo_h
#define ASD_nodo_h

/*MODIFY BY Minerva Fabio ON 11-Dec-27*/

template<class T>
class Nodo {
private:
	T elemento;
	Nodo<T>* succ;
	Nodo<T>* prec;
public:
	T leggiElem();
	Nodo<T>* leggiSucc();
	Nodo<T>* leggiPrec();
	void scriviElem(T);
	void scriviSucc(Nodo<T>*);
	void scriviPrec(Nodo<T>*);
};

template<class T>
T Nodo<T>::leggiElem() {
	return elemento;
}

template<class T>
Nodo<T>* Nodo<T>::leggiSucc() {
	return succ;
}

template<class T>
Nodo<T>* Nodo<T>::leggiPrec() {
	return prec;
}

template<class T>
void Nodo<T>::scriviElem(T e) {
	elemento = e;
}

template<class T>
void Nodo<T>::scriviSucc(Nodo<T>* s) {
	succ = s;
}

template<class T>
void Nodo<T>::scriviPrec(Nodo<T>* p) {
	prec = p;
}
#endif
