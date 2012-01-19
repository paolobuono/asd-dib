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

#ifndef ASD_datoDizionario_h
#define ASD_datoDizionario_h

#include <string>
#include <iostream>
using namespace std;

template<class T>
class Dato {
public:
	Dato();
	Dato(int, T);
	int chiaveDato;
	T elementoDato;
};

template<class T>
Dato<T>::Dato() {
	chiaveDato = 0;
}

template<class T>
Dato<T>::Dato(int k, T s) {
	chiaveDato = k;
	elementoDato = s;
}

#endif
