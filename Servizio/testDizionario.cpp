/*
 * testDizionario.cpp
 *
 *  Created on: 14/dic/2011
 *      Author: macbookpro
 */

#include "testDizionario.h"

void testDizionario(){
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
}

void caricaDizionario(Dizionario &d){
    cout << endl << "Chiamato caricaDizionario" << endl;
    chiave k=1;
    elemento e="Cane";
    d.inserisci(e,k);
    k=2;
    e="Gatto";
    d.inserisci(e,k);
    k=3;
    e="Topo";
    d.inserisci(e,k);
}
