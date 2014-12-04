#include "servizi.h"
#include <iostream>

using namespace std;

void stampa_coda(Coda& c) {
	Coda temp;
	cout << "Elementi in coda: " << endl;

	while (!c.codavuota()){
		cout << c.leggicoda << endl;
		temp.incoda(c.leggicoda());
		c.fuoricoda();
	}

	while (!temp.codavuota()){
			c.incoda(temp.leggicoda());
			temp.fuoricoda();
	}
}
