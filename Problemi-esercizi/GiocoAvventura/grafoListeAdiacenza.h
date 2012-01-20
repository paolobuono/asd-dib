#ifndef GRAFOLISTEADIACENZA_H
#define GRAFOLISTEADIACENZA_H
#include "gnodo.h"
#include "listaPuntatori.h"
#include "listaVettore.h"

template <class T, class P> // T = tipoelem del nodo, P = tipoelem del peso dell' arco
class GrafoListeAd
{
	public:
		typedef ListaPunt< GNodo<T, P> *> * pos;
		GrafoListeAd();
		bool grafovuoto();
        bool esistenodo(T);
        bool esistearco(T, T);
		int posnodo(T); // aggiunta arbitrariamente
		T legginodo(int);
		P leggiarco(T, T);
		void insnodo(T);
		void insarco(T, T, P);
        void cancnodo(T);
        void cancarco(T, T);
		pos adiacenti(T);
	private:
		ListaVett< ListaPunt< GNodo<T, P> *> *> listaG;
};

template <class T, class P>
GrafoListeAd<T, P>::GrafoListeAd()
{ listaG.crealista(); }

template <class T, class P>
bool GrafoListeAd<T, P>::grafovuoto()
{ return listaG.listavuota(); }

template <class T, class P>
bool GrafoListeAd<T, P>::esistenodo(T elem)
{
	bool trovato = false; int y = 0;
	if( !grafovuoto() ){
		while( !listaG.finelista(y) && trovato != true ){
			if( legginodo(y) == elem ) { trovato = true; }
			y++; //else{ y++; }
		}
	}
	return trovato;
}

template <class T, class P>
bool GrafoListeAd<T, P>::esistearco(T u, T v)
{
	bool trovato = false;
	if( esistenodo(u) && esistenodo(v) ){
		int i = 1;
		pos p = listaG.leggilista(posnodo(u));
		while ( !p->finelista(mappapos(*p, i)) ){
			if( p->leggilista(mappapos(*p, i))->getNodo() == v ) { trovato = true; }
			i++;
		}
	}
	return trovato;
}

template <class T, class P>
int GrafoListeAd<T, P>::posnodo(T elem)
{
	int y = 0;
	if( esistenodo(elem) ) { while( legginodo(y) != elem ) { y++; } }
	return y;
}

template <class T, class P>
T GrafoListeAd<T, P>::legginodo(int y)
{ return listaG.leggilista(y) -> leggilista(listaG.leggilista(y)->primolista()) -> getNodo(); }

template <class T, class P>
P GrafoListeAd<T, P>::leggiarco(T u, T v)
{
		int i = 1, posv;
		pos p = listaG.leggilista(posnodo(u));
		while ( !p->finelista(mappapos(*p, i)) ){
			if( p->leggilista(mappapos(*p, i))->getNodo() == v ) { posv = i; }
			i++;
		}
		return p->leggilista(mappapos(*p, posv)) -> getArco();
}

template <class T, class P>
void GrafoListeAd<T, P>::insnodo(T elem)
{
	if( !esistenodo(elem) ){
		GNodo<T, P> *g = new GNodo<T, P>(elem);			// costruttore con inizializzazione del valore del nodo
		pos listaAdi = new ListaPunt< GNodo<T, P> *>;
		listaAdi->inslista(g, listaAdi->primolista());
		listaG.inslista(listaAdi, listaG.primolista()); // listaG.ultimolista()
	}
}

template <class T, class P>
void GrafoListeAd<T, P>::insarco(T u, T v, P l)
{
	if( esistenodo(u) && esistenodo(v) ){
		GNodo<T, P> *g = new GNodo<T, P>(v, l);
		pos p = listaG.leggilista(posnodo(u));
		p->inslista(g, p->succlista(p->primolista()));
		// poiché è un grafo orientato non si ripete l'inserimento speculare dell'adiacente nel nodo v
//		pos q = listaG.leggilista(posnodo(v));
//		GNodo<T, P> *h = new GNodo<T, P>(u, l);
//		q->inslista(h, q->succlista(q->primolista()));
	}
}

template <class T, class P>
void GrafoListeAd<T, P>::cancnodo(T u)
{ if( esistenodo(u)) { listaG.canclista(posnodo(u)); } }

template <class T, class P>
void GrafoListeAd<T, P>::cancarco(T u, T v)
{
	if( esistearco(u, v)){
		int i = 1, posu, posv;
		pos p = listaG.leggilista(posnodo(u));
//		pos q = listaG.leggilista(posnodo(v)); // grafo non-orientato
		while ( !p->finelista(mappapos(*p, i)) ){
			if( p->leggilista(mappapos(*p, i))->getNodo() == v ) { posv = i; }
			i++;
		}
//		i = 1; // grafo non-orientato
//		while ( !q->finelista(mappapos(*q, i)) ){
//			if( q->leggilista(mappapos(*q, i))->getNodo() == u ) { posu = i; }
//			i++;
//		}
		p->canclista(mappapos(*p, posv));
//		q->canclista(mappapos(*q, posu)); // grafo non-orientato
	}
}

template <class T, class P>
ListaPunt< GNodo<T, P> *> * GrafoListeAd<T, P>::adiacenti(T elem)
{ return listaG.leggilista(posnodo(elem)); }

#endif
