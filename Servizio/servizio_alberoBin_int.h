/*
 * servizio_aberoBin.h
 *
 *  Created on: 20/gen/2012
 *      Author: Domenico Monaco
 */

#ifndef SERVIZIO_ALBEROBIN_H_
#define SERVIZIO_ALBEROBIN_H_

#include <iostream>
using namespace std;

#include "../Albero/alberobin.h"
#include "../Albero/cella_alberobin.h"
#include "../Albero/alberobin_impl.h"

typedef CellaAlbero<int>* Nodo;

void servizio_alberoBin_int();

void servizio_alberoBin_int() {

	AlberobinImpl<int> AlberoBinInt;

	AlberoBinInt.creaBinalbero();

	if (AlberoBinInt.binalberoVuoto()) {
		cout << "Appena creato, l'albero  vuoto" << endl;
	} else {
		cout << "Appena creato, l'albero  Non vuoto" << endl;
	}

	AlberoBinInt.insRadice();

	cout << "Inserita la radice, l'albero  " << endl;
	if (AlberoBinInt.binalberoVuoto()) {
		cout << "vuoto" << endl;
	} else {
		cout << "Non vuoto" << endl;
	}

	Nodo rad = AlberoBinInt.binRadice();

	AlberoBinInt.scriviNodo(10, rad);

	int out = AlberoBinInt.leggiNodo(rad);

	cout << "La radice contiene ora " << out << endl;
}

#endif /* SERVIZIO_ABEROBIN_H_ */
