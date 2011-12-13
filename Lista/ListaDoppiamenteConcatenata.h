#ifndef Lista_h
#define Lista_h
#include <cstdlib>
#include <iostream>
#define TRUE 1
#define FALSE 0
#include "Node.h"
using namespace std;

template <class T>
class Lista
{
 private:
         Node<T>* testa;
         int nd;
 public:
        Lista(); //operatore costruttore
        Node<T>* primo_lista();
        int fine_lista(Node<T>*);
        int lista_vuota();
        void Ins_lista(T /*,unsigned*/);  
        void Print_lista();
        Node<T>* succ_lista(Node<T>*);
        Node<T>* pred_lista(Node<T>*);
        void canc_lista(Node<T>*);
        T leggi_lista(Node<T>*);
        void scrivi_lista(Node<T>*, T); //?
        Node<T>* cerca_elemento(unsigned);
        void epurazione();
        //void mergesort(int, int );
        int get_num_nd();
        void order();
        ~Lista(); 

         //void merge(int , int, int);
         //Node* try_elem(int);
       
};

/* Metodo costruttore che costruisce un nuovo oggetto di classe lista */
template<class T>
Lista<T>:: Lista()
{
 testa=NULL;
 //nd=0;
}

/*Metodo osservatore che restituisce il valore del membro attributo testa */
template<class T>
Node<T>* Lista<T>:: primo_lista()
{
 return testa;     
}

/* Metodo osservatore che verifica che un nodo sia di fine lista */
template<class T>
int Lista<T>:: fine_lista(Node<T>* n)
{
   int result=FALSE;
    if (n!=NULL && !(lista_vuota()))
    {
       if (n->get_next()==NULL)
       {
          result=TRUE;                        
       }  
    }
    return result;
}

/* Metodo osservatore che verifica che la lista sia vuota */
template<class T>
int Lista<T>:: lista_vuota()
{
 int result=FALSE;
 if (primo_lista()==NULL)
 {
    result=TRUE;                        
 } 
 return result;  
}

/* Metodo distruttore che distrugge un oggetto di classe lista */
template<class T>
Lista<T>:: ~Lista(){}

/* Metodo osservatore che restituisce il valore del nodo successivo al nodo n */
template<class T>
Node<T>* Lista<T>:: succ_lista(Node<T>* n)
{//restituisce null se non esiste un successivo o se il nodo non è valido
 Node<T>* result=NULL;
 if (n!=NULL)
 {
    result=n->get_next();            
 } 
 return result;    
}

/* Metodo osservatore che restituisce il valore del nodo precedente al nodo n */
template<class T>
Node<T>* Lista<T>:: pred_lista(Node<T>*n)
{//restituisce null se non esiste un precedente o se il nodo non è valido
 Node<T>* result=NULL;
 if (n!=NULL)
 {
    result=n->get_previous();
 } 
 return result;     
}

/* Metodo costruttore che avvalora la lista */
template<class T>
void Lista<T>:: Ins_lista(T i/*, unsigned pos*/)
{
 Node<T>* n;
 Node<T>* node;
 if (lista_vuota()==TRUE)
 {
   n=new Node<T>();
   //n->set_pos(pos);
   n->set_elem(i);
   testa=n;   
   nd++;                     
 }
 else
 {
   n=primo_lista();
   Node<T>* previous;
   node=new Node<T>();
   node->set_elem(i);
   //node->set_pos(pos);
   nd++;
   while ( (n!=NULL) /*&& (pos> n->get_pos())*/)
   {
         previous=n;
         n=n->get_next();  
   } 
   if (n==primo_lista())
   {
    testa=node;
    testa->set_next(n);
    n->set_previous(testa);                     
   }
   else
   {
    if (n==NULL)
    {
       previous->set_next(node);  
       node->set_previous(previous);         
    }
    else
    {
        previous->set_next(node);
        node->set_next(n);
        node->set_previous(previous);  
        n->set_previous(node);    
    }
   }
 }
}

