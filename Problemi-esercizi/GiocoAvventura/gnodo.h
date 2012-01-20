#ifndef GNODO_H
#define GNODO_H
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T, class P>
class GNodo
{
	public:
		GNodo();
		GNodo(T);
		GNodo(T, P);
		void setNodo(T);
		T getNodo();
		void setArco(P);
		P getArco();
	private:
		T info;
		P peso;
};

template <class T, class P>
GNodo<T, P>::GNodo()
{}

template <class T, class P>
GNodo<T, P>::GNodo(T elem)
{
	info = elem;
}

template <class T, class P>
GNodo<T, P>::GNodo(T elem, P load)
{
	info = elem;
	peso = load;
}

template <class T, class P>
void GNodo<T, P>::setNodo(T elem)
{ info = elem; }

template <class T, class P>
T GNodo<T, P>::getNodo()
{ return info; }

template <class T, class P>
void GNodo<T, P>::setArco(P load)
{ peso = load; }

template <class T, class P>
P GNodo<T, P>::getArco()
{ return peso; }

#endif
