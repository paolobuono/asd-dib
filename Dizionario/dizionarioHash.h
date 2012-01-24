/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *                                                                         *
 *   This file is part of ASD-dib.                                         *
 *   ASD-dib is free software; you can redistribute it and/or modify       *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   ASD-dib is distributed in the hope that it will be useful,            *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with ASD-dib; if not, see <http://www.gnu.org/licenses/>        *
 ***************************************************************************/

#ifndef _dizionarioHash_h
#define _dizionarioHash_h

#include "dizionario.h"

#include<iostream>
#include<iomanip>
#include<string>
#define MAX 50

using namespace std;

typedef bool boolean;
typedef int attributo;

template<class elemento, class chiave>
class DizionarioHash: public Dizionario<elemento, chiave> {
private:
	typedef elemento Vettore[MAX];
	Vettore vettore;
public:
	chiave H(chiave ch) //TODO: definire delle funzioni hash meno banali di questa
			{
		return (ch);
	}
	void inserisci(elemento, chiave);
	void cancella(chiave);
	elemento cerca(chiave);

	//funzioni aggiuntive
	DizionarioHash();
	boolean appartiene(chiave);
	void mostravettore();
	void creadiz();
	void aggiorna(chiave, chiave);
};

template<class elemento, class chiave>
void DizionarioHash<elemento, chiave>::inserisci(elemento e, chiave c) {
	chiave a = H(c);
	if (vettore[a] == "") {
		vettore[a] = e;
	}
}

template<class elemento, class chiave>
void DizionarioHash<elemento, chiave>::cancella(chiave c) {
	chiave a = H(c);
	if (vettore[a] != "") {
		vettore[a] = "";
	}
}

template<class elemento, class chiave>
elemento DizionarioHash<elemento, chiave>::cerca(chiave c) {
	chiave a = H(c);
	return vettore[a];
}

template<class elemento, class chiave>
DizionarioHash<elemento, chiave>::DizionarioHash() {
	creadiz();
}

template<class elemento, class chiave>
void DizionarioHash<elemento, chiave>::creadiz() {
	attributo i;

	for (i = 0; i < MAX; i++)
		vettore[i] = "";
}

template<class elemento, class chiave>
boolean DizionarioHash<elemento, chiave>::appartiene(chiave c) {
//    attributo i;
	boolean risultato = true;

//    risultato=false;
//    i=H(c);
//    
//    while((i<MAX)&&(!risultato)){
//        if(vettore[i]==c) risultato=true;    
//        i++;
//    }

	return (risultato);
}

template<class elemento, class chiave>
void DizionarioHash<elemento, chiave>::mostravettore() {
//    attributo i;
//    chiave c;
//    for (i=0;i<MAX;i++) {
//        c=vettore[i];
//        if (c=="") c="LIBERO";
//        cout << setw(6) << i << setw(18) << c << "\n";
//    }
//    system ("pause");
}

template<class elemento, class chiave>
void DizionarioHash<elemento, chiave>::aggiorna(chiave c1, chiave c2) {
//    attributo a;
//    
//    if (appartiene(c1)) {
//        if (!appartiene(c2)) {
//            if (H(c1)==H(c2)) {
//                a=recupera(c1);
//                vettore[a]=c2;
//            }
//            else {
//                cancella(c1);
//                inserisci(c2);  
//            }
//        }
//        else {
//            cout << "La chiave '"<< c2 <<"' e' gia' presente nel dizionario.\n";
//            system ("pause");
//        }
//    }
//    else {
//        cout << "La chiave '"<< c1 <<"' non esiste nel dizionario.\n";
//        system ("pause");
//
}

#endif
