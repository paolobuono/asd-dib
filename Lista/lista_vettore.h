/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *   Created by Sasso Patrizia                                             *
 *                                                                         *
 *   This file is part of ASD-dib.                                         *
 *   ASD-dib is free software; you can redistribute it and/or modify       *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   ASD-dib is distributed in the hope that it will be useful,            *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with ASD-dib; if not, see <http://www.gnu.org/licenses/>        *
 ***************************************************************************/

#ifndef _LISTAVETTORE_H
#define _LISTAVETTORE_H

#include "lista.h"
#include <iostream>
using namespace std;

#define SIZE 12

template<class tipoelem>
class listaVettore: public Lista<tipoelem> {
private:
	cella vet[SIZE];
	int i;
	int lunghezza;
	int primo;
public:
	listaVettore();
	void crealista();
	bool listavuota();
	tipoelem leggilista(int); //DA TESTARE
	void scrivilista(tipoelem, int); // DA TESTARE
	int primolista();
	bool finelista(int);
	int succlista(int);
	int predlista(int);
	void inslista(int, tipoelem);
	void canclista(int);
};

template<class T>
listaVettore<T>::lista() {
	crealista();
}

template<class T>
void listaVettore<T>::crealista() {
	primo = 0;
	lunghezza = 0;
}

template<class T>
bool listaVettore<T>::listavuota() {
	return (lunghezza == 0);
}

template<class T>
T listaVettore<T>::leggilista(int i) //DA TESTARE
		{
	if (!listavuota())
		return vet[i];
}

template<class T>
void listaVettore<T>::scrivilista(T v, int i) // DA TESTARE
		{
	if (!listavuota())
		vet[i] = v;

}

template<class T>
int listaVettore<T>::primolista() {
	return primo;
}

template<class T>
bool listaVettore<T>::finelista(int i) {
	return (i == lunghezza);
}

template<class T>
int listaVettore<T>::succlista(int i) {
	if (!finelista(i))
		return (i + 1);
}

template<class T>
int listaVettore<T>::predlista(int i) {
	if (i != primolista())
		return (i - 1);
}

template<class T>
void listaVettore<T>::insLista(int i, tipoelem v) {
	if (lunghezza < SIZE) {
		if (listavuota()) {
			lunghezza = 1;
			scrivilista(v, primo);
		} else if (i >= lunghezza)
			scrivilista(v, lunghezza++);
		else {
			lunghezza++;
			for (int k = lunghezza; k > i; k--)
				scrivilista(vet[k - 1].leggi_valore(), k);
			scrivilista(v, i);
		}
	}
}

template<class T>
void listaVettore<T>::canclista(int n) {
	if (!listavuota()) {
		if (n < lunghezza) {
			int j = primolista();
			while (!finelista(j))
				j = succlista(j); //SI POSIZIONA ALL'ULTIMO ELEMENTO

			for (int i = n; i < j; i++)
				scrivilista(vet[i + 1], i);
			lunghezza--;
		} else if (n == lunghezza)
			lunghezza--;
	}
}

#endif
