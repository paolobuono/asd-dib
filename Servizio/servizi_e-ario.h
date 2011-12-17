#ifndef SERVIZI_H
#define SERVIZI_H
#include <cstdlib>
#include <iostream>

using namespace std;
typedef nodo<studente>* Nodo;

void carica(albero<studente>&,Nodo&);
void previsita(albero<studente>,Nodo);
void postvisita(albero<studente>,Nodo);
void ampiezza(albero<studente>,Nodo);


void carica(albero<studente> &a,Nodo &n1) {
    Nodo n2,n3,n4,n5,n6,n7,n8,n9;
    studente s;
     
     s.scriviCodice(1);
     a.insRadice(s);   
     n1=a.Radice();
     
     s.scriviCodice(2);
     a.insPrimofg(s,n1);
     n2=a.primoFiglio(n1);
     
     s.scriviCodice(3);
     a.insFratellosucc(s,n2);
     n3=a.succFratello(n2);
     
     s.scriviCodice(4);
     a.insFratellosucc(s,n3);
     n4=a.succFratello(n3);
     
     s.scriviCodice(5);
     a.insPrimofg(s,n2);
     n5=a.primoFiglio(n2);
     
     s.scriviCodice(6);
     a.insFratellosucc(s,n5);
     n6=a.succFratello(n5);
     
     s.scriviCodice(7);
     a.insPrimofg(s,n3);
     n7=a.primoFiglio(n3);
     
     s.scriviCodice(8);
     a.insFratellosucc(s,n7);
     n8=a.succFratello(n7);
     
     s.scriviCodice(9);
     a.insFratellosucc(s,n8);
     n9=a.succFratello(n8);
     
      a.cancSottoalbero(n1);
     
}

void previsita(albero<studente> a,Nodo u) {
     Nodo c;
      cout<<""<<a.leggiNodo(u).leggiCodice()<<endl;
       if(!a.Foglia(u)) {
           c=a.primoFiglio(u);
              while(!a.ultimoFratello(c)) {
                 previsita(a,c);
                 c=a.succFratello(c);
                 }
           previsita(a,c);
       }
}

void postvisita(albero<studente> a,Nodo u) {
     Nodo c;
       if(!a.Foglia(u)) {
           c=a.primoFiglio(u);
              while(!a.ultimoFratello(c)) {
                 postvisita(a,c);
                 c=a.succFratello(c);
                 }
           postvisita(a,c);
       }
      cout<<""<<a.leggiNodo(u).leggiCodice()<<endl;
}

void invisita(albero<studente> a,Nodo u) {
     Nodo c;
     if(a.Foglia(u)) 
          cout<<""<<a.leggiNodo(u).leggiCodice()<<endl;
        else {
          c=a.primoFiglio(u);
          invisita(a,c); 
          cout<<""<<a.leggiNodo(u).leggiCodice()<<endl;
            while(!a.ultimoFratello(c)) {
                c=a.succFratello(c);
                  invisita(a,c);
                    
                  }
           }
}          

void ampiezza(albero<studente> a,Nodo u)
{
     studente stud;
     Nodo st;
     coda< Nodo > cod;
     cod.inCoda(u);
      while(!cod.Codavuota()) {
         st=cod.leggiCoda();
         stud=st->leggiInfo();
         cout<<""<<stud.leggiCodice()<<endl;
         cod.fuoriCoda();
          if(!a.Foglia(st)) {
             st=a.primoFiglio(st);
               while(!a.ultimoFratello(st)) {
                   cod.inCoda(st);
                   st=a.succFratello(st);
                   }
               cod.inCoda(st);
     }
  }
}

#endif
