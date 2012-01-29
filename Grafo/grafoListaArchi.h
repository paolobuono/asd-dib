#include <iostream>
using namespace std;
typedef bool boolean;

//#include "grafo.h"
#include "cellaGrafo.h"
#include "arcoGrafoListaArchi.h"
#include "../Lista/listaBidirezionale.h"

template<class tipoNodo, class tipoArco>
class GrafoListaArchi {
public:

	typedef cellaGrafo<tipoNodo> nodoGrafo;
	typedef arcoGrafoListaArchi<tipoArco, tipoNodo> arcoGrafo;

	ListaBidirezionale<arcoGrafo*, NodoLista<arcoGrafo*>*> ListaArchi;
	ListaBidirezionale<nodoGrafo*, NodoLista<nodoGrafo*>*> ListaNodi;

	GrafoListaArchi();

	void creaGrafo();
	boolean grafoVuoto();

	void insNodo(nodoGrafo*, tipoNodo);

	void insArco(nodoGrafo*, nodoGrafo*, arcoGrafo*, tipoArco);

	void cancNodo(nodoGrafo*);
	void cancArco(nodoGrafo*, nodoGrafo*);
	ListaBidirezionale<cellaGrafo<tipoNodo>*, NodoLista<cellaGrafo<tipoNodo>*>*> adiacenti(
			nodoGrafo*);
	boolean esisteNodo(nodoGrafo*);
	boolean esisteArco(nodoGrafo*, nodoGrafo*);

};

template<class tipoNodo, class tipoArco>
GrafoListaArchi<tipoNodo, tipoArco>::GrafoListaArchi() {
}
template<class tipoNodo, class tipoArco>
void GrafoListaArchi<tipoNodo, tipoArco>::creaGrafo() {
	ListaArchi.creaLista();
	ListaNodi.creaLista();
}

template<class tipoNodo, class tipoArco>
boolean GrafoListaArchi<tipoNodo, tipoArco>::grafoVuoto() {
	boolean out;
	if (ListaNodi.listaVuota()) {
		out = true;
	} else {
		out = false;
	}
	return out;
}

template<class tipoNodo, class tipoArco>
void GrafoListaArchi<tipoNodo, tipoArco>::insNodo(nodoGrafo* nuovoNodo,
		tipoNodo datoNodo) {

	NodoLista<nodoGrafo*>* pos_NodoLista;
	pos_NodoLista = ListaNodi.primoLista();

	nuovoNodo->setInfo(datoNodo);

	ListaNodi.insLista(nuovoNodo, pos_NodoLista);

}

template<class tipoNodo, class tipoArco>
void GrafoListaArchi<tipoNodo, tipoArco>::insArco(nodoGrafo* nodoA,
		nodoGrafo* nodoB, arcoGrafo* arco, tipoArco datoArco) {

	if (esisteNodo(nodoA) && esisteNodo(nodoB)) {

		arco->setInfo(datoArco);

		arco->setNodoPartenza(nodoA);
		arco->setNodoArrivo(nodoB);

		NodoLista<arcoGrafo*>* pos_NodoListaArchi;
		pos_NodoListaArchi = ListaArchi.primoLista();

		ListaArchi.insLista(arco, pos_NodoListaArchi);

	}

}

template<class tipoNodo, class tipoArco>
void GrafoListaArchi<tipoNodo, tipoArco>::cancNodo(nodoGrafo* nodoRead) {
	if (esisteNodo(nodoRead)) {

		boolean check = false;
		NodoLista<nodoGrafo*>* posnodo;
		posnodo = ListaNodi.primoLista();

		while (posnodo != NULL && check != true) {

			if (posnodo->leggiElem() == nodoRead) {
				ListaNodi.cancLista(posnodo);
				check = true;
			} else {
				posnodo = ListaNodi.succLista(posnodo);
			}
		}

		arcoGrafo* arco;
		NodoLista<arcoGrafo*>* pos;
		NodoLista<arcoGrafo*>* tmppos;

		pos = ListaArchi.primoLista();

		while (pos != NULL) {
			arco = pos->leggiElem();

			if (arco->leggiNodoArrivo() == nodoRead
					|| arco->leggiNodoPartenza() == nodoRead) {

				cout << "trovato arco x" << arco->getInfo() << endl;
				tmppos = ListaArchi.succLista(pos);

				ListaArchi.cancLista(pos);

				pos = ListaArchi.primoLista();

			} else {
				pos = ListaArchi.succLista(pos);
			}

		}

	}

}

template<class tipoNodo, class tipoArco>
void GrafoListaArchi<tipoNodo, tipoArco>::cancArco(nodoGrafo* nodoA,
		nodoGrafo* nodoB) {
	boolean check = false;
	arcoGrafo* arco;
	NodoLista<arcoGrafo*>* pos;
	pos = ListaArchi.primoLista();

	while (pos != NULL && check != true) {

		arco = pos->leggiElem();

		if (arco->leggiNodoPartenza() == nodoA
				&& arco->leggiNodoArrivo() == nodoB) {

			check = true;

			ListaArchi.cancLista(pos);

		} else {
			pos = ListaArchi.succLista(pos);
		}
	}

}

template<class tipoNodo, class tipoArco>
ListaBidirezionale<cellaGrafo<tipoNodo>*, NodoLista<cellaGrafo<tipoNodo>*>*> GrafoListaArchi<
		tipoNodo, tipoArco>::adiacenti(nodoGrafo* nodo) {

	ListaBidirezionale<cellaGrafo<tipoNodo>*, NodoLista<cellaGrafo<tipoNodo>*>*> listaOut;
	listaOut.creaLista();

	if (esisteNodo(nodo)) {

		arcoGrafo* arco;
		NodoLista<arcoGrafo*>* pos;

		NodoLista<nodoGrafo*>* pos_ins;

		pos = ListaArchi.primoLista();

		while (pos != NULL) {
			arco = pos->leggiElem();

			if (arco->leggiNodoPartenza() == nodo) {
				pos_ins = listaOut.primoLista();
				listaOut.insLista(arco->leggiNodoArrivo(),pos_ins);

			}
			pos = ListaArchi.succLista(pos);
		}
	}

	return listaOut;
}

template<class tipoNodo, class tipoArco>
boolean GrafoListaArchi<tipoNodo, tipoArco>::esisteNodo(nodoGrafo* NodoCerca) {
	boolean check = false;

	NodoLista<nodoGrafo*>* pos;
	pos = ListaNodi.primoLista();

	while (pos != NULL && check != true) {
		if (pos->leggiElem() == NodoCerca) {
			check = true;
		} else {
			pos = ListaNodi.succLista(pos);
		}
	}

	return check;
}

template<class tipoNodo, class tipoArco>
boolean GrafoListaArchi<tipoNodo, tipoArco>::esisteArco(nodoGrafo* nodoA,
		nodoGrafo* nodoB) {

	boolean check = false;

	arcoGrafo* arco;
	NodoLista<arcoGrafo*>* pos;
	pos = ListaArchi.primoLista();

	while (pos != NULL && check != true) {

		arco = pos->leggiElem();

		if (arco->leggiNodoPartenza() == nodoA
				&& arco->leggiNodoArrivo() == nodoB) {
			check = true;
		} else {
			check = false;
			pos = ListaArchi.succLista(pos);
		}
	}

	return check;

}

