#ifndef NodeC_h
#define NodeC_h
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T>
class NodeC {
private:
	T info;
	NodeC<T>* next;
public:
	NodeC();
	~NodeC();

	void set_inf(T);
	T get_inf();

	void set_next(NodeC<T>*);
	NodeC<T>* get_next();
};

/* Metodo costruttore che inizializza gli attributi membri dell'oggetto */
template<class T>
NodeC<T>::NodeC() {
	next = NULL;
}

/* Metodo distruttore che distrugge un oggetto di classe NodeC */
template<class T>
NodeC<T>::~NodeC() {
}

/* Metodo costruttore che inizializza il valore dell'attributo membro inf */
template<class T>
void NodeC<T>::set_inf(T e) {
	info = e;
}

/*Metodo osservatore che restituisce il valore dell'attributo membro info */
template<class T>
T NodeC<T>::get_inf() {
	return info;
}

/* Metodo costruttore che inizializza il valore dell'attributo membro next */
template<class T>
void NodeC<T>::set_next(NodeC<T>*n) {
	next = n;
}

/* Metodo osservatore che restituisce il valore dell'attributo membro next */
template<class T>
NodeC<T>* NodeC<T>::get_next() {
	return next;
}

#endif 
