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

#include <iostream>
#include <string.h>
#include "persone.h"
#include "testo.h"
#include "../Lista/lista.h"
#include "../Lista/nodolista.h"
#include "lettore.h"

Lettore::Lettore() {

}
;

void Lettore::presta(Testo t) {
	NodoLista<Testo> * posizione = testi.primoLista();
	testi.insLista(t, posizione);
}

Testo Lettore::restituisci(string titolo) {
	NodoLista<Testo> * posizione = testi.primoLista();
	Testo libroDaRestituire;
	while (!testi.fineLista(posizione)) {
		if (testi.leggiLista(posizione).getTitolo() == titolo) {
			libroDaRestituire = testi.leggiLista(posizione);
			//testi.cancLista(posizione);        //TODO: qui da errore
		} else {
			posizione = testi.succLista(posizione);
		}
	}
	return libroDaRestituire; //TODO: implementare il controllo che il testo non sia presente
}

ListaUnidirezionale<Testo, NodoLista<Testo>*> Lettore::getElencoLibri() {
	return testi;
}
