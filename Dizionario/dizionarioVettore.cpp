///***************************************************************************
// *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
// *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
// *                                                                         *
// *   This file is part of ASD-dib.                                         *
// *   ASD-dib is free software; you can redistribute it and/or modify       *
// *   it under the terms of the GNU General Public License as published by  *
// *   the Free Software Foundation; either version 3 of the License, or     *
// *   (at your option) any later version.                                   *
// *                                                                         *
// *   ASD-dib is distributed in the hope that it will be useful,            *
// *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
// *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
// *   GNU General Public License for more details.                          *
// *                                                                         *
// *   You should have received a copy of the GNU General Public License     *
// *   along with ASD-dib; if not, see <http://www.gnu.org/licenses/>        *
// ***************************************************************************/
//
//#ifndef dizionarioVettore_cpp
//#define dizionarioVettore_cpp
//
//#include <iostream>
////#include "dizionarioVettore.h"
//
////template <class elemento>
////void DizionarioVettore<elemento>::inserisci(elemento e, chiave k){
////    bool trovato=false;
////    for(int i=0;i<dimensione;i++){
////        if (k==dati[i].chiaveDato) trovato = true;
////    }
////    if (!trovato && dimensione<MAXDIM){
////        dati[dimensione].chiaveDato=k;
////        dati[dimensione].elementoDato=e;
////        dimensione++;
////    }
////}
////
////DizionarioVettore::DizionarioVettore(){
////    dimensione=0;
////}
////
////void DizionarioVettore::cancella(chiave k){
////    bool trovato=false;
////    for(int i=0;i<dimensione;i++){
////        if (k==dati[i].chiaveDato) {
////            trovato = true;
////        }
////        if (trovato){
////            dati[i].chiaveDato=dati[i+1].chiaveDato;
////            dati[i].elementoDato=dati[i+1].elementoDato;
////        }
////    }
////}
////
////elemento DizionarioVettore::cerca(chiave k){
////    string risposta="";
////    bool trovato=false;
////    for(int i=0;(i<dimensione) && (!trovato);i++){
////        if (k==dati[i].chiaveDato) {
////            risposta = dati[i].elementoDato;
////        }
////    }
////    return risposta;
////}
////
//
//#endif
