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

#ifndef _arcoGrafoListaArchi_h
#define _arcoGrafoListaArchi_h

using namespace std;
typedef bool boolean;

#include "cellaGrafo.h"

template<class tipoArco, class tipoNodo>
class arcoGrafoListaArchi {
public:
	void setInfo(tipoArco);
	tipoArco getInfo();

	void setNodoPartenza(cellaGrafo<tipoNodo>*);
	void setNodoArrivo(cellaGrafo<tipoNodo>*);


	cellaGrafo<tipoNodo>* leggiNodoPartenza();
	cellaGrafo<tipoNodo>* leggiNodoArrivo();

private:
	cellaGrafo<tipoNodo>* NodoPartenza;
	cellaGrafo<tipoNodo>* NodoArrivo;
	tipoArco infoArco;

};

template<class T, class V>
void arcoGrafoListaArchi<T, V>::setInfo(T info) {
	infoArco = info;
}
template<class T, class V>
T arcoGrafoListaArchi<T, V>::getInfo() {
	return infoArco;
}

template<class T, class V>
void arcoGrafoListaArchi<T, V>::setNodoPartenza(cellaGrafo<V>* nodo){
	NodoPartenza = nodo;
}

template<class T, class V>
void arcoGrafoListaArchi<T, V>::setNodoArrivo(cellaGrafo<V>* nodo){
	NodoArrivo = nodo;
}

template<class T, class V>
cellaGrafo<V>* arcoGrafoListaArchi<T, V>::leggiNodoPartenza(){
	return NodoPartenza;
}

template<class T, class V>
cellaGrafo<V>* arcoGrafoListaArchi<T, V>::leggiNodoArrivo(){
	return NodoArrivo;
}
#endif //_arcoGrafoListaArchi_h
