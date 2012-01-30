/*
 * oggetto.h
 *      Autore: Domenico Monaco - domenico.monaco@kiuz.it
 *      Descrizione: Gioco di avventura da traccia Appello di Laboratorio
 *      Data prova laboratorio: 12 / 01 / 2012
 *
 */
#ifndef OGGETTOGIOCOAVVENTURA_1_H_
#define OGGETTOGIOCOAVVENTURA_1_H_

#include <iostream>
using namespace std;
typedef bool boolean;

class Oggetto {
private:
	string name;
public:
	void setName(string);
	string getName();
};

void Oggetto::setName(string stringIn) {
	name = stringIn;
}
string Oggetto::getName() {
	return name;
}

#endif /* OGGETTOGIOCOAVVENTURA_1_H_ */
