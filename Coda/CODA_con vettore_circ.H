#include <cstdlib>
#include <iostream>

#define MAX_LUNG 5

using namespace std;

typedef int Tipoelem;

class Coda {
private:
	Tipoelem elementi[MAX_LUNG];
	int testa;
	int fondo;
	int numero;
	int cont;

public:
	Coda();
	void creacoda();
	bool codavuota();
	Tipoelem leggicoda();
	void fuoricoda();
	void incoda(Tipoelem);
	void set_cont(int);
	int leggi_numero();
	int leggi_fondo();
	int leggi_testa();
};
