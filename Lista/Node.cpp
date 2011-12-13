//#include "Node.h"
//
///* Metodo costruttore che crea un oggetto di classe node ed inizializza i membri attributi next e previous */
//template<class T>
//Node<T>:: Node()
//{
// previous=NULL;
// next=NULL;
//}
//
///* Metodo distruttore che distrugge un oggetto di classe Node */
//template<class T>
//Node<T>:: ~Node(){ delete(this);}
//
///*Metodo costruttore che inizializza il valore del membro attributo pos */
//template <class T>
//void Node<T>:: set_pos(unsigned i)
//{
// pos=i;
//}
//
///* Metodo costruttore che avvalora il membro attributo next */
//template <class T>
//void Node<T>:: set_next(Node<T>* n)
//{
// next=n;
//}
//
///* Metodo costruttore che avvalora il membro attributo previous */
//template <class T>
//void Node<T>:: set_previous(Node<T>*n)
//{
// previous=n;
//}
//
///* Metodo costruttore che avvalora il membro attributo informazione */
//template<class T>
//void Node<T>:: set_elem(T i)
//{
// informazione=i;
//}
//
///* Metodo osservatore che restituisce il valore del membro attributo next*/
//template<class T>
//Node<T>* Node<T>:: get_next()
//{
// return next;
//}
//
///* Metodo osservatore che restituisce il valore del membro attributo previous */
//template<class T>
//Node<T>* Node<T>:: get_previous()
//{
// return previous;
//}
//
///* Metodo osservatore che restituisce il valore del membro attributo informazione */
//template<class T>
//T Node<T>:: get_elem()
//{
// return informazione;
//}
//
///* Metodo osservatore che restituisce il valore del membro attributo pos */
//template <class T>
//unsigned Node<T>:: get_pos()
//{
// return pos;
//}
