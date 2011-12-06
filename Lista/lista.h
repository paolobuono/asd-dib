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

#ifndef lista_h
#define lista_h
#include "../Dati/nodo.h"

using namespace std;

typedef bool boolean;

template <class tipoelem>
class Lista{
public:
    typedef Nodo <tipoelem> * posizione;
    virtual void creaLista ()=0;
    virtual boolean listaVuota()=0;
    virtual tipoelem leggiLista(posizione)=0;
    virtual void scriviLista(tipoelem,posizione)=0;
    virtual void insLista(tipoelem, posizione&)=0;
    virtual posizione primoLista()=0;
    virtual boolean fineLista(posizione)=0;
    virtual posizione succLista(posizione)=0;
    virtual posizione predLista(posizione)=0;
    virtual void cancLista(posizione)=0;
};

#endif //lista_h
