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

#ifndef _GRAFOVIRTUAL_h
#define _GRAFOVIRTUAL_h

#include <iostream>
using namespace std;
typedef bool boolean;

#include "cellaGrafo.h"
#include "arcoGrafo.h"
#include "../Lista/listaBidirezionale.h"

template<class tipoNodo, class tipoArco>
class GrafoVirtual {
public:
	GrafoVirtual();

	virtual void creaGrafo()=0;
	virtual boolean grafoVuoto()=0;
	virtual void insNodo(cellaGrafo<tipoNodo>*, tipoNodo)=0;

	virtual void insArco(cellaGrafo<tipoNodo>*, cellaGrafo<tipoNodo>*, tipoArco)=0;
	virtual void cancNodo(cellaGrafo<tipoNodo>*)=0;
	virtual void cancArco(cellaGrafo<tipoNodo>*, cellaGrafo<tipoNodo>*)=0;

	//virtual ListaBidirezionale<cellaGrafo<tipoNodo>,NodoLista<cellaGrafo<tipoNodo> >*> adiacenti( cellaGrafo<tipoNodo>*)=0;

	virtual boolean esisteNodo(cellaGrafo<tipoNodo>*)=0;
	virtual boolean esisteArco(cellaGrafo<tipoNodo>*, cellaGrafo<tipoNodo>*)=0;
};

template<class tipoNodo, class tipoArco>
GrafoVirtual<tipoNodo, tipoArco>::GrafoVirtual() {
	//ciao
}

#endif
