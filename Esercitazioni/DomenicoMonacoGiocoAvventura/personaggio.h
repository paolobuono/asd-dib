/*
 * personaggio.h
 *      Autore: Domenico Monaco - domenico.monaco@kiuz.it
 *      Descrizione: Gioco di avventura da traccia Appello di Laboratorio
 *      Data prova laboratorio: 12 / 01 / 2012
 *
 */

#ifndef PERSONAGGIO_H_
#define PERSONAGGIO_H_

#include <string>

#include "../../Lista/lista.h"
#include "../../Lista/nodolista.h"
#include "../../Lista/listaBidirezionale.h"

#include "oggetto.h"

#include <iostream>
using namespace std;
typedef bool boolean;

class Personaggio {
public:
	Personaggio(string name);
	void addObject(Oggetto object);

	typedef NodoLista<Oggetto> Object;
	ListaBidirezionale<Oggetto, Object*> Objects;

private:
	string name;


};

Personaggio::Personaggio(string nameIn) {
	Objects.creaLista();
	name = nameIn;
}
void Personaggio::addObject(Oggetto object) {
	NodoLista<Oggetto>* Object_Pos;
	Object_Pos = Objects.primoLista();

	Objects.insLista(object, Object_Pos);
}

#endif /* PERSONAGGIO_H_ */
