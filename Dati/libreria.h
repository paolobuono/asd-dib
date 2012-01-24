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

#ifndef ASD_libreria_h
#define ASD_libreria_h
#include "../Lista/lista.h"
#include "../Lista/nodolista.h"
#include "../Lista/listaUnidirezionale.h"
#include "testo.h"
#include "lettore.h"

class Prestiti {

public:
	Testo libro;
	Persona lettore;
};

class Libreria {
public:
	void aggiungiTesto(Testo);
	void presta(Testo, Persona);
	void restituisci(Testo, Persona);
	ListaUnidirezionale<Testo, NodoLista<Testo>*> getElencoLibri();
	ListaUnidirezionale<Prestiti, NodoLista<Prestiti>*> getElencoPrestiti();

private:
	ListaUnidirezionale<Testo, NodoLista<Testo>*> testiDisponibili;
	ListaUnidirezionale<Prestiti, NodoLista<Prestiti>*> prestiti;
};

#endif
