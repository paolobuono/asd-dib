/*
 * --- Possibile soluzione traccia primo esonero ASD a.a. 2014-2015 - parte implementativa ---
 *
 * Si considerino i collegamenti ferroviari di alcuni capoluoghi di provincia dell’Italia Meridionale.
 * Ad ogni collegamento sono associate le informazioni relative a
 * - tempo di durata del viaggio
 * - costo del biglietto.
 * Progettare un algoritmo che, data una citta, stampi le informazioni di tutti i collegamenti diretti
 * con le altre città, cioé dei collegamenti che non hanno fermate intermedie.
 *
 * Risolvere l’esercizio considerando i seguenti punti:
 * - definendo il problema in termini di output attesi, input, ipotesi/requisiti di progetto, struttura/e dati che si intende utilizzare;
 * - delineando l’algoritmo, descritto in pseudo-linguaggio;
 * - indicando, motivandone la scelta, una possibile realizzazione della/e struttura/e dati.
 *
 */

#ifndef SOLUZIONE_PRIMO_ESONERO_1415_H_
#define SOLUZIONE_PRIMO_ESONERO_1415_H_

#include <iostream>
using namespace std;
typedef bool boolean;

#include "../../Dati/dati1es1415.h"
#include "../../Grafo/grafoMatriciAdiacenza.h"

void soluzioneEsonero1415() {

	GrafoMatriceAdiacenza<nodoEsercizio, arcoEsercizio> citta;
	nodoEsercizio unaCitta;
	arcoEsercizio unCollegamento;

	citta.creaGrafo();

	/* inserimento nodi */
	unaCitta.nomeCitta = "Bari";
	citta.insNodo(0, unaCitta); //#0
	unaCitta.nomeCitta = "Foggia";
	citta.insNodo(1, unaCitta); //#1
	unaCitta.nomeCitta = "Brindisi";
	citta.insNodo(2, unaCitta); //#2
	unaCitta.nomeCitta = "Taranto";
	citta.insNodo(3, unaCitta); //#3
	unaCitta.nomeCitta = "Lecce";
	citta.insNodo(4, unaCitta); //#4
	unaCitta.nomeCitta = "BAT";
	citta.insNodo(5, unaCitta); //#5
	cout << "inseriti 6 nodi" << endl;

	/* inserimento archi */
	unCollegamento.costoBiglietto = 10;
	unCollegamento.tempodurata = 30;
	citta.insArco(0, 1, unCollegamento);
	unCollegamento.costoBiglietto = 5;
	unCollegamento.tempodurata = 20;
	citta.insArco(0, 5, unCollegamento);
	citta.insArco(1, 3, unCollegamento);
	citta.insArco(3, 5, unCollegamento);
	citta.insArco(5, 4, unCollegamento);
	citta.insArco(4, 2, unCollegamento);
	citta.insArco(2, 0, unCollegamento);
	cout << "inseriti archi <0,1> <0,5> <1,3> <3,5> <5,4> <4,2> <2,0>" << endl;

	ListaBidirezionale<int, NodoLista<int>*> listaNodiAdi;
	int nodoInput = 0;

	listaNodiAdi = citta.adiacenti(nodoInput);

	if (listaNodiAdi.listaVuota()) {
		cout << "il nodo " << citta.nodo(nodoInput)->getInfo().nomeCitta << " non ha adiacenti" << endl;
	} else {
		cout << "adiacenti del nodo " << citta.nodo(nodoInput)->getInfo().nomeCitta << ":" << endl;
		NodoLista<int>* pos = listaNodiAdi.primoLista();
		while (!listaNodiAdi.fineLista(pos)) {
			cout << citta.nodo(listaNodiAdi.leggiLista(pos))->getInfo().nomeCitta << endl;
			cout << "tempo: " << citta.arco(nodoInput, listaNodiAdi.leggiLista(pos))->getInfo().tempodurata << endl;
			cout << "costo: " << citta.arco(nodoInput, listaNodiAdi.leggiLista(pos))->getInfo().costoBiglietto << endl;
			pos = listaNodiAdi.succLista(pos);
		}
	}
}

#endif /* SOLUZIONE_PRIMO_ESONERO_1415_H_ */
