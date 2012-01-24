/*
 * Prioricoda.h
 * Autore:  De Tuglie Danilo
 */
#ifndef PRIORICODA_H_
#define PRIORICODA_H_

#define maxHeapLenght 10

#include "NodoPrioricoda.h"

template<class T>

class Prioricoda {
private:
	NodoPrioricoda<T>* heap[maxHeapLenght];
	int numeroNodi;

public:
	Prioricoda();
	~Prioricoda();
	void INSERISCI(T, int);
	T MIN();
	void CANCELLAMIN();
	bool PRIORICODAVUOTA();

	int getNumeroNodi();
	T LegiElemNodo(int);
	int LegiPrioNodo(int);
};

template<class T>
Prioricoda<T>::Prioricoda() {
	for (int i = 0; i <= maxHeapLenght; i++) {
		heap[i] = new NodoPrioricoda<T>;
	}
	numeroNodi = 0;
}

template<class T>
Prioricoda<T>::~Prioricoda() {
}

template<class T>
void Prioricoda<T>::INSERISCI(T elemento, int priorita) {
	int i = numeroNodi, j = ((numeroNodi + 1) / 2) - 1;
	NodoPrioricoda<T>* tmp = new NodoPrioricoda<T>;

	if (numeroNodi != maxHeapLenght) {
		heap[i]->setElemento(elemento);
		heap[i]->setPriorita(priorita);
		if (i > 0)
			while (heap[i]->getPriorita() < heap[j]->getPriorita()) {
				tmp = heap[j];
				heap[j] = heap[i];
				heap[i] = tmp;
				i = j;
				j = i / 2;
			}
		numeroNodi++;
	} else
		cout << "Coda piena!" << endl;

}

template<class T>
T Prioricoda<T>::MIN() {
	NodoPrioricoda<T>* tmp = new NodoPrioricoda<T>;
	if (!PRIORICODAVUOTA())
		return heap[0]->getElemento;
	else
		cout << "Coda vuota!" << endl;
	return tmp->getElemento;
}

template<class T>
void Prioricoda<T>::CANCELLAMIN() {
	NodoPrioricoda<T>* tmp = new NodoPrioricoda<T>;
	if (!PRIORICODAVUOTA()) {
		int i = 0, j;
		tmp = heap[0];
		heap[0] = heap[numeroNodi - 1];
		heap[numeroNodi - 1] == NULL;
		numeroNodi--;
		delete (tmp);
		j = (i + 1) * 2;
		if (j <= numeroNodi)
			while (j <= numeroNodi
					&& heap[i]->getPriorita() > heap[j - 1]->getPriorita()) {
				tmp = heap[i];
				heap[i] = heap[j - 1];
				heap[j - 1] = tmp;
				i = j - 1;
				j = (i + 1) * 2;
			}
	} else
		cout << "Coda vuota!" << endl;
}

template<class T>
bool Prioricoda<T>::PRIORICODAVUOTA() {
	if (numeroNodi == 0)
		return true;
	else
		return false;
}

template<class T>
int Prioricoda<T>::getNumeroNodi() {
	return numeroNodi;
}

template<class T>
T Prioricoda<T>::LegiElemNodo(int i) {
	NodoPrioricoda<T>* tmp = new NodoPrioricoda<T>;

	if (!PRIORICODAVUOTA())
		if (i <= numeroNodi)
			if (heap[i]->getPriorita() != -1)
				return heap[i]->getElemento();
			else
				cout << "Nodo inesistente!" << endl;
		else
			cout << "ERRORE: superata lunghezza massima in LegiElemNodo"
					<< endl;
	else
		cout << "Coda vuota!" << endl;
	return tmp->getElemento();
}

template<class T>
int Prioricoda<T>::LegiPrioNodo(int i) {
	NodoPrioricoda<T>* tmp = new NodoPrioricoda<T>;

	if (!PRIORICODAVUOTA())
		if (i <= numeroNodi)
			if (heap[i]->getPriorita() != -1)
				return heap[i]->getPriorita();
			else
				cout << "Nodo inesistente!" << endl;
		else
			cout << "ERRORE: superata lunghezza massima in LegiElemNodo"
					<< endl;
	else
		cout << "Coda vuota!" << endl;
	return -1;
}

#endif /* PRIORICODA_H_ */
