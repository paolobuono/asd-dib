#include "servizi.h"

void stampa_pila(Pila<int> &p) {

	Pila<int> app;

	while (!p.PILAVUOTA()) {
		cout << p.LEGGIPILA() << " - ";
		app.INPILA(p.LEGGIPILA());
		p.FUORIPILA();
	}

	while (!app.PILAVUOTA()) {
		p.INPILA(app.LEGGIPILA());
		app.FUORIPILA();
	}

}
