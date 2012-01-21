#ifndef GNODO_H
#define GNODO_H
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T, class P>
class GNodo
{
	public:
		GNodo(T);
		GNodo(T, P);
		T getNodo();
		P getArco();
	private:
		T info;
		P peso;
};

template <class T, class P>
GNodo<T, P>::GNodo(T elem)
{ this->info = info; }

template <class T, class P>
GNodo<T, P>::GNodo(T info, P peso)
{
	this->info = info;
	this->peso = peso;
}

template <class T, class P>
T GNodo<T, P>::getNodo()
{ return info; }

template <class T, class P>
P GNodo<T, P>::getArco()
{ return peso; }

#endif
