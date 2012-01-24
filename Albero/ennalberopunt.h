#ifndef ALBERO_H
#define ALBERO_H
#include <cstdlib>
#include <iostream>
#include "nodoenn.h"
#include "../Coda/coda.h"

using namespace std;

template<class T>
class ennalberopunt: public alberon<T> {
private:
	nodo<T>* radice;
public:
	ennalberopunt();
	~ennalberopunt();
	typedef nodo<T>* Nodo;
	void creaAlbero();
	bool alberoVuoto();
	void insRadice(T);
	Nodo Radice();
	Nodo Padre(Nodo);
	bool Foglia(Nodo);
	Nodo primoFiglio(Nodo);
	bool ultimoFratello(Nodo);
	Nodo succFratello(Nodo);
	void insPrimofg(T, Nodo);
	void insFratellosucc(T, Nodo);
	T leggiNodo(Nodo);
	void scriviNodo(T, Nodo);
	void cancSottoalbero(Nodo);
};

template<class T>
ennalberopunt<T>::ennalberopunt() {
	creaAlbero();
}

template<class T>
ennalberopunt<T>::~ennalberopunt() {
}

template<class T>
void ennalberopunt<T>::creaAlbero() {
	radice = NULL;
}
template<class T>
bool ennalberopunt<T>::alberoVuoto() {
	return radice == NULL;
}

template<class T>
void ennalberopunt<T>::insRadice(T ele) {
	radice = new nodo<T>;
	scriviNodo(ele, radice);
	radice->scriviPrimofg(NULL);
	radice->scriviSuccfr(NULL);
	radice->scriviPadre(NULL);
}

template<class T>
nodo<T>* ennalberopunt<T>::Radice() {
	return radice;
}

template<class T>
nodo<T>* ennalberopunt<T>::Padre(Nodo u) {
	if (!alberoVuoto() && u->leggiPadre() != NULL)
		return u->leggiPadre();
	else
		return NULL;
}

template<class T>
bool ennalberopunt<T>::Foglia(Nodo u) {
	if (!alberoVuoto())
		return (u->leggiPrimofg() == NULL);
}

template<class T>
nodo<T>* ennalberopunt<T>::primoFiglio(Nodo u) {
	if (!alberoVuoto() && !Foglia(u))
		return u->leggiPrimofg();
}

template<class T>
bool ennalberopunt<T>::ultimoFratello(Nodo u) {
	if (!alberoVuoto())
		return (u->leggiSuccfr() == NULL);
}

template<class T>
nodo<T>* ennalberopunt<T>::succFratello(Nodo u) {
	if (!alberoVuoto() && !ultimoFratello(u))
		return u->leggiSuccfr();
}

template<class T>
void ennalberopunt<T>::insPrimofg(T ele, Nodo u) {
	if (!alberoVuoto() && Foglia(u)) {
		Nodo nuovo = new nodo<T>;
		scriviNodo(ele, nuovo);
		u->scriviPrimofg(nuovo);
		nuovo->scriviPadre(u);
		nuovo->scriviPrimofg(NULL);
		nuovo->scriviSuccfr(NULL);
	}
}

template<class T>
void ennalberopunt<T>::insFratellosucc(T ele, Nodo u) {
	if (!alberoVuoto() && ultimoFratello(u) && u != radice) { //u!=radice la radice nn pu√≤ avere fratelli
		Nodo nuovo = new nodo<T>;
		scriviNodo(ele, nuovo);
		u->scriviSuccfr(nuovo);
		nuovo->scriviPadre(u->leggiPadre());
		nuovo->scriviSuccfr(NULL);
		nuovo->scriviPrimofg(NULL);
	}

}

template<class T>
T ennalberopunt<T>::leggiNodo(Nodo u) {
	return u->leggiInfo();
}

template<class T>
void ennalberopunt<T>::scriviNodo(T ele, Nodo u) {
	u->scriviInfo(ele);
}

template<class T>
void ennalberopunt<T>::cancSottoalbero(Nodo u) {
	/*   Nodo fg,t;
	 if(!Foglia(u)) {
	 fg = primoFiglio(u);

	 //CI posizioniamo sempre sull'ultimo fraello
	 //ad ogni istanza di CancSottoAlbero fg contiene un valore diverso
	 //quando ultimo fratello richiama cancSottoAlvero
	 //se Ë foglia verr‡ eliminato
	 //si chiude un istanza di cacnSottoAlbero
	 // e leggeremo un cancSottoAlbero di una istanza precedente
	 while(!ultimoFratello(fg)) {
	 fg = succFratello(fg);
	 cancSottoAlbero(fg);
	 }
	 cancSottoAlbero(fg);
	 } else {
	 //CANCELLIAMO FISICAMENTE IL NODO
	 DELETE(u);
	 }
	 */
}

while(!ultimoFratello(fg)) {
	succ_fg =succfratello(fg);
	cancSottoalbero(sfg);
}

#endif

