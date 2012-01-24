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

#ifndef ASD_dizionarioAlberoBinario_h
#define ASD_dizionarioAlberoBinario_h
#include "dizionario.h"
#include "../Albero/alberobin.h"
#include "../Dati/testo.h"
#include "../Servizio/servizioAlberobin.h"

class DizionarioAlberoBinario: public Dizionario {
public:
	void inserisci(elemento, chiave);
	void cancella(chiave);
	elemento cerca(chiave);
	DizionarioAlberoBinario();
private:
	Alberobin<Dato<string> > alberobin;
};

//Implementazione.. da migliorare
void DizionarioAlberoBinario::inserisci(elemento e, chiave k) {
	Dato<string> d(k, e);
	CellaAlbero<Dato<string> > * u = alberobin.binRadice();
	inserimentOrdinato(d, u, alberobin);
}

DizionarioAlberoBinario::DizionarioAlberoBinario() {
	alberobin.creaBinalbero();
}

void DizionarioAlberoBinario::cancella(chiave k) {
	CellaAlbero<Dato<string> > * u;
	u = alberobin.binRadice();
	bool trovato = false;
	while ((u != NULL) && (!trovato)) {
		if (k == u->getEtichetta().chiaveDato) {
			if (u->getSinistro() != NULL) {
				//                sostituisci il sinistro al nodo
			} else {
				if (u->getDestro() != NULL) {
					//                sostituisci il destro al nodo
				}
				delete u; //cancellare il nodo temporaneo che assume il valore di u
			}
		}
	}
}

elemento DizionarioAlberoBinario::cerca(chiave k) {
	CellaAlbero<Dato<string> > * u;
	u = alberobin.binRadice();
	while (u != NULL) {
		if (k == u->getEtichetta().chiaveDato)
			return u->getEtichetta().elementoDato;
		else if (k < u->getEtichetta().chiaveDato)
			u = alberobin.figlioSinistro(u);
		else
			u = alberobin.figlioDestro(u);
	}
	return "";
}

#endif
