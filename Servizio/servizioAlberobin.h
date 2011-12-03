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

#ifndef servizioalberobin_h
#define servizioalberobin_h

#include "../Albero/alberobin.h"
#include "../Dizionario/datoDizionario.h"
#include "../Coda/coda.h"

void previsita(CellaAlbero < Dato<string> > *,Alberobin< Dato<string> >);
void postvisita(CellaAlbero < Dato<string> > *,Alberobin< Dato<string> >);
void simmetrica(CellaAlbero < Dato<string> > *,Alberobin< Dato<string> >);
void bfs(Alberobin< Dato<string> >);

void inserimentOrdinato( Dato<string> ,CellaAlbero < Dato<string> > *,Alberobin< Dato<string> > &);  // inserimento ordinato  con rimozione dei duplicati
void inserimento( Dato<string> ,Alberobin< Dato<string> > &);  // inserimento  casuale con rimozione dei duplicati

int maxprofondita(CellaAlbero < Dato<string> > *,Alberobin< Dato<string> >);
int profnodo(CellaAlbero < Dato<string> > *,Alberobin< Dato<string> >,int, Dato<string> );

//Implementazione
// visita in preordine
void previsita (CellaAlbero < Dato<string> > * u, Alberobin< Dato<string> > T){
	if(!T.binalberoVuoto()){
        cout << T.leggiNodo(u).elementoDato << " ";
        if (!T.sinistroVuoto(u))
            previsita(T.figlioSinistro(u),T);
        if (!T.destroVuoto(u))
            previsita(T.figlioDestro(u),T);
    }
}

//simmetrica postordine
void postvisita (CellaAlbero < Dato<string> > * u, Alberobin< Dato<string> > T){
	if(!T.binalberoVuoto()){
        if (!T.sinistroVuoto(u)){
            
            postvisita(T.figlioSinistro(u),T);
        }
        if (!T.destroVuoto(u)){
            
            postvisita(T.figlioDestro(u),T);
        }
        cout << T.leggiNodo(u).elementoDato << " ";
    };
};

//visita simmetrica
void simmetrica (CellaAlbero < Dato<string> > * u, Alberobin< Dato<string> > T){
	if(!T.binalberoVuoto()){
        if (!T.sinistroVuoto(u)){
            simmetrica(T.figlioSinistro(u),T);
        }
        cout << T.leggiNodo(u).elementoDato << " ";
        if (!T.destroVuoto(u)){
            simmetrica(T.figlioDestro(u),T);
        }
    };
};


// visita dell'albero livello per livello
void bfs(Alberobin< Dato<string> > T)
{
    Coda<CellaAlbero < Dato<string> > * > c;
    CellaAlbero < Dato<string> > * x;
    
	c.creaCoda();
    if (!T.binalberoVuoto()){
        cout<<T.binRadice()->getEtichetta().elementoDato<<" ";
        c.inCoda(T.binRadice());
     	while (!c.codaVuota()){
            x=c.leggiCoda();
            c.fuoriCoda();
            if (!T.sinistroVuoto(x)){
                cout<<T.figlioSinistro(x)->getEtichetta().elementoDato<<" ";
                c.inCoda(T.figlioSinistro(x));
            }
            if (!T.destroVuoto(x)){
                cout<<T.figlioDestro(x)->getEtichetta().elementoDato<<" ";
                c.inCoda(T.figlioDestro(x));
            }
        }
    }
}

// inserimento ordinato con eleminazione dei doppi
void inserimentOrdinato( Dato<string> a,CellaAlbero < Dato<string> > * u,Alberobin< Dato<string> > & T){
	if (T.binalberoVuoto()){
        T.insRadice();
        T.scriviNodo(a,T.binRadice());
    }else{
        if (a.chiaveDato < T.leggiNodo(u).chiaveDato){
            if (T.sinistroVuoto(u)){
                T.insFiglioSinistro(u);
                T.scriviNodo(a,T.figlioSinistro(u));
            }
            else inserimentOrdinato(a,T.figlioSinistro(u),T); //chiamata ricorsiva
        }
        if (a.chiaveDato > T.leggiNodo(u).chiaveDato){
            if (T.destroVuoto(u)){
                T.insFiglioDestro(u);
                T.scriviNodo(a,T.figlioDestro(u));
            }
            else inserimentOrdinato(a,T.figlioDestro(u),T);   // chiamata ricorsiva
        }
    }
}; // fine funzione inserimentOrdinato


// inserimento ordinato con eleminazione dei doppi
void inserimento ( Dato<string>  a,Alberobin< Dato<string> > &T){
    Coda<CellaAlbero < Dato<string> > * > c;
    CellaAlbero < Dato<string> > * x;
    
	c.creaCoda();
    if (!T.binalberoVuoto()){
        c.inCoda(T.binRadice());
        bool inserimentoInAlbero=false;
        if(T.binRadice()->getEtichetta().chiaveDato==a.chiaveDato)
            inserimentoInAlbero=true;
        while (!c.codaVuota() && inserimentoInAlbero==false){
            x=c.leggiCoda();
            c.fuoriCoda();
            if (T.sinistroVuoto(x)){
                T.insFiglioSinistro(x);
                T.scriviNodo(a,T.figlioSinistro(x));
                inserimentoInAlbero=true;
            }else{
                if(T.figlioSinistro(x)->getEtichetta().chiaveDato==a.chiaveDato)
                    inserimentoInAlbero=true;
                c.inCoda(T.figlioSinistro(x));
                if (T.destroVuoto(x) && inserimentoInAlbero==false){
                    T.insFiglioDestro(x);
                    T.scriviNodo(a,T.figlioDestro(x));
                    inserimentoInAlbero=true;
                }else                {
                    if(!T.destroVuoto(x)){
                        c.inCoda(T.figlioDestro(x));
                        if(T.figlioDestro(x)->getEtichetta().chiaveDato==a.chiaveDato)
                            inserimentoInAlbero=true;
                    }                    
                }
            }
    	}
    }else{
    	T.insRadice();
     	T.scriviNodo(a,T.binRadice());
    }
}



int maxprofondita(CellaAlbero < Dato<string> > * u,Alberobin< Dato<string> > T){
	CellaAlbero < Dato<string> > * v;
    int max,corr;
    if((T.sinistroVuoto(u)==true) && (T.destroVuoto(u)==true))   //se u Ë foglia
        return 0;
    else {
        max=0;
        if (!T.sinistroVuoto(u)) {
            v=T.figlioSinistro(u);
            corr=maxprofondita(v,T);
            if(max<=corr)
                max=corr;
        }
        if (!T.destroVuoto(u)) {
            v=T.figlioDestro(u);
            corr=maxprofondita(v,T);
            if(max<=corr)
                max=corr;
        }
        return(max+1);
    }
}


int profnodo (CellaAlbero < Dato<string> > * u,Alberobin< Dato<string> > T,int livello, Dato<string>  elem)
{
    int liv=-1;
	if(!T.binalberoVuoto())
    {
        if(T.leggiNodo(u).chiaveDato==elem.chiaveDato)
            return livello;
        if (!T.sinistroVuoto(u))
            liv=profnodo(T.figlioSinistro(u),T,livello+1,elem);
        if (!T.destroVuoto(u) && (liv==-1))
            liv=profnodo(T.figlioDestro(u),T,livello+1,elem);
    }
	return liv;
}

#endif
