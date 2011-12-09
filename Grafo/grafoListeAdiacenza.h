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

//Utile per creare la lista di nodi del grafo
#include "../Lista/lista.h"

//Classe virtuale di Grafo
#include "grafo.h"

//Classe del nodo grafo, necessita di allegare un "tipoNodo"
#include "nodoGrafo.h"

//Classe dell'arco grafo, necessita di allegare un "tipo arco"
#include "arcoGrafo.h"

using namespace std;
typedef bool boolean;

template <class tipoNodo, class tipoArco>
class GrafoListeAdiacenza : public Grafo< tipoNodo, tipoArco > {
private:
    Lista< Lista < nodoGrafo < tipoNodo > > > listaNodi;

public:
	void creaGrafo();
    boolean grafoVuoto();
	void setOrientato( boolean setOrientato );
	void setPesato( boolean setPesato );

    void insNodo(nodoGrafo< tipoNodo >, tipoNodo);
	void insArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >);
    void insArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >, arcoGrafo < tipoArco >);

    void cancNodo(nodoGrafo< tipoNodo >);
    void cancArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >);

    boolean esisteNodo(nodoGrafo< tipoNodo >);
    boolean esisteArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoNodo >);
    Lista< Nodo< tipoNodo > > *adiacenti(nodoGrafo< tipoNodo >);

    tipoNodo leggiNodo(nodoGrafo< tipoNodo >);
    arcoGrafo < tipoArco > leggiArco(nodoGrafo< tipoNodo >, nodoGrafo< tipoArco >);

};

#endif /* _GrafoListeAdiacenza_H */
