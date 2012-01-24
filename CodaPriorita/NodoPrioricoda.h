/*
 * NodoPrioricoda.h
 * Autore:  De Tuglie Danilo
 */
#ifndef NODOPRIORICODA_H_
#define NODOPRIORICODA_H_

#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>

class NodoPrioricoda {
private:
	T elemento;
	int priorita;

public:
	NodoPrioricoda();
	~NodoPrioricoda();
	void setElemento(T);
	void setPriorita(int);
	T getElemento();
	int getPriorita();

};

template<class T>
NodoPrioricoda<T>::NodoPrioricoda() {
	priorita = -1;
}

template<class T>
NodoPrioricoda<T>::~NodoPrioricoda() {
}

template<class T>
void NodoPrioricoda<T>::setElemento(T elemento) {
	this->elemento = elemento;
}

template<class T>
void NodoPrioricoda<T>::setPriorita(int priorita) {
	this->priorita = priorita;
}

template<class T>
T NodoPrioricoda<T>::getElemento() {
	return elemento;
}

template<class T>
int NodoPrioricoda<T>::getPriorita() {
	return priorita;
}

#endif /* NODOPRIORICODA_H_ */