/* Metodo osservatore che stampa la lista */
template<class T>
void Lista<T>:: Print_lista()
{
  Node<T>*n;
  n=primo_lista();
  while (!fine_lista(n))
  {
        cout<< "Value:"<<n->get_elem()<<endl;
        //cout<< "Pos:"<<n->get_pos()<<endl;
        n=n->get_next();
  }  
  cout<<"Value:"<<n->get_elem()<<endl;
  //cout<< "Pos:"<<n->get_pos()<<endl;
}

/* Metodo osservatore che restituisce il contenuto dell'informazione del nodo n */
template<class T>
T Lista<T>:: leggi_lista(Node<T>*n)
{
 return n->get_elem();          
}

/* Metodo osservatore che restituisce il nodo in posizione pos */
template <class T>
Node<T>* Lista<T>:: cerca_elemento(unsigned pos)
{ //se la posizione pos non esiste il metodo restituisce null
 Node<T>* n=primo_lista();
 Node<T>* result=NULL;
 while ((pos!=n->get_pos()) && (n!=NULL))
 {
       n=n->get_next();
 } 
 if (n!=NULL)
 {
    result=n;
 }
 
 return result;
}

/* Metodo osservatore che sostituisce ad un nodo n il valore dell'informazione i */
template<class T>
void Lista<T>:: scrivi_lista(Node<T>*n, T i)
{
 if (n!=NULL)
 {
  n->set_elem(i);  
 }
 else
 {
  cout<<"Attenzione! Nodo non valido!"<<endl;
 }
}

/* Metodo osservatore che elimina il nodo n dalla lista */
template <class T>
void Lista<T>:: canc_lista(Node<T>*n)
{
 if (!lista_vuota())
 {
  if (n== primo_lista())
  {
     testa=succ_lista(n);
     testa->set_previous(NULL); 
     nd--;
     //delete(n);       
  } 
  else
  {
     if (fine_lista(n)==TRUE)
     {
        pred_lista(n)->set_next(NULL); 
        nd--;
        //delete(n);                    
     }
     else
     {
         pred_lista(n)->set_next(succ_lista(n));
         succ_lista(n)->set_previous(pred_lista(n));  
         nd--;
         //delete(n);
     }
  }
 }
}

/* Metodo che elimina i duplicati nella lista */
template <class T>
void Lista<T>:: epurazione()
{
 Node<T>* n;
 Node<T>*h;
 T a;
 T b;
 
 n=primo_lista();
 while (!fine_lista(n))
 {     
       a=leggi_lista(n); 
       h=succ_lista(n);
       while (!fine_lista(h))
       {
        b=leggi_lista(h);
        if (a->getValue()==b->getValue())
        {
          h=succ_lista(h);
          canc_lista(pred_lista(h));      
        }  
        else
        { 
         h=succ_lista(h);    
        }  
       }
       b=leggi_lista(h);
       if (a->getValue()==b->getValue())
       {
          canc_lista(h);
       }
       if (succ_lista(n)!=NULL)
       {
          n=succ_lista(n);
       }
 }
}

/* Metodo osservatore che restituisce il numero di nodi */
template<class T>
int Lista<T>:: get_num_nd()
{
 return nd;   
}

/* Metodo che ordina la lista */
template<class T>
void Lista<T>:: order()
{/*
 Node<T>*n=primo_lista();
 Node<T>*temp;
 T a; 
 T b;
 unsigned t;
 int num=get_num_nd();
 while (num>0) 
 {
       while (!fine_lista(n))
       {
           
           a=leggi_lista(n);
           b=leggi_lista(succ_lista(n));
           if (a->getValue()>b->getValue())    //basso livello
           {
             scrivi_lista(n,b);
             t=n->get_pos();
             n->set_pos(succ_lista(n)->get_pos());
             succ_lista(n)->set_pos(t);
             scrivi_lista(succ_lista(n),a); 
             n=succ_lista(n);       //la pos deve variare
           } 
           else
           {
            n=succ_lista(n);    
           }
       } 
       num--;     
 }
     
*/}


#endif
