#ifndef NODO_CODA_H
#define NODO_CODA_H
#include <cstdlib>
#include <iostream>
using namespace std;

template<class tipoelem>
class nodocoda {
private:
	tipoelem elem;
	nodocoda<tipoelem>* succ;
public:
	nodocoda();
	~nodocoda();
	tipoelem leggiElem();
	void scriviElem(tipoelem);
	nodocoda<tipoelem>* leggiSucc();
	void scriviSucc(nodocoda<tipoelem>*);

};

template<class tipoelem>
nodocoda<tipoelem>::nodocoda() {

}
template<class tipoelem>
nodocoda<tipoelem>::~nodocoda() {

}
template<class tipoelem>
tipoelem nodocoda<tipoelem>::leggiElem() {
	return elem;
}

template<class tipoelem>
void nodocoda<tipoelem>::scriviElem(tipoelem e) {
	elem = e;
}

template<class tipoelem>
nodocoda<tipoelem>* nodocoda<tipoelem>::leggiSucc() {
	return succ;
}

template<class tipoelem>
void nodocoda<tipoelem>::scriviSucc(nodocoda<tipoelem>* p) {
	succ = p;
}
#endif
