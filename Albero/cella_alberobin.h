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

#ifndef CELLA_ALBERO_H
#define CELLA_ALBERO_H
typedef bool boolean;
using namespace std;

template<class tipoelem>
class CellaAlbero {
public:
	CellaAlbero();
	~CellaAlbero();

	void setEtichetta(tipoelem);
	tipoelem getEtichetta();

	void setSinistro(CellaAlbero *);
	CellaAlbero *getSinistro();

	void setDestro(CellaAlbero *);
	CellaAlbero *getDestro();

	void setGenitore(CellaAlbero *);
	CellaAlbero *getGenitore();

private:
	tipoelem etichetta;
	CellaAlbero *sinistro;
	CellaAlbero *destro;
	CellaAlbero *genitore;

};

//Implementazione

template<class tipoelem>
CellaAlbero<tipoelem>::CellaAlbero() {
	//	etichetta = 0;
	sinistro = destro = genitore = NULL;
}
;

template<class tipoelem>
void CellaAlbero<tipoelem>::setEtichetta(tipoelem elem) {
	etichetta = elem;
}
;

template<class tipoelem>
tipoelem CellaAlbero<tipoelem>::getEtichetta() {
	return etichetta;
}
;

template<class tipoelem>
void CellaAlbero<tipoelem>::setSinistro(CellaAlbero *sx) {
	if (sx == NULL)
		delete sinistro;
	else
		sinistro = sx;
}
;

template<class tipoelem>
CellaAlbero<tipoelem> * CellaAlbero<tipoelem>::getSinistro() {
	return sinistro;
}
;

template<class tipoelem>
void CellaAlbero<tipoelem>::setDestro(CellaAlbero *dx) {
	if (dx == NULL)
		delete destro;
	destro = dx;
}
;

template<class tipoelem>
CellaAlbero<tipoelem> * CellaAlbero<tipoelem>::getDestro() {
	return destro;
}
;

template<class tipoelem>
void CellaAlbero<tipoelem>::setGenitore(CellaAlbero *father) {
	//per definizione non bisogna settare il genitore del  nodo radice !!!
	genitore = father;
}
;

template<class tipoelem>
CellaAlbero<tipoelem> * CellaAlbero<tipoelem>::getGenitore() {
	return genitore;
}
;

template<class tipoelem>
CellaAlbero<tipoelem>::~CellaAlbero() {
	delete sinistro;
	delete destro;
	delete genitore;
}
;

#endif //CELLA_ALBERO_H
