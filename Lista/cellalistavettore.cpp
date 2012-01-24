/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *   Created by Sasso Patrizia                                             *
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

#include <cstdlib>
#include <iostream>
using namespace std;

typedef bool boolean;

#include "cellalistavettore.h"

template<class tipoelem>
CellaListaVettori<tipoelem>::CellaListaVettori() {
}

template<class tipoelem>
tipoelem CellaListaVettori<tipoelem>::leggi_valore() {
	return valore;
}

template<class tipoelem>
void CellaListaVettori<tipoelem>::scrivi_valore(tipoelem v) {
	valore = v;
}

