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

#ifndef _GrafoListeAdiacenza_H
#define _GrafoListeAdiacenza_H

/*
GRAFO
SPECIFICA SINTATTICA
CREAGRAFO	: () -> -
GRAFOVUOTO	: () -> BOOLEAN
INSNODO		: (NODO,TIPONODO) ->  - 
INSARCO		: (NODO,NODO) ->  - 
CANCNODO	: (NODO) ->  - 
CANCARCO	: (NODO,NODO) ->  - 
ADIACENTI	: (NODO) -> LISTA
ESISTENODO	: (NODO) -> BOOLEAN
ESISTEARCO	: (NODO,NODO) -> BOOLEAN
*/

#include <stdlib.h>
#include "../Lista/lista.h"
#include "grafo.h"
#include "nodoGrafo.h"
#include "arcoGrafo.h"

using namespace std;
typedef bool boolean;

template <class T, class A>
class GrafoListeAdiacenza : public Grafo<T, A> {
private:
    Lista < Lista < nodoGrafo < T > > > listaNodi;

public:
	void creaGrafo();
    boolean grafoVuoto();
	void setOrientato( boolean setOrientato );
	void setPesato( boolean setPesato );

    void insNodo(nodoGrafo< T >, T);
	void insArco(nodoGrafo< T >, nodoGrafo< T >);
    void insArco(nodoGrafo< T >, nodoGrafo< T >, arcoGrafo < A >);
    
    void cancNodo(nodoGrafo< T >);
    void cancArco(nodoGrafo< T >, Nodo<T>);
		
    boolean esisteNodo(nodoGrafo< T >);
    boolean esisteArco(nodoGrafo< T >, nodoGrafo< T >);
    Lista< Nodo<T> > *adiacenti(nodoGrafo< T >);
           
    T leggiNodo(nodoGrafo< T >);
    arcoGrafo < A > leggiArco(nodoGrafo< T >, nodoGrafo< T >);

};
#endif /* _GrafoListeAdiacenza_H */
