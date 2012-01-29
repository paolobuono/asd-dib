/*
 * servizio_grafoListaArchi.h
 *
 *  Created on: 19/gen/2012
 *      Author: Domenico Monaco
 */

#ifndef SERVIZIO_GRAFOLISTAARCHI_H_
#define SERVIZIO_GRAFOLISTAARCHI_H_

#include "../Grafo/grafo.h"
#include "../Grafo/cellaGrafo.h"
#include "../Grafo/arcoGrafoListaArchi.h"

#include "../Grafo/grafoListaArchi.h"

void servizio_grafoListaArchi();
void stampaTuttiArchi(GrafoListaArchi<int, int> grafoInteri);
void stampaTuttiNodi(GrafoListaArchi<int, int> grafoInteri);

void servizio_grafoListaArchi() {

	GrafoListaArchi<int, int> grafoInteri;
	grafoInteri.creaGrafo();

	cellaGrafo<int>* nodo1;
	cellaGrafo<int>* nodo2;
	cellaGrafo<int>* nodo3;
	cellaGrafo<int>* nodo4;

	//NON verrˆ aggiunto
	cellaGrafo<int>* nodo5;
	nodo5 = new cellaGrafo<int>;

	nodo1 = new cellaGrafo<int>;
	grafoInteri.insNodo(nodo1, 1);
	nodo2 = new cellaGrafo<int>;
	grafoInteri.insNodo(nodo2, 2);
	nodo3 = new cellaGrafo<int>;
	grafoInteri.insNodo(nodo3, 3);
	nodo4 = new cellaGrafo<int>;
	grafoInteri.insNodo(nodo4, 4);

	arcoGrafoListaArchi<int, int>* arco1;
	arco1 = new arcoGrafoListaArchi<int, int>;
	grafoInteri.insArco(nodo1, nodo2, arco1, 1);

	arcoGrafoListaArchi<int, int>* arco2;
	arco2 = new arcoGrafoListaArchi<int, int>;
	grafoInteri.insArco(nodo2, nodo3, arco2, 2);

	arcoGrafoListaArchi<int, int>* arco3;
	arco3 = new arcoGrafoListaArchi<int, int>;
	grafoInteri.insArco(nodo3, nodo1, arco3, 3);

	arcoGrafoListaArchi<int, int>* arco4;
	arco4 = new arcoGrafoListaArchi<int, int>;
	grafoInteri.insArco(nodo3, nodo4, arco4, 4);

	arcoGrafoListaArchi<int, int>* arco5;
	arco5 = new arcoGrafoListaArchi<int, int>;
	grafoInteri.insArco(nodo4, nodo2, arco5, 5);

	cout << "#### StampaTutto  ####" << endl;
	stampaTuttiArchi(grafoInteri);
	stampaTuttiNodi(grafoInteri);

}
void stampaTuttiNodi(GrafoListaArchi<int, int> grafoInteri) {

	typedef cellaGrafo<int> nodoGrafo;

	nodoGrafo* posizione;

	NodoLista<nodoGrafo*>* pos = grafoInteri.ListaNodi.primoLista();
	NodoLista<nodoGrafo*>* pos_adi;

	ListaBidirezionale<cellaGrafo<int>*, NodoLista<cellaGrafo<int>*>*> Adiacenti;

	while (pos != NULL) {
		Adiacenti.creaLista();

		posizione = pos->leggiElem();

		Adiacenti = grafoInteri.adiacenti(posizione);

		cout << "Nodo#" << pos->leggiElem()->getInfo() << " " << endl;

		pos_adi = Adiacenti.primoLista();

		while (pos_adi != NULL) {
			cout << "adiacente#" << pos_adi->leggiElem()->getInfo() << " "
					<< endl;
			pos_adi = Adiacenti.succLista(pos_adi);
		}
		cout << "   " << endl;

		//cout << "Adiacenti#" << pos->leggiElem()->getInfo() << " " << endl;

		pos = grafoInteri.ListaNodi.succLista(pos);
	}

}
void stampaTuttiArchi(GrafoListaArchi<int, int> grafoInteri) {

	typedef arcoGrafoListaArchi<int, int> arcoGrafo;
	NodoLista<arcoGrafo*>* pos = grafoInteri.ListaArchi.primoLista();

	while (pos != NULL) {
		cout << "Arco#" << pos->leggiElem()->getInfo() << " "
				<< pos->leggiElem()->leggiNodoPartenza()->getInfo() << "->"
				<< pos->leggiElem()->leggiNodoArrivo()->getInfo() << endl;
		pos = grafoInteri.ListaArchi.succLista(pos);
	}

}

#endif /* SERVIZIO_GRAFOLISTAARCHI_H_ */
