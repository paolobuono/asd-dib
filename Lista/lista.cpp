#include "lista.h"
#include <iostream>

using namespace std;


lista:: lista()
        {
               crealista();
        }
        
void lista:: crealista()
        {
             primo=0;
             lunghezza=0; 
             
        }        
        
bool lista:: listavuota()
       {
            return(lunghezza==0);    
       }
        
tipoelem lista:: leggilista(int i) //DA TESTARE
       {
           if(!listavuota())
           
              return   vet[i].leggi_valore();
                  
       }       
       
void lista:: scrivilista(tipoelem v, int i) // DA TESTARE
       {
             if(!listavuota())
               vet[i].scrivi_valore(v);      
                
       }       
          
int lista:: primolista()
       {
           return primo;   
       }           

bool lista:: finelista(int i)
       {
           return (i==lunghezza);  
       }
       
int lista:: succlista(int i)
       {
            if(!finelista(i))
               return (i+1);    
       }        

int lista:: predlista(int i)
       {
            if(i!=primolista())
              return (i-1);      
       }
       
void lista:: inslista(int i, tipoelem v)
       {     
             if(lunghezza< SIZE)
                {
                  if (listavuota())
                      {
                         lunghezza=1;
                         scrivilista(v, primo);          
                      } 
                      else
                          if(i>=lunghezza)
                             scrivilista(v, lunghezza++);
                          else
                              {
                                 lunghezza++;
                                 for(int k=lunghezza; k>i; k--)
                                     scrivilista(vet[k-1].leggi_valore(), k);
                                 scrivilista(v,i);                     
                              }            
                }  
       }       


void lista:: canclista(int n)
     {       
             if(!listavuota())
                {  
                        if(n<lunghezza)
                           {                               
                             int j=primolista(); 
                             while(!finelista(j))
                                  j=succlista(j); //SI POSIZIONA ALL'ULTIMO ELEMENTO   
                               
                              for(int i=n;i<j;i++)
                                  scrivilista(vet[i+1].leggi_valore(),i);
                                  lunghezza--;
                            }  
                        else if(n==lunghezza)         
                             lunghezza--;
                          
                                 
                              }
             
     }
