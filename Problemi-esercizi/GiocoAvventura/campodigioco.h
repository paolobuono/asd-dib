/*
 * campodigioco.h
 *      Autore: Domenico Monaco - domenico.monaco@kiuz.it
 *      Descrizione: Gioco di avventura da traccia Appello di Laboratorio
 *      Data prova laboratorio: 12 / 01 / 2012
 *
 */

#ifndef CAMPODIGIOCO_H_
#define CAMPODIGIOCO_H_

#include <string>
#include <iostream>
using namespace std;
typedef bool boolean;

#include "oggetto.h"

#include "../../Grafo/arcoGrafoListaArchi.h"
#include "../../Grafo/grafoListaArchi.h"

#include "../../Lista/lista.h"
#include "../../Lista/nodolista.h"
#include "../../Lista/listaBidirezionale.h"

class data_Nodo {
public:
	string description;
	typedef NodoLista<Oggetto> Object;
	ListaBidirezionale<Oggetto, Object*> Objects;

	data_Nodo();

	void addObject(Oggetto);
	void setDescription(string);
	string getDescription();
};

data_Nodo::data_Nodo() {
	Objects.creaLista();
}

void data_Nodo::addObject(Oggetto objectIn) {
	NodoLista<Oggetto>*pos;
	pos = Objects.primoLista();

	Objects.insLista(objectIn, pos);
}
void data_Nodo::setDescription(string stringIn) {
	description = stringIn;
}
string data_Nodo::getDescription() {
	return description;
}

class data_Arco {
public:
	string direction;
	Oggetto object;
	data_Arco();
	void setObject(Oggetto);
	void setDirection(string);
	string getDirection();
};

string data_Arco::getDirection() {
	return direction;
}

data_Arco::data_Arco() {
}

void data_Arco::setObject(Oggetto objectIn) {
	object = objectIn;
}

void data_Arco::setDirection(string stringIn) {
	direction = stringIn;
}

typedef GrafoListaArchi<data_Nodo, data_Arco> CampoDiGioco;

#endif;
