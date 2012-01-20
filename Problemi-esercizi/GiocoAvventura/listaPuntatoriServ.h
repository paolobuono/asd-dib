#ifndef LISTAPUNTATORISERV_H
#define LISTAPUNTATORISERV_H
#include "listaPuntatori.h"

// procedura di mappatura della posizione da intero ad indirizzo di memoria
template <class T>
Cella<T> * mappapos(ListaPunt<T> &L, int p)
{
	int i = 1;
	Cella<T> *pos = L.primolista();
	if( p>1 )
		while( i<p && !L.finelista(pos) ){
			pos = L.succlista(pos);
			i++;
		}
	return pos;
}

#endif
