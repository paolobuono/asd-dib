/*
 * Pila.h
 * Autore:  De Tuglie Danilo
 */

#ifndef PILA_H_
#define PILA_H_

#include "NodoPila.h"

template<class T>
class Pila {
private:
	NodoPila<T>* testa;
public:
	Pila();
	~Pila();
	void CREAPILA();
	bool PILAVUOTA();
	T LEGGIPILA();
	void FUORIPILA();
	void INPILA(T);
};

template<class T>
Pila<T>::Pila() {
	testa = NULL;
}

template<class T>
Pila<T>::~Pila() {
	while (!PILAVUOTA())
		FUORIPILA();
}

template<class T>
void Pila<T>::CREAPILA() {
	Pila();
}

template<class T>
bool Pila<T>::PILAVUOTA() {
	if (testa == NULL)
		return true;
	else
		return false;
}

template<class T>
T Pila<T>::LEGGIPILA() {
	if (!PILAVUOTA())
		return testa->getElemento();
	else {
		cout << "ERRORE: pila vuota! in LEGGIPILA" << endl;
		T elemNULL;
		return elemNULL;
	}
}

template<class T>
void Pila<T>::FUORIPILA() {
	NodoPila<T>* temp = new NodoPila<T>;
	if (!PILAVUOTA()) {
		temp = testa;
		testa = testa->getSuccessivo();
		delete (temp);
	} else
		cout << "ERRORE: pila vuota! in FUORIILA" << endl;
}

template<class T>
void Pila<T>::INPILA(T elemento) {
	NodoPila<T>* nuovo = new NodoPila<T>;
	nuovo->setElemento(elemento);
	if (!PILAVUOTA())
		nuovo->setSuccessivo(testa);
	testa = nuovo;
}

#endif /*PILA_H_*/
