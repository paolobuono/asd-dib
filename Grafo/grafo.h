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

#ifndef _Grafo_h
#define _Grafo_h

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
#include "../Lista/lista.h" //Utile per creare la lista di nodi del grafo
#include "nodoGrafo.h"      //Classe del nodo grafo, necessita di allegare un "tipoNodo"
#include "arcoGrafo.h"      //Classe dell'arco grafo, necessita di allegare un "tipo arco"

using namespace std;
typedef bool boolean;

//TODO vanno eliminati metodi e variabili dipendenti dall'implementazione del grafo.

template < class tipoNodo, class tipoArco >
class Grafo {
//private:
		  //Lista< Lista < nodoGrafo < tipoNodo > > > listaNodi;
public:
	virtual void creaGrafo();
    virtual boolean grafoVuoto();
	virtual void setOrientato( boolean setOrientato );
	virtual void setPesato( boolean setPesato );

    virtual void insNodo(nodoGrafo< tipoNodo >, tipoNodo);
    virtual void cancNodo(nodoGrafo< tipoNodo >);
    virtual boolean esisteNodo(nodoGrafo< tipoNodo >);
    virtual tipoNodo leggiNodo(nodoGrafo< tipoNodo >);

    virtual void insArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >);
    virtual void insArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >, arcoGrafo < tipoArco >);
    virtual void cancArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >);
    virtual boolean esisteArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >);
    virtual arcoGrafo < tipoArco > leggiArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoArco >);
    
    virtual Lista< Nodo< tipoNodo > > *adiacenti(nodoGrafo< tipoNodo >);
};

#endif
