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

#ifndef ASD_dizionarioLista_h
#define ASD_dizionarioLista_h

#include "dizionario.h"
#include "../Lista/listaUnidirezionale.h"
#include "../Dati/testo.h"

class DizionarioLista : public Dizionario{
public:
    void inserisci(elemento,chiave);
    void cancella(chiave);
    elemento cerca(chiave);
    DizionarioLista();
private:
    ListaUnidirezionale< Dato<string> > lista;
};


//implementazione
void DizionarioLista::inserisci(elemento e, chiave k){
    Dato<string> d;
    d.elementoDato = e;
    d.chiaveDato = k;
    Nodo< Dato<string> > * posizione;
    boolean trovato=false;
    posizione=lista.primoLista();
    while (!lista.fineLista(posizione)) {
        if (lista.leggiLista(posizione).chiaveDato==d.chiaveDato)
            trovato=true;
        posizione=lista.succLista(posizione);
    }
    //inserisce sempre in testa, ottimizzare effettuando l'inserimento ordinato della lista
    if (!trovato){ 
        posizione=lista.primoLista();
        lista.insLista(d,posizione);   
    }
}

DizionarioLista::DizionarioLista(){
    lista.creaLista();
}

void DizionarioLista::cancella(chiave k){
    boolean trovato=false;
    Nodo< Dato<string> > * posizione;
    posizione = lista.primoLista();
    while ((!lista.fineLista(posizione)) && (!trovato)) {
        if (lista.leggiLista(posizione).chiaveDato==k){
            lista.cancLista(posizione);
            trovato=true;
        }
        posizione=lista.succLista(posizione);
    }
    cout << "Dato con chiave "<<k<<" cancellato"<<endl;
}

elemento DizionarioLista::cerca(chiave k){
    boolean trovato=false;
    Nodo< Dato<string> > * posizione;
    posizione = lista.primoLista();
    elemento e;
    while ((!lista.fineLista(posizione)) && (!trovato)) {
        if (lista.leggiLista(posizione).chiaveDato==k){
            e=(lista.leggiLista(posizione)).elementoDato;
            trovato=true;
        }
        posizione=lista.succLista(posizione);
    }
    return e;
}

#endif

