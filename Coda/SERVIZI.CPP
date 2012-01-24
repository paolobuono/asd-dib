#include "servizi.h"
#define MAX_LUNG 5

/*int conta_elementi(Coda & c){
 int cont=0;
 Coda app;
 Tipoelem e;

 while(!c.codavuota())
 { 
 e=c.leggicoda();
 app.incoda(e);
 c.fuoricoda();
 cont++;
 }

 while(!app.codavuota())
 { 
 e=app.leggicoda();
 c.incoda(e);
 app.fuoricoda();
 }     
 return cont;
 }*/

void stampa_coda(Coda& c) {
	int k;
	Coda app;
	Tipoelem e;
	int i = 1;
	int j = c.leggi_numero();
	if (!c.codavuota()) {
		while (!c.codavuota()) {
			e = c.leggicoda();
			if (i == 1) {
				cout << "TESTA        " << e << endl;
			} else {
				if (i == j) {
					cout << "FONDO        " << e << endl;
				} else {
					cout << i << "o ELEMENTO  " << e << endl;
				}
			}
			app.incoda(e);
			c.fuoricoda();
			i++;
		}
		c.set_cont(0);
		while (!app.codavuota()) {
			c.incoda(app.leggicoda());
			app.fuoricoda();
		}
	} else {
		cout << "La coda e' vuota" << endl;
	}
}
