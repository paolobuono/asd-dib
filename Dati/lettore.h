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

#ifndef ASD_lettore_h
#define ASD_lettore_h
#include <string.h>
#include "persone.h"
#include "testo.h"
#include "../Lista/lista.h"
#include "../Lista/nodolista.h"
#include "../Lista/listaUnidirezionale.h"

class Lettore: public Persona {

public:
	Lettore();
	void presta(Testo);
	Testo restituisci(string);
	ListaUnidirezionale<Testo, NodoLista<Testo>*> getElencoLibri();
private:
	ListaUnidirezionale<Testo, NodoLista<Testo>*> testi;
};

#endif

