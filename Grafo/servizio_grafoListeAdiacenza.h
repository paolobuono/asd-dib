/*
 * servizo_grafoListeAdiacenza.h
 *
 *  Created on: 11/gen/2012
 *      Author: kiuzhack
 */

#ifndef SERVIZO_GRAFOLISTEADIACENZA_H_
#define SERVIZO_GRAFOLISTEADIACENZA_H_

#include "grafoListeAdiacenza.h"

void servizio_grafoListeAdiacenza();

void servizio_grafoListeAdiacenza() {

	GrafoListeAdiacenza<int, int> grafo;
	nodoGrafo<int> nodo;
	nodo = grafo.creaNodo();

	grafo.insNodo(nodo, 20);

	cout << "fine" << endl;

}

#endif /* SERVIZO_GRAFOLISTEADIACENZA_H_ */
