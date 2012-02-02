#ifndef LISTAVETTORE_H
#define LISTAVETTORE_H
#include <cstdlib>
#include <iostream>
#define MAXELEM 50

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
		T leggilista(int);
		void scrivilista(T, int);
		void inslista(T, int);
		void canclista(int);
	private:
		T lista[MAXELEM];
		int contatore;
};

template <class T>
ListaVett<T>::ListaVett()
{ crealista(); }

template <class T>
void ListaVett<T>::crealista()
{ contatore = 0; }

template <class T>
bool ListaVett<T>::listavuota()
{ return contatore == 0; }

template <class T>
int ListaVett<T>::primolista()
{ return 0; }

template <class T>
int ListaVett<T>::ultimolista()
{ return contatore; }

template <class T>
int ListaVett<T>::succlista(int pos)
{ return pos+1; }

template <class T>
int ListaVett<T>::predlista(int pos)
{ return pos-1; }

template <class T>
T ListaVett<T>::leggilista(int pos)
{ return lista[pos-1]; }

template <class T>
void ListaVett<T>::scrivilista(T elem, int pos)
{ lista[pos-1] = elem; }

template <class T>
void ListaVett<T>::inslista(T elem, int pos)
{
	int i;
	if( pos>=0 && pos <=contatore+1 ){
		for( i=ultimolista() ; i>=pos ; i-- )
			{ lista[i] = lista[i-1]; } // shifta gli elementi di una posizione a dx
		if( pos == primolista() ) { lista[pos] = elem; }
		else{ lista[pos-1] = elem; }
		contatore++;
	}
}

template <class T>
void ListaVett<T>::canclista(int pos)
{
	int i;
	if( pos>=0 && pos <=contatore ){
	    for( i=pos-1 ; i<=ultimolista() ; i++ )
			{ lista[i] = lista[i+1]; } // shifta gli elementi di una posizione a sn
		contatore--;
	}
}

#endif
