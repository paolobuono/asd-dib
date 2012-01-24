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

#ifndef _GrafoMatriciAdiacenza_H
#define _GrafoMatriceAdiacenza_H

/*
 GRAFO - SPECIFICA SINTATTICA
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
#define RIGHe 100
#define COLONNE 100

using namespace std;
typedef bool boolean;

#include "grafo.h" //Classe virtuale di Grafo
#include "nodoGrafo.h" //Classe del nodo grafo, necessita di allegare un "tipoNodo"
#include "arcoGrafo.h"

#include "../Lista/lista.h" //Utile per creare la lista di nodi del grafo
template <class tipoNodo, class tipoArco>
class GrafoListeMatriceIncidenza: public Grafo<tipoNodo, tipoArco> {
public:
	//LISTA NODI
	/*
	 * Lista ordinata di nodi dove le posizioni 0 > i > n
	 * corrispondono alle 0 > i > n righe e colonne della mat. adiacenza
	 **/
	Lista < nodoGrafo < tipoNodo > > > listaNodi;

	//LISTA ARCHI
	//TODO non so ancora come collegare l'informazione arco
	//alla matrice di incidenza
	//
	Lista < arcoGrafo < tipoArco > > > listaArchi;

	//MATRICE INCIDENZA (1,0)
	/*
	 * matrice quadrata n X n dove righe e colonne corrispondono ai nodi
	 * ordinati nella lista nodi
	 **/
	bool matriceIncidenza[RIGHE][COLONNE];

	//METODI di base
	void creaGrafo();
	boolean grafoVuoto();
	void setOrientato(boolean setOrientato);
	void setPesato(boolean setPesato);

	void insNodo(nodoGrafo<tipoNodo>, tipoNodo);
	void cancNodo(nodoGrafo<tipoNodo>);
	boolean esisteNodo(nodoGrafo<tipoNodo>);
	tipoNodo leggiNodo(nodoGrafo<tipoNodo>);

	void insArco(nodoGrafo<tipoNodo>, nodoGrafo<tipoNodo>);
	void insArco(nodoGrafo<tipoNodo>, nodoGrafo<tipoNodo>, arcoGrafo<tipoArco>);
	void cancArco(nodoGrafo<tipoNodo>, nodoGrafo<tipoNodo>);
	boolean esisteArco(nodoGrafo<tipoNodo>, nodoGrafo<tipoNodo>);
	arcoGrafo<tipoArco> leggiArco(nodoGrafo<tipoNodo>, nodoGrafo<tipoArco>);

	Lista<Nodo<tipoNodo> > *adiacenti(nodoGrafo<tipoNodo>);

}

#endif
