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

#ifndef _dizionarioBase_h
#define _dizionarioBase_h

#include <string>
#include <iostream>
using namespace std;

#include "datoDizionario.h"

//typedef int chiave;
//TODO:fare in modo che chiave sia un tipo generico
//typedef string elemento;

template<class elemento, class chiave>
class Dizionario {
public:
	Dizionario();
	virtual void inserisci(elemento, chiave)=0;
	virtual void cancella(chiave)=0;
	virtual elemento cerca(chiave)=0;
};

template<class elemento, class chiave>
Dizionario<elemento, chiave>::Dizionario() {
}

#endif
