/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
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

#ifndef lista_h
#define lista_h
#include <cstdlib>
#include <iostream>
#include "../Dati/nodo.h"

using namespace std;

typedef bool boolean;

template <class tipoelem>
class Lista{

public:
    typedef Nodo <tipoelem> * posizione;
    Lista();   
    void creaLista ();
    boolean listaVuota();
    tipoelem leggiLista(posizione);
    void scriviLista(tipoelem,posizione);
    void insLista(tipoelem, posizione&);
    posizione primoLista();
    boolean fineLista(posizione);
    posizione succLista(posizione);
    posizione predLista(posizione);
    void cancLista(posizione);
private:
    posizione testa;
};



template <class T> 
Lista<T>::Lista(){
    creaLista();                           
}

template <class T> 
void Lista<T>::creaLista (){
    testa=NULL;
}

template <class T> 
boolean Lista<T>::listaVuota(){
    return (testa==NULL);
}

template <class T>
T Lista<T>::leggiLista(posizione p){
    return p->elemento;
}

template <class tipoelem>
void Lista<tipoelem>::scriviLista(tipoelem t,posizione p){
    p->elemento=t;
}

template <class T>
Nodo <T> * Lista<T>::primoLista(){
    return testa;
}

template <class tipoelem>
void Lista<tipoelem>::insLista(tipoelem t, posizione &p){
    Nodo<tipoelem> * temp = new Nodo<tipoelem>();
    temp->elemento = t;
    temp->succ=p;
    if (p==primoLista()) {
        testa=temp;
    }else{
        posizione prec=predLista(p);
        prec->succ=temp;
    }
}

template <class T>
void Lista<T>::cancLista(posizione p){
    Nodo <T> * temp;
    temp = predLista(p);
    temp->succ=p->succ;
    delete p;
}

template <class T>
boolean Lista<T>::fineLista(posizione p){
    return (p==NULL)?true:false;//todo: da specifiche è vero se è oltre l'ultimo elemento (n+1) 
}

template <class T>
Nodo <T> * Lista<T>::succLista(posizione p){
    return p->succ;
}

template <class T>
Nodo <T> * Lista<T>::predLista(posizione p){
    posizione p1=primoLista();
    while (!fineLista(p1) && (p1->succ != p)) {
        p1=succLista(p1);
    }
    return p1;
}

#endif //lista_h
