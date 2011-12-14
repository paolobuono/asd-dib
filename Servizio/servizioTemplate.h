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

#ifndef ASD_servizioTemplate_h
#define ASD_servizioTemplate_h
#include "../Lista/lista.h"
#include "../Coda/coda.h"

//per creare la funzione di caricamento o stampa fare overloading della funzione per ogni tipo di dato gestito

void caricaDizionario(Dizionario &);

void CaricaLibreria(Lista<Prestiti> &);

void stampaLista(Lista <Testo> &);
void stampaLista(Lista <Persona> &);
void stampaCoda(Coda <Persona>);

void CaricaLista(Lista <Testo> &);
void CaricaLista(Lista <Persona> &);
void caricaCoda(Coda <Persona> &);

template <class T>
void Messaggio(ListaUnidirezionale <T> l){
    string messaggio;
    messaggio = l.listaVuota()? "Lista vuota":"Lista piena";
    cout << endl << messaggio << endl;
};

//funzioni di caricamento

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

void CaricaLibreria(Lista<Prestiti> & libreria){
//    //Creazione lista di persone
//    Testo testo("Il libro delle anime", 1);
//    Persona persona("Glenn Cooper");
//    Prestiti prestito;
//    Nodo<Persona> * posPersona;
//    posPersona = prestito.p.primoLista();
//    prestito.p.insLista(persona, posPersona);
//    Nodo<Prestiti> * posPrestito;
//    posPrestito=libreria.primoLista();
//    libreria.insLista(prestito, posPrestito);
}

void CaricaLista(Lista<Testo> & l){
    //acquisizione dati
    Testo t("Algoritmi e Strutture Dati", 1);
    Nodo<Testo>* p=l.primoLista();
    l.insLista(t,p);
    
    t.setTesto("Basi di dati", 2);
    p=l.primoLista();
    l.insLista(t,p);
    
    //p=l.succLista(p);
    t.setTesto("Architetture degli elaboratori",3);
    l.insLista(t, p);
};

void CaricaLista(Lista<Persona> & l){
    Persona persona;
    persona.setNome("Pippo");
    
    Nodo<Persona>* p=l.primoLista();
    l.insLista(persona,p);
    
    persona.setNome("Pluto");
    p=l.primoLista();
    l.insLista(persona,p);
    
    persona.setNome("Paperino");
    p=l.succLista(p);
    l.insLista(persona,p);
};

void caricaCoda(Coda<Persona> & c){
    Persona persona("Antonio");
    c.inCoda(persona);
    persona.setNome("Luciano");
    c.inCoda(persona);
    persona.setNome("Maria");
    c.inCoda(persona);
}

//void caricaDizionario(Dizionario &d){
//    cout << endl << "Chiamato caricaDizionario" << endl;
//    chiave k=1;
//    elemento e="Cane";
//    d.inserisci(e,k);
//    k=2;
//    e="Gatto";
//    d.inserisci(e,k);
//    k=3;
//    e="Topo";
//    d.inserisci(e,k);
//}

//funzioni di stampa
void stampaLista(Lista<Persona> &l){
    Nodo<Persona>* p;
    Persona elemento;
    p=l.primoLista();
    if (p!=NULL) {
        cout << "elementi della lista: "<<endl;
    }
    while (!l.fineLista(p)){
        elemento=l.leggiLista(p);
        cout << elemento.getNome() << endl;
        p=l.succLista(p);
    }
    cout<<endl;
}

void stampaLista(Lista<Testo> &l){
    Nodo<Testo>* p;
    Testo elemento;
    p=l.primoLista();
    if (p!=NULL) {
        cout << "Elementi della lista: "<<endl;
    }
    while (!l.fineLista(p)){
        elemento=l.leggiLista(p);
        cout << elemento.getCodice() << " " << elemento.getTitolo() << endl;
        p=l.succLista(p);
    }
    cout<<endl;
}

void stampaCoda(Coda<Persona> c){
    Persona elemento;
    while (!c.codaVuota()){
        elemento=c.leggiCoda();
        cout << elemento.getNome() << endl;
        c.fuoriCoda();
    }
    cout<<endl;
    
}



#endif
