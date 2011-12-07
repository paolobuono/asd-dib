/*
 * Grafo.h
 * Autore:  De Tuglie Danilo
 */
#ifndef GRAFO_H_
#define GRAFO_H_

#include "NodoGrafo.h"
#include "ArcoGrafo.h"
#include "ListeGra\funzioniLista.h"

#define MAXNODI 30

typedef int Nodo;

template <class TN, class TA>

class Grafo{
private:
        ArcoGrafo<TA>* MatriceAdiacenza[MAXNODI][MAXNODI]; //matrice adiacenza
        NodoGrafo<TN>* Array[MAXNODI]; //vettore di nodi
        int numnodi;
public:
       Grafo();
       ~Grafo();
       void CREAGRAFO();
       bool GRAFOVUOTO();
       void INSNODO(Nodo, TN);
       void INSARCO(Nodo, Nodo, TA);
       void CANCNODO(Nodo);
       void CANCARCO(Nodo,Nodo);
       Lista<Nodo>* ADIACENTI(Nodo);
       bool ESISTENODO(Nodo);
       bool ESISTEARCO(Nodo,Nodo);
};




template <class TN, class TA>
Grafo<TN,TA>::Grafo()
{
     for(int i = 0; i < MAXNODI; i++)
     {
          for(int j = 0; j < MAXNODI; j++)
          {
                  MatriceAdiacenza[i][j] = NULL;
          }
          Array[i] = NULL;
     }
     numnodi = 0;
}

template <class TN, class TA>
Grafo<TN,TA>::~Grafo()
{
}

template <class TN, class TA>
void Grafo<TN,TA>::CREAGRAFO()
{
     Grafo<TN,TA>();
}

template <class TN, class TA>
bool Grafo<TN,TA>::GRAFOVUOTO()
{
     return numnodi == 0;
}

template <class TN, class TA>
void Grafo<TN,TA>::INSNODO(Nodo pos, TN elementoN)
{
     if(pos >= 0 && pos < MAXNODI)
     {
          if(Array[pos] == NULL)
          {
               Array[pos] = new NodoGrafo<TN>();
               Array[pos]->setElemento(elementoN);
               numnodi++;
          }
          else
               cout<<"ERRORE: Posizione "<<pos<<" gia' occupata! in INSNODO"<<endl;
     }
     else
          cout<<"ERRORE: Posizione "<<pos<<" inesistente! in INSNODO"<<endl;
}

template <class TN, class TA>
void Grafo<TN,TA>::INSARCO(Nodo pos1, Nodo pos2, TA elementoA)
{
     if(MatriceAdiacenza[pos1][pos2] == NULL)
     {
          MatriceAdiacenza[pos1][pos2] = new ArcoGrafo<TA>();
          MatriceAdiacenza[pos1][pos2]->setElemento(elementoA);
     }
     else
          cout<<"ERRORE: arco gia' esistente! in INSARCO"<<endl;
}

template <class TN, class TA>
void Grafo<TN,TA>::CANCNODO(Nodo pos)
{
     if(ESISTENODO(pos))
     {
               if(ADIACENTI(pos).LISTAVUOTA())
               {
                    numnodi--;
                    Array[pos] = NULL;
               }
               else
                    cout<<"ERRORE: inpissibile cancellare nodo "<<pos
                        <<", nodo connesso"<<endl;
     }
}

template <class TN, class TA>
void Grafo<TN,TA>::CANCARCO(Nodo pos1,Nodo pos2)
{
     if(ESISTEARCO(pos1, pos2))
     {
          MatriceAdiacenza[pos1][pos2] = NULL;
          Array[pos1]->setNumarch(Array[pos1]->getNumarch()- 1);
     }
     else
          cout<<"ERRORE: arco tra nodo "<<pos1<<" e "<<pos2<<" inesistente"<<endl;
}

template <class TN, class TA>
Lista<Nodo>* Grafo<TN,TA>::ADIACENTI(Nodo pos)
{
     Lista<Nodo>* L = new Lista<Nodo>();
     if(ESISTENODO(pos))
     {
     for(int i = 0; i < MAXNODI; i++)
           if(MatriceAdiacenza[pos][i] != NULL)
           {
                L->INSLISTA(i, L->PRIMOLISTA());
           }
     }
     return L;
}

template <class TN, class TA>
bool Grafo<TN,TA>::ESISTENODO(Nodo pos)
{
     if(pos >= 0 && pos < MAXNODI)
     {
          if(Array[pos] != NULL)
               return true;
          else
          {
               cout<<"ERRORE: Nodo "<<pos<<" inesistente!"<<endl;
               return false;
          }
     }
     else
     {
          cout<<"ERRORE: Posizione "<<pos<<" inesistente!"<<endl;
          return false;
     }
}

template <class TN, class TA>
bool Grafo<TN,TA>::ESISTEARCO(Nodo pos1, Nodo pos2)
{
     if(ESISTENODO(pos1) && ESISTENODO(pos2))
         if(MatriceAdiacenza[pos1][pos2] != NULL)
              return true;
     return false;
}





#endif /* GRAFO_H_ */
