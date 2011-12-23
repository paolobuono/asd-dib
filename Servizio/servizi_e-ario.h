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
int contanodi_albero_enn(Albero_enn<studente> &, Nodo<studente>*, int);
int altezza(Albero_enn<studente> &, Nodo<studente>*, int);
int calcolo(Albero_enn<studente> &, Nodo<studente>*, int , int);
int conta_foglie(Albero_enn<studente> &, Nodo<studente>*, int);
void ricercaCodice(albero<studente>,int);

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





int contanodi_albero_enn(Albero<studente> & t, Nodo<T>* u, int cont)   // restituisce il numero di sottoalberi dell'albero
{
   
 if(!t.albero_vuoto()){
                         Nodo<studente>* c;
                         cont++;  
                         
                         if(!t.foglia(u))
                           {
                            c=t.primo_figlio(u);
                            
                            while(!t.ultimo_fratello(c))
                                {
                                  cont=contanodi_albero_enn(t, c, cont);
                                  c=t.succ_fratello(c);                      
                                }             
                          cont=contanodi_albero_enn(t, c, cont);   
                        }
                      }                                  
   return cont;                                                         
};



int conta_foglie(Albero_enn<studente> & t, Nodo<studente>* u, int cont)     //restituisce il numero delle foglie dell'albero
{  
 if(!t.albero_vuoto()){
                         Nodo<studente>* c;
                        
                         if(t.foglia(u))
                            cont++; 
                         
                         else
                           {
                            c=t.primo_figlio(u);
                            
                            while(!t.ultimo_fratello(c))
                                {
                                  cont=conta_foglie(t, c, cont);
                                  c=t.succ_fratello(c);                      
                                }             
                          cont=conta_foglie(t, c, cont);   
                        }
                      }                                  
   return cont;                                                         
};



int altezza(Albero_enn<sudente> & t, Nodo<studente>* u,int temp)  //restituisce l'altezza dell'albero
{
  int max=temp;  
  if(!t.albero_vuoto())
      max=calcolo(t,u, temp, max);                                  
        return max;             
};                      
                           


int calcolo(Albero_enn<studente> & t, Nodo<studente>* u,int temp, int max)
{
    Nodo<studente>* c;
    if(t.foglia(u))
      {
       if(temp>=max) 
          max=temp;          
      }
                         
    else
      {
       temp++;
        {
          c=t.primo_figlio(u);
          while(!t.ultimo_fratello(c))
            {
             max=calcolo(t, c, temp, max);
             c=t.succ_fratello(c);                      
            }             
          max=calcolo(t, c, temp, max);      
        }    
     }
return max;
}

Nodo ricercaCodice(albero<studente> a,int c) {
  studente s;
  bool trovato=false;
  Nodo temp,rad;
  coda< Nodo > cod;
  rad=a.Radice();
     /*controllo subito se ho trovato l'elemento ritorno rad altrimenti faccio visita in ampiezza */
       if(rad->leggiInfo().leggiCodice()==c)
           return rad;
  cod.inCoda(rad);
    while(!cod.Codavuota() && trovato==false) {
                            temp=cod.leggiCoda();
                            s=temp->leggiInfo();
                            cod.fuoriCoda();
                             if(s.leggiCodice()!=c) {
                                                    if(!a.Foglia(temp)) {
                                                                        temp=a.primoFiglio(temp);
                                                                         while(!a.ultimoFratello(temp)) {
                                                                                                        cod.inCoda(temp);
                                                                                                        temp=a.succFratello(temp);
                                                                                                        }
                                                                                                        cod.inCoda(temp);
                                                                         }
                                                    } else {
                                                           trovato=true;
                                                           }
                             }
            if(cod.Codavuota()) {
                                cout<<"Nessun elemento trovato!"<<endl;
                                return NULL;
                                } else {
                                    return temp;
                                    }
  } 




#endif
