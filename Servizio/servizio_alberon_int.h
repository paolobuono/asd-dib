/*
 * servizio_alberon_int.h
 *
 *  Created on: 21/gen/2012
 *      Author: kiuzhack
 */

#ifndef SERVIZIO_ALBERON_INT_H_
#define SERVIZIO_ALBERON_INT_H_

#include <iostream>
using namespace std;

#include "../Albero/alberon.h"
#include "../Albero/cella_alberon.h"
#include "../Albero/alberon_impl.h"

void servizio_alberon_int();
void servizio_alberon_int() {

	AlberonImpl<int> AlberoInteri;
	AlberoInteri.creaAlbero();

	if (AlberoInteri.alberoVuoto()) {
		cout << "L'albero  vuoto" << endl;
	} else {
		cout << "L'albero NON  vuoto" << endl;
	}

	cout << "Inserisco Radice 45" << endl;
	AlberoInteri.insRadice(45);

	if (AlberoInteri.alberoVuoto()) {
		cout << "L'albero  vuoto" << endl;
	} else {
		cout << "L'albero NON  vuoto" << endl;
	}

	CellaAlberoN<int>* rad;
	CellaAlberoN<int>* nodoGen;
	CellaAlberoN<int>* nodo2Gen;
	CellaAlberoN<int>* nodo3Gen;

	rad = AlberoInteri.Radice();
	int outint = rad->leggiInfo();
	cout << "LA radice  " << outint << endl;

	AlberoInteri.insPrimofiglio(60, rad);

	nodoGen = AlberoInteri.primoFiglio(rad);
	cout << "Il primo figlio di RAD  " << nodoGen->leggiInfo() << endl;

	AlberoInteri.insFratellosucc(65, nodoGen);
	nodo2Gen = AlberoInteri.succFratello(nodoGen);
	cout << "Il primo fratello di '60'  " << nodo2Gen->leggiInfo() << endl;

	AlberoInteri.insFratellosucc(38, nodo2Gen);
	nodoGen = nodo2Gen = AlberoInteri.succFratello(nodo2Gen);
	cout << "Il primo fratello di '65'  " << nodo2Gen->leggiInfo() << endl;

	AlberoInteri.insFratellosucc(28, nodo2Gen);
	nodo3Gen = nodo2Gen = AlberoInteri.succFratello(nodo2Gen);
	cout << "Il primo fratello di '38'  " << nodo2Gen->leggiInfo() << endl;

	AlberoInteri.insPrimofiglio(36, nodo2Gen);
	nodo2Gen = AlberoInteri.primoFiglio(nodo2Gen);
	cout << "Il primofiglio di '28'  " << nodo2Gen->leggiInfo() << endl;

	AlberoInteri.cancSottoalbero(nodo3Gen);


}

#endif /* SERVIZIO_ALBERON_INT_H_ */
