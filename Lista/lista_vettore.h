#ifndef LISTA_H
#define LISTA_H
#include "cella.h"
#define SIZE 12


class lista{
      private:
              cella vet[SIZE];
              int i;
              int lunghezza;
              int primo;
             
      public:   
              lista();
              void crealista();
              bool listavuota();
              tipoelem leggilista(int); //DA TESTARE
              void scrivilista(tipoelem, int); // DA TESTARE
              int primolista();
              bool finelista(int);
              int succlista (int);
              int predlista(int);
              void inslista(int, tipoelem);
              void canclista(int);
      
      };
#endif
