#ifndef VIRTUAL_ENNARIO_H
#define VIRTUAL_ENNARIO_H
#include "../Albero/nodo.h"

using namespace std;


template<class T>
class viralbero {
      public: 
             virtual void creaAlbero()=0;
             virtual bool alberoVuoto()=0;
             virtual void insRadice(T)=0;
             virtual nodo<T>* Radice()=0;
             virtual nodo<T>* Padre(nodo<T>*)=0;
             virtual bool Foglia(nodo<T>*)=0;
             virtual nodo<T>* primoFiglio(nodo<T>*)=0;
             virtual bool ultimoFratello(nodo<T>*)=0;
             virtual nodo<T>* succFratello(nodo<T>*)=0;
             virtual void insPrimofg(T,nodo<T>*)=0;
             virtual void insFratellosucc(T,nodo<T>*)=0;
             virtual T leggiNodo(nodo<T>*)=0;
             virtual void scriviNodo(T,nodo<T>*)=0;
             virtual void cancSottoalbero(nodo<T>*)=0;
      };
      
#endif
