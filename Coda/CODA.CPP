#include "coda.h"

Coda::Coda() {
	creacoda();
}
;

void Coda::creacoda() {
	testa = 0;
	fondo = -1;
	numero = 0;
	cont = 0;
}
void Coda::set_cont(int c) {
	cont = c;
}

bool Coda::codavuota() {
	//testa=-1;
	return (numero == 0);
}

Tipoelem Coda::leggicoda() {
	if (!codavuota())

		//cout<<"TESTA IN LEGGICODA:   "<<testa<<endl; 
		return elementi[testa];
}
;

void Coda::fuoricoda() {

	int i = 0;
	int app = numero;
	if (!codavuota()) {
		while (i < app - 1) {
			elementi[i] = elementi[i + 1];
			i++;
		}
		numero--;
		cont--;
	}

}
;

void Coda::incoda(Tipoelem t) {

	int pos = cont % MAX_LUNG;
	elementi[pos] = t;
	cont++;
	if (cont <= MAX_LUNG) {
		numero++;
	}

}
;

int Coda::leggi_numero() {

	return numero;
}

int Coda::leggi_fondo() {

	if (cont < MAX_LUNG)
		fondo = cont;
	else
		fondo = cont % MAX_LUNG;
	return fondo;
}

