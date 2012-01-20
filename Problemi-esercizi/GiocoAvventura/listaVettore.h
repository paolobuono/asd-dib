#ifndef LISTAVETTORE_H
#define LISTAVETTORE_H
#include <cstdlib>
#include <iostream>
#define MAXELEM 50
#define NIL 0

using namespace std;

template <class T>
class ListaVett
{
	public:
		ListaVett();
		void crealista();
		bool listavuota();
		int primolista();
		int ultimolista();
		int succlista(int);
		int predlista(int);
		bool finelista(int);
		T leggilista(int);
		void scrivilista(T, int);
		void inslista(T, int);
		void canclista(int);
	private:
		T lista[MAXELEM];
};

template <class T>
ListaVett<T>::ListaVett()
{
    crealista();
}

template <class T>
void ListaVett<T>::crealista()
{
	int i;
	for( i=0; i<MAXELEM; i++ ) { lista[i] = NIL; }
}

template <class T>
bool ListaVett<T>::listavuota()
{
	int i;
	bool risposta = true;
	for( i=0; i<MAXELEM; i++ ){
		if( lista[i] != NIL ) { risposta = false; }
    }
    return risposta;
}

template <class T>
int ListaVett<T>::primolista()
{
    return 0;
}

template <class T>
int ListaVett<T>::ultimolista()
{
	int pos = primolista();
	while( lista[pos] != NIL ){
		pos = succlista(pos);
	}
    if( !listavuota() ) { pos--; }
	return pos;
}

template <class T>
int ListaVett<T>::succlista(int pos)
{
	return pos+1;
}

template <class T>
int ListaVett<T>::predlista(int pos)
{
	return pos-1;
}

template <class T>
bool ListaVett<T>::finelista(int pos)
{
    return lista[pos] == NIL;
}

template <class T>
T ListaVett<T>::leggilista(int pos)
{
	return lista[pos];
}

template <class T>
void ListaVett<T>::scrivilista(T elem, int pos)
{
	if( !finelista(pos) ) { lista[pos] = elem; }
}

template <class T>
void ListaVett<T>::inslista(T elem, int pos)
{
	int i;
	for( i=ultimolista(); i>=pos; i-- )
		{ lista[i+1] = lista[i]; } // shifta gli elementi di una posizione a dx
	lista[pos] = elem;
}

template <class T>
void ListaVett<T>::canclista(int pos)
{
	int i;
    for( i=pos; i<=ultimolista(); i++ )
		{ lista[i] = lista[i+1]; } // shifta gli elementi di una posizione a sn
}

#endif
