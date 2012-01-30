#ifndef CELLA_H
#define CELLA_H
#include <cstdlib>
#include <iostream>
//#include "bnodo.h"

using namespace std;

template <class T>
class Cella
{
	public:
		void setCella(T);
		T getCella();
		void setSucc(Cella *);
		Cella * getSucc();
	private:
		T info;
		Cella *succ;
};

template <class T>
void Cella<T>::setCella(T info)
{ this->info = info; }

template <class T>
T Cella<T>::getCella()
{ return info; }

template <class T>
void Cella<T>::setSucc(Cella *succ)
{ this->succ = succ; }

template <class T>
Cella<T> * Cella<T>::getSucc()
{ return succ; }

#endif
