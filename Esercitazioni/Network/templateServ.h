#ifndef TEMPLATESERV_H
#define TEMPLATESERV_H
#include "listaVettore.h"
#include "listaPuntatoriServ.h"
#include "canale.h"

typedef ListaPunt<Programma *> *punt;

void caricaPalinsesto(ListaVett<Canale> &r)
{
	// oggetti "Canale", inserimento nell'oggetto "Rete" e dichiarazione puntatori a "Canale"
	Canale Raiuno("Rai Uno"), Raidue("Rai Due"), Raitre("Rai Tre");
	r.inslista(Raiuno, 1);
	r.inslista(Raidue, 2);
	r.inslista(Raitre, 3);
	punt puntuno = r.leggilista(1).getPali(),
		 puntdue = r.leggilista(2).getPali(),
		 punttre = r.leggilista(3).getPali();

	// creazione oggetti "Programma"
	Programma *tg_uno = new Programma(1010, "TG 1", "telegiornale");
	Programma *la_vita_e_bella = new Programma(1020, "La Vita � Bella", "film");
	Programma *italia_germania = new Programma(1030, "Italia - Germania", "partita di calcio");
	Programma *tg_due = new Programma(2010, "TG 2", "telegiornale");
	Programma *la_signora_in_giallo = new Programma(2020, "La Signora in Giallo", "film");
	Programma *tg_tre = new Programma(3010, "TG 3", "telegiornale");

	// inserimento dei programmi nelle liste "Palinsesto" relative ai canali
	puntuno->inslista(tg_uno, puntuno->primolista());
	puntuno->inslista(la_vita_e_bella, puntuno->succlista(puntuno->ultimolista())); // append
	puntuno->inslista(italia_germania, puntuno->succlista(puntuno->ultimolista())); // append
	puntdue->inslista(tg_due, puntdue->primolista());
	puntdue->inslista(la_signora_in_giallo, puntdue->succlista(puntdue->ultimolista()));
	punttre->inslista(tg_tre, punttre->primolista());
}

void elencoCanali(ListaVett<Canale> &r)
{
	int i;
	for( i=1 ; i<=r.ultimolista() ; i++ ) { cout<< r.leggilista(i).getNome() << endl; }
	cout << endl;
}

void elencoProgrammi(ListaVett<Canale> &r, string nome)
{
	int i, j=1;
	for( i=1 ; i<=r.ultimolista() ; i++ ){
		if( r.leggilista(i).getNome() == nome ){
			cout << "Palinsesto " << nome << ":" <<endl;
			punt p = r.leggilista(i).getPali();
			while ( !p->finelista(mappapos(*p, j)) ){
				cout<< p->leggilista(mappapos(*p, j))->getTitolo() << endl;
				j++;
			}
		}
	}
	cout << endl;
}

Programma * ottieniProgramma(ListaVett<Canale> &r, int codice)
{
	int i, j; punt p; Programma *puntAprog = NULL;
	for( i=1 ; i<=r.ultimolista() ; i++ ){
		p = r.leggilista(i).getPali();	j=1;
		while ( !p->finelista(mappapos(*p, j)) ){
			if( p->leggilista(mappapos(*p, j))->getCodice() == codice )
				{ puntAprog = p->leggilista(mappapos(*p, j)); }
			j++;
		}
	}
	return puntAprog;
}

void registraProgramma(ListaVett<Canale> &r, int codice, ListaPunt<Programma *> &reg)
{
	Programma *puntAprog = ottieniProgramma(r, codice);
	if( puntAprog != NULL ){
		reg.inslista(puntAprog, reg.primolista());
	}
}

void ottieniRegistrazioni(ListaPunt<Programma *> &reg)
{
	int i=1;
	cout<< "Film registrati: ";
	while ( !reg.finelista(mappapos(reg, i)) ){
		if( reg.leggilista(mappapos(reg, i))->getDescrizione() == "film" )
			{ cout<< reg.leggilista(mappapos(reg, i))->getTitolo() << ", "; }
		i++;
	}
	cout << endl;
}

void testNetwork()
{
	ListaVett<Canale> Rete;
	cout << "Esecuzione di caricaPalinsesto(), funzione che carica il palinsesto della rete" << endl;
	caricaPalinsesto(Rete);
	cout << "Esecuzione di elencoCanali(), funzione che restituisce l'elenco di canali messi a disposizione dalla rete televisiva" << endl;
	elencoCanali(Rete);
	cout << "Esecuzione di elencoProgrammi(canale), funzione che restituisce l'elenco dei programmi disponibili nel canale specificato" << endl;
	elencoProgrammi(Rete, "Rai Due");
	cout << "Esecuzione di ottieniProgramma(codiceProgramma), funzione che restituisce il programma per stamparne titolo e descrizione" << endl;
	Programma* puntAprog = ottieniProgramma(Rete, 2010);
	if( puntAprog != NULL ){
		cout << "Programma con codice " << puntAprog->getCodice() << ":" <<endl;
		cout<< puntAprog->getTitolo() << " -> ";
		cout<< puntAprog->getDescrizione() << endl;
	} else {
		cout << "Programma con codice xxx non trovato!" <<endl;
	}
	cout << endl;
};

//void testNetwork()
//{
//	ListaVett<Canale> Rete;
//
//	// caricaPalinsesto(), che carica il palinsesto della rete
//	caricaPalinsesto(Rete);
//
//	// elencoCanali(), che restituisce l'elenco di canali messi a disposizione dalla rete televisiva
//	elencoCanali(Rete);
//	cout << "Esecuzione di registraProgramma(codiceProgramma), funzione che memorizza il programma passato al metodo ad una lista contenente i programmi in registrazione" << endl;
//	ListaPunt<Programma *> Registrazioni;
//	registraProgramma(Rete, 1010, Registrazioni);
//	registraProgramma(Rete, 1020, Registrazioni);
//	registraProgramma(Rete, 2020, Registrazioni);
//
//	cout << "Esecuzione di ottieniRegistrazioni(), funzione che restituisce l'elenco di film in registrazione" << endl;
//	ottieniRegistrazioni(Registrazioni);
//}
//
//	// elencoProgrammi(canale), che restituisce l'elenco dei programmi disponibili nel canale specificato
//	elencoProgrammi(Rete, "Rai Due");
//
//	// ottieniProgramma(codiceProgramma), che restituisce il programma per stamparne titolo e descrizione
//	Programma* puntAprog = ottieniProgramma(Rete, 2010);
//	if( puntAprog != NULL ){
//		cout << "Programma con codice " << puntAprog->getCodice() << ":" <<endl;
//		cout<< puntAprog->getTitolo() << " -> ";
//		cout<< puntAprog->getDescrizione() << endl;
//	} else {
//		cout << "Programma con codice xxx non trovato!" <<endl;
//	}
//	cout << endl;
//
//	// registraProgramma(codiceProgramma), che memorizza il programma passato al metodo ad una lista contenente i programmi in registrazione
//	ListaPunt<Programma *> Registrazioni;
//	registraProgramma(Rete, 1010, Registrazioni);
//	registraProgramma(Rete, 1020, Registrazioni);
//	registraProgramma(Rete, 2020, Registrazioni);
//
//	// ottieniRegistrazioni(), che restituisce l'elenco di film in registrazione
//	ottieniRegistrazioni(Registrazioni);
//}
#endif
