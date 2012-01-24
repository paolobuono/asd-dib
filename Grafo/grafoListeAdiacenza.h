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

#include <stdlib.h>
#include <cstddef>

using namespace std;
typedef bool boolean;

#include "grafo.h"          //Classe virtuale di Grafo
#include "nodoGrafo.h"      //Classe del nodo grafo,  necessita di allegare un "tipoNodo"
#include "arcoGrafo.h"      //Classe dell'arco grafo, necessita di allegare un "tipo arco"
#include "../Lista/listaUnidirezionale.h" //Utile per creare la lista di nodi del grafo
template<class tipoNodo, class tipoArco>
class GrafoListeAdiacenza: public Grafo<tipoNodo, tipoArco> {
private:
	ListaUnidirezionale<ListaUnidirezionale<nodoGrafo<tipoNodo> > > listaAdiacenza;

public:
	typedef nodoGrafo<tipoNodo> nodoGrafoListaAdiacenza;

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

	//Funzioni Aggiuntive
	nodoGrafo<tipoNodo> creaNodo();

	ListaUnidirezionale<Nodo<tipoNodo> > *adiacenti(nodoGrafo<tipoNodo>);
};

template<class tipoNodo, class tipoArco>
void GrafoListeAdiacenza<tipoNodo, tipoArco>::creaGrafo() {

	//inizializza il grafo con la lista di adiacenza vuota
	listaAdiacenza.creaLista();
}

template<class tipoNodo, class tipoArco>
nodoGrafo<tipoNodo> GrafoListeAdiacenza<tipoNodo, tipoArco>::creaNodo() {

	nodoGrafo<tipoNodo> nodo;
	return (nodo);
}

/*
 INSNODO (u, a, G) = G'
 PRE: G = (N,A) u NON APPARTIENE ad N, a E’ DI TIPO TIPONODO
 POST: G' = (N’,A) N' = N U {u}
 */
template<class tipoNodo, class tipoArco>
void GrafoListeAdiacenza<tipoNodo, tipoArco>::insNodo(nodoGrafo<tipoNodo> nodo,
		tipoNodo infNodo) {
	//creo un nuovo nodo
	nodoGrafo<tipoNodo> nuovo_nodo;

	//allego l'informazione
	//nuovo_nodo->infoNodo = infNodo;

	//TODO serve un metodo per inserire alla fine della lista
	//listaAdiacenza.insLista(nuovo_nodo, posizione&);
}
/*
 INSARCO (u, v, peso G) = G‘
 PRE: u APPARTIENE ad N, v APPARTIENE ad N e non esiste arco tra u e v
 POST: G' = (N,A') , A' = A ? {(u,v)}
 */
template<class tipoNodo, class tipoArco>
void GrafoListeAdiacenza<tipoNodo, tipoArco>::insArco(nodoGrafo<tipoNodo>,
		nodoGrafo<tipoNodo>) {

	//SEARCH nodo1 into listaAdiacenza
	//SEARCH nodo2 into listaAdiecenza

	//aggiungi nodo adiacente a listaAdiacenza[NODO1]
	//aggiungi nodo adiacente a listaAdiacenza[NODO2]
}

template<class tipoNodo, class tipoArco>
boolean GrafoListeAdiacenza<tipoNodo, tipoArco>::esisteArco(nodoGrafo<tipoNodo>,
		nodoGrafo<tipoNodo>) {
	boolean out;

	return (out);
}

/*
 GRAFOVUOTO (G) = b
 PRE: NESSUNA
 POST: b=VERO SE N=0 E A=0 b=FALSO ALTRIMENTI

 //Modificata, basta controllare se non ci sono NODI in N
 POST: b=VERO SE N=0 b=FALSO ALTRIMENTI
 */
template<class tipoNodo, class tipoArco>
boolean GrafoListeAdiacenza<tipoNodo, tipoArco>::grafoVuoto() {
	boolean out;
	if (listaAdiacenza.listaVuota()) {
		out = true;
	} else {
		out = false;
	}
	return (out);
}

template<class tipoNodo, class tipoArco>
boolean GrafoListeAdiacenza<tipoNodo, tipoArco>::esisteNodo(
		nodoGrafo<tipoNodo> n) {
	boolean out;
	/*if (listaAdiacenza.cerca(n)) {
	 out = true;
	 } else {
	 out = false;
	 }*/
	return (out);
}

#endif /* _GrafoListeAdiacenza_H */
