/*
 * NodoPila.h
 * Autore:  De Tuglie Danilo
 */

#ifndef NODOPILA_H_
#define NODOPILA_H_

#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>

class NodoPila {
private:
	T elemento;
	NodoPila<T> *successivo;
public:
	NodoPila();
	~NodoPila();
	T getElemento();
	NodoPila<T> *getSuccessivo();
	void setElemento(T elemento);
	void setSuccessivo(NodoPila<T> *successivo);
};

template<class T>
NodoPila<T>::NodoPila() {
	/*elemento = 0;			per rendere generica la classe NodoPila non posso 
	 settare elemento nel costruttore*/
	successivo = NULL;
}

template<class T>
T NodoPila<T>::getElemento() {
	return elemento;
}

template<class T>
NodoPila<T> *NodoPila<T>::getSuccessivo() {
	return successivo;
}

template<class T>
void NodoPila<T>::setElemento(T elemento) {
	this->elemento = elemento;
}

template<class T>
void NodoPila<T>::setSuccessivo(NodoPila<T> *successivo) {
	this->successivo = successivo;
}

template<class T>
NodoPila<T>::~NodoPila() {
}

#endif /*NODOPILA_H_*/
