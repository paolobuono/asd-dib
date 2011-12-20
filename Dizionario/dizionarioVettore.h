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

#ifndef ASD_dizionarioVettore_h
#define ASD_dizionarioVettore_h
#include "dizionario.h"
#define MAXDIM 100

template <class elemento>
class DizionarioVettore : public Dizionario < elemento >{
public:
    void inserisci(elemento,chiave);
    void cancella(chiave);
    elemento cerca(chiave);
    DizionarioVettore();
private:
    Dato<elemento> dati[MAXDIM];
    int dimensione;
};


template <class elemento>
void DizionarioVettore<elemento>::inserisci(elemento e, chiave k){
    bool trovato=false;
    for(int i=0;i<dimensione;i++){
        if (k==dati[i].chiaveDato) trovato = true;
    }
    if (!trovato && dimensione<MAXDIM){
        dati[dimensione].chiaveDato=k;
        dati[dimensione].elementoDato=e;
        dimensione++;
    }
}

template <class elemento>
DizionarioVettore<elemento>::DizionarioVettore(){
    dimensione=0;
}

template <class elemento>
void DizionarioVettore<elemento>::cancella(chiave k){
    bool trovato=false;
    for(int i=0;i<dimensione;i++){
        if (k==dati[i].chiaveDato) {
            trovato = true;
        }
        if (trovato){
            dati[i].chiaveDato=dati[i+1].chiaveDato;
            dati[i].elementoDato=dati[i+1].elementoDato;
        }
    }
}

template <class elemento>
elemento DizionarioVettore<elemento>::cerca(chiave k){
    string risposta="";
    bool trovato=false;
    for(int i=0;(i<dimensione) && (!trovato);i++){
        if (k==dati[i].chiaveDato) {
            risposta = dati[i].elementoDato;
        }
    }
    return risposta;
}


#endif
