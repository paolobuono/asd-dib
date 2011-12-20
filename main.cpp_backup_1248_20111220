/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *                                                                         *
 *   Modified by Domenico Monaco (monaco.d@gmail.com)                      *
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

#include <cstdlib>
#include <iostream>

#include "Dati/testo.h"
#include "Dati/persone.h"

#include "Lista/lista.h"
#include "Lista/listaUnidirezionale.h"
#include "Coda/coda.h"
#include "Albero/alberobin.h"
#include "Dati/libreria.h"

#include "Dizionario/dizionario.h"
#include "Dizionario/dizionarioLista.h"
#include "Dizionario/dizionarioVettore.h"
#include "Dizionario/dizionarioHash.h"
#include "Dizionario/dizionarioAlberoBinario.h"
#include "Dizionario/datoDizionario.h"

#include "Servizio/servizioAlberobin.h"
#include "Servizio/servizioTemplate.h"
#include "Servizio/testDizionario.h"

using namespace std;

int main(int argc, char *argv[])
{
	ListaUnidirezionale< ListaUnidirezionale<Prestiti> > libreria;
    //    CaricaLibreria(libreria);
    
    cout << "Carico e stampo elenco libri" << endl;
    ListaUnidirezionale <Testo> l;
    CaricaLista(l);
    Messaggio(l);
    stampaLista(l);
    
    cout << "Carico e stampo le persone" << endl;
    ListaUnidirezionale<Persona> p;
    CaricaLista(p);
    Messaggio(p);
    stampaLista(p);
    
    cout << "Carico e stampo altri dati: " << endl;
    Coda<Persona> c;
    caricaCoda(c);
    stampaCoda(c);
    
    DizionarioVettore dv;
    caricaDizionario(dv);
    dv.cancella(1);
    elemento ev=dv.cerca(2);
    if(ev!="") cout << "Trovato elemento: " << ev << endl;
    else cout << "Elemento non trovato"<<endl;

    DizionarioLista dl;
    caricaDizionario(dl);
    dl.cancella(1);
    elemento el=dl.cerca(2);
    if(el!="") cout << "Trovato elemento dizionario lista: " << el << endl;
    else cout << "Elemento non trovato in dizionario lista"<<endl;

    DizionarioAlberoBinario db;
    caricaDizionario(db);
    db.cancella(1);
    elemento eb=db.cerca(2);
    if(eb!="") cout << "Trovato elemento dizionario alberobin: " << eb << endl;
    else cout << "Elemento non trovato in dizionario alberobin"<<endl;

    DizionarioHash dh;
    caricaDizionario(dh);
    dh.cancella(1);
    elemento eh=dh.cerca(2);
    if(eh!="") cout << "Trovato elemento dizionario hash: " << eh << endl;
    else cout << "Elemento non trovato in dizionario hash"<<endl;


    system("PAUSE");
    return EXIT_SUCCESS;
}
