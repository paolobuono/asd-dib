#ifndef NODO_H
#define NODO_H
#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
class nodo {
private:
	T info;
	nodo<T>* primofg;
	nodo<T>* succfr;
	nodo<T>* padre;
public:
	nodo();
	~nodo();
	T leggiInfo();
	nodo<T>* leggiPrimofg();
	nodo<T>* leggiSuccfr();
	nodo<T>* leggiPadre();
	void scriviInfo(T);
	void scriviPrimofg(nodo<T>*);
	void scriviSuccfr(nodo<T>*);
	void scriviPadre(nodo<T>*);
};

template<class T>
nodo<T>::nodo() {
}

template<class T>
nodo<T>::~nodo() {
}

template<class T>
T nodo<T>::leggiInfo() {
	return info;
}

template<class T>
nodo<T>* nodo<T>::leggiSuccfr() {
	return succfr;
}

template<class T>
nodo<T>* nodo<T>::leggiPrimofg() {
	return primofg;
}

template<class T>
nodo<T>* nodo<T>::leggiPadre() {
	return padre;
}

template<class T>
void nodo<T>::scriviInfo(T i) {
	info = i;
}

template<class T>
void nodo<T>::scriviPrimofg(nodo<T>* fg) {
	primofg = fg;
}

template<class T>
void nodo<T>::scriviSuccfr(nodo<T>* fr) {
	succfr = fr;
}

template<class T>
void nodo<T>::scriviPadre(nodo<T>* p) {
	padre = p;
}
#endif
