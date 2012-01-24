#include "servizi.h"

void stampa_pila(pila &p) {
	pila app;

	while (!p.pilavuota()) {
		cout << p.leggipila() << " - ";
		app.inpila(p.leggipila());
		p.fuoripila();
	}

	while (!app.pilavuota()) {
		p.inpila(app.leggipila());
		app.fuoripila();
	}

}
