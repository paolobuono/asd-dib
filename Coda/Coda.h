#ifndef Coda_h
#define Coda_h
#include <cstdlib>
#include <iostream>
#include "NodeC.h"
#define TRUE 1
#define FALSE 0
using namespace std;
template<class T>
class Coda
{
 private:
         NodeC<T>* top;
         NodeC<T>* bottom;
 public:
        Coda();
        ~Coda();
        int coda_vuota();
        T leggi_coda();
        void fuori_coda();
        void in_coda(T);
 };
 
 
 /* Metodo costruttore che inizializza gli attributi membri top e bottom */
template<class T>
Coda<T>:: Coda()
{
 top=NULL;
 bottom=NULL;      
}

/* Metodo distruttore che distrugge un oggetto di classe Coda */
template<class T>
Coda<T>:: ~Coda(){}

/* Metodo osservatore che controlla se la coda è vuota */
template<class T>
int Coda<T>:: coda_vuota()
{
   int result=FALSE;
   if ((top==NULL) || (bottom == NULL)) 
   {
      result=TRUE;
   }
return result;
}

/* Metodo osservatore che restituisce il valore dell'elemento in coda */
template<class T>
T Coda<T>:: leggi_coda()
{
 T result;
 if (!coda_vuota())
 {
    result=top->get_inf(); 
 }          
return result;
}

/* Metodo osservatore che elimina l'elemento in top alla coda */
template<class T>
void Coda<T>:: fuori_coda()
{
 if (!coda_vuota())
 {
    top=top->get_next();                  
 }    
}

/* Metodo costruttore che avvalora la coda */
template<class T>
void Coda<T>:: in_coda(T e)
{
 NodeC<T>* n;
 NodeC<T>*node;
 if (coda_vuota())
 {
    n=new NodeC<T>();
    n->set_inf(e);
    top=n;
    bottom=n;           
 }
 else
 {
  node=new NodeC<T>();
  node->set_inf(e);
  bottom->set_next(node);
  bottom=bottom->get_next();   
 }    
}

#endif
