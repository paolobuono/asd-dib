#include <cstdlib>
#include <iostream>

#define MAX_LUNG 4 
using namespace std;

typedef int tipoelem;

class pila {
private:
	tipoelem elementi[MAX_LUNG];
	int testa;

public:
	pila();
	void creapila();
	bool pilavuota();
	tipoelem leggipila();
	void fuoripila();
	void inpila(tipoelem);

};
