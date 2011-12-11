#include "pila.h"
using namespace std;

pila:: pila(){
            creapila();
     };
     
void pila:: creapila(){
          testa=0;
      };
      
bool pila:: pilavuota(){
           return(testa==0);
         }; 
         
tipoelem pila:: leggipila(){
        if (!pilavuota())
              return elementi[testa]; 
         };  
         
void pila:: fuoripila(){
        if(!pilavuota())
            testa--;
     };                    
  
void pila:: inpila(tipoelem t){
     
     testa++;       
     elementi[testa]=t;
     };      
  
 
