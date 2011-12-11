#ifndef CELLA_H
#define CELLA_H

typedef int tipoelem;


class cella {
       private:
              tipoelem valore; 
              
              
        public:  
              cella();
              tipoelem leggi_valore();
              void scrivi_valore(tipoelem);
      };
#endif      
