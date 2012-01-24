/***************************************************************************
 *   Copyright (C) 2011 by Paolo Buono - IVU Lab.                          *
 *   http://ivu.di.uniba.it - buono@di.uniba.it                            *
 *   Modified by Minerva Fabio                                             *
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
#include "cella_alberobin.h"

template<class tipoelem>
class Alberobin {
public:
	typedef CellaAlbero<tipoelem> * NodoAlbero;
	typedef bool boolean;
	virtual void creaBinalbero()=0;
	virtual boolean binalberoVuoto()=0;
	virtual NodoAlbero binRadice()=0;
	virtual NodoAlbero binPadre(NodoAlbero)=0;
	virtual NodoAlbero figlioSinistro(NodoAlbero)=0;
	virtual NodoAlbero figlioDestro(NodoAlbero)=0;
	virtual boolean sinistroVuoto(NodoAlbero)=0;
	virtual boolean destroVuoto(NodoAlbero)=0;
	virtual tipoelem leggiNodo(NodoAlbero)=0;
	virtual void scriviNodo(tipoelem, NodoAlbero)=0;
	virtual void insRadice()=0;
	virtual void insFiglioSinistro(NodoAlbero)=0;
	virtual void insFiglioDestro(NodoAlbero)=0;
	virtual void cancSottoBinalbero(NodoAlbero)=0;
};

#endif
