/*
 * servizio_dizionarioVettore.h
 *
 *  Created on: 16/gen/2012
 *      Author: Domenico Monaco
 */

#ifndef SERVIZIO_DIZIONARIOVETTORE_H_
#define SERVIZIO_DIZIONARIOVETTORE_H_

#include "../Dizionario/dizionarioVettore.h"
#include "../Dizionario/dizionario.h"
#include "../Dizionario/datoDizionario.h"

#include "../Dati/studente.h"

//DEFINIAMO IL TIPO ELEM DA ALLEGARE

//template<class elemento, class chiave>
typedef DizionarioVettore<Studente, int> Corso;

//DICHIARAZIONI DELLE FUNZIONI DI SERVIZIO
void servizio_dizionarioVettore();
void caricaTutto(Corso&);
void stampaTutto(Corso);
void cercaCancella(Corso&, int);

/*  NodoInteri* cerca(ListaInteri, int);
 void cercaSostituisci(ListaInteri, int interodacercare , int interodasostituire);

 */

void servizio_dizionarioVettore() {

	Corso CorsoInformatica;

	//CorsoInformatica = caricaTutto(CorsoInformatica);
	caricaTutto(CorsoInformatica);

	stampaTutto(CorsoInformatica);

	cercaCancella(CorsoInformatica, 3248);

	stampaTutto(CorsoInformatica);

}
void stampaTutto(Corso CorsoInformatica) {

	Studente S;

	S = CorsoInformatica.cerca(3248);

	cout << "Lo studente matricola: " << S.getMatricola() << endl;
	cout << " ha etˆ " << S.getEta() << endl;
	cout << " " << endl;

	S = CorsoInformatica.cerca(3847);

	cout << "Lo studente matricola: " << S.getMatricola() << endl;
	cout << " ha etˆ " << S.getEta() << endl;
	cout << " " << endl;

	S = CorsoInformatica.cerca(435987);

	cout << "Lo studente matricola: " << S.getMatricola() << endl;
	cout << " ha etˆ " << S.getEta() << endl;
	cout << " " << endl;

	S = CorsoInformatica.cerca(490857);

	cout << "Lo studente matricola: " << S.getMatricola() << endl;
	cout << " ha etˆ " << S.getEta() << endl;
	cout << " " << endl;

	S = CorsoInformatica.cerca(8457);

	cout << "Lo studente matricola: " << S.getMatricola() << endl;
	cout << " ha etˆ " << S.getEta() << endl;
	cout << " " << endl;

}

void caricaTutto(Corso& CorsoInit) {
	Studente S;

	S.setStudente(23, 3248);
	CorsoInit.inserisci(S, S.getMatricola());

	S.setStudente(24, 3847);
	CorsoInit.inserisci(S, S.getMatricola());

	S.setStudente(29, 435987);
	CorsoInit.inserisci(S, S.getMatricola());

	S.setStudente(23, 490857);
	CorsoInit.inserisci(S, S.getMatricola());

	S.setStudente(19, 8457);
	CorsoInit.inserisci(S, S.getMatricola());

	//	return CorsoInit;
}

void cercaCancella(Corso& CorsoInformatica, int matricola){
	CorsoInformatica.cancella(matricola);
}


#endif /* SERVIZIO_DIZIONARIOVETTORE_H_ */
