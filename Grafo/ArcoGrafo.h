/*
 * ArcoGrafo.h
 * Autore:  De Tuglie Danilo
 */
#ifndef ARCOGRAFO_H_
#define ARCOGRAFO_H_

#include <cstdlib>
#include <iostream>

using namespace std;


template <class T>

class ArcoGrafo {    
private:
        T elemento;
public:
       ArcoGrafo();
       ~ArcoGrafo();
       T getElemento();
       void setElemento(T);
};



template <class T>
ArcoGrafo<T>::ArcoGrafo()
{
}

template <class T>
ArcoGrafo<T>::~ArcoGrafo()
{
}

template <class T>
T ArcoGrafo<T>::getElemento()
{
     return elemento;
}

template <class T>
void ArcoGrafo<T>::setElemento(T elemento)
{
     this->elemento = elemento;
}



#endif /* ARCOGRAFO_H_ */
