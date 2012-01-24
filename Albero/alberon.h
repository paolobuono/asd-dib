/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *   Modified by Minerva Fabio                                             *
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

#ifndef ALBERO_N_H
#define ALBERO_N_H
#include "nodoenn.h"

using namespace std;

template<class T>
class alberon {
public:
	virtual void creaAlbero()=0;
	virtual bool alberoVuoto()=0;
	virtual void insRadice(T)=0;
	virtual nodo<T>* Radice()=0;
	virtual nodo<T>* Padre(nodo<T>*)=0;
	virtual bool Foglia(nodo<T>*)=0;
	virtual nodo<T>* primoFiglio(nodo<T>*)=0;
	virtual bool ultimoFratello(nodo<T>*)=0;
	virtual nodo<T>* succFratello(nodo<T>*)=0;
	virtual void insPrimofg(T, nodo<T>*)=0;
	virtual void insFratellosucc(T, nodo<T>*)=0;
	virtual T leggiNodo(nodo<T>*)=0;
	virtual void scriviNodo(T, nodo<T>*)=0;
	virtual void cancSottoalbero(nodo<T>*)=0;
};

#endif
