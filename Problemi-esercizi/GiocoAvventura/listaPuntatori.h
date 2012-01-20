#ifndef LISTAPUNTATORI_H
#define LISTAPUNTATORI_H
#include "cella.h"

template <class T>
class ListaPunt
{
	public:
		typedef Cella<T> *pos;
		ListaPunt();
		~ListaPunt();
		void crealista();
		bool listavuota();
		pos primolista();
		pos ultimolista();
		pos succlista(pos);
		pos predlista(pos);
		bool finelista(pos);
		T leggilista(pos);
		void scrivilista(T, pos);
		void inslista(T, pos);
		void canclista(pos);
	private:
        pos testa;
};

template <class T>
ListaPunt<T>::ListaPunt()
{
	crealista();
}

template <class T>
ListaPunt<T>::~ListaPunt()
{
	delete testa;
}

template <class T>
void ListaPunt<T>::crealista()
{
    testa = NULL;
}

template <class T>
bool ListaPunt<T>::listavuota()
{
	return testa == NULL;
}

template <class T>
Cella<T> * ListaPunt<T>::primolista()
{
	return testa;
}

template <class T>
Cella<T> * ListaPunt<T>::ultimolista()
{
	pos p = primolista();
	if( !listavuota() ){
		while( p->getSucc() != NULL ){
			p = succlista(p);
        }
	}
	return p;
}

template <class T>
Cella<T> * ListaPunt<T>::succlista(pos p)
{
	return p->getSucc();
}

// predlista di primolista restituisce errore
template <class T>
Cella<T> * ListaPunt<T>::predlista(pos p)
{
	pos newp = primolista(); // la scansione per la ricerca della pos parte dalla testa
	while( !finelista(newp) && newp->getSucc() != p ){
		newp = succlista(newp);
    }
	return newp;
}

template <class T>
bool ListaPunt<T>::finelista(pos p)
{
    return p == NULL;
}

template <class T>
T ListaPunt<T>::leggilista(pos p)
{
	return p->getCella();
}

template <class T>
void ListaPunt<T>::scrivilista(T elem, pos p)
{
	if( !finelista(p) ) { p->setCella(elem); }
}

template <class T>
void ListaPunt<T>::inslista(T elem, pos p)
{
	pos newp = new Cella<T>;	// alloco memoria e assegno l'indirizzo della cella alla variabile newpos
	scrivilista(elem, newp);	// tramite il metodo della lista setto l'elemento di newp
	newp->setSucc(p);			// tramite il metodo della cella setto il puntatore con l'indirizzo passato all'inslista
	if( p == primolista() ) { testa = newp; }
	else 					{ predlista(p)->setSucc(newp);	}
}

template <class T>
void ListaPunt<T>::canclista(pos p)
{
	if( !finelista(p) ){ // && !listavuota()
		if( p == primolista() ) { testa = succlista(p); } // indirizzo cui punta il primolista
		else 					{ predlista(p)->setSucc(succlista(p)); }
		delete p; // rende lo spazio in memoria di nuovo disponibile
	}
}

#endif
