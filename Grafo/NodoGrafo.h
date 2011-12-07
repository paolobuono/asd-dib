/*
 * NodoGrafo.h
 * Autore:  De Tuglie Danilo
 */
#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_

#include <cstdlib>
#include <iostream>

using namespace std;


template <class T>

class NodoGrafo {    
private:
        T elemento;
        bool visitato;
        int numarch;
public:
       NodoGrafo();
       ~NodoGrafo();
       T getElemento();
       bool getVisitato();
       int getNumarch();
       void setElemento(T);
       void setVisitato(bool);
       void setNumarch(int);
};



template <class T>
NodoGrafo<T>::NodoGrafo()
{
     visitato = false;
     numarch = 0;
}

template <class T>
NodoGrafo<T>::~NodoGrafo()
{
}

template <class T>
T NodoGrafo<T>::getElemento()
{
     return elemento;
}

template <class T>
bool NodoGrafo<T>::getVisitato()
{
     return visitato;
}

template <class T>
int NodoGrafo<T>::getNumarch()
{
    return numarch;
}

template <class T>
void NodoGrafo<T>::setElemento(T elemento)
{
     this->elemento = elemento;
}

template <class T>
void NodoGrafo<T>::setVisitato(bool visitato)
{
     this->visitato = visitato;
}

template <class T>
void NodoGrafo<T>::setNumarch(int numarch)
{
     this->numarch = numarch;
}




#endif /* NODOGRAFO_H_ */
