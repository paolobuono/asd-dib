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

#ifndef ALBEROBIN_H
#define ALBEROBIN_H
#include <iostream>
#include "cella_albero.h"

template <class tipoelem>
class Alberobin{
public:
    Alberobin();
    ~Alberobin();
    typedef CellaAlbero <tipoelem> * NodoAlbero;
    void creaBinalbero();
    boolean binalberoVuoto();
    NodoAlbero binRadice();
    NodoAlbero binPadre(NodoAlbero);
    NodoAlbero figlioSinistro(NodoAlbero);
    NodoAlbero figlioDestro(NodoAlbero);
    boolean sinistroVuoto(NodoAlbero);
    boolean destroVuoto(NodoAlbero);
    tipoelem leggiNodo(NodoAlbero);
    void scriviNodo(tipoelem,NodoAlbero);
    void insRadice(); 
    void insFiglioSinistro(NodoAlbero);
    void insFiglioDestro(NodoAlbero);
    void cancSottoBinalbero(NodoAlbero);
private:
    NodoAlbero albero;
};

//Implementazione

template <class T>
Alberobin<T>::Alberobin(){
	creaBinalbero();
};

template <class T>
Alberobin<T>::~Alberobin(){
};

template <class T>
void Alberobin<T>::creaBinalbero(){
    //rispetta le specifiche, ma va controllato.
	albero = NULL;
};

template <class T>
boolean Alberobin<T>::binalberoVuoto(){
	return (albero == NULL);
};

template <class tipoelem>
CellaAlbero <tipoelem> * Alberobin<tipoelem>::binRadice(){
    if(!binalberoVuoto())//condizione messa per rispettare le specifiche, non necessaria
		return albero;
    else return NULL;
};

template <class tipoelem>
CellaAlbero <tipoelem> * Alberobin<tipoelem>::binPadre(NodoAlbero u){
	if(!binalberoVuoto() && u != albero)
        return u->getGenitore();
    else return NULL;
};

template <class tipoelem>
CellaAlbero <tipoelem> * Alberobin<tipoelem>::figlioSinistro(NodoAlbero u){
	if(!binalberoVuoto() && !sinistroVuoto(u))
        return u->getSinistro();
    else return NULL;
};

template <class tipoelem>
CellaAlbero <tipoelem> * Alberobin<tipoelem>::figlioDestro(NodoAlbero u){
	if(!binalberoVuoto() && !destroVuoto(u))
        return u->getDestro();
    else return NULL;
};

template <class T>
boolean Alberobin<T>::sinistroVuoto(NodoAlbero u){
	return (u->getSinistro() == NULL);
};

template <class T>
boolean Alberobin<T>::destroVuoto(NodoAlbero u){
	return (u->getDestro() == NULL);
};

template <class tipoelem>
tipoelem Alberobin<tipoelem>::leggiNodo(CellaAlbero <tipoelem> * u){
	return u->getEtichetta();
};

template <class tipoelem>
void Alberobin<tipoelem>::scriviNodo(tipoelem elem, NodoAlbero u){
	u->setEtichetta(elem);
};

template <class T>
void Alberobin<T>::insRadice(){
	if(binalberoVuoto())
        albero = new CellaAlbero<T>;
};

template <class T>
void Alberobin<T>::insFiglioSinistro(NodoAlbero u){
	if((!binalberoVuoto()) && (sinistroVuoto(u)))
    {
        NodoAlbero temp;
        temp = new CellaAlbero<T>;
        u->setSinistro(temp);
        temp->setGenitore(u);
    };
};

template <class T>
void Alberobin<T>::insFiglioDestro(NodoAlbero u){
	if((!binalberoVuoto()) && (destroVuoto(u)))
    {
        NodoAlbero temp;
        temp = new CellaAlbero<T>;
        u->setDestro(temp);
        temp->setGenitore(u);
    };
};

/**
    restituisce il nodo padre del nodo u da cancellare, se u è radice allora restituisce NULL
 */
template <class T>
void Alberobin<T>::cancSottoBinalbero(NodoAlbero u){
	if (!binalberoVuoto()){
        if (u == albero) delete albero;
        else{
            NodoAlbero padre; // nodo d'appoggio
            padre = u->getGenitore();
            if (padre->getSinistro() == u) delete padre->getSinistro();
            else delete padre->getDestro();
        };
    };
};


#endif
