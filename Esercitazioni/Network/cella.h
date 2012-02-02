#ifndef CELLA_H
#define CELLA_H
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class Cella
{
	public:
		void setInfo(T);
		T getInfo();
		void setSucc(Cella *);
		Cella * getSucc();
	private:
		T info;
		Cella *succ;
};

template <class T>
void Cella<T>::setInfo(T info)
{ this->info = info; }

template <class T>
T Cella<T>::getInfo()
{ return info; }

template <class T>
void Cella<T>::setSucc(Cella *succ)
{ this->succ = succ; }

template <class T>
Cella<T> * Cella<T>::getSucc()
{ return succ; }

#endif
